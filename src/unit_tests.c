#include <check.h>
#include <math.h>

#include "s21_math.h"

START_TEST(abs_1) { ck_assert_int_eq(s21_abs(21), abs(21)); }
END_TEST

START_TEST(abs_2) { ck_assert_int_eq(s21_abs(-21), abs(-21)); }
END_TEST

START_TEST(abs_3) { ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647)); }
END_TEST

START_TEST(abs_4) { ck_assert_int_eq(s21_abs(2147483647), abs(2147483647)); }
END_TEST

START_TEST(abs_5) { ck_assert_int_eq(s21_abs(-0), abs(-0)); }
END_TEST

START_TEST(abs_6) { ck_assert_int_eq(s21_abs(+0), abs(+0)); }
END_TEST

START_TEST(abs_7) { ck_assert_int_eq(s21_abs((int)NAN), abs((int)NAN)); }
END_TEST

START_TEST(abs_8) {
  ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
}
END_TEST

START_TEST(abs_9) {
  ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));
}
END_TEST

START_TEST(abs_10) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

START_TEST(ceil_test1) {
  ck_assert_double_eq(ceil(INFINITY), s21_ceil(s21_INFINITY));
}
END_TEST

START_TEST(ceil_test2) {
  ck_assert_double_eq(ceil(-INFINITY), s21_ceil(-s21_INFINITY));
}
END_TEST

START_TEST(ceil_test3) { ck_assert_double_nan(ceil(NAN)); }
END_TEST

START_TEST(ceil_test4) { ck_assert_double_nan(s21_ceil(s21_NAN)); }
END_TEST

START_TEST(ceil_test5) { ck_assert_double_eq(ceil(-7.0), s21_ceil(-7.0)); }
END_TEST

START_TEST(ceil_test6) { ck_assert_double_eq(ceil(-98.1), s21_ceil(-98.1)); }
END_TEST

START_TEST(ceil_test7) { ck_assert_double_eq(ceil(123.02), s21_ceil(123.02)); }
END_TEST

START_TEST(ceil_test8) {
  ck_assert_double_eq(ceil(10009.00123), s21_ceil(10009.00123));
}
END_TEST

START_TEST(ceil_test9) {
  ck_assert_double_eq(ceil(-10009.555), s21_ceil(-10009.555));
}
END_TEST

START_TEST(ceil_test10) {
  ck_assert_double_eq(ceil(-0.10009), s21_ceil(-0.10009));
}
END_TEST

START_TEST(ceil_test11) { ck_assert_double_eq(ceil(-1e-23), s21_ceil(-1e-23)); }
END_TEST

START_TEST(floor_1) { ck_assert_ldouble_eq(s21_floor(0.0), floor(0.0)); }
END_TEST

START_TEST(floor_2) { ck_assert_ldouble_eq(s21_floor(21.21), floor(21.21)); }
END_TEST

START_TEST(floor_3) { ck_assert_ldouble_eq(s21_floor(21.91), floor(21.91)); }
END_TEST

START_TEST(floor_4) { ck_assert_ldouble_eq(s21_floor(-21.21), floor(-21.21)); }
END_TEST

START_TEST(floor_5) { ck_assert_ldouble_eq(s21_floor(-21.91), floor(-21.91)); }
END_TEST

START_TEST(floor_6) {
  ck_assert_ldouble_infinite(s21_floor(INFINITY));
  ck_assert_ldouble_infinite(floor(INFINITY));
}
END_TEST

START_TEST(floor_7) {
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_nan(floor(NAN));
}
END_TEST

START_TEST(floor_8) { ck_assert_ldouble_eq(s21_floor(0), floor(0)); }
END_TEST

START_TEST(floor_10) { ck_assert_ldouble_eq(s21_floor(-15.01), floor(-15.01)); }
END_TEST

START_TEST(floor_11) { ck_assert_ldouble_eq(s21_floor(15.01), floor(15.01)); }
END_TEST

START_TEST(floor_12) {
  ck_assert_ldouble_eq(s21_floor(INFINITY), floor(INFINITY));
}
END_TEST

START_TEST(floor_13) {
  ck_assert_ldouble_eq(s21_floor(-INFINITY), floor(-INFINITY));
}
END_TEST

