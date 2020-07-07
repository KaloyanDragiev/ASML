/*
 * File: Tester.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "f3_auto_tester.h"
#include <stdio.h>

/* Function Definitions */

/*
 * Initialize Values
 * Arguments    : void
 * Return Type  : void
 */
void Tester(void)
{
  unsigned long time;
  double elapsed_time;

  /*  Change range size */
  /*  Change range size */
  /*  Change number of times the calcuations are performed  */
  time = 0;

  /* Calculate elapse time start 256 */
  PLXAtimeinterval_start(&time);

  /* 256; */
  /*  f3_auto_tester(coder.ignoreConst(data_nrow), coder.ignoreConst(data_ncol),  coder.ignoreConst(buf_size), ... */
  /*   coder.ignoreConst(timesToRun)); */
  f3_auto_tester();

  /* Calculate elapse time end 256 */
  elapsed_time = time_diff_msec(time);
  printf("\nTime for f3_auto_tester with size 256: %gms\n", elapsed_time /
         1000.0);
  fflush(stdout);

  /* Calculate elapse time start 512 */
  PLXAtimeinterval_start(&time);

  /* 512; */
  /*  f3_auto_tester(coder.ignoreConst(data_nrow), coder.ignoreConst(data_ncol),  coder.ignoreConst(buf_size), ... */
  /*   coder.ignoreConst(timesToRun)); */
  b_f3_auto_tester();

  /* Calculate elapse time end 512 */
  elapsed_time = time_diff_msec(time);
  printf("\nTime for f3_auto_tester with size 512: %gms\n", elapsed_time /
         1000.0);
  fflush(stdout);

  /* Calculate elapse time start 1024 */
  PLXAtimeinterval_start(&time);

  /* 1024; */
  /*  f3_auto_tester(coder.ignoreConst(data_nrow), coder.ignoreConst(data_ncol),  coder.ignoreConst(buf_size), ... */
  /*   coder.ignoreConst(timesToRun)); */
  c_f3_auto_tester();

  /* Calculate elapse time end 1024 */
  elapsed_time = time_diff_msec(time);
  printf("\nTime for f3_auto_tester with size 1024: %gms\n", elapsed_time /
         1000.0);
  fflush(stdout);

  /* Calculate elapse time start 2048 */
  PLXAtimeinterval_start(&time);

  /* 2048; */
  /*  f3_auto_tester(coder.ignoreConst(data_nrow), coder.ignoreConst(data_ncol),  coder.ignoreConst(buf_size), ... */
  /*   coder.ignoreConst(timesToRun)); */
  d_f3_auto_tester();

  /* Calculate elapse time end 2048 */
  elapsed_time = time_diff_msec(time);
  printf("\nTime for f3_auto_tester with size 2048: %gms\n", elapsed_time /
         1000.0);
  fflush(stdout);

  /* Calculate elapse time start 4096 */
  PLXAtimeinterval_start(&time);

  /* 4096; */
  /*  f3_auto_tester(coder.ignoreConst(data_nrow), coder.ignoreConst(data_ncol),  coder.ignoreConst(buf_size), ... */
  /*   coder.ignoreConst(timesToRun)); */
  e_f3_auto_tester();

  /* Calculate elapse time end 4096 */
  elapsed_time = time_diff_msec(time);
  printf("\nTime for f3_auto_tester with size 4096: %gms\n", elapsed_time /
         1000.0);
  fflush(stdout);
}

/*
 * File trailer for Tester.c
 *
 * [EOF]
 */
