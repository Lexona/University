# Si scriva uno script bash che, data una directory in input, crei una cartella per ogni gruppo associato ad almeno un file nella directory e in ognuna
# di queste una sotto-cartella associata ad ogni utente proprietario di almeno un file associato a tale gruppo. All'interno di queste lo script
# sposterà tutti i file appartenenti al gruppo e di proprietà dell'utente. 

#!/bin/bash

dir=$1

# controllo se la cartella è vuota
if ! [[ $(ls) ]]; then
    echo "ERRORE: la cartella è vuota."
    exit 1
fi

for elem in "$dir"/*; do
    gruppo=$(ls -l "$elem" | awk '{print $4}')
    user=$(ls -l "$elem" | awk '{print $3}')
    mkdir -p "$gruppo/$user"
    mv "$elem" "$gruppo/$user"
done

