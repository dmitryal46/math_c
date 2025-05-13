#ifndef S21_MATH_H
#define S21_MATH_H

#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S21_PI 3.1415926535897932

#define S21_E 2.7182818284590452354
#define S21_LN2 0.69314718055994530942

#define S21_INF __builtin_inf()
#define S21_NAN_2 0.0 / 0.0
#define S21_NAN __builtin_nanf("0x7fc00000")
#define S21_NAN_F __builtin_nanf("0x7fc00000")
#define s21_is_inf __builtin_isinf
#define s21_is_nan __builtin_isnan

#define S21_NINF -1.0 / 0.0

#define S21_EPS 1e-07
#define S21_M_PI 3.14159265358979323846
#define S21_MAX_LONG_DOUBLE 1.79769313486231571e+308

#define S21_NEGZERO -0.0

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif
