#!/bin/bash

function guess_files {
    local file_count=$(ls -1 | wc -l) # Compte le nombre de fichiers dans le répertoire actuel
    while true; do
        echo "Combien de fichiers se trouvent dans le répertoire actuel ?"
        read guess
        if [[ $guess -eq $file_count ]]; then
            echo "Félicitations ! Vous avez trouvé le bon nombre : $file_count."
            break
        elif [[ $guess -lt $file_count ]]; then
            echo "C'est trop bas. Essayez encore."
        else
            echo "C'est trop haut. Essayez encore."
        fi
    done
}

# Appel de la fonction
guess_files
