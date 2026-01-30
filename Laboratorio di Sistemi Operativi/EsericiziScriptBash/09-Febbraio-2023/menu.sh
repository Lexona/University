#!/bin/bash

# salvo il file passato per argomento
FILE=$1

# FUNZIONI

cerca() {
	echo "----------------"
	echo "Inserisci una stringa che vuoi trovare nel file:"
	read stringa

	# controllo che la stringa non sia vuota
	if [[ -z "$stringa" ]]; then
		echo "ERRORE: non hai inserito niente."
		return
	fi

	# se l'inserimento va bene cerco la stringa nel file
	if grep -q "$stringa" "$FILE"; then
		echo "Stringa ($stringa) trovata nel file."
	else
		echo "La stringa non e' presente nel file."
	fi
}

aggiungi() {
	echo "--------------------------"
	echo "Inserisci il codice del prodotto:"
	read codice_prodotto
	echo "Quanti ne vuoi?"
	read quantita

	# controllo gli inserimenti fatti
	if ! grep -q "$codice_prodotto" "$FILE" || (( quantita <= 0 )); then
		echo "ERRORE: inserimento non valido."
		return
	fi

	# se gli inserimenti sono corretti, li memorizzo nel file carrello.txt
	echo "$codice_prodotto $quantita" >> carrello.txt
}

elimina() {
	echo "-----------------------"

	# controllo che il file carrello.txt esista e che non sia vuoto
	if [[ ! -s "carrello.txt" ]]; then
		echo "ERRORE: il file non esiste o e' vuoto.";
		return
	fi

	echo "Inserisci il codice del prodotto che vuoi eliminare dal carrello:"
	read codice_prodotto

	# controllo l'inserimento
	if ! grep -q "$codice_prodotto" "carrello.txt"; then
		echo "ERRORE: prodotto non presente nel carrello."
		return
	fi

	# se l'inserimento è corretto, lo cancello dal file carrello.txt
	sed -i "/$codice_prodotto/d" "carrello.txt"

}

# MENU

while true; do
	echo "------------------------"
	echo "Cosa vuoi fare?"
	echo "1 - Cerca una stringa nel file listino.txt"
	echo "2 - Aggiungi un prodotto al carrrello."
	echo "3 - Elimina un prodotto dal carrello"
	echo "4 - Esci"
	read risposta

	case "$risposta" in
		1) cerca ;;
		2) aggiungi ;;
		3) elimina ;;
		4) exit 0 ;;
	esac
done
