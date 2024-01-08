

#include <time.h>


// algorithme dfs

typedef struct Point{
    size_t x, y;
} Point;

/*
 def generer_labyrinthe_dfs(matrice, position_actuelle):
    i =position_actuelle[0]
    j = position_actuelle[1]
     directions = [(0, 2), (0, -2), (2, 0), (-2, 0)]

     random.shuffle(directions) // mélange les directions

     for di, dj in directions:
         ni, nj = i + di, j + dj

         if 0 <= ni < 1100 and 0 <= nj < 1100 and matrice[ni][nj] == 1:
             matrice[(i + ni) // 2][(j + nj) // 2] = 0
             matrice[ni][nj] = 0
             generer_labyrinthe_dfs(matrice, (ni, nj))

*/

/**
 * @brief fonction qui permet de mélanger des points aléatoirement en déplacant les
 * éléments contenu dans la liste d'entrée la liste est de la forme suivante :
 * 
 * {{0, 1},{4, 8}, etc...}
 * 
 * "random shuffle algorithm"
 * 
 * algorithm :
 * 
 * arr a of n elements
 * for i from n−1 down to 1 do
 *      j ← random integer such that 0 ≤ j ≤ i
 *       exchange a[j] and a[i]
*/
int**random_shuffle(int**dynamic_arr, int len){
    srand( time( NULL ) );// init random func
    int**temp=dynamic_arr;
    Point*tem;
    int i=0;
    int rd;
    while(i < len-1){
        rd = rand()%(i+1);
        tem = temp[i];
        temp[i] = temp[j];
        temp[j] = tem;
        i++;
    }
    return temp;
}   



/**
 * @brief permet de générer un chemin aléatoirement (cohérents) 
 * dans une matrice remplie de murs
 * 
 * 
 * l'algorithme se trouve en anglais tout en haut de la page !!!!!!!!
*/
char ** generate_DFS_maze(char**matr, int posx,int posy){
    int x=posx;
    int y=posy;

    return matr;
}




// end page