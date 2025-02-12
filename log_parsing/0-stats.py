#!/usr/bin/python3
""" Module : Log Parsing."""


import sys


def main():
    # Dictionnaire pour les statistiques
    status_codes = {
        '200': 0, '301': 0, '400': 0, '401': 0,
        '403': 0, '404': 0, '405': 0, '500': 0}
    file_size = 0
    line_count = 0

    # Traitement en temps réel des lignes depuis stdin
    try:
        for line in sys.stdin:
            words = line.split()
            if len(words) >= 2:
                status = words[-2]
                try:
                    size = int(words[-1])
                    file_size += size
                except ValueError:
                    continue
                if status in status_codes:
                    status_codes[status] += 1

                line_count += 1

                if line_count % 10 == 0:
                    print(f"File size: {file_size}")
                    for cle, valeur in status_codes.items():
                        if valeur != 0:
                            print(f"{cle}: {valeur}")

    except KeyboardInterrupt:
        # Gérer l'interruption (par exemple, Ctrl+C)
        pass

    # Affichage des statistiques finales à la fin de l'exécution
    if (line_count % 10 != 0) or line_count == 0:
        print(f"File size: {file_size}")
        for cle, valeur in status_codes.items():
            if valeur != 0:
                print(f"{cle}: {valeur}")


if __name__ == "__main__":
    main()
