/*
 * File: xdotc.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:35:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "xdotc.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : int n
 *                const emxArray_real_T *x
 *                int ix0
 *                const emxArray_real_T *y
 *                int iy0
 * Return Type  : double
 */
double xdotc(int n, const emxArray_real_T *x, int ix0, const emxArray_real_T *y,
             int iy0)
{
  double d;
  if (n < 1) {
    d = 0.0;
  } else {
    d = cblas_ddot((int)n, &x->data[ix0 - 1], (int)1, &y->data[iy0 - 1], (int)1);
  }

  return d;
}

/*
 * File trailer for xdotc.c
 *
 * [EOF]
 */
