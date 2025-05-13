#include "./suits.h"

START_TEST(s21_tan_test) {
  long double x = 0;
  long double actual;
  long double expected;
  actual = s21_tan(x);
  expected = tanl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_tan_test_1) {
  long double x = S21_NAN_F;
  long double expected;
  expected = tanl(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_tan_test_2) {
  double x = -1.0;
  long double actual;
  long double expected;
  actual = s21_tan(x);
  expected = tanl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_tan_test_3) {
  double x = S21_NAN;
  long double expected;
  expected = tan(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_tan_test_4) {
  double x = S21_INF;
  long double expected;
  expected = tan(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_tan_test_5) {
  double x = S21_NINF;
  long double expected;
  expected = tan(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_tan_test_6) {
  double x = 3 * S21_PI;
  long double actual;
  long double expected;
  actual = s21_tan(x);
  expected = tanl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

END_TEST
Suite *s21_tan_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_tan_suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_tan_test);
  tcase_add_test(tc_core, s21_tan_test_1);
  tcase_add_test(tc_core, s21_tan_test_2);
  tcase_add_test(tc_core, s21_tan_test_3);
  tcase_add_test(tc_core, s21_tan_test_4);
  tcase_add_test(tc_core, s21_tan_test_5);
  tcase_add_test(tc_core, s21_tan_test_6);
  suite_add_tcase(s, tc_core);
  return s;
}

int run_s21_tan() {
  int number_filed = 0;
  Suite *s21_tan = s21_tan_suite();
  SRunner *sr;
  sr = srunner_create(s21_tan);
  srunner_run_all(sr, CK_NORMAL);
  number_filed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_filed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}