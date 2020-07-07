/*
 * File: Cholesky.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:45:17
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Tester.h"
#include "Cholesky.h"
#include "xscal.h"
#include "Tester_emxutil.h"

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
  int i;
  int info;
  int j;
  boolean_T exitg1;
  int jj;
  double ajj;
  int ix;
  int iy;
  int nmj;
  int ia0;
  int iac;
  double c;
  int ia;
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
    for (i = 0; i < loop_ub; i++) {
      L->data[i + L->size[0] * jmax] = A->data[i + A->size[0] * jmax];
    }
  }

  if (b_loop_ub != 0) {
    info = 0;
    if ((loop_ub != 0) && (b_loop_ub != 0)) {
      j = 0;
      exitg1 = false;
      while ((!exitg1) && (j <= loop_ub - 1)) {
        jj = j + j * b_loop_ub;
        ajj = 0.0;
        if (j >= 1) {
          ix = j;
          iy = j;
          for (jmax = 0; jmax < j; jmax++) {
            ajj += L->data[ix] * L->data[iy];
            ix += b_loop_ub;
            iy += b_loop_ub;
          }
        }

        ajj = L->data[jj] - ajj;
        if (ajj > 0.0) {
          ajj = sqrt(ajj);
          L->data[jj] = ajj;
          if (j + 1 < loop_ub) {
            nmj = (loop_ub - j) - 1;
            ia0 = j + 2;
            if ((nmj == 0) || (j == 0)) {
            } else {
              ix = j;
              jmax = (j + b_loop_ub * (j - 1)) + 2;
              for (iac = ia0; b_loop_ub < 0 ? iac >= jmax : iac <= jmax; iac +=
                   b_loop_ub) {
                c = -L->data[ix];
                iy = jj + 1;
                i = (iac + nmj) - 1;
                for (ia = iac; ia <= i; ia++) {
                  L->data[iy] += L->data[ia - 1] * c;
                  iy++;
                }

                ix += b_loop_ub;
              }
            }

            xscal(nmj, 1.0 / ajj, L, jj + 2);
          }

          j++;
        } else {
          L->data[jj] = ajj;
          info = j + 1;
          exitg1 = true;
        }
      }
    }

    if (info == 0) {
      jmax = b_loop_ub;
    } else {
      jmax = info - 1;
    }

    for (j = 2; j <= jmax; j++) {
      for (i = 0; i <= j - 2; i++) {
        L->data[i + L->size[0] * (j - 1)] = 0.0;
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
