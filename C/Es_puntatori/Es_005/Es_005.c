
#include <stdio.h>
#include <stdlib.h>

typedef struct _hola{
    int a;
}Hola;

int main(){

    int n=3;
    Hola *array= malloc(n*sizeof(Hola));
    

    array->a = 1;
    (array+1)->a=2;
    (array+2)->a=3;

    for(int k=0;k<n;k++){
        printf("\n %d ",(array+k)->a);

    }
    free(array);
}