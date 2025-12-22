/* main.c */

/* our librairies */
#include "ui/term/display.h"
#include "./pion_chain.h" // le fichier #include tools.h
#include "./load.h"
#include "./save.h"
#include "./tools.h"
/* generic librairies */
#include <stdio.h>
#include <stdlib.h>


/**
 * author : felix TTL 
 * date : 24/12/2023 - 9/1/2024 14h40 (2:40 pm) (V1)
 * project name : Mazer
 * 
*/

int main(){
    // nombre de lignes et nombre de colonnes
    int x=0;
    int y=0;

    // on demande le nom du fichier
    char filename[60]="../../data/test5ct.txt";

    // // "interface" avec le terminal
    // printf("\n");
    // printf("veuillez entrer le nom \n");
    // printf("du fichier ou se trouve le labyrinthe:\n");
    // scanf("%s", filename);
    // le fichier est test5ct.txt

    // on extrait les données + allocation
    char**matrix=get_char_array_fromfile(filename, &x, &y);
    char**matrix1=get_char_array_fromfile(filename, &x, &y); // tester en passant par la sortie
    char**matrix2=get_char_array_fromfile(filename, &x, &y); // tester avec un autre algo spécifique

    // j'affiche la matrice avant de rajouter le chemin
    display(matrix, x, y);

    // on récupère les données d'initialisation/collect data for init
    int ex=0, ey=0;// l'entrée/input
    int sx=0, sy=0;// sortie/output
    int heading_in; // orientation pour le pion de l'entrée
    int heading_out; // orientation pour le pion de la sortie
    // si on a trouvé les coordonées entree sortie on continue    
    if (get_mazer_io(matrix, '2', '3', x, y, &ex, &ey, &sx, &sy, &heading_in, &heading_out)){
        printf("matrice en commencant par l'entrée en méthode rotation a droite:\n");
        // on commence par l'entrée en tournant a droite
        // affichange déja inclu dans la fonction réccursive  
        forward_right(&matrix, ex, ey, sx, sy, x, y, heading_in);  

        // on charge les même données pour les 3 cas
        printf("méthode en commençant par la sortie(+ rotation droite)\n");    
        forward_right(&matrix1, sx, sy, ex, ey, x, y, heading_out);

        // on commmence par la sortie avec l'algo de proche en proche
        Pion*chemin2=pn_add_path(pn_shortest_way(matrix2, ex, ey, sx, sy, x, y), matrix2);
        printf("chemin créé avec la méthode de parcours de proche en proche\n");
        display(matrix2, x, y);      

        // on utilise l'algo DFS
        // Pion*cheminDFS=pn_add_path(          (matrix, ex, ey, sx, sy, x, y), matrix2);
        // printf("chemin créer avec l'algorithme DFS\n");
        // display(matrix3, x, y);

        // j'enregistre le tout dans le répertoire courant (pour la première méthode)
        // on se sauvegarde pas les matrices avec les autres algo car c'est le même
        // resultat
        // on peut faire la fonction avant ou aprés avoir écrit le chemin de sortie dedans
        save_matr(matrix, x);

        // on lache la mémoire  
        pn_free_chain(chemin2);        
        //free_pion_chain(cheminDFS);  
    } else {
        printf("les coordonnées d'entrée/sortie n'ont pas étés trouvées");
        printf("ou incohérence des données(ex: plusieurs entrées\n");
    }

    printf("\n");
    simple_display(matrix, x, y); // exemple simpliste


    // libération de mémoire
    // REGLE d'or/Golden Rule: 
    // 1 free par 1 malloc/calloc/realloc utilisés
    for (unsigned char i=0; i<x; i++){
        free(matrix[i]);   
        free(matrix1[i]);           
        free(matrix2[i]);                 
    }
    free(matrix);   
    free(matrix1);      
    free(matrix2);          
    return 0;
}




// end page