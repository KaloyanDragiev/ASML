/*
 * File: Arithmetic.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 25-Nov-2019 15:28:30
 */

/* Include Files */
#include <emmintrin.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "f2_auto_tester.h"
#include "Arithmetic.h"
#include "mod.h"
#include "mrdivide_helper.h"
#include "xtrsm.h"
#include "xgetrf.h"
#include "xpotrf.h"
#include "rand.h"
#include "cblas.h"

/* Function Definitions */

/*
 * function str = backslash(str)
 * Arguments    : struct_T *str
 * Return Type  : void
 */
void backslash(struct_T *str)
{
  int info;
  static double A[1000000];
  int ipiv[1000];
  int xi;
  int xj;
  int temp_tmp;
  double temp;

  /* 'Arithmetic:31' coder.inline('never'); */
  /* 'Arithmetic:32' str.D = str.A \ str.B; */
  for (info = 0; info < 1000000; info++) {
    str->D[info] = str->B[info];
    A[info] = str->A[info];
  }

  b_xgetrf(A, ipiv, &info);
  for (xi = 0; xi < 999; xi++) {
    if (ipiv[xi] != xi + 1) {
      for (xj = 0; xj < 1000; xj++) {
        temp_tmp = xi + 1000 * xj;
        temp = str->D[temp_tmp];
        info = (ipiv[xi] + 1000 * xj) - 1;
        str->D[temp_tmp] = str->D[info];
        str->D[info] = temp;
      }
    }
  }

  c_xtrsm(A, str->D);
  d_xtrsm(A, str->D);
}

/*
 * function str = cholesky(str)
 * Arguments    : struct_T *str
 * Return Type  : void
 */
void cholesky(struct_T *str)
{
  static double b[1000000];
  int jmax;
  int j;
  static double b_b[1000000];
  int i;

  /* 'Arithmetic:19' coder.inline('never'); */
  /* 'Arithmetic:20' b = rand(length(str.D)); */
  d_rand(b);

  /* 'Arithmetic:21' b = b * b'; */
  for (jmax = 0; jmax < 1000; jmax++) {
    for (j = 0; j < 1000; j++) {
      b_b[j + 1000 * jmax] = b[jmax + 1000 * j];
    }
  }

  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)1000, (int)1000,
              (int)1000, 1.0, &b[0], (int)1000, &b_b[0], (int)1000, 0.0, &str->
              D[0], (int)1000);

  /* 'Arithmetic:22' str.D = chol(b); */
  jmax = xpotrf(str->D);
  if (jmax == 0) {
    jmax = 1000;
  } else {
    jmax--;
  }

  for (j = 0; j < jmax; j++) {
    for (i = j + 2; i <= jmax; i++) {
      str->D[(i + 1000 * j) - 1] = 0.0;
    }
  }
}

/*
 * function str =  divide(str)
 * Arguments    : struct_T *str
 * Return Type  : void
 */
void divide(struct_T *str)
{
  static double dv0[1000000];
  int k;
  boolean_T y;
  static boolean_T x[1000000];
  boolean_T exitg1;
  __m128d r1;
  __attribute((aligned(16))) static double dv1[1000000];
  __m128d r2;
  __m128d r3;

  /* 'Arithmetic:36' coder.inline('never'); */
  /* 'Arithmetic:37' str.D = str.A / str.C; */
  mrdivide_helper(str->A, str->C, str->D);

  /* 'Arithmetic:38' if(mod(str.D,9) == 0) */
  c_mod(str->D, dv0);
  for (k = 0; k < 1000000; k++) {
    x[k] = (dv0[k] == 0.0);
  }

  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 1000000)) {
    if (!x[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (y) {
    /* 'Arithmetic:39' str.D = str.D * 35 ; */
    r1 = _mm_set1_pd(35.0);
    for (k = 0; k <= 999998; k += 2) {
      r2 = _mm_loadu_pd(*(double (*)[2])&str->D[k]);
      r3 = _mm_mul_pd(r2, r1);
      _mm_storeu_pd(&dv1[k], r3);
    }

    memcpy(&str->D[0], &dv1[0], 1000000U * sizeof(double));
  } else {
    /* 'Arithmetic:40' else */
    /* 'Arithmetic:41' str.D = str.D - 2 ; */
    r1 = _mm_set1_pd(2.0);
    for (k = 0; k <= 999998; k += 2) {
      r2 = _mm_loadu_pd(*(double (*)[2])&str->D[k]);
      r3 = _mm_sub_pd(r2, r1);
      _mm_storeu_pd(&dv1[k], r3);
    }

    memcpy(&str->D[0], &dv1[0], 1000000U * sizeof(double));
  }

  /* 'Arithmetic:43' for i = 1:length(str.D) */
  for (k = 0; k < 1000; k++) {
    /* 'Arithmetic:44' str.D(i) = max(abs(length(str.D)))/str.D(i); */
    str->D[k] = 1000.0 / str->D[k];
  }
}

/*
 * function str = multiply(str)
 * Arguments    : struct_T *str
 * Return Type  : void
 */
void multiply(struct_T *str)
{
  int i1;
  static double a[1000000];
  static double b[1000000];

  /* 'Arithmetic:26' coder.inline('never'); */
  /* 'Arithmetic:27' str.C = str.A * str.B; */
  for (i1 = 0; i1 < 1000000; i1++) {
    a[i1] = str->A[i1];
    b[i1] = str->B[i1];
  }

  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)1000, (int)1000,
              (int)1000, 1.0, &a[0], (int)1000, &b[0], (int)1000, 0.0, &str->C[0],
              (int)1000);
}

/*
 * File trailer for Arithmetic.c
 *
 * [EOF]
 */
