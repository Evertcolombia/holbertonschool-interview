#!/usr/bin/python3
"""
This software defines rules to check if an integer combination is a valid
UTF-8 Encoding
A valid UTF-8 character can be 1 - 4 bytes long.
For a 1-byte character, the first bit is a 0, followed by its unicode.
For an n-bytes character, the first n-bits are all ones, the n+1 bit is 0,
followed by n-1 bytes with most significant 2 bits being 10.
"""


def validUTF8(data):
    """
    args:
        @data: Integer list with the information about the character
    Return: True if the integers are UTF 8 encodable False otherwise
    """
    bytes_num = 0
    for num in data:
        mask = 1 << 7
        if bytes_num == 0:
            # If byte is not in chain dont ask for confirmation bytes
            while mask & num:
                bytes_num += 1
                mask = mask >> 1
            if bytes_num == 0:
                continue
            elif bytes_num == 1 or bytes_num > 4:
                return False
        else:
            # If byte doesnt start with 10 return false
            if not (num & 1 << 7 and not (num & 1 << 6)):
                return False
        bytes_num -= 1
    if bytes_num == 0:
        return True
    return False
