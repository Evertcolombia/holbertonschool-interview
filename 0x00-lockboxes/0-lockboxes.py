#!/usr/bin/python3
"""
Lock boxes
"""


def canUnlockAll(boxes):
    """
    you have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1 and
    each box may contain keys to the other boxes.

    Args:
    boxes (list of boxes) : List
    Returns:
    True if all boxes can be opened, otherwise False
    """
    thisset = [0]

    for key in thisset:
        for k in boxes[key]: 
            if k  < len(boxes) and k not in thisset:
                thisset.append(k)

    if len(thisset) == len(boxes):
        return True
    return False
