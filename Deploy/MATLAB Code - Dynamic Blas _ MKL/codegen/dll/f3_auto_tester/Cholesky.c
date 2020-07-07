/*
 * File: Cholesky.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 09-Jan-2020 11:21:18
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "f3_auto_tester.h"
#include "Cholesky.h"
#include "xpotrf.h"

/* Function Definitions */

/*
 * function L = Cholesky(A, data_nrow, data_ncol)
 * Arguments    : const double A[16192576]
 *                double L[10000]
 * Return Type  : void
 */
void Cholesky(const double A[16192576], double L[10000])
{
  int jmax;
  int j;
  int i;

  /* 'Cholesky:2' coder.inline('never'); */
  /* 'Cholesky:4' if coder.target('MATLAB') */
  /* 'Cholesky:6' else */
  /* 'Cholesky:7' L = chol(A(1:data_nrow,1:data_ncol), 'lower'); */
  for (jmax = 0; jmax < 100; jmax++) {
    memcpy(&L[jmax * 100], &A[jmax * 4024], 100U * sizeof(double));
  }

  jmax = xpotrf(L);
  if (jmax == 0) {
    jmax = 100;
  } else {
    jmax--;
  }

  for (j = 2; j <= jmax; j++) {
    for (i = 0; i <= j - 2; i++) {
      L[i + 100 * (j - 1)] = 0.0;
    }
  }

  /*          coder.cinclude('cblas.h') */
  /*       */
  /*          CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /*          CblasLeft = coder.opaque('CBLAS_SIDE', 'CblasLeft'); */
  /*          CblasUpper = coder.opaque('CBLAS_UPLO', 'CblasUpper'); */
  /*          CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans'); */
  /*          CblasNonUnit = coder.opaque('CBLAS_DIAG', 'CblasNonUnit');          */
  /*  scaling_Factor_A_X = -1.0. */
  /*  scaling_Factor_Y = 1.0; */
  /*  cblas_dgemv(CblasColMajor, CblasNoTrans, (int)(99 - j), (int)j, scaling_Factor_A_X, */
  /*                        &A[j + 1], (int)100, &A[j], (int)100, scaling_Factor_Y, &A[jj + 1], */
  /*                        (int)1); */
}

/*
 * File trailer for Cholesky.c
 *
 * [EOF]
 */
