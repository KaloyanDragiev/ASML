/*
 * File: xpotrf.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Tester.h"
#include "xpotrf.h"

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
  int jp1j;
  int i14;
  int iac;
  double c;
  int i15;
  int ia;
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
        k = j + 2;
        jp1j = jj + 2;
        if (j != 0) {
          ix = j;
          i14 = (j + ((j - 1) << 8)) + 2;
          for (iac = k; iac <= i14; iac += 256) {
            c = -A[ix];
            iy = jj + 1;
            i15 = (iac - j) + 254;
            for (ia = iac; ia <= i15; ia++) {
              A[iy] += A[ia - 1] * c;
              iy++;
            }

            ix += 256;
          }
        }

        ajj = 1.0 / ajj;
        i14 = (jj - j) + 256;
        for (k = jp1j; k <= i14; k++) {
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
  int ix;
  int iy;
  int k;
  int jp1j;
  int i23;
  int iac;
  double c;
  int i24;
  int ia;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 512)) {
    jj = j + (j << 9);
    ajj = 0.0;
    if (j >= 1) {
      ix = j;
      iy = j;
      for (k = 0; k < j; k++) {
        ajj += A[ix] * A[iy];
        ix += 512;
        iy += 512;
      }
    }

    ajj = A[jj] - ajj;
    if (ajj > 0.0) {
      ajj = sqrt(ajj);
      A[jj] = ajj;
      if (j + 1 < 512) {
        k = j + 2;
        jp1j = jj + 2;
        if (j != 0) {
          ix = j;
          i23 = (j + ((j - 1) << 9)) + 2;
          for (iac = k; iac <= i23; iac += 512) {
            c = -A[ix];
            iy = jj + 1;
            i24 = (iac - j) + 510;
            for (ia = iac; ia <= i24; ia++) {
              A[iy] += A[ia - 1] * c;
              iy++;
            }

            ix += 512;
          }
        }

        ajj = 1.0 / ajj;
        i23 = (jj - j) + 512;
        for (k = jp1j; k <= i23; k++) {
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
  int ix;
  int iy;
  int k;
  int jp1j;
  int i32;
  int iac;
  double c;
  int i33;
  int ia;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 1024)) {
    jj = j + (j << 10);
    ajj = 0.0;
    if (j >= 1) {
      ix = j;
      iy = j;
      for (k = 0; k < j; k++) {
        ajj += A[ix] * A[iy];
        ix += 1024;
        iy += 1024;
      }
    }

    ajj = A[jj] - ajj;
    if (ajj > 0.0) {
      ajj = sqrt(ajj);
      A[jj] = ajj;
      if (j + 1 < 1024) {
        k = j + 2;
        jp1j = jj + 2;
        if (j != 0) {
          ix = j;
          i32 = (j + ((j - 1) << 10)) + 2;
          for (iac = k; iac <= i32; iac += 1024) {
            c = -A[ix];
            iy = jj + 1;
            i33 = (iac - j) + 1022;
            for (ia = iac; ia <= i33; ia++) {
              A[iy] += A[ia - 1] * c;
              iy++;
            }

            ix += 1024;
          }
        }

        ajj = 1.0 / ajj;
        i32 = (jj - j) + 1024;
        for (k = jp1j; k <= i32; k++) {
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
  int ix;
  int iy;
  int k;
  int jp1j;
  int i41;
  int iac;
  double c;
  int i42;
  int ia;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 2048)) {
    jj = j + (j << 11);
    ajj = 0.0;
    if (j >= 1) {
      ix = j;
      iy = j;
      for (k = 0; k < j; k++) {
        ajj += A[ix] * A[iy];
        ix += 2048;
        iy += 2048;
      }
    }

    ajj = A[jj] - ajj;
    if (ajj > 0.0) {
      ajj = sqrt(ajj);
      A[jj] = ajj;
      if (j + 1 < 2048) {
        k = j + 2;
        jp1j = jj + 2;
        if (j != 0) {
          ix = j;
          i41 = (j + ((j - 1) << 11)) + 2;
          for (iac = k; iac <= i41; iac += 2048) {
            c = -A[ix];
            iy = jj + 1;
            i42 = (iac - j) + 2046;
            for (ia = iac; ia <= i42; ia++) {
              A[iy] += A[ia - 1] * c;
              iy++;
            }

            ix += 2048;
          }
        }

        ajj = 1.0 / ajj;
        i41 = (jj - j) + 2048;
        for (k = jp1j; k <= i41; k++) {
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
  int ix;
  int iy;
  int k;
  int jp1j;
  int i50;
  int iac;
  double c;
  int i51;
  int ia;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 4096)) {
    jj = j + (j << 12);
    ajj = 0.0;
    if (j >= 1) {
      ix = j;
      iy = j;
      for (k = 0; k < j; k++) {
        ajj += A[ix] * A[iy];
        ix += 4096;
        iy += 4096;
      }
    }

    ajj = A[jj] - ajj;
    if (ajj > 0.0) {
      ajj = sqrt(ajj);
      A[jj] = ajj;
      if (j + 1 < 4096) {
        k = j + 2;
        jp1j = jj + 2;
        if (j != 0) {
          ix = j;
          i50 = (j + ((j - 1) << 12)) + 2;
          for (iac = k; iac <= i50; iac += 4096) {
            c = -A[ix];
            iy = jj + 1;
            i51 = (iac - j) + 4094;
            for (ia = iac; ia <= i51; ia++) {
              A[iy] += A[ia - 1] * c;
              iy++;
            }

            ix += 4096;
          }
        }

        ajj = 1.0 / ajj;
        i50 = (jj - j) + 4096;
        for (k = jp1j; k <= i50; k++) {
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
  int jp1j;
  int i11;
  int iac;
  double c;
  int i12;
  int ia;
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
        k = j + 2;
        jp1j = jj + 2;
        if (j != 0) {
          ix = j;
          i11 = (j + 100 * (j - 1)) + 2;
          for (iac = k; iac <= i11; iac += 100) {
            c = -A[ix];
            iy = jj + 1;
            i12 = (iac - j) + 98;
            for (ia = iac; ia <= i12; ia++) {
              A[iy] += A[ia - 1] * c;
              iy++;
            }

            ix += 100;
          }
        }

        ajj = 1.0 / ajj;
        i11 = (jj - j) + 100;
        for (k = jp1j; k <= i11; k++) {
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
