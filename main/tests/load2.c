#include "../add_lib.h"
#include "../display.h"
#include "../pion_chain.h"

int main(){ // gdb debugger

    // récupère la chaine de données
    char * get_datas = read_file_char_by_char("test.txt");
    // convertit la chaine de char en matrice de char
    char ** get_data;
    // allocation d'espace
    get_data = (char**)malloc(lines * sizeof(char*));
    for (int i=0;i<cols;i++)get_data[i]=(char*)malloc(cols * sizeof(char));

    printf("extracted data:\n\n%s\n\n", get_datas);


    // placement des données dans la matrice
    int x = 0, y = 0; // ligne colonne
    for (int i = 2; i < strlen(get_datas); i++) {
        // debugger
        printf("i: %d, x: %d, y: %d, char: %c\n", i, x, y, *(get_datas + i));

        if (*(get_datas + i) == ' ' || *(get_datas + i) == '\t') {
            // espace ou tabulation
            // fin de string
            *(*(get_data + x) + y) = '\0';
            y = 0; // réinitialiser la colonne
        } else if (*(get_datas + i) == '\n') {
            // changement de ligne ou fin de chaîne
            // fin de string
            *(*(get_data + x) + y) = '\0';
            x++; // passer à la ligne suivante
            y = 0; // réinitialiser la colonne
        } else {
            // caractère valide
            *(*(get_data + x) + y) = *(get_datas + i);
            y++;
        }
    }



    // fermeture de pointeur
    *(*(get_data+x)+y) = '\0';

    // series de tests

    printf("loop extracted data:\n\n");
    // affichage simple
    for (int i=0;i<strlen(get_datas);i++){
            printf("%c", *(get_datas+i));
    } 

    printf("\n\nour formatted data:\n\n");
    // affichage simple
    for (int i=0;i<lines;i++){
        for (int j=0;j<cols;j++){
            printf("%c", *(*(get_data+i)+j));
        }
        printf("\n");
    }  
    printf("\nnumeric display:\n\n");
    for (int i=0;i<lines;i++){
        for (int j=0;j<cols;j++){
            printf("%d ", *(*(get_data+i)+j));
        }
        printf("\n");        
    }    
    printf("\n\nlinear own display(char by char):\n\n");
    for (int i=0;i<lines;i++){
        for (int j=0;j<cols;j++){
            printf("%c", *(*(get_data+i)+j));
        }
        printf("\n");
    }    
    printf("\n\nlinear own display(str by str):\n\n");
    for (int i=0;i<lines;i++){
        printf("%s", get_data[i]);
        printf("\n");
    }   
    printf("\n");
    // display(get_data, lines, cols);

    printf("get datas : %p\n", get_datas);

    //releaze(get_data, lines);
    free(get_datas);    
    free(get_data);
    return 0;
}