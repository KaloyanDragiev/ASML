/*
 * File: multiply_Smart.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:35:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "multiply_Smart.h"
#include "Tester_emxutil.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *A
 *                emxArray_real_T *B
 *                double data_nrow
 *                double data_ncol
 *                emxArray_real_T *x
 * Return Type  : void
 */
void multiply_Smart(emxArray_real_T *A, emxArray_real_T *B, double data_nrow,
                    double data_ncol, emxArray_real_T *x)
{
  int i7;
  int loop_ub;
  i7 = x->size[0];
  loop_ub = (int)data_nrow;
  x->size[0] = loop_ub;
  emxEnsureCapacity_real_T(x, i7);
  for (i7 = 0; i7 < loop_ub; i7++) {
    x->data[i7] = 1.0;
  }

  /*  Scaling factor for the product of matrices A and B. */
  /*  Scaling factor for matrix C. */
  /*  Number of columns in matrices B and C. */
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, data_nrow, 1.0,
              data_ncol, 1.0, &A->data[0], data_nrow, &B->data[0], data_ncol,
              0.0, &x->data[0], data_nrow);

  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * File trailer for multiply_Smart.c
 *
 * [EOF]
 */
