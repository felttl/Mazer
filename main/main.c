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
// déja importé dans pion_chain
//#include "./tools.h"// gestion des fichiers + fonction utiles

int main(){
    // on dépose un fichier dans la répertoire

    // nombre de lignes et nombre de colonnes
    int x=0;
    int y=0;

    // on demande le nom du fichier
    char filename[60];

    // // "interface" avec le terminal
    printf("\n");
    printf("veuillez entrer le nom \n");
    printf("du fichier ou se trouve le labyrinthe:\n");
    scanf("%s", filename);

    // on extrait les données + allocation
    char**matrix = get_char_array_fromfile(filename, &x, &y);
    char**matrix1=matrix; // pour tester avec un parcour en commençant par la fin
    char**matrix2=matrix; // tester avec un autre algo spacifique

    // j'affiche la matrice avant de rajouter le chemin
    display(matrix, x, y);

    // on récupère l'entrée et la sortie
    int ex=0, ey=0;
    int sx=0, sy=0;
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            if (matrix[i][j] == '2'){
                ex=i;
                ey=j;
            } else if (matrix[i][j] == '3'){
                sx=i;
                sy=j;                
            }
        }
    }
    // on cherche la sortie et on renvoie le pointeur pour libere la memoire
    // on comence par l'entrée en tournant a droite
    Pion*chemin=add_path(forward_right(matrix, ex, ey, x, y), matrix);
    // on commence cette fois par la sortie
    printf("matrice en commencant par l'entrée en méthode rotation a droite:\n");
    // j'affiche la matrice aprés avoir ajouté le chemin    
    display(matrix, x, y); 

    // on comence par la sortie en tournant a droite
    Pion*chemin1=add_path(forward_right(matrix1, sx, sy, x, y), matrix1);
    printf("chemin tracé avec la méthode de début à la fin (+ rotation droite)\n");
    display(matrix1, x, y);    

    // on commmence par la sortie avec l'algo de proche en proche
    Pion*chemin2=add_path(shortest_point_way(matrix2, ex, ey, sx, sy, x, y), matrix2);
    printf("chemin créé avec la méthode de parcours de proche en proche\n");
    display(matrix2, x, y);  
    
    // on utilise l'algo DFS
    // Pion*cheminDFS=add_path(          (matrix, ex, ey, sx, sy, x, y), matrix2);
    // printf("chemin créer avec l'algorithme DFS\n");
    // display(matrix2, x, y);        

    // j'enregistre le tout dans le répertoire courant (pour la première méthode)
    // on se sauvegarde pas les matrices avec les autres algo car c'est le même
    // resultat
    // on peut faire la fonction avant ou aprés avoir écrit le chemin de sortie dedans
    save_matr(matrix, x);

    // on lache la mémoire 

    free_pion_chain(chemin);  
    free_pion_chain(chemin1);   
    free_pion_chain(chemin2);
    //free_pion_chain(cheminDFS);    
    for (size_t i = 0; i < x; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}




// end page