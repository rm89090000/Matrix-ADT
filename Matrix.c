/***
* Riddhi Mundhra 
* rmundhra
* 2025 Winter CSE101 PA4 
* Matrix.c
* Functions for the Matrix ADT
***/ 


#include "Matrix.h"


Matrix newMatrix(int n){
    Matrix matrix = calloc(1, sizeof(MatrixObj));
    assert(matrix!=NULL);
    matrix->size = n;
    matrix->non_zero = 0;
    matrix->entries = calloc(n+1, sizeof(List));
    assert(matrix->entries!=NULL);
    for(int i=1; i<=n; i++){
        matrix->entries[i] = newList();
    }
    return matrix;
}

Entry createEntry(int j, double val){
    Entry entry = calloc(1, sizeof(EntryObj));
    assert(entry!=NULL);
    entry->column = j;
    entry->value = val;
    return entry;
}

//freeMatrix()
void freeMatrix(Matrix *pM){
    if((*pM)==NULL){
        fprintf(stderr, "Can't call on a NULL matrix");
                exit(EXIT_FAILURE);

    }
    for(int i=1; i<=(*pM)->size; i++){
        List a = (*pM)->entries[i];
        moveFront(a);
        while(index(a)>=0){
            Entry h = get(a);
            free(h);
            moveNext(a);
        }

        freeList(&a);
    }
    free((*pM)->entries);
    free((*pM));
    (*pM) = NULL;
}

//size()
int size(Matrix M){
            if((M)==NULL){
        fprintf(stderr, "Can't call on a NULL matrix");
        exit(EXIT_FAILURE);
    }

    return M->size;
}

int NNZ(Matrix M){
    return M->non_zero;
}

void makeZero(Matrix M){
        if((M)==NULL){
        fprintf(stderr, "Can't call on a NULL matrix");
        exit(EXIT_FAILURE);
    }

    for(int i=1; i<=M->size; i++){

        List a = M->entries[i];
        moveFront(a);
        while(index(a)>=0){
            Entry b = get(a);
            free(b);
            moveNext(a);
        }
        
            clear(M->entries[i]);
    }
    M->non_zero = 0;
}

int equals(Matrix A, Matrix B){

                if((A)==NULL || B==NULL){
        fprintf(stderr, "Can't call on a NULL matrix");
        exit(EXIT_FAILURE);
    }
    if(A->size !=B->size){
        return 0;
    }
    for(int i=1; i<=A->size; i++){
        List entriesA = A->entries[i];
        List entriesB = B->entries[i];

        if(length(entriesA)!=length(entriesB)){
            return 0;
        }
        moveFront(entriesA); 
        moveFront(entriesB);

        while(index(entriesA)>=0 && index(entriesB)>=0){
            Entry a = get(entriesA);
            Entry b = get(entriesB);

            if(a->column!=b->column){
                return 0;
            }

            if(a->value!=b->value){
                return 0;
            }
            moveNext(entriesA);
            moveNext(entriesB);
        }
    }
    return 1;
}


void changeEntry(Matrix M, int i, int j, double x){

                if((M)==NULL){
        fprintf(stderr, "Can't call on a NULL matrix");
        exit(EXIT_FAILURE);
    }
    if(M->entries[i]==NULL){
        return;
    }
    List entry = M->entries[i];

    if(x!=0){        
        moveFront(entry);
        while(index(entry)>=0){
            Entry a = get(entry);

            if(a->column>j){
                insertBefore(entry,createEntry(j, x));
                M->non_zero++;
                return;
            }        
        else if(a->column==j){
            a->value =x;
            return;
     }

        moveNext(entry);

        
     }
     if(index(entry)==-1){
        
        append(entry, createEntry(j, x));
        M->non_zero++;

     }
        
    }
else{
    List entry1 = M->entries[i];
    moveFront(entry1);
    while(index(entry1)>=0){
        Entry c = get(entry1);
        if(c->column==j){
        delete(entry1);
        free(c);
        M->non_zero--;
        return;
        }
        moveNext(entry1);
    }
}
}

Matrix copy(Matrix A){

                if((A)==NULL){
        fprintf(stderr, "Can't call on a NULL matrix");
        exit(EXIT_FAILURE);
    }
    Matrix M = newMatrix(A->size);
    for(int i=1; i<=A->size; i++){
        List entryA = A->entries[i];
        moveFront(entryA);
        while(index(entryA)>=0){
                Entry a = get(entryA);
             changeEntry(M,i, a->column, a->value);
            moveNext(entryA);
        }
            M->non_zero = A->non_zero;

    }
    return M;
}

Matrix transpose(Matrix A){

                if((A)==NULL){
        fprintf(stderr, "Can't call on a NULL matrix");
        exit(EXIT_FAILURE);
    }
    Matrix M = newMatrix(A->size);
    for(int i=1; i<=A->size; i++){
        List entryA = A->entries[i];
        moveFront(entryA);
        while(index(entryA)>=0){
            Entry a = get(entryA);
            changeEntry(M,a->column, i, a->value);
            moveNext(entryA);
        }
        M->non_zero = A->non_zero;
    }
    return M;
}

Matrix scalarMult(double x, Matrix A){

                if((A)==NULL){
        fprintf(stderr, "Can't call on a NULL matrix");
        exit(EXIT_FAILURE);
    }

    if(x==0){
        return A;
    }
    Matrix M = newMatrix(size(A));

    for(int i=1; i<=A->size; i++){
        List entryA = A->entries[i];
        moveFront(entryA);
        while(index(entryA)>=0){
            Entry a = get(entryA);
            append(M->entries[i],createEntry(a->column, x*a->value));
            M->non_zero++;
            moveNext(entryA);

        }
 
    }    
    return M;
}

