/***
* Riddhi Mundhra 
* rmundhra
* 2025 Winter CSE101 PA4
* List.h
* Header File for List ADT
***/ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#pragma once

typedef struct ListObj* List;


typedef struct NodeObj{
 void* data;
 struct NodeObj* next;
 struct NodeObj*prev;
} NodeObj;

typedef NodeObj* Node;

List newList(void); 
void freeList(List* pL); 
int length(List L); 
int index(List L); 

void* front(List L); 
void* back(List L); 
void* get(List L);
void clear(List L); 
void set(List L, void* x); 
void moveFront(List L); 
void moveBack(List L);
void movePrev(List L); 
void moveNext(List L); 
void prepend(List L, void* x); 
void append(List L, void* x); 
void insertBefore(List L, void* x); 
void insertAfter(List L, void* x);
void deleteFront(List L); 
void deleteBack(List L); 
void delete(List L); 
List concatList(List A, List B);
