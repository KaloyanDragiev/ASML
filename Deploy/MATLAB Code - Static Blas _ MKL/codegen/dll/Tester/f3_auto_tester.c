/*
 * File: f3_auto_tester.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Tester.h"
#include "f3_auto_tester.h"
#include "mean.h"
#include "Tester_emxutil.h"
#include "f3_array_save_bin.h"
#include "multiply_Smart.h"
#include "SVD.h"
#include "xpotrf.h"
#include "linsolve_blas.h"
#include "Cholesky.h"
#include "randi.h"
#include "cblas.h"
#include <stdio.h>

/* Function Definitions */

/*
 * Initialize
 *  coder.varsize('A', [inf inf], [true true]);
 *  coder.varsize('B', [inf inf], [true true]);
 *  coder.varsize('U', [inf inf], [true true]);
 *  coder.varsize('L', [inf inf], [true true]);
 * Arguments    : void
 * Return Type  : void
 */
void b_f3_auto_tester(void)
{
  static double A[262144];
  int j;
  int jmax;
  static double B[262144];
  static double cholesky[262144];
  static double L[10000];
  emxArray_real_T *y_result;
  emxArray_real_T *x_result;
  double U[10000];
  int n;
  unsigned long time;
  double b_L[10000];
  boolean_T b1;
  double AverageTimeLinSolve[10];
  int i;
  boolean_T exitg1;
  double ex;
  double d1;
  double AverageTimeCholesky[10];
  static double b_A[262144];
  static double V[262144];
  double AverageTimeMultiplySmart[10];
  double AverageTimeSVD[10];
  double c_A[512];
  double normal[512];
  double AverageTimeMultiplyNormal[10];
  double x[100];
  b_randi(A);
  for (j = 0; j < 512; j++) {
    for (jmax = 0; jmax < 512; jmax++) {
      cholesky[jmax + (j << 9)] = A[j + (jmax << 9)];
    }
  }

  memcpy(&B[0], &A[0], sizeof(double) << 18);
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)512, (int)512,
              (int)512, 1.0, &cholesky[0], (int)512, &B[0], (int)512, 0.0, &A[0],
              (int)512);

  /*  LinSolve(Cholesky), SVD, Multiplication */
  /* Calculate Cholesky     */
  b_Cholesky(A, L);
  for (j = 0; j < 100; j++) {
    for (jmax = 0; jmax < 100; jmax++) {
      U[jmax + 100 * j] = L[j + 100 * jmax];
    }
  }

  /* Run the calculations X times for correcteness  */
  emxInit_real_T(&y_result, 2);
  emxInit_real_T(&x_result, 2);
  for (n = 0; n < 10; n++) {
    /*  opts settings */
    /* Calculate elapse time LinSolve start */
    time = 0;
    PLXAtimeinterval_start(&time);

    /* Forward */
    /*      [y_result, L, B] = linsolve_blas(coder.ignoreConst(L), coder.ignoreConst(B), coder.ignoreConst(data_nrow), ... */
    /*      coder.ignoreConst(data_ncol), coder.ignoreConst(opts)); */
    memcpy(&b_L[0], &L[0], 10000U * sizeof(double));
    c_linsolve_blas(b_L, *(double (*)[512])&A[0], y_result);

    /* Backward */
    /*      [x_result, U, y_result] = linsolve_blas(coder.ignoreConst(U), coder.ignoreConst(y_result), coder.ignoreConst(data_nrow), ...  */
    /*      coder.ignoreConst(data_ncol), coder.ignoreConst(opts));     */
    memcpy(&b_L[0], &U[0], 10000U * sizeof(double));
    b_linsolve_blas(b_L, y_result, x_result);

    /* Calculate elapse time LinSolve end */
    AverageTimeLinSolve[n] = time_diff_msec(time);

    /* Calculate Cholesky   */
    /* Calculate elapse time Cholesky start */
    PLXAtimeinterval_start(&time);

    /*      chol = Cholesky(A, buf_size, buf_size);  */
    memcpy(&cholesky[0], &A[0], sizeof(double) << 18);
    jmax = c_xpotrf(cholesky);
    if (jmax == 0) {
      jmax = 512;
    } else {
      jmax--;
    }

    for (j = 2; j <= jmax; j++) {
      for (i = 0; i <= j - 2; i++) {
        cholesky[i + ((j - 1) << 9)] = 0.0;
      }
    }

    /* Calculate elapse time Cholesky end */
    AverageTimeCholesky[n] = time_diff_msec(time);

    /* Calculate SVD   */
    /* Calculate elapse time SVD start */
    PLXAtimeinterval_start(&time);
    b_SVD(A, B, b_A, V);

    /* Calculate elapse time SVD end */
    AverageTimeSVD[n] = time_diff_msec(time);

    /* Calculate Multiplication Normal */
    /* Calculate elapse time Multiplication Normal start */
    PLXAtimeinterval_start(&time);

    /*      [x, A, B] = multiply_Smart(coder.ignoreConst(A), coder.ignoreConst(B), coder.ignoreConst(buf_size), ... */
    /*           coder.ignoreConst(buf_size));  */
    memcpy(&b_A[0], &A[0], sizeof(double) << 18);
    memcpy(&c_A[0], &A[0], sizeof(double) << 9);
    c_multiply_Smart(b_A, c_A, 512.0, normal);

    /* Calculate elapse time Multiplication Normal end */
    AverageTimeMultiplyNormal[n] = time_diff_msec(time);

    /* Calculate Multiplication Smart */
    /* Calculate elapse time Multiplication Smart start */
    PLXAtimeinterval_start(&time);

    /*      [x, A, B] = multiply_Smart(coder.ignoreConst(A), coder.ignoreConst(B), coder.ignoreConst(data_nrow), ... */
    /*           coder.ignoreConst(data_ncol));  */
    memcpy(&b_A[0], &A[0], sizeof(double) << 18);
    memcpy(&c_A[0], &A[0], sizeof(double) << 9);
    d_multiply_Smart(b_A, c_A, 100.0, x);

    /* Calculate elapse time Multiplication Smart end */
    AverageTimeMultiplySmart[n] = time_diff_msec(time);

    /* Save/Check Results and Precision  */
    f3_array_save_bin(x_result);
    b_f3_array_save_bin(y_result);
    g_f3_array_save_bin(cholesky);
    h_f3_array_save_bin(B);
    i_f3_array_save_bin(normal);
    f_f3_array_save_bin(x);
  }

  emxFree_real_T(&x_result);
  emxFree_real_T(&y_result);
  printf("\n---------------------------------------------------------------\n");
  fflush(stdout);
  printf("For matrix size: %3e\n", 512.0);
  fflush(stdout);
  printf("\nSame values - set range of calcuations 100x100 (LinSolve & Smart Multiply): \n\n");
  fflush(stdout);
  b1 = rtIsNaN(AverageTimeLinSolve[0]);
  if (!b1) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d1 = AverageTimeLinSolve[i - 1];
      if (ex < d1) {
        ex = d1;
      }
    }
  }

  printf("Worst Time LinSolve: %gms\n", ex / 1000.0);
  fflush(stdout);
  printf("Average Time LinSolve: %gms\n", mean(AverageTimeLinSolve) / 1000.0);
  fflush(stdout);
  if (!b1) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d1 = AverageTimeLinSolve[i - 1];
      if (ex > d1) {
        ex = d1;
      }
    }
  }

  printf("Best Time LinSolve: %gms\n\n", ex / 1000.0);
  fflush(stdout);
  b1 = rtIsNaN(AverageTimeMultiplySmart[0]);
  if (!b1) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d1 = AverageTimeMultiplySmart[i - 1];
      if (ex < d1) {
        ex = d1;
      }
    }
  }

  printf("Worst Time Multiply Smart: %gms\n", ex / 1000.0);
  fflush(stdout);
  printf("Average Time Multiply Smart: %gms\n", mean(AverageTimeMultiplySmart) /
         1000.0);
  fflush(stdout);
  if (!b1) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d1 = AverageTimeMultiplySmart[i - 1];
      if (ex > d1) {
        ex = d1;
      }
    }
  }

  printf("Best Time Multiply Smart: %gms\n", ex / 1000.0);
  fflush(stdout);
  printf("\nDifferent values with size change (Cholesky, SVD, Normal Multiply): \n\n");
  fflush(stdout);
  b1 = rtIsNaN(AverageTimeCholesky[0]);
  if (!b1) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d1 = AverageTimeCholesky[i - 1];
      if (ex < d1) {
        ex = d1;
      }
    }
  }

  printf("Worst Time Cholesky: %gms\n", ex / 1000.0);
  fflush(stdout);
  ex = AverageTimeCholesky[0];
  for (i = 0; i < 9; i++) {
    ex += AverageTimeCholesky[i + 1];
  }

  printf("Average Time Cholesky: %gms\n", ex / 10.0 / 1000.0);
  fflush(stdout);
  if (!b1) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d1 = AverageTimeCholesky[i - 1];
      if (ex > d1) {
        ex = d1;
      }
    }
  }

  printf("Best Time Cholesky: %gms\n\n", ex / 1000.0);
  fflush(stdout);
  b1 = rtIsNaN(AverageTimeSVD[0]);
  if (!b1) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeSVD[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d1 = AverageTimeSVD[i - 1];
      if (ex < d1) {
        ex = d1;
      }
    }
  }

  printf("Worst Time SVD: %gms\n", ex / 1000.0);
  fflush(stdout);
  ex = AverageTimeSVD[0];
  for (i = 0; i < 9; i++) {
    ex += AverageTimeSVD[i + 1];
  }

  printf("Average Time SVD: %gms\n", ex / 10.0 / 1000.0);
  fflush(stdout);
  if (!b1) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeSVD[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d1 = AverageTimeSVD[i - 1];
      if (ex > d1) {
        ex = d1;
      }
    }
  }

  printf("Best Time SVD: %gms\n\n", ex / 1000.0);
  fflush(stdout);
  b1 = rtIsNaN(AverageTimeMultiplyNormal[0]);
  if (!b1) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d1 = AverageTimeMultiplyNormal[i - 1];
      if (ex < d1) {
        ex = d1;
      }
    }
  }

  printf("Worst Time Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
  ex = AverageTimeMultiplyNormal[0];
  for (i = 0; i < 9; i++) {
    ex += AverageTimeMultiplyNormal[i + 1];
  }

  printf("Average Time Multiply Normal: %gms\n", ex / 10.0 / 1000.0);
  fflush(stdout);
  if (!b1) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d1 = AverageTimeMultiplyNormal[i - 1];
      if (ex > d1) {
        ex = d1;
      }
    }
  }

  printf("Bes tTime Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
}

