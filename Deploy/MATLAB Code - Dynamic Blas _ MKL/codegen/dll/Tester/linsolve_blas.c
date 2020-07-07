/*
 * File: linsolve_blas.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:35:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "linsolve_blas.h"
#include "Tester_emxutil.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *A
 *                const emxArray_real_T *B
 *                double data_nrow
 *                double data_ncol
 *                boolean_T opts_LT
 *                emxArray_real_T *result
 * Return Type  : void
 */
void linsolve_blas(emxArray_real_T *A, const emxArray_real_T *B, double
                   data_nrow, double data_ncol, boolean_T opts_LT,
                   emxArray_real_T *result)
{
  int loop_ub;
  int b_loop_ub;
  int i5;
  int i6;

  /* Define variables */
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

  i5 = result->size[0] * result->size[1];
  result->size[0] = loop_ub;
  result->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(result, i5);
  for (i5 = 0; i5 < b_loop_ub; i5++) {
    for (i6 = 0; i6 < loop_ub; i6++) {
      result->data[i6 + result->size[0] * i5] = B->data[i6 + B->size[0] * i5];
    }
  }

  /*  Assign result to B - Because B gets overwritten otherwise */
  /*  The number of columns in matrix B. */
  /*  Scaling factor for matrix A. */
  if (opts_LT) {
    /* forward */
    cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasNonUnit,
                data_nrow, 1.0, 1.0, &A->data[0], data_ncol, &result->data[0],
                data_nrow);
  } else {
    /* backward */
    cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit,
                data_nrow, 1.0, 1.0, &A->data[0], data_ncol, &result->data[0],
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
