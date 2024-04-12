#include "massCalc.h"

double ballMassCalc(double r, double ro) {
  return (M_PI * 4 * r*r*r) * (ro / 3);
}