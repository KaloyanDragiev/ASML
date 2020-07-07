/*
 * File: meshgrid.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 09-Jan-2020 11:21:18
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "f3_auto_tester.h"
#include "meshgrid.h"

/* Function Definitions */

/*
 * Arguments    : const double x[4024]
 *                double xx[16192576]
 *                double yy[16192576]
 * Return Type  : void
 */
void meshgrid(const double x[4024], double xx[16192576], double yy[16192576])
{
  int j;
  int i;
  for (j = 0; j < 4024; j++) {
    memcpy(&yy[j * 4024], &x[0], 4024U * sizeof(double));
    for (i = 0; i < 4024; i++) {
      xx[i + 4024 * j] = x[j];
    }
  }
}

/*
 * File trailer for meshgrid.c
 *
 * [EOF]
 */
