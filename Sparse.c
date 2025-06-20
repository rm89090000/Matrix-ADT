
/***
* Riddhi Mundhra 
* rmundhra
* 2025 Winter CSE101 PA4 
* Sparse.c
* Reads values from files and prints out matrices
***/ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"
#include <assert.h>
#include "Matrix.h"



int main(int argc, char * argv[]){
  FILE* in;
  FILE* out;
  if(argc!=3){
  fprintf(stderr,"Usage: %s <input file> <output file>\n", argv[0]);
  exit(1);
  }

  in = fopen(argv[1], "r");
  if( in==NULL ){
      exit(1);
  }
  out = fopen(argv[2], "w");
  if(out==NULL){
    printf("Unable to open file %s for writing\n", argv[2]);
    exit(1);
  }

  int n =1;
  int a =1; 
  int b =1;
  fscanf(in, "%d %d %d\n", &n, &a, &b);
  double row=0;
  double column = 1;
  double value = 1;
  Matrix A = newMatrix(n);
  Matrix B = newMatrix(n);

  for(int i=0; i<a; i++){

    fscanf(in, "%lf %lf %lf \n", &row, &column, &value);
    changeEntry(A,row, column, value);
  }

  for(int i=0; i<b; i++){

    fscanf(in, "%lf %lf %lf \n", &row, &column, &value);
    changeEntry(B,row, column, value);
  }
  fprintf(out, "A has %d non-zero entries:\n", a);
  printMatrix(out, A);
  fprintf(out, "\n");
  fprintf(out, "B has %d non-zero entries:\n", b);
  printMatrix(out, B);
  fprintf(out, "\n");
  Matrix scalar_A = scalarMult(1.5, A);
  fprintf(out, "(1.5)*A = \n");
  printMatrix(out, scalar_A);
  fprintf(out, "\n");
  Matrix sum_AB = sum(A, B);
  fprintf(out, "A+B = \n");
  printMatrix(out, sum_AB);
  fprintf(out, "\n");
  Matrix sum_AA = sum(A, A);
  fprintf(out, "A+A = \n");
  printMatrix(out, sum_AA);
  fprintf(out, "\n");
  fprintf(out, "B-A = \n");
  Matrix diff_BA = diff(B,  A);
  printMatrix(out, diff_BA);
  fprintf(out, "\n");
  Matrix diff_AA = diff(A, A);
  fprintf(out, "A-A = \n");
  fprintf(out, "\n");
  fprintf(out, "Transpose(A) = ");

  Matrix transpose_A = transpose(A);
  fprintf(out, "\n");
  printMatrix(out, transpose_A);
  fprintf(out, "\n");
  printMatrix(out, diff_AA);

  fprintf(out, "A*B = ");
  Matrix mult_AB= product(A, B);
  fprintf(out, "\n");
  printMatrix(out, mult_AB);
  fprintf(out, "\n");


  fprintf(out, "B*B = ");
  Matrix mult_BB = product(B, B);
  fprintf(out, "\n");
  printMatrix(out, mult_BB);
  fprintf(out, "\n");

freeMatrix(&scalar_A);
freeMatrix(&sum_AA);
freeMatrix(&sum_AB);
freeMatrix(&diff_BA);
freeMatrix(&diff_AA);
freeMatrix(&mult_AB);
freeMatrix(&mult_BB);
freeMatrix(&transpose_A);
freeMatrix(&A);
freeMatrix(&B);

  fclose(in);
  fclose(out);
}

