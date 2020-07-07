/*
 * File: f3_auto_tester.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:45:17
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
  emxArray_real_T *a;
  int i0;
  int loop_ub;
  emxArray_real_T *b;
  int b_loop_ub;
  int k;
  int m;
  int inner;
  int n;
  int j;
  int coffset;
  int boffset;
  int i;
  emxArray_real_T *b_A;
  int aoffset;
  double temp;
  emxArray_real_T *B;
  emxArray_real_T *L;
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
  unsigned long time;
  boolean_T exitg1;
  int jj;
  int ix;
  int iy;
  double c;
  emxInit_real_T(&A, 2);
  emxInit_real_T(&a, 2);
  randi(buf_size, buf_size, A);
  i0 = a->size[0] * a->size[1];
  a->size[0] = A->size[1];
  a->size[1] = A->size[0];
  emxEnsureCapacity_real_T(a, i0);
  loop_ub = A->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_loop_ub = A->size[1];
    for (k = 0; k < b_loop_ub; k++) {
      a->data[k + a->size[0] * i0] = A->data[i0 + A->size[0] * k];
    }
  }

  emxInit_real_T(&b, 2);
  i0 = b->size[0] * b->size[1];
  b->size[0] = A->size[0];
  b->size[1] = A->size[1];
  emxEnsureCapacity_real_T(b, i0);
  loop_ub = A->size[0] * A->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b->data[i0] = A->data[i0];
  }

  if ((a->size[1] == 1) || (A->size[0] == 1)) {
    i0 = b->size[0] * b->size[1];
    b->size[0] = a->size[0];
    b->size[1] = A->size[1];
    emxEnsureCapacity_real_T(b, i0);
    loop_ub = a->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_loop_ub = A->size[1];
      for (k = 0; k < b_loop_ub; k++) {
        b->data[i0 + b->size[0] * k] = 0.0;
        coffset = a->size[1];
        for (inner = 0; inner < coffset; inner++) {
          b->data[i0 + b->size[0] * k] += a->data[i0 + a->size[0] * inner] *
            A->data[inner + A->size[0] * k];
        }
      }
    }

    i0 = A->size[0] * A->size[1];
    A->size[0] = b->size[0];
    A->size[1] = b->size[1];
    emxEnsureCapacity_real_T(A, i0);
    loop_ub = b->size[0] * b->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      A->data[i0] = b->data[i0];
    }
  } else {
    m = a->size[0];
    inner = a->size[1];
    n = A->size[1];
    i0 = A->size[1];
    k = A->size[0] * A->size[1];
    A->size[0] = a->size[0];
    A->size[1] = i0;
    emxEnsureCapacity_real_T(A, k);
    for (j = 0; j < n; j++) {
      coffset = j * m;
      boffset = j * inner;
      for (i = 0; i < m; i++) {
        A->data[coffset + i] = 0.0;
      }

      for (k = 0; k < inner; k++) {
        aoffset = k * m;
        temp = b->data[boffset + k];
        for (i = 0; i < m; i++) {
          i0 = coffset + i;
          A->data[i0] += temp * a->data[aoffset + i];
        }
      }
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

  emxInit_real_T(&B, 2);
  i0 = B->size[0] * B->size[1];
  B->size[0] = loop_ub;
  B->size[1] = 1;
  emxEnsureCapacity_real_T(B, i0);
  for (i0 = 0; i0 < loop_ub; i0++) {
    B->data[i0] = b_A->data[i0];
  }

  emxFree_real_T(&b_A);
  emxInit_real_T(&L, 2);
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
    for (k = 0; k < b_loop_ub; k++) {
      U->data[k + U->size[0] * i0] = L->data[i0 + L->size[0] * k];
    }
  }

  emxInit_real_T(&AverageTimeLinSolve, 2);
  emxInit_real_T(&AverageTimeCholesky, 2);
  emxInit_real_T(&AverageTimeSVD, 2);
  emxInit_real_T(&AverageTimeMultiplyNormal, 2);
  emxInit_real_T(&AverageTimeMultiplySmart, 2);

  /* Run the calculations X times for correcteness  */
  i0 = (int)timesToRun;
  k = AverageTimeLinSolve->size[0] * AverageTimeLinSolve->size[1];
  AverageTimeLinSolve->size[0] = 1;
  AverageTimeLinSolve->size[1] = i0;
  emxEnsureCapacity_real_T(AverageTimeLinSolve, k);
  k = AverageTimeCholesky->size[0] * AverageTimeCholesky->size[1];
  AverageTimeCholesky->size[0] = 1;
  AverageTimeCholesky->size[1] = i0;
  emxEnsureCapacity_real_T(AverageTimeCholesky, k);
  k = AverageTimeSVD->size[0] * AverageTimeSVD->size[1];
  AverageTimeSVD->size[0] = 1;
  AverageTimeSVD->size[1] = i0;
  emxEnsureCapacity_real_T(AverageTimeSVD, k);
  k = AverageTimeMultiplyNormal->size[0] * AverageTimeMultiplyNormal->size[1];
  AverageTimeMultiplyNormal->size[0] = 1;
  AverageTimeMultiplyNormal->size[1] = i0;
  emxEnsureCapacity_real_T(AverageTimeMultiplyNormal, k);
  k = AverageTimeMultiplySmart->size[0] * AverageTimeMultiplySmart->size[1];
  AverageTimeMultiplySmart->size[0] = 1;
  AverageTimeMultiplySmart->size[1] = i0;
  emxEnsureCapacity_real_T(AverageTimeMultiplySmart, k);
  emxInit_real_T(&cholesky, 2);
  emxInit_real_T(&y_result, 2);
  emxInit_real_T(&x_result, 2);
  emxInit_real_T(&u, 2);
  for (n = 0; n < i0; n++) {
    /*  opts settings */
    /* Calculate elapse time LinSolve start */
    time = 0;
    PLXAtimeinterval_start(&time);

    /* Forward */
    linsolve_blas(L, B, data_nrow, data_ncol, y_result);

    /* Backward */
    b_linsolve_blas(U, y_result, data_nrow, data_ncol, x_result);

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

    k = cholesky->size[0] * cholesky->size[1];
    cholesky->size[0] = loop_ub;
    cholesky->size[1] = b_loop_ub;
    emxEnsureCapacity_real_T(cholesky, k);
    for (k = 0; k < b_loop_ub; k++) {
      for (inner = 0; inner < loop_ub; inner++) {
        cholesky->data[inner + cholesky->size[0] * k] = A->data[inner + A->size
          [0] * k];
      }
    }

    if (b_loop_ub != 0) {
      i = 0;
      if ((loop_ub != 0) && (b_loop_ub != 0)) {
        j = 0;
        exitg1 = false;
        while ((!exitg1) && (j <= loop_ub - 1)) {
          jj = j + j * b_loop_ub;
          temp = 0.0;
          if (j >= 1) {
            ix = j;
            iy = j;
            for (k = 0; k < j; k++) {
              temp += cholesky->data[ix] * cholesky->data[iy];
              ix += b_loop_ub;
              iy += b_loop_ub;
            }
          }

          temp = cholesky->data[jj] - temp;
          if (temp > 0.0) {
            temp = sqrt(temp);
            cholesky->data[jj] = temp;
            if (j + 1 < loop_ub) {
              coffset = (loop_ub - j) - 1;
              boffset = j + 2;
              if ((coffset == 0) || (j == 0)) {
              } else {
                ix = j;
                k = (j + b_loop_ub * (j - 1)) + 2;
                for (aoffset = boffset; b_loop_ub < 0 ? aoffset >= k : aoffset <=
                     k; aoffset += b_loop_ub) {
                  c = -cholesky->data[ix];
                  iy = jj + 1;
                  inner = (aoffset + coffset) - 1;
                  for (m = aoffset; m <= inner; m++) {
                    cholesky->data[iy] += cholesky->data[m - 1] * c;
                    iy++;
                  }

                  ix += b_loop_ub;
                }
              }

              xscal(coffset, 1.0 / temp, cholesky, jj + 2);
            }

            j++;
          } else {
            cholesky->data[jj] = temp;
            i = j + 1;
            exitg1 = true;
          }
        }
      }

      if (i == 0) {
        coffset = b_loop_ub;
      } else {
        coffset = i - 1;
      }

      for (j = 2; j <= coffset; j++) {
        for (i = 0; i <= j - 2; i++) {
          cholesky->data[i + cholesky->size[0] * (j - 1)] = 0.0;
        }
      }
    }

    /* Calculate elapse time Cholesky end */
    AverageTimeCholesky->data[n] = time_diff_msec(time);

    /* Calculate SVD   */
    /* Calculate elapse time SVD start */
    PLXAtimeinterval_start(&time);
    SVD(A, buf_size, buf_size, u, a, b);

    /* Calculate elapse time SVD end */
    AverageTimeSVD->data[n] = time_diff_msec(time);

    /* Calculate Multiplication Normal */
    /* Calculate elapse time Multiplication Normal start */
    PLXAtimeinterval_start(&time);
    multiply_Smart(A, B, buf_size, buf_size, a);

    /* Calculate elapse time Multiplication Normal end */
    AverageTimeMultiplyNormal->data[n] = time_diff_msec(time);

    /* Calculate Multiplication Smart */
    /* Calculate elapse time Multiplication Smart start */
    PLXAtimeinterval_start(&time);
    multiply_Smart(A, B, data_nrow, data_ncol, b);

    /* Calculate elapse time Multiplication Smart end */
    AverageTimeMultiplySmart->data[n] = time_diff_msec(time);

    /* Save/Check Results and Precision  */
    f3_array_save_bin(x_result);
    b_f3_array_save_bin(y_result);
    c_f3_array_save_bin(cholesky);
    d_f3_array_save_bin(u);
    e_f3_array_save_bin(a);
    f_f3_array_save_bin(b);
  }

  emxFree_real_T(&b);
  emxFree_real_T(&a);
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
      temp = rtNaN;
    } else if (AverageTimeLinSolve->size[1] == 1) {
      temp = AverageTimeLinSolve->data[0];
    } else if ((AverageTimeLinSolve->data[0] < AverageTimeLinSolve->data[1]) ||
               (rtIsNaN(AverageTimeLinSolve->data[0]) && (!rtIsNaN
                 (AverageTimeLinSolve->data[1])))) {
      temp = AverageTimeLinSolve->data[1];
    } else {
      temp = AverageTimeLinSolve->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeLinSolve->data[0])) {
      coffset = 1;
    } else {
      coffset = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= AverageTimeLinSolve->size[1])) {
        if (!rtIsNaN(AverageTimeLinSolve->data[k - 1])) {
          coffset = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (coffset == 0) {
      temp = AverageTimeLinSolve->data[0];
    } else {
      temp = AverageTimeLinSolve->data[coffset - 1];
      i0 = coffset + 1;
      for (k = i0; k <= n; k++) {
        if (temp < AverageTimeLinSolve->data[k - 1]) {
          temp = AverageTimeLinSolve->data[k - 1];
        }
      }
    }
  }

  printf("Worst Time LinSolve: %gms\n", temp / 1000.0);
  fflush(stdout);
  printf("Average Time LinSolve: %gms\n", mean(AverageTimeLinSolve) / 1000.0);
  fflush(stdout);
  n = AverageTimeLinSolve->size[1];
  if (AverageTimeLinSolve->size[1] <= 2) {
    if (AverageTimeLinSolve->size[1] == 0) {
      temp = rtNaN;
    } else if (AverageTimeLinSolve->size[1] == 1) {
      temp = AverageTimeLinSolve->data[0];
    } else if ((AverageTimeLinSolve->data[0] > AverageTimeLinSolve->data[1]) ||
               (rtIsNaN(AverageTimeLinSolve->data[0]) && (!rtIsNaN
                 (AverageTimeLinSolve->data[1])))) {
      temp = AverageTimeLinSolve->data[1];
    } else {
      temp = AverageTimeLinSolve->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeLinSolve->data[0])) {
      coffset = 1;
    } else {
      coffset = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= AverageTimeLinSolve->size[1])) {
        if (!rtIsNaN(AverageTimeLinSolve->data[k - 1])) {
          coffset = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (coffset == 0) {
      temp = AverageTimeLinSolve->data[0];
    } else {
      temp = AverageTimeLinSolve->data[coffset - 1];
      i0 = coffset + 1;
      for (k = i0; k <= n; k++) {
        if (temp > AverageTimeLinSolve->data[k - 1]) {
          temp = AverageTimeLinSolve->data[k - 1];
        }
      }
    }
  }

  emxFree_real_T(&AverageTimeLinSolve);
  printf("Best Time LinSolve: %gms\n\n", temp / 1000.0);
  fflush(stdout);
  n = AverageTimeMultiplySmart->size[1];
  if (AverageTimeMultiplySmart->size[1] <= 2) {
    if (AverageTimeMultiplySmart->size[1] == 0) {
      temp = rtNaN;
    } else if (AverageTimeMultiplySmart->size[1] == 1) {
      temp = AverageTimeMultiplySmart->data[0];
    } else if ((AverageTimeMultiplySmart->data[0] <
                AverageTimeMultiplySmart->data[1]) || (rtIsNaN
                (AverageTimeMultiplySmart->data[0]) && (!rtIsNaN
                 (AverageTimeMultiplySmart->data[1])))) {
      temp = AverageTimeMultiplySmart->data[1];
    } else {
      temp = AverageTimeMultiplySmart->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeMultiplySmart->data[0])) {
      coffset = 1;
    } else {
      coffset = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= AverageTimeMultiplySmart->size[1])) {
        if (!rtIsNaN(AverageTimeMultiplySmart->data[k - 1])) {
          coffset = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (coffset == 0) {
      temp = AverageTimeMultiplySmart->data[0];
    } else {
      temp = AverageTimeMultiplySmart->data[coffset - 1];
      i0 = coffset + 1;
      for (k = i0; k <= n; k++) {
        if (temp < AverageTimeMultiplySmart->data[k - 1]) {
          temp = AverageTimeMultiplySmart->data[k - 1];
        }
      }
    }
  }

  printf("Worst Time Multiply Smart: %gms\n", temp / 1000.0);
  fflush(stdout);
  printf("Average Time Multiply Smart: %gms\n", mean(AverageTimeMultiplySmart) /
         1000.0);
  fflush(stdout);
  n = AverageTimeMultiplySmart->size[1];
  if (AverageTimeMultiplySmart->size[1] <= 2) {
    if (AverageTimeMultiplySmart->size[1] == 0) {
      temp = rtNaN;
    } else if (AverageTimeMultiplySmart->size[1] == 1) {
      temp = AverageTimeMultiplySmart->data[0];
    } else if ((AverageTimeMultiplySmart->data[0] >
                AverageTimeMultiplySmart->data[1]) || (rtIsNaN
                (AverageTimeMultiplySmart->data[0]) && (!rtIsNaN
                 (AverageTimeMultiplySmart->data[1])))) {
      temp = AverageTimeMultiplySmart->data[1];
    } else {
      temp = AverageTimeMultiplySmart->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeMultiplySmart->data[0])) {
      coffset = 1;
    } else {
      coffset = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= AverageTimeMultiplySmart->size[1])) {
        if (!rtIsNaN(AverageTimeMultiplySmart->data[k - 1])) {
          coffset = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (coffset == 0) {
      temp = AverageTimeMultiplySmart->data[0];
    } else {
      temp = AverageTimeMultiplySmart->data[coffset - 1];
      i0 = coffset + 1;
      for (k = i0; k <= n; k++) {
        if (temp > AverageTimeMultiplySmart->data[k - 1]) {
          temp = AverageTimeMultiplySmart->data[k - 1];
        }
      }
    }
  }

  emxFree_real_T(&AverageTimeMultiplySmart);
  printf("Best Time Multiply Smart: %gms\n", temp / 1000.0);
  fflush(stdout);
  printf("\nDifferent values with size change (Cholesky, SVD, Normal Multiply): \n\n");
  fflush(stdout);
  n = AverageTimeCholesky->size[1];
  if (AverageTimeCholesky->size[1] <= 2) {
    if (AverageTimeCholesky->size[1] == 0) {
      temp = rtNaN;
    } else if (AverageTimeCholesky->size[1] == 1) {
      temp = AverageTimeCholesky->data[0];
    } else if ((AverageTimeCholesky->data[0] < AverageTimeCholesky->data[1]) ||
               (rtIsNaN(AverageTimeCholesky->data[0]) && (!rtIsNaN
                 (AverageTimeCholesky->data[1])))) {
      temp = AverageTimeCholesky->data[1];
    } else {
      temp = AverageTimeCholesky->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeCholesky->data[0])) {
      coffset = 1;
    } else {
      coffset = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= AverageTimeCholesky->size[1])) {
        if (!rtIsNaN(AverageTimeCholesky->data[k - 1])) {
          coffset = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (coffset == 0) {
      temp = AverageTimeCholesky->data[0];
    } else {
      temp = AverageTimeCholesky->data[coffset - 1];
      i0 = coffset + 1;
      for (k = i0; k <= n; k++) {
        if (temp < AverageTimeCholesky->data[k - 1]) {
          temp = AverageTimeCholesky->data[k - 1];
        }
      }
    }
  }

  printf("Worst Time Cholesky: %gms\n", temp / 1000.0);
  fflush(stdout);
  printf("Average Time Cholesky: %gms\n", mean(AverageTimeCholesky) / 1000.0);
  fflush(stdout);
  n = AverageTimeCholesky->size[1];
  if (AverageTimeCholesky->size[1] <= 2) {
    if (AverageTimeCholesky->size[1] == 0) {
      temp = rtNaN;
    } else if (AverageTimeCholesky->size[1] == 1) {
      temp = AverageTimeCholesky->data[0];
    } else if ((AverageTimeCholesky->data[0] > AverageTimeCholesky->data[1]) ||
               (rtIsNaN(AverageTimeCholesky->data[0]) && (!rtIsNaN
                 (AverageTimeCholesky->data[1])))) {
      temp = AverageTimeCholesky->data[1];
    } else {
      temp = AverageTimeCholesky->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeCholesky->data[0])) {
      coffset = 1;
    } else {
      coffset = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= AverageTimeCholesky->size[1])) {
        if (!rtIsNaN(AverageTimeCholesky->data[k - 1])) {
          coffset = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (coffset == 0) {
      temp = AverageTimeCholesky->data[0];
    } else {
      temp = AverageTimeCholesky->data[coffset - 1];
      i0 = coffset + 1;
      for (k = i0; k <= n; k++) {
        if (temp > AverageTimeCholesky->data[k - 1]) {
          temp = AverageTimeCholesky->data[k - 1];
        }
      }
    }
  }

  emxFree_real_T(&AverageTimeCholesky);
  printf("Best Time Cholesky: %gms\n\n", temp / 1000.0);
  fflush(stdout);
  n = AverageTimeSVD->size[1];
  if (AverageTimeSVD->size[1] <= 2) {
    if (AverageTimeSVD->size[1] == 0) {
      temp = rtNaN;
    } else if (AverageTimeSVD->size[1] == 1) {
      temp = AverageTimeSVD->data[0];
    } else if ((AverageTimeSVD->data[0] < AverageTimeSVD->data[1]) || (rtIsNaN
                (AverageTimeSVD->data[0]) && (!rtIsNaN(AverageTimeSVD->data[1]))))
    {
      temp = AverageTimeSVD->data[1];
    } else {
      temp = AverageTimeSVD->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeSVD->data[0])) {
      coffset = 1;
    } else {
      coffset = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= AverageTimeSVD->size[1])) {
        if (!rtIsNaN(AverageTimeSVD->data[k - 1])) {
          coffset = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (coffset == 0) {
      temp = AverageTimeSVD->data[0];
    } else {
      temp = AverageTimeSVD->data[coffset - 1];
      i0 = coffset + 1;
      for (k = i0; k <= n; k++) {
        if (temp < AverageTimeSVD->data[k - 1]) {
          temp = AverageTimeSVD->data[k - 1];
        }
      }
    }
  }

  printf("Worst Time SVD: %gms\n", temp / 1000.0);
  fflush(stdout);
  printf("Average Time SVD: %gms\n", mean(AverageTimeSVD) / 1000.0);
  fflush(stdout);
  n = AverageTimeSVD->size[1];
  if (AverageTimeSVD->size[1] <= 2) {
    if (AverageTimeSVD->size[1] == 0) {
      temp = rtNaN;
    } else if (AverageTimeSVD->size[1] == 1) {
      temp = AverageTimeSVD->data[0];
    } else if ((AverageTimeSVD->data[0] > AverageTimeSVD->data[1]) || (rtIsNaN
                (AverageTimeSVD->data[0]) && (!rtIsNaN(AverageTimeSVD->data[1]))))
    {
      temp = AverageTimeSVD->data[1];
    } else {
      temp = AverageTimeSVD->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeSVD->data[0])) {
      coffset = 1;
    } else {
      coffset = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= AverageTimeSVD->size[1])) {
        if (!rtIsNaN(AverageTimeSVD->data[k - 1])) {
          coffset = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (coffset == 0) {
      temp = AverageTimeSVD->data[0];
    } else {
      temp = AverageTimeSVD->data[coffset - 1];
      i0 = coffset + 1;
      for (k = i0; k <= n; k++) {
        if (temp > AverageTimeSVD->data[k - 1]) {
          temp = AverageTimeSVD->data[k - 1];
        }
      }
    }
  }

  emxFree_real_T(&AverageTimeSVD);
  printf("Best Time SVD: %gms\n\n", temp / 1000.0);
  fflush(stdout);
  n = AverageTimeMultiplyNormal->size[1];
  if (AverageTimeMultiplyNormal->size[1] <= 2) {
    if (AverageTimeMultiplyNormal->size[1] == 0) {
      temp = rtNaN;
    } else if (AverageTimeMultiplyNormal->size[1] == 1) {
      temp = AverageTimeMultiplyNormal->data[0];
    } else if ((AverageTimeMultiplyNormal->data[0] <
                AverageTimeMultiplyNormal->data[1]) || (rtIsNaN
                (AverageTimeMultiplyNormal->data[0]) && (!rtIsNaN
                 (AverageTimeMultiplyNormal->data[1])))) {
      temp = AverageTimeMultiplyNormal->data[1];
    } else {
      temp = AverageTimeMultiplyNormal->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeMultiplyNormal->data[0])) {
      coffset = 1;
    } else {
      coffset = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= AverageTimeMultiplyNormal->size[1])) {
        if (!rtIsNaN(AverageTimeMultiplyNormal->data[k - 1])) {
          coffset = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (coffset == 0) {
      temp = AverageTimeMultiplyNormal->data[0];
    } else {
      temp = AverageTimeMultiplyNormal->data[coffset - 1];
      i0 = coffset + 1;
      for (k = i0; k <= n; k++) {
        if (temp < AverageTimeMultiplyNormal->data[k - 1]) {
          temp = AverageTimeMultiplyNormal->data[k - 1];
        }
      }
    }
  }

  printf("Worst Time Multiply Normal: %gms\n", temp / 1000.0);
  fflush(stdout);
  printf("Average Time Multiply Normal: %gms\n", mean(AverageTimeMultiplyNormal)
         / 1000.0);
  fflush(stdout);
  n = AverageTimeMultiplyNormal->size[1];
  if (AverageTimeMultiplyNormal->size[1] <= 2) {
    if (AverageTimeMultiplyNormal->size[1] == 0) {
      temp = rtNaN;
    } else if (AverageTimeMultiplyNormal->size[1] == 1) {
      temp = AverageTimeMultiplyNormal->data[0];
    } else if ((AverageTimeMultiplyNormal->data[0] >
                AverageTimeMultiplyNormal->data[1]) || (rtIsNaN
                (AverageTimeMultiplyNormal->data[0]) && (!rtIsNaN
                 (AverageTimeMultiplyNormal->data[1])))) {
      temp = AverageTimeMultiplyNormal->data[1];
    } else {
      temp = AverageTimeMultiplyNormal->data[0];
    }
  } else {
    if (!rtIsNaN(AverageTimeMultiplyNormal->data[0])) {
      coffset = 1;
    } else {
      coffset = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= AverageTimeMultiplyNormal->size[1])) {
        if (!rtIsNaN(AverageTimeMultiplyNormal->data[k - 1])) {
          coffset = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (coffset == 0) {
      temp = AverageTimeMultiplyNormal->data[0];
    } else {
      temp = AverageTimeMultiplyNormal->data[coffset - 1];
      i0 = coffset + 1;
      for (k = i0; k <= n; k++) {
        if (temp > AverageTimeMultiplyNormal->data[k - 1]) {
          temp = AverageTimeMultiplyNormal->data[k - 1];
        }
      }
    }
  }

  emxFree_real_T(&AverageTimeMultiplyNormal);
  printf("Bes tTime Multiply Normal: %gms\n", temp / 1000.0);
  fflush(stdout);
}

/*
 * File trailer for f3_auto_tester.c
 *
 * [EOF]
 */
