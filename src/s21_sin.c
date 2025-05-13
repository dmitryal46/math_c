#include "s21_math.h"

long double s21_sin(double x) {
  long double result_sin = x;

  if (x == S21_PI || x == 0.0) {
    result_sin = x;
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    result_sin = x;
  }

  long double formula = x;

  for (int series_step = 1; s21_fabs(formula) > S21_EPS; series_step += 1) {
    formula *= -x * x / (2 * series_step * (2 * series_step + 1));
    result_sin += formula;
  }
  return result_sin;
}
