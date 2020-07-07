/*
 * File: xrotg.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:35:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "xrotg.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : double *a
 *                double *b
 *                double *c
 *                double *s
 * Return Type  : void
 */
void xrotg(double *a, double *b, double *c, double *s)
{
  *c = 0.0;
  *s = 0.0;
  cblas_drotg(a, b, c, s);
}

/*
 * File trailer for xrotg.c
 *
 * [EOF]
 */
