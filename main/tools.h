// package de librairies extérieures
#include "add_lib.h"

// variables globales non constantes
#ifndef isdefined
#define isdefined 0
    static int lines=0, cols=0;
#endif

/**
 * #tools file
 * @brief charge les données d'un fichier dans une chaine de caractère
 * QUELQUE SOIT LA TAILLE DE CHAQUE LIGNE 
 *
*/
char * read_file_char_by_char(char * filename){
    // récupération du nb de lignes et colonnes
    // fichier de sortie
    int size = 5;// taille de départ qui sera réajusté
    FILE *fp=fopen(filename,"r");
    char*sortie_donnee=(char*)malloc(size*sizeof(char));
    // transfert d'addresse pour faire un free en dehors
    int count=0;
    char c=fgetc(fp);
    if (fp!=NULL){
        do {
            // récupère un caractère a la fois
            c=fgetc(fp);
            //printf("%c", c);                 
            strncat(sortie_donnee,&c,1); // concat un char dans un string
            // si pas assez de place en mémoire alors on double l'espace mémoire utilisable
            if (size<count){
                size*=2;                
                sortie_donnee=(char*)realloc(sortie_donnee,size*sizeof(char));
            }
            if (sortie_donnee==NULL){// erreur donnnées
                printf("\n\nproblème de création de l'allocation de mémoire ");
                printf("dynamique dans la variable pointeur %c mémoire : %p\n\n", sortie_donnee[count], sortie_donnee+count);
                exit(EXIT_FAILURE);
            }
            if (c=='\n'){
                lines++;
                if (cols==0){
                    cols=count-2;
                }
            }
            count++;
        } while(c != EOF);
        // réajuste la taille allouée a la bonne taille (pas de perte de mémoire)
        sortie_donnee=(char*)realloc(sortie_donnee,strlen(sortie_donnee)*sizeof(char));
        sortie_donnee[strlen(sortie_donnee)*sizeof(char)-1]='\0';
        fclose(fp);    
        //printf("%d lignes, %d colonnes\n",++lines,++cols); // affiche le nombre de lignes et colonnes aprés lecture 
    } else {
        printf("\n\nerreur : le fichier '%s'n'existe pas ou n'as pas pu être ouvert\n\n", filename);
    }
    return sortie_donnee;
}







/**
 * @brief sauvegarde les données d'une ligne 
 *  (séparateur avec \n pour plusieurs lignes)
 * #tools file
 * 
 *  -   ATTENTION : les données sont écrasées a chaque fois
 *  pour permettre de compiler plusieurs fois le même fichier
 *  de la même manière (si le fichier a la même nom)
 *  mais n'as pas forcément le même contenu dans le fichier d'entree
 * et de sortie
 * 
*/
void save_matr(char**matr, int nbline){
    FILE *fp;
    fp = fopen("out.txt", "w+");
	if(fp == NULL){
        /* File not created hence exit */
        printf("impossible de créer le fichier : (%s)\n", "out.txt");
        exit(EXIT_FAILURE);
    }
    // pour chaque ligne
    for (int i=0;i<nbline;i++){
        fputs(matr[i], fp);
        fputs("\n", fp);
    }
    fclose(fp);
}


