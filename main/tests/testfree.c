#include "../add_lib.h"

void releaze(char ** matr, int x){
    printf("in releaze\n");
    while (x-- != 0){
        printf("%p\n", matr[x]);
        free(matr[x]);
    } 
}

int main(){

    char * get_datas = (char*)malloc(48 * sizeof(char));
    // convertit la chaine de char en matrice de char
    char ** get_data;
    // allocation d'espace
    get_data = (char**)malloc(8 * sizeof(char*));
    for (int i=0;i<8;i++)get_data[i]=(char*)malloc(5 * sizeof(char));

    // (5 * 8) = 40

    strcpy(get_datas, "11311\n10101\n10101\n11101\n10001\n10101\n10101\n11121");
    int x=0,y=0;
    printf("-start-\n");
    for (int i=0;i<47;i++){
        printf("%c", get_datas[i]);
        if (get_datas[i] == '\n'){// changement de ligne   
            // fin de string
            get_data[x][y]='\0';      
            x++;
            y=0;
        } else {
            // récupération du caractère et mise dans la matrice
            get_data[x][y] = get_datas[i]; // concat un char dans un string
            y++;            
        }
    }
    printf("\n-end-\n");    
    *(*(get_data+x)+y) = '\0';

    // affichage simple 
    for (int i=0;i<8;i++){    
        for (int j=0;j<5;j++){
            printf("%c", *(*(get_data+i)+j));
        }
        printf("\n");
    }

    // test de "double free" erreur générée
    releaze(get_data, 8);
    free(get_datas);
    free(get_data);


    return 0;
}