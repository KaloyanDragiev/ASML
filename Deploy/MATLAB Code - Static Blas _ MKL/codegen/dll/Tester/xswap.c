/*
 * File: xswap.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "xswap.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : double x[262144]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void b_xswap(double x[262144], int ix0, int iy0)
{
  cblas_dswap((int)512, &x[ix0 - 1], (int)1, &x[iy0 - 1], (int)1);
}

/*
 * Arguments    : double x[1048576]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void c_xswap(double x[1048576], int ix0, int iy0)
{
  cblas_dswap((int)1024, &x[ix0 - 1], (int)1, &x[iy0 - 1], (int)1);
}

/*
 * Arguments    : double x[4194304]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void d_xswap(double x[4194304], int ix0, int iy0)
{
  cblas_dswap((int)2048, &x[ix0 - 1], (int)1, &x[iy0 - 1], (int)1);
}

/*
 * Arguments    : double x[16777216]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void e_xswap(double x[16777216], int ix0, int iy0)
{
  cblas_dswap((int)4096, &x[ix0 - 1], (int)1, &x[iy0 - 1], (int)1);
}

/*
 * Arguments    : double x[65536]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void xswap(double x[65536], int ix0, int iy0)
{
  int ix;
  int iy;
  int k;
  double temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 256; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix++;
    iy++;
  }
}

/*
 * File trailer for xswap.c
 *
 * [EOF]
 */
