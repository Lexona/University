#!/bin/bash

first_dir=$1
second_dir=$2
file_copiati=()

# controllo che siano state passate delle cartelle e che non siano vuote
if ! [[ -d "$first_dir" ]] || ! [[ -d "$second_dir" ]]; then
    echo "Non sono state passate due cartelle come argomento allo script."
    exit 1
elif [[ -z "$(ls "$first_dir")" ]] || [[ -z "$(ls "$second_dir")" ]]; then
    echo "Una delle due directory passate e' vuota."
    exit 1
fi

# MAIN

echo "Inizio script..."

# scorro gli elementi della prima directory
echo "Controllo gli elementi della prima directory nella seconda..."

for elem in $(find "$first_dir" -type f); do
    filename=$(basename "$elem")

    if [[ ! -e "$second_dir/$filename" ]]; then
        cp "$elem" "$second_dir"
        echo "$elem copiano in $second_dir"
        file_copiati+="$elem"
    fi
done

# scorro gli elementi della seconda directory
echo "Controllo gli elementi della seconda directory nella prima..."
for elem in $(find "$second_dir" -type f); do
    filename=$(basename "$elem")

    if [[ ! -e "$first_dir/$filename" ]]; then
        cp "$elem" "$first_dir"
        echo "$elem copiato in $fist_dir"
        file_copiati+="$elem"
    fi
done

echo "---------------------------"
echo "La prima cartella contiene: "
echo "$(find "$first_dir" -type f)"
echo "La sua dimensione: $(ls -l "$first_dir" | awk '{print $5}')"

echo "---------------------------"
echo "La seconda cartella contiene: "
echo "$(find "$second_dir" -type f)"
echo "La sua dimensione: $(ls -l "$second_dir" | awk '{print $5}')"

echo "---------------------------"
echo "I file copiati sono:"
for file in "${file_copiati[@]}"; do
    echo "$file"
done

