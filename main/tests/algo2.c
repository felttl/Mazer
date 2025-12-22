#include "../add_lib.h"
#include "../display.h"
#include "../pion_chain.h"


// la taille de chaque bloc de mémoire qui enregistr tous 
// les caractères dans chaque lignes (MORE_CHARS)
// et pour la liste dynamique de pointeurs ver les caractères
// qui pointent ver la chaine/lignes (MORE_LINES)
#define MORE_LINES 1024
#define MORE_CHARS 1024


/**
 * @brief fonction pour mettre les données d'un fichier 
 * dans une matrice de char 2d dynamique 
 * @ref github see : https://github.com/portfoliocourses/c-example-code/blob/main/files_lines_to_dynamic_array.c
*/
char ** get_char_array_fromfile(char*filename, int*finallines, int*finalcols){
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
      exit(EXIT_FAILURE);
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
      if (*finalcols==0)
        *finalcols=total_chars-1;// nb cols
      total_chars = 0;
      if (total_lines % MORE_LINES == 0){
        size_t new_size = total_lines + MORE_LINES;
        lines = realloc(lines, sizeof(char *) * new_size);
      }
    } else if (total_chars % MORE_CHARS == 0){
      size_t new_size = total_chars + MORE_CHARS;
      lines[total_lines] = realloc(lines[total_lines], new_size); 
    }
  } while (true);
  lines = realloc(lines, sizeof(char *) * total_lines);
  fclose(file);
  *finallines=total_lines; // nb lines
  return lines;
}


int main(){ // gdb debugger


    int lines=0, cols=0;

    // récupère la chaine de données
    char ** matrix = get_char_array_fromfile("test5ct.txt", &lines, &cols);
    printf("\n\nlines : %d cols : %d\n", lines, cols);

    // on récupère l'entrée et la sortie
    int ex=0, ey=0;
    int sx=0, sy=0;
    for (int i=0;i<lines;i++){
        for (int j=0;j<cols;j++){
            if (matrix[i][j] == '2'){
                ex=i;
                ey=j;
            } else if (matrix[i][j] == '3'){
                sx=i;
                sy=j;                
            }
        }
    }
    // si l'entrée ou sortie ne sont pas présente
    //  dans la matrice :
    if (ex == ey || sx == sy){
      printf("entrée ou sortie non présente dans la matrice\n\n");
    }

    // on trace la sortie
    Pion*chemin=pn_add_path(pn_shortest_way(matrix, ex, ey, sx, sy, lines, cols), matrix);

    display(matrix, lines, cols);



    // relache la mémoire
    free_pion_chain(chemin);
    for (size_t i = 0; i < lines; i++)
        free(matrix[i]);
    free(matrix);
    return 0;
}



// end page