START_TEST(floor_14) {
  double num = NAN;
  long double orig_res = floor(num), our_res = s21_floor(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(floor_15) { ck_assert_ldouble_eq(s21_floor(-0), floor(-0)); }
END_TEST

START_TEST(floor_16) { ck_assert_double_eq(floor(-7.0), s21_floor(-7.0)); }
END_TEST

START_TEST(floor_17) { ck_assert_double_eq(floor(-98.1), s21_floor(-98.1)); }
END_TEST

START_TEST(floor_18) { ck_assert_double_eq(floor(123.02), s21_floor(123.02)); }
END_TEST

START_TEST(floor_19) {
  ck_assert_double_eq(floor(10009.00123), s21_floor(10009.00123));
}
END_TEST

START_TEST(floor_20) {
  ck_assert_double_eq(floor(-10009.555), s21_floor(-10009.555));
}
END_TEST

START_TEST(floor_21) {
  ck_assert_double_eq(floor(-0.10009), s21_floor(-0.10009));
}
END_TEST

START_TEST(floor_22) { ck_assert_double_eq(floor(-1e-23), s21_floor(-1e-23)); }
END_TEST

START_TEST(floor_23) {
  ck_assert_double_eq(floor(100091234.5), s21_floor(100091234.5));
}
END_TEST

START_TEST(s21_fmod_test_1) {
  ck_assert_ldouble_eq(s21_fmod(2.34, 2.0), fmod(2.34, 2.0));
}
END_TEST

START_TEST(s21_fmod_test_2) {
  ck_assert_ldouble_eq(s21_fmod(-2.34, 2.0), fmod(-2.34, 2.0));
}
END_TEST

START_TEST(s21_fmod_test_3) {
  ck_assert_ldouble_eq(s21_fmod(2.34, -2.0), fmod(2.34, -2.0));
}
END_TEST

START_TEST(s21_fmod_test_4) {
  ck_assert_ldouble_eq(s21_fmod(-2.34, -2.0), fmod(-2.34, -2.0));
}
END_TEST

START_TEST(s21_fmod_test_5) {
  ck_assert_ldouble_eq(s21_fmod(21.21, 3), fmod(21.21, 3));
}
END_TEST

START_TEST(s21_fmod_test_6) {
  ck_assert_ldouble_eq(s21_fmod(3, 21.21), fmod(3, 21.21));
}
END_TEST

START_TEST(s21_fmod_test_7) {
  ck_assert_ldouble_eq(s21_fmod(-21.21, 3), fmod(-21.21, 3));
}
END_TEST

START_TEST(s21_fmod_test_8) {
  ck_assert_ldouble_eq(s21_fmod(3, -21.21), fmod(3, -21.21));
}
END_TEST

START_TEST(s21_fmod_test_9) {
  ck_assert_ldouble_eq(s21_fmod(100500, 9), fmod(100500, 9));
}
END_TEST

START_TEST(s21_fmod_test_10) {
  ck_assert_ldouble_eq(s21_fmod(-100500, -9), fmod(-100500, -9));
}
END_TEST

START_TEST(s21_fmod_test_11) {
  ck_assert_ldouble_eq(s21_fmod(-9, -100500), fmod(-9, -100500));
}
END_TEST

START_TEST(s21_fmod_test_12) {
  ck_assert_ldouble_eq(s21_fmod(-9, -9), fmod(-9, -9));
}
END_TEST

START_TEST(s21_fmod_test_13) {
  ck_assert_ldouble_eq(s21_fmod(10, 5), fmod(10, 5));
}
END_TEST

START_TEST(s21_fmod_test_14) {
  ck_assert_ldouble_nan(s21_fmod(INFINITY, INFINITY));
  ck_assert_ldouble_nan(fmod(INFINITY, INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_15) {
  ck_assert_ldouble_nan(s21_fmod(NAN, NAN));
  ck_assert_ldouble_nan(fmod(NAN, NAN));
}
END_TEST

START_TEST(s21_fmod_test_16) { ck_assert_ldouble_nan(s21_fmod(2.45, 0)); }
END_TEST

START_TEST(s21_fmod_test_17) { ck_assert_ldouble_nan(s21_fmod(0, 0)); }
END_TEST

START_TEST(s21_fmod_test_18) { ck_assert_ldouble_nan(s21_fmod(INFINITY, 0)); }
END_TEST

START_TEST(s21_fmod_test_19) {
  double num = NAN;
  long double orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_20) {
  double num = NAN;
  long double orig_res = fmod(2.0, num), our_res = s21_fmod(2.0, num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_21) {
  ck_assert_ldouble_eq(s21_fmod(2.0, INFINITY), fmod(2.0, INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_22) {
  double num = INFINITY;
  long double orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_23) {
  ck_assert_ldouble_eq(s21_fmod(2.0, INFINITY), fmod(2.0, INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_24) {
  ck_assert_ldouble_eq(s21_fmod(2.0, -INFINITY), fmod(2.0, -INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_25) {
  double num = -INFINITY;
  long double orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_26) {
  ck_assert_ldouble_nan(s21_fmod(s21_INFINITY, s21_INFINITY));
  ck_assert_ldouble_nan(fmod(s21_INFINITY, s21_INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_27) {
  ck_assert_ldouble_eq(s21_fmod(0, 23), fmod(0, 23));
}
END_TEST

START_TEST(s21_fmod_test_28) {
  ck_assert_double_eq(fmod(0, -1), s21_fmod(0, -1));
}
END_TEST

START_TEST(s21_fmod_test_29) {
  ck_assert_double_eq(fmod(0, 1), s21_fmod(0, 1));
}
END_TEST

START_TEST(s21_fmod_test_30) { ck_assert_double_nan(s21_fmod(INFINITY, -1)); }

START_TEST(s21_fmod_test_31) {
  ck_assert_double_eq(fmod(-1, -INFINITY), s21_fmod(-1, -INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_32) {
  ck_assert_double_eq(fmod(0, INFINITY), s21_fmod(0, INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_33) { ck_assert_double_nan(s21_fmod(0, s21_NAN)); }
END_TEST

START_TEST(s21_fmod_test_34) {
  ck_assert_double_nan(s21_fmod(s21_NAN, s21_NAN));
}
END_TEST

START_TEST(s21_fmod_test_35) {
  ck_assert_double_nan(s21_fmod(s21_NAN, INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_36) {
  ck_assert_double_nan(s21_fmod(INFINITY, s21_NAN));
}
END_TEST

START_TEST(s21_fmod_test_37) {
  ck_assert_double_nan(s21_fmod(s21_NAN, -INFINITY));
}
END_TEST

START_TEST(s21_fmod_test_38) {
  ck_assert_double_nan(s21_fmod(-INFINITY, s21_NAN));
}
END_TEST

START_TEST(s21_fmod_test_39) {
  for (double a = -1500; a < 1500; a += 123) {
    for (double b = -12; b < 12; b += 1.25) {
      ck_assert_double_eq(fmod(a, b), s21_fmod(a, b));
      ck_assert_double_eq(fmod(b, a), s21_fmod(b, a));
    }
  }
}
END_TEST

START_TEST(fabs_1) { ck_assert_ldouble_eq(s21_fabs(0.000001), fabs(0.000001)); }
END_TEST

START_TEST(fabs_2) {
  ck_assert_ldouble_eq(s21_fabs(-21.000345), fabs(-21.000345));
}
END_TEST

START_TEST(fabs_3) {
  ck_assert_ldouble_eq(s21_fabs(-2147483600.543), fabs(-2147483600.543));
}
END_TEST

START_TEST(fabs_4) {
  ck_assert_ldouble_eq(s21_fabs(2147483600.4857), fabs(2147483600.4857));
}
END_TEST

START_TEST(fabs_5) {
  double a = -5.53151413431;
  ck_assert_ldouble_eq(s21_fabs(a), fabs(a));
}
END_TEST

START_TEST(fabs_6) {
  double a = NAN;
  ck_assert_ldouble_nan(s21_fabs(a));
  ck_assert_ldouble_nan(fabs(a));
}
END_TEST

START_TEST(fabs_7) {
  double a = s21_INFINITY;
  ck_assert_ldouble_infinite(s21_fabs(a));
  ck_assert_ldouble_infinite(fabs(a));
}
END_TEST

START_TEST(fabs_8) {
  double a = -9519359135915.53151413431;
  ck_assert_ldouble_eq_tol(s21_fabs(a), fabs(a), 10e-6);
}
END_TEST

START_TEST(fabs_10) {
  ck_assert_ldouble_nan(s21_fabs(NAN));
  ck_assert_ldouble_nan(fabs(NAN));
}
END_TEST

START_TEST(fabs_11) { ck_assert_ldouble_eq(s21_fabs(-15.01), fabs(-15.01)); }
END_TEST

START_TEST(fabs_12) { ck_assert_ldouble_eq(s21_fabs(15.01), fabs(15.01)); }
END_TEST

START_TEST(fabs_13) {
  ck_assert_ldouble_eq(s21_fabs(INFINITY), fabs(INFINITY));
}
END_TEST

START_TEST(fabs_14) {
  ck_assert_ldouble_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
}
END_TEST

START_TEST(sin_1) {
  double num = 0.55;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_2) { ck_assert_float_eq(s21_sin(0), sin(0)); }
END_TEST

START_TEST(sin_3) {
  double num = 1;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_4) {
  double num = -1;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_5) {
  double num = 0.999999;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_6) {
  double num = -0.999999;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_7) {
  double num = NAN;
  long double orig_res = sin(num), our_res = s21_sin(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_8) {
  double num = INFINITY;
  long double orig_res = sin(num), our_res = s21_sin(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_9) {
  double num = -INFINITY;
  long double orig_res = sin(num), our_res = s21_sin(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_10) {
  double x = 0;
  ck_assert_double_eq_tol(s21_sin(x), sinl(x), 1e-06);
}
END_TEST

START_TEST(sin_11) {
  ck_assert_ldouble_nan(s21_sin(-INFINITY));
  ck_assert_ldouble_nan(sinl(-INFINITY));
}
END_TEST

START_TEST(sin_12) {
  ck_assert_ldouble_nan(s21_sin(INFINITY));
  ck_assert_ldouble_nan(sinl(INFINITY));
}
END_TEST

START_TEST(sin_13) {
  ck_assert_ldouble_nan(s21_sin(NAN));
  ck_assert_ldouble_nan(sinl(NAN));
}
END_TEST

START_TEST(sin_14) { ck_assert_double_eq_tol(s21_sin(0.0), sin(0.0), 1e-06); }
END_TEST

START_TEST(sin_15) {
  ck_assert_double_eq_tol(s21_sin(s21_PI / 6), sin(s21_PI / 6), 1e-06);
}
END_TEST

START_TEST(sin_16) {
  ck_assert_double_eq_tol(s21_sin(s21_PI / 4), sin(s21_PI / 4), 1e-06);
}
END_TEST

START_TEST(sin_17) {
  ck_assert_double_eq_tol(s21_sin(s21_PI / 3), sin(s21_PI / 3), 1e-06);
}
END_TEST

START_TEST(sin_18) {
  ck_assert_double_eq_tol(s21_sin(s21_PI / 2), sin(s21_PI / 2), 1e-06);
}
END_TEST

START_TEST(sin_19) {
  ck_assert_double_eq_tol(s21_sin(3 * s21_PI / 2), sin(3 * s21_PI / 2), 1e-06);
}
END_TEST

START_TEST(sin_20) {
  ck_assert_double_eq_tol(s21_sin(2 * s21_PI), sin(2 * s21_PI), 1e-06);
}
END_TEST

START_TEST(sin_21) {
  ck_assert_double_eq_tol(s21_sin(-2 * s21_PI), sin(-2 * s21_PI), 1e-06);
}
END_TEST

START_TEST(sin_22) {
  ck_assert_double_eq_tol(s21_sin(-3 * s21_PI), sin(-3 * s21_PI), 1e-06);
}
END_TEST

START_TEST(sin_23) {
  ck_assert_double_eq_tol(s21_sin(174.532925199433), sin(174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(sin_24) {
  ck_assert_double_eq_tol(s21_sin(-174.532925199433), sin(-174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(sin_25) {
  ck_assert_double_eq_tol(s21_sin(-s21_PI), sin(-s21_PI), 1e-06);
}
END_TEST

START_TEST(sin_26) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * s21_PI; k > -2 * s21_PI; k -= s21_PI / 17) {
      ck_assert_double_eq_tol(sin(k + R * s21_PI), s21_sin(k + R * s21_PI),
                              1e-6);
    }
  }
}
END_TEST

START_TEST(cos_1) {
  double num = 0.55;
  long double orig_res = s21_cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_2) {
  double num = -0.999999;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_3) {
  double num = 628;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_4) { ck_assert_float_eq(s21_cos(0), cos(0)); }
END_TEST

START_TEST(cos_5) { ck_assert_float_eq(s21_cos(-1), cos(-1)); }
END_TEST

START_TEST(cos_6) {
  double num = NAN;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_7) {
  double num = INFINITY;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_8) {
  double num = -INFINITY;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_9) {
  double x = 0;
  ck_assert_double_eq_tol(s21_cos(x), cosl(x), 1e-06);
}
END_TEST

START_TEST(cos_10) {
  ck_assert_ldouble_nan(s21_cos(-INFINITY));
  ck_assert_ldouble_nan(cosl(-INFINITY));
}
END_TEST

START_TEST(cos_11) {
  ck_assert_ldouble_nan(s21_cos(INFINITY));
  ck_assert_ldouble_nan(cosl(INFINITY));
}
END_TEST

START_TEST(cos_12) {
  ck_assert_ldouble_nan(s21_cos(NAN));
  ck_assert_ldouble_nan(cosl(NAN));
}
END_TEST

START_TEST(cos_13) { ck_assert_double_eq_tol(s21_cos(0.0), cosl(0.0), 1e-06); }
END_TEST

START_TEST(cos_14) {
  ck_assert_double_eq_tol(s21_cos(s21_PI / 4), cosl(s21_PI / 4), 1e-06);
}
END_TEST

START_TEST(cos_15) {
  ck_assert_double_eq_tol(s21_cos(s21_PI / 6), cosl(s21_PI / 6), 1e-06);
}
END_TEST

START_TEST(cos_16) {
  ck_assert_double_eq_tol(s21_cos(s21_PI / 3), cosl(s21_PI / 3), 1e-06);
}
END_TEST

START_TEST(cos_17) {
  ck_assert_double_eq_tol(s21_cos(s21_PI / 2), cosl(s21_PI / 2), 1e-06);
}
END_TEST

START_TEST(cos_18) {
  ck_assert_double_eq_tol(s21_cos(3 * s21_PI / 2), cosl(3 * s21_PI / 2), 1e-06);
}
END_TEST

START_TEST(cos_19) {
  ck_assert_double_eq_tol(s21_cos(2 * s21_PI), cosl(2 * s21_PI), 1e-06);
}
END_TEST

START_TEST(cos_20) {
  ck_assert_double_eq_tol(s21_cos(174.532925199433), cosl(174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(cos_21) {
  ck_assert_double_eq_tol(s21_cos(-174.532925199433), cosl(-174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(cos_22) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * s21_PI; k > -2 * s21_PI; k -= s21_PI / 17) {
      ck_assert_double_eq_tol(cos(k + R * s21_PI), s21_cos(k + R * s21_PI),
                              1e-6);
    }
  }
}
END_TEST

START_TEST(tan_1) { ck_assert_float_eq(s21_tan(-15.01), tan(-15.01)); }
END_TEST

START_TEST(tan_2) {
  double num = 0.55;
  long double orig_res = s21_tan(num), our_res = s21_tan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tan_4) {
  double num = NAN;
  long double orig_res = tan(num), our_res = s21_tan(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tan_5) {
  double num = INFINITY;
  long double orig_res = tan(num), our_res = s21_tan(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tan_6) {
  double num = -INFINITY;
  long double orig_res = tan(num), our_res = s21_tan(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tan_7) {
  double x = 0;
  ck_assert_double_eq_tol(s21_tan(x), tanl(x), 1e-06);
}
END_TEST

START_TEST(tan_8) {
  ck_assert_ldouble_nan(s21_tan(-INFINITY));
  ck_assert_ldouble_nan(tanl(-INFINITY));
}
END_TEST

START_TEST(tan_9) {
  ck_assert_ldouble_nan(s21_tan(INFINITY));
  ck_assert_ldouble_nan(tanl(INFINITY));
}
END_TEST

START_TEST(tan_10) {
  ck_assert_ldouble_nan(s21_tan(NAN));
  ck_assert_ldouble_nan(tanl(NAN));
}
END_TEST

START_TEST(tan_11) { ck_assert_double_eq_tol(s21_tan(0.0), tanl(0.0), 1e-06); }
END_TEST

START_TEST(tan_12) {
  ck_assert_double_eq_tol(s21_tan(s21_PI / 6), tanl(s21_PI / 6), 1e-06);
}
END_TEST

START_TEST(tan_13) {
  ck_assert_double_eq_tol(s21_tan(s21_PI / 4), tanl(s21_PI / 4), 1e-06);
}
END_TEST

START_TEST(tan_14) {
  ck_assert_double_eq_tol(s21_tan(-2 * s21_PI), tanl(-2 * s21_PI), 1e-06);
}
END_TEST

START_TEST(tan_15) {
  ck_assert_double_eq_tol(s21_tan(s21_PI), tanl(s21_PI), 1e-06);
}
END_TEST

START_TEST(tan_16) {
  ck_assert_double_eq_tol(s21_tan(s21_PI / 3), tanl(s21_PI / 3), 1e-06);
}
END_TEST

START_TEST(tan_17) {
  ck_assert_double_eq_tol(s21_tan(3 * s21_PI / 3), tanl(3 * s21_PI / 3), 1e-06);
}
END_TEST

START_TEST(tan_18) {
  ck_assert_double_eq_tol(s21_tan(174.532925199433), tanl(174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(tan_19) {
  ck_assert_double_eq_tol(s21_tan(-174.532925199433), tanl(-174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(tan_22) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * s21_PI; k > -2 * s21_PI; k -= s21_PI / 9) {
      ck_assert_double_eq_tol(tan(k + R * s21_PI), s21_tan(k + R * s21_PI),
                              1e-6);
    }
  }
}
END_TEST

START_TEST(atan_1) { ck_assert_float_eq(s21_atan(-15.01), atan(-15.01)); }
END_TEST

START_TEST(atan_2) {
  double num = -0.99;
  long double orig_res = s21_atan(num), our_res = atan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(atan_3) { ck_assert_float_eq(-9999999999, -9999999999); }
END_TEST

START_TEST(atan_4) {
  ck_assert_ldouble_eq_tol(s21_atan(INFINITY), atan(INFINITY), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-INFINITY), atan(-INFINITY), 1e-6);
}
END_TEST

START_TEST(atan_5) {
  double num = NAN;
  long double orig_res = s21_atan(num), our_res = atan(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(atan_6) {
  ck_assert_ldouble_eq_tol(s21_atan(INFINITY), (s21_PI / 2.0), 1e-6);
  ck_assert_ldouble_eq_tol(atan(INFINITY), (s21_PI / 2.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan((-INFINITY)), ((s21_PI) / -2.0), 1e-6);
  ck_assert_ldouble_eq_tol(atan(-INFINITY), ((s21_PI) / -2.0), 1e-6);
}
END_TEST

START_TEST(atan_7) {
  ck_assert_ldouble_nan(s21_atan(NAN));
  ck_assert_ldouble_nan(atan(NAN));
}
END_TEST

START_TEST(atan_8) {
  ck_assert_ldouble_eq_tol(s21_atan(1.0), atan(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1.1), atan(1.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1.0), atan(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1.1), atan(-1.1), 1e-6);
}
END_TEST

START_TEST(atan_9) {
  ck_assert_ldouble_eq_tol(s21_atan(0.0), atan(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-0.0), atan(-0.0), 1e-6);
}
END_TEST

START_TEST(atan_10) { ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6); }
END_TEST

START_TEST(atan_11) {
  ck_assert_ldouble_eq_tol(s21_atan(-sqrt(3) / 2), atan(-sqrt(3) / 2), 1e-6);
}
END_TEST

START_TEST(atan_12) {
  ck_assert_ldouble_eq_tol(s21_atan(-sqrt(2) / 2), atan(-sqrt(2) / 2), 1e-6);
}
END_TEST

START_TEST(atan_13) {
  ck_assert_ldouble_eq_tol(s21_atan(-1 / 2), atan(-1 / 2), 1e-6);
}
END_TEST

START_TEST(atan_14) {
  ck_assert_ldouble_eq_tol(s21_atan(1 / 2), atan(1 / 2), 1e-6);
}
END_TEST

START_TEST(atan_15) { ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6); }
END_TEST

START_TEST(atan_16) {
  ck_assert_ldouble_eq_tol(s21_atan(sqrt(3) / 2), atan(sqrt(3) / 2), 1e-6);
}
END_TEST

START_TEST(atan_17) { ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6); }
END_TEST

START_TEST(atan_18) {
  ck_assert_ldouble_eq_tol(s21_atan(1.23456e-7), atan(1.23456e-7), 1e-6);
}
END_TEST

START_TEST(atan_19) {
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567), atan(2.1234567), 1e-6);
}
END_TEST

START_TEST(atan_20) {
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567e-7), atan(2.1234567e-7), 1e-6);
}
END_TEST

START_TEST(atan_21) {
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567e-16), atan(2.1234567e-16), 1e-6);
}
END_TEST

START_TEST(atan_22) { ck_assert_float_nan(s21_atan(s21_NAN)); }
END_TEST

START_TEST(atan_23) {
  ck_assert_ldouble_eq_tol(s21_atan(s21_PI / 2), atan(s21_PI / 2), 1e-6);
}
END_TEST

START_TEST(atan_24) {
  ck_assert_ldouble_eq_tol(s21_atan(-s21_PI / 2), atan(-s21_PI / 2), 1e-6);
}
END_TEST

START_TEST(atan_25) {
  for (float k = -10; k <= 10; k += 4) {
    double a = s21_atan(k);
    double b = atan(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(sqrt_1) {
  for (double k = 0; k < 21; k += 3) {
    double a = s21_sqrt(k);
    double b = sqrt(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(sqrt_2) { ck_assert_double_nan(s21_sqrt(s21_NAN)); }
END_TEST

START_TEST(sqrt_3) { ck_assert_double_eq(s21_sqrt(INFINITY), sqrt(INFINITY)); }
END_TEST

START_TEST(sqrt_4) { ck_assert_double_nan(s21_sqrt(-INFINITY)); }
END_TEST

START_TEST(sqrt_5) { ck_assert_double_nan(s21_sqrt(-5)); }
END_TEST

START_TEST(sqrt_6) {
  ck_assert_double_eq_tol(s21_sqrt(1000), sqrt(1000), 1e-7);
}
END_TEST

START_TEST(sqrt_7) {
  ck_assert_ldouble_infinite(s21_sqrt(INFINITY));
  ck_assert_ldouble_infinite(sqrt(INFINITY));
}
END_TEST

START_TEST(sqrt_8) {
  ck_assert_ldouble_nan(s21_sqrt(NAN));
  ck_assert_ldouble_nan(sqrt(NAN));
}
END_TEST

START_TEST(sqrt_9) {
  ck_assert_ldouble_eq_tol(s21_sqrt(1.0), sqrt(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(1.1), sqrt(1.1), 1e-6);
}
END_TEST

START_TEST(sqrt_10) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0.0), sqrt(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(-0.0), sqrt(-0.0), 1e-6);
}
END_TEST

START_TEST(sqrt_11) {
  ck_assert_ldouble_eq_tol(s21_sqrt(10e+16), sqrt(10e+16), 1e-6);
}
END_TEST

START_TEST(sqrt_12) { ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-6); }
END_TEST

START_TEST(sqrt_13) {
  ck_assert_ldouble_eq_tol(s21_sqrt(100), sqrt(100), 1e-6);
}
END_TEST

START_TEST(sqrt_14) {
  ck_assert_ldouble_eq_tol(s21_sqrt(98765432.123), sqrt(98765432.123), 1e-6);
}
END_TEST

START_TEST(sqrt_15) {
  ck_assert_ldouble_eq_tol(s21_sqrt(981.123e6), sqrt(981.123e6), 1e-6);
}
END_TEST

START_TEST(sqrt_16) {
  ck_assert_ldouble_eq_tol(s21_sqrt(981.123e-15), sqrt(981.123e-15), 1e-6);
}
END_TEST

START_TEST(asin_test_1) {
  for (float k = -1; k <= 1; k += 0.1) {
    long double a = s21_asin(k);
    long double b = asin(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
  ck_assert_double_eq_tol(asin(1), s21_asin(1), 1e-6);
}
END_TEST

START_TEST(asin_test_2) {
  for (float k = -1; k <= 1; k += 0.0771) {
    long double a = s21_asin(k);
    long double b = asin(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(asin_test_3) { ck_assert_double_nan(s21_asin(s21_NAN)); }
END_TEST

START_TEST(asin_test_4) { ck_assert_double_nan(s21_asin(INFINITY)); }
END_TEST

START_TEST(asin_test_5) { ck_assert_double_nan(s21_asin(-INFINITY)); }
END_TEST

START_TEST(asin_test_6) { ck_assert_double_nan(s21_asin(5)); }
END_TEST

START_TEST(asin_test_7) { ck_assert_double_nan(s21_asin(-8)); }
END_TEST

START_TEST(asin_test_8) {
  ck_assert_ldouble_eq_tol(s21_asin(1.0), asin(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1.0), asin(-1.0), 1e-6);
}
END_TEST

START_TEST(asin_test_9) {
  ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.0), asin(-0.0), 1e-6);
}
END_TEST

START_TEST(asin_test_10) {
  ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), 1e-6);
}
END_TEST

START_TEST(asin_test_11) {
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
}
END_TEST

START_TEST(asin_test_12) {
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
}
END_TEST

START_TEST(asin_test_13) {
  ck_assert_ldouble_eq_tol(s21_asin(-sqrt(3) / 2), asin(-sqrt(3) / 2), 1e-6);
}
END_TEST

START_TEST(asin_test_14) {
  ck_assert_ldouble_eq_tol(s21_asin(-1 / 2), asin(-1 / 2), 1e-6);
}
END_TEST

START_TEST(asin_test_15) {
  ck_assert_ldouble_eq_tol(s21_asin(1 / 2), asin(1 / 2), 1e-6);
}
END_TEST

START_TEST(asin_test_16) {
  ck_assert_ldouble_eq_tol(s21_asin(sqrt(3) / 2), asin(sqrt(3) / 2), 1e-6);
}
END_TEST

START_TEST(acos_test_1) {
  for (float k = -1; k <= 1; k += 0.1) {
    double a = s21_acos(k);
    double b = acos(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(acos_test_2) {
  for (float k = -1; k <= 1; k += 0.0305) {
    double a = s21_acos(k);
    double b = acos(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(acos_test_3) { ck_assert_double_nan(s21_acos(s21_NAN)); }
END_TEST

START_TEST(acos_test_4) { ck_assert_double_nan(s21_acos(INFINITY)); }
END_TEST

START_TEST(acos_test_5) { ck_assert_double_nan(s21_acos(-INFINITY)); }
END_TEST

START_TEST(acos_test_6) { ck_assert_double_nan(s21_acos(6)); }
END_TEST

START_TEST(acos_test_7) { ck_assert_double_nan(s21_acos(-4)); }
END_TEST

START_TEST(acos_test_8) {
  ck_assert_ldouble_eq_tol(s21_acos(1.0), acos(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-1.0), acos(-1.0), 1e-6);
}
END_TEST

START_TEST(acos_test_9) {
  ck_assert_ldouble_eq_tol(s21_acos(0.0), acos(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0.0), acos(-0.0), 1e-6);
}
END_TEST

START_TEST(acos_test_10) {
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-6);
}
END_TEST

START_TEST(acos_test_11) {
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);
}
END_TEST

START_TEST(acos_test_12) {
  ck_assert_ldouble_eq_tol(s21_acos(-s21_sqrt(3) / 2), acos(-s21_sqrt(3) / 2),
                           1e-6);
}
END_TEST

START_TEST(acos_test_13) {
  ck_assert_ldouble_eq_tol(s21_acos(-s21_sqrt(2) / 2), acos(-s21_sqrt(2) / 2),
                           1e-6);
}
END_TEST

START_TEST(acos_test_14) {
  ck_assert_ldouble_eq_tol(s21_acos(-1 / 2), acos(-1 / 2), 1e-6);
}
END_TEST

START_TEST(acos_test_15) {
  ck_assert_ldouble_eq_tol(s21_acos(1 / 2), acos(1 / 2), 1e-6);
}
END_TEST

START_TEST(acos_test_16) {
  ck_assert_ldouble_eq_tol(s21_acos(2 / 2), acos(2 / 2), 1e-6);
}
END_TEST

START_TEST(exp_0) {
  double x = 0;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_1) {
  double x = 1;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_2) {
  double x = 2;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_3) {
  double x = 3;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_4) {
  double x = 1.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_5) {
  double x = -1.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_6) {
  double x = 0.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_7) {
  double x = -0.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_8) {
  double x = 715;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_9) {
  double x = -715;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_10) {
  double x = -0;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_11) {
  double x = 'A';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_12) {
  double x = -'N';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_13) {
  double x = -'V';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_14) {
  double x = +'B';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_15) {
  double x = 0 / 1;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_16) {
  double x = 0 / 1;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_17) { ck_assert_float_eq(s21_exp(2), exp(2)); }
END_TEST

START_TEST(exp_18) { ck_assert_float_eq(s21_exp(-750), exp(-750)); }
END_TEST

START_TEST(exp_19) { ck_assert_float_eq(s21_exp(-2), exp(-2)); }
END_TEST

START_TEST(exp_20) {
  double num = NAN;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(exp_21) {
  double num = INFINITY;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if (isinf(orig_res) && isinf(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(exp_22) {
  double num = -INFINITY;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(exp_23) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_24) {
  ck_assert_ldouble_eq_tol(s21_exp(-INFINITY), expl(-INFINITY), 1e-06);
}
END_TEST

START_TEST(exp_25) {
  ck_assert_ldouble_infinite(s21_exp(INFINITY));
  ck_assert_ldouble_infinite(expl(INFINITY));
}
END_TEST

START_TEST(exp_26) {
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_nan(expl(NAN));
}
END_TEST

START_TEST(exp_27) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_28) {
  double x = -1.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_29) {
  double x = -100;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_30) {
  double x = -1000000;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_31) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_32) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_33) {
  double num = 1000000;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if (isinf(orig_res) && isinf(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(exp_34) {
  for (double k = -21; k < 21; k += 1) {
    double a = s21_exp(k);
    double b = exp(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(exp_35) {
  for (double k = -15; k < 15; k += 0.123) {
    double a = s21_exp(k);
    double b = exp(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(exp_36) {
  for (double k = -5; k < 5; k += 0.00573) {
    double a = s21_exp(k);
    double b = exp(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_1) {
  double num = 456.789;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_2) {
  double num = NAN;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_3) {
  double num = 0.001;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_4) {
  double num = 0.4;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_5) {
  double num = -INFINITY;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_6) {
  double num = INFINITY;
  long double orig_res = log(num);
  long double our_res = s21_log(num);
  int suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_7) {
  ck_assert_ldouble_infinite(s21_log(INFINITY));
  ck_assert_ldouble_infinite(log(INFINITY));

  ck_assert_ldouble_nan(s21_log(-INFINITY));
  ck_assert_ldouble_nan(log(-INFINITY));
}
END_TEST

START_TEST(log_8) {
  ck_assert_ldouble_nan(s21_log(NAN));
  ck_assert_ldouble_nan(log(NAN));
}
END_TEST

START_TEST(log_9) {
  ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), 1e-6);
}
END_TEST

START_TEST(log_10) { ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6); }
END_TEST

START_TEST(log_11) { ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-6); }
END_TEST

START_TEST(log_12) { ck_assert_ldouble_eq_tol(s21_log(100), log(100), 1e-6); }
END_TEST

START_TEST(log_13) { ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6); }
END_TEST

START_TEST(log_14) { ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6); }
END_TEST

START_TEST(log_16) {
  ck_assert_ldouble_eq_tol(s21_log(s21_PI / 3), log(s21_PI / 3), 1e-6);
}
END_TEST

START_TEST(log_17) {
  ck_assert_ldouble_eq_tol(s21_log(9.234578353457e-6), log(9.234578353457e-6),
                           1e-6);
}
END_TEST

START_TEST(log_18) {
  ck_assert_ldouble_eq_tol(s21_log(9.234578353457e6), log(9.234578353457e6),
                           1e-6);
}
END_TEST

START_TEST(log_19) {
  ck_assert_ldouble_eq_tol(s21_log(1234567.000000004), log(1234567.000000004),
                           1e-6);
}
END_TEST

START_TEST(log_20) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-16), log(1.1e-16), 1e-6);
}
END_TEST

START_TEST(log_24) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-45), log(1.1e-45), 1e-6);
}
END_TEST

START_TEST(log_25) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-18), log(1.1e-18), 1e-6);
}
END_TEST

START_TEST(log_26) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-19), log(1.1e-19), 1e-6);
}
END_TEST

START_TEST(log_27) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-23), log(1.1e-23), 1e-6);
}
END_TEST

START_TEST(log_21) {
  ck_assert_ldouble_eq_tol(s21_log(987654321123.123e-30),
                           log(987654321123.123e-30), 1e-6);
}
END_TEST

START_TEST(log_22) {
  ck_assert_ldouble_eq_tol(s21_log(98765.123e-11), log(98765.123e-11), 1e-6);
}
END_TEST

START_TEST(log_23) { ck_assert_ldouble_infinite(s21_log(0)); }
END_TEST

START_TEST(log_28) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-17), log(1.1e-17), 1e-6);
}
END_TEST

START_TEST(log_29) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-15), log(1.1e-15), 1e-6);
}
END_TEST

START_TEST(log_30) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-14), log(1.1e-14), 1e-6);
}
END_TEST

START_TEST(log_31) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-13), log(1.1e-13), 1e-6);
}
END_TEST

START_TEST(log_32) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-12), log(1.1e-12), 1e-6);
}
END_TEST

START_TEST(log_33) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-11), log(1.1e-11), 1e-6);
}
END_TEST

START_TEST(log_34) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-80), log(1.1e-80), 1e-6);
}
END_TEST

START_TEST(log_35) {
  for (double k = 1; k < 100; k += 13.2) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_36) {
  for (double k = 0.1; k < 4; k += 0.24) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_37) {
  for (double k = 0.1; k < 10000; k += 123) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_38) {
  for (double k = 0.000005; k < 1; k *= 5) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(pow_1) {
  double num = 456.789;
  double ex = 1.1;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  ck_assert_float_eq(our_res, orig_res);
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_2) {
  double num = INFINITY;
  double ex = 1.1;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_3) {
  double num = NAN;
  double ex = 1.1;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_4) {
  double num = NAN;
  double ex = NAN;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_5) {
  double num = 0.001;
  double ex = NAN;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (isnan(our_res) && isnan(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_6) {
  double num = INFINITY;
  double ex = INFINITY;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_7) {
  double num = INFINITY;
  double ex = INFINITY;
  long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
  int suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_8) {
  long double base = -16.161435;
  long double exp = 9.;
  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_9) {
  long double base = -10.1261;
  long double exp = -0.72;
  ck_assert_double_nan(s21_pow(base, exp));
  ck_assert_double_nan(pow(base, exp));
}
END_TEST

START_TEST(pow_10) {
  long double base = +0;
  long double exp = -0.33;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_12) {
  long double base = -0;
  long double exp = -0.33;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_13) {
  long double base = -0;
  long double exp = s21_INFINITY;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_14) {
  long double base = +0;
  long double exp = 123;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_15) {
  long double base = -0;
  long double exp = 123;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_16) {
  long double base = -0;
  long double exp = s21_INFINITY;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_17) {
  long double base = -1;
  long double exp = s21_INFINITY;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_18) {
  long double base = -1;
  long double exp = s21_NAN;
  ck_assert_double_nan(pow(base, exp));
  ck_assert_double_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_19) {
  long double base = s21_NAN;
  long double exp = 0;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_20) {
  long double base = -123;
  long double exp = s21_NAN;
  ck_assert_double_nan(s21_pow(base, exp));
  ck_assert_double_nan(pow(base, exp));
}
END_TEST

START_TEST(pow_21) {
  long double base = 0.5591951;
  long double exp = -s21_INFINITY;
  ck_assert_ldouble_infinite(pow(base, exp));
  ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_22) {
  long double base = 1.5591951;
  long double exp = -s21_INFINITY;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_23) {
  long double base = 0.5591951;
  long double exp = s21_INFINITY;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_24) {
  long double base = 1.5591951;
  long double exp = s21_INFINITY;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_25) {
  long double base = -s21_INFINITY;
  long double exp = -193491;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_26) {
  long double base = -s21_INFINITY;
  long double exp = -142;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_27) {
  long double base = -s21_INFINITY;
  long double exp = 141;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_28) {
  long double base = -s21_INFINITY;
  long double exp = 142;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_29) {
  long double base = s21_INFINITY;
  long double exp = -1;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_30) {
  long double base = s21_INFINITY;
  long double exp = 1;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_31) {
  ck_assert_ldouble_eq_tol(s21_pow(0.0, 0.0), pow(0.0, 0.0), 1e-6);
}
END_TEST

START_TEST(pow_32) {
  ck_assert_ldouble_eq_tol(s21_pow(-1, 4), pow(-1, 4), 1e-6);
}
END_TEST

START_TEST(pow_33) {
  ck_assert_ldouble_eq_tol(s21_pow(2, 18), pow(2, 18), 1e-6);
}
END_TEST

START_TEST(pow_34) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1, 11), pow(2.1, 11), 1e-6);
}
END_TEST

START_TEST(pow_35) {
  ck_assert_ldouble_eq_tol(s21_pow(1.23456e-7, 2.21), pow(1.23456e-7, 2.21),
                           1e-6);
}
END_TEST

START_TEST(pow_36) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1234567, -2), pow(2.1234567, -2), 1e-6);
}
END_TEST

START_TEST(pow_37) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1234567, -2), pow(2.1234567, -2), 1e-6);
}
END_TEST

START_TEST(pow_38) {
  long double orig_res = pow(2.1234567e-7, -2.45e4),
              our_res = s21_pow(2.1234567e-7, -2.45e4);
  int suc = 0;
  if (isinf(our_res) && isinf(orig_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(pow_39) {
  ck_assert_ldouble_eq_tol(s21_pow(9.99999999e3, 9.95e-4),
                           pow(9.99999999e3, 9.95e-4), 1e-6);
}
END_TEST

START_TEST(pow_40) {
  long double exp = -12;
  ck_assert_ldouble_infinite(s21_pow(+0, exp));
  ck_assert_ldouble_infinite(pow(+0, exp));
}
END_TEST

START_TEST(pow_41) {
  long double exp = -12;
  ck_assert_ldouble_infinite(s21_pow(-0, exp));
  ck_assert_ldouble_infinite(pow(-0, exp));
}
END_TEST

START_TEST(pow_42) {
  long double exp = 0;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
}
END_TEST

START_TEST(pow_43) {
  long double exp = s21_NAN;
  ck_assert_double_nan(s21_pow(+0, exp));
  ck_assert_double_nan(pow(+0, exp));
}
END_TEST

START_TEST(pow_44) {
  long double exp = 2.456;
  ck_assert_ldouble_eq_tol(s21_pow(+0, exp), pow(+0, exp), 1e-6);
}
END_TEST

START_TEST(pow_45) {
  long double exp = -s21_INFINITY;
  ck_assert_ldouble_infinite(s21_pow(+0, exp));
  ck_assert_ldouble_infinite(pow(+0, exp));
}
END_TEST

START_TEST(pow_46) {
  long double exp = 56;
  ck_assert_ldouble_eq_tol(s21_pow(+0, exp), pow(+0, exp), 1e-6);
}
END_TEST

START_TEST(pow_47) {
  long double exp = 56;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
}
END_TEST

START_TEST(pow_48) {
  long double exp = 56.345;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
}
END_TEST

START_TEST(pow_49) {
  long double exp = s21_INFINITY;
  ck_assert_ldouble_eq_tol(s21_pow(-1, exp), pow(-1, exp), 1e-6);
}
END_TEST

START_TEST(pow_50) {
  long double exp = -s21_INFINITY;
  ck_assert_ldouble_eq_tol(s21_pow(-1, exp), pow(-1, exp), 1e-6);
}
END_TEST

START_TEST(pow_51) {
  long double exp = s21_NAN;
  ck_assert_ldouble_eq_tol(s21_pow(+1, exp), pow(+1, exp), 1e-6);
}
END_TEST

START_TEST(pow_52) {
  long double exp = -0;
  ck_assert_ldouble_eq_tol(s21_pow(4567, exp), pow(4567, exp), 1e-6);
}
END_TEST

START_TEST(pow_53) {
  long double exp = +0;
  ck_assert_ldouble_eq_tol(s21_pow(34567, exp), pow(34567, exp), 1e-6);
}
END_TEST

START_TEST(pow_54) {
  long double exp = -0;
  ck_assert_ldouble_eq_tol(s21_pow(s21_NAN, exp), pow(s21_NAN, exp), 1e-6);
}
END_TEST

START_TEST(pow_55) {
  long double exp = +0;
  ck_assert_ldouble_eq_tol(s21_pow(s21_NAN, exp), pow(s21_NAN, exp), 1e-6);
}
END_TEST

START_TEST(pow_56) {
  long double exp = s21_NAN;
  ck_assert_double_nan(s21_pow(s21_NAN, exp));
  ck_assert_double_nan(pow(s21_NAN, exp));
}
END_TEST

START_TEST(pow_57) {
  long double exp = s21_INFINITY;
  ck_assert_ldouble_infinite(s21_pow(s21_INFINITY, exp));
  ck_assert_ldouble_infinite(pow(s21_INFINITY, exp));
}
END_TEST

START_TEST(pow_58) {
  long double exp = -s21_INFINITY;
  ck_assert_ldouble_eq_tol(s21_pow(-s21_INFINITY, exp), pow(-s21_INFINITY, exp),
                           1e-6);
}
END_TEST

START_TEST(pow_59) {
  double exp = s21_INFINITY;
  ck_assert_ldouble_infinite(s21_pow(-s21_INFINITY, exp));
  ck_assert_ldouble_infinite(pow(-s21_INFINITY, exp));
}
END_TEST

START_TEST(pow_60) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp > -1000; exp -= 0.1) {
    res1 = pow(s21_INFINITY, exp);
    res2 = s21_pow(s21_INFINITY, exp);
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_61) {
  double base;
  double res1;
  long double res2;

  for (base = 0.0; base < 10; base += 0.1) {
    res1 = pow(base, s21_INFINITY);
    res2 = s21_pow(base, s21_INFINITY);
  }
  ck_assert_ldouble_infinite(res1);
  ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(pow_62) {
  double base;
  double res1;
  long double res2;

  for (base = 0.0; base > -10; base -= 0.1) {
    res1 = pow(base, s21_INFINITY);
    res2 = s21_pow(base, s21_INFINITY);
  }
  ck_assert_ldouble_infinite(res1);
  ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(pow_63) {
  long double base;
  long double res1;
  long double res2;

  for (base = 0.0; base < 10; base += 0.1) {
    res1 = pow(base, -s21_INFINITY);
    res2 = s21_pow(base, -s21_INFINITY);
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_64) {
  long double base;
  long double res1;
  long double res2;

  for (base = 0.0; base > -10; base -= 0.1) {
    res1 = pow(base, -s21_INFINITY);
    res2 = s21_pow(base, -s21_INFINITY);
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_65) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp > -10; exp -= 0.1) {
    if (fmod(exp, 2) != 0) {
      res1 = pow(-s21_INFINITY, exp);
      res2 = s21_pow(-s21_INFINITY, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_66) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp > -10; exp -= 0.1) {
    if (fmod(exp, 2) == 0) {
      res1 = pow(-s21_INFINITY, exp);
      res2 = s21_pow(-s21_INFINITY, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_67) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp < 10; exp += 0.1) {
    if (fmod(exp, 2) != 0) {
      res1 = pow(-s21_INFINITY, exp);
      res2 = s21_pow(-s21_INFINITY, exp);
    }
  }
  ck_assert_ldouble_infinite(res1);
  ck_assert_ldouble_infinite(res2);
}
END_TEST

START_TEST(pow_68) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp < 10; exp += 0.1) {
    if (fmod(exp, 2) == 0) {
      res1 = pow(-s21_INFINITY, exp);
      res2 = s21_pow(-s21_INFINITY, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res2, res1, 1e-6);
}
END_TEST

START_TEST(pow_69) {
  long double exp = 3;
  ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), 1e-6);
}
END_TEST

START_TEST(pow_70) {
  long double exp = -3;
  ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), 1e-6);
}
END_TEST

START_TEST(pow_71) {
  long double exp = -3;
  ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), 1e-6);
}
END_TEST

START_TEST(pow_72) {
  long double exp = 3;
  ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), 1e-6);
}
END_TEST

