/*
 * File: mean.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "mean.h"

/* Function Definitions */

/*
 * Arguments    : const double x[10]
 * Return Type  : double
 */
double mean(const double x[10])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 9; k++) {
    y += x[k + 1];
  }

  y /= 10.0;
  return y;
}

/*
 * File trailer for mean.c
 *
 * [EOF]
 */
