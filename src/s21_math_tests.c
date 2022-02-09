#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(absTest) {
  ck_assert_int_eq(s21_abs(-15), abs(-15));
  ck_assert_int_eq(s21_abs(15), abs(15));
  ck_assert_int_eq(s21_abs((int)NAN), abs((int)NAN));
  ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
  ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));
}
END_TEST

START_TEST(fabsTest) {
  ck_assert_ldouble_eq(s21_fabs(-15.01), fabs(-15.01));
  ck_assert_ldouble_eq(s21_fabs(15.01), fabs(15.01));
  ck_assert_ldouble_eq(s21_fabs(INFINITY), fabs(INFINITY));
  ck_assert_ldouble_eq(s21_fabs(-INFINITY), fabs(-INFINITY));

  double num = NAN;
  long double orig_res = fabs(num), our_res = s21_fabs(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(ceilTest) {
  ck_assert_ldouble_eq(s21_ceil(-15.01), ceil(-15.01));
  ck_assert_ldouble_eq(s21_ceil(15.01), ceil(15.01));
  ck_assert_ldouble_eq(s21_ceil(INFINITY), ceil(INFINITY));
  ck_assert_ldouble_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
  ck_assert_ldouble_eq(s21_ceil(-0.12), ceil(-0.12));

  double num = NAN;
  long double orig_res = ceil(num), our_res = s21_ceil(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(floorTest) {
  ck_assert_ldouble_eq(s21_floor(-15.01), floor(-15.01));
  ck_assert_ldouble_eq(s21_floor(15.01), floor(15.01));
  ck_assert_ldouble_eq(s21_floor(INFINITY), floor(INFINITY));
  ck_assert_ldouble_eq(s21_floor(-INFINITY), floor(-INFINITY));

  double num = NAN;
  long double orig_res = floor(num), our_res = s21_floor(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sqrtTest) {
  double num = INFINITY;
  long double orig_res = sqrt(num), our_res = s21_sqrt(num);
  int suc = 0;
  if (isinf(orig_res) && isinf(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -INFINITY;
  orig_res = sqrt(num), our_res = s21_sqrt(num);
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -15.01;
  orig_res = sqrt(num), our_res = s21_sqrt(num);
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = 0.9999;
  orig_res = sqrt(num), our_res = s21_sqrt(num);
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = NAN;
  orig_res = sqrt(num), our_res = s21_sqrt(num);
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(atanTest) {
  ck_assert_float_eq(s21_atan(-15.01), atan(-15.01));

  double num = -0.99;
  long double orig_res = s21_atan(num), our_res = atan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  ck_assert_float_eq(-9999999999, -9999999999);

  ck_assert_ldouble_eq(s21_atan(INFINITY), atan(INFINITY));
  ck_assert_ldouble_eq(s21_atan(-INFINITY), atan(-INFINITY));

  num = NAN;
  orig_res = s21_atan(num), our_res = atan(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(acosTest) {
  double num = 0.55;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -0.99;
  orig_res = acos(num), our_res = s21_acos(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -9;
  orig_res = acos(num), our_res = s21_acos(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  orig_res = acos(num), our_res = s21_acos(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -INFINITY;
  orig_res = acos(num), our_res = s21_acos(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = NAN;
  orig_res = s21_acos(num), our_res = acos(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(asinTest) {
  double num = 0.55;
  long double orig_res = asin(num), our_res = s21_asin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -0.99;
  orig_res = asin(num), our_res = s21_asin(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -9;
  orig_res = asin(num), our_res = s21_asin(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  orig_res = asin(num), our_res = s21_asin(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -INFINITY;
  orig_res = asin(num), our_res = s21_asin(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = NAN;
  orig_res = asin(num), our_res = s21_asin(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sinTest) {
  double num = 0.55;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  ck_assert_float_eq(s21_sin(0), sin(0));

  num = 1;
  orig_res = s21_sin(num), our_res = s21_sin(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -1;
  orig_res = s21_sin(num), our_res = s21_sin(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = 0.999999;
  orig_res = s21_sin(num), our_res = s21_sin(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -0.999999;
  orig_res = s21_sin(num), our_res = s21_sin(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = NAN;
  orig_res = sin(num), our_res = s21_sin(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  orig_res = sin(num), our_res = s21_sin(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -INFINITY;
  orig_res = sin(num), our_res = s21_sin(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cosTest) {
  double num = 0.55;
  long double orig_res = s21_cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -0.999999;
  orig_res = cos(num), our_res = s21_cos(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = 628;
  orig_res = cos(num), our_res = s21_cos(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  ck_assert_float_eq(s21_cos(0), cos(0));
  ck_assert_float_eq(s21_cos(-1), cos(-1));

  num = NAN;
  orig_res = cos(num), our_res = s21_cos(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  orig_res = cos(num), our_res = s21_cos(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -INFINITY;
  orig_res = cos(num), our_res = s21_cos(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tanTest) {
  ck_assert_float_eq(s21_tan(-15.01), tan(-15.01));

  double num = 0.55;
  long double orig_res = s21_tan(num), our_res = s21_tan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  ck_assert_float_eq(-9999999999, -9999999999);

  num = NAN;
  orig_res = tan(num), our_res = s21_tan(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  orig_res = tan(num), our_res = s21_tan(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -INFINITY;
  orig_res = tan(num), our_res = s21_tan(num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(expTest) {
  ck_assert_float_eq(s21_exp(2), exp(2));
  ck_assert_float_eq(s21_exp(-750), exp(-750));
  ck_assert_float_eq(s21_exp(-2), exp(-2));

  double num = NAN;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  orig_res = exp(num), our_res = s21_exp(num);
  suc = 0;
  if (isinf(orig_res) && isinf(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -INFINITY;
  orig_res = exp(num), our_res = s21_exp(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(logTest) {
  double num = 456.789;
  long double orig_res = log(num), our_res = s21_log(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = NAN;
  orig_res = log(num);
  our_res = s21_log(num);
  suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = 0.001;
  orig_res = log(num);
  our_res = s21_log(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = 0.4;
  orig_res = log(num);
  our_res = s21_log(num);
  suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = -INFINITY;
  orig_res = log(num);
  our_res = s21_log(num);
  suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  orig_res = log(num);
  our_res = s21_log(num);
  suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(powTest) {
  double num = 456.789;
  double ex = 1.1;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  ck_assert_float_eq(our_res, orig_res);
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  ex = 1.1;
  orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = NAN;
  ex = 1.1;
  orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = NAN;
  ex = NAN;
  orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = 0.001;
  ex = NAN;
  orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  ex = INFINITY;
  orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = INFINITY;
  ex = INFINITY;
  orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(fmodTest) {
  ck_assert_ldouble_eq(s21_fmod(2.34, 2.0), fmod(2.34, 2.0));
  ck_assert_ldouble_eq(s21_fmod(-2.34, 2.0), fmod(-2.34, 2.0));
  ck_assert_ldouble_eq(s21_fmod(2.34, -2.0), fmod(2.34, -2.0));
  ck_assert_ldouble_eq(s21_fmod(-2.34, -2.0), fmod(-2.34, -2.0));

  double num = NAN;
  long double orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  num = NAN;
  orig_res = fmod(2.0, num), our_res = s21_fmod(2.0, num);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  ck_assert_ldouble_eq(s21_fmod(2.0, INFINITY), fmod(2.0, INFINITY));

  num = INFINITY;
  orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);

  ck_assert_ldouble_eq(s21_fmod(2.0, -INFINITY), fmod(2.0, -INFINITY));

  num = -INFINITY;
  orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
  suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

Suite *Suite_create(void) {
  Suite *s21_string = suite_create("s21_string");
  TCase *tcase_test = tcase_create("test");

  tcase_add_test(tcase_test, absTest);
  tcase_add_test(tcase_test, fabsTest);
  tcase_add_test(tcase_test, ceilTest);
  tcase_add_test(tcase_test, floorTest);
  tcase_add_test(tcase_test, asinTest);
  tcase_add_test(tcase_test, acosTest);
  tcase_add_test(tcase_test, sqrtTest);
  tcase_add_test(tcase_test, atanTest);
  tcase_add_test(tcase_test, sinTest);
  tcase_add_test(tcase_test, cosTest);
  tcase_add_test(tcase_test, tanTest);
  tcase_add_test(tcase_test, expTest);
  tcase_add_test(tcase_test, logTest);
  tcase_add_test(tcase_test, powTest);
  tcase_add_test(tcase_test, fmodTest);

  suite_add_tcase(s21_string, tcase_test);

  return s21_string;
}

int main(void) {
  Suite *suite = Suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);

  int failed_count = srunner_ntests_failed(suite_runner);

  srunner_free(suite_runner);

  return (failed_count != 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
