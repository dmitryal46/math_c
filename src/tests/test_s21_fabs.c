#include "./suits.h"

START_TEST(s21_fabs_test) {
  long double x = 0.0;
  long double actual;
  long double expected;
  actual = s21_fabs(x);
  expected = fabsl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_fabs_test_1) {
  long double x = -1.000005;
  long double actual;
  long double expected;
  actual = s21_fabs(x);
  expected = fabsl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_fabs_test_2) {
  double x = -2323232232.323232;
  long double actual;
  long double expected;
  actual = s21_fabs(x);
  expected = fabsl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_fabs_test_3) {
  double x = S21_NAN;
  long double expected;
  expected = fabsl(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_fabs_test_4) {
  double x = S21_INF;
  long double expected;
  expected = s21_fabs(x);
  ck_assert_ldouble_infinite(expected);
}
END_TEST

START_TEST(s21_fabs_test_5) { ck_assert_ldouble_nan(s21_fabs(S21_NAN)); }
END_TEST

START_TEST(s21_fabs_test_6) {
  long double x = -0.0;
  long double actual;
  long double expected;
  actual = s21_fabs(x);
  expected = fabsl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_fabs_test_7) {
  double x = S21_INF;
  long double expected;
  expected = s21_fabs(x);
  ck_assert_ldouble_infinite(expected);
}
END_TEST

START_TEST(s21_fabs_test_8) {
  double x = S21_NINF;
  long double expected;
  expected = s21_fabs(x);
  ck_assert_ldouble_infinite(expected);
}
END_TEST

START_TEST(s21_fabs_test_9) {
  double x = -9999999999.999999;
  long double actual;
  long double expected;
  actual = s21_fabs(x);
  expected = fabsl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_fabs_test_10) {
  double x = 9999999999.999999;
  long double actual;
  long double expected;
  actual = s21_fabs(x);
  expected = fabsl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_fabs_test_11) {
  double x = -9999999999999999.0;
  long double actual;
  long double expected;
  actual = s21_fabs(x);
  expected = fabsl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_fabs_test_12) {
  double x = S21_NEGZERO;
  long double actual;
  long double expected;
  actual = s21_fabs(x);
  expected = fabsl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

Suite *s21_fabs_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_fabs_suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_fabs_test);
  tcase_add_test(tc_core, s21_fabs_test_1);
  tcase_add_test(tc_core, s21_fabs_test_2);
  tcase_add_test(tc_core, s21_fabs_test_3);
  tcase_add_test(tc_core, s21_fabs_test_4);
  tcase_add_test(tc_core, s21_fabs_test_5);
  tcase_add_test(tc_core, s21_fabs_test_6);
  tcase_add_test(tc_core, s21_fabs_test_7);
  tcase_add_test(tc_core, s21_fabs_test_8);
  tcase_add_test(tc_core, s21_fabs_test_9);
  tcase_add_test(tc_core, s21_fabs_test_10);
  tcase_add_test(tc_core, s21_fabs_test_11);
  tcase_add_test(tc_core, s21_fabs_test_12);
  suite_add_tcase(s, tc_core);
  return s;
}

int run_s21_fabs() {
  int number_filed = 0;
  Suite *s21_fabs = s21_fabs_suite();
  SRunner *sr;
  sr = srunner_create(s21_fabs);
  srunner_run_all(sr, CK_NORMAL);
  number_filed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_filed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
