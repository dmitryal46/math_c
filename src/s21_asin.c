#include "s21_math.h"

long double s21_asin(double x) {
  if (x < -1.0 || x > 1.0) return S21_NAN;
  if (s21_is_nan(x)) return S21_NAN;
  return s21_atan(x / s21_sqrt(1 - x * x));
}