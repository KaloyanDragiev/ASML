/*
 * File: xgetrf.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 25-Nov-2019 15:28:30
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "f2_auto_tester.h"
#include "xgetrf.h"
#include "xswap.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : double A[1000000]
 *                int ipiv[1000]
 *                int *info
 * Return Type  : void
 */
void b_xgetrf(double A[1000000], int ipiv[1000], int *info)
{
  int b;
  int j;
  int jj;
  int jp1j;
  int idxmax_t;
  int i;
  for (b = 0; b < 1000; b++) {
    ipiv[b] = 1 + b;
  }

  *info = 0;
  for (j = 0; j < 999; j++) {
    b = j * 1001;
    jj = j * 1001;
    jp1j = b + 2;
    idxmax_t = cblas_idamax((int)(1000 - j), &A[b], (int)1);
    if (A[jj + (int)idxmax_t] != 0.0) {
      if ((int)idxmax_t != 0) {
        ipiv[j] = (j + (int)idxmax_t) + 1;
        b_xswap(A, j + 1, (j + (int)idxmax_t) + 1);
      }

      b = (jj - j) + 1000;
      for (i = jp1j; i <= b; i++) {
        A[i - 1] /= A[jj];
      }
    } else {
      *info = j + 1;
    }

    cblas_dger(CblasColMajor, (int)(999 - j), (int)(999 - j), -1.0, &A[jj + 1],
               (int)1, &A[jj + 1000], (int)1000, &A[jj + 1001], (int)1000);
  }

  if ((*info == 0) && (!(A[999999] != 0.0))) {
    *info = 1000;
  }
}

/*
 * Arguments    : double A[10000]
 *                int ipiv[100]
 *                int *info
 * Return Type  : void
 */
void xgetrf(double A[10000], int ipiv[100], int *info)
{
  int n;
  int j;
  int ix;
  int jj;
  int jp1j;
  int a;
  double smax;
  int k;
  double s;
  for (n = 0; n < 100; n++) {
    ipiv[n] = 1 + n;
  }

  *info = 0;
  for (j = 0; j < 99; j++) {
    ix = j * 101;
    jj = j * 101;
    jp1j = ix + 2;
    n = 100 - j;
    a = 1;
    smax = fabs(A[ix]);
    for (k = 2; k <= n; k++) {
      ix++;
      s = fabs(A[ix]);
      if (s > smax) {
        a = k;
        smax = s;
      }
    }

    if (A[(jj + a) - 1] != 0.0) {
      if (a - 1 != 0) {
        ipiv[j] = j + a;
        xswap(A, j + 1, j + a);
      }

      n = (jj - j) + 100;
      for (a = jp1j; a <= n; a++) {
        A[a - 1] /= A[jj];
      }
    } else {
      *info = j + 1;
    }

    cblas_dger(CblasColMajor, (int)(99 - j), (int)(99 - j), -1.0, &A[jj + 1],
               (int)1, &A[jj + 100], (int)100, &A[jj + 101], (int)100);
  }

  if ((*info == 0) && (!(A[9999] != 0.0))) {
    *info = 100;
  }
}

/*
 * File trailer for xgetrf.c
 *
 * [EOF]
 */
