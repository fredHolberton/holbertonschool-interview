#!/usr/bin/python3
""" Module : UTF-8 Validation """


def validUTF8(data):
    i = 0
    while i < len(data):
        byte = data[i] % 256
        # Make sure the byte is between 0-255

        # Check how many bytes are in the current character
        # based on the leading bits
        if (byte >> 7) == 0:  # 1-byte character: 0xxxxxxx
            i += 1
        elif (byte >> 5) == 0b110:  # 2-byte character: 110xxxxx 10xxxxxx
            if i + 1 >= len(data) or (data[i + 1] % 256 >> 6) != 0b10:
                return False
            i += 2
        elif (byte >> 4) == 0b1110:
            # 3-byte character: 1110xxxx 10xxxxxx 10xxxxxx
            if (i + 2 >= len(data) or
                (data[i + 1] % 256 >> 6) != 0b10 or
                (data[i + 2] % 256 >> 6) != 0b10):
                return False
            i += 3
        elif (byte >> 3) == 0b11110:
            # 4-byte character: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
            if (i + 3 >= len(data) or
                (data[i + 1] % 256 >> 6) != 0b10 or
                (data[i + 2] % 256 >> 6) != 0b10 or
                (data[i + 3] % 256 >> 6) != 0b10):
                return False
            i += 4
        else:
            return False  # Invalid byte

    return True