Matrix sum(Matrix A, Matrix B){

                if((A)==NULL || B==NULL){
        fprintf(stderr, "Can't call on a NULL matrix");
        exit(EXIT_FAILURE);
    }


    if(A->size!=B->size){
        fprintf(stderr, "Not the same size");
        exit(EXIT_FAILURE);
    }

    if(equals(A, B)==1){
        Matrix G = scalarMult(2, A);
        return G;
    }

    Matrix M = newMatrix(A->size);

    for(int i=1; i<=A->size; i++){
        List entryA = A->entries[i];
        List entryB = B->entries[i];
        moveFront(entryA);
        moveFront(entryB);
        while(index(entryA)>=0 && index(entryB)>=0){
            Entry a = get(entryA);
            Entry b = get(entryB);
            if(a->column == b->column){        
            if( a->value+b->value!=0){
                changeEntry(M, i, a->column,a->value+b->value);
                M->non_zero++;

            }
            moveNext(entryA);
            moveNext(entryB);

            }
            else if(a->column<b->column){
                if(a->value!=0){
                    changeEntry(M, i, a->column, a->value);

                }
                moveNext(entryA);
            }
            else if(b->column<a->column){
                if(b->value!=0){
                      changeEntry(M, i, b->column, b->value);
                }
                moveNext(entryB);

            }
        }

        while(index(entryA)>=0){
            Entry a = get(entryA);
            if(a->value!=0){
            changeEntry(M, i, a->column, a->value);

            }
            moveNext(entryA);

        }

        while(index(entryB)>=0){
        Entry b = get(entryB);
        if(b->value!=0){
            changeEntry(M, i, b->column, b->value);

        }
                moveNext(entryB);

        }

    }

        return M;

}


Matrix diff(Matrix A, Matrix B){

                    if((A)==NULL || B==NULL){
        fprintf(stderr, "Can't call on a NULL matrix");
        exit(EXIT_FAILURE);
    }

    if(A->size!=B->size){
        fprintf(stderr, "Not the same size");
        exit(EXIT_FAILURE);
    }
  
    Matrix M = newMatrix(A->size);

    for(int i=1; i<=A->size; i++){
        List entryA = A->entries[i];
        List entryB = B->entries[i];
        moveFront(entryA);
        moveFront(entryB);
        while(index(entryA)>=0 && index(entryB)>=0){
            Entry a = get(entryA);
            Entry b = get(entryB);
            if(a->column == b->column){
               
            if( a->value-b->value!=0){
                changeEntry(M, i, a->column,a->value-b->value);
                M->non_zero++;

            }
            moveNext(entryA);
            moveNext(entryB);

            }
            else if(a->column<b->column){
                if(a->value!=0){
                    changeEntry(M, i, a->column, a->value);

                }
                moveNext(entryA);
            }
            else if(b->column<a->column){
                if(b->value!=0){
                      changeEntry(M, i, b->column, -b->value);
                }
                moveNext(entryB);

            }
        }

        while(index(entryA)>=0){
            Entry a = get(entryA);
            if(a->value!=0){
            changeEntry(M, i, a->column, a->value);

            }
            moveNext(entryA);

        }

        while(index(entryB)>=0){
        Entry b = get(entryB);
        if(b->value!=0){
            changeEntry(M, i, b->column, -b->value);

        }
                moveNext(entryB);
        }


    }
        return M;

}

    

    double vectorDot(List P, List Q){
                    if((P)==NULL || Q==NULL){
        fprintf(stderr, "Can't call on a NULL List");
        exit(EXIT_FAILURE);
    }   
        double sum = 0;
        moveFront(P);
        moveFront(Q);
        while(index(P)>=0 && index(Q)>=0){
            Entry a = get(P);
            Entry b = get(Q);
            if(a->column==b->column){
                 sum = sum+(a->value*b->value);
                 moveNext(P);
                 moveNext(Q);
            }

            if(a->column<b->column){
                moveNext(P);
            }

            if(b->column<a->column){
                moveNext(Q);
            }
            
        }
        return sum;
    }


    Matrix product(Matrix A, Matrix B){

    if((A)==NULL || B==NULL){
        fprintf(stderr, "Can't call on a NULL matrix");
        exit(EXIT_FAILURE);
    }

            Matrix M = newMatrix(A->size);
            Matrix C = transpose(B);
            for(int i=1; i<=A->size; i++){
                List A1 = A->entries[i];
                if(length(A1)==0){
                    continue;
                }
                for(int j =1; j<=C->size; j++){
                List C1 = C->entries[j];
                double count = vectorDot(A1, C1);

                if(length(C1)==0){
                    continue;
                }
                if(count!=0){
                    append(M->entries[i], createEntry(j,count));
                    M->non_zero++;

                }
            }
            
        }
        freeMatrix(&C);
        return M;

    }

    void printMatrix(FILE*out, Matrix M){

                            if((M)==NULL){
        fprintf(stderr, "Can't call on a NULL matrix");
        exit(EXIT_FAILURE);
    }
        for(int i=1; i<=M->size; i++){
            List entry = M->entries[i];
            if(length(entry)>0){
            fprintf(out, "%d: ", i);
            moveFront(entry);
            while(index(entry)>=0){
                Entry e = get(entry);
                fprintf(out, "(%d, %.1f) ", e->column, e->value);
                moveNext(entry);
            }
            fprintf(out, "\n");
        }
}
    }

    
