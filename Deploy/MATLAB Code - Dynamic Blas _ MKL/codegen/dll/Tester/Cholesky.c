/*
 * File: Cholesky.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:35:01
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Tester.h"
#include "Cholesky.h"
#include "xscal.h"
#include "Tester_emxutil.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *A
 *                double data_nrow
 *                double data_ncol
 *                emxArray_real_T *L
 * Return Type  : void
 */
void Cholesky(const emxArray_real_T *A, double data_nrow, double data_ncol,
              emxArray_real_T *L)
{
  int loop_ub;
  int b_loop_ub;
  int jmax;
  int jj;
  int j;
  boolean_T exitg1;
  double ajj;
  int nmj;
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

  jmax = L->size[0] * L->size[1];
  L->size[0] = loop_ub;
  L->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(L, jmax);
  for (jmax = 0; jmax < b_loop_ub; jmax++) {
    for (jj = 0; jj < loop_ub; jj++) {
      L->data[jj + L->size[0] * jmax] = A->data[jj + A->size[0] * jmax];
    }
  }

  if (b_loop_ub != 0) {
    jmax = -1;
    if ((loop_ub != 0) && (b_loop_ub != 0)) {
      j = 0;
      exitg1 = false;
      while ((!exitg1) && (j <= loop_ub - 1)) {
        jj = j + j * b_loop_ub;
        if (j < 1) {
          ajj = 0.0;
        } else {
          ajj = cblas_ddot((int)j, &L->data[j], (int)b_loop_ub, &L->data[j],
                           (int)b_loop_ub);
        }

        ajj = L->data[jj] - ajj;
        if (ajj > 0.0) {
          ajj = sqrt(ajj);
          L->data[jj] = ajj;
          if (j + 1 < loop_ub) {
            nmj = (loop_ub - j) - 1;
            if ((nmj < 1) || (j < 1)) {
            } else {
              cblas_dgemv(CblasColMajor, CblasNoTrans, (int)nmj, (int)j, -1.0,
                          &L->data[j + 1], (int)b_loop_ub, &L->data[j], (int)
                          b_loop_ub, 1.0, &L->data[jj + 1], (int)1);
            }

            xscal(nmj, 1.0 / ajj, L, jj + 2);
          }

          j++;
        } else {
          L->data[jj] = ajj;
          jmax = j;
          exitg1 = true;
        }
      }
    }

    if (jmax + 1 == 0) {
      jmax = b_loop_ub;
    }

    for (j = 2; j <= jmax; j++) {
      for (jj = 0; jj <= j - 2; jj++) {
        L->data[jj + L->size[0] * (j - 1)] = 0.0;
      }
    }
  }

  /*          coder.cinclude('cblas.h') */
  /*       */
  /*          CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /*          CblasLeft = coder.opaque('CBLAS_SIDE', 'CblasLeft'); */
  /*          CblasUpper = coder.opaque('CBLAS_UPLO', 'CblasUpper'); */
  /*          CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans'); */
  /*          CblasNonUnit = coder.opaque('CBLAS_DIAG', 'CblasNonUnit');          */
  /*  scaling_Factor_A_X = -1.0. */
  /*  scaling_Factor_Y = 1.0; */
  /*  cblas_dgemv(CblasColMajor, CblasNoTrans, (int)(99 - j), (int)j, scaling_Factor_A_X, */
  /*                        &A[j + 1], (int)100, &A[j], (int)100, scaling_Factor_Y, &A[jj + 1], */
  /*                        (int)1); */
}

/*
 * File trailer for Cholesky.c
 *
 * [EOF]
 */
