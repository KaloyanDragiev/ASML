/*
 * File: linsolve_blas.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 09-Jan-2020 11:21:18
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "f3_auto_tester.h"
#include "linsolve_blas.h"
#include "f3_auto_tester_emxutil.h"
#include "cblas.h"

/* Function Definitions */

/*
 * function [result, A, B] = linsolve_blas(A, B, data_nrow, data_ncol, opts)
 * Arguments    : double A[10000]
 *                const emxArray_real_T *B
 *                double data_nrow
 *                double data_ncol
 *                boolean_T opts_LT
 *                emxArray_real_T *result
 * Return Type  : void
 */
void b_linsolve_blas(double A[10000], const emxArray_real_T *B, double data_nrow,
                     double data_ncol, boolean_T opts_LT, emxArray_real_T
                     *result)
{
  int loop_ub;
  int b_loop_ub;
  int i3;
  int i4;

  /* 'linsolve_blas:2' coder.inline('never'); */
  /* Define variables */
  /* 'linsolve_blas:5' result = nan; */
  /* 'linsolve_blas:7' if coder.target('MATLAB') */
  /* 'linsolve_blas:9' else */
  /* 'linsolve_blas:10' coder.cinclude('cblas.h') */
  /* 'linsolve_blas:12' result = B(1:data_nrow,1:data_ncol); */
  if (1.0 > data_nrow) {
    loop_ub = 0;
  } else {
    loop_ub = (int)data_nrow;
  }

  if (1.0 > data_ncol) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = (int)data_ncol;
  }

  i3 = result->size[0] * result->size[1];
  result->size[0] = loop_ub;
  result->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(result, i3);
  for (i3 = 0; i3 < b_loop_ub; i3++) {
    for (i4 = 0; i4 < loop_ub; i4++) {
      result->data[i4 + result->size[0] * i3] = B->data[i4 + B->size[0] * i3];
    }
  }

  /*  Assign result to B - Because B gets overwritten otherwise */
  /* 'linsolve_blas:13' n_columns_B = 1; */
  /*  The number of columns in matrix B. */
  /* 'linsolve_blas:14' scaling_Factor_A = 1.0; */
  /*  Scaling factor for matrix A. */
  /* 'linsolve_blas:16' if opts.LT == 1 */
  if (opts_LT) {
    /* 'linsolve_blas:17' CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
    /* 'linsolve_blas:18' CblasLeft = coder.opaque('CBLAS_SIDE', 'CblasLeft'); */
    /* 'linsolve_blas:19' CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans'); */
    /* 'linsolve_blas:20' CblasLower = coder.opaque('CBLAS_UPLO', 'CblasLower'); */
    /* 'linsolve_blas:21' CblasNonUnit = coder.opaque('CBLAS_DIAG', 'CblasNonUnit'); */
    /* forward */
    /* 'linsolve_blas:24' coder.ceval('cblas_dtrsm', CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasNonUnit, ... */
    /* 'linsolve_blas:25'             data_nrow, n_columns_B, scaling_Factor_A, coder.ref(A(1)), data_ncol, coder.ref(result(1)), data_nrow); */
    cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasNonUnit,
                data_nrow, 1.0, 1.0, &A[0], data_ncol, &result->data[0],
                data_nrow);
  } else {
    /* 'linsolve_blas:26' else */
    /* 'linsolve_blas:27' CblasColMajor1 = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
    /* 'linsolve_blas:28' CblasLeft1 = coder.opaque('CBLAS_SIDE', 'CblasLeft'); */
    /* 'linsolve_blas:29' CblasUpper1 = coder.opaque('CBLAS_UPLO', 'CblasUpper'); */
    /* 'linsolve_blas:30' CblasNoTrans1 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans'); */
    /* 'linsolve_blas:31' CblasNonUnit1 = coder.opaque('CBLAS_DIAG', 'CblasNonUnit'); */
    /* backward */
    /* 'linsolve_blas:34' coder.ceval('cblas_dtrsm', CblasColMajor1, CblasLeft1, CblasUpper1, CblasNoTrans1, CblasNonUnit1, ... */
    /* 'linsolve_blas:35'             data_nrow, n_columns_B, scaling_Factor_A, coder.ref(A(1)), data_ncol, coder.ref(result(1)), data_nrow); */
    cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit,
                data_nrow, 1.0, 1.0, &A[0], data_ncol, &result->data[0],
                data_nrow);
  }

  /*    cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, */
  /*                (int)90, (int)1, 1.0, &A[0], (int)100, &B[0], (int)90); row =100; col = 90; */
}

