#!/bin/bash

# controllo se è stato passato un argomento
if [ -z "$1" ]; then
    echo "Per favore, fornisci un'estensione (senza il punto, ad esempio 'txt')."
    exit 1
fi

estensione=$1
numero_file=0
dimensione_totale=0
file_dimensione_maggiore=()
file_trovati=()

for file in $(find . -type f -name "*.$estensione"); do
    file_trovati+=("$file")
    ((numero_file+=1))        # incremento il conteggio

    # calcoliamo la dimensione totale dei file e ci salviamo i nomi dei file con dimensione maggiore 1000
    dimensione=$(ls -l $file | awk '{print $5}')
    ((dimensione_totale+=dimensione))

    if [[ $dimensione -gt 1000 ]]; then
        file_dimensione_maggiore+=("$(basename "$file" .$estensione)")
    fi
done 

echo "I $numero_file file $estensione occupano un totale di $dimensione_totale"
echo "I seguenti file $estensione hanno dimensione maggiore di 1000 byte:"
echo "${file_dimensione_maggiore[@]}"

echo "Vuoi che li cancelli? (s/n)"
read -r risposta

if [[ $risposta == 's' ]]; then
    cancellati=0
    for f in "${file_trovati[@]}"; do
        dimensione=$(ls -l $file | awk '{print $5}')
        if [[ $dimensione -gt 1000 ]]; then
            rm $file
            ((cancellati+=1))
        fi
    done

    echo "Ho cancellato $cancellati file"
elif [[ $risposta == 'n' ]]; then
    echo "Nessun file è stato cancellato."
    exit 0
else
    echo "Non hai inserito correttamente la risposta."
    exit 1
fi

exit 0