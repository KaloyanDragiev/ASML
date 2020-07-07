/*
 * File: xswap.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 25-Nov-2019 15:28:30
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "f2_auto_tester.h"
#include "xswap.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : double x[1000000]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void b_xswap(double x[1000000], int ix0, int iy0)
{
  cblas_dswap((int)1000, &x[ix0 - 1], (int)1000, &x[iy0 - 1], (int)1000);
}

/*
 * Arguments    : double x[10000]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void xswap(double x[10000], int ix0, int iy0)
{
  int ix;
  int iy;
  int k;
  double temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 100; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix += 100;
    iy += 100;
  }
}

/*
 * File trailer for xswap.c
 *
 * [EOF]
 */
