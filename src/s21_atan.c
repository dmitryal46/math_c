#include "s21_math.h"

long double s21_atan(double x) {
  if (s21_is_nan(x)) return S21_NAN;
  if (x == S21_INF) return S21_PI / 2.0;
  if (x == S21_NINF) return -S21_PI / 2.0;
  long double res = 0.0;
  int sign = 1;
  long double summand;
  if (-1.0 < x && x < 1.0) {
    summand = x;  // for i = 0
    res = summand;
    for (int i = 1; i < 5000; i++) {
      sign *= -1;
      summand *= x * x;
      res += sign * summand / (1.0 + 2.0 * i);
    }
  } else if (x < -1.0 || x > 1.0) {
    summand = 1.0 / x;  // for i = 0
    res = summand;
    for (int i = 1; i < 10000; i++) {
      sign *= -1;
      summand /= (x * x);
      res += sign * summand / (1.0 + 2.0 * i);
    }
    res = S21_PI * s21_fabs(x) / (2.0 * x) - res;
  } else if (x == 1.0) {
    res = S21_PI / 4.0;
  } else  // x == -1.0
    res = -S21_PI / 4.0;
  return res;
}