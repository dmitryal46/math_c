#include "./suits.h"

START_TEST(s21_ceil_test) {
  long double x = 0.666;
  long double actual;
  long double expected;
  actual = s21_ceil(x);
  expected = ceil(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_ceil_test_1) {
  double x = 8743517471375471154.34143134134134;

  long double actual;
  long double expected;
  actual = s21_ceil(x);
  expected = ceil(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_ceil_test_2) {
  double x = -0.0313;
  long double actual;
  long double expected;
  actual = s21_ceil(x);
  expected = ceil(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_ceil_test_3) {
  double x = S21_NAN;
  long double expected;
  expected = ceil(x);
  ck_assert_ldouble_nan(expected);
}
END_TEST

// START_TEST(s21_ceil_test_4) {
//   double x = S21_INF;
//   long double expected;
//   expected = ceil(x);
//   ck_assert_ldouble_nan(expected);
// }
// END_TEST

START_TEST(s21_ceil_test_5) {
  double x = S21_INF;
  long double expected;
  expected = ceil(x);
  ck_assert_ldouble_infinite(expected);
}
END_TEST

START_TEST(s21_ceil_test_6) {
  long double x = 4.2;
  long double actual;
  long double expected;
  actual = s21_ceil(x);
  expected = ceil(x);
  ck_assert_ldouble_eq_tol(actual, expected, S21_EPS);
}
END_TEST

START_TEST(s21_ceil_test_7) {
  double num = 2.0293;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

START_TEST(s21_ceil_test_8) {
  double num = -2.0293;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

START_TEST(s21_ceil_test_9) {
  double num = 0.8293;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

// START_TEST(s21_ceil_test_10) {
//   double num = S21_INF;
//   ck_assert_double_eq(s21_ceil(num), ceil(num));
// }
// END_TEST

// START_TEST(s21_ceil_test_11) {
//   double num = S21_NINF;
//   ck_assert_double_eq(s21_ceil(num), ceil(num));
// }
// END_TEST

// START_TEST(s21_ceil_test_12) {
//   double num = S21_NAN;
//   ck_assert_double_nan(s21_ceil(num));
// }
// END_TEST

// START_TEST(s21_ceil_test_13) {
//   float num = S21_NAN;
//   ck_assert_double_nan(s21_ceil(num));
// }
// END_TEST

// START_TEST(s21_ceil_test_14) {
//   long double num = S21_NAN;
//   ck_assert_double_nan(s21_ceil(num));
// }
// END_TEST

START_TEST(s21_ceil_test_15) {
  double num = -0.8293;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

START_TEST(s21_ceil_test_16) {
  double num = -INT_MAX;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

START_TEST(s21_ceil_test_17) {
  double num = INT_MAX;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

// START_TEST(s21_ceil_test_18) {
//   double num = LONG_MAX;
//   ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
// }
// END_TEST

START_TEST(s21_ceil_test_19) {
  double num = -LONG_MAX;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

START_TEST(s21_ceil_test_20) {
  double num = 5.000000000000001;
  ck_assert_double_eq_tol(s21_ceil(num), ceil(num), 0.000001);
}
END_TEST

START_TEST(test_tolerance_pos) {
  double a = 0.1;
  int i = _i;
  ck_assert_ldouble_eq_tol(ceil(a * i), s21_ceil(a * i), S21_EPS);
}
END_TEST

START_TEST(test_tolerance_neg) {
  double a = 0.1;
  int i = _i;
  ck_assert_ldouble_eq_tol(ceil(-a * i), s21_ceil(-a * i), S21_EPS);
}
END_TEST

Suite *s21_ceil_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_ceil_suite");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_ceil_test);
  tcase_add_test(tc_core, s21_ceil_test_1);
  tcase_add_test(tc_core, s21_ceil_test_2);
  tcase_add_test(tc_core, s21_ceil_test_3);
  // tcase_add_test(tc_core, s21_ceil_test_4);
  tcase_add_test(tc_core, s21_ceil_test_5);
  tcase_add_test(tc_core, s21_ceil_test_6);
  tcase_add_test(tc_core, s21_ceil_test_7);
  tcase_add_test(tc_core, s21_ceil_test_8);
  tcase_add_test(tc_core, s21_ceil_test_9);
  // tcase_add_test(tc_core, s21_ceil_test_10);
  // tcase_add_test(tc_core, s21_ceil_test_11);
  // tcase_add_test(tc_core, s21_ceil_test_12);
  // tcase_add_test(tc_core, s21_ceil_test_13);
  // tcase_add_test(tc_core, s21_ceil_test_14);
  tcase_add_test(tc_core, s21_ceil_test_15);
  tcase_add_test(tc_core, s21_ceil_test_16);
  tcase_add_test(tc_core, s21_ceil_test_17);
  // tcase_add_test(tc_core, s21_ceil_test_18);
  tcase_add_test(tc_core, s21_ceil_test_19);
  tcase_add_test(tc_core, s21_ceil_test_20);
  tcase_add_test(tc_core, test_tolerance_pos);
  tcase_add_test(tc_core, test_tolerance_neg);
  suite_add_tcase(s, tc_core);
  return s;
}

int run_s21_ceil() {
  int number_filed = 0;
  Suite *s21_ceil = s21_ceil_suite();
  SRunner *sr;
  sr = srunner_create(s21_ceil);
  srunner_run_all(sr, CK_NORMAL);
  number_filed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_filed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