/*
 * function [result, A, B] = linsolve_blas(A, B, data_nrow, data_ncol, opts)
 * Arguments    : double A[10000]
 *                const double B[4024]
 *                double data_nrow
 *                double data_ncol
 *                boolean_T opts_LT
 *                emxArray_real_T *result
 * Return Type  : void
 */
void linsolve_blas(double A[10000], const double B[4024], double data_nrow,
                   double data_ncol, boolean_T opts_LT, emxArray_real_T *result)
{
  int loop_ub;
  int b_loop_ub;
  int i1;
  int i2;

  /* 'linsolve_blas:2' coder.inline('never'); */
  /* Define variables */
  /* 'linsolve_blas:5' result = nan; */
  /* 'linsolve_blas:7' if coder.target('MATLAB') */
  /* 'linsolve_blas:9' else */
  /* 'linsolve_blas:10' coder.cinclude('cblas.h') */
  /* 'linsolve_blas:12' result = B(1:data_nrow,1:data_ncol); */
  if (1.0 > data_nrow) {
    loop_ub = 0;
  } else {
    loop_ub = (int)data_nrow;
  }

  if (1.0 > data_ncol) {
    b_loop_ub = -1;
  } else {
    b_loop_ub = 0;
  }

  i1 = result->size[0] * result->size[1];
  result->size[0] = loop_ub;
  result->size[1] = b_loop_ub + 1;
  emxEnsureCapacity_real_T(result, i1);
  for (i1 = 0; i1 <= b_loop_ub; i1++) {
    for (i2 = 0; i2 < loop_ub; i2++) {
      result->data[i2] = B[i2];
    }
  }

  /*  Assign result to B - Because B gets overwritten otherwise */
  /* 'linsolve_blas:13' n_columns_B = 1; */
  /*  The number of columns in matrix B. */
  /* 'linsolve_blas:14' scaling_Factor_A = 1.0; */
  /*  Scaling factor for matrix A. */
  /* 'linsolve_blas:16' if opts.LT == 1 */
  if (opts_LT) {
    /* 'linsolve_blas:17' CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
    /* 'linsolve_blas:18' CblasLeft = coder.opaque('CBLAS_SIDE', 'CblasLeft'); */
    /* 'linsolve_blas:19' CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans'); */
    /* 'linsolve_blas:20' CblasLower = coder.opaque('CBLAS_UPLO', 'CblasLower'); */
    /* 'linsolve_blas:21' CblasNonUnit = coder.opaque('CBLAS_DIAG', 'CblasNonUnit'); */
    /* forward */
    /* 'linsolve_blas:24' coder.ceval('cblas_dtrsm', CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasNonUnit, ... */
    /* 'linsolve_blas:25'             data_nrow, n_columns_B, scaling_Factor_A, coder.ref(A(1)), data_ncol, coder.ref(result(1)), data_nrow); */
    cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasNonUnit,
                data_nrow, 1.0, 1.0, &A[0], data_ncol, &result->data[0],
                data_nrow);
  } else {
    /* 'linsolve_blas:26' else */
    /* 'linsolve_blas:27' CblasColMajor1 = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
    /* 'linsolve_blas:28' CblasLeft1 = coder.opaque('CBLAS_SIDE', 'CblasLeft'); */
    /* 'linsolve_blas:29' CblasUpper1 = coder.opaque('CBLAS_UPLO', 'CblasUpper'); */
    /* 'linsolve_blas:30' CblasNoTrans1 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans'); */
    /* 'linsolve_blas:31' CblasNonUnit1 = coder.opaque('CBLAS_DIAG', 'CblasNonUnit'); */
    /* backward */
    /* 'linsolve_blas:34' coder.ceval('cblas_dtrsm', CblasColMajor1, CblasLeft1, CblasUpper1, CblasNoTrans1, CblasNonUnit1, ... */
    /* 'linsolve_blas:35'             data_nrow, n_columns_B, scaling_Factor_A, coder.ref(A(1)), data_ncol, coder.ref(result(1)), data_nrow); */
    cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit,
                data_nrow, 1.0, 1.0, &A[0], data_ncol, &result->data[0],
                data_nrow);
  }

  /*    cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, */
  /*                (int)90, (int)1, 1.0, &A[0], (int)100, &B[0], (int)90); row =100; col = 90; */
}

/*
 * File trailer for linsolve_blas.c
 *
 * [EOF]
 */
