#!/usr/bin/python3
from itertools import takewhile


def to_bits(bytes):
    for byte in bytes:
        num = []
        exp = 1 << 8
        while exp:
            exp >>= 1
            num.append(bool(byte & exp))
        yield num


def validUTF8(data):
    """
        validates if a list constains valid elements

        :type data: List[int]
    """

    bits = to_bits(data)
    for byte in bits:
        # single byte char
        if byte[0] == 0:
            continue
        
        amount = sum(takewhile(bool, byte))
        if amount <= 1:
            return false
        if amount >= 4:
            return false
        
        for _ in range(amount - 1):
            try:
                byte = next(bits)
            except StopIteration:
                return False
            if byte[0:2] != [1, 0]:
                return False
    return True
