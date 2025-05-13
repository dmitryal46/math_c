#include "./suits.h"

START_TEST(s21_sin_test) {
  long double x = 0;
  long double actual;
  long double expected;
  actual = s21_sin(x);
  expected = sinl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_sin_test_1) {
  long double x = S21_PI;
  long double actual;
  long double expected;
  actual = s21_sin(x);
  expected = sinl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_sin_test_2) {
  double x = -1.0;
  long double actual;
  long double expected;
  actual = s21_sin(x);
  expected = sinl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_sin_test_3) {
  double x = S21_NAN;
  long double expected;
  expected = sin(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_sin_test_4) {
  double x = S21_INF;
  long double expected;
  expected = sin(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_sin_test_5) {
  double x = S21_NINF;
  long double expected;
  expected = sin(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_sin_test_6) {
  double x = 3 * S21_PI;
  long double actual;
  long double expected;
  actual = s21_sin(x);
  expected = sinl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_sin_test_7) {
  double x = -(S21_INF);
  long double expected;
  expected = sin(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

Suite *s21_sin_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_sin_suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_sin_test);
  tcase_add_test(tc_core, s21_sin_test_1);
  tcase_add_test(tc_core, s21_sin_test_2);
  tcase_add_test(tc_core, s21_sin_test_3);
  tcase_add_test(tc_core, s21_sin_test_4);
  tcase_add_test(tc_core, s21_sin_test_5);
  tcase_add_test(tc_core, s21_sin_test_6);
  tcase_add_test(tc_core, s21_sin_test_7);
  suite_add_tcase(s, tc_core);
  return s;
}

int run_s21_sin() {
  int number_filed = 0;
  Suite *s21_sin = s21_sin_suite();
  SRunner *sr;
  sr = srunner_create(s21_sin);
  srunner_run_all(sr, CK_NORMAL);
  number_filed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_filed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
