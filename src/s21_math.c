#include "s21_math.h"

#include <float.h>
//вычисляет абсолютное значение целого числа
int s21_abs(int x) { return x < 0 ? -x : x; }

long double s21_acos(double x) {
  long double newx = x;
  if (s21_fabs(x) > 1)
    newx = s21_NAN;
  else if (x == 0)
    newx = s21_PI / 2;
  else if (x > 0)
    newx = s21_atan(s21_sqrt(1 - x * x) / x);
  else
    newx = s21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  return newx;
}

long double s21_asin(double x) {
  long double newx = x;
  if (s21_fabs(x) > 1) newx = s21_NAN;
  if (x == 1)
    newx = s21_PI / 2;
  else if (x == -1)
    newx = -s21_PI / 2;
  else {
    long double n = s21_sqrt(1 - x * x);
    newx = s21_atan(x / n);
  }
  return newx;
}
long double s21_atan(double x) {
  long double newx = x;
  if (x != x)
    newx = s21_NAN;
  else if (x == 1)
    newx = s21_PI / 4;
  else if (x == -1)
    newx = -s21_PI / 4;
  else if (x > 1)
    newx = s21_PI / 2 - s21_atan(1 / x);
  else if (x < -1)
    newx = -s21_PI / 2 - s21_atan(1 / x);
  else {
    long double t = x, s = x;
    long int prev = 1;
    for (long int n = 3; s21_fabs(t) > 1e-7; n += 2) {
      t = -t * x * x * prev / n;
      s += t;
      prev = n;
    }
    newx = s;
  }
  return newx;
}
long double s21_ceil(double x) {
  long double newx = x;
  if (x != x || x == -s21_INFINITY || x == s21_INFINITY)
    ;
  else {
    long double n = x;
    char buf[50];
    sprintf(buf, "%.0Lf", newx);
    sscanf(buf, "%Lf", &newx);
    if (n > newx) newx++;
  }
  return newx;
}
long double s21_cos(double x) {
  long double newx = x;
  if (x != x || x == -s21_INFINITY || x == s21_INFINITY)
    newx = s21_NAN;
  else {
    int sign = 1;
    newx = s21_fmod(s21_fabs(x), 2 * s21_PI);  //приводим к [0, 2pi]
    if (newx > s21_PI) {
      newx = newx - s21_PI;
      sign *= -1;
    }  //приводим к [0, pi]
    if (newx > s21_PI / 2) {
      newx = s21_PI - newx;
      sign *= -1;
    }  //приводим к [0, pi/2]
    long double t = 1, s = 1;
    for (long long int n = 2, i = 0; i < 501; n += 2, i++) {
      t = -t * newx * newx / (n * (n - 1));
      s += t;
    }
    newx = s * sign;
  }
  return newx;
}

long double s21_exp(double x) {
  long double res = x;
  if (x != x)
    ;
  else if (x >= 710)
    res = s21_INFINITY;
  else if (x <= -746)
    res = 0;
  else {
    int sign = x < 0 ? -1 : 1;
    x = s21_fabs(x);
    long double int_part = s21_floor(x);
    long double fractional_part = x - int_part;
    int_part = binpow(EXP, int_part);
    long double t = fractional_part, s = 1 + fractional_part;
    for (int n = 2; s21_fabs(t) > 1e-17; n++) {
      t = t * fractional_part / n;
      s += t;
    }
    res = sign == -1 ? 1.0 / (int_part * s) : (int_part * s);
  }
  return res;
}

long double s21_fabs(double x) {
  long double newx = x;
  if (x != x)
    ;
  else {
    newx = x < 0 ? -newx : newx;
  }
  return newx;
}

long double s21_floor(double x) {
  long double newx = x;
  if (x != x || x == -s21_INFINITY || x == s21_INFINITY)
    ;
  else {
    long double n = x;
    char buf[50];
    sprintf(buf, "%.0Lf", newx);
    sscanf(buf, "%Lf", &newx);
    if (newx > n) newx--;
  }
  return newx;
}

//остаток операции деления с плавающей точкой
long double s21_fmod(double x, double y) {
  long double n;
  if (y == 0 || x != x || x == s21_INFINITY || x == -s21_INFINITY || y != y)
    n = s21_NAN;
  else if (y == s21_INFINITY || y == -s21_INFINITY)
    n = x;
  else {
    if (x * y < 0)
      n = x - y * s21_ceil(x / y);
    else
      n = x - y * s21_floor(x / y);
  }
  return n;
}

