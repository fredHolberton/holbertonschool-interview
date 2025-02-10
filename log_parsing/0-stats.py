#!/usr/bin/python3
"""Module : Log Parsing."""


import sys
import re

reg_IP = r'^([0-9]{1,3}\.){3}[0-9]{1,3}?$'
datetime_regex = r'^\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{6}$'
status_codes = {
    '200': 0,
    '301': 0, 
    '400': 0, 
    '401': 0, 
    '403': 0, 
    '404': 0, 
    '405': 0, 
    '500': 0
}
file_size = 0

try:        
    while True:
        for i in range(10):
            line = sys.stdin.readline()
            line = line.strip()

            avant, separateur, apres = line.partition(' - [')
            if re.match(reg_IP, avant):
                # une adresse ip est trouvée, on continue
                end_line = apres
                avant, separateur, apres = end_line.partition('] "')
                if re.match(datetime_regex, avant):
                    # une date est trouvée, on continue
                    end_line = apres
                    avant, separateur, apres = end_line.partition('" ')
                    if avant == 'GET /projects/260 HTTP/1.1': 
                        # la chaine "GET /projects/260 HTTP/1.1" est trouvée
                        end_line = apres
                        avant, separateur, apres = end_line.partition(' ')
                        if (avant in status_codes) and apres.isdigit():
                            status_codes[avant] += 1
                            file_size += int(apres)
                            
        print(f"File size: {file_size}")
        for cle, valeur in status_codes.items():
            if valeur != 0:
                print(f"{cle}: {valeur}")
except KeyboardInterrupt:
    print(f"File size: {file_size}")
    for cle, valeur in status_codes.items():
        if valeur != 0:
            print(f"{cle}: {valeur}")

