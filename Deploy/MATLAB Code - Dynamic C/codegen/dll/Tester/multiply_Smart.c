/*
 * File: multiply_Smart.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:45:17
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "multiply_Smart.h"
#include "Tester_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *A
 *                const emxArray_real_T *B
 *                double data_nrow
 *                double data_ncol
 *                emxArray_real_T *x
 * Return Type  : void
 */
void multiply_Smart(const emxArray_real_T *A, const emxArray_real_T *B, double
                    data_nrow, double data_ncol, emxArray_real_T *x)
{
  int loop_ub;
  int b_loop_ub;
  int c_loop_ub;
  emxArray_real_T *b_A;
  int i17;
  emxArray_real_T *b_B;
  int i18;

  /*       if coder.target('MATLAB') */
  if (1.0 > data_nrow) {
    loop_ub = 0;
  } else {
    loop_ub = (int)data_nrow;
  }

  if (1.0 > data_ncol) {
    b_loop_ub = 0;
    c_loop_ub = 0;
  } else {
    b_loop_ub = (int)data_ncol;
    c_loop_ub = (int)data_ncol;
  }

  emxInit_real_T(&b_A, 2);
  i17 = b_A->size[0] * b_A->size[1];
  b_A->size[0] = loop_ub;
  b_A->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(b_A, i17);
  for (i17 = 0; i17 < b_loop_ub; i17++) {
    for (i18 = 0; i18 < loop_ub; i18++) {
      b_A->data[i18 + b_A->size[0] * i17] = A->data[i18 + A->size[0] * i17];
    }
  }

  emxInit_real_T(&b_B, 2);
  i17 = b_B->size[0] * b_B->size[1];
  b_B->size[0] = 1;
  b_B->size[1] = c_loop_ub;
  emxEnsureCapacity_real_T(b_B, i17);
  for (i17 = 0; i17 < c_loop_ub; i17++) {
    b_B->data[i17] = B->data[i17];
  }

  i17 = x->size[0] * x->size[1];
  x->size[0] = loop_ub;
  x->size[1] = b_B->size[1];
  emxEnsureCapacity_real_T(x, i17);
  for (i17 = 0; i17 < loop_ub; i17++) {
    b_loop_ub = b_B->size[1];
    for (i18 = 0; i18 < b_loop_ub; i18++) {
      x->data[i17 + x->size[0] * i18] = b_A->data[i17] * b_B->data[i18];
    }
  }

  emxFree_real_T(&b_B);
  emxFree_real_T(&b_A);

  /*      else     */
  /*          coder.cinclude('cblas.h') */
  /*           */
  /*          scaling_Factor_A_B = 1.0; % Scaling factor for the product of matrices A and B. */
  /*          scaling_Factor_C = 0.0; % Scaling factor for matrix C. */
  /*          n_col_B_C = 1; % Number of columns in matrices B and C. */
  /*           */
  /*          CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /*          CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*          CblasNoTrans2 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*           */
  /*          coder.ceval('cblas_dgemm', CblasColMajor, CblasNoTrans, CblasNoTrans2, data_nrow, n_col_B_C, data_ncol, ... */
  /*              scaling_Factor_A_B, coder.ref(A(1)), data_nrow, coder.ref(B(1)), data_ncol, scaling_Factor_C, coder.ref(x(1)), data_nrow); */
  /*      end     */
  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * File trailer for multiply_Smart.c
 *
 * [EOF]
 */
