#include "s21_math.h"
/*
long double s21_sqrt(double x) {
    //if (x < 0) return S21_NAN;
    //long double left = 0;
    long double res = S21_NAN;
    if (x > 0) {
        res = pow(x, 0.5);  // s21_pow(x, 0.5)
    }
    else if (x == 0) {
        res = 0;
    }

    return res;
}
*/
long double s21_sqrt(double x) {
  if (x < 0) return S21_NAN;
  if (x != x) return S21_NAN;
  long double left = 0;
  long double right = 1.0;
  if (x > 1.0) right = x;
  long double mid = (left + right) / 2.0;
  while ((mid - left) > S21_EPS) {
    if (mid * mid > x) {
      right = mid;
    } else {
      left = mid;
    }
    mid = (left + right) / 2.0;
  }

  return mid;
}