#ifndef GENERATION_H
#define GENERATION_H

/**
 * @brief fonction pour générer un labyrinthe aléatoirement avec DFS
 * la fonction renvoie la matrice (dynamique)
 * 
 * 
 * @param nbline nombre de lignes voulues
 * @param nbcol nombre de colonnes voulues
 * 
 * @warning ATTENTION :
 * - il ne doit pas y avoir l'entrée et la sortie trop près
 * - il faut calculer la direction au départ parmis les 4 possibilités
 * - il ne doit pas y avoir de blocage (on doit toujours pouvoir atteindre la sortie)
 * - lors d'un passsage les configurations ou les angles des murs manquantes ne sont pas 
 * autorisés (tous les angles doivent être présents) exemple :
 * 
 * 010                                                 111
 * 101 est considérée comme une impasse incorrecte     101
 * 101  le chemin est correct a droite                 101
 * 
 * fonctionnalité : 
 * - pouvoir avoir des murs qui ne forment pas des cercles (perte de cases a l'intérieur d'un bloc)
 * exemple :
 * []  |____.
 * __  |____|
 * 
 * @example de structure de la matrice labyrinthe (tous sont des 
 * chiffres écrits dans un fichier et extraits sous forme de caractères)
 * [[a, b, c],
 *  [d, e, f],
 *  [g, h, i]]
 * 
 * @return int** 
 */
int** generate(int nbline, int nbcol);


#endif

// end page