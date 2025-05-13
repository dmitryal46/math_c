#include "s21_math.h"

long double s21_cos(double x) {
  long double result_cos = s21_sin(x + S21_PI / 2);
  return result_cos;
}