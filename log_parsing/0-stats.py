#!/usr/bin/python3
""" Module : Log Parsing."""


import sys
import re
from collections import defaultdict

def main():
    # Dictionnaire pour les statistiques
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
    line_count = 0

    # Expression régulière pour extraire les informations du log
    log_pattern = re.compile(
        r"(?P<ip>\d+\.\d+\.\d+\.\d+) - \[.*\] \"GET /projects/\d+ HTTP/1.1\" (?P<status>\d{3}) (?P<size>\d+)"
    )

    # Traitement en temps réel des lignes depuis stdin
    try:
        for line in sys.stdin:
            line = line.strip()  # Enlever les espaces et retours à la ligne

            # Ne rien faire si la ligne est vide
            if not line:
                continue

            # Extraire les données de la ligne à l'aide de l'expression régulière
            match = log_pattern.match(line)
            if match:
                status = match.group("status")
                size = int(match.group("size"))

                # Mettre à jour les statistiques
                status_codes[status] += 1
                file_size += size

                # Incrémenter le compteur de lignes
                line_count += 1

                # Afficher les statistiques cumulées tous les 10 logs
                if line_count % 10 == 0:
                    print(f"File size: {file_size}")
                    for cle, valeur in status_codes.items():
                        if valeur != 0:
                            print(f"{cle}: {valeur}")

    except KeyboardInterrupt:
        # Gérer l'interruption (par exemple, Ctrl+C)
        pass

    # Affichage des statistiques finales à la fin de l'exécution
    if line_count % 10 != 0:
        print(f"File size: {file_size}")
        for cle, valeur in status_codes.items():
            if valeur != 0:
                print(f"{cle}: {valeur}")

if __name__ == "__main__":
    main()