long double s21_log(double x) {
  long double newx = x;
  if (x < 0)
    newx = s21_NAN;
  else if (x == 0)
    newx = -s21_INFINITY;
  else if (x == s21_INFINITY)
    ;
  else if (x == 1)
    newx = 0;
  else {
    long double ln = 0, ln0 = 0;
    int cnt = 0;
    for (; newx > 1e-9; newx /= EXP, cnt++) continue;
    for (int i = 0; i < 400; i++) {
      ln = ln0 + 2 * (newx - s21_exp(ln0)) / (newx + s21_exp(ln0));
      ln0 = ln;
    }
    newx = ln + cnt;
  }
  return newx;
}

long double s21_pow(double base, double exp) {
  long double newbase = base;
  if (exp == 0)
    newbase = 1;
  else if ((exp != exp && (base != 1)) || (base != base))
    newbase = s21_NAN;
  else if (base == -s21_INFINITY) {
    if (s21_fmod(s21_fabs(exp), 2) == 0)
      newbase = exp < 0 ? 0 : s21_INFINITY;
    else if (s21_fmod(s21_fabs(exp), 1) == 0)
      newbase = exp < 0 ? 1.0 / (-s21_INFINITY) : -s21_INFINITY;
    else
      newbase = exp < 0 ? 0 : s21_INFINITY;
  } else if (1 / base == -s21_INFINITY && s21_fmod(s21_fabs(exp), 1) == 0) {
    if (exp > 0)
      newbase = s21_fmod(exp, 2) == 0 ? 0.0 : -0.0;
    else
      newbase = -s21_INFINITY;
  } else if (base == 0)
    newbase = exp < 0 ? s21_INFINITY : 0;
  else if (base == 1) {
    ;
  } else if (base == -1) {
    if (exp == s21_INFINITY || exp == -s21_INFINITY)
      newbase = 1;
    else if (s21_fmod(exp, 1) != 0)
      newbase = s21_NAN;
    else
      newbase = s21_fmod(s21_fabs(exp), 2) == 0 ? 1 : -1;
  } else if (exp == -s21_INFINITY) {
    if (s21_fabs(base) > 0 && s21_fabs(base) < 1)
      newbase = s21_INFINITY;
    else
      newbase = 0;
  } else if (exp == s21_INFINITY) {
    if (s21_fabs(base) > 0 && s21_fabs(base) < 1)
      newbase = 0;
    else
      newbase = s21_INFINITY;
  } else if (s21_fmod(exp, 1) == 0) {
    long double n = binpow(newbase, s21_fabs(exp));
    newbase = exp < 0 ? 1 / n : n;
  } else {
    long double degree = s21_fabs(exp);
    long double int_part = s21_floor(degree);
    long double fractional_part = degree - int_part;
    int_part = binpow(newbase, int_part);
    fractional_part = s21_exp(fractional_part * s21_log(newbase));
    if (exp < 0)
      newbase = 1 / (int_part * fractional_part);
    else
      newbase = int_part * fractional_part;
  }
  return newbase;
}

long double s21_sin(double x) {
  long double newx = x;
  if (x != x || x == s21_INFINITY || x == -s21_INFINITY)
    newx = s21_NAN;
  else {
    int sign = x < 0 ? -1 : 1;
    newx = s21_fmod(s21_fabs(x), 2 * s21_PI);  //приводим к [0, 2pi]
    if (x > s21_PI) {
      newx -= s21_PI;
      sign *= -1;
    }                                          //приводим к[0, pi]
    if (x > s21_PI / 2) newx = s21_PI - newx;  //приводим к [0, pi/2]

    long double t = newx, s = newx;
    for (long long int n = 3, i = 0; i < 501; n += 2, i++) {
      t = -t * newx * newx / (n * (n - 1));
      s += t;
    }
    newx = s * sign;
  }
  return newx;
}
long double s21_sqrt(double x) {
  long double res;
  if (x < 0)
    res = s21_NAN;
  else if (x == s21_INFINITY)
    res = s21_INFINITY;
  else if (x == 0)
    res = 0;
  else {
    long double y = 1;
    for (int i = 0; i < 50; i++) {
      res = 0.5 * (y + x / y);
      y = res;
    }
  }
  return res;
}

long double s21_tan(double x) {
  if (x == 0)
    ;
  else
    x = s21_sin(x) / s21_cos(x);
  return x;
}

long double binpow(long double a, unsigned long long int n) {
  long double res = 1;
  while (n != 0) {
    if (n & 1) res = res * a;
    a = a * a;
    n >>= 1;
  }
  return res;
}