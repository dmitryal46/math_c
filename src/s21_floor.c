#include "s21_math.h"

// возвращает ближайшее целое число, не превышающее заданное значение |
long double s21_floor(double x) {
  long double floor_x = (long long int)x;
  if (s21_fabs(x - floor_x) > 0. && s21_fabs(x) > 0.) {
    if (x < 0.) floor_x -= 1;
  }
  return floor_x;
}
