/*
 * File: xpotrf.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 09-Jan-2020 11:21:18
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "f3_auto_tester.h"
#include "xpotrf.h"
#include "cblas.h"

/* Type Definitions */

/* Function Definitions */

/*
 * Arguments    : double A[10000]
 * Return Type  : int
 */
int xpotrf(double A[10000])
{
  int info;
  int j;
  boolean_T exitg1;
  int jj;
  double ajj;
  int ix;
  int iy;
  int k;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 100)) {
    jj = j + j * 100;
    ajj = 0.0;
    if (j >= 1) {
      ix = j;
      iy = j;
      for (k = 0; k < j; k++) {
        ajj += A[ix] * A[iy];
        ix += 100;
        iy += 100;
      }
    }

    ajj = A[jj] - ajj;
    if (ajj > 0.0) {
      ajj = sqrt(ajj);
      A[jj] = ajj;
      if (j + 1 < 100) {
        iy = jj + 2;
        if (j >= 1) {
          cblas_dgemv(CblasColMajor, CblasNoTrans, (int)(99 - j), (int)j, -1.0,
                      &A[j + 1], (int)100, &A[j], (int)100, 1.0, &A[jj + 1],
                      (int)1);
        }

        ajj = 1.0 / ajj;
        ix = (jj - j) + 100;
        for (k = iy; k <= ix; k++) {
          A[k - 1] *= ajj;
        }
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
