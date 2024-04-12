#include "matrix.h"

int IsCorr(matrix_t *A) {
  if (A != NULL && A->matrix && A->rows > 0 && A->columns > 0)
    return kOk;
  else
    return kMatrIncorrect;
}

int IsSim(matrix_t *A, matrix_t *B) {
  int status = IsCorr(A) || IsCorr(B);
  if (status == kOk && !(A->rows == B->rows && A->columns == B->columns))
    status = kMatrCacl;
  return status;
}

int IsMul(matrix_t *A, matrix_t *B) {
  int status = IsCorr(A) || IsCorr(B);
  if (status == kOk && A->columns != B->rows) status = kMatrCacl;
  return status;
}
