#include "s21_math.h"

// остаток операции деления с плавающей точкой
long double s21_fmod(double x, double y) {
  long long mod = x / y;
  long double result = 0;
  if (y == 0 || x == S21_INF || x == S21_NINF)
    result = S21_NAN;
  else if (y == S21_INF || y == S21_NINF)
    result = x;
  else
    result = x - (y * mod);
  return result;
}

/*
long double s21_fmod(double x, double y) {
  long long int mod = 0;
  mod = x / y;
  long double result = (long double)x - mod * (long double)y;
  return result;
}
*/
