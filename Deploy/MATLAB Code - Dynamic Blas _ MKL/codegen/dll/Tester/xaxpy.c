/*
 * File: xaxpy.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:35:01
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
 *                const emxArray_real_T *x
 *                int ix0
 *                emxArray_real_T *y
 *                int iy0
 * Return Type  : void
 */
void b_xaxpy(int n, double a, const emxArray_real_T *x, int ix0, emxArray_real_T
             *y, int iy0)
{
  if (n >= 1) {
    cblas_daxpy((int)n, a, &x->data[ix0 - 1], (int)1, &y->data[iy0 - 1], (int)1);
  }
}

/*
 * Arguments    : int n
 *                double a
 *                int ix0
 *                emxArray_real_T *y
 *                int iy0
 * Return Type  : void
 */
void xaxpy(int n, double a, int ix0, emxArray_real_T *y, int iy0)
{
  if (n >= 1) {
    cblas_daxpy((int)n, a, &y->data[ix0 - 1], (int)1, &y->data[iy0 - 1], (int)1);
  }
}

/*
 * File trailer for xaxpy.c
 *
 * [EOF]
 */
