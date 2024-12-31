#!/usr/bin/python3
""" Module : Lockboxes """


list_boxes = []

def canUnlockAll(boxes):
    """ Method that return true if all boxes can be opened """
    global list_boxes 
    list_boxes.clear()
    for box in boxes:
        list_boxes.append(False)     
    unlockBox(boxes, 0)
    return_value = True
    for value in list_boxes:
        if value == False:
            return_value = False
    return return_value
     
def unlockBox(boxes, index):
    """ Method that opens all boxes corresponding to each key
        contained in the boxes[index] 
    """
    if index >= 0 and index < len(boxes):
        if list_boxes[index] == False:
            list_boxes[index] = True
            for i in boxes[index]:     
                unlockBox(boxes, i)
    