#include "matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = kOk;
  if (result == NULL || rows <= 0 || columns <= 0) {
    return kMatrIncorrect;
  }

  result->matrix = (int **)calloc(rows, sizeof(int *));
  if (result->matrix == NULL) {
    status = kMatrIncorrect;
  }

  for (int i = 0; result->matrix && i < rows; i++) {
    result->matrix[i] = (int *)calloc(columns, sizeof(int *));
    if (result->matrix[i] == NULL) {
      s21_remove_matrix(result);
      status = kMatrIncorrect;
      break;
    }
  }

  if (status == kOk) {
    result->rows = rows;
    result->columns = columns;
  }

  return status;
}

void s21_remove_matrix(matrix_t *A) {
  if (IsCorr(A) == kOk) {
    for (int i = 0; i < A->rows && A->matrix != NULL; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->columns = 0;
    A->rows = 0;
    A->matrix = NULL;
  }
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = IsMul(A, B);
  if (status == kOk && s21_create_matrix(A->rows, B->columns, result) != kOk) {
    status = kMatrIncorrect;
  }
  for (int i = 0; status == kOk && i < A->rows; i++)
    for (int j = 0; j < B->columns; j++)
      for (int k = 0; k < B->rows; k++)
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
  return status;
}

int read_matrix(matrix_t *A) {
  if (A == NULL) {
    return kMatrIncorrect;
  }
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      scanf("%d", (A->matrix[i] + j));
    }
  }
  return kOk;
}

int print_matrix(matrix_t *A) {
  if (A == NULL) {
    return kMatrIncorrect;
  }
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns-1; ++j) {
      printf("%d ", A->matrix[i][j]);
    }
      printf("%d\n", A->matrix[i][A->columns-1]);
  }
  return kOk;
}