START_TEST(pow_73) {
  long double base = -0;
  long double exp = s21_INFINITY;
  long double res = pow(base, exp);
  long double res1 = s21_pow(base, exp);
  ck_assert_ldouble_eq_tol(res, res1, 1e-6);
}
END_TEST

START_TEST(pow_74) {
  long double exp;
  long double base = -0;
  long double res;
  long double res1;
  for (exp = 0.0; exp < 10; exp += 0.1) {
    if (fmod(exp, 2) != 0) {
      res = pow(base, exp);
      res1 = s21_pow(base, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res, res1, 1e-6);
}
END_TEST

START_TEST(pow_75) {
  for (double k = -9; k <= 9; k += 1.7) {
    for (double g = -5; g < 5; g += 1) {
      long double a = s21_pow(k, g);
      long double b = pow(k, g);
      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, 1e-6);
      }
      a = s21_pow(g, k);
      b = pow(g, k);
      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, 1e-6);
      }
    }
  }
}
END_TEST

START_TEST(pow_76) {
  ck_assert_ldouble_eq(s21_pow(-0.0 / 1.0, 3), pow(-0.0, 3));
}
END_TEST
START_TEST(pow_77) {
  ck_assert_ldouble_eq(s21_pow(-0.0 / 1.0, -3), pow(-0.0, -3));
}
END_TEST

