/*
 * File: f3_auto_tester.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 09-Jan-2020 11:21:18
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "f3_auto_tester.h"
#include "f3_auto_tester_emxutil.h"
#include "fclose.h"
#include "fwrite.h"
#include "fileManager.h"
#include "multiply_Smart.h"
#include "linsolve_blas.h"
#include "Cholesky.h"
#include "magic.h"
#include <stdio.h>

/* Function Definitions */

/*
 * function f3_auto_tester
 * Initialize
 * Arguments    : void
 * Return Type  : void
 */
void f3_auto_tester(void)
{
  static double A[16192576];
  int trueCount;
  int i;
  emxArray_int32_T *r0;
  int idx;
  emxArray_real_T *b_A;
  double B[4024];
  static double L[10000];
  emxArray_real_T *y_result;
  double U[10000];
  emxArray_real_T *x_result;
  emxArray_real_T *x;
  boolean_T b0;
  double AverageTimeLinSolve[50];
  boolean_T exitg1;
  double elapsed_time_linsolve;
  unsigned long time;
  double elapsed_time_multiply;
  double AverageTimeMultiplySmart[50];
  signed char fileid;
  emxArray_real_T b_x_result;
  int c_x_result[1];
  int d_x_result[1];

  /* 'f3_auto_tester:3' data_nrow = 100; */
  /* 'f3_auto_tester:4' data_ncol = 100; */
  /* 'f3_auto_tester:5' buf_size  = 4024; */
  /* 'f3_auto_tester:7' A = magic(buf_size); */
  magic(A);

  /* 'f3_auto_tester:8' C = A(A <= buf_size); */
  /* 'f3_auto_tester:9' B = C(1:buf_size, 1); */
  trueCount = 0;
  for (i = 0; i < 16192576; i++) {
    if (A[i] <= 4024.0) {
      trueCount++;
    }
  }

  emxInit_int32_T(&r0, 1);
  i = r0->size[0];
  r0->size[0] = trueCount;
  emxEnsureCapacity_int32_T(r0, i);
  idx = 0;
  for (i = 0; i < 16192576; i++) {
    if (A[i] <= 4024.0) {
      r0->data[idx] = i + 1;
      idx++;
    }
  }

  emxInit_real_T(&b_A, 2);
  idx = r0->size[0];
  i = b_A->size[0] * b_A->size[1];
  b_A->size[0] = idx;
  b_A->size[1] = 1;
  emxEnsureCapacity_real_T(b_A, i);
  for (i = 0; i < idx; i++) {
    b_A->data[i] = A[r0->data[i] - 1];
  }

  emxFree_int32_T(&r0);
  for (i = 0; i < 4024; i++) {
    B[i] = b_A->data[i];
  }

  emxFree_real_T(&b_A);

  /* 'f3_auto_tester:11' AverageTimeLinSolve = zeros(1, 50); */
  /* 'f3_auto_tester:12' AverageTimeMultiplySmart = zeros(1, 50); */
  /*  LinSolve */
  /* Calculate Cholesky     */
  /* 'f3_auto_tester:16' L = Cholesky(A, data_nrow, data_ncol); */
  Cholesky(A, L);

  /* 'f3_auto_tester:17' U = L'; */
  for (i = 0; i < 100; i++) {
    for (idx = 0; idx < 100; idx++) {
      U[idx + 100 * i] = L[i + 100 * idx];
    }
  }

  /* Run the calculations 50 times for correcteness  */
  /* 'f3_auto_tester:20' for n = 1:50 */
  emxInit_real_T(&y_result, 2);
  emxInit_real_T(&x_result, 2);
  emxInit_real_T(&x, 1);
  for (idx = 0; idx < 50; idx++) {
    /* 'f3_auto_tester:21' fprintf('\n--------------------------------------\n'); */
    printf("\n--------------------------------------\n");
    fflush(stdout);

    /* 'f3_auto_tester:22' fprintf('LinSolve & Multiplication tester...\n\n'); */
    printf("LinSolve & Multiplication tester...\n\n");
    fflush(stdout);

    /*  opts settings */
    /* 'f3_auto_tester:25' opts.LT = false; */
    /* 'f3_auto_tester:26' opts.UT = false; */
    /* 'f3_auto_tester:27' opts.TRANSA = false; */
    /* Calculate elapse time LinSolve start */
    /* 'f3_auto_tester:30' time = coder.opaque('unsigned long', '0'); */
    time = 0;

    /* 'f3_auto_tester:31' elapsed_time_linsolve = 0; */
    /* 'f3_auto_tester:32' elapsed_time_multiply = 0; */
    /* 'f3_auto_tester:34' if coder.target('MATLAB') */
    /* 'f3_auto_tester:36' else */
    /* 'f3_auto_tester:37' coder.ceval('PLXAtimeinterval_start', coder.ref(time)); */
    PLXAtimeinterval_start(&time);

    /* Forward */
    /* 'f3_auto_tester:41' opts.LT = true; */
    /* 'f3_auto_tester:42' opts.TRANSA = false; */
    /* 'f3_auto_tester:44' [y_result, L, B] = linsolve_blas(coder.ignoreConst(L), coder.ignoreConst(B), coder.ignoreConst(data_nrow), ... */
    /* 'f3_auto_tester:45'     coder.ignoreConst(data_ncol), coder.ignoreConst(opts)); */
    linsolve_blas(L, B, 100.0, 100.0, true, y_result);

    /* Backward */
    /* 'f3_auto_tester:48' opts.LT = false; */
    /* 'f3_auto_tester:49' opts.UT = true; */
    /* 'f3_auto_tester:50' opts.TRANSA = false; */
    /* 'f3_auto_tester:52' [x_result, U, y_result] = linsolve_blas(coder.ignoreConst(U), coder.ignoreConst(y_result), coder.ignoreConst(data_nrow), ...  */
    /* 'f3_auto_tester:53'     coder.ignoreConst(data_ncol), coder.ignoreConst(opts)); */
    b_linsolve_blas(U, y_result, 100.0, 100.0, false, x_result);

    /* 'f3_auto_tester:55' fprintf('Results X:\n'); */
    printf("Results X:\n");
    fflush(stdout);

    /* 'f3_auto_tester:56' fprintf('1 - %15e\n', x_result(1)); */
    printf("1 - %15e\n", x_result->data[0]);
    fflush(stdout);

    /* 'f3_auto_tester:57' fprintf('2 - %15e\n', x_result(2)); */
    printf("2 - %15e\n", x_result->data[1]);
    fflush(stdout);

    /* 'f3_auto_tester:58' fprintf('3 - %15e\n', x_result(3)); */
    printf("3 - %15e\n", x_result->data[2]);
    fflush(stdout);

    /* 'f3_auto_tester:59' fprintf('4 - %15e\n', x_result(4)); */
    printf("4 - %15e\n", x_result->data[3]);
    fflush(stdout);

    /* 'f3_auto_tester:60' fprintf('5 - %15e\n\n', x_result(5)); */
    printf("5 - %15e\n\n", x_result->data[4]);
    fflush(stdout);

    /* 'f3_auto_tester:62' fprintf('Results Y:\n'); */
    printf("Results Y:\n");
    fflush(stdout);

    /* 'f3_auto_tester:63' fprintf('1 - %15e\n', y_result(1)); */
    printf("1 - %15e\n", y_result->data[0]);
    fflush(stdout);

    /* 'f3_auto_tester:64' fprintf('2 - %15e\n', y_result(2)); */
    printf("2 - %15e\n", y_result->data[1]);
    fflush(stdout);

    /* 'f3_auto_tester:65' fprintf('3 - %15e\n', y_result(3)); */
    printf("3 - %15e\n", y_result->data[2]);
    fflush(stdout);

    /* 'f3_auto_tester:66' fprintf('4 - %15e\n', y_result(4)); */
    printf("4 - %15e\n", y_result->data[3]);
    fflush(stdout);

    /* 'f3_auto_tester:67' fprintf('5 - %15e\n', y_result(5)); */
    printf("5 - %15e\n", y_result->data[4]);
    fflush(stdout);

    /* Calculate elapse time LinSolve end */
    /* 'f3_auto_tester:70' if coder.target('MATLAB') */
    /* 'f3_auto_tester:72' else */
    /* 'f3_auto_tester:73' elapsed_time_linsolve = coder.ceval('time_diff_msec', time); */
    elapsed_time_linsolve = time_diff_msec(time);

    /* 'f3_auto_tester:76' fprintf('\nElapsed_time_LinSolve: %gms\n\n', elapsed_time_linsolve/1e3); */
    printf("\nElapsed_time_LinSolve: %gms\n\n", elapsed_time_linsolve / 1000.0);
    fflush(stdout);

    /* Calculate elapse time Multiplication start */
    /* 'f3_auto_tester:79' if coder.target('MATLAB') */
    /* 'f3_auto_tester:81' else */
    /* 'f3_auto_tester:82' coder.ceval('PLXAtimeinterval_start', coder.ref(time)); */
    PLXAtimeinterval_start(&time);

    /* Smart Multiplication */
    /* 'f3_auto_tester:86' [x, A, B] = multiply_Smart(coder.ignoreConst(A), coder.ignoreConst(B), coder.ignoreConst(data_nrow), ... */
    /* 'f3_auto_tester:87'         coder.ignoreConst(data_ncol)); */
    multiply_Smart(A, B, 100.0, 100.0, x);

    /* 'f3_auto_tester:89' fprintf('Results Multiplication:\n'); */
    printf("Results Multiplication:\n");
    fflush(stdout);

    /* 'f3_auto_tester:90' fprintf('1 - %15e\n', x(1)); */
    printf("1 - %15e\n", x->data[0]);
    fflush(stdout);

    /* 'f3_auto_tester:91' fprintf('2 - %15e\n', x(2)); */
    printf("2 - %15e\n", x->data[1]);
    fflush(stdout);

    /* Calculate elapse time Multiplication end */
    /* 'f3_auto_tester:94' if coder.target('MATLAB') */
    /* 'f3_auto_tester:96' else */
    /* 'f3_auto_tester:97' elapsed_time_multiply = coder.ceval('time_diff_msec', time); */
    elapsed_time_multiply = time_diff_msec(time);

    /* 'f3_auto_tester:99' fprintf('\nElapsed_time_Multiplication: %gms\n', elapsed_time_multiply/1e3); */
    printf("\nElapsed_time_Multiplication: %gms\n", elapsed_time_multiply /
           1000.0);
    fflush(stdout);

    /* Save/Check LinSolve Results and Precision  */
    /* 'f3_auto_tester:102' if coder.target('MATLAB') */
    /* 'f3_auto_tester:108' else */
    /* 'f3_auto_tester:109' fn = 'f3_lin_x.bin'; */
    /* 'f3_auto_tester:110' err = f3_array_save_bin(fn, x_result); */
    /* 'f3_array_save_bin:3' if nargin < 1 */
    /* 'f3_array_save_bin:4' if nargin < 2 */
    /* 'f3_array_save_bin:6' err = 0; */
    /* 'f3_array_save_bin:7' f = fopen(fn, 'w'); */
    fileid = cfopen("f3_lin_x.bin", "wb");

    /* 'f3_array_save_bin:8' if f < 0 */
    if (fileid >= 0) {
      /* 'f3_array_save_bin:10' fwrite(f, data(:), 'double'); */
      trueCount = x_result->size[0] * x_result->size[1];
      b_x_result = *x_result;
      c_x_result[0] = trueCount;
      b_x_result.size = &c_x_result[0];
      b_x_result.numDimensions = 1;
      b_fwrite(fileid, &b_x_result);

      /* 'f3_array_save_bin:11' fclose(f); */
      b_fclose(fileid);
    } else {
      /* 'f3_array_save_bin:8' err = 1; */
    }

    /* 'f3_auto_tester:112' fn2 = 'f3_lin_y.bin'; */
    /* 'f3_auto_tester:113' err2 = f3_array_save_bin(fn2, y_result); */
    /* 'f3_array_save_bin:3' if nargin < 1 */
    /* 'f3_array_save_bin:4' if nargin < 2 */
    /* 'f3_array_save_bin:6' err = 0; */
    /* 'f3_array_save_bin:7' f = fopen(fn, 'w'); */
    fileid = cfopen("f3_lin_y.bin", "wb");

    /* 'f3_array_save_bin:8' if f < 0 */
    if (fileid >= 0) {
      /* 'f3_array_save_bin:10' fwrite(f, data(:), 'double'); */
      trueCount = y_result->size[0] * y_result->size[1];
      b_x_result = *y_result;
      d_x_result[0] = trueCount;
      b_x_result.size = &d_x_result[0];
      b_x_result.numDimensions = 1;
      b_fwrite(fileid, &b_x_result);

      /* 'f3_array_save_bin:11' fclose(f); */
      b_fclose(fileid);
    } else {
      /* 'f3_array_save_bin:8' err = 1; */
    }

    /* 'f3_auto_tester:116' AverageTimeLinSolve(n) = elapsed_time_linsolve; */
    AverageTimeLinSolve[idx] = elapsed_time_linsolve;

    /* 'f3_auto_tester:117' AverageTimeMultiplySmart(n) = elapsed_time_multiply; */
    AverageTimeMultiplySmart[idx] = elapsed_time_multiply;
  }

  emxFree_real_T(&x);
  emxFree_real_T(&x_result);
  emxFree_real_T(&y_result);

  /* 'f3_auto_tester:120' fprintf('\n--------------------------------------\n'); */
  printf("\n--------------------------------------\n");
  fflush(stdout);

  /* 'f3_auto_tester:121' fprintf('WorstTimeLinSolve: %gms\n', max(AverageTimeLinSolve)/1e3); */
  b0 = rtIsNaN(AverageTimeLinSolve[0]);
  if (!b0) {
    idx = 1;
  } else {
    idx = 0;
    trueCount = 2;
    exitg1 = false;
    while ((!exitg1) && (trueCount < 51)) {
      if (!rtIsNaN(AverageTimeLinSolve[trueCount - 1])) {
        idx = trueCount;
        exitg1 = true;
      } else {
        trueCount++;
      }
    }
  }

  if (idx == 0) {
    elapsed_time_linsolve = AverageTimeLinSolve[0];
  } else {
    elapsed_time_linsolve = AverageTimeLinSolve[idx - 1];
    i = idx + 1;
    for (trueCount = i; trueCount < 51; trueCount++) {
      elapsed_time_multiply = AverageTimeLinSolve[trueCount - 1];
      if (elapsed_time_linsolve < elapsed_time_multiply) {
        elapsed_time_linsolve = elapsed_time_multiply;
      }
    }
  }

  printf("WorstTimeLinSolve: %gms\n", elapsed_time_linsolve / 1000.0);
  fflush(stdout);

  /* 'f3_auto_tester:122' fprintf('AverageTimeLinSolve: %gms\n', mean(AverageTimeLinSolve)/1e3); */
  elapsed_time_linsolve = AverageTimeLinSolve[0];
  for (trueCount = 0; trueCount < 49; trueCount++) {
    elapsed_time_linsolve += AverageTimeLinSolve[trueCount + 1];
  }

  printf("AverageTimeLinSolve: %gms\n", elapsed_time_linsolve / 50.0 / 1000.0);
  fflush(stdout);

  /* 'f3_auto_tester:123' fprintf('BestTimeLinSolve: %gms\n\n', min(AverageTimeLinSolve)/1e3); */
  if (!b0) {
    idx = 1;
  } else {
    idx = 0;
    trueCount = 2;
    exitg1 = false;
    while ((!exitg1) && (trueCount < 51)) {
      if (!rtIsNaN(AverageTimeLinSolve[trueCount - 1])) {
        idx = trueCount;
        exitg1 = true;
      } else {
        trueCount++;
      }
    }
  }

  if (idx == 0) {
    elapsed_time_linsolve = AverageTimeLinSolve[0];
  } else {
    elapsed_time_linsolve = AverageTimeLinSolve[idx - 1];
    i = idx + 1;
    for (trueCount = i; trueCount < 51; trueCount++) {
      elapsed_time_multiply = AverageTimeLinSolve[trueCount - 1];
      if (elapsed_time_linsolve > elapsed_time_multiply) {
        elapsed_time_linsolve = elapsed_time_multiply;
      }
    }
  }

  printf("BestTimeLinSolve: %gms\n\n", elapsed_time_linsolve / 1000.0);
  fflush(stdout);

  /* 'f3_auto_tester:125' fprintf('WorstTimeMultiplySmart: %gms\n', max(AverageTimeMultiplySmart)/1e3); */
  b0 = rtIsNaN(AverageTimeMultiplySmart[0]);
  if (!b0) {
    idx = 1;
  } else {
    idx = 0;
    trueCount = 2;
    exitg1 = false;
    while ((!exitg1) && (trueCount < 51)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[trueCount - 1])) {
        idx = trueCount;
        exitg1 = true;
      } else {
        trueCount++;
      }
    }
  }

  if (idx == 0) {
    elapsed_time_linsolve = AverageTimeMultiplySmart[0];
  } else {
    elapsed_time_linsolve = AverageTimeMultiplySmart[idx - 1];
    i = idx + 1;
    for (trueCount = i; trueCount < 51; trueCount++) {
      elapsed_time_multiply = AverageTimeMultiplySmart[trueCount - 1];
      if (elapsed_time_linsolve < elapsed_time_multiply) {
        elapsed_time_linsolve = elapsed_time_multiply;
      }
    }
  }

  printf("WorstTimeMultiplySmart: %gms\n", elapsed_time_linsolve / 1000.0);
  fflush(stdout);

  /* 'f3_auto_tester:126' fprintf('AverageTimeMultiplySmart: %gms\n', mean(AverageTimeMultiplySmart)/1e3); */
  elapsed_time_linsolve = AverageTimeMultiplySmart[0];
  for (trueCount = 0; trueCount < 49; trueCount++) {
    elapsed_time_linsolve += AverageTimeMultiplySmart[trueCount + 1];
  }

  printf("AverageTimeMultiplySmart: %gms\n", elapsed_time_linsolve / 50.0 /
         1000.0);
  fflush(stdout);

  /* 'f3_auto_tester:127' fprintf('BestTimeMultiplySmart: %gms\n', min(AverageTimeMultiplySmart)/1e3); */
  if (!b0) {
    idx = 1;
  } else {
    idx = 0;
    trueCount = 2;
    exitg1 = false;
    while ((!exitg1) && (trueCount < 51)) {
      if (!rtIsNaN(AverageTimeMultiplySmart[trueCount - 1])) {
        idx = trueCount;
        exitg1 = true;
      } else {
        trueCount++;
      }
    }
  }

  if (idx == 0) {
    elapsed_time_linsolve = AverageTimeMultiplySmart[0];
  } else {
    elapsed_time_linsolve = AverageTimeMultiplySmart[idx - 1];
    i = idx + 1;
    for (trueCount = i; trueCount < 51; trueCount++) {
      elapsed_time_multiply = AverageTimeMultiplySmart[trueCount - 1];
      if (elapsed_time_linsolve > elapsed_time_multiply) {
        elapsed_time_linsolve = elapsed_time_multiply;
      }
    }
  }

  printf("BestTimeMultiplySmart: %gms\n", elapsed_time_linsolve / 1000.0);
  fflush(stdout);
}

/*
 * File trailer for f3_auto_tester.c
 *
 * [EOF]
 */
