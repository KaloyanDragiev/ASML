/*
 * File: f3_auto_tester.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
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
#include <stdio.h>

/* Function Definitions */

/*
 * Initialize
 * Arguments    : void
 * Return Type  : void
 */
void b_f3_auto_tester(void)
{
  static double A[262144];
  int i3;
  static double cholesky[262144];
  int jmax;
  double B[512];
  int cholesky_tmp;
  int b_cholesky_tmp;
  double L[10000];
  double y;
  int n;
  emxArray_real_T *y_result;
  emxArray_real_T *x_result;
  double U[10000];
  unsigned long time;
  double AverageTimeLinSolve[10];
  boolean_T b1;
  boolean_T exitg1;
  double ex;
  double AverageTimeCholesky[10];
  static double u[262144];
  static double S[262144];
  static double V[262144];
  double AverageTimeSVD[10];
  double normal[512];
  double AverageTimeMultiplySmart[10];
  double AverageTimeMultiplyNormal[10];
  double x[100];
  b_randi(A);
  for (i3 = 0; i3 < 512; i3++) {
    for (jmax = 0; jmax < 512; jmax++) {
      cholesky_tmp = jmax << 9;
      b_cholesky_tmp = i3 + cholesky_tmp;
      cholesky[b_cholesky_tmp] = 0.0;
      y = 0.0;
      for (n = 0; n < 512; n++) {
        y += A[n + (i3 << 9)] * A[n + cholesky_tmp];
      }

      cholesky[b_cholesky_tmp] = y;
    }
  }

  memcpy(&A[0], &cholesky[0], sizeof(double) << 18);
  memcpy(&B[0], &A[0], sizeof(double) << 9);

  /*  LinSolve, Cholesky,  SVD, Multiplication Normal, Smart */
  /* Calculate Cholesky for LinSolve */
  b_Cholesky(A, L);
  for (i3 = 0; i3 < 100; i3++) {
    for (jmax = 0; jmax < 100; jmax++) {
      U[jmax + 100 * i3] = L[i3 + 100 * jmax];
    }
  }

  /* Run the calculations X times for correcteness  */
  emxInit_real_T(&y_result, 1);
  emxInit_real_T(&x_result, 1);
  for (n = 0; n < 10; n++) {
    /*  opts settings */
    /* Calculate elapse time LinSolve start */
    time = 0;
    PLXAtimeinterval_start(&time);

    /* Forward */
    c_linsolve_blas(L, B, y_result);

    /* Backward */
    b_linsolve_blas(U, y_result, x_result);

    /* Calculate elapse time LinSolve end */
    AverageTimeLinSolve[n] = time_diff_msec(time);

    /* Calculate Cholesky   */
    /* Calculate elapse time Cholesky start */
    PLXAtimeinterval_start(&time);
    memcpy(&cholesky[0], &A[0], sizeof(double) << 18);
    jmax = c_xpotrf(cholesky);
    if (jmax == 0) {
      jmax = 512;
    } else {
      jmax--;
    }

    for (cholesky_tmp = 2; cholesky_tmp <= jmax; cholesky_tmp++) {
      for (b_cholesky_tmp = 0; b_cholesky_tmp <= cholesky_tmp - 2;
           b_cholesky_tmp++) {
        cholesky[b_cholesky_tmp + ((cholesky_tmp - 1) << 9)] = 0.0;
      }
    }

    /* Calculate elapse time Cholesky end */
    AverageTimeCholesky[n] = time_diff_msec(time);

    /* Calculate SVD   */
    /* Calculate elapse time SVD start */
    PLXAtimeinterval_start(&time);
    b_SVD(A, u, S, V);

    /* Calculate elapse time SVD end */
    AverageTimeSVD[n] = time_diff_msec(time);

    /* Calculate Multiplication Normal */
    /* Calculate elapse time Multiplication Normal start */
    PLXAtimeinterval_start(&time);
    c_multiply_Smart(A, B, normal);

    /* Calculate elapse time Multiplication Normal end */
    AverageTimeMultiplyNormal[n] = time_diff_msec(time);

    /* Calculate Multiplication Smart */
    /* Calculate elapse time Multiplication Smart start */
    PLXAtimeinterval_start(&time);
    d_multiply_Smart(A, B, x);

    /* Calculate elapse time Multiplication Smart end */
    AverageTimeMultiplySmart[n] = time_diff_msec(time);

    /* Save/Check Results and Precision  */
    f3_array_save_bin(x_result);
    b_f3_array_save_bin(y_result);
    g_f3_array_save_bin(cholesky);
    h_f3_array_save_bin(u);
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    i3 = jmax + 1;
    for (cholesky_tmp = i3; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeLinSolve[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    i3 = jmax + 1;
    for (cholesky_tmp = i3; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeLinSolve[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    i3 = jmax + 1;
    for (cholesky_tmp = i3; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplySmart[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    i3 = jmax + 1;
    for (cholesky_tmp = i3; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplySmart[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    i3 = jmax + 1;
    for (cholesky_tmp = i3; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeCholesky[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
      }
    }
  }

  printf("Worst Time Cholesky: %gms\n", ex / 1000.0);
  fflush(stdout);
  y = AverageTimeCholesky[0];
  for (cholesky_tmp = 0; cholesky_tmp < 9; cholesky_tmp++) {
    y += AverageTimeCholesky[cholesky_tmp + 1];
  }

  printf("Average Time Cholesky: %gms\n", y / 10.0 / 1000.0);
  fflush(stdout);
  if (!b1) {
    jmax = 1;
  } else {
    jmax = 0;
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    i3 = jmax + 1;
    for (cholesky_tmp = i3; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeCholesky[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeSVD[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    i3 = jmax + 1;
    for (cholesky_tmp = i3; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeSVD[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
      }
    }
  }

  printf("Worst Time SVD: %gms\n", ex / 1000.0);
  fflush(stdout);
  y = AverageTimeSVD[0];
  for (cholesky_tmp = 0; cholesky_tmp < 9; cholesky_tmp++) {
    y += AverageTimeSVD[cholesky_tmp + 1];
  }

  printf("Average Time SVD: %gms\n", y / 10.0 / 1000.0);
  fflush(stdout);
  if (!b1) {
    jmax = 1;
  } else {
    jmax = 0;
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeSVD[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    i3 = jmax + 1;
    for (cholesky_tmp = i3; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeSVD[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    i3 = jmax + 1;
    for (cholesky_tmp = i3; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplyNormal[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
      }
    }
  }

  printf("Worst Time Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
  y = AverageTimeMultiplyNormal[0];
  for (cholesky_tmp = 0; cholesky_tmp < 9; cholesky_tmp++) {
    y += AverageTimeMultiplyNormal[cholesky_tmp + 1];
  }

  printf("Average Time Multiply Normal: %gms\n", y / 10.0 / 1000.0);
  fflush(stdout);
  if (!b1) {
    jmax = 1;
  } else {
    jmax = 0;
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    i3 = jmax + 1;
    for (cholesky_tmp = i3; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplyNormal[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
      }
    }
  }

  printf("Bes tTime Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
}

/*
 * Initialize
 * Arguments    : void
 * Return Type  : void
 */
void c_f3_auto_tester(void)
{
  static double A[1048576];
  int i5;
  static double cholesky[1048576];
  int jmax;
  double B[1024];
  int cholesky_tmp;
  int b_cholesky_tmp;
  static double L[10000];
  double y;
  int n;
  emxArray_real_T *y_result;
  emxArray_real_T *x_result;
  double U[10000];
  unsigned long time;
  double AverageTimeLinSolve[10];
  boolean_T b2;
  boolean_T exitg1;
  double ex;
  double AverageTimeCholesky[10];
  static double u[1048576];
  static double S[1048576];
  static double V[1048576];
  double AverageTimeSVD[10];
  double normal[1024];
  double AverageTimeMultiplySmart[10];
  double AverageTimeMultiplyNormal[10];
  double x[100];
  c_randi(A);
  for (i5 = 0; i5 < 1024; i5++) {
    for (jmax = 0; jmax < 1024; jmax++) {
      cholesky_tmp = jmax << 10;
      b_cholesky_tmp = i5 + cholesky_tmp;
      cholesky[b_cholesky_tmp] = 0.0;
      y = 0.0;
      for (n = 0; n < 1024; n++) {
        y += A[n + (i5 << 10)] * A[n + cholesky_tmp];
      }

      cholesky[b_cholesky_tmp] = y;
    }
  }

  memcpy(&A[0], &cholesky[0], sizeof(double) << 20);
  memcpy(&B[0], &A[0], sizeof(double) << 10);

  /*  LinSolve, Cholesky,  SVD, Multiplication Normal, Smart */
  /* Calculate Cholesky for LinSolve */
  c_Cholesky(A, L);
  for (i5 = 0; i5 < 100; i5++) {
    for (jmax = 0; jmax < 100; jmax++) {
      U[jmax + 100 * i5] = L[i5 + 100 * jmax];
    }
  }

  /* Run the calculations X times for correcteness  */
  emxInit_real_T(&y_result, 1);
  emxInit_real_T(&x_result, 1);
  for (n = 0; n < 10; n++) {
    /*  opts settings */
    /* Calculate elapse time LinSolve start */
    time = 0;
    PLXAtimeinterval_start(&time);

    /* Forward */
    d_linsolve_blas(L, B, y_result);

    /* Backward */
    b_linsolve_blas(U, y_result, x_result);

    /* Calculate elapse time LinSolve end */
    AverageTimeLinSolve[n] = time_diff_msec(time);

    /* Calculate Cholesky   */
    /* Calculate elapse time Cholesky start */
    PLXAtimeinterval_start(&time);
    memcpy(&cholesky[0], &A[0], sizeof(double) << 20);
    jmax = d_xpotrf(cholesky);
    if (jmax == 0) {
      jmax = 1024;
    } else {
      jmax--;
    }

    for (cholesky_tmp = 2; cholesky_tmp <= jmax; cholesky_tmp++) {
      for (b_cholesky_tmp = 0; b_cholesky_tmp <= cholesky_tmp - 2;
           b_cholesky_tmp++) {
        cholesky[b_cholesky_tmp + ((cholesky_tmp - 1) << 10)] = 0.0;
      }
    }

    /* Calculate elapse time Cholesky end */
    AverageTimeCholesky[n] = time_diff_msec(time);

    /* Calculate SVD   */
    /* Calculate elapse time SVD start */
    PLXAtimeinterval_start(&time);
    c_SVD(A, u, S, V);

    /* Calculate elapse time SVD end */
    AverageTimeSVD[n] = time_diff_msec(time);

    /* Calculate Multiplication Normal */
    /* Calculate elapse time Multiplication Normal start */
    PLXAtimeinterval_start(&time);
    e_multiply_Smart(A, B, normal);

    /* Calculate elapse time Multiplication Normal end */
    AverageTimeMultiplyNormal[n] = time_diff_msec(time);

    /* Calculate Multiplication Smart */
    /* Calculate elapse time Multiplication Smart start */
    PLXAtimeinterval_start(&time);
    f_multiply_Smart(A, B, x);

    /* Calculate elapse time Multiplication Smart end */
    AverageTimeMultiplySmart[n] = time_diff_msec(time);

    /* Save/Check Results and Precision  */
    f3_array_save_bin(x_result);
    b_f3_array_save_bin(y_result);
    j_f3_array_save_bin(cholesky);
    k_f3_array_save_bin(u);
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    i5 = jmax + 1;
    for (cholesky_tmp = i5; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeLinSolve[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    i5 = jmax + 1;
    for (cholesky_tmp = i5; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeLinSolve[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    i5 = jmax + 1;
    for (cholesky_tmp = i5; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplySmart[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    i5 = jmax + 1;
    for (cholesky_tmp = i5; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplySmart[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    i5 = jmax + 1;
    for (cholesky_tmp = i5; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeCholesky[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
      }
    }
  }

  printf("Worst Time Cholesky: %gms\n", ex / 1000.0);
  fflush(stdout);
  y = AverageTimeCholesky[0];
  for (cholesky_tmp = 0; cholesky_tmp < 9; cholesky_tmp++) {
    y += AverageTimeCholesky[cholesky_tmp + 1];
  }

  printf("Average Time Cholesky: %gms\n", y / 10.0 / 1000.0);
  fflush(stdout);
  if (!b2) {
    jmax = 1;
  } else {
    jmax = 0;
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    i5 = jmax + 1;
    for (cholesky_tmp = i5; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeCholesky[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeSVD[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    i5 = jmax + 1;
    for (cholesky_tmp = i5; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeSVD[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
      }
    }
  }

  printf("Worst Time SVD: %gms\n", ex / 1000.0);
  fflush(stdout);
  y = AverageTimeSVD[0];
  for (cholesky_tmp = 0; cholesky_tmp < 9; cholesky_tmp++) {
    y += AverageTimeSVD[cholesky_tmp + 1];
  }

  printf("Average Time SVD: %gms\n", y / 10.0 / 1000.0);
  fflush(stdout);
  if (!b2) {
    jmax = 1;
  } else {
    jmax = 0;
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeSVD[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    i5 = jmax + 1;
    for (cholesky_tmp = i5; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeSVD[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    i5 = jmax + 1;
    for (cholesky_tmp = i5; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplyNormal[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
      }
    }
  }

  printf("Worst Time Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
  y = AverageTimeMultiplyNormal[0];
  for (cholesky_tmp = 0; cholesky_tmp < 9; cholesky_tmp++) {
    y += AverageTimeMultiplyNormal[cholesky_tmp + 1];
  }

  printf("Average Time Multiply Normal: %gms\n", y / 10.0 / 1000.0);
  fflush(stdout);
  if (!b2) {
    jmax = 1;
  } else {
    jmax = 0;
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    i5 = jmax + 1;
    for (cholesky_tmp = i5; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplyNormal[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
      }
    }
  }

  printf("Bes tTime Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
}

/*
 * Initialize
 * Arguments    : void
 * Return Type  : void
 */
void d_f3_auto_tester(void)
{
  static double A[4194304];
  int i7;
  static double cholesky[4194304];
  int jmax;
  double B[2048];
  int cholesky_tmp;
  int b_cholesky_tmp;
  static double L[10000];
  double y;
  int n;
  emxArray_real_T *y_result;
  emxArray_real_T *x_result;
  double U[10000];
  unsigned long time;
  double AverageTimeLinSolve[10];
  boolean_T b3;
  boolean_T exitg1;
  double ex;
  double AverageTimeCholesky[10];
  static double u[4194304];
  static double S[4194304];
  static double V[4194304];
  double AverageTimeSVD[10];
  double normal[2048];
  double AverageTimeMultiplySmart[10];
  double AverageTimeMultiplyNormal[10];
  double x[100];
  d_randi(A);
  for (i7 = 0; i7 < 2048; i7++) {
    for (jmax = 0; jmax < 2048; jmax++) {
      cholesky_tmp = jmax << 11;
      b_cholesky_tmp = i7 + cholesky_tmp;
      cholesky[b_cholesky_tmp] = 0.0;
      y = 0.0;
      for (n = 0; n < 2048; n++) {
        y += A[n + (i7 << 11)] * A[n + cholesky_tmp];
      }

      cholesky[b_cholesky_tmp] = y;
    }
  }

  memcpy(&A[0], &cholesky[0], sizeof(double) << 22);
  memcpy(&B[0], &A[0], sizeof(double) << 11);

  /*  LinSolve, Cholesky,  SVD, Multiplication Normal, Smart */
  /* Calculate Cholesky for LinSolve */
  d_Cholesky(A, L);
  for (i7 = 0; i7 < 100; i7++) {
    for (jmax = 0; jmax < 100; jmax++) {
      U[jmax + 100 * i7] = L[i7 + 100 * jmax];
    }
  }

  /* Run the calculations X times for correcteness  */
  emxInit_real_T(&y_result, 1);
  emxInit_real_T(&x_result, 1);
  for (n = 0; n < 10; n++) {
    /*  opts settings */
    /* Calculate elapse time LinSolve start */
    time = 0;
    PLXAtimeinterval_start(&time);

    /* Forward */
    e_linsolve_blas(L, B, y_result);

    /* Backward */
    b_linsolve_blas(U, y_result, x_result);

    /* Calculate elapse time LinSolve end */
    AverageTimeLinSolve[n] = time_diff_msec(time);

    /* Calculate Cholesky   */
    /* Calculate elapse time Cholesky start */
    PLXAtimeinterval_start(&time);
    memcpy(&cholesky[0], &A[0], sizeof(double) << 22);
    jmax = e_xpotrf(cholesky);
    if (jmax == 0) {
      jmax = 2048;
    } else {
      jmax--;
    }

    for (cholesky_tmp = 2; cholesky_tmp <= jmax; cholesky_tmp++) {
      for (b_cholesky_tmp = 0; b_cholesky_tmp <= cholesky_tmp - 2;
           b_cholesky_tmp++) {
        cholesky[b_cholesky_tmp + ((cholesky_tmp - 1) << 11)] = 0.0;
      }
    }

    /* Calculate elapse time Cholesky end */
    AverageTimeCholesky[n] = time_diff_msec(time);

    /* Calculate SVD   */
    /* Calculate elapse time SVD start */
    PLXAtimeinterval_start(&time);
    d_SVD(A, u, S, V);

    /* Calculate elapse time SVD end */
    AverageTimeSVD[n] = time_diff_msec(time);

    /* Calculate Multiplication Normal */
    /* Calculate elapse time Multiplication Normal start */
    PLXAtimeinterval_start(&time);
    g_multiply_Smart(A, B, normal);

    /* Calculate elapse time Multiplication Normal end */
    AverageTimeMultiplyNormal[n] = time_diff_msec(time);

    /* Calculate Multiplication Smart */
    /* Calculate elapse time Multiplication Smart start */
    PLXAtimeinterval_start(&time);
    h_multiply_Smart(A, B, x);

    /* Calculate elapse time Multiplication Smart end */
    AverageTimeMultiplySmart[n] = time_diff_msec(time);

    /* Save/Check Results and Precision  */
    f3_array_save_bin(x_result);
    b_f3_array_save_bin(y_result);
    m_f3_array_save_bin(cholesky);
    n_f3_array_save_bin(u);
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    i7 = jmax + 1;
    for (cholesky_tmp = i7; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeLinSolve[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    i7 = jmax + 1;
    for (cholesky_tmp = i7; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeLinSolve[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    i7 = jmax + 1;
    for (cholesky_tmp = i7; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplySmart[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    i7 = jmax + 1;
    for (cholesky_tmp = i7; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplySmart[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    i7 = jmax + 1;
    for (cholesky_tmp = i7; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeCholesky[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
      }
    }
  }

  printf("Worst Time Cholesky: %gms\n", ex / 1000.0);
  fflush(stdout);
  y = AverageTimeCholesky[0];
  for (cholesky_tmp = 0; cholesky_tmp < 9; cholesky_tmp++) {
    y += AverageTimeCholesky[cholesky_tmp + 1];
  }

  printf("Average Time Cholesky: %gms\n", y / 10.0 / 1000.0);
  fflush(stdout);
  if (!b3) {
    jmax = 1;
  } else {
    jmax = 0;
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    i7 = jmax + 1;
    for (cholesky_tmp = i7; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeCholesky[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeSVD[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    i7 = jmax + 1;
    for (cholesky_tmp = i7; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeSVD[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
      }
    }
  }

  printf("Worst Time SVD: %gms\n", ex / 1000.0);
  fflush(stdout);
  y = AverageTimeSVD[0];
  for (cholesky_tmp = 0; cholesky_tmp < 9; cholesky_tmp++) {
    y += AverageTimeSVD[cholesky_tmp + 1];
  }

  printf("Average Time SVD: %gms\n", y / 10.0 / 1000.0);
  fflush(stdout);
  if (!b3) {
    jmax = 1;
  } else {
    jmax = 0;
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeSVD[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    i7 = jmax + 1;
    for (cholesky_tmp = i7; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeSVD[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    i7 = jmax + 1;
    for (cholesky_tmp = i7; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplyNormal[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
      }
    }
  }

  printf("Worst Time Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
  y = AverageTimeMultiplyNormal[0];
  for (cholesky_tmp = 0; cholesky_tmp < 9; cholesky_tmp++) {
    y += AverageTimeMultiplyNormal[cholesky_tmp + 1];
  }

  printf("Average Time Multiply Normal: %gms\n", y / 10.0 / 1000.0);
  fflush(stdout);
  if (!b3) {
    jmax = 1;
  } else {
    jmax = 0;
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    i7 = jmax + 1;
    for (cholesky_tmp = i7; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplyNormal[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
      }
    }
  }

  printf("Bes tTime Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
}

/*
 * Initialize
 * Arguments    : void
 * Return Type  : void
 */
void e_f3_auto_tester(void)
{
  static double A[16777216];
  int i9;
  static double cholesky[16777216];
  int jmax;
  double B[4096];
  int cholesky_tmp;
  int b_cholesky_tmp;
  static double L[10000];
  double y;
  int n;
  emxArray_real_T *y_result;
  emxArray_real_T *x_result;
  static double U[10000];
  unsigned long time;
  double AverageTimeLinSolve[10];
  boolean_T b4;
  boolean_T exitg1;
  double ex;
  double AverageTimeCholesky[10];
  static double u[16777216];
  static double S[16777216];
  static double V[16777216];
  double AverageTimeSVD[10];
  double normal[4096];
  double AverageTimeMultiplySmart[10];
  double AverageTimeMultiplyNormal[10];
  double x[100];
  e_randi(A);
  for (i9 = 0; i9 < 4096; i9++) {
    for (jmax = 0; jmax < 4096; jmax++) {
      cholesky_tmp = jmax << 12;
      b_cholesky_tmp = i9 + cholesky_tmp;
      cholesky[b_cholesky_tmp] = 0.0;
      y = 0.0;
      for (n = 0; n < 4096; n++) {
        y += A[n + (i9 << 12)] * A[n + cholesky_tmp];
      }

      cholesky[b_cholesky_tmp] = y;
    }
  }

  memcpy(&A[0], &cholesky[0], sizeof(double) << 24);
  memcpy(&B[0], &A[0], sizeof(double) << 12);

  /*  LinSolve, Cholesky,  SVD, Multiplication Normal, Smart */
  /* Calculate Cholesky for LinSolve */
  e_Cholesky(A, L);
  for (i9 = 0; i9 < 100; i9++) {
    for (jmax = 0; jmax < 100; jmax++) {
      U[jmax + 100 * i9] = L[i9 + 100 * jmax];
    }
  }

  /* Run the calculations X times for correcteness  */
  emxInit_real_T(&y_result, 1);
  emxInit_real_T(&x_result, 1);
  for (n = 0; n < 10; n++) {
    /*  opts settings */
    /* Calculate elapse time LinSolve start */
    time = 0;
    PLXAtimeinterval_start(&time);

    /* Forward */
    f_linsolve_blas(L, B, y_result);

    /* Backward */
    b_linsolve_blas(U, y_result, x_result);

    /* Calculate elapse time LinSolve end */
    AverageTimeLinSolve[n] = time_diff_msec(time);

    /* Calculate Cholesky   */
    /* Calculate elapse time Cholesky start */
    PLXAtimeinterval_start(&time);
    memcpy(&cholesky[0], &A[0], sizeof(double) << 24);
    jmax = f_xpotrf(cholesky);
    if (jmax == 0) {
      jmax = 4096;
    } else {
      jmax--;
    }

    for (cholesky_tmp = 2; cholesky_tmp <= jmax; cholesky_tmp++) {
      for (b_cholesky_tmp = 0; b_cholesky_tmp <= cholesky_tmp - 2;
           b_cholesky_tmp++) {
        cholesky[b_cholesky_tmp + ((cholesky_tmp - 1) << 12)] = 0.0;
      }
    }

    /* Calculate elapse time Cholesky end */
    AverageTimeCholesky[n] = time_diff_msec(time);

    /* Calculate SVD   */
    /* Calculate elapse time SVD start */
    PLXAtimeinterval_start(&time);
    e_SVD(A, u, S, V);

    /* Calculate elapse time SVD end */
    AverageTimeSVD[n] = time_diff_msec(time);

    /* Calculate Multiplication Normal */
    /* Calculate elapse time Multiplication Normal start */
    PLXAtimeinterval_start(&time);
    i_multiply_Smart(A, B, normal);

    /* Calculate elapse time Multiplication Normal end */
    AverageTimeMultiplyNormal[n] = time_diff_msec(time);

    /* Calculate Multiplication Smart */
    /* Calculate elapse time Multiplication Smart start */
    PLXAtimeinterval_start(&time);
    j_multiply_Smart(A, B, x);

    /* Calculate elapse time Multiplication Smart end */
    AverageTimeMultiplySmart[n] = time_diff_msec(time);

    /* Save/Check Results and Precision  */
    f3_array_save_bin(x_result);
    b_f3_array_save_bin(y_result);
    p_f3_array_save_bin(cholesky);
    q_f3_array_save_bin(u);
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    i9 = jmax + 1;
    for (cholesky_tmp = i9; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeLinSolve[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    i9 = jmax + 1;
    for (cholesky_tmp = i9; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeLinSolve[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    i9 = jmax + 1;
    for (cholesky_tmp = i9; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplySmart[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    i9 = jmax + 1;
    for (cholesky_tmp = i9; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplySmart[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    i9 = jmax + 1;
    for (cholesky_tmp = i9; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeCholesky[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
      }
    }
  }

  printf("Worst Time Cholesky: %gms\n", ex / 1000.0);
  fflush(stdout);
  y = AverageTimeCholesky[0];
  for (cholesky_tmp = 0; cholesky_tmp < 9; cholesky_tmp++) {
    y += AverageTimeCholesky[cholesky_tmp + 1];
  }

  printf("Average Time Cholesky: %gms\n", y / 10.0 / 1000.0);
  fflush(stdout);
  if (!b4) {
    jmax = 1;
  } else {
    jmax = 0;
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    i9 = jmax + 1;
    for (cholesky_tmp = i9; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeCholesky[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeSVD[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    i9 = jmax + 1;
    for (cholesky_tmp = i9; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeSVD[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
      }
    }
  }

  printf("Worst Time SVD: %gms\n", ex / 1000.0);
  fflush(stdout);
  y = AverageTimeSVD[0];
  for (cholesky_tmp = 0; cholesky_tmp < 9; cholesky_tmp++) {
    y += AverageTimeSVD[cholesky_tmp + 1];
  }

  printf("Average Time SVD: %gms\n", y / 10.0 / 1000.0);
  fflush(stdout);
  if (!b4) {
    jmax = 1;
  } else {
    jmax = 0;
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeSVD[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    i9 = jmax + 1;
    for (cholesky_tmp = i9; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeSVD[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    i9 = jmax + 1;
    for (cholesky_tmp = i9; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplyNormal[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
      }
    }
  }

  printf("Worst Time Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
  y = AverageTimeMultiplyNormal[0];
  for (cholesky_tmp = 0; cholesky_tmp < 9; cholesky_tmp++) {
    y += AverageTimeMultiplyNormal[cholesky_tmp + 1];
  }

  printf("Average Time Multiply Normal: %gms\n", y / 10.0 / 1000.0);
  fflush(stdout);
  if (!b4) {
    jmax = 1;
  } else {
    jmax = 0;
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    i9 = jmax + 1;
    for (cholesky_tmp = i9; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplyNormal[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
      }
    }
  }

  printf("Bes tTime Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
}

/*
 * Initialize
 * Arguments    : void
 * Return Type  : void
 */
void f3_auto_tester(void)
{
  static double A[65536];
  int i0;
  static double cholesky[65536];
  int jmax;
  double B[256];
  int cholesky_tmp;
  int b_cholesky_tmp;
  double L[10000];
  double y;
  int n;
  emxArray_real_T *y_result;
  emxArray_real_T *x_result;
  double U[10000];
  unsigned long time;
  double AverageTimeLinSolve[10];
  boolean_T b0;
  boolean_T exitg1;
  double ex;
  double AverageTimeCholesky[10];
  static double u[65536];
  static double S[65536];
  static double V[65536];
  double AverageTimeSVD[10];
  double normal[256];
  double AverageTimeMultiplySmart[10];
  double AverageTimeMultiplyNormal[10];
  double x[100];
  randi(A);
  for (i0 = 0; i0 < 256; i0++) {
    for (jmax = 0; jmax < 256; jmax++) {
      cholesky_tmp = jmax << 8;
      b_cholesky_tmp = i0 + cholesky_tmp;
      cholesky[b_cholesky_tmp] = 0.0;
      y = 0.0;
      for (n = 0; n < 256; n++) {
        y += A[n + (i0 << 8)] * A[n + cholesky_tmp];
      }

      cholesky[b_cholesky_tmp] = y;
    }
  }

  memcpy(&A[0], &cholesky[0], sizeof(double) << 16);
  memcpy(&B[0], &A[0], sizeof(double) << 8);

  /*  LinSolve, Cholesky,  SVD, Multiplication Normal, Smart */
  /* Calculate Cholesky for LinSolve */
  Cholesky(A, L);
  for (i0 = 0; i0 < 100; i0++) {
    for (jmax = 0; jmax < 100; jmax++) {
      U[jmax + 100 * i0] = L[i0 + 100 * jmax];
    }
  }

  /* Run the calculations X times for correcteness  */
  emxInit_real_T(&y_result, 1);
  emxInit_real_T(&x_result, 1);
  for (n = 0; n < 10; n++) {
    /*  opts settings */
    /* Calculate elapse time LinSolve start */
    time = 0;
    PLXAtimeinterval_start(&time);

    /* Forward */
    linsolve_blas(L, B, y_result);

    /* Backward */
    b_linsolve_blas(U, y_result, x_result);

    /* Calculate elapse time LinSolve end */
    AverageTimeLinSolve[n] = time_diff_msec(time);

    /* Calculate Cholesky   */
    /* Calculate elapse time Cholesky start */
    PLXAtimeinterval_start(&time);
    memcpy(&cholesky[0], &A[0], sizeof(double) << 16);
    jmax = b_xpotrf(cholesky);
    if (jmax == 0) {
      jmax = 256;
    } else {
      jmax--;
    }

    for (cholesky_tmp = 2; cholesky_tmp <= jmax; cholesky_tmp++) {
      for (b_cholesky_tmp = 0; b_cholesky_tmp <= cholesky_tmp - 2;
           b_cholesky_tmp++) {
        cholesky[b_cholesky_tmp + ((cholesky_tmp - 1) << 8)] = 0.0;
      }
    }

    /* Calculate elapse time Cholesky end */
    AverageTimeCholesky[n] = time_diff_msec(time);

    /* Calculate SVD   */
    /* Calculate elapse time SVD start */
    PLXAtimeinterval_start(&time);
    SVD(A, u, S, V);

    /* Calculate elapse time SVD end */
    AverageTimeSVD[n] = time_diff_msec(time);

    /* Calculate Multiplication Normal */
    /* Calculate elapse time Multiplication Normal start */
    PLXAtimeinterval_start(&time);
    multiply_Smart(A, B, normal);

    /* Calculate elapse time Multiplication Normal end */
    AverageTimeMultiplyNormal[n] = time_diff_msec(time);

    /* Calculate Multiplication Smart */
    /* Calculate elapse time Multiplication Smart start */
    PLXAtimeinterval_start(&time);
    b_multiply_Smart(A, B, x);

    /* Calculate elapse time Multiplication Smart end */
    AverageTimeMultiplySmart[n] = time_diff_msec(time);

    /* Save/Check Results and Precision  */
    f3_array_save_bin(x_result);
    b_f3_array_save_bin(y_result);
    c_f3_array_save_bin(cholesky);
    d_f3_array_save_bin(u);
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    i0 = jmax + 1;
    for (cholesky_tmp = i0; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeLinSolve[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeLinSolve[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeLinSolve[0];
  } else {
    ex = AverageTimeLinSolve[jmax - 1];
    i0 = jmax + 1;
    for (cholesky_tmp = i0; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeLinSolve[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    i0 = jmax + 1;
    for (cholesky_tmp = i0; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplySmart[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplySmart[0];
  } else {
    ex = AverageTimeMultiplySmart[jmax - 1];
    i0 = jmax + 1;
    for (cholesky_tmp = i0; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplySmart[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    i0 = jmax + 1;
    for (cholesky_tmp = i0; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeCholesky[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
      }
    }
  }

  printf("Worst Time Cholesky: %gms\n", ex / 1000.0);
  fflush(stdout);
  y = AverageTimeCholesky[0];
  for (cholesky_tmp = 0; cholesky_tmp < 9; cholesky_tmp++) {
    y += AverageTimeCholesky[cholesky_tmp + 1];
  }

  printf("Average Time Cholesky: %gms\n", y / 10.0 / 1000.0);
  fflush(stdout);
  if (!b0) {
    jmax = 1;
  } else {
    jmax = 0;
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeCholesky[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeCholesky[0];
  } else {
    ex = AverageTimeCholesky[jmax - 1];
    i0 = jmax + 1;
    for (cholesky_tmp = i0; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeCholesky[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeSVD[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    i0 = jmax + 1;
    for (cholesky_tmp = i0; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeSVD[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
      }
    }
  }

  printf("Worst Time SVD: %gms\n", ex / 1000.0);
  fflush(stdout);
  y = AverageTimeSVD[0];
  for (cholesky_tmp = 0; cholesky_tmp < 9; cholesky_tmp++) {
    y += AverageTimeSVD[cholesky_tmp + 1];
  }

  printf("Average Time SVD: %gms\n", y / 10.0 / 1000.0);
  fflush(stdout);
  if (!b0) {
    jmax = 1;
  } else {
    jmax = 0;
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeSVD[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeSVD[0];
  } else {
    ex = AverageTimeSVD[jmax - 1];
    i0 = jmax + 1;
    for (cholesky_tmp = i0; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeSVD[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    i0 = jmax + 1;
    for (cholesky_tmp = i0; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplyNormal[cholesky_tmp - 1];
      if (ex < y) {
        ex = y;
      }
    }
  }

  printf("Worst Time Multiply Normal: %gms\n", ex / 1000.0);
  fflush(stdout);
  y = AverageTimeMultiplyNormal[0];
  for (cholesky_tmp = 0; cholesky_tmp < 9; cholesky_tmp++) {
    y += AverageTimeMultiplyNormal[cholesky_tmp + 1];
  }

  printf("Average Time Multiply Normal: %gms\n", y / 10.0 / 1000.0);
  fflush(stdout);
  if (!b0) {
    jmax = 1;
  } else {
    jmax = 0;
    cholesky_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (cholesky_tmp < 11)) {
      if (!rtIsNaN(AverageTimeMultiplyNormal[cholesky_tmp - 1])) {
        jmax = cholesky_tmp;
        exitg1 = true;
      } else {
        cholesky_tmp++;
      }
    }
  }

  if (jmax == 0) {
    ex = AverageTimeMultiplyNormal[0];
  } else {
    ex = AverageTimeMultiplyNormal[jmax - 1];
    i0 = jmax + 1;
    for (cholesky_tmp = i0; cholesky_tmp < 11; cholesky_tmp++) {
      y = AverageTimeMultiplyNormal[cholesky_tmp - 1];
      if (ex > y) {
        ex = y;
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
