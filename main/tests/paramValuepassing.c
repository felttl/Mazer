#include <stdio.h>
 
void add(int* i){
    *i+=1;
}
 
int main(void){
    int a = 0;
 
    add(&a);
    add(&a); 
    add(&a); 
    printf("%d", a);
    return 0;
}