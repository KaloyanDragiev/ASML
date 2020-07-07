/*
 * File: xpotrf.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 25-Nov-2019 15:28:30
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "f2_auto_tester.h"
#include "xpotrf.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : double A[1000000]
 * Return Type  : int
 */
int xpotrf(double A[1000000])
{
  int info;
  int colj;
  int j;
  boolean_T exitg1;
  int jj;
  double ajj;
  info = 0;
  colj = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 1000)) {
    jj = colj + j;
    if (j < 1) {
      ajj = 0.0;
    } else {
      ajj = cblas_ddot((int)j, &A[colj], (int)1, &A[colj], (int)1);
    }

    ajj = A[jj] - ajj;
    if (ajj > 0.0) {
      ajj = sqrt(ajj);
      A[jj] = ajj;
      if (j + 1 < 1000) {
        if (j >= 1) {
          cblas_dgemv(CblasColMajor, CblasTrans, (int)j, (int)(999 - j), -1.0,
                      &A[colj + 1000], (int)1000, &A[colj], (int)1, 1.0, &A[jj +
                      1000], (int)1000);
        }

        cblas_dscal((int)(999 - j), 1.0 / ajj, &A[jj + 1000], (int)1000);
        colj += 1000;
      }

      j++;
    } else {
      A[jj] = ajj;
      info = j + 1;
      exitg1 = true;
    }
  }

  return info;
}

/*
 * File trailer for xpotrf.c
 *
 * [EOF]
 */
