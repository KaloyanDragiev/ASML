/*
 * File: xrot.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:45:17
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "xrot.h"

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
  int ix;
  int iy;
  int k;
  double temp;
  if (n >= 1) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      temp = c * x->data[ix] + s * x->data[iy];
      x->data[iy] = c * x->data[iy] - s * x->data[ix];
      x->data[ix] = temp;
      iy++;
      ix++;
    }
  }
}

/*
 * File trailer for xrot.c
 *
 * [EOF]
 */
