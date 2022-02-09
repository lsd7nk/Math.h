#include "s21_math.h"


long int s21_abs(int x) { return x > 0 ? x : -x; }

long double s21_fabs(double x) {
  if (x != x) return S21_NAN;
  return (x > 0) ? x : -x;
}

long double s21_sqrt(double x) {
  if (x == S21_INFINITY || x == S21_MINUS_INFINITY) return x;
  return (x < 0 || x != x) ? S21_NAN : s21_exp(0.5 * s21_log(x));
}

static long double taylor(double x) {
  long double PowX = 1, Add, Sum = 0;
  int Sig = 1, n = 1;
  Add = PowX = x;

  while (s21_fabs(Add) > 0) {
    Sum += Add;
    Sig = -Sig;
    Add = Sig * (PowX *= x) / ++n;
  }
  return Sum;
}

long double s21_log(double x) {
  if (x != x) return S21_NAN;
  if (x == 0.0) return -S21_INFINITY;
  if (x == S21_INFINITY) return S21_INFINITY;
  if (x == -S21_INFINITY) return S21_NAN;

  long double res = 0.0;
  if (x > 2) {
    int n = 0;

    while (x > 1) {
      x /= 10;
      n++;
    }
    res = n * LN10 + taylor(x - 1);
  } else {
    x = x - 1;
    res = taylor(x);
  }
  return res;
}

long double s21_pow(double x, double exp) {
  long double res = 0.0;
  if (x == 1 && exp == S21_NAN) {
    res = 1;
  } else if (x != x || exp != exp) {
    res = S21_NAN;
  } else if ((x == S21_INFINITY && exp == -S21_INFINITY) ||
             (x == -S21_INFINITY && exp == -S21_INFINITY)) {
    res = (long double)0.0;
  } else if ((x == S21_INFINITY && exp == S21_INFINITY) ||
             (x == -S21_INFINITY && exp == S21_INFINITY)) {
    res = S21_INFINITY;
  } else if (x == S21_INFINITY) {
    res = S21_INFINITY;
  } else if (x < 0) {
    if (exp < 1 && exp > -1) return S21_NAN;
    int i = (int)exp;
    if (exp - i != 0) {
      return S21_NAN;
    }
  } else {
    res = 1.0;
    int a = (int)exp;

    if (exp - a == 0) {
      while (exp > 0) {
        res *= x;
        exp--;
      }
    } else {
      res = s21_exp(exp * s21_log(s21_fabs(x)));
    }
  }
  return res;
}

long double s21_sin(double x) {
  long double y;
  if (x != x) {
    y = -S21_NAN;
  } else if (x == S21_INFINITY || x == -S21_INFINITY) {
    y = -S21_NAN;
  } else {
    int negative = 1;
    if (x < 0) {
      negative = -1;
      x *= -1;
    }
    while (x > S21_PI_2) {
      x -= S21_PI;
      negative *= -1;
    }
    if (x <= S21_PI_3 && x >= -S21_PI_3) {
      long double P1 = 1.5707963, P2 = 0.64596410, P3 = 0.079692626;
      long double P4 = 0.0046817541, P5 = 0.00016044118, P6 = 0.0000035988432;
      long double d_x3, d_x5, d_x7, d_x9, d_x11;
      x = x / S21_PI_2;
      d_x3 = x * x * x;
      d_x5 = d_x3 * x * x;
      d_x7 = d_x5 * x * x;
      d_x9 = d_x7 * x * x;
      d_x11 = d_x9 * x * x;
      y = P1 * x - P2 * d_x3 + P3 * d_x5 - P4 * d_x7 + P5 * d_x9 + P6 * d_x11;
    } else {
      if (x > S21_PI_3) {
        y = s21_sin(x - S21_PI_6) * S21_SQRT_3_DIV_2 +
            s21_cos(x - S21_PI_6) * 0.5;
      } else {
        y = (s21_sin(x + S21_PI_6) * S21_SQRT_3_DIV_2 -
             s21_cos(x + S21_PI_6) * 0.5);
      }
    }
    y *= (long double)negative;
    if (y < -1.0) y = -0.99999999999999999;
    if (y > 1.0) y = 0.9999999999999999990;
  }
  return y;
}

long double s21_tan(double x) {
  long double y = 0;
  if (x != x) {
    y = -S21_NAN;
  } else if (x == S21_INFINITY || x == -S21_INFINITY) {
    y = -S21_NAN;
  } else {
    long double sin_x = s21_sin(x), cos_x = s21_cos(x);
    if (cos_x == 0) {
      if (sin_x > 0) {
        y = S21_INFINITY;
      } else if (sin_x < 0) {
        y = -S21_INFINITY;
      }
    } else {
      y = sin_x / cos_x;
    }
  }
  return y;
}

