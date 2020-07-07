/*
 * File: linsolve_blas.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "linsolve_blas.h"
#include "Tester_emxutil.h"
#include "trisolve.h"
#include "linsolve.h"

/* Function Definitions */

/*
 * Arguments    : const double A[10000]
 *                const emxArray_real_T *B
 *                emxArray_real_T *result
 * Return Type  : void
 */
void b_linsolve_blas(const double A[10000], const emxArray_real_T *B,
                     emxArray_real_T *result)
{
  int i;
  double C[100];

  /* Define variables */
  /*      if coder.target('MATLAB')      */
  for (i = 0; i < 100; i++) {
    C[i] = B->data[i];
  }

  b_trisolve(A, C);
  i = result->size[0];
  result->size[0] = 100;
  emxEnsureCapacity_real_T(result, i);
  for (i = 0; i < 100; i++) {
    result->data[i] = C[i];
  }

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
}

/*
 * Arguments    : const double A[10000]
 *                const double B[512]
 *                emxArray_real_T *result
 * Return Type  : void
 */
void c_linsolve_blas(const double A[10000], const double B[512], emxArray_real_T
                     *result)
{
  double dv1[100];
  int i4;

  /* Define variables */
  /*      if coder.target('MATLAB')      */
  linsolve(A, *(double (*)[100])&B[0], dv1);
  i4 = result->size[0];
  result->size[0] = 100;
  emxEnsureCapacity_real_T(result, i4);
  for (i4 = 0; i4 < 100; i4++) {
    result->data[i4] = dv1[i4];
  }

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
}

/*
 * Arguments    : const double A[10000]
 *                const double B[1024]
 *                emxArray_real_T *result
 * Return Type  : void
 */
void d_linsolve_blas(const double A[10000], const double B[1024],
                     emxArray_real_T *result)
{
  double dv2[100];
  int i6;

  /* Define variables */
  /*      if coder.target('MATLAB')      */
  linsolve(A, *(double (*)[100])&B[0], dv2);
  i6 = result->size[0];
  result->size[0] = 100;
  emxEnsureCapacity_real_T(result, i6);
  for (i6 = 0; i6 < 100; i6++) {
    result->data[i6] = dv2[i6];
  }

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
}

/*
 * Arguments    : const double A[10000]
 *                const double B[2048]
 *                emxArray_real_T *result
 * Return Type  : void
 */
void e_linsolve_blas(const double A[10000], const double B[2048],
                     emxArray_real_T *result)
{
  double dv3[100];
  int i8;

  /* Define variables */
  /*      if coder.target('MATLAB')      */
  linsolve(A, *(double (*)[100])&B[0], dv3);
  i8 = result->size[0];
  result->size[0] = 100;
  emxEnsureCapacity_real_T(result, i8);
  for (i8 = 0; i8 < 100; i8++) {
    result->data[i8] = dv3[i8];
  }

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
}

/*
 * Arguments    : const double A[10000]
 *                const double B[4096]
 *                emxArray_real_T *result
 * Return Type  : void
 */
void f_linsolve_blas(const double A[10000], const double B[4096],
                     emxArray_real_T *result)
{
  double dv4[100];
  int i10;

  /* Define variables */
  /*      if coder.target('MATLAB')      */
  linsolve(A, *(double (*)[100])&B[0], dv4);
  i10 = result->size[0];
  result->size[0] = 100;
  emxEnsureCapacity_real_T(result, i10);
  for (i10 = 0; i10 < 100; i10++) {
    result->data[i10] = dv4[i10];
  }

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
}

/*
 * Arguments    : const double A[10000]
 *                const double B[256]
 *                emxArray_real_T *result
 * Return Type  : void
 */
void linsolve_blas(const double A[10000], const double B[256], emxArray_real_T
                   *result)
{
  double dv0[100];
  int i1;

  /* Define variables */
  /*      if coder.target('MATLAB')      */
  linsolve(A, *(double (*)[100])&B[0], dv0);
  i1 = result->size[0];
  result->size[0] = 100;
  emxEnsureCapacity_real_T(result, i1);
  for (i1 = 0; i1 < 100; i1++) {
    result->data[i1] = dv0[i1];
  }

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
}

/*
 * File trailer for linsolve_blas.c
 *
 * [EOF]
 */