START_TEST(pow_78) {
  ck_assert_double_eq(pow(1, 0), s21_pow(1, 0));
  ck_assert_double_eq(pow(-1, 3), s21_pow(-1, 3));
  ck_assert_double_eq(pow(-1, 4), s21_pow(-1, 4));
  ck_assert_double_eq(pow(0, 0), s21_pow(0, 0));
  ck_assert_double_eq(pow(0, -1), s21_pow(0, -1));
  ck_assert_double_eq(pow(0, 1), s21_pow(0, 1));
  ck_assert_double_eq(pow(INFINITY, 0), s21_pow(INFINITY, 0));
  ck_assert_double_eq(pow(INFINITY, -1), s21_pow(INFINITY, -1));
  ck_assert_double_eq(pow(-1, -INFINITY), s21_pow(-1, -INFINITY));
  ck_assert_double_eq(pow(0, INFINITY), s21_pow(0, INFINITY));
  ck_assert_double_nan(s21_pow(0, s21_NAN));
  ck_assert_double_eq(pow(NAN, 0), s21_pow(s21_NAN, 0));
  ck_assert_double_nan(s21_pow(s21_NAN, s21_NAN));
  ck_assert_double_eq(pow(INFINITY, INFINITY), s21_pow(INFINITY, INFINITY));
  ck_assert_double_eq(pow(INFINITY, -INFINITY), s21_pow(INFINITY, -INFINITY));
  ck_assert_double_eq(pow(-INFINITY, INFINITY), s21_pow(-INFINITY, INFINITY));
  ck_assert_double_eq(pow(-INFINITY, -INFINITY), s21_pow(-INFINITY, -INFINITY));
  ck_assert_double_eq(pow(1, -INFINITY), s21_pow(1, -INFINITY));
  ck_assert_double_eq(pow(1, NAN), s21_pow(1, s21_NAN));
  ck_assert_double_nan(s21_pow(s21_NAN, INFINITY));
  ck_assert_double_nan(s21_pow(INFINITY, s21_NAN));
  ck_assert_double_nan(s21_pow(s21_NAN, -INFINITY));
  ck_assert_double_nan(s21_pow(-INFINITY, s21_NAN));
  ck_assert_double_eq(pow(2, INFINITY), s21_pow(2, INFINITY));
  ck_assert_double_eq(pow(0.5, INFINITY), s21_pow(0.5, INFINITY));
  ck_assert_double_eq(pow(-2, INFINITY), s21_pow(-2, INFINITY));
  ck_assert_double_eq(pow(2, -INFINITY), s21_pow(2, -INFINITY));
  ck_assert_double_eq(pow(0.5, -INFINITY), s21_pow(0.5, -INFINITY));
  ck_assert_double_eq(pow(-2, -INFINITY), s21_pow(-2, -INFINITY));
}
END_TEST

