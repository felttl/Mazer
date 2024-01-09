#include "../add_lib.h"
#include "../display.h"
#include <math.h>
#include "../load.h"
typedef struct Pion{
    int line;
    int column;
    int num_step;
    char character;
    struct Pion * suivant;
} Pion ;
int get_number_borders(int line, int col){
    return 2*(line+col-4);
}
int short_vec_point(int currentx,int currenty,int sx,int sy){
    return (int)(abs(currentx-sx)+abs(currenty-sy));
}
int min(int*list, int size){
    int index=-1;
    if (size > 0){
        index=0;
        for (int i=1;i<size;i++){
            if (list[i] < list[0]){
                index=i;
            }
        }
    } else {
        printf("la taille ne peut pas être 0 !\n");
        exit(EXIT_FAILURE);
    }
    return index;
}
int minr(int*list, int size){
    int index=-1;
    if (size > 0){
        index=0;
        for (int i=size-1;i>0;i--){
            if (list[i] < list[0]){
                index=i;
            }
        }
    } else {
        printf("la taille ne peut pas être 0 !\n");
        exit(EXIT_FAILURE);
    }
    return index;
}
Pion * create_Pion(int x, int y, int num){
    Pion * res=(Pion*)malloc(sizeof(Pion));
    res->line = x;
    res->column = y;
    res->num_step = num;
    res->suivant = NULL;
    res->character = '\0';    
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
Pion * add_path(Pion*head, char**matr){
    Pion*cursor=NULL;
    cursor=(Pion*)malloc(sizeof(Pion));
    cursor=head;
    // parcours des points
    while(cursor != NULL){
        // attention il droit y avoir les coordonées correctes
        // sinon problème de mémoire (pas d'erreurs possible puisqe c'est)
        // uniquement certaines fonctions spécifiques qui peuvent faire 
        // l'oppération
        matr[cursor->line][cursor->column]='5';
        cursor=cursor->suivant;
    }
    return head;
}
Pion * display_chain(Pion * head){
    printf("\naffichage de pions : \n");
    Pion*cursor=NULL;
    cursor=(Pion*)malloc(sizeof(Pion));
    cursor=head;
    // parcours des points
    while(cursor != NULL){
        printf("(%d,%d)c=(%c)\n", cursor->line, cursor->column, cursor->character);
        cursor=cursor->suivant;
    }
    printf("\n");
    return head;
}
Pion*shortest_point_way(char**matrix,int ex,int ey,int sx, int sy, int lenx,int leny){
    int scanx=ex; // position du scanner central
    int scany=ey;
    Pion*head_pion;
    int step=1;

    int maxoccur=lenx*leny-get_number_borders(lenx, leny)+2;// sécurité
    int nsew[4]={0, 0, 0, 0};// nord sud est west
    int togo=0; // récupérer l'index de la direction pour choisir le déplacement
    // déplacement du pion
    if (ex == 0){
        scanx++;
    } else if (ex == lenx-1){
        scanx=lenx-2;
    } else {scanx=ex;}
    if (ey == 0){
        scany++;
    } else if (ey == leny-1){
        scanx=leny-2;
    } else {scany=ey;}
    Pion*etape=create_Pion(scanx, scany, 0);
    head_pion=etape;    
    do {
        // on va a la case la plus proche de la sortie qui n'est pas un mur
        nsew[0] = scanx-1>=0&&matrix[scanx-1][scany]!='1' ? short_vec_point(scanx-1, scany, sx, sy) : lenx+leny+1;
        nsew[1] = scanx+1<lenx-1&&matrix[scanx+1][scany]!='1' ? short_vec_point(scanx+1, scany, sx, sy) : lenx+leny+1;
        nsew[2] = scany-1>=0&&matrix[scanx][scany-1]!='1' ? short_vec_point(scanx, scany-1, sx, sy) : lenx+leny+1;
        nsew[3] = scany+1<leny-1&&matrix[scanx][scany+1]!='1' ? short_vec_point(scanx, scany+1, sx, sy) : lenx+leny+1;
        // permet d'afficher une croix en cas de problèmes de racactères ou d'overflow
        // if(maxoccur==0){
        //     printf("croix : \n %c\n%c", matrix[scanx-1][scany],matrix[scanx+1][scany]);
        //     printf("%c%c\n %c\n",matrix[scanx][scany-1], matrix[scanx][scany-1], matrix[scanx][scany+1]);
        // }
        // on regarde l'index du min pour se déplacer
        togo = step%2 ? min(nsew, 4) : minr(nsew, 4); // 1/2 etape au cas ou 2 cas ont la même valeur
        if (togo==0){
            scanx--; // on va au nord
        } else if (togo==1){
            scanx++; // on va au sud etc...
        } else if (togo==2){
            scany--;
        } else if (togo==3){
            scany++;
        } else {
            printf("erreur: min n'est pas trouvé case : (%d,%d)", scanx, scany);
            exit(EXIT_FAILURE);
        }    
        // en dehors de la matrice pb de caractère
        if ((scanx == 0||scanx==lenx-1||scany==0||scany==leny-1)&&step>2){
            printf("le point est en dehors du labyrinthe il ya  un problème de caractère\n");
            if (maxoccur<4) maxoccur--;
            maxoccur=3;            
        }
        etape->suivant=create_Pion(scanx, scany, step);
        etape->character=matrix[scanx][scany];
        etape=etape->suivant;
        step++;
        maxoccur--;      
    }while (scanx!=sx && scany!=sy && maxoccur!=0 && scanx>=0 && scanx<=lenx && scany>=0 && scany<=leny);
    if (maxoccur == 0){// erreur d'iterations (pb dans la matrice donné en paramètre)
        printf("\nnombre d'iterations dépassée\n");
        // affichange de la liste
        display_chain(head_pion);
    }
    printf("\n");
    return head_pion;
}
int main(){
    int x=0;
    int y=0;
    char filename[20]="test5ct.txt";
    char**matrix = get_char_array_fromfile(filename, &x, &y);

    printf("premier affichage :\n");
    display(matrix, x, y);
    int ex=0, ey=0;
    int sx=0, sy=0;
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            if (matrix[i][j] == '2'){
                ex=i;
                ey=j;
            } else if (matrix[i][j] == '3'){
                sx=i;
                sy=j;                
            }
        }
    }
    Pion*chemin=add_path(shortest_point_way(matrix, ex, ey, sx, sy, x, y), matrix);



    printf("premier affichage :\n");
    display(matrix, x, y);    




    // free memory
    free_pion_chain(chemin);  
    for (size_t i = 0; i < x; i++)
        free(matrix[i]);
    free(matrix);
    return 0;
}





// end page