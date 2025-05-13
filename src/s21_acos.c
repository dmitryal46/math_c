#include "s21_math.h"

long double s21_acos(double x) {
  if (x < -1.0 || x > 1.0) return S21_NAN;
  if (s21_is_nan(x)) return S21_NAN;
  long double res;
  if (x >= 0 && x < 1)
    res = s21_atan(s21_sqrt(1 - x * x) / x);
  else if (x > -1 && x < 0)
    res = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  else if (x == 1.0)
    res = 0.0;
  else  // x == -1.0
    res = S21_PI;
  return res;
}