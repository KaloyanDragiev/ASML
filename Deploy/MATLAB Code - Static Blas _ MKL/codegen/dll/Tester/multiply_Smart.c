/*
 * File: multiply_Smart.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "multiply_Smart.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : double A[65536]
 *                double B[256]
 *                double data_ncol
 *                double x[100]
 * Return Type  : void
 */
void b_multiply_Smart(double A[65536], double B[256], double data_ncol, double
                      x[100])
{
  int i;
  for (i = 0; i < 100; i++) {
    x[i] = 1.0;
  }

  /*  Scaling factor for the product of matrices A and B. */
  /*  Scaling factor for matrix C. */
  /*  Number of columns in matrices B and C. */
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, 100.0, 1.0, data_ncol,
              1.0, &A[0], 100.0, &B[0], data_ncol, 0.0, &x[0], 100.0);

  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : double A[262144]
 *                double B[512]
 *                double data_ncol
 *                double x[512]
 * Return Type  : void
 */
void c_multiply_Smart(double A[262144], double B[512], double data_ncol, double
                      x[512])
{
  int i;
  for (i = 0; i < 512; i++) {
    x[i] = 1.0;
  }

  /*  Scaling factor for the product of matrices A and B. */
  /*  Scaling factor for matrix C. */
  /*  Number of columns in matrices B and C. */
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, 512.0, 1.0, data_ncol,
              1.0, &A[0], 512.0, &B[0], data_ncol, 0.0, &x[0], 512.0);

  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : double A[262144]
 *                double B[512]
 *                double data_ncol
 *                double x[100]
 * Return Type  : void
 */
void d_multiply_Smart(double A[262144], double B[512], double data_ncol, double
                      x[100])
{
  int i;
  for (i = 0; i < 100; i++) {
    x[i] = 1.0;
  }

  /*  Scaling factor for the product of matrices A and B. */
  /*  Scaling factor for matrix C. */
  /*  Number of columns in matrices B and C. */
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, 100.0, 1.0, data_ncol,
              1.0, &A[0], 100.0, &B[0], data_ncol, 0.0, &x[0], 100.0);

  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : double A[1048576]
 *                double B[1024]
 *                double data_ncol
 *                double x[1024]
 * Return Type  : void
 */
void e_multiply_Smart(double A[1048576], double B[1024], double data_ncol,
                      double x[1024])
{
  int i;
  for (i = 0; i < 1024; i++) {
    x[i] = 1.0;
  }

  /*  Scaling factor for the product of matrices A and B. */
  /*  Scaling factor for matrix C. */
  /*  Number of columns in matrices B and C. */
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, 1024.0, 1.0, data_ncol,
              1.0, &A[0], 1024.0, &B[0], data_ncol, 0.0, &x[0], 1024.0);

  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : double A[1048576]
 *                double B[1024]
 *                double data_ncol
 *                double x[100]
 * Return Type  : void
 */
void f_multiply_Smart(double A[1048576], double B[1024], double data_ncol,
                      double x[100])
{
  int i;
  for (i = 0; i < 100; i++) {
    x[i] = 1.0;
  }

  /*  Scaling factor for the product of matrices A and B. */
  /*  Scaling factor for matrix C. */
  /*  Number of columns in matrices B and C. */
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, 100.0, 1.0, data_ncol,
              1.0, &A[0], 100.0, &B[0], data_ncol, 0.0, &x[0], 100.0);

  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : double A[4194304]
 *                double B[2048]
 *                double data_ncol
 *                double x[2048]
 * Return Type  : void
 */
void g_multiply_Smart(double A[4194304], double B[2048], double data_ncol,
                      double x[2048])
{
  int i;
  for (i = 0; i < 2048; i++) {
    x[i] = 1.0;
  }

  /*  Scaling factor for the product of matrices A and B. */
  /*  Scaling factor for matrix C. */
  /*  Number of columns in matrices B and C. */
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, 2048.0, 1.0, data_ncol,
              1.0, &A[0], 2048.0, &B[0], data_ncol, 0.0, &x[0], 2048.0);

  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : double A[4194304]
 *                double B[2048]
 *                double data_ncol
 *                double x[100]
 * Return Type  : void
 */
void h_multiply_Smart(double A[4194304], double B[2048], double data_ncol,
                      double x[100])
{
  int i;
  for (i = 0; i < 100; i++) {
    x[i] = 1.0;
  }

  /*  Scaling factor for the product of matrices A and B. */
  /*  Scaling factor for matrix C. */
  /*  Number of columns in matrices B and C. */
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, 100.0, 1.0, data_ncol,
              1.0, &A[0], 100.0, &B[0], data_ncol, 0.0, &x[0], 100.0);

  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : double A[16777216]
 *                double B[4096]
 *                double data_ncol
 *                double x[4096]
 * Return Type  : void
 */
void i_multiply_Smart(double A[16777216], double B[4096], double data_ncol,
                      double x[4096])
{
  int i;
  for (i = 0; i < 4096; i++) {
    x[i] = 1.0;
  }

  /*  Scaling factor for the product of matrices A and B. */
  /*  Scaling factor for matrix C. */
  /*  Number of columns in matrices B and C. */
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, 4096.0, 1.0, data_ncol,
              1.0, &A[0], 4096.0, &B[0], data_ncol, 0.0, &x[0], 4096.0);

  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : double A[16777216]
 *                double B[4096]
 *                double data_ncol
 *                double x[100]
 * Return Type  : void
 */
void j_multiply_Smart(double A[16777216], double B[4096], double data_ncol,
                      double x[100])
{
  int i;
  for (i = 0; i < 100; i++) {
    x[i] = 1.0;
  }

  /*  Scaling factor for the product of matrices A and B. */
  /*  Scaling factor for matrix C. */
  /*  Number of columns in matrices B and C. */
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, 100.0, 1.0, data_ncol,
              1.0, &A[0], 100.0, &B[0], data_ncol, 0.0, &x[0], 100.0);

  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : double A[65536]
 *                double B[256]
 *                double data_ncol
 *                double x[256]
 * Return Type  : void
 */
void multiply_Smart(double A[65536], double B[256], double data_ncol, double x
                    [256])
{
  int i;
  for (i = 0; i < 256; i++) {
    x[i] = 1.0;
  }

  /*  Scaling factor for the product of matrices A and B. */
  /*  Scaling factor for matrix C. */
  /*  Number of columns in matrices B and C. */
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, 256.0, 1.0, data_ncol,
              1.0, &A[0], 256.0, &B[0], data_ncol, 0.0, &x[0], 256.0);

  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * File trailer for multiply_Smart.c
 *
 * [EOF]
 */
