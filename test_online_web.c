// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int main() {
    // Write C code here
    char a = 'm';
    char * n = (char*) malloc(10 * sizeof(char));

    strncat(n, &a, 1);
    printf("%s", n);


    return 0;
}
/**
 * fichier de test sur compiler en ligne
 * 
 * ne pas oublier de placer les print pour savoir ou ça plante (important)
 * essayer d'isoler le code qui fonctionne pas pour comprendre
 *  (avec moins de fioriture et le code minimal)
*/