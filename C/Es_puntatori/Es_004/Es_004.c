#include <stdio.h>
#include <stdlib.h>

int main(){

    char* str="Ciaooooooooooooo"; 
    char* ciao= str;

    while(*str != '\0'){
        str ++;
    }

    ciao=(str-ciao)/sizeof(char);

    printf("Lunghezza: %d",ciao);
}