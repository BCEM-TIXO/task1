#include <stdio.h>
#include "matrix.h"

int main() {
  int n;
  matrix_t A, B, C;
  scanf("%d", &n);
  if (n < 1) {
    printf("n/a");
    return 1;
  }
  create_matrix(n, n, &A);
  create_matrix(n, n, &B);
  if (IsCorr(&A) != kOk || IsCorr(&B) != kOk) {
    printf("n/a");
    return 1;
  }
  read_matrix(&A);
  read_matrix(&B);
  mult_matrix(&A, &B, &C);
  print_matrix(&C);
  return 0;
}