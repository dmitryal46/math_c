#include "s21_math.h"

long double s21_log(double x) {
  if (x < 0.0) return S21_NAN;
  if (x == 0.0) return S21_NINF;
  if (x != x) return S21_NAN;
  if (s21_is_inf(x)) return S21_INF;
  // if (x == S21_NINF) return S21_NAN;

  double arg = x;
  int ex_pow = 0;
  for (; arg >= S21_E; arg /= S21_E, ex_pow++) continue;

  long double res = 0.0;
  long double prev_res = 0.0;
  for (int i = 0; i < 100; i++) {
    prev_res = res;
    res = prev_res + 2 * (arg - s21_exp(prev_res)) / (arg + s21_exp(prev_res));
  }

  return res + ex_pow;
}