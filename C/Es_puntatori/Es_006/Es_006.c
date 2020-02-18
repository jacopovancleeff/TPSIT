#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define DIM 50

typedef struct contact
{
    /* data */
    char name[DIM];
    int number;
    Contact* next;
}Contact;


int main(){
    
    // creo un contatto

     Contact giovanni;
    strcpy(giovanni.name,"giovanni");
    giovanni.number = 11;
    giovanni.next = NULL;

    // creo un secondo contatto

    Contact mamma;
    strcpy(mamma.name,"mamma");
    mamma.number = 12;
    mamma.next = &giovanni;

    // creo un terzo contatto 

    Contact io;
    strcpy(io.name,"io");
    io.number = 15;
    io.next = &giovanni;

    mamma.next = &io;

    Contact* support = &mamma; 

    do
    {
        printf("name: %s \t number \n ",support->name,support->number);
        support = support->next;
    } while (support->next != NULL);
    
    

    return 1;

}