long double s21_cos(double x) {
  long double y;
  if (x != x) {
    y = -S21_NAN;
  } else if (x == S21_INFINITY || x == -S21_INFINITY) {
    y = -S21_NAN;
  } else {
    if (x < 0) {
      x *= -1;
    }
    while (x >= 2 * S21_PI) {
      x -= 2 * S21_PI;
    }
    x = S21_PI_2 - x;
    y = s21_sin(x);
  }
  return y;
}

long double s21_exp(double x) {
  if (x != x) return x;
  if (x <= MIN_DEGREE) return 1e-310;
  if (x == S21_INFINITY || x > MAX_DEGREE)
    return S21_INFINITY;
  else if (x == S21_MINUS_INFINITY)
    return 0;

  double dVal = 1.0;
  double dTemp = 1.0;

  for (int nStep = 1; dTemp >= PRECISION; ++nStep) {
    dTemp *= s21_fabs(x) / nStep;
    dVal += dTemp;
  }
  return (x > 0) ? dVal : 1.0 / dVal;
}

long double s21_fmod(double x, double y) {
  double result;
  int flag = 0;

  if (y == S21_INFINITY || y == S21_MINUS_INFINITY) return x;  // inf

  if (x != x || y != y) return S21_NAN;  // nan

  if (x < 0 && y > 0) {  // normal
    y = -y;
  } else if (x > 0 && y < 0) {
    x *= -1;
    flag = 1;
  }

  result = x - y * s21_floor(x / y);
  return (flag == 1) ? -result : result;
}

long double s21_floor(double x) {
  if (x != x) return x;
  long double y = 0.0;
  if (x == S21_INFINITY) {
    y = S21_INFINITY;
  } else if (x == S21_MINUS_INFINITY) {
    y = S21_MINUS_INFINITY;
  } else {
    long long int i = 0;

    if (x < 0) {
      i = x - 1;
    } else {
      i = x;
    }
    y = i;
  }
  return x != x ? S21_NAN : y;
}

long double s21_ceil(double x) {
  if (x != x) return x;
  long double y = 0.0;
  if (x == S21_INFINITY) {
    y = S21_INFINITY;
  } else if (x == S21_MINUS_INFINITY) {
    y = S21_MINUS_INFINITY;
  } else {
    long long int i = 0;

    if (x <= -1) {
      i = x;
    } else if (x > 0 || x == 0) {
      i = x + 1;
    } else {
      i = -0;
    }
    y = i;
  }
  return x != x ? S21_NAN : y;
}

long double s21_asin(double x) {
  long double y;
  if (x != x || x > 1.0 || x < -1.0) {
    y = S21_NAN;
  } else if (x == 1) {
    y = S21_PI_2;
  } else if (x == -1) {
    y = -S21_PI_2;
  } else {
    y = s21_atan(x / s21_sqrt(1 - x * x));
  }
  return y;
}

long double s21_acos(double x) {
  long double y;
  if (x != x || x > 1.0 || x < -1.0) {
    y = S21_NAN;
  } else if (x == 1) {
    y = 0;
  } else if (x == -1) {
    y = S21_PI;
  } else {
    y = S21_PI_2 - s21_asin(x);
  }
  return y;
}

long double s21_atan(double x) {
  long double y;
  if (x != x) {
    y = -S21_NAN;
  } else if (x == S21_INFINITY) {
    y = S21_PI_2;
  } else if (x == -S21_INFINITY) {
    y = -S21_PI_2;
  } else {
    long double dx, s21_abss;
    int n = 1, flag = 0, flag_negative = 0;
    if (x < 0) {
      flag_negative = 1;
      x *= -1;
    }
    if (x > 1) {
      x = 1 / x;
      flag = 1;
    }
    dx = x;
    y = x;
    s21_abss = x;
    if (x != 1) {
      while (s21_abss > 0.000000000000001) {
        ++n;
        dx *= -x * x * (2 * n - 3) / (2 * n - 1);
        y += dx;
        if (dx < 0) {
          s21_abss *= -dx;
        } else {
          s21_abss = dx;
        }
      }
    } else {
      y = S21_PI_4;
    }
    if (flag == 1) {
      y = S21_PI_2 - y;
    }
    if (flag_negative == 1) {
      y *= -1;
    }
  }
  return y;
}