/*
 * Initialize
 *  coder.varsize('A', [inf inf], [true true]);
 *  coder.varsize('B', [inf inf], [true true]);
 *  coder.varsize('U', [inf inf], [true true]);
 *  coder.varsize('L', [inf inf], [true true]);
 * Arguments    : void
 * Return Type  : void
 */
void c_f3_auto_tester(void)
{
  static double A[1048576];
  int j;
  int jmax;
  static double B[1048576];
  static double cholesky[1048576];
  static double L[10000];
  emxArray_real_T *y_result;
  emxArray_real_T *x_result;
  static double U[10000];
  int n;
  unsigned long time;
  double b_L[10000];
  boolean_T b2;
  double AverageTimeLinSolve[10];
  int i;
  boolean_T exitg1;
  double ex;
  double d2;
  double AverageTimeCholesky[10];
  static double b_A[1048576];
  static double V[1048576];
  double AverageTimeMultiplySmart[10];
  double AverageTimeSVD[10];
  double c_A[1024];
  double normal[1024];
  double AverageTimeMultiplyNormal[10];
  double x[100];
  c_randi(A);
  for (j = 0; j < 1024; j++) {
    for (jmax = 0; jmax < 1024; jmax++) {
      cholesky[jmax + (j << 10)] = A[j + (jmax << 10)];
    }
  }

  memcpy(&B[0], &A[0], sizeof(double) << 20);
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)1024, (int)1024,
              (int)1024, 1.0, &cholesky[0], (int)1024, &B[0], (int)1024, 0.0,
              &A[0], (int)1024);

  /*  LinSolve(Cholesky), SVD, Multiplication */
  /* Calculate Cholesky     */
  c_Cholesky(A, L);
  for (j = 0; j < 100; j++) {
    for (jmax = 0; jmax < 100; jmax++) {
      U[jmax + 100 * j] = L[j + 100 * jmax];
    }
  }

  /* Run the calculations X times for correcteness  */
  emxInit_real_T(&y_result, 2);
  emxInit_real_T(&x_result, 2);
  for (n = 0; n < 10; n++) {
    /*  opts settings */
    /* Calculate elapse time LinSolve start */
    time = 0;
    PLXAtimeinterval_start(&time);

    /* Forward */
    /*      [y_result, L, B] = linsolve_blas(coder.ignoreConst(L), coder.ignoreConst(B), coder.ignoreConst(data_nrow), ... */
    /*      coder.ignoreConst(data_ncol), coder.ignoreConst(opts)); */
    memcpy(&b_L[0], &L[0], 10000U * sizeof(double));
    d_linsolve_blas(b_L, *(double (*)[1024])&A[0], y_result);

    /* Backward */
    /*      [x_result, U, y_result] = linsolve_blas(coder.ignoreConst(U), coder.ignoreConst(y_result), coder.ignoreConst(data_nrow), ...  */
    /*      coder.ignoreConst(data_ncol), coder.ignoreConst(opts));     */
    memcpy(&b_L[0], &U[0], 10000U * sizeof(double));
    b_linsolve_blas(b_L, y_result, x_result);

    /* Calculate elapse time LinSolve end */
    AverageTimeLinSolve[n] = time_diff_msec(time);

    /* Calculate Cholesky   */
    /* Calculate elapse time Cholesky start */
    PLXAtimeinterval_start(&time);

    /*      chol = Cholesky(A, buf_size, buf_size);  */
    memcpy(&cholesky[0], &A[0], sizeof(double) << 20);
    jmax = d_xpotrf(cholesky);
    if (jmax == 0) {
      jmax = 1024;
    } else {
      jmax--;
    }

    for (j = 2; j <= jmax; j++) {
      for (i = 0; i <= j - 2; i++) {
        cholesky[i + ((j - 1) << 10)] = 0.0;
      }
    }

    /* Calculate elapse time Cholesky end */
    AverageTimeCholesky[n] = time_diff_msec(time);

    /* Calculate SVD   */
    /* Calculate elapse time SVD start */
    PLXAtimeinterval_start(&time);
    c_SVD(A, B, b_A, V);

    /* Calculate elapse time SVD end */
    AverageTimeSVD[n] = time_diff_msec(time);

    /* Calculate Multiplication Normal */
    /* Calculate elapse time Multiplication Normal start */
    PLXAtimeinterval_start(&time);

    /*      [x, A, B] = multiply_Smart(coder.ignoreConst(A), coder.ignoreConst(B), coder.ignoreConst(buf_size), ... */
    /*           coder.ignoreConst(buf_size));  */
    memcpy(&b_A[0], &A[0], sizeof(double) << 20);
    memcpy(&c_A[0], &A[0], sizeof(double) << 10);
    e_multiply_Smart(b_A, c_A, 1024.0, normal);

    /* Calculate elapse time Multiplication Normal end */
    AverageTimeMultiplyNormal[n] = time_diff_msec(time);

    /* Calculate Multiplication Smart */
    /* Calculate elapse time Multiplication Smart start */
    PLXAtimeinterval_start(&time);

    /*      [x, A, B] = multiply_Smart(coder.ignoreConst(A), coder.ignoreConst(B), coder.ignoreConst(data_nrow), ... */
    /*           coder.ignoreConst(data_ncol));  */
    memcpy(&b_A[0], &A[0], sizeof(double) << 20);
    memcpy(&c_A[0], &A[0], sizeof(double) << 10);
    f_multiply_Smart(b_A, c_A, 100.0, x);

    /* Calculate elapse time Multiplication Smart end */
    AverageTimeMultiplySmart[n] = time_diff_msec(time);

    /* Save/Check Results and Precision  */
    f3_array_save_bin(x_result);
    b_f3_array_save_bin(y_result);
    j_f3_array_save_bin(cholesky);
    k_f3_array_save_bin(B);
    l_f3_array_save_bin(normal);
    f_f3_array_save_bin(x);
  }

  emxFree_real_T(&x_result);
  emxFree_real_T(&y_result);
  printf("\n---------------------------------------------------------------\n");
  fflush(stdout);
  printf("For matrix size: %3e\n", 1024.0);
  fflush(stdout);
  printf("\nSame values - set range of calcuations 100x100 (LinSolve & Smart Multiply): \n\n");
  fflush(stdout);
  b2 = rtIsNaN(AverageTimeLinSolve[0]);
  if (!b2) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d2 = AverageTimeLinSolve[i - 1];
      if (ex < d2) {
        ex = d2;
      }
    }
  }

  printf("Worst Time LinSolve: %gms\n", ex / 1000.0);
  fflush(stdout);
  printf("Average Time LinSolve: %gms\n", mean(AverageTimeLinSolve) / 1000.0);
  fflush(stdout);
  if (!b2) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d2 = AverageTimeLinSolve[i - 1];
      if (ex > d2) {
        ex = d2;
      }
    }
  }

  printf("Best Time LinSolve: %gms\n\n", ex / 1000.0);
  fflush(stdout);
  b2 = rtIsNaN(AverageTimeMultiplySmart[0]);
  if (!b2) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d2 = AverageTimeMultiplySmart[i - 1];
      if (ex < d2) {
        ex = d2;
      }
    }
  }

  printf("Worst Time Multiply Smart: %gms\n", ex / 1000.0);
  fflush(stdout);
  printf("Average Time Multiply Smart: %gms\n", mean(AverageTimeMultiplySmart) /
         1000.0);
  fflush(stdout);
  if (!b2) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d2 = AverageTimeMultiplySmart[i - 1];
      if (ex > d2) {
        ex = d2;
      }
    }
  }

  printf("Best Time Multiply Smart: %gms\n", ex / 1000.0);
  fflush(stdout);
  printf("\nDifferent values with size change (Cholesky, SVD, Normal Multiply): \n\n");
  fflush(stdout);
  b2 = rtIsNaN(AverageTimeCholesky[0]);
  if (!b2) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d2 = AverageTimeCholesky[i - 1];
      if (ex < d2) {
        ex = d2;
      }
    }
  }

  printf("Worst Time Cholesky: %gms\n", ex / 1000.0);
  fflush(stdout);
  ex = AverageTimeCholesky[0];
  for (i = 0; i < 9; i++) {
    ex += AverageTimeCholesky[i + 1];
  }

  printf("Average Time Cholesky: %gms\n", ex / 10.0 / 1000.0);
  fflush(stdout);
  if (!b2) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d2 = AverageTimeCholesky[i - 1];
      if (ex > d2) {
        ex = d2;
      }
    }
  }

  printf("Best Time Cholesky: %gms\n\n", ex / 1000.0);
  fflush(stdout);
  b2 = rtIsNaN(AverageTimeSVD[0]);
  if (!b2) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeSVD[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d2 = AverageTimeSVD[i - 1];
      if (ex < d2) {
        ex = d2;
      }
    }
  }

  printf("Worst Time SVD: %gms\n", ex / 1000.0);
  fflush(stdout);
  ex = AverageTimeSVD[0];
  for (i = 0; i < 9; i++) {
    ex += AverageTimeSVD[i + 1];
  }

  printf("Average Time SVD: %gms\n", ex / 10.0 / 1000.0);
  fflush(stdout);
  if (!b2) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeSVD[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d2 = AverageTimeSVD[i - 1];
      if (ex > d2) {
        ex = d2;
      }
    }
  }

  printf("Best Time SVD: %gms\n\n", ex / 1000.0);
  fflush(stdout);
  b2 = rtIsNaN(AverageTimeMultiplyNormal[0]);
  if (!b2) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d2 = AverageTimeMultiplyNormal[i - 1];
      if (ex < d2) {
        ex = d2;
      }
    }
  }

  printf("Worst Time Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
  ex = AverageTimeMultiplyNormal[0];
  for (i = 0; i < 9; i++) {
    ex += AverageTimeMultiplyNormal[i + 1];
  }

  printf("Average Time Multiply Normal: %gms\n", ex / 10.0 / 1000.0);
  fflush(stdout);
  if (!b2) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d2 = AverageTimeMultiplyNormal[i - 1];
      if (ex > d2) {
        ex = d2;
      }
    }
  }

  printf("Bes tTime Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
}

