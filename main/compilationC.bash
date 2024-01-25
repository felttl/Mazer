# EN

# Script to automate compilation of c files with GCC
#     input : file in c
#     compiling in binnary with .sh or .exe
    # and run file after compiling (aoto run)


# it's possible to install a linux terminal to launch this script 
# with eaze (and be very useful)

# FR

# Script pour automatiser la compilation et l'interprétation de fichier en c
#       demande un fichier en entrée avec l'extension en c
#       compile en binaire (pas de .sh ou d'.exe)
#            en utilisant gcc file_entrée.c -o file_sortie
#       lance le fichier file_sortie
#           si le fichier file_sortie est donné il portera ce nom
#           sinon le fichier créé sera aléatoire et sera ensuite lancé


sci(){
    clear
    pwd
    echo -e "\n"
    gcc -Wall -g $( echo "$1") -o $( echo "${1/.c/''}") -lm
    gdb $( echo "${1/.c/''}")
    # manually run and quit with q

    # # 3 steps compiling : 
    # gcc -c $( echo "$1") 
    # gcc $( echo "${1/.c/'.o'}") -o $( echo "${1/.c/'.sh'}") 
    # "./$( echo "${1/.c/'.sh'}")"        
}
sci $1

# end page