Suite *test_log(void) {
  Suite *s = suite_create("\033[45m-=s21_log=-\033[0m");
  TCase *tc11 = tcase_create("log_tc");
  suite_add_tcase(s, tc11);
  tcase_add_test(tc11, log_1);
  tcase_add_test(tc11, log_2);
  tcase_add_test(tc11, log_3);
  tcase_add_test(tc11, log_4);
  tcase_add_test(tc11, log_5);
  tcase_add_test(tc11, log_6);
  tcase_add_test(tc11, log_7);
  tcase_add_test(tc11, log_8);
  tcase_add_test(tc11, log_9);
  tcase_add_test(tc11, log_10);
  tcase_add_test(tc11, log_11);
  tcase_add_test(tc11, log_12);
  tcase_add_test(tc11, log_13);
  tcase_add_test(tc11, log_14);
  tcase_add_test(tc11, log_16);
  tcase_add_test(tc11, log_17);
  tcase_add_test(tc11, log_18);
  tcase_add_test(tc11, log_19);
  tcase_add_test(tc11, log_20);
  tcase_add_test(tc11, log_21);
  tcase_add_test(tc11, log_22);
  tcase_add_test(tc11, log_23);
  tcase_add_test(tc11, log_24);
  tcase_add_test(tc11, log_25);
  tcase_add_test(tc11, log_26);
  tcase_add_test(tc11, log_27);
  tcase_add_test(tc11, log_28);
  tcase_add_test(tc11, log_29);
  tcase_add_test(tc11, log_30);
  tcase_add_test(tc11, log_31);
  tcase_add_test(tc11, log_32);
  tcase_add_test(tc11, log_33);
  tcase_add_test(tc11, log_34);
  tcase_add_test(tc11, log_35);
  tcase_add_test(tc11, log_36);
  tcase_add_test(tc11, log_37);
  tcase_add_test(tc11, log_38);
  suite_add_tcase(s, tc11);
  return s;
}