/*
 * Initialize
 *  coder.varsize('A', [inf inf], [true true]);
 *  coder.varsize('B', [inf inf], [true true]);
 *  coder.varsize('U', [inf inf], [true true]);
 *  coder.varsize('L', [inf inf], [true true]);
 * Arguments    : void
 * Return Type  : void
 */
void d_f3_auto_tester(void)
{
  static double A[4194304];
  int j;
  int jmax;
  static double B[4194304];
  static double cholesky[4194304];
  static double L[10000];
  emxArray_real_T *y_result;
  emxArray_real_T *x_result;
  static double U[10000];
  int n;
  unsigned long time;
  double b_L[10000];
  boolean_T b3;
  double AverageTimeLinSolve[10];
  int i;
  boolean_T exitg1;
  double ex;
  double d3;
  double AverageTimeCholesky[10];
  static double b_A[4194304];
  static double V[4194304];
  double AverageTimeMultiplySmart[10];
  double AverageTimeSVD[10];
  double c_A[2048];
  double normal[2048];
  double AverageTimeMultiplyNormal[10];
  double x[100];
  d_randi(A);
  for (j = 0; j < 2048; j++) {
    for (jmax = 0; jmax < 2048; jmax++) {
      cholesky[jmax + (j << 11)] = A[j + (jmax << 11)];
    }
  }

  memcpy(&B[0], &A[0], sizeof(double) << 22);
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)2048, (int)2048,
              (int)2048, 1.0, &cholesky[0], (int)2048, &B[0], (int)2048, 0.0,
              &A[0], (int)2048);

  /*  LinSolve(Cholesky), SVD, Multiplication */
  /* Calculate Cholesky     */
  d_Cholesky(A, L);
  for (j = 0; j < 100; j++) {
    for (jmax = 0; jmax < 100; jmax++) {
      U[jmax + 100 * j] = L[j + 100 * jmax];
    }
  }

  /* Run the calculations X times for correcteness  */
  emxInit_real_T(&y_result, 2);
  emxInit_real_T(&x_result, 2);
  for (n = 0; n < 10; n++) {
    /*  opts settings */
    /* Calculate elapse time LinSolve start */
    time = 0;
    PLXAtimeinterval_start(&time);

    /* Forward */
    /*      [y_result, L, B] = linsolve_blas(coder.ignoreConst(L), coder.ignoreConst(B), coder.ignoreConst(data_nrow), ... */
    /*      coder.ignoreConst(data_ncol), coder.ignoreConst(opts)); */
    memcpy(&b_L[0], &L[0], 10000U * sizeof(double));
    e_linsolve_blas(b_L, *(double (*)[2048])&A[0], y_result);

    /* Backward */
    /*      [x_result, U, y_result] = linsolve_blas(coder.ignoreConst(U), coder.ignoreConst(y_result), coder.ignoreConst(data_nrow), ...  */
    /*      coder.ignoreConst(data_ncol), coder.ignoreConst(opts));     */
    memcpy(&b_L[0], &U[0], 10000U * sizeof(double));
    b_linsolve_blas(b_L, y_result, x_result);

    /* Calculate elapse time LinSolve end */
    AverageTimeLinSolve[n] = time_diff_msec(time);

    /* Calculate Cholesky   */
    /* Calculate elapse time Cholesky start */
    PLXAtimeinterval_start(&time);

    /*      chol = Cholesky(A, buf_size, buf_size);  */
    memcpy(&cholesky[0], &A[0], sizeof(double) << 22);
    jmax = e_xpotrf(cholesky);
    if (jmax == 0) {
      jmax = 2048;
    } else {
      jmax--;
    }

    for (j = 2; j <= jmax; j++) {
      for (i = 0; i <= j - 2; i++) {
        cholesky[i + ((j - 1) << 11)] = 0.0;
      }
    }

    /* Calculate elapse time Cholesky end */
    AverageTimeCholesky[n] = time_diff_msec(time);

    /* Calculate SVD   */
    /* Calculate elapse time SVD start */
    PLXAtimeinterval_start(&time);
    d_SVD(A, B, b_A, V);

    /* Calculate elapse time SVD end */
    AverageTimeSVD[n] = time_diff_msec(time);

    /* Calculate Multiplication Normal */
    /* Calculate elapse time Multiplication Normal start */
    PLXAtimeinterval_start(&time);

    /*      [x, A, B] = multiply_Smart(coder.ignoreConst(A), coder.ignoreConst(B), coder.ignoreConst(buf_size), ... */
    /*           coder.ignoreConst(buf_size));  */
    memcpy(&b_A[0], &A[0], sizeof(double) << 22);
    memcpy(&c_A[0], &A[0], sizeof(double) << 11);
    g_multiply_Smart(b_A, c_A, 2048.0, normal);

    /* Calculate elapse time Multiplication Normal end */
    AverageTimeMultiplyNormal[n] = time_diff_msec(time);

    /* Calculate Multiplication Smart */
    /* Calculate elapse time Multiplication Smart start */
    PLXAtimeinterval_start(&time);

    /*      [x, A, B] = multiply_Smart(coder.ignoreConst(A), coder.ignoreConst(B), coder.ignoreConst(data_nrow), ... */
    /*           coder.ignoreConst(data_ncol));  */
    memcpy(&b_A[0], &A[0], sizeof(double) << 22);
    memcpy(&c_A[0], &A[0], sizeof(double) << 11);
    h_multiply_Smart(b_A, c_A, 100.0, x);

    /* Calculate elapse time Multiplication Smart end */
    AverageTimeMultiplySmart[n] = time_diff_msec(time);

    /* Save/Check Results and Precision  */
    f3_array_save_bin(x_result);
    b_f3_array_save_bin(y_result);
    m_f3_array_save_bin(cholesky);
    n_f3_array_save_bin(B);
    o_f3_array_save_bin(normal);
    f_f3_array_save_bin(x);
  }

  emxFree_real_T(&x_result);
  emxFree_real_T(&y_result);
  printf("\n---------------------------------------------------------------\n");
  fflush(stdout);
  printf("For matrix size: %3e\n", 2048.0);
  fflush(stdout);
  printf("\nSame values - set range of calcuations 100x100 (LinSolve & Smart Multiply): \n\n");
  fflush(stdout);
  b3 = rtIsNaN(AverageTimeLinSolve[0]);
  if (!b3) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d3 = AverageTimeLinSolve[i - 1];
      if (ex < d3) {
        ex = d3;
      }
    }
  }

  printf("Worst Time LinSolve: %gms\n", ex / 1000.0);
  fflush(stdout);
  printf("Average Time LinSolve: %gms\n", mean(AverageTimeLinSolve) / 1000.0);
  fflush(stdout);
  if (!b3) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d3 = AverageTimeLinSolve[i - 1];
      if (ex > d3) {
        ex = d3;
      }
    }
  }

  printf("Best Time LinSolve: %gms\n\n", ex / 1000.0);
  fflush(stdout);
  b3 = rtIsNaN(AverageTimeMultiplySmart[0]);
  if (!b3) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d3 = AverageTimeMultiplySmart[i - 1];
      if (ex < d3) {
        ex = d3;
      }
    }
  }

  printf("Worst Time Multiply Smart: %gms\n", ex / 1000.0);
  fflush(stdout);
  printf("Average Time Multiply Smart: %gms\n", mean(AverageTimeMultiplySmart) /
         1000.0);
  fflush(stdout);
  if (!b3) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d3 = AverageTimeMultiplySmart[i - 1];
      if (ex > d3) {
        ex = d3;
      }
    }
  }

  printf("Best Time Multiply Smart: %gms\n", ex / 1000.0);
  fflush(stdout);
  printf("\nDifferent values with size change (Cholesky, SVD, Normal Multiply): \n\n");
  fflush(stdout);
  b3 = rtIsNaN(AverageTimeCholesky[0]);
  if (!b3) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d3 = AverageTimeCholesky[i - 1];
      if (ex < d3) {
        ex = d3;
      }
    }
  }

  printf("Worst Time Cholesky: %gms\n", ex / 1000.0);
  fflush(stdout);
  ex = AverageTimeCholesky[0];
  for (i = 0; i < 9; i++) {
    ex += AverageTimeCholesky[i + 1];
  }

  printf("Average Time Cholesky: %gms\n", ex / 10.0 / 1000.0);
  fflush(stdout);
  if (!b3) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d3 = AverageTimeCholesky[i - 1];
      if (ex > d3) {
        ex = d3;
      }
    }
  }

  printf("Best Time Cholesky: %gms\n\n", ex / 1000.0);
  fflush(stdout);
  b3 = rtIsNaN(AverageTimeSVD[0]);
  if (!b3) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeSVD[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d3 = AverageTimeSVD[i - 1];
      if (ex < d3) {
        ex = d3;
      }
    }
  }

  printf("Worst Time SVD: %gms\n", ex / 1000.0);
  fflush(stdout);
  ex = AverageTimeSVD[0];
  for (i = 0; i < 9; i++) {
    ex += AverageTimeSVD[i + 1];
  }

  printf("Average Time SVD: %gms\n", ex / 10.0 / 1000.0);
  fflush(stdout);
  if (!b3) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeSVD[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d3 = AverageTimeSVD[i - 1];
      if (ex > d3) {
        ex = d3;
      }
    }
  }

  printf("Best Time SVD: %gms\n\n", ex / 1000.0);
  fflush(stdout);
  b3 = rtIsNaN(AverageTimeMultiplyNormal[0]);
  if (!b3) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d3 = AverageTimeMultiplyNormal[i - 1];
      if (ex < d3) {
        ex = d3;
      }
    }
  }

  printf("Worst Time Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
  ex = AverageTimeMultiplyNormal[0];
  for (i = 0; i < 9; i++) {
    ex += AverageTimeMultiplyNormal[i + 1];
  }

  printf("Average Time Multiply Normal: %gms\n", ex / 10.0 / 1000.0);
  fflush(stdout);
  if (!b3) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d3 = AverageTimeMultiplyNormal[i - 1];
      if (ex > d3) {
        ex = d3;
      }
    }
  }

  printf("Bes tTime Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
}

