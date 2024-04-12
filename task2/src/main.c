#include <stdio.h>
#include <math.h>
#include "massCalc.h"

int main() {
  double r, ro;
  ro = 21500;
  if (scanf("%lf", &r) != 1) {
    printf("n/a");
    return 1;
  }
  double mass = round(ballMassCalc(r, ro));
  if (isinf(mass) || isnan(mass) || mass < 0) {
    printf("n/a");
    return 1;
  }
  printf("%.0lf", mass);
  return 0;
}