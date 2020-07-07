/*
 * File: Cholesky.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Tester.h"
#include "Cholesky.h"
#include "xpotrf.h"

/* Function Definitions */

/*
 * Arguments    : const double A[65536]
 *                double L[10000]
 * Return Type  : void
 */
void Cholesky(const double A[65536], double L[10000])
{
  int jmax;
  int j;
  int i;
  for (jmax = 0; jmax < 100; jmax++) {
    memcpy(&L[jmax * 100], &A[jmax << 8], 100U * sizeof(double));
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
 * Arguments    : const double A[262144]
 *                double L[10000]
 * Return Type  : void
 */
void b_Cholesky(const double A[262144], double L[10000])
{
  int jmax;
  int j;
  int i;
  for (jmax = 0; jmax < 100; jmax++) {
    memcpy(&L[jmax * 100], &A[jmax << 9], 100U * sizeof(double));
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
 * Arguments    : const double A[1048576]
 *                double L[10000]
 * Return Type  : void
 */
void c_Cholesky(const double A[1048576], double L[10000])
{
  int jmax;
  int j;
  int i;
  for (jmax = 0; jmax < 100; jmax++) {
    memcpy(&L[jmax * 100], &A[jmax << 10], 100U * sizeof(double));
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
 * Arguments    : const double A[4194304]
 *                double L[10000]
 * Return Type  : void
 */
void d_Cholesky(const double A[4194304], double L[10000])
{
  int jmax;
  int j;
  int i;
  for (jmax = 0; jmax < 100; jmax++) {
    memcpy(&L[jmax * 100], &A[jmax << 11], 100U * sizeof(double));
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
 * Arguments    : const double A[16777216]
 *                double L[10000]
 * Return Type  : void
 */
void e_Cholesky(const double A[16777216], double L[10000])
{
  int jmax;
  int j;
  int i;
  for (jmax = 0; jmax < 100; jmax++) {
    memcpy(&L[jmax * 100], &A[jmax << 12], 100U * sizeof(double));
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
