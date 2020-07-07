/*
 * File: xscal.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:35:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "xscal.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : int n
 *                double a
 *                emxArray_real_T *x
 *                int ix0
 * Return Type  : void
 */
void xscal(int n, double a, emxArray_real_T *x, int ix0)
{
  if (n >= 1) {
    cblas_dscal((int)n, a, &x->data[ix0 - 1], (int)1);
  }
}

/*
 * File trailer for xscal.c
 *
 * [EOF]
 */
