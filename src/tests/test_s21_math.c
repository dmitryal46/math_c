#include "suits.h"

int main() {
  int number_filed = 0;
  number_filed = run_s21_atan() + run_s21_asin() + run_s21_acos() +
                 run_s21_fabs() + run_s21_abs() + run_s21_sqrt() +
                 run_s21_exp() + run_s21_log() + run_s21_fmod() +
                 run_s21_pow() + run_s21_ceil() + run_s21_floor() +
                 run_s21_sin() + run_s21_cos() + run_s21_tan();
  return (number_filed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}