Suite *test_pow(void) {
  Suite *s = suite_create("\033[45m-=s21_pow=-\033[0m");
  TCase *tc12 = tcase_create("pow_tc");
  suite_add_tcase(s, tc12);
  tcase_add_test(tc12, pow_1);
  tcase_add_test(tc12, pow_2);
  tcase_add_test(tc12, pow_3);
  tcase_add_test(tc12, pow_4);
  tcase_add_test(tc12, pow_5);
  tcase_add_test(tc12, pow_6);
  tcase_add_test(tc12, pow_7);
  tcase_add_test(tc12, pow_8);
  tcase_add_test(tc12, pow_9);
  tcase_add_test(tc12, pow_10);
  tcase_add_test(tc12, pow_12);
  tcase_add_test(tc12, pow_13);
  tcase_add_test(tc12, pow_14);
  tcase_add_test(tc12, pow_15);
  tcase_add_test(tc12, pow_16);
  tcase_add_test(tc12, pow_17);
  tcase_add_test(tc12, pow_18);
  tcase_add_test(tc12, pow_19);
  tcase_add_test(tc12, pow_20);
  tcase_add_test(tc12, pow_21);
  tcase_add_test(tc12, pow_22);
  tcase_add_test(tc12, pow_23);
  tcase_add_test(tc12, pow_24);
  tcase_add_test(tc12, pow_25);
  tcase_add_test(tc12, pow_26);
  tcase_add_test(tc12, pow_27);
  tcase_add_test(tc12, pow_28);
  tcase_add_test(tc12, pow_29);
  tcase_add_test(tc12, pow_30);
  tcase_add_test(tc12, pow_31);
  tcase_add_test(tc12, pow_32);
  tcase_add_test(tc12, pow_33);
  tcase_add_test(tc12, pow_34);
  tcase_add_test(tc12, pow_35);
  tcase_add_test(tc12, pow_36);
  tcase_add_test(tc12, pow_37);
  tcase_add_test(tc12, pow_38);
  tcase_add_test(tc12, pow_39);
  tcase_add_test(tc12, pow_40);
  tcase_add_test(tc12, pow_41);
  tcase_add_test(tc12, pow_42);
  tcase_add_test(tc12, pow_43);
  tcase_add_test(tc12, pow_44);
  tcase_add_test(tc12, pow_45);
  tcase_add_test(tc12, pow_46);
  tcase_add_test(tc12, pow_47);
  tcase_add_test(tc12, pow_48);
  tcase_add_test(tc12, pow_49);
  tcase_add_test(tc12, pow_50);
  tcase_add_test(tc12, pow_51);
  tcase_add_test(tc12, pow_52);
  tcase_add_test(tc12, pow_53);
  tcase_add_test(tc12, pow_54);
  tcase_add_test(tc12, pow_55);
  tcase_add_test(tc12, pow_56);
  tcase_add_test(tc12, pow_57);
  tcase_add_test(tc12, pow_58);
  tcase_add_test(tc12, pow_59);
  tcase_add_test(tc12, pow_60);
  tcase_add_test(tc12, pow_61);
  tcase_add_test(tc12, pow_62);
  tcase_add_test(tc12, pow_63);
  tcase_add_test(tc12, pow_64);
  tcase_add_test(tc12, pow_65);
  tcase_add_test(tc12, pow_66);
  tcase_add_test(tc12, pow_67);
  tcase_add_test(tc12, pow_68);
  tcase_add_test(tc12, pow_69);
  tcase_add_test(tc12, pow_70);
  tcase_add_test(tc12, pow_71);
  tcase_add_test(tc12, pow_72);
  tcase_add_test(tc12, pow_73);
  tcase_add_test(tc12, pow_74);
  tcase_add_test(tc12, pow_75);
  tcase_add_test(tc12, pow_76);
  tcase_add_test(tc12, pow_77);
  tcase_add_test(tc12, pow_78);
  suite_add_tcase(s, tc12);
  return s;
}

