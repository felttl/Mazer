#include "../add_lib.h"
#include "../tools.h"
#include <math.h>

typedef struct Pion{
    int line;
    int column;
    int num_step;
    struct Pion * suivant;
} Pion ;



Pion * create_Pion(int x, int y, int num){
    Pion * res=(Pion*)malloc(sizeof(Pion));
    res->line = x;
    res->column = y;
    res->num_step = num;
    res->suivant = NULL;
    return res;
}

void free_pion_chain(Pion * head){
    Pion*temp=head;
    Pion*last=head;
    // et pas temp->null car il manque le dernier
    while(temp != NULL){ 
        last=temp;        
        temp=temp->suivant;
        free(last);
    }
}

Pion*add_path(Pion* head, char** matr) {
    Pion*cursor=head;
    // parcours des points
    while (cursor != NULL) {
        printf("addpath:(%d,%d)", cursor->line, cursor->column);
        matr[cursor->line][cursor->column] = '5';
        Pion* nextNode = cursor->suivant;
        free(cursor);
        cursor = nextNode;
    }
    return NULL; // Retourner NULL car tous les nœuds ont été libérés
}


int main(){
    char**chaine=malloc(5*sizeof(char*));
    for (int i=0;i<5;i++)chaine=(char*)malloc(5*sizeof(char));
    Pion*head;
    Pion*cur=create_Pion(2, 4)// attentions la matr requiert des entiers
        





    for (int i=0;i<5;i++)chaine=free(chaine[i]);
    free(chaine);
    return 0;
}


// end page