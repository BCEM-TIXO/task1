#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct matrix_struct {
  int **matrix;
  int rows;
  int columns;
} matrix_t;

#include "matrixHelper.h"

enum matrix_status { kOk, kMatrIncorrect, kMatrCacl, kNotEq = 0, kEq };

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int read_matrix(matrix_t *A);
int print_matrix(matrix_t *A);

#endif