/**
 * @brief permet de récupérer les points qui sont au bords
 * d'une matrice de longueur et largeur définie
 * 
 * attention : la forme de la matrice peut soit être carrée
 * soit rectangulaire sinon la formule ne fonctionne plus
 * 
 * @param nblignes le nombre de lignes de la matrice
 * @param nbcolonnes le nombre de colonnes
 * @return les points qui sont au bords de la matrice
 * dans une liste (sauf les 4 angles) du type 
 * #tools file
 * int *2 var
 * 
 * exemple de la structure des données :
 * {{0, 1}, {0,2}, etc...}
 * 
*/
int ** get_borders(int nblignes, int nbcolonnes){
    // tous les bords sauf les angles
    int ** bords = (int**)malloc((2*(nblignes+nbcolonnes)-8) * sizeof(int*));
    
    // obligation de parcourir uniquement les bords
    // car les autres cases du labyrinthe ne nous servent a rien
    // et ce serait une perte de temps inutile (donc pas de double for)
    // ex matrice de 400 * 300 = 120 000 cases 
    // mais uniquement 2*400 + 2*300 - 8 = 1392 cases nous intéressent
    // les angles nous intéressent pas

    // ligne doit toujours être suppérieur a 2 comme le nb de colonnes
    if (nblignes > 2 && nbcolonnes > 2){
        // ajout des points
        int cpt = 0; // connaitre les coordonnées des points dans la liste "bords"
        unsigned const int lenhozitonal = 2*(nblignes-2); // connaitre le nombre de points horizontaux
        for (int x=1;x<nblignes-1;x++){
            bords[cpt] = (int*)malloc(2*sizeof(int));
            **(bords+cpt) = x;
            *(*(bords+cpt)+1) = 0;
            cpt++;        
            bords[cpt] = (int*)malloc(2*sizeof(int));
            **(bords+cpt) = x;
            *(*(bords+cpt)+1) = nbcolonnes-1;
            cpt++;
        }
        cpt=0;
        for (int y=1;y<nbcolonnes-1;y++){
            bords[cpt+lenhozitonal] = (int*)malloc(2*sizeof(int));
            **(bords+cpt+lenhozitonal) = 0;
            *(*(bords+cpt+lenhozitonal)+1) = y;
            cpt++;
            bords[cpt+lenhozitonal] = (int*)malloc(2*sizeof(int));
            **(bords+cpt+lenhozitonal) = nblignes-1;
            *(*(bords+cpt+lenhozitonal)+1) = y;
            cpt++;
        }
    } else {
        printf("error: le nombre de lignes ou colonnees n'est pas suffisament élevé pour cette fonction\n");
        exit(EXIT_FAILURE);
    } 
    return bords;      
}


/**
 * @brief permet de récupérer le longueur d'un array de points
 * #tools file
 * @return le nombre déélément dans la liste
*/
int get_number_borders(int line, int col){
    return 2*(line+col-4);
}



/**
 * @brief fonction pour mettre les données d'un fichier 
 * dans une matrice de char 2d dynamique 
 * @ref github see : https://github.com/portfoliocourses/c-example-code/blob/main/files_lines_to_dynamic_array.c
*/
char ** get_char_array_fromfile(char*filename){
  FILE *file = fopen(filename, "r");
  if (file == NULL){
    printf("Error opening file.\n");
    exit(EXIT_FAILURE);
  }
  char **lines;
  lines = malloc(sizeof(char*) * MORE_LINES);
  size_t total_lines = 0;
  size_t total_chars = 0;
  char c;
  do {
    c = fgetc(file);
    if (ferror(file)){
      printf("Error reading from file.\n");
      return 1;
    }
    if (feof(file)){
      if (total_chars != 0){        
        lines[total_lines] = realloc(lines[total_lines], total_chars + 1 );
        lines[total_lines][total_chars] = '\0';
        total_lines++;
      }
      break; 
    }
    if (total_chars == 0) lines[total_lines] = malloc(MORE_CHARS); 
    lines[total_lines][total_chars] = c; 
    total_chars++;
    if (c == '\n'){
      lines[total_lines] = realloc(lines[total_lines], total_chars + 1 );
      lines[total_lines][total_chars] = '\0';
      total_lines++;
      total_chars = 0;
      if (total_lines % MORE_LINES == 0){
        size_t new_size = total_lines + MORE_LINES;
        lines = realloc(lines, sizeof(char *) * new_size);
      }
    } else if (total_chars % MORE_CHARS == 0){
      size_t new_size = total_chars + MORE_CHARS;
      lines[total_lines] = 
        realloc(lines[total_lines], new_size); 
    }
  } while (true);
  lines = realloc(lines, sizeof(char *) * total_lines);
//   for (size_t i = 0; i < total_lines; i++)
//     free(lines[i]);
//   free(lines);
  fclose(file);
  // maj "param passing"

  return lines;
}




// end page