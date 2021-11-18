#!/usr/bin/python3
"""
Given a list of non-negative integers representing walls of width 1,
calculate how much water will be retained after it rains.
"""


def rain(walls):
    """
    Function that gets the water drop from walls.

    Args:
        param1: walls wallsay structure.

    Returns:
        The water inside walls

    """
    left = 0
    right = len(walls) - 1
    left_max = 0
    right_max = 0
    result = 0
    while (left <= right):
        if right_max <= left_max:
            result += max(0, right_max - walls[right])
            right_max = max(right_max, walls[right])
            right -= 1
        else:
            result += max(0, left_max - walls[left])
            left_max = max(left_max, walls[left])
            left += 1
    return result