/*
 * Initialize
 *  coder.varsize('A', [inf inf], [true true]);
 *  coder.varsize('B', [inf inf], [true true]);
 *  coder.varsize('U', [inf inf], [true true]);
 *  coder.varsize('L', [inf inf], [true true]);
 * Arguments    : void
 * Return Type  : void
 */
void e_f3_auto_tester(void)
{
  static double A[16777216];
  int j;
  int jmax;
  static double B[16777216];
  static double cholesky[16777216];
  static double L[10000];
  emxArray_real_T *y_result;
  emxArray_real_T *x_result;
  static double U[10000];
  int n;
  unsigned long time;
  static double b_L[10000];
  boolean_T b4;
  double AverageTimeLinSolve[10];
  int i;
  boolean_T exitg1;
  double ex;
  double d4;
  double AverageTimeCholesky[10];
  static double b_A[16777216];
  static double V[16777216];
  double AverageTimeMultiplySmart[10];
  double AverageTimeSVD[10];
  double c_A[4096];
  double normal[4096];
  double AverageTimeMultiplyNormal[10];
  double x[100];
  e_randi(A);
  for (j = 0; j < 4096; j++) {
    for (jmax = 0; jmax < 4096; jmax++) {
      cholesky[jmax + (j << 12)] = A[j + (jmax << 12)];
    }
  }

  memcpy(&B[0], &A[0], sizeof(double) << 24);
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)4096, (int)4096,
              (int)4096, 1.0, &cholesky[0], (int)4096, &B[0], (int)4096, 0.0,
              &A[0], (int)4096);

  /*  LinSolve(Cholesky), SVD, Multiplication */
  /* Calculate Cholesky     */
  e_Cholesky(A, L);
  for (j = 0; j < 100; j++) {
    for (jmax = 0; jmax < 100; jmax++) {
      U[jmax + 100 * j] = L[j + 100 * jmax];
    }
  }

  /* Run the calculations X times for correcteness  */
  emxInit_real_T(&y_result, 2);
  emxInit_real_T(&x_result, 2);
  for (n = 0; n < 10; n++) {
    /*  opts settings */
    /* Calculate elapse time LinSolve start */
    time = 0;
    PLXAtimeinterval_start(&time);

    /* Forward */
    /*      [y_result, L, B] = linsolve_blas(coder.ignoreConst(L), coder.ignoreConst(B), coder.ignoreConst(data_nrow), ... */
    /*      coder.ignoreConst(data_ncol), coder.ignoreConst(opts)); */
    memcpy(&b_L[0], &L[0], 10000U * sizeof(double));
    f_linsolve_blas(b_L, *(double (*)[4096])&A[0], y_result);

    /* Backward */
    /*      [x_result, U, y_result] = linsolve_blas(coder.ignoreConst(U), coder.ignoreConst(y_result), coder.ignoreConst(data_nrow), ...  */
    /*      coder.ignoreConst(data_ncol), coder.ignoreConst(opts));     */
    memcpy(&b_L[0], &U[0], 10000U * sizeof(double));
    b_linsolve_blas(b_L, y_result, x_result);

    /* Calculate elapse time LinSolve end */
    AverageTimeLinSolve[n] = time_diff_msec(time);

    /* Calculate Cholesky   */
    /* Calculate elapse time Cholesky start */
    PLXAtimeinterval_start(&time);

    /*      chol = Cholesky(A, buf_size, buf_size);  */
    memcpy(&cholesky[0], &A[0], sizeof(double) << 24);
    jmax = f_xpotrf(cholesky);
    if (jmax == 0) {
      jmax = 4096;
    } else {
      jmax--;
    }

    for (j = 2; j <= jmax; j++) {
      for (i = 0; i <= j - 2; i++) {
        cholesky[i + ((j - 1) << 12)] = 0.0;
      }
    }

    /* Calculate elapse time Cholesky end */
    AverageTimeCholesky[n] = time_diff_msec(time);

    /* Calculate SVD   */
    /* Calculate elapse time SVD start */
    PLXAtimeinterval_start(&time);
    e_SVD(A, B, b_A, V);

    /* Calculate elapse time SVD end */
    AverageTimeSVD[n] = time_diff_msec(time);

    /* Calculate Multiplication Normal */
    /* Calculate elapse time Multiplication Normal start */
    PLXAtimeinterval_start(&time);

    /*      [x, A, B] = multiply_Smart(coder.ignoreConst(A), coder.ignoreConst(B), coder.ignoreConst(buf_size), ... */
    /*           coder.ignoreConst(buf_size));  */
    memcpy(&b_A[0], &A[0], sizeof(double) << 24);
    memcpy(&c_A[0], &A[0], sizeof(double) << 12);
    i_multiply_Smart(b_A, c_A, 4096.0, normal);

    /* Calculate elapse time Multiplication Normal end */
    AverageTimeMultiplyNormal[n] = time_diff_msec(time);

    /* Calculate Multiplication Smart */
    /* Calculate elapse time Multiplication Smart start */
    PLXAtimeinterval_start(&time);

    /*      [x, A, B] = multiply_Smart(coder.ignoreConst(A), coder.ignoreConst(B), coder.ignoreConst(data_nrow), ... */
    /*           coder.ignoreConst(data_ncol));  */
    memcpy(&b_A[0], &A[0], sizeof(double) << 24);
    memcpy(&c_A[0], &A[0], sizeof(double) << 12);
    j_multiply_Smart(b_A, c_A, 100.0, x);

    /* Calculate elapse time Multiplication Smart end */
    AverageTimeMultiplySmart[n] = time_diff_msec(time);

    /* Save/Check Results and Precision  */
    f3_array_save_bin(x_result);
    b_f3_array_save_bin(y_result);
    p_f3_array_save_bin(cholesky);
    q_f3_array_save_bin(B);
    r_f3_array_save_bin(normal);
    f_f3_array_save_bin(x);
  }

  emxFree_real_T(&x_result);
  emxFree_real_T(&y_result);
  printf("\n---------------------------------------------------------------\n");
  fflush(stdout);
  printf("For matrix size: %3e\n", 4096.0);
  fflush(stdout);
  printf("\nSame values - set range of calcuations 100x100 (LinSolve & Smart Multiply): \n\n");
  fflush(stdout);
  b4 = rtIsNaN(AverageTimeLinSolve[0]);
  if (!b4) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d4 = AverageTimeLinSolve[i - 1];
      if (ex < d4) {
        ex = d4;
      }
    }
  }

  printf("Worst Time LinSolve: %gms\n", ex / 1000.0);
  fflush(stdout);
  printf("Average Time LinSolve: %gms\n", mean(AverageTimeLinSolve) / 1000.0);
  fflush(stdout);
  if (!b4) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d4 = AverageTimeLinSolve[i - 1];
      if (ex > d4) {
        ex = d4;
      }
    }
  }

  printf("Best Time LinSolve: %gms\n\n", ex / 1000.0);
  fflush(stdout);
  b4 = rtIsNaN(AverageTimeMultiplySmart[0]);
  if (!b4) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d4 = AverageTimeMultiplySmart[i - 1];
      if (ex < d4) {
        ex = d4;
      }
    }
  }

  printf("Worst Time Multiply Smart: %gms\n", ex / 1000.0);
  fflush(stdout);
  printf("Average Time Multiply Smart: %gms\n", mean(AverageTimeMultiplySmart) /
         1000.0);
  fflush(stdout);
  if (!b4) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d4 = AverageTimeMultiplySmart[i - 1];
      if (ex > d4) {
        ex = d4;
      }
    }
  }

  printf("Best Time Multiply Smart: %gms\n", ex / 1000.0);
  fflush(stdout);
  printf("\nDifferent values with size change (Cholesky, SVD, Normal Multiply): \n\n");
  fflush(stdout);
  b4 = rtIsNaN(AverageTimeCholesky[0]);
  if (!b4) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d4 = AverageTimeCholesky[i - 1];
      if (ex < d4) {
        ex = d4;
      }
    }
  }

  printf("Worst Time Cholesky: %gms\n", ex / 1000.0);
  fflush(stdout);
  ex = AverageTimeCholesky[0];
  for (i = 0; i < 9; i++) {
    ex += AverageTimeCholesky[i + 1];
  }

  printf("Average Time Cholesky: %gms\n", ex / 10.0 / 1000.0);
  fflush(stdout);
  if (!b4) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d4 = AverageTimeCholesky[i - 1];
      if (ex > d4) {
        ex = d4;
      }
    }
  }

  printf("Best Time Cholesky: %gms\n\n", ex / 1000.0);
  fflush(stdout);
  b4 = rtIsNaN(AverageTimeSVD[0]);
  if (!b4) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeSVD[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d4 = AverageTimeSVD[i - 1];
      if (ex < d4) {
        ex = d4;
      }
    }
  }

  printf("Worst Time SVD: %gms\n", ex / 1000.0);
  fflush(stdout);
  ex = AverageTimeSVD[0];
  for (i = 0; i < 9; i++) {
    ex += AverageTimeSVD[i + 1];
  }

  printf("Average Time SVD: %gms\n", ex / 10.0 / 1000.0);
  fflush(stdout);
  if (!b4) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeSVD[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d4 = AverageTimeSVD[i - 1];
      if (ex > d4) {
        ex = d4;
      }
    }
  }

  printf("Best Time SVD: %gms\n\n", ex / 1000.0);
  fflush(stdout);
  b4 = rtIsNaN(AverageTimeMultiplyNormal[0]);
  if (!b4) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d4 = AverageTimeMultiplyNormal[i - 1];
      if (ex < d4) {
        ex = d4;
      }
    }
  }

  printf("Worst Time Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
  ex = AverageTimeMultiplyNormal[0];
  for (i = 0; i < 9; i++) {
    ex += AverageTimeMultiplyNormal[i + 1];
  }

  printf("Average Time Multiply Normal: %gms\n", ex / 10.0 / 1000.0);
  fflush(stdout);
  if (!b4) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d4 = AverageTimeMultiplyNormal[i - 1];
      if (ex > d4) {
        ex = d4;
      }
    }
  }

  printf("Bes tTime Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
}

