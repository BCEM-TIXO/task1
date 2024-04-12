#ifndef SRC_MATRIXHELPER_H_
#define SRC_MATRIXHELPER_H_

#include "matrix.h"

int IsCorr(matrix_t *A);


int IsSim(matrix_t *A, matrix_t *B);

int IsMul(matrix_t *A, matrix_t *B);

#endif  // SRC_MATRIXHELPER_H_
