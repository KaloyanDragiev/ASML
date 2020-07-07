/*
 * File: linsolve_blas.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "linsolve_blas.h"
#include "Tester_emxutil.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : double A[10000]
 *                const emxArray_real_T *B
 *                emxArray_real_T *result
 * Return Type  : void
 */
void b_linsolve_blas(double A[10000], const emxArray_real_T *B, emxArray_real_T *
                     result)
{
  int i2;
  int i3;

  /* Define variables */
  i2 = result->size[0] * result->size[1];
  result->size[0] = 100;
  result->size[1] = 100;
  emxEnsureCapacity_real_T(result, i2);
  for (i2 = 0; i2 < 100; i2++) {
    for (i3 = 0; i3 < 100; i3++) {
      result->data[i3 + result->size[0] * i2] = B->data[i3 + B->size[0] * i2];
    }
  }

  /*  Assign result to B - Because B gets overwritten otherwise */
  /*  The number of columns in matrix B. */
  /*  Scaling factor for matrix A. */
  /* backward */
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit,
              100.0, 1.0, 1.0, &A[0], 100.0, &result->data[0], 100.0);

  /*    cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, */
  /*                (int)90, (int)1, 1.0, &A[0], (int)100, &B[0], (int)90); row =100; col = 90; */
}

/*
 * Arguments    : double A[10000]
 *                const double B[512]
 *                emxArray_real_T *result
 * Return Type  : void
 */
void c_linsolve_blas(double A[10000], const double B[512], emxArray_real_T
                     *result)
{
  int i5;
  int i6;

  /* Define variables */
  i5 = result->size[0] * result->size[1];
  result->size[0] = 100;
  result->size[1] = 100;
  emxEnsureCapacity_real_T(result, i5);
  for (i5 = 0; i5 < 100; i5++) {
    for (i6 = 0; i6 < 100; i6++) {
      result->data[i6 + result->size[0] * i5] = B[i6];
    }
  }

  /*  Assign result to B - Because B gets overwritten otherwise */
  /*  The number of columns in matrix B. */
  /*  Scaling factor for matrix A. */
  /* forward */
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasNonUnit,
              100.0, 1.0, 1.0, &A[0], 100.0, &result->data[0], 100.0);

  /*    cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, */
  /*                (int)90, (int)1, 1.0, &A[0], (int)100, &B[0], (int)90); row =100; col = 90; */
}

/*
 * Arguments    : double A[10000]
 *                const double B[1024]
 *                emxArray_real_T *result
 * Return Type  : void
 */
void d_linsolve_blas(double A[10000], const double B[1024], emxArray_real_T
                     *result)
{
  int i7;
  int i8;

  /* Define variables */
  i7 = result->size[0] * result->size[1];
  result->size[0] = 100;
  result->size[1] = 100;
  emxEnsureCapacity_real_T(result, i7);
  for (i7 = 0; i7 < 100; i7++) {
    for (i8 = 0; i8 < 100; i8++) {
      result->data[i8 + result->size[0] * i7] = B[i8];
    }
  }

  /*  Assign result to B - Because B gets overwritten otherwise */
  /*  The number of columns in matrix B. */
  /*  Scaling factor for matrix A. */
  /* forward */
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasNonUnit,
              100.0, 1.0, 1.0, &A[0], 100.0, &result->data[0], 100.0);

  /*    cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, */
  /*                (int)90, (int)1, 1.0, &A[0], (int)100, &B[0], (int)90); row =100; col = 90; */
}

/*
 * Arguments    : double A[10000]
 *                const double B[2048]
 *                emxArray_real_T *result
 * Return Type  : void
 */
void e_linsolve_blas(double A[10000], const double B[2048], emxArray_real_T
                     *result)
{
  int i9;
  int i10;

  /* Define variables */
  i9 = result->size[0] * result->size[1];
  result->size[0] = 100;
  result->size[1] = 100;
  emxEnsureCapacity_real_T(result, i9);
  for (i9 = 0; i9 < 100; i9++) {
    for (i10 = 0; i10 < 100; i10++) {
      result->data[i10 + result->size[0] * i9] = B[i10];
    }
  }

  /*  Assign result to B - Because B gets overwritten otherwise */
  /*  The number of columns in matrix B. */
  /*  Scaling factor for matrix A. */
  /* forward */
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasNonUnit,
              100.0, 1.0, 1.0, &A[0], 100.0, &result->data[0], 100.0);

  /*    cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, */
  /*                (int)90, (int)1, 1.0, &A[0], (int)100, &B[0], (int)90); row =100; col = 90; */
}

/*
 * Arguments    : double A[10000]
 *                const double B[4096]
 *                emxArray_real_T *result
 * Return Type  : void
 */
void f_linsolve_blas(double A[10000], const double B[4096], emxArray_real_T
                     *result)
{
  int i11;
  int i12;

  /* Define variables */
  i11 = result->size[0] * result->size[1];
  result->size[0] = 100;
  result->size[1] = 100;
  emxEnsureCapacity_real_T(result, i11);
  for (i11 = 0; i11 < 100; i11++) {
    for (i12 = 0; i12 < 100; i12++) {
      result->data[i12 + result->size[0] * i11] = B[i12];
    }
  }

  /*  Assign result to B - Because B gets overwritten otherwise */
  /*  The number of columns in matrix B. */
  /*  Scaling factor for matrix A. */
  /* forward */
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasNonUnit,
              100.0, 1.0, 1.0, &A[0], 100.0, &result->data[0], 100.0);

  /*    cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, */
  /*                (int)90, (int)1, 1.0, &A[0], (int)100, &B[0], (int)90); row =100; col = 90; */
}

/*
 * Arguments    : double A[10000]
 *                const double B[256]
 *                emxArray_real_T *result
 * Return Type  : void
 */
void linsolve_blas(double A[10000], const double B[256], emxArray_real_T *result)
{
  int i0;
  int i1;

  /* Define variables */
  i0 = result->size[0] * result->size[1];
  result->size[0] = 100;
  result->size[1] = 100;
  emxEnsureCapacity_real_T(result, i0);
  for (i0 = 0; i0 < 100; i0++) {
    for (i1 = 0; i1 < 100; i1++) {
      result->data[i1 + result->size[0] * i0] = B[i1];
    }
  }

  /*  Assign result to B - Because B gets overwritten otherwise */
  /*  The number of columns in matrix B. */
  /*  Scaling factor for matrix A. */
  /* forward */
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasNonUnit,
              100.0, 1.0, 1.0, &A[0], 100.0, &result->data[0], 100.0);

  /*    cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, */
  /*                (int)90, (int)1, 1.0, &A[0], (int)100, &B[0], (int)90); row =100; col = 90; */
}

/*
 * File trailer for linsolve_blas.c
 *
 * [EOF]
 */
