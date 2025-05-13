#include "s21_math.h"

// возвращает ближайшее целое число, не меньшее заданного значения
long double s21_ceil(double x) {
  long double ceil_x = (long long int)x;
  if (s21_fabs(x) > 0. && x != ceil_x) {
    if (x > 0.) ceil_x += 1;
  }
  return ceil_x;
}
