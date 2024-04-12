#include <stdio.h>
#include "matrix.h"

int main() {
  int n;
  matrix_t A, B, C;
  scanf("%d", &n);
  if (n < 1) {
    printf("Matrix demension must be > 0: %d", n);
    return 1;
  }
  s21_create_matrix(n, n, &A);
  s21_create_matrix(n, n, &B);
  read_matrix(&A);
  read_matrix(&B);
  s21_mult_matrix(&A, &B, &C);
  print_matrix(&C);
  return 0;
}