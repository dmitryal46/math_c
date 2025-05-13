#include "./suits.h"

START_TEST(s21_acos_test) {
  long double x = 0.0;
  long double actual;
  long double expected;
  actual = s21_acos(x);
  expected = acos(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_acos_test_1) {
  long double x = 1.0;
  long double actual;
  long double expected;
  actual = s21_acos(x);
  expected = acosl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_acos_test_2) {
  long double x = -1.0;
  long double actual;
  long double expected;
  actual = s21_acos(x);
  expected = acosl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_acos_test_3) {
  long double x = 0.000002;
  long double actual;
  long double expected;
  actual = s21_acos(x);
  expected = acos(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_acos_test_4) {
  long double x = 0.875438;
  long double actual;
  long double expected;
  actual = s21_acos(x);
  expected = acos(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_acos_test_5) {
  long double x = -0.999999;
  long double actual;
  long double expected;
  actual = s21_acos(x);
  expected = acos(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_acos_test_6) {
  long double x = 2.0;
  long double expected;
  expected = s21_acos(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_acos_test_7) {
  long double x = -2.0;
  long double expected;
  expected = s21_acos(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_acos_test_8) {
  long double x = 9999999999.999999;
  long double expected;
  expected = s21_acos(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_acos_test_9) {
  long double x = -9999999999999999.0;
  long double expected;
  expected = s21_acos(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_acos_test_10) {
  long double x = S21_NAN;
  long double expected;
  expected = s21_acos(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_acos_test_11) {
  long double x = S21_INF;
  long double expected;
  expected = s21_acos(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_acos_test_12) {
  long double x = S21_NINF;
  long double expected;
  expected = s21_acos(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

Suite *s21_acos_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_acos_suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_acos_test);
  tcase_add_test(tc_core, s21_acos_test_1);
  tcase_add_test(tc_core, s21_acos_test_2);
  tcase_add_test(tc_core, s21_acos_test_3);
  tcase_add_test(tc_core, s21_acos_test_4);
  tcase_add_test(tc_core, s21_acos_test_5);
  tcase_add_test(tc_core, s21_acos_test_6);
  tcase_add_test(tc_core, s21_acos_test_7);
  tcase_add_test(tc_core, s21_acos_test_8);
  tcase_add_test(tc_core, s21_acos_test_9);
  tcase_add_test(tc_core, s21_acos_test_10);
  tcase_add_test(tc_core, s21_acos_test_11);
  tcase_add_test(tc_core, s21_acos_test_12);

  suite_add_tcase(s, tc_core);
  return s;
}

int run_s21_acos() {
  int number_filed = 0;
  Suite *s21_acos = s21_acos_suite();
  SRunner *sr;
  sr = srunner_create(s21_acos);
  srunner_run_all(sr, CK_NORMAL);
  number_filed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_filed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
