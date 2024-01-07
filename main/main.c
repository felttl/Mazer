/**
 * author : felix TTL 
 * date : 24/12/2023 - 7/1/2024
 * project name : Mazer
 * 
*/


#include "./add_lib.h"
#include "./display.h"
#include "./pion_chain.h"
#include "tools.h"// gestion des fichiers + fonction utiles



void main(){
    // on dépose un fichier dans la répertoire

    // on extrait les données + allocation
    char * extracted_data = read_file_char_by_char("input.txt");

    // allocation d'espace pour la matrice
    char ** matrix=(char**)malloc(lines*sizeof(char*));
    for (int i=0;i<cols;i++)matrix[i]=(char*)malloc(cols*sizeof(char));

    // variables des coordonnées :
    int ex=0, ey=0;// entrée de la matrice

    // placement des données dans la matrice
    int x=0;y=0;// ligne colonne
    for (int i=0;i<strlen(extracted_data);i++){
        if (extracted_data[i] == '\n'){// changement de ligne   
            // fin de string
            matrix[x][y]='\0';      
            x++;
            y=0;
        } else {
            matrix[x][y] = extracted_data[i];
            y++;            
        }
        if (extracted_data[i]=='2'){// entree (1 iteration)
            ex=x;
            ey=y;
        } 
    }
    // fermeture de pointeur
    *(*(matrix+x)+y) = '\0';

    // j'affiche la matrice avant de rajouter le chemin
    display(matrix, lines, cols);

    // je cherche le chemin entre l'entrée et la sortie
    // une fois que je tiens la chaine de piosn entre l'entrée et la sortie
    // je change les cases concernées dans la matrice pour voir le chemin a l'affichange
    // je récupère le chaine pour pouvoir libérer la mémoire prise par le programme
    Pion*chemin=add_path(forward_right(matrix, ex, ey, lines, cols));

    // j'affiche la matrice aprés avoir ajouté le chemin
    display(matrix, lines, cols);

    // j'enregistre le tout dans le répertoire courant
    // on peut faire la fonction avant ou aprés avoir écrit le chemin de sortie dedans
    save_matr(matrix, lines);

    // on lache la mémoire 
    // pas besoin de faire un free(matrix[i]) avec uen boucle 
    //(déja des contraintes de liaison avec extracted_data)
    free(extracted_data);
    free(matrix);
    free_pion_chain(chemin);
}




// end page