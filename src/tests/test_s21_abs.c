#include "./suits.h"

START_TEST(s21_abs_test) {
  long double x = 1;
  long double actual;
  long double expected;
  actual = s21_abs(x);
  expected = fabsl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_abs_test_1) {
  long double x = -0xA13;
  long double actual;
  long double expected;
  actual = s21_abs(x);
  expected = fabsl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_abs_test_2) {
  double x = -2147483647;
  long double actual;
  long double expected;
  actual = s21_abs(x);
  expected = fabs(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_abs_test_3) {
  double x = S21_NAN;
  long double expected;
  expected = fabsl(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_abs_test_4) {
  double x = S21_INF;
  long double expected;
  expected = fabsl(x);
  ck_assert_ldouble_infinite(expected);
}
END_TEST

START_TEST(s21_abs_test_5) {
  double x = S21_NAN;
  long double expected;
  expected = fabsl(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

Suite *s21_abs_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_abs_suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_abs_test);
  tcase_add_test(tc_core, s21_abs_test_1);
  tcase_add_test(tc_core, s21_abs_test_2);
  tcase_add_test(tc_core, s21_abs_test_3);
  tcase_add_test(tc_core, s21_abs_test_4);
  tcase_add_test(tc_core, s21_abs_test_5);
  suite_add_tcase(s, tc_core);
  return s;
}

int run_s21_abs() {
  int number_filed = 0;
  Suite *s21_abs = s21_abs_suite();
  SRunner *sr;
  sr = srunner_create(s21_abs);
  srunner_run_all(sr, CK_NORMAL);
  number_filed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_filed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
