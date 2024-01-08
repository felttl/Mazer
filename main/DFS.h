

#include <time.h>


// algorithme dfs

typedef struct Point{
    size_t x, y;
} Point;

/*


*/


/**
 * @brief fonction qui permet de mélanger des points aléatoirement en déplacant les
 * éléments contenu dans la liste d'entrée la liste est de la forme suivante :
 * 
 * {{0, 1},{4, 8}, etc...}
 * 
 * "random shuffle algorithm"
 * 
 * algorithm (wikipedia):
 * 
 * arr a of n elements
 * for i from n−1 down to 1 do
 *      j ← random integer such that 0 ≤ j ≤ i
 *       exchange a[j] and a[i]
 * 
 * @return le pointeur de l'arrays dynamique qu'il faudre libérer
*/
Point*random_shuffle(Point*dynamic_arr, int len){
    srand( time( NULL ) );// init random func
    int**temp=dynamic_arr;
    Point*tem;
    int i=0,rd;
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
 *fonction generer_labyrinthe_dfs(matrice, position_actuelle):
 *    i=position_actuelle[0]
 *    j=position_actuelle[1]
 *    directions = [(0, 2), (0, -2), (2, 0), (-2, 0)]
 *
 *    random.shuffle(directions) // mélange les directions aléatoirement
 *
 *    pour di, dj dans directions: // on prend en même temps les 2 coordonnées du point
 *         ni, nj = i + di, j + dj
 *         // si pas déja visité
 *         si 0 <= ni < 1100 and 0 <= nj < 1100 and matrice[ni][nj] == 1 faire
 *             matrice[(i + ni) // 2][(j + nj) // 2] = 0
 *             matrice[ni][nj] = 0
 *             generer_labyrinthe_dfs(matrice, (ni, nj))
 *         fin si
 *    fin pour
*/
char ** generate_DFS_maze(char**matr, int matr_lines, int matr_cols, int posx,int posy){
    int i=posx,j=posy;
    int x, y;
    Point*dir=(Point*)malloc(4*sizeof(Point));
    Point insert={0, 2};
    dir[0]=insert;
    insert.x=0;
    insert.y=-2;
    dir[1]=insert;
    insert.x=2;
    insert.y=0;    
    dir[2]=insert;
    insert.x=-2;
    insert.y=0;       
    dir[3]=insert;
    dir=random_shuffle(dir, 4);
    // position actuelle
    insert.x=posx;
    insert.y=0;    
    x=0+dir[0].x;
    y=0+dir[0].y;
    if (x>0&&x<matr_lines-1&&y>0 &&y<matr_cols&&matr[x][y]=='1'){
        matr[(int)(i+x)/2][(int)(j+y)/2]='0';
        matr[x][y]='0';
        generate_DFS_maze(matr, matr_lines, matr_cols, x, y);
    }
    x=1+dir[1].x;
    y=1+dir[1].y;
    if (x>0&&x<matr_lines-1&&y>0 &&y<matr_cols&&matr[x][y]=='1'){
        matr[(int)(i+x)/2][(int)(j+y)/2]='0';
        matr[x][y]='0';
        generate_DFS_maze(matr, matr_lines, matr_cols, x, y);
    }
    x=2+dir[2].x;
    y=2+dir[2].y;
    if (x>0&&x<matr_lines-1&&y>0 &&y<matr_cols&&matr[x][y]=='1'){
        matr[(int)(i+x)/2][(int)(j+y)/2]='0';
        matr[x][y]='0';
        generate_DFS_maze(matr, matr_lines, matr_cols, x, y);
    }
    x=3+dir[3].x;
    y=3+dir[3].y;
    if (x>0&&x<matr_lines-1&&y>0 &&y<matr_cols&&matr[x][y]=='1'){
        matr[(int)(i+x)/2][(int)(j+y)/2]='0';
        matr[x][y]='0';
        generate_DFS_maze(matr, matr_lines, matr_cols, x, y);
    }
    free(dir);
    return matr;
}




// end page