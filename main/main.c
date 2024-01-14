/**
 * author : felix TTL 
 * date : 24/12/2023 - 9/1/2024 14h40 (2:40 pm)
 * project name : Mazer
 * 
*/

#include "./add_lib.h"
#include "./display.h"
#include "./pion_chain.h" // le fichier #include tools.h
#include "./load.h"
#include "./save.h"

int main(){
    // on dépose un fichier dans le répertoire

    // nombre de lignes et nombre de colonnes
    int x=0;
    int y=0;

    // on demande le nom du fichier
    char filename[60]="test5ct.txt";

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
    int heading; // orientation
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            if (matrix[i][j] == '2'){
                ex=i;
                ey=j;
                // calcul de l'orientation (seulement pour le point d'entrée pas de sortie)
                if (ex == 0){// we are in north
                    heading=1;
                } else if (ex == x-1){// we are in south
                    heading=0;
                } else if (ey == 0){// we are in est
                    heading=2;
                } else if (ey == y-1){// we are in west
                    heading=3;
                }
            } else if (matrix[i][j] == '3'){
                sx=i;
                sy=j;                
            }
        }
    }
    // on commence cette fois par la sortie
    printf("matrice en commencant par l'entrée en méthode rotation a droite:\n");
    // on cherche la sortie et on renvoie le pointeur pour liberer la memoire
    // on commence par l'entrée en tournant a droite
    forward_right(&matrix, ex, ey, sx, sy, x, y, heading);    


    // on comence par la sortie en tournant a droite
    printf("méthode en commençant par la sortie(+ rotation droite)\n");    
    forward_right(&matrix1, sx, sy, ex, ey, x, y, 1);

    // display(matrix1, x, y);    

    // on commmence par la sortie avec l'algo de proche en proche
    Pion*chemin2=add_path(shortest_point_way(matrix2, ex, ey, sx, sy, x, y), matrix2);
    printf("chemin créé avec la méthode de parcours de proche en proche\n");
    display(matrix2, x, y);  
    
    // on utilise l'algo DFS
    // Pion*cheminDFS=add_path(          (matrix, ex, ey, sx, sy, x, y), matrix2);
    // printf("chemin créer avec l'algorithme DFS\n");
    // display(matrix3, x, y);        

    // j'enregistre le tout dans le répertoire courant (pour la première méthode)
    // on se sauvegarde pas les matrices avec les autres algo car c'est le même
    // resultat
    // on peut faire la fonction avant ou aprés avoir écrit le chemin de sortie dedans
    save_matr(matrix, x);

    // on lache la mémoire  
    free_pion_chain(chemin2);
    //free_pion_chain(cheminDFS);  

    // pas besoin de léibérer chaque valeur dynamique
    // matrix1 et 2 déja libéré par les lignes qui suivent:
    // REGLE d'or/Golden Rule: 
    // 1 free par 1 malloc/calloc/realloc utilisés
    for (short int i=0; i<x; i++){
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