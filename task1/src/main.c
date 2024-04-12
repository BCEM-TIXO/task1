#include <stdio.h>
#include "matrix.h"

int main() {
  int n;
  matrix_t A, B, C;
  if (scanf("%d", &n) != 1 && n < 1) {
    printf("n/a");
    return 1;
  }
  create_matrix(n, n, &A);
  create_matrix(n, n, &B);
  if (IsCorr(&A) != kOk || IsCorr(&B) != kOk) {
    printf("n/a");
    return 1;
  }
  if (read_matrix(&A) != kOk) {
    printf("n/a");
    return 1;
  }
  if (read_matrix(&B) != kOk) {
    printf("n/a");
    return 1;
  }
  mult_matrix(&A, &B, &C);
  print_matrix(&C);
  return 0;
}