/***
* Riddhi Mundhra 
* rmundhra
* 2025 Winter CSE101 PA4 
* MatrixTest.c
* Tests for the Matrix ADT
***/ 


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "Matrix.h"

int main(void){
    Matrix M = newMatrix(100);
    changeEntry(M, 1, 1, 3);
    changeEntry(M, 1, 2, 2);
    changeEntry(M, 2, 3, 3);
    changeEntry(M, 2, 5, 6);
    changeEntry(M, 3, 4, 6);
    printMatrix(stdout, M);
    Matrix scalar_A = scalarMult(4, M);
    Matrix mult_AA = product(scalar_A, scalar_A);
    Matrix sum_AA = sum(mult_AA, scalar_A);
    Matrix diff_AA = diff(scalar_A, scalar_A);
    Matrix transpose_A = transpose(scalar_A);
    fprintf(stdout, "Multiplying the Matrix M by 4 is\n");
    printMatrix(stdout, scalar_A);
    fprintf(stdout, "\n");
    fprintf(stdout, "Adding Matrix mult_A and Matrix scalar_A\n");
    printMatrix(stdout, sum_AA);
    fprintf(stdout, "\n");
    fprintf(stdout, "Subtracting Matrix scalar_A and Matrix scalar_A\n");
    printMatrix(stdout, diff_AA );
    fprintf(stdout, "\n");

    fprintf(stdout, "Product of Matrix scalar_A and Matrix scalar_A is\n");
    printMatrix(stdout, mult_AA);
    fprintf(stdout, "\n");


  fprintf(stdout, "transpose of Matrix scalar_A\n");
    printMatrix(stdout, transpose_A);
    fprintf(stdout, "\n");

    freeMatrix(&M);
    freeMatrix(&scalar_A);
    freeMatrix(&sum_AA);
    freeMatrix(&diff_AA);
    freeMatrix(&mult_AA);
    freeMatrix(&transpose_A);

}
