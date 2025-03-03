#!/usr/bin/python3
""" Module : UTF-8 Validation """


def validUTF8(data):
    for i in data:
        if i >= 256:
            return False
    return True
    