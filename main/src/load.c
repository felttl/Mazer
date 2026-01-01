/*load.c*/
// internal librairies
#include "../include/load.h"
// external librairies
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char** get_char_array_fromfile(char* filename, int* finallines, int* finalcols){
	// la taille de chaque bloc de mémoire qui enregistr tous 
	// les caractères dans chaque lignes (more_chars)
	// et pour la liste dynamique de pointeurs ver les caractères
	// qui pointent ver la chaine/lignes (more_lines)  
	int more_lines=1024;
	int more_chars=1024;
	FILE* file = fopen(filename, "r");
	if (file == NULL){
		printf("Error opening file \"%s\" \n", filename);
		exit(EXIT_FAILURE);
	}
	char **lines;
	lines = malloc(sizeof(char*) * more_lines);
	size_t total_lines = 0;
	size_t total_chars = 0;
	char c;
	unsigned short carry=1;
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
			carry=0; 
		}
		if (total_chars == 0) lines[total_lines] = malloc(more_chars); 
		lines[total_lines][total_chars] = c; 
		total_chars++;
		if (c == '\n'){
			lines[total_lines] = realloc(lines[total_lines], total_chars + 1 );
			lines[total_lines][total_chars] = '\0';
			total_lines++;
			if (*finalcols==0)
				*finalcols=total_chars-1;// nb cols
			total_chars = 0;
			if (total_lines % more_lines == 0){
				size_t new_size = total_lines + more_lines;
				lines = realloc(lines, sizeof(char *) * new_size);
			}
		} else if (total_chars % more_chars == 0){
			size_t new_size = total_chars + more_chars;
			lines[total_lines] = realloc(lines[total_lines], new_size); 
		}
	} while (carry==1);
	lines = realloc(lines, sizeof(char *) * total_lines); // ajustement definitif
	fclose(file);
	*finallines=total_lines; // nb lines
	return lines;
}

char * read_file_char_by_char(char * filename, int*nblines, int*nbcols){
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
			// sert a renvoyer le nb de lignes et colonnes de la matrice
			if (c=='\n'){
				*nblines+=1;
				if (*nbcols==0){
					*nbcols=count-2;
				}
			}
			count++;
		} while(c != EOF);
		// réajuste la taille allouée a la bonne taille (pas de perte de mémoire)
		sortie_donnee=(char*)realloc(sortie_donnee,strlen(sortie_donnee)*sizeof(char));
		sortie_donnee[strlen(sortie_donnee)*sizeof(char)-1]='\0';
		fclose(fp);   
		//  nblines+=1;nbcols+=1;
		//printf("%d lignes, %d colonnes\n",nblines,nbcols); // affiche le nombre de lignes et colonnes aprés lecture 
	} else {
		printf("\n\nerreur : le fichier '%s'n'existe pas ou n'as pas pu être ouvert\n\n", filename);
	}
	return sortie_donnee;
}

// end page