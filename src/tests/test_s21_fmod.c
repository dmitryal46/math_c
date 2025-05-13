#include "./suits.h"

START_TEST(s21_fmod_test) {
  long double x = 3.92, y = 2.0;
  long double actual;
  long double expected;
  actual = s21_fmod(x, y);
  expected = fmodl(x, y);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_fmod_test_1) {
  long double x = 0.0, y = 5.0;
  long double actual;
  long double expected;
  actual = s21_fmod(x, y);
  expected = fmodl(x, y);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_fmod_test_2) {
  double x = 0.0, y = S21_INF;
  long double actual;
  long double expected;
  actual = s21_fmod(x, y);
  expected = fmodl(x, y);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_fmod_test_3) {
  double x = S21_INF, y = 0;
  // long double expected;
  long double actual = s21_fmod(x, y);
  // expected = fmod(x, y);
  ck_assert_ldouble_nan(actual);
}
END_TEST

START_TEST(s21_fmod_test_4) {
  double x = 100, y = S21_NAN;
  long double expected;
  expected = fmod(x, y);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_fmod_test_5) {
  double x = S21_NINF, y = S21_INF;
  long double expected;
  expected = fmod(x, y);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_fmod_test_6) {
  double x = S21_INF, y = 0;
  long double expected;
  expected = fmod(x, y);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_fmod_test_7) {
  double x = S21_NINF, y = 0;
  long double expected;
  expected = fmod(x, y);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_fmod_test_8) {
  double x = S21_NINF, y = 0.0;
  long double expected;
  expected = fmod(x, y);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_fmod_test_9) {
  double x = S21_INF, y = 0.0;
  long double expected;
  expected = fmod(x, y);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(test_inf) {
  ck_assert_ldouble_nan(s21_fmod(S21_INF, S21_INF));
  ck_assert_ldouble_nan(fmod(INFINITY, INFINITY));
}
END_TEST

START_TEST(test_nan) {
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(fmod(NAN, NAN));
}
END_TEST

START_TEST(test_y_zero) {
  ck_assert_ldouble_nan(s21_fmod(2.45, 0));
  ck_assert_ldouble_nan(fmod(2.45, 0));
}
END_TEST

START_TEST(test_x_zero) {
  ck_assert_ldouble_nan(s21_fmod(0, 0));
  ck_assert_ldouble_nan(fmod(0, 0));
}
END_TEST

Suite *s21_fmod_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_fmod_suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_fmod_test);
  tcase_add_test(tc_core, s21_fmod_test_1);
  tcase_add_test(tc_core, s21_fmod_test_2);
  tcase_add_test(tc_core, s21_fmod_test_3);
  tcase_add_test(tc_core, s21_fmod_test_4);
  tcase_add_test(tc_core, s21_fmod_test_5);
  tcase_add_test(tc_core, s21_fmod_test_6);
  tcase_add_test(tc_core, s21_fmod_test_7);
  tcase_add_test(tc_core, s21_fmod_test_8);
  tcase_add_test(tc_core, s21_fmod_test_9);
  tcase_add_test(tc_core, test_inf);
  tcase_add_test(tc_core, test_nan);
  tcase_add_test(tc_core, test_y_zero);
  tcase_add_test(tc_core, test_x_zero);
  // tcase_add_test(tc_core, s21_fmod_test_6);
  suite_add_tcase(s, tc_core);
  return s;
}

int run_s21_fmod() {
  int number_filed = 0;
  Suite *s21_fmod = s21_fmod_suite();
  SRunner *sr;
  sr = srunner_create(s21_fmod);
  srunner_run_all(sr, CK_NORMAL);
  number_filed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_filed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
