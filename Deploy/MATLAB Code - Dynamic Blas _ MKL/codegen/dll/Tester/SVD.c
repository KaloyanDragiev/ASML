/*
 * File: SVD.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:35:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "SVD.h"
#include "Tester_emxutil.h"
#include "svd2.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *A
 *                double data_nrow
 *                double data_ncol
 *                emxArray_real_T *u
 *                emxArray_real_T *S
 *                emxArray_real_T *V
 * Return Type  : void
 */
void SVD(const emxArray_real_T *A, double data_nrow, double data_ncol,
         emxArray_real_T *u, emxArray_real_T *S, emxArray_real_T *V)
{
  int loop_ub;
  int b_loop_ub;
  int nx;
  boolean_T p;
  int k;
  emxArray_real_T *s;
  emxArray_real_T *b_A;
  double x;
  int i3;
  emxArray_real_T *U1;
  emxArray_real_T *V1;
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

  nx = loop_ub * b_loop_ub;
  p = true;
  for (k = 0; k < nx; k++) {
    if (p) {
      x = A->data[k % loop_ub + A->size[0] * (k / loop_ub)];
      if ((!rtIsInf(x)) && (!rtIsNaN(x))) {
        p = true;
      } else {
        p = false;
      }
    } else {
      p = false;
    }
  }

  emxInit_real_T(&s, 1);
  emxInit_real_T(&b_A, 2);
  if (p) {
    i3 = b_A->size[0] * b_A->size[1];
    b_A->size[0] = loop_ub;
    b_A->size[1] = b_loop_ub;
    emxEnsureCapacity_real_T(b_A, i3);
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      for (nx = 0; nx < loop_ub; nx++) {
        b_A->data[nx + b_A->size[0] * i3] = A->data[nx + A->size[0] * i3];
      }
    }

    svd(b_A, u, s, V);
  } else {
    i3 = b_A->size[0] * b_A->size[1];
    b_A->size[0] = loop_ub;
    b_A->size[1] = b_loop_ub;
    emxEnsureCapacity_real_T(b_A, i3);
    loop_ub *= b_loop_ub;
    for (i3 = 0; i3 < loop_ub; i3++) {
      b_A->data[i3] = 0.0;
    }

    emxInit_real_T(&U1, 2);
    emxInit_real_T(&V1, 2);
    svd(b_A, U1, s, V1);
    i3 = u->size[0] * u->size[1];
    u->size[0] = U1->size[0];
    u->size[1] = U1->size[1];
    emxEnsureCapacity_real_T(u, i3);
    loop_ub = U1->size[0] * U1->size[1];
    emxFree_real_T(&U1);
    for (i3 = 0; i3 < loop_ub; i3++) {
      u->data[i3] = rtNaN;
    }

    loop_ub = s->size[0];
    i3 = s->size[0];
    s->size[0] = loop_ub;
    emxEnsureCapacity_real_T(s, i3);
    for (i3 = 0; i3 < loop_ub; i3++) {
      s->data[i3] = rtNaN;
    }

    i3 = V->size[0] * V->size[1];
    V->size[0] = V1->size[0];
    V->size[1] = V1->size[1];
    emxEnsureCapacity_real_T(V, i3);
    loop_ub = V1->size[0] * V1->size[1];
    emxFree_real_T(&V1);
    for (i3 = 0; i3 < loop_ub; i3++) {
      V->data[i3] = rtNaN;
    }
  }

  emxFree_real_T(&b_A);
  i3 = S->size[0] * S->size[1];
  S->size[0] = u->size[1];
  S->size[1] = V->size[1];
  emxEnsureCapacity_real_T(S, i3);
  loop_ub = u->size[1] * V->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    S->data[i3] = 0.0;
  }

  i3 = s->size[0] - 1;
  for (k = 0; k <= i3; k++) {
    S->data[k + S->size[0] * k] = s->data[k];
  }

  emxFree_real_T(&s);

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
 * File trailer for SVD.c
 *
 * [EOF]
 */