/*
 * Initialize
 *  coder.varsize('A', [inf inf], [true true]);
 *  coder.varsize('B', [inf inf], [true true]);
 *  coder.varsize('U', [inf inf], [true true]);
 *  coder.varsize('L', [inf inf], [true true]);
 * Arguments    : void
 * Return Type  : void
 */
void f3_auto_tester(void)
{
  static double A[65536];
  int j;
  int jmax;
  static double B[65536];
  static double cholesky[65536];
  static double L[10000];
  emxArray_real_T *y_result;
  emxArray_real_T *x_result;
  double U[10000];
  int n;
  unsigned long time;
  double b_L[10000];
  boolean_T b0;
  double AverageTimeLinSolve[10];
  int i;
  boolean_T exitg1;
  double ex;
  double d0;
  double AverageTimeCholesky[10];
  static double b_A[65536];
  static double V[65536];
  double AverageTimeMultiplySmart[10];
  double AverageTimeSVD[10];
  double c_A[256];
  double normal[256];
  double AverageTimeMultiplyNormal[10];
  double x[100];
  randi(A);
  for (j = 0; j < 256; j++) {
    for (jmax = 0; jmax < 256; jmax++) {
      cholesky[jmax + (j << 8)] = A[j + (jmax << 8)];
    }
  }

  memcpy(&B[0], &A[0], sizeof(double) << 16);
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)256, (int)256,
              (int)256, 1.0, &cholesky[0], (int)256, &B[0], (int)256, 0.0, &A[0],
              (int)256);

  /*  LinSolve(Cholesky), SVD, Multiplication */
  /* Calculate Cholesky     */
  Cholesky(A, L);
  for (j = 0; j < 100; j++) {
    for (jmax = 0; jmax < 100; jmax++) {
      U[jmax + 100 * j] = L[j + 100 * jmax];
    }
  }

  /* Run the calculations X times for correcteness  */
  emxInit_real_T(&y_result, 2);
  emxInit_real_T(&x_result, 2);
  for (n = 0; n < 10; n++) {
    /*  opts settings */
    /* Calculate elapse time LinSolve start */
    time = 0;
    PLXAtimeinterval_start(&time);

    /* Forward */
    /*      [y_result, L, B] = linsolve_blas(coder.ignoreConst(L), coder.ignoreConst(B), coder.ignoreConst(data_nrow), ... */
    /*      coder.ignoreConst(data_ncol), coder.ignoreConst(opts)); */
    memcpy(&b_L[0], &L[0], 10000U * sizeof(double));
    linsolve_blas(b_L, *(double (*)[256])&A[0], y_result);

    /* Backward */
    /*      [x_result, U, y_result] = linsolve_blas(coder.ignoreConst(U), coder.ignoreConst(y_result), coder.ignoreConst(data_nrow), ...  */
    /*      coder.ignoreConst(data_ncol), coder.ignoreConst(opts));     */
    memcpy(&b_L[0], &U[0], 10000U * sizeof(double));
    b_linsolve_blas(b_L, y_result, x_result);

    /* Calculate elapse time LinSolve end */
    AverageTimeLinSolve[n] = time_diff_msec(time);

    /* Calculate Cholesky   */
    /* Calculate elapse time Cholesky start */
    PLXAtimeinterval_start(&time);

    /*      chol = Cholesky(A, buf_size, buf_size);  */
    memcpy(&cholesky[0], &A[0], sizeof(double) << 16);
    jmax = b_xpotrf(cholesky);
    if (jmax == 0) {
      jmax = 256;
    } else {
      jmax--;
    }

    for (j = 2; j <= jmax; j++) {
      for (i = 0; i <= j - 2; i++) {
        cholesky[i + ((j - 1) << 8)] = 0.0;
      }
    }

    /* Calculate elapse time Cholesky end */
    AverageTimeCholesky[n] = time_diff_msec(time);

    /* Calculate SVD   */
    /* Calculate elapse time SVD start */
    PLXAtimeinterval_start(&time);
    SVD(A, B, b_A, V);

    /* Calculate elapse time SVD end */
    AverageTimeSVD[n] = time_diff_msec(time);

    /* Calculate Multiplication Normal */
    /* Calculate elapse time Multiplication Normal start */
    PLXAtimeinterval_start(&time);

    /*      [x, A, B] = multiply_Smart(coder.ignoreConst(A), coder.ignoreConst(B), coder.ignoreConst(buf_size), ... */
    /*           coder.ignoreConst(buf_size));  */
    memcpy(&b_A[0], &A[0], sizeof(double) << 16);
    memcpy(&c_A[0], &A[0], sizeof(double) << 8);
    multiply_Smart(b_A, c_A, 256.0, normal);

    /* Calculate elapse time Multiplication Normal end */
    AverageTimeMultiplyNormal[n] = time_diff_msec(time);

    /* Calculate Multiplication Smart */
    /* Calculate elapse time Multiplication Smart start */
    PLXAtimeinterval_start(&time);

    /*      [x, A, B] = multiply_Smart(coder.ignoreConst(A), coder.ignoreConst(B), coder.ignoreConst(data_nrow), ... */
    /*           coder.ignoreConst(data_ncol));  */
    memcpy(&b_A[0], &A[0], sizeof(double) << 16);
    memcpy(&c_A[0], &A[0], sizeof(double) << 8);
    b_multiply_Smart(b_A, c_A, 100.0, x);

    /* Calculate elapse time Multiplication Smart end */
    AverageTimeMultiplySmart[n] = time_diff_msec(time);

    /* Save/Check Results and Precision  */
    f3_array_save_bin(x_result);
    b_f3_array_save_bin(y_result);
    c_f3_array_save_bin(cholesky);
    d_f3_array_save_bin(B);
    e_f3_array_save_bin(normal);
    f_f3_array_save_bin(x);
  }

  emxFree_real_T(&x_result);
  emxFree_real_T(&y_result);
  printf("\n---------------------------------------------------------------\n");
  fflush(stdout);
  printf("For matrix size: %3e\n", 256.0);
  fflush(stdout);
  printf("\nSame values - set range of calcuations 100x100 (LinSolve & Smart Multiply): \n\n");
  fflush(stdout);
  b0 = rtIsNaN(AverageTimeLinSolve[0]);
  if (!b0) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d0 = AverageTimeLinSolve[i - 1];
      if (ex < d0) {
        ex = d0;
      }
    }
  }

  printf("Worst Time LinSolve: %gms\n", ex / 1000.0);
  fflush(stdout);
  printf("Average Time LinSolve: %gms\n", mean(AverageTimeLinSolve) / 1000.0);
  fflush(stdout);
  if (!b0) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d0 = AverageTimeLinSolve[i - 1];
      if (ex > d0) {
        ex = d0;
      }
    }
  }

  printf("Best Time LinSolve: %gms\n\n", ex / 1000.0);
  fflush(stdout);
  b0 = rtIsNaN(AverageTimeMultiplySmart[0]);
  if (!b0) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d0 = AverageTimeMultiplySmart[i - 1];
      if (ex < d0) {
        ex = d0;
      }
    }
  }

  printf("Worst Time Multiply Smart: %gms\n", ex / 1000.0);
  fflush(stdout);
  printf("Average Time Multiply Smart: %gms\n", mean(AverageTimeMultiplySmart) /
         1000.0);
  fflush(stdout);
  if (!b0) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d0 = AverageTimeMultiplySmart[i - 1];
      if (ex > d0) {
        ex = d0;
      }
    }
  }

  printf("Best Time Multiply Smart: %gms\n", ex / 1000.0);
  fflush(stdout);
  printf("\nDifferent values with size change (Cholesky, SVD, Normal Multiply): \n\n");
  fflush(stdout);
  b0 = rtIsNaN(AverageTimeCholesky[0]);
  if (!b0) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d0 = AverageTimeCholesky[i - 1];
      if (ex < d0) {
        ex = d0;
      }
    }
  }

  printf("Worst Time Cholesky: %gms\n", ex / 1000.0);
  fflush(stdout);
  ex = AverageTimeCholesky[0];
  for (i = 0; i < 9; i++) {
    ex += AverageTimeCholesky[i + 1];
  }

  printf("Average Time Cholesky: %gms\n", ex / 10.0 / 1000.0);
  fflush(stdout);
  if (!b0) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d0 = AverageTimeCholesky[i - 1];
      if (ex > d0) {
        ex = d0;
      }
    }
  }

  printf("Best Time Cholesky: %gms\n\n", ex / 1000.0);
  fflush(stdout);
  b0 = rtIsNaN(AverageTimeSVD[0]);
  if (!b0) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeSVD[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d0 = AverageTimeSVD[i - 1];
      if (ex < d0) {
        ex = d0;
      }
    }
  }

  printf("Worst Time SVD: %gms\n", ex / 1000.0);
  fflush(stdout);
  ex = AverageTimeSVD[0];
  for (i = 0; i < 9; i++) {
    ex += AverageTimeSVD[i + 1];
  }

  printf("Average Time SVD: %gms\n", ex / 10.0 / 1000.0);
  fflush(stdout);
  if (!b0) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeSVD[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d0 = AverageTimeSVD[i - 1];
      if (ex > d0) {
        ex = d0;
      }
    }
  }

  printf("Best Time SVD: %gms\n\n", ex / 1000.0);
  fflush(stdout);
  b0 = rtIsNaN(AverageTimeMultiplyNormal[0]);
  if (!b0) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d0 = AverageTimeMultiplyNormal[i - 1];
      if (ex < d0) {
        ex = d0;
      }
    }
  }

  printf("Worst Time Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
  ex = AverageTimeMultiplyNormal[0];
  for (i = 0; i < 9; i++) {
    ex += AverageTimeMultiplyNormal[i + 1];
  }

  printf("Average Time Multiply Normal: %gms\n", ex / 10.0 / 1000.0);
  fflush(stdout);
  if (!b0) {
    jmax = 1;
  } else {
    jmax = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[i - 1])) {
        jmax = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    j = jmax + 1;
    for (i = j; i < 11; i++) {
      d0 = AverageTimeMultiplyNormal[i - 1];
      if (ex > d0) {
        ex = d0;
      }
    }
  }

  printf("Bes tTime Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
}

/*
 * File trailer for f3_auto_tester.c
 *
 * [EOF]
 */
