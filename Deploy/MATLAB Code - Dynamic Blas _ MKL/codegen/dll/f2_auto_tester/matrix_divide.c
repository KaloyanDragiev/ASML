/*
 * File: matrix_divide.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 25-Nov-2019 15:28:30
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "f2_auto_tester.h"
#include "matrix_divide.h"
#include "xtrsm.h"
#include "xgetrf.h"

/* Function Definitions */

/*
 * function x = matrix_divide(A, b)
 * Arguments    : const double A[10000]
 *                double b[100]
 * Return Type  : void
 */
void matrix_divide(const double A[10000], double b[100])
{
  double b_A[10000];
  int ipiv[100];
  int info;
  double temp;

  /* 'matrix_divide:2' coder.inline('never')  */
  /* 'matrix_divide:3' x = A \ b; */
  memcpy(&b_A[0], &A[0], 10000U * sizeof(double));
  xgetrf(b_A, ipiv, &info);
  for (info = 0; info < 99; info++) {
    if (ipiv[info] != info + 1) {
      temp = b[info];
      b[info] = b[ipiv[info] - 1];
      b[ipiv[info] - 1] = temp;
    }
  }

  xtrsm(b_A, b);
  b_xtrsm(b_A, b);
}

/*
 * File trailer for matrix_divide.c
 *
 * [EOF]
 */