Suite *test_exp(void) {
  Suite *s = suite_create("\033[45m-=s21_exp=-\033[0m");
  TCase *tc7 = tcase_create("exp_tc");
  suite_add_tcase(s, tc7);
  tcase_add_test(tc7, exp_0);
  tcase_add_test(tc7, exp_1);
  tcase_add_test(tc7, exp_2);
  tcase_add_test(tc7, exp_3);
  tcase_add_test(tc7, exp_4);
  tcase_add_test(tc7, exp_5);
  tcase_add_test(tc7, exp_6);
  tcase_add_test(tc7, exp_7);
  tcase_add_test(tc7, exp_8);
  tcase_add_test(tc7, exp_9);
  tcase_add_test(tc7, exp_10);
  tcase_add_test(tc7, exp_11);
  tcase_add_test(tc7, exp_12);
  tcase_add_test(tc7, exp_13);
  tcase_add_test(tc7, exp_14);
  tcase_add_test(tc7, exp_15);
  tcase_add_test(tc7, exp_16);
  tcase_add_test(tc7, exp_17);
  tcase_add_test(tc7, exp_18);
  tcase_add_test(tc7, exp_19);
  tcase_add_test(tc7, exp_20);
  tcase_add_test(tc7, exp_21);
  tcase_add_test(tc7, exp_22);
  tcase_add_test(tc7, exp_23);
  tcase_add_test(tc7, exp_24);
  tcase_add_test(tc7, exp_25);
  tcase_add_test(tc7, exp_26);
  tcase_add_test(tc7, exp_27);
  tcase_add_test(tc7, exp_28);
  tcase_add_test(tc7, exp_29);
  tcase_add_test(tc7, exp_30);
  tcase_add_test(tc7, exp_31);
  tcase_add_test(tc7, exp_32);
  tcase_add_test(tc7, exp_33);
  tcase_add_test(tc7, exp_34);
  tcase_add_test(tc7, exp_35);
  tcase_add_test(tc7, exp_36);
  suite_add_tcase(s, tc7);
  return s;
}

Suite *test_acos(void) {
  Suite *s = suite_create("\033[45m-=s21_acos=-\033[0m");
  TCase *tc = tcase_create("acos_tc");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, acos_test_1);
  tcase_add_test(tc, acos_test_2);
  tcase_add_test(tc, acos_test_3);
  tcase_add_test(tc, acos_test_4);
  tcase_add_test(tc, acos_test_5);
  tcase_add_test(tc, acos_test_6);
  tcase_add_test(tc, acos_test_7);
  tcase_add_test(tc, acos_test_8);
  tcase_add_test(tc, acos_test_9);
  tcase_add_test(tc, acos_test_10);
  tcase_add_test(tc, acos_test_11);
  tcase_add_test(tc, acos_test_12);
  tcase_add_test(tc, acos_test_13);
  tcase_add_test(tc, acos_test_14);
  tcase_add_test(tc, acos_test_15);
  tcase_add_test(tc, acos_test_16);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_asin(void) {
  Suite *s = suite_create("\033[45m-=s21_asin=-\033[0m");
  TCase *tc3 = tcase_create("asin_tc");
  suite_add_tcase(s, tc3);
  tcase_add_test(tc3, asin_test_1);
  tcase_add_test(tc3, asin_test_2);
  tcase_add_test(tc3, asin_test_3);
  tcase_add_test(tc3, asin_test_4);
  tcase_add_test(tc3, asin_test_5);
  tcase_add_test(tc3, asin_test_6);
  tcase_add_test(tc3, asin_test_7);
  tcase_add_test(tc3, asin_test_8);
  tcase_add_test(tc3, asin_test_9);
  tcase_add_test(tc3, asin_test_10);
  tcase_add_test(tc3, asin_test_11);
  tcase_add_test(tc3, asin_test_12);
  tcase_add_test(tc3, asin_test_13);
  tcase_add_test(tc3, asin_test_14);
  tcase_add_test(tc3, asin_test_15);
  tcase_add_test(tc3, asin_test_16);
  suite_add_tcase(s, tc3);
  return s;
}

Suite *test_sqrt(void) {
  Suite *s = suite_create("\033[45m-=s21_sqrt=-\033[0m");
  TCase *tc14 = tcase_create("sqrt_tc");
  suite_add_tcase(s, tc14);
  tcase_add_test(tc14, sqrt_1);
  tcase_add_test(tc14, sqrt_2);
  tcase_add_test(tc14, sqrt_3);
  tcase_add_test(tc14, sqrt_4);
  tcase_add_test(tc14, sqrt_5);
  tcase_add_test(tc14, sqrt_6);
  tcase_add_test(tc14, sqrt_7);
  tcase_add_test(tc14, sqrt_8);
  tcase_add_test(tc14, sqrt_9);
  tcase_add_test(tc14, sqrt_10);
  tcase_add_test(tc14, sqrt_11);
  tcase_add_test(tc14, sqrt_12);
  tcase_add_test(tc14, sqrt_13);
  tcase_add_test(tc14, sqrt_14);
  tcase_add_test(tc14, sqrt_15);
  tcase_add_test(tc14, sqrt_16);
  suite_add_tcase(s, tc14);
  return s;
}

Suite *test_atan(void) {
  Suite *s = suite_create("\033[45m-=s21_atan=-\033[0m");
  TCase *tc4 = tcase_create("atan_tc");
  suite_add_tcase(s, tc4);
  tcase_add_test(tc4, atan_1);
  tcase_add_test(tc4, atan_2);
  tcase_add_test(tc4, atan_3);
  tcase_add_test(tc4, atan_4);
  tcase_add_test(tc4, atan_5);
  tcase_add_test(tc4, atan_6);
  tcase_add_test(tc4, atan_7);
  tcase_add_test(tc4, atan_8);
  tcase_add_test(tc4, atan_9);
  tcase_add_test(tc4, atan_10);
  tcase_add_test(tc4, atan_11);
  tcase_add_test(tc4, atan_12);
  tcase_add_test(tc4, atan_13);
  tcase_add_test(tc4, atan_14);
  tcase_add_test(tc4, atan_15);
  tcase_add_test(tc4, atan_16);
  tcase_add_test(tc4, atan_17);
  tcase_add_test(tc4, atan_18);
  tcase_add_test(tc4, atan_19);
  tcase_add_test(tc4, atan_20);
  tcase_add_test(tc4, atan_21);
  tcase_add_test(tc4, atan_22);
  tcase_add_test(tc4, atan_23);
  tcase_add_test(tc4, atan_24);
  tcase_add_test(tc4, atan_25);
  suite_add_tcase(s, tc4);
  return s;
}

Suite *test_sin(void) {
  Suite *s = suite_create("\033[45m-=s21_sin=-\033[0m");
  TCase *tc13 = tcase_create("sin_tc");
  suite_add_tcase(s, tc13);
  tcase_add_test(tc13, sin_1);
  tcase_add_test(tc13, sin_2);
  tcase_add_test(tc13, sin_3);
  tcase_add_test(tc13, sin_4);
  tcase_add_test(tc13, sin_5);
  tcase_add_test(tc13, sin_6);
  tcase_add_test(tc13, sin_7);
  tcase_add_test(tc13, sin_8);
  tcase_add_test(tc13, sin_9);
  tcase_add_test(tc13, sin_10);
  tcase_add_test(tc13, sin_11);
  tcase_add_test(tc13, sin_12);
  tcase_add_test(tc13, sin_13);
  tcase_add_test(tc13, sin_14);
  tcase_add_test(tc13, sin_15);
  tcase_add_test(tc13, sin_16);
  tcase_add_test(tc13, sin_17);
  tcase_add_test(tc13, sin_18);
  tcase_add_test(tc13, sin_19);
  tcase_add_test(tc13, sin_20);
  tcase_add_test(tc13, sin_21);
  tcase_add_test(tc13, sin_22);
  tcase_add_test(tc13, sin_23);
  tcase_add_test(tc13, sin_24);
  tcase_add_test(tc13, sin_25);
  tcase_add_test(tc13, sin_26);
  suite_add_tcase(s, tc13);
  return s;
}

