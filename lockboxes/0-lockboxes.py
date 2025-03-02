#!/usr/bin/python3
""" Module : Lockboxes """


def canUnlockAll(boxes):
    """ Method that return true if all boxes can be opened """

    # Declaration, vidage et remplissage de la liste des booléen
    list_boxes = []
    for box in boxes:
        list_boxes.append(False)
    # Ouverture de la première box
    list_boxes[0] = True
    # Création d'une liste de clés
    # et ajout des clés contenues dans la première box
    list_cles = []
    for i in boxes[0]:
        list_cles.append(i)
    i = 0
    while i < len(list_cles):
        index = list_cles[i]
        if index >= 0 and index < len(boxes):
            if list_boxes[index] is False:
                list_boxes[index] = True
                for j in boxes[index]:
                    if j not in list_cles:
                        list_cles.insert(i + 1, j)
        i += 1

    return_value = True
    for value in list_boxes:
        if value is False:
            return_value = False
    return return_value
