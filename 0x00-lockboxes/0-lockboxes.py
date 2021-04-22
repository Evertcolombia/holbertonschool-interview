#!/usr/bin/python3

def canUnlockAll(boxes):
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
