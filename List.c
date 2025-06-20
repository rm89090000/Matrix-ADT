/***
* Riddhi Mundhra 
* rmundhra
* 2025 Winter CSE101 PA4 
* List.c
* Functions for List ADT
***/ 

#include "List.h"
#include <assert.h>


typedef struct ListObj{
 Node front;
 Node back;
Node cursor;
 int length;
 int cursor_index;
} ListObj;

List newList(void){
    List list = calloc(1, sizeof(ListObj));
    if(list==NULL){
        fprintf(stderr, "Not working");
        exit(EXIT_FAILURE);
    }
    list->front = list->back = NULL;
    list->length = 0;
    list->cursor = NULL;
    list->cursor_index = -1;
    return list;
}

Node newNode(void* data){
   Node N = malloc(sizeof(NodeObj));
   assert(N!=NULL );
   N->data = data;
   N->next = NULL;
   N->prev = NULL;
   return(N);
}

void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

void freeList(List*pl){
    if(*pl==NULL || pl==NULL){
         fprintf(stderr,"List Error: Calling freeList() on a NULL List reference.\n");
        exit(EXIT_FAILURE);
        
    }
    if(pl!=NULL && *pl!=NULL){
        if((*pl)->length>0){
            clear(*pl);
    }
    free(*pl);
    *pl= NULL;
}
}
// Access Functions
int length(List L){
    return L->length;
}

int index(List L){
    if(L->length>0){
        return L->cursor_index;
    }
    else{
        return -1;
    }
}

