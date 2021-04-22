#!/usr/bin/python3

"Look boxes"""


def canUnlockAll(boxes):
    """
    ou have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1 and
    each box may contain keys to the other boxes.
    """
    thisset = set ()

    for key in boxes:
        if (key):
            if key[0] < len(boxes):
                thisset.add(key[0])

    if not 0  in thisset:
        thisset.add(0)

    if len(thisset) == len(boxes):
        return True
    return False
