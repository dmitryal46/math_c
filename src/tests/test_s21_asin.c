#include "./suits.h"

START_TEST(s21_asin_test) {
  long double x = 0.0;
  long double actual;
  long double expected;
  actual = s21_asin(x);
  expected = asin(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_asin_test_1) {
  long double x = 1.0;
  long double actual;
  long double expected;
  actual = s21_asin(x);
  expected = asin(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_asin_test_2) {
  long double x = -1.0;
  long double actual;
  long double expected;
  actual = s21_asin(x);
  expected = asin(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_asin_test_3) {
  long double x = 0.000002;
  long double actual;
  long double expected;
  actual = s21_asin(x);
  expected = asin(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_asin_test_4) {
  long double x = 0.875438;
  long double actual;
  long double expected;
  actual = s21_asin(x);
  expected = asin(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_asin_test_5) {
  long double x = -0.999999;
  long double actual;
  long double expected;
  actual = s21_asin(x);
  expected = asin(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_asin_test_6) {
  long double x = 2.0;
  long double expected;
  expected = s21_asin(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_asin_test_7) {
  long double x = -2.0;
  long double expected;
  expected = s21_asin(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_asin_test_8) {
  long double x = 9999999999.999999;
  long double expected;
  expected = s21_asin(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_asin_test_9) {
  long double x = -9999999999999999.0;
  long double expected;
  expected = s21_asin(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_asin_test_10) {
  long double x = S21_NAN;
  long double expected;
  expected = s21_asin(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_asin_test_11) {
  long double x = S21_INF;
  long double expected;
  expected = s21_asin(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_asin_test_12) {
  long double x = S21_NINF;
  long double expected;
  expected = s21_asin(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

/*
START_TEST(s21_asin_test_16) {
  long double x = S21_NAN;
  long double expected;
  expected = s21_atan(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST
*/

Suite *s21_asin_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_asin_suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_asin_test);
  tcase_add_test(tc_core, s21_asin_test_1);
  tcase_add_test(tc_core, s21_asin_test_2);
  tcase_add_test(tc_core, s21_asin_test_3);
  tcase_add_test(tc_core, s21_asin_test_4);
  tcase_add_test(tc_core, s21_asin_test_5);
  tcase_add_test(tc_core, s21_asin_test_6);
  tcase_add_test(tc_core, s21_asin_test_7);
  tcase_add_test(tc_core, s21_asin_test_8);
  tcase_add_test(tc_core, s21_asin_test_9);
  tcase_add_test(tc_core, s21_asin_test_10);
  tcase_add_test(tc_core, s21_asin_test_11);
  tcase_add_test(tc_core, s21_asin_test_12);

  suite_add_tcase(s, tc_core);
  return s;
}

int run_s21_asin() {
  int number_filed = 0;
  Suite *s21_asin = s21_asin_suite();
  SRunner *sr;
  sr = srunner_create(s21_asin);
  srunner_run_all(sr, CK_NORMAL);
  number_filed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_filed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
