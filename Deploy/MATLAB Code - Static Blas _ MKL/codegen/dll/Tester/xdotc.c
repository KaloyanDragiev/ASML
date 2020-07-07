/*
 * File: xdotc.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "xdotc.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : int n
 *                const double x[262144]
 *                int ix0
 *                const double y[262144]
 *                int iy0
 * Return Type  : double
 */
double b_xdotc(int n, const double x[262144], int ix0, const double y[262144],
               int iy0)
{
  double d;
  if (n < 1) {
    d = 0.0;
  } else {
    d = cblas_ddot((int)n, &x[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
  }

  return d;
}

/*
 * Arguments    : int n
 *                const double x[1048576]
 *                int ix0
 *                const double y[1048576]
 *                int iy0
 * Return Type  : double
 */
double c_xdotc(int n, const double x[1048576], int ix0, const double y[1048576],
               int iy0)
{
  double d;
  if (n < 1) {
    d = 0.0;
  } else {
    d = cblas_ddot((int)n, &x[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
  }

  return d;
}

/*
 * Arguments    : int n
 *                const double x[4194304]
 *                int ix0
 *                const double y[4194304]
 *                int iy0
 * Return Type  : double
 */
double d_xdotc(int n, const double x[4194304], int ix0, const double y[4194304],
               int iy0)
{
  double d;
  if (n < 1) {
    d = 0.0;
  } else {
    d = cblas_ddot((int)n, &x[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
  }

  return d;
}

/*
 * Arguments    : int n
 *                const double x[16777216]
 *                int ix0
 *                const double y[16777216]
 *                int iy0
 * Return Type  : double
 */
double e_xdotc(int n, const double x[16777216], int ix0, const double y[16777216],
               int iy0)
{
  double d;
  if (n < 1) {
    d = 0.0;
  } else {
    d = cblas_ddot((int)n, &x[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
  }

  return d;
}

/*
 * Arguments    : int n
 *                const double x[65536]
 *                int ix0
 *                const double y[65536]
 *                int iy0
 * Return Type  : double
 */
double xdotc(int n, const double x[65536], int ix0, const double y[65536], int
             iy0)
{
  double d;
  int ix;
  int iy;
  int k;
  d = 0.0;
  if (n >= 1) {
    ix = ix0;
    iy = iy0;
    for (k = 0; k < n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

/*
 * File trailer for xdotc.c
 *
 * [EOF]
 */
