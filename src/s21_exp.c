#include "s21_math.h"

long double s21_exp(double x) {
  if (s21_is_nan(x)) return S21_NAN;
  if (x == S21_NINF) return 0.0;
  if (x < -14) return 0.0;
  if (s21_is_inf(x)) return S21_INF;
  long double res = 1.0 + x;
  long double summand = x;
  for (int i = 2; i < 5000; i++) {
    summand *= (x / i);
    res += summand;
  }
  return res;
}