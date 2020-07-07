/*
 * File: xrot.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "xrot.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : double x[262144]
 *                int ix0
 *                int iy0
 *                double c
 *                double s
 * Return Type  : void
 */
void b_xrot(double x[262144], int ix0, int iy0, double c, double s)
{
  cblas_drot((int)512, &x[ix0 - 1], (int)1, &x[iy0 - 1], (int)1, c, s);
}

/*
 * Arguments    : double x[1048576]
 *                int ix0
 *                int iy0
 *                double c
 *                double s
 * Return Type  : void
 */
void c_xrot(double x[1048576], int ix0, int iy0, double c, double s)
{
  cblas_drot((int)1024, &x[ix0 - 1], (int)1, &x[iy0 - 1], (int)1, c, s);
}

/*
 * Arguments    : double x[4194304]
 *                int ix0
 *                int iy0
 *                double c
 *                double s
 * Return Type  : void
 */
void d_xrot(double x[4194304], int ix0, int iy0, double c, double s)
{
  cblas_drot((int)2048, &x[ix0 - 1], (int)1, &x[iy0 - 1], (int)1, c, s);
}

/*
 * Arguments    : double x[16777216]
 *                int ix0
 *                int iy0
 *                double c
 *                double s
 * Return Type  : void
 */
void e_xrot(double x[16777216], int ix0, int iy0, double c, double s)
{
  cblas_drot((int)4096, &x[ix0 - 1], (int)1, &x[iy0 - 1], (int)1, c, s);
}

/*
 * Arguments    : double x[65536]
 *                int ix0
 *                int iy0
 *                double c
 *                double s
 * Return Type  : void
 */
void xrot(double x[65536], int ix0, int iy0, double c, double s)
{
  int ix;
  int iy;
  int k;
  double temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 256; k++) {
    temp = c * x[ix] + s * x[iy];
    x[iy] = c * x[iy] - s * x[ix];
    x[ix] = temp;
    iy++;
    ix++;
  }
}

/*
 * File trailer for xrot.c
 *
 * [EOF]
 */
