#include "./suits.h"

START_TEST(s21_floor_test) {
  long double x = -0.37;
  long double actual;
  long double expected;
  actual = s21_floor(x);
  expected = floorl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_floor_test_1) {
  long double x = 0.65;
  long double actual;
  long double expected;
  actual = s21_floor(x);
  expected = floorl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST
/*
START_TEST(s21_floor_test_NAN) {
  double x = S21_NAN;
  ck_assert_double_nan(s21_floor(x));
}
END_TEST
*/
START_TEST(s21_floor_test_3) {
  double x = -0.7323234567890765;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), 6);
}
END_TEST
/*
START_TEST(s21_floor_test_INF) {
  ck_assert_ldouble_eq(floor(S21_INF), s21_floor(S21_INF));
}
END_TEST
*/
START_TEST(s21_floor_test_5) {
  double x = 4732323456789076.593849023842083402985;
  long double actual;
  long double expected;
  actual = s21_floor(x);
  expected = floorl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_floor_test_6) {
  double x = 4732.85;
  long double actual;
  long double expected;
  actual = s21_floor(x);
  expected = floorl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_floor_test_7) {
  double x = 473.2985;
  long double actual;
  long double expected;
  actual = s21_floor(x);
  expected = floorl(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_floor_test_8) {
  double a = 0.00000001;
  int i = _i;
  ck_assert_ldouble_eq_tol(floor(a * i), s21_floor(a * i), S21_EPS);
}
END_TEST

START_TEST(s21_floor_test_9) {
  double a = 0.000001;
  int i = _i;
  ck_assert_ldouble_eq_tol(floor(-a * i), s21_floor(-a * i), S21_EPS);
}
END_TEST

START_TEST(s21_floor_test_10) {
  double a = ULLONG_MAX;
  int i = _i;
  ck_assert_ldouble_eq_tol(floor(-a * i), s21_floor(-a * i), S21_EPS);
}
END_TEST
Suite *s21_floor_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_floor_suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_floor_test);
  tcase_add_test(tc_core, s21_floor_test_1);
  // tcase_add_test(tc_core, s21_floor_test_NAN);
  tcase_add_test(tc_core, s21_floor_test_3);
  // tcase_add_test(tc_core, s21_floor_test_INF);
  tcase_add_test(tc_core, s21_floor_test_5);
  tcase_add_test(tc_core, s21_floor_test_6);
  tcase_add_test(tc_core, s21_floor_test_7);
  tcase_add_test(tc_core, s21_floor_test_8);
  tcase_add_test(tc_core, s21_floor_test_9);
  tcase_add_test(tc_core, s21_floor_test_10);

  suite_add_tcase(s, tc_core);
  return s;
}

int run_s21_floor() {
  int number_filed = 0;
  Suite *s21_floor = s21_floor_suite();
  SRunner *sr;
  sr = srunner_create(s21_floor);
  srunner_run_all(sr, CK_NORMAL);
  number_filed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_filed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
