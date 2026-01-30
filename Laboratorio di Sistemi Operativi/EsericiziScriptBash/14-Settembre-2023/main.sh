# Scrivere uno script bash che si sposta nella home directory, crea una nuova directory chiamata "LSO", e copia tutti i file contenuti nella directory
# /etc in questa. Assicurarsi che tutti i file e le directory siano copiate ricorsivamente (quindi anche le sottodirectory). Spostarsi nella nuova
# directory, e creare una directory per tutti i file che hanno una lettera maiuscola. Spostare tutti i file che iniziano con una lettera minuscola
# all'interno delle directory.

#!/bin/bash

# vado nella cartella home
cd ~

# creo la nuova directory
dir_lso="LSO"
mkdir -p "$dir_lso"

# copio tutti i file da /etc a LSO
cp -r /etc/* "$dir_lso"

# mi sposto nella nuova directory
cd "$dir_lso"

# Creare directory per file con lettere maiuscole e minuscole
mkdir -p Uppercase Lowercase

# trovo tutti i file che iniziano per lettera maiuscola
find . -type f -name ^[:upper:] -exec mv {} Uppercase/ \;

# trovo tutti i file che iniziano per lettera minuscola
find . -type f -name ^[:lower:] -exec mv {} Lowercase/ \;
