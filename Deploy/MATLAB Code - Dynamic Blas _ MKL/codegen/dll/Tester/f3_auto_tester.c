/*
 * File: f3_auto_tester.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:35:01
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Tester.h"
#include "f3_auto_tester.h"
#include "Tester_emxutil.h"
#include "mean.h"
#include "xscal.h"
#include "f3_array_save_bin.h"
#include "multiply_Smart.h"
#include "SVD.h"
#include "linsolve_blas.h"
#include "Cholesky.h"
#include "randi.h"
#include "cblas.h"
#include <stdio.h>

/* Function Definitions */

/*
 * Initialize
 * Arguments    : double data_nrow
 *                double data_ncol
 *                double buf_size
 *                double timesToRun
 * Return Type  : void
 */
void f3_auto_tester(double data_nrow, double data_ncol, double buf_size, double
                    timesToRun)
{
  emxArray_real_T *A;
  emxArray_real_T *B;
  int i0;
  int loop_ub;
  emxArray_real_T *L;
  int b_loop_ub;
  int nmj;
  int nB;
  int jj;
  emxArray_real_T *b_A;
  emxArray_real_T *U;
  emxArray_real_T *AverageTimeLinSolve;
  emxArray_real_T *AverageTimeCholesky;
  emxArray_real_T *AverageTimeSVD;
  emxArray_real_T *AverageTimeMultiplyNormal;
  emxArray_real_T *AverageTimeMultiplySmart;
  emxArray_real_T *cholesky;
  emxArray_real_T *y_result;
  emxArray_real_T *x_result;
  emxArray_real_T *u;
  emxArray_real_T *S;
  emxArray_real_T *V;
  emxArray_real_T *x;
  int n;
  unsigned long time;
  double ajj;
  boolean_T exitg1;
  int j;
  emxInit_real_T(&A, 2);
  emxInit_real_T(&B, 2);
  randi(buf_size, buf_size, A);
  i0 = B->size[0] * B->size[1];
  B->size[0] = A->size[1];
  B->size[1] = A->size[0];
  emxEnsureCapacity_real_T(B, i0);
  loop_ub = A->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_loop_ub = A->size[1];
    for (nmj = 0; nmj < b_loop_ub; nmj++) {
      B->data[nmj + B->size[0] * i0] = A->data[i0 + A->size[0] * nmj];
    }
  }

  emxInit_real_T(&L, 2);
  i0 = L->size[0] * L->size[1];
  L->size[0] = A->size[0];
  L->size[1] = A->size[1];
  emxEnsureCapacity_real_T(L, i0);
  loop_ub = A->size[0] * A->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    L->data[i0] = A->data[i0];
  }

  if ((B->size[1] == 1) || (A->size[0] == 1)) {
    i0 = L->size[0] * L->size[1];
    L->size[0] = B->size[0];
    L->size[1] = A->size[1];
    emxEnsureCapacity_real_T(L, i0);
    loop_ub = B->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_loop_ub = A->size[1];
      for (nmj = 0; nmj < b_loop_ub; nmj++) {
        L->data[i0 + L->size[0] * nmj] = 0.0;
        nB = B->size[1];
        for (jj = 0; jj < nB; jj++) {
          L->data[i0 + L->size[0] * nmj] += B->data[i0 + B->size[0] * jj] *
            A->data[jj + A->size[0] * nmj];
        }
      }
    }

    i0 = A->size[0] * A->size[1];
    A->size[0] = L->size[0];
    A->size[1] = L->size[1];
    emxEnsureCapacity_real_T(A, i0);
    loop_ub = L->size[0] * L->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      A->data[i0] = L->data[i0];
    }
  } else {
    nB = A->size[1];
    if ((B->size[0] == 0) || (B->size[1] == 0) || (A->size[0] == 0) || (A->size
         [1] == 0)) {
      i0 = A->size[1];
      nB = B->size[0];
      nmj = A->size[0] * A->size[1];
      A->size[0] = nB;
      A->size[1] = i0;
      emxEnsureCapacity_real_T(A, nmj);
      loop_ub = nB * i0;
      for (i0 = 0; i0 < loop_ub; i0++) {
        A->data[i0] = 0.0;
      }
    } else {
      i0 = A->size[1];
      nmj = A->size[0] * A->size[1];
      A->size[0] = B->size[0];
      A->size[1] = i0;
      emxEnsureCapacity_real_T(A, nmj);
      cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)B->size[0],
                  (int)nB, (int)B->size[1], 1.0, &B->data[0], (int)B->size[0],
                  &L->data[0], (int)B->size[1], 0.0, &A->data[0], (int)B->size[0]);
    }
  }

  if (1.0 > buf_size) {
    loop_ub = 0;
  } else {
    loop_ub = (int)buf_size;
  }

  emxInit_real_T(&b_A, 1);
  i0 = b_A->size[0];
  b_A->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_A, i0);
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_A->data[i0] = A->data[i0];
  }

  i0 = B->size[0] * B->size[1];
  B->size[0] = loop_ub;
  B->size[1] = 1;
  emxEnsureCapacity_real_T(B, i0);
  for (i0 = 0; i0 < loop_ub; i0++) {
    B->data[i0] = b_A->data[i0];
  }

  emxInit_real_T(&U, 2);

  /*  LinSolve(Cholesky), SVD, Multiplication */
  /* Calculate Cholesky     */
  Cholesky(A, data_nrow, data_ncol, L);
  i0 = U->size[0] * U->size[1];
  U->size[0] = L->size[1];
  U->size[1] = L->size[0];
  emxEnsureCapacity_real_T(U, i0);
  loop_ub = L->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_loop_ub = L->size[1];
    for (nmj = 0; nmj < b_loop_ub; nmj++) {
      U->data[nmj + U->size[0] * i0] = L->data[i0 + L->size[0] * nmj];
    }
  }

  emxInit_real_T(&AverageTimeLinSolve, 2);
  emxInit_real_T(&AverageTimeCholesky, 2);
  emxInit_real_T(&AverageTimeSVD, 2);
  emxInit_real_T(&AverageTimeMultiplyNormal, 2);
  emxInit_real_T(&AverageTimeMultiplySmart, 2);

  /* Run the calculations X times for correcteness  */
  i0 = (int)timesToRun;
  nmj = AverageTimeLinSolve->size[0] * AverageTimeLinSolve->size[1];
  AverageTimeLinSolve->size[0] = 1;
  AverageTimeLinSolve->size[1] = i0;
  emxEnsureCapacity_real_T(AverageTimeLinSolve, nmj);
  nmj = AverageTimeCholesky->size[0] * AverageTimeCholesky->size[1];
  AverageTimeCholesky->size[0] = 1;
  AverageTimeCholesky->size[1] = i0;
  emxEnsureCapacity_real_T(AverageTimeCholesky, nmj);
  nmj = AverageTimeSVD->size[0] * AverageTimeSVD->size[1];
  AverageTimeSVD->size[0] = 1;
  AverageTimeSVD->size[1] = i0;
  emxEnsureCapacity_real_T(AverageTimeSVD, nmj);
  nmj = AverageTimeMultiplyNormal->size[0] * AverageTimeMultiplyNormal->size[1];
  AverageTimeMultiplyNormal->size[0] = 1;
  AverageTimeMultiplyNormal->size[1] = i0;
  emxEnsureCapacity_real_T(AverageTimeMultiplyNormal, nmj);
  nmj = AverageTimeMultiplySmart->size[0] * AverageTimeMultiplySmart->size[1];
  AverageTimeMultiplySmart->size[0] = 1;
  AverageTimeMultiplySmart->size[1] = i0;
  emxEnsureCapacity_real_T(AverageTimeMultiplySmart, nmj);
  emxInit_real_T(&cholesky, 2);
  emxInit_real_T(&y_result, 2);
  emxInit_real_T(&x_result, 2);
  emxInit_real_T(&u, 2);
  emxInit_real_T(&S, 2);
  emxInit_real_T(&V, 2);
  emxInit_real_T(&x, 1);
  for (n = 0; n < i0; n++) {
    /*  opts settings */
    /* Calculate elapse time LinSolve start */
    time = 0;
    PLXAtimeinterval_start(&time);

    /* Forward */
    linsolve_blas(L, B, data_nrow, data_ncol, true, y_result);

    /* Backward */
    linsolve_blas(U, y_result, data_nrow, data_ncol, false, x_result);

    /* Calculate elapse time LinSolve end */
    AverageTimeLinSolve->data[n] = time_diff_msec(time);

    /* Calculate Cholesky   */
    /* Calculate elapse time Cholesky start */
    PLXAtimeinterval_start(&time);

    /*      chol = Cholesky(A, buf_size, buf_size);  */
    if (1.0 > buf_size) {
      loop_ub = 0;
      b_loop_ub = 0;
    } else {
      loop_ub = (int)buf_size;
      b_loop_ub = (int)buf_size;
    }

    nmj = cholesky->size[0] * cholesky->size[1];
    cholesky->size[0] = loop_ub;
    cholesky->size[1] = b_loop_ub;
    emxEnsureCapacity_real_T(cholesky, nmj);
    for (nmj = 0; nmj < b_loop_ub; nmj++) {
      for (jj = 0; jj < loop_ub; jj++) {
        cholesky->data[jj + cholesky->size[0] * nmj] = A->data[jj + A->size[0] *
          nmj];
      }
    }

    if (b_loop_ub != 0) {
      nB = -1;
      if ((loop_ub != 0) && (b_loop_ub != 0)) {
        j = 0;
        exitg1 = false;
        while ((!exitg1) && (j <= loop_ub - 1)) {
          jj = j + j * b_loop_ub;
          if (j < 1) {
            ajj = 0.0;
          } else {
            ajj = cblas_ddot((int)j, &cholesky->data[j], (int)b_loop_ub,
                             &cholesky->data[j], (int)b_loop_ub);
          }

          ajj = cholesky->data[jj] - ajj;
          if (ajj > 0.0) {
            ajj = sqrt(ajj);
            cholesky->data[jj] = ajj;
            if (j + 1 < loop_ub) {
              nmj = (loop_ub - j) - 1;
              if ((nmj < 1) || (j < 1)) {
              } else {
                cblas_dgemv(CblasColMajor, CblasNoTrans, (int)nmj, (int)j, -1.0,
                            &cholesky->data[j + 1], (int)b_loop_ub,
                            &cholesky->data[j], (int)b_loop_ub, 1.0,
                            &cholesky->data[jj + 1], (int)1);
              }

              xscal(nmj, 1.0 / ajj, cholesky, jj + 2);
            }

            j++;
          } else {
            cholesky->data[jj] = ajj;
            nB = j;
            exitg1 = true;
          }
        }
      }

      if (nB + 1 == 0) {
        nB = b_loop_ub;
      }

      for (j = 2; j <= nB; j++) {
        for (jj = 0; jj <= j - 2; jj++) {
          cholesky->data[jj + cholesky->size[0] * (j - 1)] = 0.0;
        }
      }
    }

    /* Calculate elapse time Cholesky end */
    AverageTimeCholesky->data[n] = time_diff_msec(time);

    /* Calculate SVD   */
    /* Calculate elapse time SVD start */
    PLXAtimeinterval_start(&time);
    SVD(A, buf_size, buf_size, u, S, V);

    /* Calculate elapse time SVD end */
    AverageTimeSVD->data[n] = time_diff_msec(time);

    /* Calculate Multiplication Normal */
    /* Calculate elapse time Multiplication Normal start */
    PLXAtimeinterval_start(&time);
    multiply_Smart(A, B, buf_size, buf_size, b_A);

    /* Calculate elapse time Multiplication Normal end */
    AverageTimeMultiplyNormal->data[n] = time_diff_msec(time);

    /* Calculate Multiplication Smart */
    /* Calculate elapse time Multiplication Smart start */
    PLXAtimeinterval_start(&time);
    multiply_Smart(A, B, data_nrow, data_ncol, x);

    /* Calculate elapse time Multiplication Smart end */
    AverageTimeMultiplySmart->data[n] = time_diff_msec(time);

    /* Save/Check Results and Precision  */
    f3_array_save_bin(x_result);
    b_f3_array_save_bin(y_result);
    c_f3_array_save_bin(cholesky);
    d_f3_array_save_bin(u);
    e_f3_array_save_bin(b_A);
    f_f3_array_save_bin(x);
  }

  emxFree_real_T(&b_A);
  emxFree_real_T(&x);
  emxFree_real_T(&V);
  emxFree_real_T(&S);
  emxFree_real_T(&u);
  emxFree_real_T(&x_result);
  emxFree_real_T(&y_result);
  emxFree_real_T(&cholesky);
  emxFree_real_T(&U);
  emxFree_real_T(&L);
  emxFree_real_T(&B);
  emxFree_real_T(&A);
  printf("\n---------------------------------------------------------------\n");
  fflush(stdout);
  printf("For matrix size: %3e\n", buf_size);
  fflush(stdout);
  printf("\nSame values - set range of calcuations 100x100 (LinSolve & Smart Multiply): \n\n");
  fflush(stdout);
  n = AverageTimeLinSolve->size[1];
  if (AverageTimeLinSolve->size[1] <= 2) {
    if (AverageTimeLinSolve->size[1] == 0) {
      ajj = rtNaN;
    } else if (AverageTimeLinSolve->size[1] == 1) {
      ajj = AverageTimeLinSolve->data[0];
    } else if ((AverageTimeLinSolve->data[0] < AverageTimeLinSolve->data[1]) ||
               (rtIsNaN(AverageTimeLinSolve->data[0]) && (!rtIsNaN
                 (AverageTimeLinSolve->data[1])))) {
      ajj = AverageTimeLinSolve->data[1];
    } else {
      ajj = AverageTimeLinSolve->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeLinSolve->data[0])) {
      nB = 1;
    } else {
      nB = 0;
      jj = 2;
      exitg1 = false;
      while ((!exitg1) && (jj <= AverageTimeLinSolve->size[1])) {
        if (!rtIsNaN(AverageTimeLinSolve->data[jj - 1])) {
          nB = jj;
          exitg1 = true;
        } else {
          jj++;
        }
      }
    }

    if (nB == 0) {
      ajj = AverageTimeLinSolve->data[0];
    } else {
      ajj = AverageTimeLinSolve->data[nB - 1];
      i0 = nB + 1;
      for (jj = i0; jj <= n; jj++) {
        if (ajj < AverageTimeLinSolve->data[jj - 1]) {
          ajj = AverageTimeLinSolve->data[jj - 1];
        }
      }
    }
  }

  printf("Worst Time LinSolve: %gms\n", ajj / 1000.0);
  fflush(stdout);
  printf("Average Time LinSolve: %gms\n", mean(AverageTimeLinSolve) / 1000.0);
  fflush(stdout);
  n = AverageTimeLinSolve->size[1];
  if (AverageTimeLinSolve->size[1] <= 2) {
    if (AverageTimeLinSolve->size[1] == 0) {
      ajj = rtNaN;
    } else if (AverageTimeLinSolve->size[1] == 1) {
      ajj = AverageTimeLinSolve->data[0];
    } else if ((AverageTimeLinSolve->data[0] > AverageTimeLinSolve->data[1]) ||
               (rtIsNaN(AverageTimeLinSolve->data[0]) && (!rtIsNaN
                 (AverageTimeLinSolve->data[1])))) {
      ajj = AverageTimeLinSolve->data[1];
    } else {
      ajj = AverageTimeLinSolve->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeLinSolve->data[0])) {
      nB = 1;
    } else {
      nB = 0;
      jj = 2;
      exitg1 = false;
      while ((!exitg1) && (jj <= AverageTimeLinSolve->size[1])) {
        if (!rtIsNaN(AverageTimeLinSolve->data[jj - 1])) {
          nB = jj;
          exitg1 = true;
        } else {
          jj++;
        }
      }
    }

    if (nB == 0) {
      ajj = AverageTimeLinSolve->data[0];
    } else {
      ajj = AverageTimeLinSolve->data[nB - 1];
      i0 = nB + 1;
      for (jj = i0; jj <= n; jj++) {
        if (ajj > AverageTimeLinSolve->data[jj - 1]) {
          ajj = AverageTimeLinSolve->data[jj - 1];
        }
      }
    }
  }

  emxFree_real_T(&AverageTimeLinSolve);
  printf("Best Time LinSolve: %gms\n\n", ajj / 1000.0);
  fflush(stdout);
  n = AverageTimeMultiplySmart->size[1];
  if (AverageTimeMultiplySmart->size[1] <= 2) {
    if (AverageTimeMultiplySmart->size[1] == 0) {
      ajj = rtNaN;
    } else if (AverageTimeMultiplySmart->size[1] == 1) {
      ajj = AverageTimeMultiplySmart->data[0];
    } else if ((AverageTimeMultiplySmart->data[0] <
                AverageTimeMultiplySmart->data[1]) || (rtIsNaN
                (AverageTimeMultiplySmart->data[0]) && (!rtIsNaN
                 (AverageTimeMultiplySmart->data[1])))) {
      ajj = AverageTimeMultiplySmart->data[1];
    } else {
      ajj = AverageTimeMultiplySmart->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeMultiplySmart->data[0])) {
      nB = 1;
    } else {
      nB = 0;
      jj = 2;
      exitg1 = false;
      while ((!exitg1) && (jj <= AverageTimeMultiplySmart->size[1])) {
        if (!rtIsNaN(AverageTimeMultiplySmart->data[jj - 1])) {
          nB = jj;
          exitg1 = true;
        } else {
          jj++;
        }
      }
    }

    if (nB == 0) {
      ajj = AverageTimeMultiplySmart->data[0];
    } else {
      ajj = AverageTimeMultiplySmart->data[nB - 1];
      i0 = nB + 1;
      for (jj = i0; jj <= n; jj++) {
        if (ajj < AverageTimeMultiplySmart->data[jj - 1]) {
          ajj = AverageTimeMultiplySmart->data[jj - 1];
        }
      }
    }
  }

  printf("Worst Time Multiply Smart: %gms\n", ajj / 1000.0);
  fflush(stdout);
  printf("Average Time Multiply Smart: %gms\n", mean(AverageTimeMultiplySmart) /
         1000.0);
  fflush(stdout);
  n = AverageTimeMultiplySmart->size[1];
  if (AverageTimeMultiplySmart->size[1] <= 2) {
    if (AverageTimeMultiplySmart->size[1] == 0) {
      ajj = rtNaN;
    } else if (AverageTimeMultiplySmart->size[1] == 1) {
      ajj = AverageTimeMultiplySmart->data[0];
    } else if ((AverageTimeMultiplySmart->data[0] >
                AverageTimeMultiplySmart->data[1]) || (rtIsNaN
                (AverageTimeMultiplySmart->data[0]) && (!rtIsNaN
                 (AverageTimeMultiplySmart->data[1])))) {
      ajj = AverageTimeMultiplySmart->data[1];
    } else {
      ajj = AverageTimeMultiplySmart->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeMultiplySmart->data[0])) {
      nB = 1;
    } else {
      nB = 0;
      jj = 2;
      exitg1 = false;
      while ((!exitg1) && (jj <= AverageTimeMultiplySmart->size[1])) {
        if (!rtIsNaN(AverageTimeMultiplySmart->data[jj - 1])) {
          nB = jj;
          exitg1 = true;
        } else {
          jj++;
        }
      }
    }

    if (nB == 0) {
      ajj = AverageTimeMultiplySmart->data[0];
    } else {
      ajj = AverageTimeMultiplySmart->data[nB - 1];
      i0 = nB + 1;
      for (jj = i0; jj <= n; jj++) {
        if (ajj > AverageTimeMultiplySmart->data[jj - 1]) {
          ajj = AverageTimeMultiplySmart->data[jj - 1];
        }
      }
    }
  }

  emxFree_real_T(&AverageTimeMultiplySmart);
  printf("Best Time Multiply Smart: %gms\n", ajj / 1000.0);
  fflush(stdout);
  printf("\nDifferent values with size change (Cholesky, SVD, Normal Multiply): \n\n");
  fflush(stdout);
  n = AverageTimeCholesky->size[1];
  if (AverageTimeCholesky->size[1] <= 2) {
    if (AverageTimeCholesky->size[1] == 0) {
      ajj = rtNaN;
    } else if (AverageTimeCholesky->size[1] == 1) {
      ajj = AverageTimeCholesky->data[0];
    } else if ((AverageTimeCholesky->data[0] < AverageTimeCholesky->data[1]) ||
               (rtIsNaN(AverageTimeCholesky->data[0]) && (!rtIsNaN
                 (AverageTimeCholesky->data[1])))) {
      ajj = AverageTimeCholesky->data[1];
    } else {
      ajj = AverageTimeCholesky->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeCholesky->data[0])) {
      nB = 1;
    } else {
      nB = 0;
      jj = 2;
      exitg1 = false;
      while ((!exitg1) && (jj <= AverageTimeCholesky->size[1])) {
        if (!rtIsNaN(AverageTimeCholesky->data[jj - 1])) {
          nB = jj;
          exitg1 = true;
        } else {
          jj++;
        }
      }
    }

    if (nB == 0) {
      ajj = AverageTimeCholesky->data[0];
    } else {
      ajj = AverageTimeCholesky->data[nB - 1];
      i0 = nB + 1;
      for (jj = i0; jj <= n; jj++) {
        if (ajj < AverageTimeCholesky->data[jj - 1]) {
          ajj = AverageTimeCholesky->data[jj - 1];
        }
      }
    }
  }

  printf("Worst Time Cholesky: %gms\n", ajj / 1000.0);
  fflush(stdout);
  printf("Average Time Cholesky: %gms\n", mean(AverageTimeCholesky) / 1000.0);
  fflush(stdout);
  n = AverageTimeCholesky->size[1];
  if (AverageTimeCholesky->size[1] <= 2) {
    if (AverageTimeCholesky->size[1] == 0) {
      ajj = rtNaN;
    } else if (AverageTimeCholesky->size[1] == 1) {
      ajj = AverageTimeCholesky->data[0];
    } else if ((AverageTimeCholesky->data[0] > AverageTimeCholesky->data[1]) ||
               (rtIsNaN(AverageTimeCholesky->data[0]) && (!rtIsNaN
                 (AverageTimeCholesky->data[1])))) {
      ajj = AverageTimeCholesky->data[1];
    } else {
      ajj = AverageTimeCholesky->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeCholesky->data[0])) {
      nB = 1;
    } else {
      nB = 0;
      jj = 2;
      exitg1 = false;
      while ((!exitg1) && (jj <= AverageTimeCholesky->size[1])) {
        if (!rtIsNaN(AverageTimeCholesky->data[jj - 1])) {
          nB = jj;
          exitg1 = true;
        } else {
          jj++;
        }
      }
    }

    if (nB == 0) {
      ajj = AverageTimeCholesky->data[0];
    } else {
      ajj = AverageTimeCholesky->data[nB - 1];
      i0 = nB + 1;
      for (jj = i0; jj <= n; jj++) {
        if (ajj > AverageTimeCholesky->data[jj - 1]) {
          ajj = AverageTimeCholesky->data[jj - 1];
        }
      }
    }
  }

  emxFree_real_T(&AverageTimeCholesky);
  printf("Best Time Cholesky: %gms\n\n", ajj / 1000.0);
  fflush(stdout);
  n = AverageTimeSVD->size[1];
  if (AverageTimeSVD->size[1] <= 2) {
    if (AverageTimeSVD->size[1] == 0) {
      ajj = rtNaN;
    } else if (AverageTimeSVD->size[1] == 1) {
      ajj = AverageTimeSVD->data[0];
    } else if ((AverageTimeSVD->data[0] < AverageTimeSVD->data[1]) || (rtIsNaN
                (AverageTimeSVD->data[0]) && (!rtIsNaN(AverageTimeSVD->data[1]))))
    {
      ajj = AverageTimeSVD->data[1];
    } else {
      ajj = AverageTimeSVD->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeSVD->data[0])) {
      nB = 1;
    } else {
      nB = 0;
      jj = 2;
      exitg1 = false;
      while ((!exitg1) && (jj <= AverageTimeSVD->size[1])) {
        if (!rtIsNaN(AverageTimeSVD->data[jj - 1])) {
          nB = jj;
          exitg1 = true;
        } else {
          jj++;
        }
      }
    }

    if (nB == 0) {
      ajj = AverageTimeSVD->data[0];
    } else {
      ajj = AverageTimeSVD->data[nB - 1];
      i0 = nB + 1;
      for (jj = i0; jj <= n; jj++) {
        if (ajj < AverageTimeSVD->data[jj - 1]) {
          ajj = AverageTimeSVD->data[jj - 1];
        }
      }
    }
  }

  printf("Worst Time SVD: %gms\n", ajj / 1000.0);
  fflush(stdout);
  printf("Average Time SVD: %gms\n", mean(AverageTimeSVD) / 1000.0);
  fflush(stdout);
  n = AverageTimeSVD->size[1];
  if (AverageTimeSVD->size[1] <= 2) {
    if (AverageTimeSVD->size[1] == 0) {
      ajj = rtNaN;
    } else if (AverageTimeSVD->size[1] == 1) {
      ajj = AverageTimeSVD->data[0];
    } else if ((AverageTimeSVD->data[0] > AverageTimeSVD->data[1]) || (rtIsNaN
                (AverageTimeSVD->data[0]) && (!rtIsNaN(AverageTimeSVD->data[1]))))
    {
      ajj = AverageTimeSVD->data[1];
    } else {
      ajj = AverageTimeSVD->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeSVD->data[0])) {
      nB = 1;
    } else {
      nB = 0;
      jj = 2;
      exitg1 = false;
      while ((!exitg1) && (jj <= AverageTimeSVD->size[1])) {
        if (!rtIsNaN(AverageTimeSVD->data[jj - 1])) {
          nB = jj;
          exitg1 = true;
        } else {
          jj++;
        }
      }
    }

    if (nB == 0) {
      ajj = AverageTimeSVD->data[0];
    } else {
      ajj = AverageTimeSVD->data[nB - 1];
      i0 = nB + 1;
      for (jj = i0; jj <= n; jj++) {
        if (ajj > AverageTimeSVD->data[jj - 1]) {
          ajj = AverageTimeSVD->data[jj - 1];
        }
      }
    }
  }

  emxFree_real_T(&AverageTimeSVD);
  printf("Best Time SVD: %gms\n\n", ajj / 1000.0);
  fflush(stdout);
  n = AverageTimeMultiplyNormal->size[1];
  if (AverageTimeMultiplyNormal->size[1] <= 2) {
    if (AverageTimeMultiplyNormal->size[1] == 0) {
      ajj = rtNaN;
    } else if (AverageTimeMultiplyNormal->size[1] == 1) {
      ajj = AverageTimeMultiplyNormal->data[0];
    } else if ((AverageTimeMultiplyNormal->data[0] <
                AverageTimeMultiplyNormal->data[1]) || (rtIsNaN
                (AverageTimeMultiplyNormal->data[0]) && (!rtIsNaN
                 (AverageTimeMultiplyNormal->data[1])))) {
      ajj = AverageTimeMultiplyNormal->data[1];
    } else {
      ajj = AverageTimeMultiplyNormal->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeMultiplyNormal->data[0])) {
      nB = 1;
    } else {
      nB = 0;
      jj = 2;
      exitg1 = false;
      while ((!exitg1) && (jj <= AverageTimeMultiplyNormal->size[1])) {
        if (!rtIsNaN(AverageTimeMultiplyNormal->data[jj - 1])) {
          nB = jj;
          exitg1 = true;
        } else {
          jj++;
        }
      }
    }

    if (nB == 0) {
      ajj = AverageTimeMultiplyNormal->data[0];
    } else {
      ajj = AverageTimeMultiplyNormal->data[nB - 1];
      i0 = nB + 1;
      for (jj = i0; jj <= n; jj++) {
        if (ajj < AverageTimeMultiplyNormal->data[jj - 1]) {
          ajj = AverageTimeMultiplyNormal->data[jj - 1];
        }
      }
    }
  }

  printf("Worst Time Multiply Normal: %gms\n", ajj / 1000.0);
  fflush(stdout);
  printf("Average Time Multiply Normal: %gms\n", mean(AverageTimeMultiplyNormal)
         / 1000.0);
  fflush(stdout);
  n = AverageTimeMultiplyNormal->size[1];
  if (AverageTimeMultiplyNormal->size[1] <= 2) {
    if (AverageTimeMultiplyNormal->size[1] == 0) {
      ajj = rtNaN;
    } else if (AverageTimeMultiplyNormal->size[1] == 1) {
      ajj = AverageTimeMultiplyNormal->data[0];
    } else if ((AverageTimeMultiplyNormal->data[0] >
                AverageTimeMultiplyNormal->data[1]) || (rtIsNaN
                (AverageTimeMultiplyNormal->data[0]) && (!rtIsNaN
                 (AverageTimeMultiplyNormal->data[1])))) {
      ajj = AverageTimeMultiplyNormal->data[1];
    } else {
      ajj = AverageTimeMultiplyNormal->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeMultiplyNormal->data[0])) {
      nB = 1;
    } else {
      nB = 0;
      jj = 2;
      exitg1 = false;
      while ((!exitg1) && (jj <= AverageTimeMultiplyNormal->size[1])) {
        if (!rtIsNaN(AverageTimeMultiplyNormal->data[jj - 1])) {
          nB = jj;
          exitg1 = true;
        } else {
          jj++;
        }
      }
    }

    if (nB == 0) {
      ajj = AverageTimeMultiplyNormal->data[0];
    } else {
      ajj = AverageTimeMultiplyNormal->data[nB - 1];
      i0 = nB + 1;
      for (jj = i0; jj <= n; jj++) {
        if (ajj > AverageTimeMultiplyNormal->data[jj - 1]) {
          ajj = AverageTimeMultiplyNormal->data[jj - 1];
        }
      }
    }
  }

  emxFree_real_T(&AverageTimeMultiplyNormal);
  printf("Bes tTime Multiply Normal: %gms\n", ajj / 1000.0);
  fflush(stdout);
}

/*
 * File trailer for f3_auto_tester.c
 *
 * [EOF]
 */
