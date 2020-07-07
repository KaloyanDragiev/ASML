/*
 * File: matrix_divide_smart.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 25-Nov-2019 15:28:30
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "f2_auto_tester.h"
#include "matrix_divide_smart.h"
#include "f2_auto_tester_emxutil.h"
#include "cblas.h"

/* Function Definitions */

/*
 * function x = matrix_divide_smart(A, B, data_nrow, data_ncol)
 * Arguments    : double A[10000]
 *                double B[100]
 *                double data_nrow
 *                double data_ncol
 *                emxArray_real_T *x
 * Return Type  : void
 */
void matrix_divide_smart(double A[10000], double B[100], double data_nrow,
  double data_ncol, emxArray_real_T *x)
{
  int i0;

  /* 'matrix_divide_smart:2' coder.inline('never') */
  /* 'matrix_divide_smart:3' x = nan; */
  /* 'matrix_divide_smart:5' if coder.target('MATLAB') */
  /* 'matrix_divide_smart:7' else */
  /* 'matrix_divide_smart:8' coder.cinclude('cblas.h') */
  /*      x = A(1:data_nrow, 1:data_ncol) \ B(1:data_nrow); */
  /* 'matrix_divide_smart:12' CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /* 'matrix_divide_smart:13' CblasLeft = coder.opaque('CBLAS_SIDE', 'CblasLeft'); */
  /* 'matrix_divide_smart:14' CblasUpper = coder.opaque('CBLAS_UPLO', 'CblasUpper'); */
  /* 'matrix_divide_smart:15' CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans'); */
  /* 'matrix_divide_smart:16' CblasNonUnit = coder.opaque('CBLAS_DIAG', 'CblasNonUnit'); */
  /* 'matrix_divide_smart:18' CblasLower = coder.opaque('CBLAS_UPLO', 'CblasLower'); */
  /* 'matrix_divide_smart:19' CblasUnit = coder.opaque('CBLAS_DIAG', 'CblasUnit'); */
  /* 'matrix_divide_smart:21' CblasColMajor2 = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /* 'matrix_divide_smart:22' CblasLeft2 = coder.opaque('CBLAS_SIDE', 'CblasLeft'); */
  /* 'matrix_divide_smart:23' CblasNoTrans2 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans'); */
  /* 'matrix_divide_smart:25' coder.ceval('cblas_dtrsm', CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, data_nrow, 1, 1.0, coder.ref(A(1)), data_ncol, coder.ref(B(1)), data_nrow); */
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit,
              data_nrow, 1.0, 1.0, &A[0], data_ncol, &B[0], data_nrow);

  /* 'matrix_divide_smart:26' coder.ceval('cblas_dtrsm', CblasColMajor2, CblasLeft2, CblasLower, CblasNoTrans2, CblasUnit, data_nrow, 1, 1.0, coder.ref(A(1)), data_ncol, coder.ref(B(1)), data_nrow); */
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasUnit,
              data_nrow, 1.0, 1.0, &A[0], data_ncol, &B[0], data_nrow);

  /* 'matrix_divide_smart:27' x = B; */
  i0 = x->size[0];
  x->size[0] = 100;
  emxEnsureCapacity_real_T(x, i0);
  for (i0 = 0; i0 < 100; i0++) {
    x->data[i0] = B[i0];
  }
}

/*
 * File trailer for matrix_divide_smart.c
 *
 * [EOF]
 */
