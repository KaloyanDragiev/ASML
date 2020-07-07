/*
 * File: mrdivide_helper.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 25-Nov-2019 15:28:30
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "f2_auto_tester.h"
#include "mrdivide_helper.h"
#include "xtrsm.h"
#include "xgetrf.h"

/* Function Definitions */

/*
 * Arguments    : const double A[1000000]
 *                const double B[1000000]
 *                double y[1000000]
 * Return Type  : void
 */
void mrdivide_helper(const double A[1000000], const double B[1000000], double y
                     [1000000])
{
  static double b_A[1000000];
  int ipiv[1000];
  int info;
  int xi;
  int temp_tmp;
  double temp;
  int y_tmp;
  memcpy(&b_A[0], &B[0], 1000000U * sizeof(double));
  b_xgetrf(b_A, ipiv, &info);
  memcpy(&y[0], &A[0], 1000000U * sizeof(double));
  e_xtrsm(b_A, y);
  f_xtrsm(b_A, y);
  for (info = 998; info >= 0; info--) {
    if (ipiv[info] != info + 1) {
      for (xi = 0; xi < 1000; xi++) {
        temp_tmp = xi + 1000 * info;
        temp = y[temp_tmp];
        y_tmp = xi + 1000 * (ipiv[info] - 1);
        y[temp_tmp] = y[y_tmp];
        y[y_tmp] = temp;
      }
    }
  }
}

/*
 * File trailer for mrdivide_helper.c
 *
 * [EOF]
 */
