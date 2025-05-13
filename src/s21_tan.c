#include "s21_math.h"

long double s21_tan(double x) {
  long double result_tan = 0.0;

  if (x == 0.0) {
    result_tan = 0;
  } else {
    result_tan = s21_sin(x) / s21_cos(x);
  }
  return result_tan;
}