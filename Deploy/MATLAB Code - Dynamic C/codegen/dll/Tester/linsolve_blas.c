/*
 * File: linsolve_blas.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:45:17
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "linsolve_blas.h"
#include "Tester_emxutil.h"
#include "trisolve.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *A
 *                const emxArray_real_T *B
 *                double data_nrow
 *                double data_ncol
 *                emxArray_real_T *result
 * Return Type  : void
 */
void b_linsolve_blas(const emxArray_real_T *A, const emxArray_real_T *B, double
                     data_nrow, double data_ncol, emxArray_real_T *result)
{
  int loop_ub;
  int b_loop_ub;
  int i10;
  int minszA;
  int i11;
  int j;
  emxArray_real_T *b_A;
  int i;

  /* Define variables */
  /*      if coder.target('MATLAB')      */
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

  if (1.0 > data_nrow) {
    i10 = 0;
  } else {
    i10 = (int)data_nrow;
  }

  if (loop_ub < b_loop_ub) {
    minszA = loop_ub;
  } else {
    minszA = b_loop_ub;
  }

  i11 = result->size[0] * result->size[1];
  result->size[0] = b_loop_ub;
  result->size[1] = i10;
  emxEnsureCapacity_real_T(result, i11);
  for (j = 0; j < i10; j++) {
    for (i = 0; i < minszA; i++) {
      result->data[i + result->size[0] * j] = B->data[j];
    }

    i11 = minszA + 1;
    for (i = i11; i <= b_loop_ub; i++) {
      result->data[(i + result->size[0] * j) - 1] = 0.0;
    }
  }

  emxInit_real_T(&b_A, 2);
  i10 = b_A->size[0] * b_A->size[1];
  b_A->size[0] = loop_ub;
  b_A->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(b_A, i10);
  for (i10 = 0; i10 < b_loop_ub; i10++) {
    for (i11 = 0; i11 < loop_ub; i11++) {
      b_A->data[i11 + b_A->size[0] * i10] = A->data[i11 + A->size[0] * i10];
    }
  }

  b_trisolve(b_A, result);

  /*      else */
  /*          coder.cinclude('cblas.h') */
  /*               */
  /*          result = B(1:data_nrow,1:data_ncol); % Assign result to B - Because B gets overwritten otherwise */
  /*          n_columns_B = 1; % The number of columns in matrix B. */
  /*          scaling_Factor_A = 1.0; % Scaling factor for matrix A. */
  /*           */
  /*          if opts.LT == 1  */
  /*              CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /*              CblasLeft = coder.opaque('CBLAS_SIDE', 'CblasLeft'); */
  /*              CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');     */
  /*              CblasLower = coder.opaque('CBLAS_UPLO', 'CblasLower'); */
  /*              CblasNonUnit = coder.opaque('CBLAS_DIAG', 'CblasNonUnit'); */
  /*   */
  /*              %forward */
  /*              coder.ceval('cblas_dtrsm', CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasNonUnit, ... */
  /*              data_nrow, n_columns_B, scaling_Factor_A, coder.ref(A(1)), data_ncol, coder.ref(result(1)), data_nrow); */
  /*          else             */
  /*              CblasColMajor1 = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /*              CblasLeft1 = coder.opaque('CBLAS_SIDE', 'CblasLeft'); */
  /*              CblasUpper1 = coder.opaque('CBLAS_UPLO', 'CblasUpper'); */
  /*              CblasNoTrans1 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans'); */
  /*              CblasNonUnit1 = coder.opaque('CBLAS_DIAG', 'CblasNonUnit'); */
  /*   */
  /*              %backward */
  /*              coder.ceval('cblas_dtrsm', CblasColMajor1, CblasLeft1, CblasUpper1, CblasNoTrans1, CblasNonUnit1, ... */
  /*              data_nrow, n_columns_B, scaling_Factor_A, coder.ref(A(1)), data_ncol, coder.ref(result(1)), data_nrow); */
  /*          end         */
  /*      end */
  /*    cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, */
  /*                (int)90, (int)1, 1.0, &A[0], (int)100, &B[0], (int)90); row =100; col = 90; */
  emxFree_real_T(&b_A);
}

