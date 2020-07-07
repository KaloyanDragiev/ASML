/*
 * File: xaxpy.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "xaxpy.h"

/* Function Definitions */

/*
 * Arguments    : int n
 *                double a
 *                const double x[65536]
 *                int ix0
 *                double y[256]
 *                int iy0
 * Return Type  : void
 */
void b_xaxpy(int n, double a, const double x[65536], int ix0, double y[256], int
             iy0)
{
  int ix;
  int iy;
  int i17;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i17 = n - 1;
    for (k = 0; k <= i17; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const double x[256]
 *                int ix0
 *                double y[65536]
 *                int iy0
 * Return Type  : void
 */
void c_xaxpy(int n, double a, const double x[256], int ix0, double y[65536], int
             iy0)
{
  int ix;
  int iy;
  int i18;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i18 = n - 1;
    for (k = 0; k <= i18; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                int ix0
 *                double y[262144]
 *                int iy0
 * Return Type  : void
 */
void d_xaxpy(int n, double a, int ix0, double y[262144], int iy0)
{
  int ix;
  int iy;
  int i25;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i25 = n - 1;
    for (k = 0; k <= i25; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const double x[262144]
 *                int ix0
 *                double y[512]
 *                int iy0
 * Return Type  : void
 */
void e_xaxpy(int n, double a, const double x[262144], int ix0, double y[512],
             int iy0)
{
  int ix;
  int iy;
  int i26;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i26 = n - 1;
    for (k = 0; k <= i26; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const double x[512]
 *                int ix0
 *                double y[262144]
 *                int iy0
 * Return Type  : void
 */
void f_xaxpy(int n, double a, const double x[512], int ix0, double y[262144],
             int iy0)
{
  int ix;
  int iy;
  int i27;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i27 = n - 1;
    for (k = 0; k <= i27; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                int ix0
 *                double y[1048576]
 *                int iy0
 * Return Type  : void
 */
void g_xaxpy(int n, double a, int ix0, double y[1048576], int iy0)
{
  int ix;
  int iy;
  int i34;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i34 = n - 1;
    for (k = 0; k <= i34; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const double x[1048576]
 *                int ix0
 *                double y[1024]
 *                int iy0
 * Return Type  : void
 */
void h_xaxpy(int n, double a, const double x[1048576], int ix0, double y[1024],
             int iy0)
{
  int ix;
  int iy;
  int i35;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i35 = n - 1;
    for (k = 0; k <= i35; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const double x[1024]
 *                int ix0
 *                double y[1048576]
 *                int iy0
 * Return Type  : void
 */
void i_xaxpy(int n, double a, const double x[1024], int ix0, double y[1048576],
             int iy0)
{
  int ix;
  int iy;
  int i36;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i36 = n - 1;
    for (k = 0; k <= i36; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                int ix0
 *                double y[4194304]
 *                int iy0
 * Return Type  : void
 */
void j_xaxpy(int n, double a, int ix0, double y[4194304], int iy0)
{
  int ix;
  int iy;
  int i43;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i43 = n - 1;
    for (k = 0; k <= i43; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const double x[4194304]
 *                int ix0
 *                double y[2048]
 *                int iy0
 * Return Type  : void
 */
void k_xaxpy(int n, double a, const double x[4194304], int ix0, double y[2048],
             int iy0)
{
  int ix;
  int iy;
  int i44;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i44 = n - 1;
    for (k = 0; k <= i44; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const double x[2048]
 *                int ix0
 *                double y[4194304]
 *                int iy0
 * Return Type  : void
 */
void l_xaxpy(int n, double a, const double x[2048], int ix0, double y[4194304],
             int iy0)
{
  int ix;
  int iy;
  int i45;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i45 = n - 1;
    for (k = 0; k <= i45; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                int ix0
 *                double y[16777216]
 *                int iy0
 * Return Type  : void
 */
void m_xaxpy(int n, double a, int ix0, double y[16777216], int iy0)
{
  int ix;
  int iy;
  int i52;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i52 = n - 1;
    for (k = 0; k <= i52; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const double x[16777216]
 *                int ix0
 *                double y[4096]
 *                int iy0
 * Return Type  : void
 */
void n_xaxpy(int n, double a, const double x[16777216], int ix0, double y[4096],
             int iy0)
{
  int ix;
  int iy;
  int i53;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i53 = n - 1;
    for (k = 0; k <= i53; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                const double x[4096]
 *                int ix0
 *                double y[16777216]
 *                int iy0
 * Return Type  : void
 */
void o_xaxpy(int n, double a, const double x[4096], int ix0, double y[16777216],
             int iy0)
{
  int ix;
  int iy;
  int i54;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i54 = n - 1;
    for (k = 0; k <= i54; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * Arguments    : int n
 *                double a
 *                int ix0
 *                double y[65536]
 *                int iy0
 * Return Type  : void
 */
void xaxpy(int n, double a, int ix0, double y[65536], int iy0)
{
  int ix;
  int iy;
  int i16;
  int k;
  if ((n < 1) || (a == 0.0)) {
  } else {
    ix = ix0 - 1;
    iy = iy0 - 1;
    i16 = n - 1;
    for (k = 0; k <= i16; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/*
 * File trailer for xaxpy.c
 *
 * [EOF]
 */
