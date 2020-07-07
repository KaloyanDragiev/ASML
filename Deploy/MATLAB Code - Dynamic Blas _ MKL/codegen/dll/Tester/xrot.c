/*
 * File: xrot.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:35:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "xrot.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : int n
 *                emxArray_real_T *x
 *                int ix0
 *                int iy0
 *                double c
 *                double s
 * Return Type  : void
 */
void xrot(int n, emxArray_real_T *x, int ix0, int iy0, double c, double s)
{
  if (n >= 1) {
    cblas_drot((int)n, &x->data[ix0 - 1], (int)1, &x->data[iy0 - 1], (int)1, c,
               s);
  }
}

/*
 * File trailer for xrot.c
 *
 * [EOF]
 */
