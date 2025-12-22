/* Graph.h */
#ifndef GRAPHS_H
#define GRAPHS_H


/**
 * @brief data structure to show the path and store data on a maze
 * 
 * - x int : coordinate on the map horizontally
 * 
 * - y int : coordinate on the map vertically
 */
typedef struct Point2D Point2D;

/**
 * @brief cell container that store cell states
 * have this attributes :
 * 
 * - way : empty cell
 * 
 * - wall : the cell contains a wall
 * 
 * - home : is where the user starts
 * 
 * - exit : is where the user wants to go
 * 
 * - visited : the user already moved this way
 * 
 * - forbiden : all cells marked as forbiden
 * 
 */
typedef enum Cell Cell;

/**
 * @brief fonction qui permet de mélanger des points aléatoirement
 * en déplacant les éléments contenu dans la liste d'entrée. 
 * La liste est de la forme suivante :
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
Point2D* pt_random_shuffle(Point2D* dynamic_arr, int len);


/**
 * @brief permet de générer un chemin aléatoirement (cohérents) 
 * dans une matrice remplie de murs
 * 
 * @param matr_lines int : nombre de lignes de la matrice
 * @param matr_cols int : npmbre de colonnes de la matrice
 * @param start Point : position du point initiale (entrée du labyrinthe)
 * @param stop Point : position de la sortie
 * @return char** : une matrice 2D avec les murs générés
 * 
 *  *fonction generer_labyrinthe_dfs(matrice, position_actuelle):
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
 * @warning allocate memory (if fail may stop the wole program)
 */
char** pt_generate_DFS_maze(int matr_lines, int matr_cols, Point2D start, Point2D stop);

/**
 * @brief reccursive function to use with `pt_generate_DFS_maze()`
 * 
 * @param matr char** : reccursive empty matrix
 * @param matr_lines int : nombre de lignes de la matrice
 * @param matr_cols int : npmbre de colonnes de la matrice
 * @param start Point : position du point initiale (entrée du labyrinthe)
 * @param stop Point : position de la sortie
 * @return char** : une matrice 2D avec les murs générés
 */
char** pt_generate_DFS_maze_rec(char** matr, int matr_lines, int matr_cols, Point2D start, Point2D stop);

#endif

/* end page */
