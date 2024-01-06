/**
 * author : felix TTL 
 * date : 24/12/2023 - 7/1/2024
 * project name : Mazer
 * 
*/


#include "./add_lib.h"
#include "./display.h"
#include "./pion_chainee.h"
#include "tools.h"// gestion des fichiers + fonction utiles



void main(){

    // on dépose un fichier dans la répertoire

    // on extrait les données + allocation
    char * extracted_data = read_file_char_by_char("input.txt");

    // allocation d'espace pour la matrice
    char ** matrix=(char**)malloc(lines*sizeof(char*));
    for (int i=0;i<cols;i++)matrix[i]=(char*)malloc(cols*sizeof(char));

    // varaibles des coordonnées :
    int ex=0, ey=0;// entrée de la matrice
    int sx=0, sy=0;// sortie de la matrice
    int px=0, py=0;// position du pion de départ

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
        if (extracted_data[i]=='2'){// entree
            ex=x;
            ey=y;
        } else if (extracted_data[i]=='3'){//sortie
            sx=x;
            sy=y;
        } else if(extracted_data[i]=='4'){// pion
            px=x;
            py=y;
        }
    }
    // fermeture de pointeur
    *(*(matrix+x)+y) = '\0';

    // je trouve l'entrée et la sortie
    // je cherche le chemin entre les deux



    // on lache la mémoire 
    // pas besoin de faire un free(matrix[i]) avec uen boucle 
    //(déja des contraintes de liaison avec extracted_data)
    free(extracted_data);
    free(matrix);




}




// end page