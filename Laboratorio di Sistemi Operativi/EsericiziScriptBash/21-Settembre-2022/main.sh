# Si realizzi uno script che elenchi i tipi di files contenuti nella directory classificandoli tramite il tipo ed elenchi per ogni tipo i gruppi che
# possiedono almeno un file di tale tipo, il numero e la dimensione totale dei file da essi posseduti. Ad esempio:
# -: staff 4(8305) users 2(3413)
# d: staff 1(96)
# l: users 1(6)

#!/bin/bash

# controllo se la cartella corrente è vuota
if ! [[ $(ls) ]]; then
    echo "La cartella è vuota!"
    exit 1
fi

for elem in *; do
    # controllo se si tratta di un file regolare
    if [[ -f "$elem" ]]; then
        estensione="${elem##*.}"
        gruppo=$(ls -l "$elem" | awk '{print $4}')
        dimensione=$(ls -l "$elem" | awk '{print $5}')

        echo "$estensione: $gruppo ($dimensione)"
    fi
done | sort | uniq -c | awk '{print $2, $3, $1, $4}'

