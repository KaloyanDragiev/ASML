/*
 * File: meshgrid.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 25-Nov-2019 15:28:30
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "f2_auto_tester.h"
#include "meshgrid.h"

/* Function Definitions */

/*
 * Arguments    : const double x[100]
 *                double xx[10000]
 *                double yy[10000]
 * Return Type  : void
 */
void meshgrid(const double x[100], double xx[10000], double yy[10000])
{
  int j;
  int i;
  for (j = 0; j < 100; j++) {
    memcpy(&yy[j * 100], &x[0], 100U * sizeof(double));
    for (i = 0; i < 100; i++) {
      xx[i + 100 * j] = x[j];
    }
  }
}

/*
 * File trailer for meshgrid.c
 *
 * [EOF]
 */
