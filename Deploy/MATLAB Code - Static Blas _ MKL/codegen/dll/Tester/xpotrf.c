/*
 * File: xpotrf.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Tester.h"
#include "xpotrf.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : double A[65536]
 * Return Type  : int
 */
int b_xpotrf(double A[65536])
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
  while ((!exitg1) && (j < 256)) {
    jj = j + (j << 8);
    ajj = 0.0;
    if (j >= 1) {
      ix = j;
      iy = j;
      for (k = 0; k < j; k++) {
        ajj += A[ix] * A[iy];
        ix += 256;
        iy += 256;
      }
    }

    ajj = A[jj] - ajj;
    if (ajj > 0.0) {
      ajj = sqrt(ajj);
      A[jj] = ajj;
      if (j + 1 < 256) {
        iy = jj + 2;
        if (j >= 1) {
          cblas_dgemv(CblasColMajor, CblasNoTrans, (int)(255 - j), (int)j, -1.0,
                      &A[j + 1], (int)256, &A[j], (int)256, 1.0, &A[jj + 1],
                      (int)1);
        }

        ajj = 1.0 / ajj;
        ix = (jj - j) + 256;
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
 * Arguments    : double A[262144]
 * Return Type  : int
 */
int c_xpotrf(double A[262144])
{
  int info;
  int j;
  boolean_T exitg1;
  int jj;
  double ajj;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 512)) {
    jj = j + (j << 9);
    if (j < 1) {
      ajj = 0.0;
    } else {
      ajj = cblas_ddot((int)j, &A[j], (int)512, &A[j], (int)512);
    }

    ajj = A[jj] - ajj;
    if (ajj > 0.0) {
      ajj = sqrt(ajj);
      A[jj] = ajj;
      if (j + 1 < 512) {
        if (j >= 1) {
          cblas_dgemv(CblasColMajor, CblasNoTrans, (int)(511 - j), (int)j, -1.0,
                      &A[j + 1], (int)512, &A[j], (int)512, 1.0, &A[jj + 1],
                      (int)1);
        }

        cblas_dscal((int)(511 - j), 1.0 / ajj, &A[jj + 1], (int)1);
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
 * Arguments    : double A[1048576]
 * Return Type  : int
 */
int d_xpotrf(double A[1048576])
{
  int info;
  int j;
  boolean_T exitg1;
  int jj;
  double ajj;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 1024)) {
    jj = j + (j << 10);
    if (j < 1) {
      ajj = 0.0;
    } else {
      ajj = cblas_ddot((int)j, &A[j], (int)1024, &A[j], (int)1024);
    }

    ajj = A[jj] - ajj;
    if (ajj > 0.0) {
      ajj = sqrt(ajj);
      A[jj] = ajj;
      if (j + 1 < 1024) {
        if (j >= 1) {
          cblas_dgemv(CblasColMajor, CblasNoTrans, (int)(1023 - j), (int)j, -1.0,
                      &A[j + 1], (int)1024, &A[j], (int)1024, 1.0, &A[jj + 1],
                      (int)1);
        }

        cblas_dscal((int)(1023 - j), 1.0 / ajj, &A[jj + 1], (int)1);
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
 * Arguments    : double A[4194304]
 * Return Type  : int
 */
int e_xpotrf(double A[4194304])
{
  int info;
  int j;
  boolean_T exitg1;
  int jj;
  double ajj;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 2048)) {
    jj = j + (j << 11);
    if (j < 1) {
      ajj = 0.0;
    } else {
      ajj = cblas_ddot((int)j, &A[j], (int)2048, &A[j], (int)2048);
    }

    ajj = A[jj] - ajj;
    if (ajj > 0.0) {
      ajj = sqrt(ajj);
      A[jj] = ajj;
      if (j + 1 < 2048) {
        if (j >= 1) {
          cblas_dgemv(CblasColMajor, CblasNoTrans, (int)(2047 - j), (int)j, -1.0,
                      &A[j + 1], (int)2048, &A[j], (int)2048, 1.0, &A[jj + 1],
                      (int)1);
        }

        cblas_dscal((int)(2047 - j), 1.0 / ajj, &A[jj + 1], (int)1);
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
 * Arguments    : double A[16777216]
 * Return Type  : int
 */
int f_xpotrf(double A[16777216])
{
  int info;
  int j;
  boolean_T exitg1;
  int jj;
  double ajj;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 4096)) {
    jj = j + (j << 12);
    if (j < 1) {
      ajj = 0.0;
    } else {
      ajj = cblas_ddot((int)j, &A[j], (int)4096, &A[j], (int)4096);
    }

    ajj = A[jj] - ajj;
    if (ajj > 0.0) {
      ajj = sqrt(ajj);
      A[jj] = ajj;
      if (j + 1 < 4096) {
        if (j >= 1) {
          cblas_dgemv(CblasColMajor, CblasNoTrans, (int)(4095 - j), (int)j, -1.0,
                      &A[j + 1], (int)4096, &A[j], (int)4096, 1.0, &A[jj + 1],
                      (int)1);
        }

        cblas_dscal((int)(4095 - j), 1.0 / ajj, &A[jj + 1], (int)1);
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
