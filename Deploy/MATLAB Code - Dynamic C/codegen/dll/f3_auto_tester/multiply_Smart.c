/*
 * File: multiply_Smart.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 09-Jan-2020 11:21:18
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "f3_auto_tester.h"
#include "multiply_Smart.h"
#include "f3_auto_tester_emxutil.h"
#include "cblas.h"

/* Function Definitions */

/*
 * function [x, A, B] = multiply_Smart(A, B, data_nrow, data_ncol)
 * Arguments    : double A[16192576]
 *                double B[4024]
 *                double data_nrow
 *                double data_ncol
 *                emxArray_real_T *x
 * Return Type  : void
 */
void multiply_Smart(double A[16192576], double B[4024], double data_nrow, double
                    data_ncol, emxArray_real_T *x)
{
  int i5;
  int loop_ub;

  /* 'multiply_Smart:2' coder.inline('never'); */
  /* 'multiply_Smart:3' x = ones(data_nrow, 1); */
  i5 = x->size[0];
  loop_ub = (int)data_nrow;
  x->size[0] = loop_ub;
  emxEnsureCapacity_real_T(x, i5);
  for (i5 = 0; i5 < loop_ub; i5++) {
    x->data[i5] = 1.0;
  }

  /* 'multiply_Smart:5' if coder.target('MATLAB') */
  /* 'multiply_Smart:7' else */
  /* 'multiply_Smart:8' coder.cinclude('cblas.h') */
  /* 'multiply_Smart:10' scaling_Factor_A_B = 1.0; */
  /*  Scaling factor for the product of matrices A and B. */
  /* 'multiply_Smart:11' scaling_Factor_C = 0.0; */
  /*  Scaling factor for matrix C. */
  /* 'multiply_Smart:12' n_col_B_C = 1; */
  /*  Number of columns in matrices B and C. */
  /* 'multiply_Smart:14' CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /* 'multiply_Smart:15' CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans'); */
  /* 'multiply_Smart:16' CblasNoTrans2 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans'); */
  /* 'multiply_Smart:18' coder.ceval('cblas_dgemm', CblasColMajor, CblasNoTrans, CblasNoTrans2, data_nrow, n_col_B_C, data_ncol, ... */
  /* 'multiply_Smart:19'             scaling_Factor_A_B, coder.ref(A(1)), data_nrow, coder.ref(B(1)), data_ncol, scaling_Factor_C, coder.ref(x(1)), data_nrow); */
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, data_nrow, 1.0,
              data_ncol, 1.0, &A[0], data_nrow, &B[0], data_ncol, 0.0, &x->data
              [0], data_nrow);

  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * File trailer for multiply_Smart.c
 *
 * [EOF]
 */
