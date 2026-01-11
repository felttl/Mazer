/* main.c */

/* our librairies */
#include "../include/ui/term/display.h"
#include "../include/pion_chain.h" // le fichier #include tools.h
#include "../include/load.h"
#include "../include/save.h"
#include "../include/utils/tools.h"
#include "../include/utils/map.h"
/* external librairies */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// («) last - next (»)

/**
 * @author Félix TTL
 * @date 24/12/2023 - 9/1/2024 14h40 (2:40 pm) (V1)
 * @date dec 2025
 * @version V2
 * @project_name : Mazer
 */
int main(){
    ERR_PUSH_STACKTRACE();
    // init once the rand() function (ONLY ONCE PLZ)
    srand( time( NULL ) ); // init random func

    // nombre de lignes et nombre de colonnes
    int x=0;
    int y=0;
    // on demande le nom du fichier
    char filename[60]="data/test5ct.txt";

    // "interface utilisateur" coté terminal ?

    // on extrait les données + allocation
    char**matrix=get_char_array_fromfile(filename, &x, &y);

    // j'affiche la matrice avant de rajouter le chemin
    display(matrix, x, y);
    printf("\033[2J");  // clear screen

    // on récupère les données d'initialisation/collect data for init
    int ex=0, ey=0;// l'entrée/input
    int sx=0, sy=0;// sortie/output
    _4d_heading heading_in; // orientation pour le pion de l'entrée
    _4d_heading heading_out; // orientation pour le pion de la sortie
    // si on a trouvé les coordonées entree sortie on continue    
    if (!get_mazer_io(matrix, '2', '3', x, y, &ex, &ey, &sx, &sy, &heading_in, &heading_out)){
        printf("les coordonnées d'entrée/sortie n'ont pas étés trouvées");
        printf("ou incohérence des données(ex: plusieurs entrées\n");
    } else {
        printf("matrice en commencant par l'entrée en méthode rotation a droite:\n");
        // on commence par l'entrée en tournant a droite
        // affichange déja inclu dans la fonction réccursive  
        forward_right(&matrix, ex, ey, sx, sy, x, y, heading_in);  
  
        // on utilise l'algo DFS
        // Pion*cheminDFS=pn_add_path(          (matrix, ex, ey, sx, sy, x, y), matrix2);
        // printf("chemin créer avec l'algorithme DFS\n");
        // display(matrix3, x, y);

        // j'enregistre le tout dans le répertoire courant (pour la première méthode)
        // on se sauvegarde pas les matrices avec les autres algo car c'est le même
        // resultat
        // on peut faire la fonction avant ou aprés avoir écrit le chemin de sortie dedans
        save_matr(matrix, x, "./out.txt");
    }


    printf("\n");
    printf("\033[2J");  // clear screen
    simple_display(matrix, x, y); // exemple simpliste


    // libération de mémoire
    // REGLE d'or/Golden Rule: 
    // 1 free par 1 malloc/calloc/realloc utilisés
    for (; x>0; x--){
        free(matrix[x]);
    }
    free(matrix);
    return 0;
}




// end page