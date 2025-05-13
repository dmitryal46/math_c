#include "s21_math.h"

// вычисляет абсолютное значение числа с плавающей точкой

long double s21_fabs(double x) {
  long double res = 0;
  if (s21_is_nan(x)) {
    res = S21_NAN;
  } else if (x == 0.0) {
    res = 0.0;
  } else if (s21_is_inf(x)) {
    res = S21_INF;
  } else {
    res = x > 0 ? (long double)x : (long double)(x *= -1);
  }
  return res;
}