Suite *test_cos(void) {
  Suite *s = suite_create("\033[45m-=s21_cos=-\033[0m");
  TCase *tc6 = tcase_create("cos_tc");
  suite_add_tcase(s, tc6);
  tcase_add_test(tc6, cos_1);
  tcase_add_test(tc6, cos_2);
  tcase_add_test(tc6, cos_3);
  tcase_add_test(tc6, cos_4);
  tcase_add_test(tc6, cos_5);
  tcase_add_test(tc6, cos_6);
  tcase_add_test(tc6, cos_7);
  tcase_add_test(tc6, cos_8);
  tcase_add_test(tc6, cos_9);
  tcase_add_test(tc6, cos_10);
  tcase_add_test(tc6, cos_11);
  tcase_add_test(tc6, cos_12);
  tcase_add_test(tc6, cos_13);
  tcase_add_test(tc6, cos_14);
  tcase_add_test(tc6, cos_15);
  tcase_add_test(tc6, cos_16);
  tcase_add_test(tc6, cos_17);
  tcase_add_test(tc6, cos_18);
  tcase_add_test(tc6, cos_19);
  tcase_add_test(tc6, cos_20);
  tcase_add_test(tc6, cos_21);
  tcase_add_test(tc6, cos_22);
  suite_add_tcase(s, tc6);
  return s;
}

Suite *test_tan(void) {
  Suite *s = suite_create("\033[45m-=s21_tan=-\033[0m");
  TCase *tc15 = tcase_create("tan_tc");
  suite_add_tcase(s, tc15);
  tcase_add_test(tc15, tan_1);
  tcase_add_test(tc15, tan_2);
  tcase_add_test(tc15, tan_4);
  tcase_add_test(tc15, tan_5);
  tcase_add_test(tc15, tan_6);
  tcase_add_test(tc15, tan_7);
  tcase_add_test(tc15, tan_8);
  tcase_add_test(tc15, tan_9);
  tcase_add_test(tc15, tan_10);
  tcase_add_test(tc15, tan_11);
  tcase_add_test(tc15, tan_12);
  tcase_add_test(tc15, tan_13);
  tcase_add_test(tc15, tan_14);
  tcase_add_test(tc15, tan_15);
  tcase_add_test(tc15, tan_16);
  tcase_add_test(tc15, tan_17);
  tcase_add_test(tc15, tan_18);
  tcase_add_test(tc15, tan_19);
  tcase_add_test(tc15, tan_22);
  suite_add_tcase(s, tc15);
  return s;
}

Suite *test_fabs(void) {
  Suite *s = suite_create("\033[45m-=s21_fabs=-\033[0m");
  TCase *tc8 = tcase_create("fabs_tc");
  suite_add_tcase(s, tc8);
  tcase_add_test(tc8, fabs_1);
  tcase_add_test(tc8, fabs_2);
  tcase_add_test(tc8, fabs_3);
  tcase_add_test(tc8, fabs_4);
  tcase_add_test(tc8, fabs_5);
  tcase_add_test(tc8, fabs_6);
  tcase_add_test(tc8, fabs_7);
  tcase_add_test(tc8, fabs_8);
  tcase_add_test(tc8, fabs_10);
  tcase_add_test(tc8, fabs_11);
  tcase_add_test(tc8, fabs_12);
  tcase_add_test(tc8, fabs_13);
  tcase_add_test(tc8, fabs_14);
  suite_add_tcase(s, tc8);

  return s;
}

Suite *test_abs(void) {
  Suite *s = suite_create("\033[45m-=s21_abs=-\033[0m");
  TCase *tc = tcase_create("abs_tc");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, abs_1);
  tcase_add_test(tc, abs_2);
  tcase_add_test(tc, abs_3);
  tcase_add_test(tc, abs_4);
  tcase_add_test(tc, abs_5);
  tcase_add_test(tc, abs_6);
  tcase_add_test(tc, abs_7);
  tcase_add_test(tc, abs_8);
  tcase_add_test(tc, abs_9);
  tcase_add_test(tc, abs_10);
  suite_add_tcase(s, tc);

  return s;
}

Suite *test_ceil(void) {
  Suite *s = suite_create("\033[45m-=s21_ceil=-\033[0m");
  TCase *tc = tcase_create("ceil_tc");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, ceil_test1);
  tcase_add_test(tc, ceil_test2);
  tcase_add_test(tc, ceil_test3);
  tcase_add_test(tc, ceil_test4);
  tcase_add_test(tc, ceil_test5);
  tcase_add_test(tc, ceil_test6);
  tcase_add_test(tc, ceil_test7);
  tcase_add_test(tc, ceil_test8);
  tcase_add_test(tc, ceil_test9);
  tcase_add_test(tc, ceil_test10);
  tcase_add_test(tc, ceil_test11);
  suite_add_tcase(s, tc);
  return s;
}

Suite *test_floor(void) {
  Suite *s = suite_create("\033[45m-=s21_floor=-\033[0m");
  TCase *tc9 = tcase_create("floor_tc");
  suite_add_tcase(s, tc9);
  tcase_add_test(tc9, floor_1);
  tcase_add_test(tc9, floor_2);
  tcase_add_test(tc9, floor_3);
  tcase_add_test(tc9, floor_4);
  tcase_add_test(tc9, floor_5);
  tcase_add_test(tc9, floor_6);
  tcase_add_test(tc9, floor_7);
  tcase_add_test(tc9, floor_8);
  tcase_add_test(tc9, floor_10);
  tcase_add_test(tc9, floor_11);
  tcase_add_test(tc9, floor_12);
  tcase_add_test(tc9, floor_13);
  tcase_add_test(tc9, floor_14);
  tcase_add_test(tc9, floor_15);
  tcase_add_test(tc9, floor_16);
  tcase_add_test(tc9, floor_17);
  tcase_add_test(tc9, floor_18);
  tcase_add_test(tc9, floor_19);
  tcase_add_test(tc9, floor_20);
  tcase_add_test(tc9, floor_21);
  tcase_add_test(tc9, floor_22);
  tcase_add_test(tc9, floor_23);
  suite_add_tcase(s, tc9);
  return s;
}

Suite *test_fmod(void) {
  Suite *s = suite_create("\033[45m-=s21_fmod=-\033[0m");
  TCase *tc10 = tcase_create("fmod_tc");
  suite_add_tcase(s, tc10);
  tcase_add_test(tc10, s21_fmod_test_1);
  tcase_add_test(tc10, s21_fmod_test_2);
  tcase_add_test(tc10, s21_fmod_test_3);
  tcase_add_test(tc10, s21_fmod_test_4);
  tcase_add_test(tc10, s21_fmod_test_5);
  tcase_add_test(tc10, s21_fmod_test_6);
  tcase_add_test(tc10, s21_fmod_test_7);
  tcase_add_test(tc10, s21_fmod_test_8);
  tcase_add_test(tc10, s21_fmod_test_9);
  tcase_add_test(tc10, s21_fmod_test_10);
  tcase_add_test(tc10, s21_fmod_test_11);
  tcase_add_test(tc10, s21_fmod_test_12);
  tcase_add_test(tc10, s21_fmod_test_13);
  tcase_add_test(tc10, s21_fmod_test_14);
  tcase_add_test(tc10, s21_fmod_test_15);
  tcase_add_test(tc10, s21_fmod_test_16);
  tcase_add_test(tc10, s21_fmod_test_17);
  tcase_add_test(tc10, s21_fmod_test_18);
  tcase_add_test(tc10, s21_fmod_test_19);
  tcase_add_test(tc10, s21_fmod_test_20);
  tcase_add_test(tc10, s21_fmod_test_21);
  tcase_add_test(tc10, s21_fmod_test_22);
  tcase_add_test(tc10, s21_fmod_test_23);
  tcase_add_test(tc10, s21_fmod_test_24);
  tcase_add_test(tc10, s21_fmod_test_25);
  tcase_add_test(tc10, s21_fmod_test_26);
  tcase_add_test(tc10, s21_fmod_test_27);
  tcase_add_test(tc10, s21_fmod_test_28);
  tcase_add_test(tc10, s21_fmod_test_29);
  tcase_add_test(tc10, s21_fmod_test_30);
  tcase_add_test(tc10, s21_fmod_test_31);
  tcase_add_test(tc10, s21_fmod_test_32);
  tcase_add_test(tc10, s21_fmod_test_33);
  tcase_add_test(tc10, s21_fmod_test_34);
  tcase_add_test(tc10, s21_fmod_test_35);
  tcase_add_test(tc10, s21_fmod_test_36);
  tcase_add_test(tc10, s21_fmod_test_37);
  tcase_add_test(tc10, s21_fmod_test_38);
  tcase_add_test(tc10, s21_fmod_test_39);
  suite_add_tcase(s, tc10);

  return s;
}

int main(void) {
  // setlocale(LC_ALL, "");
  int failed = 0;
  Suite *s21_math_test[] = {test_abs(),  test_ceil(), test_floor(), test_fmod(),
                            test_fabs(), test_sin(),  test_cos(),   test_tan(),
                            test_atan(), test_sqrt(), test_asin(),  test_acos(),
                            test_exp(),  test_log(),  test_pow(),   NULL};
  for (int i = 0; s21_math_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s21_math_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_VERBOSE);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
