# Dato un file di testo "paghe.txt" con almeno 6 righe di testo, scrivere uno script "stipendi" che inserisca il titolo "Sig.re" se si tratta di un uomo
# e il titolo "Sig.ra" se si tratta di una donna, prima del nome. Calcolare e mostrare a video lo stipendio minimo, massimo e medio del personale,
# e aggiungere un bonus di x euro (dove x viene inserito dall'utente) allo stipendio minimo. Il fine dovrà contenere i seguenti campi:
# nome, cognome, genere, stipendio, anno di assunzione.

#!/bin/bash

FILE=$1         # salvo il file passato per argomento

echo "Modifica del file..."
sed -i '/femmina/s/^\([^ ]*\)/Sig.ra \1/' "$FILE"
sed -i '/maschio/s/^\([^ ]*\)/Sig.re \1/' "$FILE"

# calcolo lo stipendio minimo
echo "--------------------------------"
stipendio_minimo=$(awk 'BEGIN {min = 1e9} {if (min > $5) min = $5} END {print min}' "$FILE")
echo "Lo stipendio minimo e' di $stipendio_minimo"

# calcolo lo stipendio massimo
echo "--------------------------------"
stipendio_massimo=$(awk 'BEGIN {max = 0} {if (max < $5) max = $5} END {print max}' "$FILE")
echo "Lo stipendio massimo e' di $stipendio_massimo"

# trovo la media di tutti gli stipendi
echo "--------------------------------"
media_stipendi=$(awk '{count++; somma+=$5} END {if (count > 0) print somma/count; else print 0}' "$FILE")
echo "La media di tutti gli stipendi e' di $media_stipendi"

# chiedo e aggiungo il bonus allo stipendio minimo
echo "--------------------------------"
echo "Che bonus gli vuoi aggiungere? (inserisci un numero)"
read bonus

if ! [[ $bonus =~ ^[0-9]*$ ]] || (( bonus < 0 )); then
    echo "ERRORE: inserimento non valido"
    exit 1
fi

# aggiungo il bonus allo stipendio
sed -i "/$stipendio_minimo/s/$stipendio_minimo/$(($stipendio_minimo + $bonus))/" "$FILE"
echo "Bonus aggiunto."
exit 0
