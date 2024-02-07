#ifndef SRC_MATH_H_
#define SRC_MATH_H_

#define MIN_DEGREE -713
#define MAX_DEGREE 709.782712
#define LN10 2.30258509299404568401799145468436421
#define LN2 0.693147180559945309417232121458176568
#define PRECISION 1e-9
#define INFINITY __builtin_huge_vall()
#define NEGATIVE_INFINITY -__builtin_huge_vall()
#define PI_6 0.52359877559829881565889309058547951
#define PI_4 0.785398163397448309615660845819875721
#define PI_3 1.04719755119659763131778618117095903
#define PI_2 1.57079632679489661923132169163975144
#define PI 3.14159265358979323846264338327950288
#define SQRT_3_DIV_2 0.86602540378443859658830206171842292
#define NAN __builtin_nanf("0x7fc00000")

long int abs(int x);
long double acos(double x);
long double asin(double x);
long double atan(double x);
long double ceil(double x);
long double cos(double x);
long double exp(double x);
long double fabs(double x);
long double floor(double x);
long double fmod(double x, double y);
long double log(double x);
long double pow(double base, double exp);
long double sin(double x);
long double sqrt(double x);
long double tan(double x);
#endif  // SRC_MATH_H_
