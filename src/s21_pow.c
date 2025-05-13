#include "s21_math.h"

/*
long double s21_pow(double base, double exp) {
    long double res;
    long double base2 = base;
    long long int ecp_int = (long long int) exp;

    if (base2 < 0) {
        base2 = -base2;
        res = s21_exp(exp * s21_log(base2));
        if (s21_fmod(exp, 2) != 0)
            res = -res;
    } else {
        res = s21_exp(exp * s21_log(base2));
    }

    return res;
}
*/

long double s21_pow(double base, double exp) {
  long double res;
  if (base < 0) {
    if ((long int)exp == exp) {
      if (exp > 0) {
        res = base;
        for (long int i = 0; i < (long int)exp - 1; i++) {
          res *= base;
        }
      } else if (exp == 0) {
        res = 1;
      } else {
        res = 1 / base;
        for (long int i = 0; i < (long int)exp * (-1) - 1; i++) {
          res /= base;
        }
      }
    } else {
      if (exp == S21_NINF || exp == S21_INF) {
        if (base * (-1) < 1) {
          res = 0;
        } else if (base * (-1) == 1) {
          res = 1;
        } else {
          if (exp == S21_NINF) {
            res = 0;
          } else {
            res = S21_INF;
          }
        }
      } else {
        res = S21_NAN;
      }
    }
  } else if (base == 0) {
    res = exp == 0 ? 1 : 0;
  } else if (base == 1) {
    res = 1;
  } else {
    if ((long int)exp == exp) {
      if (exp > 0) {
        res = base;
        for (long int i = 0; i < (long int)exp - 1; i++) {
          res *= base;
        }
      } else if (exp == 0) {
        res = 1;
      } else {
        res = 1 / base;
        for (long int i = 0; i < (long int)exp * (-1) - 1; i++) {
          res /= base;
        }
      }
    } else {
      res = s21_exp(exp * (double)s21_log(base));
    }
  }
  return res;
}