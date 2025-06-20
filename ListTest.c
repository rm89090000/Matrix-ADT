/***
* Riddhi Mundhra 
* rmundhra
* 2025 Winter CSE101 PA4
* ListTest.c
* Test File for List ADT
***/ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include "List.h"

int main(void){
    List L = newList();
    int y = 3;
    prepend(L, &y);
    y = 2;
    prepend(L, &y);
    y = 1;
    prepend(L, &y);
    int r = 3;
    append(L, &r);
    r = 8;
    append(L, &r);
    r = 4;
    append(L, &r);

    deleteBack(L);

    moveFront(L);

    int l = 6;
    insertAfter(L, &l);
    int i = 8;

    insertBefore(L, &i);

    moveNext(L);
    int t = 8;
    insertAfter(L, &t);
    delete(L);
    deleteFront(L);

    moveBack(L);

    int p =4;
    insertBefore(L,&p);
    deleteFront(L);

    movePrev(L);
    int v = 1;
    insertAfter(L, &v);


    moveFront(L);
    while(index(L)>=0){
         fprintf(stdout, "%d ", *(int*)get(L));
         moveNext(L);
    }
   freeList(&L);


}

