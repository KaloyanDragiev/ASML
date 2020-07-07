/*
 * File: xaxpy.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "xaxpy.h"
#include "cblas.h"

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
  if (n >= 1) {
    cblas_daxpy((int)n, a, &x[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
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
  if (n >= 1) {
    cblas_daxpy((int)n, a, &x[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
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
  if (n >= 1) {
    cblas_daxpy((int)n, a, &y[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
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
  if (n >= 1) {
    cblas_daxpy((int)n, a, &x[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
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
  if (n >= 1) {
    cblas_daxpy((int)n, a, &x[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
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
  if (n >= 1) {
    cblas_daxpy((int)n, a, &y[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
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
  if (n >= 1) {
    cblas_daxpy((int)n, a, &x[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
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
  if (n >= 1) {
    cblas_daxpy((int)n, a, &x[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
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
  if (n >= 1) {
    cblas_daxpy((int)n, a, &y[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
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
  if (n >= 1) {
    cblas_daxpy((int)n, a, &x[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
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
  if (n >= 1) {
    cblas_daxpy((int)n, a, &x[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
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
  if (n >= 1) {
    cblas_daxpy((int)n, a, &y[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
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
  if (n >= 1) {
    cblas_daxpy((int)n, a, &x[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
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
  if (n >= 1) {
    cblas_daxpy((int)n, a, &x[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
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
  if (n >= 1) {
    cblas_daxpy((int)n, a, &y[ix0 - 1], (int)1, &y[iy0 - 1], (int)1);
  }
}

/*
 * File trailer for xaxpy.c
 *
 * [EOF]
 */
