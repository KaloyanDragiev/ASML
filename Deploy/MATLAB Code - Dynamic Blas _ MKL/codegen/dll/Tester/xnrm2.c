/*
 * File: xnrm2.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:35:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "xnrm2.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : int n
 *                const emxArray_real_T *x
 *                int ix0
 * Return Type  : double
 */
double xnrm2(int n, const emxArray_real_T *x, int ix0)
{
  double y;
  if (n < 1) {
    y = 0.0;
  } else {
    y = cblas_dnrm2((int)n, &x->data[ix0 - 1], (int)1);
  }

  return y;
}

/*
 * File trailer for xnrm2.c
 *
 * [EOF]
 */
