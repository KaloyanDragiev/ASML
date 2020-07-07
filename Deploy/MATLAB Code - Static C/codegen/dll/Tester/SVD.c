/*
 * File: SVD.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Tester.h"
#include "SVD.h"
#include "svd2.h"
#include "anyNonFinite.h"

/* Function Definitions */

/*
 * Arguments    : const double A[65536]
 *                double u[65536]
 *                double S[65536]
 *                double V[65536]
 * Return Type  : void
 */
void SVD(const double A[65536], double u[65536], double S[65536], double V[65536])
{
  int i;
  double s[256];
  if (!anyNonFinite(A)) {
    svd(A, u, s, V);
  } else {
    for (i = 0; i < 65536; i++) {
      u[i] = rtNaN;
    }

    for (i = 0; i < 256; i++) {
      s[i] = rtNaN;
    }

    for (i = 0; i < 65536; i++) {
      V[i] = rtNaN;
    }
  }

  memset(&S[0], 0, sizeof(double) << 16);
  for (i = 0; i < 256; i++) {
    S[i + (i << 8)] = s[i];
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
 *                double u[262144]
 *                double S[262144]
 *                double V[262144]
 * Return Type  : void
 */
void b_SVD(const double A[262144], double u[262144], double S[262144], double V
           [262144])
{
  int i;
  double s[512];
  if (!b_anyNonFinite(A)) {
    b_svd(A, u, s, V);
  } else {
    for (i = 0; i < 262144; i++) {
      u[i] = rtNaN;
    }

    for (i = 0; i < 512; i++) {
      s[i] = rtNaN;
    }

    for (i = 0; i < 262144; i++) {
      V[i] = rtNaN;
    }
  }

  memset(&S[0], 0, sizeof(double) << 18);
  for (i = 0; i < 512; i++) {
    S[i + (i << 9)] = s[i];
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
 *                double u[1048576]
 *                double S[1048576]
 *                double V[1048576]
 * Return Type  : void
 */
void c_SVD(const double A[1048576], double u[1048576], double S[1048576], double
           V[1048576])
{
  int i;
  double s[1024];
  if (!c_anyNonFinite(A)) {
    c_svd(A, u, s, V);
  } else {
    for (i = 0; i < 1048576; i++) {
      u[i] = rtNaN;
    }

    for (i = 0; i < 1024; i++) {
      s[i] = rtNaN;
    }

    for (i = 0; i < 1048576; i++) {
      V[i] = rtNaN;
    }
  }

  memset(&S[0], 0, sizeof(double) << 20);
  for (i = 0; i < 1024; i++) {
    S[i + (i << 10)] = s[i];
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
 *                double u[4194304]
 *                double S[4194304]
 *                double V[4194304]
 * Return Type  : void
 */
void d_SVD(const double A[4194304], double u[4194304], double S[4194304], double
           V[4194304])
{
  int i;
  double s[2048];
  if (!d_anyNonFinite(A)) {
    d_svd(A, u, s, V);
  } else {
    for (i = 0; i < 4194304; i++) {
      u[i] = rtNaN;
    }

    for (i = 0; i < 2048; i++) {
      s[i] = rtNaN;
    }

    for (i = 0; i < 4194304; i++) {
      V[i] = rtNaN;
    }
  }

  memset(&S[0], 0, sizeof(double) << 22);
  for (i = 0; i < 2048; i++) {
    S[i + (i << 11)] = s[i];
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
 *                double u[16777216]
 *                double S[16777216]
 *                double V[16777216]
 * Return Type  : void
 */
void e_SVD(const double A[16777216], double u[16777216], double S[16777216],
           double V[16777216])
{
  int i;
  double s[4096];
  if (!e_anyNonFinite(A)) {
    e_svd(A, u, s, V);
  } else {
    for (i = 0; i < 16777216; i++) {
      u[i] = rtNaN;
    }

    for (i = 0; i < 4096; i++) {
      s[i] = rtNaN;
    }

    for (i = 0; i < 16777216; i++) {
      V[i] = rtNaN;
    }
  }

  memset(&S[0], 0, sizeof(double) << 24);
  for (i = 0; i < 4096; i++) {
    S[i + (i << 12)] = s[i];
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
 * File trailer for SVD.c
 *
 * [EOF]
 */
