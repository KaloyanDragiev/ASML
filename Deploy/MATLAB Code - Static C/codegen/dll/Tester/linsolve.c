/*
 * File: linsolve.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Tester.h"
#include "linsolve.h"
#include "trisolve.h"

/* Function Definitions */

/*
 * Arguments    : const double A[10000]
 *                const double B[100]
 *                double C[100]
 * Return Type  : void
 */
void linsolve(const double A[10000], const double B[100], double C[100])
{
  memcpy(&C[0], &B[0], 100U * sizeof(double));
  trisolve(A, C);
}

/*
 * File trailer for linsolve.c
 *
 * [EOF]
 */
