/*
 * File: trisolve.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "trisolve.h"

/* Function Definitions */

/*
 * Arguments    : const double A[10000]
 *                double B[100]
 * Return Type  : void
 */
void b_trisolve(const double A[10000], double B[100])
{
  int k;
  int kAcol;
  int i;
  for (k = 99; k >= 0; k--) {
    kAcol = 100 * k;
    if (B[k] != 0.0) {
      B[k] /= A[k + kAcol];
      for (i = 0; i < k; i++) {
        B[i] -= B[k] * A[i + kAcol];
      }
    }
  }
}

/*
 * Arguments    : const double A[10000]
 *                double B[100]
 * Return Type  : void
 */
void trisolve(const double A[10000], double B[100])
{
  int k;
  int kAcol;
  int i13;
  int i;
  for (k = 0; k < 100; k++) {
    kAcol = 100 * k;
    if (B[k] != 0.0) {
      B[k] /= A[k + kAcol];
      i13 = k + 2;
      for (i = i13; i < 101; i++) {
        B[i - 1] -= B[k] * A[(i + kAcol) - 1];
      }
    }
  }
}

/*
 * File trailer for trisolve.c
 *
 * [EOF]
 */