void* front(List L){
       if( L==NULL ){
      fprintf(stderr, "List Error: calling front() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if( L->length==0 ){
      fprintf(stderr, "List Error: calling front() on an empty List\n");
      exit(EXIT_FAILURE);
   }
   return(L->front->data);
}

void* back(List L){
           if( L==NULL ){
      fprintf(stderr, "List Error: calling back() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if( L->length==0 ){
      fprintf(stderr, "List Error: calling back() on an empty List\n");
      exit(EXIT_FAILURE);
   }
   return(L->back->data);
}

void* get(List L){
       if(L==NULL){
      fprintf(stderr, "List Error: calling get() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   return(L->cursor->data);
}





//Manipulation procedures

void clear(List L){
    if(L==NULL){
        fprintf(stderr,"List Error: Calling equals() on a NULL List reference.\n");
        exit(EXIT_FAILURE);
    }
    else{
    while(L->length>0){
        deleteFront(L);
        
    }
    L->front = NULL;
    L->back = NULL;
    L->length = 0;
    L->cursor = NULL;
    L->cursor_index = -1; 
      }
}

void set(List L, void* x){

        if(L==NULL){
        fprintf(stderr, "List Error: Calling set() on a NULL List reference.\n");
        exit(EXIT_FAILURE);
    }

    if(L->length>0 && L->cursor_index>=0){
        L->cursor->data = x;
    }
    else if(L->length<=0){
        fprintf(stderr, "List Error: Calling set() on a NULL List reference.\n");
        exit(EXIT_FAILURE);
    }

    else if(L->cursor_index<0){
           fprintf(stderr, "List Error: Calling set() on a CursorIndex List reference.\n");
            exit(EXIT_FAILURE);

    }
    }

void moveFront(List L){
    if(L==NULL){
        fprintf(stderr, "List Error: Calling moveFront() on a NULL List reference.\n");
        exit(EXIT_FAILURE);
    }
    if(L->length>0){
        L->cursor = L->front;
        L->cursor_index = 0;
    }

}

void moveBack(List L){

        if(L==NULL){
        fprintf(stderr, "List Error: Calling set() on a NULL List reference.\n");
        exit(EXIT_FAILURE);
    }
    if(L->length>0){
        L->cursor = L->back;
        L->cursor_index = L->length-1;
    }


}

void movePrev(List L){
    if(L->cursor!=NULL && L->cursor!=L->front){
        L->cursor = L->cursor->prev;
        L->cursor_index--;
    }
    else if(L->cursor!=NULL && L->cursor==L->front){
        L->cursor = NULL;
        L->cursor_index = -1;
    }
}

void moveNext(List L){
    if(L->cursor!=NULL && L->cursor!=L->back){
        L->cursor = L->cursor->next;
        L->cursor_index++;
    }
    else if(L->cursor!=NULL && L->cursor==L->back){
        L->cursor = NULL;
        L->cursor_index = -1;
    }
}

void prepend(List L, void*x){
    Node N = newNode(x);
    if(L==NULL){
        fprintf(stderr,"List Error: calling prepend() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    else if(L->length==0){
        L->front = L->back = N;
        L->cursor_index=0;
        L->length++;
    }
    else{
        L->front->prev = N;
        N->next = L->front;
        L->front = N;
        if(L->cursor_index>=0){
            L->cursor_index++;
        }
        L->length++;

    }
}

void append(List L, void*x){
    Node N = newNode(x);
    if(L==NULL){
        fprintf(stderr,"List Error: calling append() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    else if(L->length==0){
        L->front=L->back = N;
        L->cursor_index=0;
        L->length++;

    }
    else{
        L->back->next = N;
        N->prev = L->back;
        L->back = N;
        L->length++;
    }

}

void insertBefore(List L, void*x){
    Node N = newNode(x);
    if(L==NULL){
      fprintf(stderr,"List Error: calling insertBefore() on NULL List reference\n");
      exit(EXIT_FAILURE);

    }
    if(L->length==0){
    fprintf(stderr,"List Error: calling insertBefore() on EMPTY List reference\n");
      exit(EXIT_FAILURE);


    if(L->cursor_index<0){
    fprintf(stderr,"List Error: calling insertBefore() on Cursor List reference\n");
      exit(EXIT_FAILURE);

    }
    }
    else if(L->length>0 && L->cursor_index>=0){
        if(L->cursor->prev!=NULL){
        L->cursor->prev->next = N;
        N->prev = L->cursor->prev;
        L->cursor->prev = N;
        N->next = L->cursor;
        L->length++;
        L->cursor_index++;
        
    }
    else{
        L->front->prev = N;
        N->next = L->front;
        L->front = N;
        L->cursor_index++;
        L->length++;
    }
}
}



void insertAfter(List L, void*x){
    Node N = newNode(x);
    if(L==NULL){
      fprintf(stderr,"List Error: calling insertAfter() on NULL List reference\n");
      exit(EXIT_FAILURE);
    }

     if(L->cursor==NULL){
        fprintf(stderr,"List Error: calling insertAfter() on NULL Cursor reference\n");
        exit(EXIT_FAILURE);
    }

    if(L->length==0){
            fprintf(stderr,"List Error: calling insertAfter() on an EMPTY list reference\n");
            exit(EXIT_FAILURE);
    }
    
    else if(L->length>0 && L->cursor_index>=0){
        if(L->cursor->next!=NULL){
            N->prev = L->cursor;
            N->next = L->cursor->next;
            L->cursor->next->prev = N;
            L->cursor->next = N;
            L->length++;
            L->cursor_index++;
        }
        else{
            L->back->next = N;
            N->prev = L->back;
            L->back = N;
            L->length++;
        }

    }

}

void deleteFront(List L){

     if(L==NULL){
      fprintf(stderr,"List Error: calling deleteFront() on NULL List reference\n");
      exit(EXIT_FAILURE);
    }

    if(L->length==0){
        fprintf(stderr, "List Error: calling deleteFront() on an empty List\n");
      exit(EXIT_FAILURE);
    }
    if(L->length>0){
    Node first = L->front;
    if(L->length==1){
        L->front = NULL;
        L->back = NULL;
        L->cursor = NULL;
        L->cursor_index = -1;
        L->length--;

    }
    else if(L->length>1){
            L->front = L->front->next;
            L->front->prev = NULL;
            if(L->cursor_index>=0){
                L->cursor_index--;
            }
            L->length--;

    }
    freeNode(&first);   
    }
    
}


void deleteBack(List L){
    if(L==NULL){
        fprintf(stderr,"List Error: calling deleteBack() on NULL List reference\n");
        exit(EXIT_FAILURE);

    }

    else if(L->length ==0){
    fprintf(stderr, "List Error: calling deleteBack() on an empty Queue\n");
      exit(EXIT_FAILURE);
    }

    else{
        Node curr = L->back;
    if(L->length==1){
        L->front=NULL;
        L->back = NULL;
        L->cursor = NULL;
        L->cursor_index = -1;
        L->length=0;
    }
    else{
        L->back = L->back->prev;
        L->back->next = NULL;
        L->length--;
    }
         if(L->cursor==curr || L->cursor_index>=L->length){
                L->cursor = NULL;
                L->cursor_index =-1;
        }
        freeNode(&curr);    
}
}

void delete(List L){


     if(L==NULL){
      fprintf(stderr,"List Error: calling delete() on NULL List reference\n");
      exit(EXIT_FAILURE);
    }

    if(L->length==0){
        fprintf(stderr, "List Error: calling delete() on an empty List\n");
      exit(EXIT_FAILURE);
    }

    if(L->length>0 && L->cursor_index>=0){
          Node first = L->cursor;
        if(L->cursor == L->front){
            deleteFront(L);
        }
        else if(L->cursor == L->back){
            deleteBack(L);
        }
        else{   
                L->cursor->prev->next = L->cursor->next;
                L->cursor->next->prev = L->cursor->prev;
                L->length--;
                L->cursor_index--;
                freeNode(&first);
    }
}
}


List concatList(List A, List B){

    if(A==NULL || B==NULL){
      fprintf(stderr, "List Error: calling concatList() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }

    List create = newList();
    Node curr = A->front;
    Node second = B->front;
    while(curr){
        append(create, curr->data);
        curr = curr->next;
    }
    while(second){
        append(create, second->data);
        second = second->next;
    }
    return create;
}

