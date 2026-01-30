# Scrivi uno script Bash che:

# 1 - Controlla una directory specificata come argomento e verifica l'esistenza di file di log (.log).
# 2 - Se esistono file .log, li sposta in una directory chiamata backup_logs (creandola se non esiste).
# 3 - Comprime i file spostati in un archivio .tar.gz nominato con la data corrente (backup_YYYY-MM-DD.tar.gz).
# 4 - Cancella i file originali dalla directory di partenza.

#!/bin/bash

# salvo la cartella passata per argomento
directory=$1

# controllo che l'argomento passato sia una cartella
if [[ ! -d "$directory" ]]; then
    echo "ERRORE: l'argomento passato non è una directory."
    exit 1
fi 

# controllo se la cartella presenta file .log
if ! [[ $(find "$directory" -type f -name "*.log") ]]; then
    echo "Non ci sono file .log in questa cartella."
else
    mkdir -p Backup_logs
    for file in $(find "$directory" -type f -name "*.log"); do 
        mv "$file" Backup_logs
    done
fi

# archivio i file 
tar -czf 2025-01-19.tar.gz Backup_logs/

echo "Fine script..."
exit 0