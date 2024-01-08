/**
 * author : felix TTL 
 * date : 24/12/2023 - 9/1/2024 14h40 (2:40 pm)
 * project name : Mazer
 * 
*/


#include "./add_lib.h"
#include "./display.h"
#include "./pion_chain.h"
#include "./load.h"
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


    // j'affiche la matrice avant de rajouter le chemin
    display(matrix, x, y);

    // on récupère l'entrée
    int ex=0, ey=0;
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            if (matrix[i][j] == '2'){
                ex=i;
                ey=j;
            }
        }
    }
    // on cherche la sortie et onn renvoie le pointeur pour 
    // libérer la mémoire
    Pion*chemin=add_path(forward_right(matrix, ex, ey, x, y), matrix);

    // j'affiche la matrice aprés avoir ajouté le chemin
    display(matrix, x, y);

    // j'enregistre le tout dans le répertoire courant
    // on peut faire la fonction avant ou aprés avoir écrit le chemin de sortie dedans
    save_matr(matrix, x);

    // on lache la mémoire 
    free_pion_chain(chemin);
    for (size_t i = 0; i < x; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}




// end page