/*
 * Arguments    : const emxArray_real_T *A
 *                const emxArray_real_T *B
 *                double data_nrow
 *                double data_ncol
 *                emxArray_real_T *result
 * Return Type  : void
 */
void linsolve_blas(const emxArray_real_T *A, const emxArray_real_T *B, double
                   data_nrow, double data_ncol, emxArray_real_T *result)
{
  int loop_ub;
  int b_loop_ub;
  int i6;
  int minszA;
  int i7;
  int j;
  emxArray_real_T *b_A;
  int i;

  /* Define variables */
  /*      if coder.target('MATLAB')      */
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

  if (1.0 > data_nrow) {
    i6 = 0;
  } else {
    i6 = (int)data_nrow;
  }

  if (loop_ub < b_loop_ub) {
    minszA = loop_ub;
  } else {
    minszA = b_loop_ub;
  }

  i7 = result->size[0] * result->size[1];
  result->size[0] = b_loop_ub;
  result->size[1] = i6;
  emxEnsureCapacity_real_T(result, i7);
  for (j = 0; j < i6; j++) {
    for (i = 0; i < minszA; i++) {
      result->data[i + result->size[0] * j] = B->data[j];
    }

    i7 = minszA + 1;
    for (i = i7; i <= b_loop_ub; i++) {
      result->data[(i + result->size[0] * j) - 1] = 0.0;
    }
  }

  emxInit_real_T(&b_A, 2);
  i6 = b_A->size[0] * b_A->size[1];
  b_A->size[0] = loop_ub;
  b_A->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(b_A, i6);
  for (i6 = 0; i6 < b_loop_ub; i6++) {
    for (i7 = 0; i7 < loop_ub; i7++) {
      b_A->data[i7 + b_A->size[0] * i6] = A->data[i7 + A->size[0] * i6];
    }
  }

  trisolve(b_A, result);

  /*      else */
  /*          coder.cinclude('cblas.h') */
  /*               */
  /*          result = B(1:data_nrow,1:data_ncol); % Assign result to B - Because B gets overwritten otherwise */
  /*          n_columns_B = 1; % The number of columns in matrix B. */
  /*          scaling_Factor_A = 1.0; % Scaling factor for matrix A. */
  /*           */
  /*          if opts.LT == 1  */
  /*              CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /*              CblasLeft = coder.opaque('CBLAS_SIDE', 'CblasLeft'); */
  /*              CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');     */
  /*              CblasLower = coder.opaque('CBLAS_UPLO', 'CblasLower'); */
  /*              CblasNonUnit = coder.opaque('CBLAS_DIAG', 'CblasNonUnit'); */
  /*   */
  /*              %forward */
  /*              coder.ceval('cblas_dtrsm', CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasNonUnit, ... */
  /*              data_nrow, n_columns_B, scaling_Factor_A, coder.ref(A(1)), data_ncol, coder.ref(result(1)), data_nrow); */
  /*          else             */
  /*              CblasColMajor1 = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /*              CblasLeft1 = coder.opaque('CBLAS_SIDE', 'CblasLeft'); */
  /*              CblasUpper1 = coder.opaque('CBLAS_UPLO', 'CblasUpper'); */
  /*              CblasNoTrans1 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans'); */
  /*              CblasNonUnit1 = coder.opaque('CBLAS_DIAG', 'CblasNonUnit'); */
  /*   */
  /*              %backward */
  /*              coder.ceval('cblas_dtrsm', CblasColMajor1, CblasLeft1, CblasUpper1, CblasNoTrans1, CblasNonUnit1, ... */
  /*              data_nrow, n_columns_B, scaling_Factor_A, coder.ref(A(1)), data_ncol, coder.ref(result(1)), data_nrow); */
  /*          end         */
  /*      end */
  /*    cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, */
  /*                (int)90, (int)1, 1.0, &A[0], (int)100, &B[0], (int)90); row =100; col = 90; */
  emxFree_real_T(&b_A);
}

/*
 * File trailer for linsolve_blas.c
 *
 * [EOF]
 */
