/*
 * File: multiply_Smart.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "multiply_Smart.h"

/* Function Definitions */

/*
 * Arguments    : const double A[65536]
 *                const double B[256]
 *                double x[100]
 * Return Type  : void
 */
void b_multiply_Smart(const double A[65536], const double B[256], double x[100])
{
  int i21;
  double d1;
  int i22;

  /*       if coder.target('MATLAB') */
  for (i21 = 0; i21 < 100; i21++) {
    x[i21] = 0.0;
    d1 = 0.0;
    for (i22 = 0; i22 < 100; i22++) {
      d1 += A[i21 + (i22 << 8)] * B[i22];
    }

    x[i21] = d1;
  }

  /*      else     */
  /*          coder.cinclude('cblas.h') */
  /*           */
  /*          scaling_Factor_A_B = 1.0; % Scaling factor for the product of matrices A and B. */
  /*          scaling_Factor_C = 0.0; % Scaling factor for matrix C. */
  /*          n_col_B_C = 1; % Number of columns in matrices B and C. */
  /*           */
  /*          CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /*          CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*          CblasNoTrans2 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*           */
  /*          coder.ceval('cblas_dgemm', CblasColMajor, CblasNoTrans, CblasNoTrans2, data_nrow, n_col_B_C, data_ncol, ... */
  /*              scaling_Factor_A_B, coder.ref(A(1)), data_nrow, coder.ref(B(1)), data_ncol, scaling_Factor_C, coder.ref(x(1)), data_nrow); */
  /*      end     */
  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : const double A[262144]
 *                const double B[512]
 *                double x[512]
 * Return Type  : void
 */
void c_multiply_Smart(const double A[262144], const double B[512], double x[512])
{
  int i28;
  double d2;
  int i29;

  /*       if coder.target('MATLAB') */
  for (i28 = 0; i28 < 512; i28++) {
    x[i28] = 0.0;
    d2 = 0.0;
    for (i29 = 0; i29 < 512; i29++) {
      d2 += A[i28 + (i29 << 9)] * B[i29];
    }

    x[i28] = d2;
  }

  /*      else     */
  /*          coder.cinclude('cblas.h') */
  /*           */
  /*          scaling_Factor_A_B = 1.0; % Scaling factor for the product of matrices A and B. */
  /*          scaling_Factor_C = 0.0; % Scaling factor for matrix C. */
  /*          n_col_B_C = 1; % Number of columns in matrices B and C. */
  /*           */
  /*          CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /*          CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*          CblasNoTrans2 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*           */
  /*          coder.ceval('cblas_dgemm', CblasColMajor, CblasNoTrans, CblasNoTrans2, data_nrow, n_col_B_C, data_ncol, ... */
  /*              scaling_Factor_A_B, coder.ref(A(1)), data_nrow, coder.ref(B(1)), data_ncol, scaling_Factor_C, coder.ref(x(1)), data_nrow); */
  /*      end     */
  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : const double A[262144]
 *                const double B[512]
 *                double x[100]
 * Return Type  : void
 */
void d_multiply_Smart(const double A[262144], const double B[512], double x[100])
{
  int i30;
  double d3;
  int i31;

  /*       if coder.target('MATLAB') */
  for (i30 = 0; i30 < 100; i30++) {
    x[i30] = 0.0;
    d3 = 0.0;
    for (i31 = 0; i31 < 100; i31++) {
      d3 += A[i30 + (i31 << 9)] * B[i31];
    }

    x[i30] = d3;
  }

  /*      else     */
  /*          coder.cinclude('cblas.h') */
  /*           */
  /*          scaling_Factor_A_B = 1.0; % Scaling factor for the product of matrices A and B. */
  /*          scaling_Factor_C = 0.0; % Scaling factor for matrix C. */
  /*          n_col_B_C = 1; % Number of columns in matrices B and C. */
  /*           */
  /*          CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /*          CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*          CblasNoTrans2 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*           */
  /*          coder.ceval('cblas_dgemm', CblasColMajor, CblasNoTrans, CblasNoTrans2, data_nrow, n_col_B_C, data_ncol, ... */
  /*              scaling_Factor_A_B, coder.ref(A(1)), data_nrow, coder.ref(B(1)), data_ncol, scaling_Factor_C, coder.ref(x(1)), data_nrow); */
  /*      end     */
  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : const double A[1048576]
 *                const double B[1024]
 *                double x[1024]
 * Return Type  : void
 */
void e_multiply_Smart(const double A[1048576], const double B[1024], double x
                      [1024])
{
  int i37;
  double d4;
  int i38;

  /*       if coder.target('MATLAB') */
  for (i37 = 0; i37 < 1024; i37++) {
    x[i37] = 0.0;
    d4 = 0.0;
    for (i38 = 0; i38 < 1024; i38++) {
      d4 += A[i37 + (i38 << 10)] * B[i38];
    }

    x[i37] = d4;
  }

  /*      else     */
  /*          coder.cinclude('cblas.h') */
  /*           */
  /*          scaling_Factor_A_B = 1.0; % Scaling factor for the product of matrices A and B. */
  /*          scaling_Factor_C = 0.0; % Scaling factor for matrix C. */
  /*          n_col_B_C = 1; % Number of columns in matrices B and C. */
  /*           */
  /*          CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /*          CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*          CblasNoTrans2 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*           */
  /*          coder.ceval('cblas_dgemm', CblasColMajor, CblasNoTrans, CblasNoTrans2, data_nrow, n_col_B_C, data_ncol, ... */
  /*              scaling_Factor_A_B, coder.ref(A(1)), data_nrow, coder.ref(B(1)), data_ncol, scaling_Factor_C, coder.ref(x(1)), data_nrow); */
  /*      end     */
  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : const double A[1048576]
 *                const double B[1024]
 *                double x[100]
 * Return Type  : void
 */
void f_multiply_Smart(const double A[1048576], const double B[1024], double x
                      [100])
{
  int i39;
  double d5;
  int i40;

  /*       if coder.target('MATLAB') */
  for (i39 = 0; i39 < 100; i39++) {
    x[i39] = 0.0;
    d5 = 0.0;
    for (i40 = 0; i40 < 100; i40++) {
      d5 += A[i39 + (i40 << 10)] * B[i40];
    }

    x[i39] = d5;
  }

  /*      else     */
  /*          coder.cinclude('cblas.h') */
  /*           */
  /*          scaling_Factor_A_B = 1.0; % Scaling factor for the product of matrices A and B. */
  /*          scaling_Factor_C = 0.0; % Scaling factor for matrix C. */
  /*          n_col_B_C = 1; % Number of columns in matrices B and C. */
  /*           */
  /*          CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /*          CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*          CblasNoTrans2 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*           */
  /*          coder.ceval('cblas_dgemm', CblasColMajor, CblasNoTrans, CblasNoTrans2, data_nrow, n_col_B_C, data_ncol, ... */
  /*              scaling_Factor_A_B, coder.ref(A(1)), data_nrow, coder.ref(B(1)), data_ncol, scaling_Factor_C, coder.ref(x(1)), data_nrow); */
  /*      end     */
  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : const double A[4194304]
 *                const double B[2048]
 *                double x[2048]
 * Return Type  : void
 */
void g_multiply_Smart(const double A[4194304], const double B[2048], double x
                      [2048])
{
  int i46;
  double d6;
  int i47;

  /*       if coder.target('MATLAB') */
  for (i46 = 0; i46 < 2048; i46++) {
    x[i46] = 0.0;
    d6 = 0.0;
    for (i47 = 0; i47 < 2048; i47++) {
      d6 += A[i46 + (i47 << 11)] * B[i47];
    }

    x[i46] = d6;
  }

  /*      else     */
  /*          coder.cinclude('cblas.h') */
  /*           */
  /*          scaling_Factor_A_B = 1.0; % Scaling factor for the product of matrices A and B. */
  /*          scaling_Factor_C = 0.0; % Scaling factor for matrix C. */
  /*          n_col_B_C = 1; % Number of columns in matrices B and C. */
  /*           */
  /*          CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /*          CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*          CblasNoTrans2 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*           */
  /*          coder.ceval('cblas_dgemm', CblasColMajor, CblasNoTrans, CblasNoTrans2, data_nrow, n_col_B_C, data_ncol, ... */
  /*              scaling_Factor_A_B, coder.ref(A(1)), data_nrow, coder.ref(B(1)), data_ncol, scaling_Factor_C, coder.ref(x(1)), data_nrow); */
  /*      end     */
  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : const double A[4194304]
 *                const double B[2048]
 *                double x[100]
 * Return Type  : void
 */
void h_multiply_Smart(const double A[4194304], const double B[2048], double x
                      [100])
{
  int i48;
  double d7;
  int i49;

  /*       if coder.target('MATLAB') */
  for (i48 = 0; i48 < 100; i48++) {
    x[i48] = 0.0;
    d7 = 0.0;
    for (i49 = 0; i49 < 100; i49++) {
      d7 += A[i48 + (i49 << 11)] * B[i49];
    }

    x[i48] = d7;
  }

  /*      else     */
  /*          coder.cinclude('cblas.h') */
  /*           */
  /*          scaling_Factor_A_B = 1.0; % Scaling factor for the product of matrices A and B. */
  /*          scaling_Factor_C = 0.0; % Scaling factor for matrix C. */
  /*          n_col_B_C = 1; % Number of columns in matrices B and C. */
  /*           */
  /*          CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /*          CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*          CblasNoTrans2 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*           */
  /*          coder.ceval('cblas_dgemm', CblasColMajor, CblasNoTrans, CblasNoTrans2, data_nrow, n_col_B_C, data_ncol, ... */
  /*              scaling_Factor_A_B, coder.ref(A(1)), data_nrow, coder.ref(B(1)), data_ncol, scaling_Factor_C, coder.ref(x(1)), data_nrow); */
  /*      end     */
  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : const double A[16777216]
 *                const double B[4096]
 *                double x[4096]
 * Return Type  : void
 */
void i_multiply_Smart(const double A[16777216], const double B[4096], double x
                      [4096])
{
  int i55;
  double d8;
  int i56;

  /*       if coder.target('MATLAB') */
  for (i55 = 0; i55 < 4096; i55++) {
    x[i55] = 0.0;
    d8 = 0.0;
    for (i56 = 0; i56 < 4096; i56++) {
      d8 += A[i55 + (i56 << 12)] * B[i56];
    }

    x[i55] = d8;
  }

  /*      else     */
  /*          coder.cinclude('cblas.h') */
  /*           */
  /*          scaling_Factor_A_B = 1.0; % Scaling factor for the product of matrices A and B. */
  /*          scaling_Factor_C = 0.0; % Scaling factor for matrix C. */
  /*          n_col_B_C = 1; % Number of columns in matrices B and C. */
  /*           */
  /*          CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /*          CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*          CblasNoTrans2 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*           */
  /*          coder.ceval('cblas_dgemm', CblasColMajor, CblasNoTrans, CblasNoTrans2, data_nrow, n_col_B_C, data_ncol, ... */
  /*              scaling_Factor_A_B, coder.ref(A(1)), data_nrow, coder.ref(B(1)), data_ncol, scaling_Factor_C, coder.ref(x(1)), data_nrow); */
  /*      end     */
  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : const double A[16777216]
 *                const double B[4096]
 *                double x[100]
 * Return Type  : void
 */
void j_multiply_Smart(const double A[16777216], const double B[4096], double x
                      [100])
{
  int i57;
  double d9;
  int i58;

  /*       if coder.target('MATLAB') */
  for (i57 = 0; i57 < 100; i57++) {
    x[i57] = 0.0;
    d9 = 0.0;
    for (i58 = 0; i58 < 100; i58++) {
      d9 += A[i57 + (i58 << 12)] * B[i58];
    }

    x[i57] = d9;
  }

  /*      else     */
  /*          coder.cinclude('cblas.h') */
  /*           */
  /*          scaling_Factor_A_B = 1.0; % Scaling factor for the product of matrices A and B. */
  /*          scaling_Factor_C = 0.0; % Scaling factor for matrix C. */
  /*          n_col_B_C = 1; % Number of columns in matrices B and C. */
  /*           */
  /*          CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /*          CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*          CblasNoTrans2 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*           */
  /*          coder.ceval('cblas_dgemm', CblasColMajor, CblasNoTrans, CblasNoTrans2, data_nrow, n_col_B_C, data_ncol, ... */
  /*              scaling_Factor_A_B, coder.ref(A(1)), data_nrow, coder.ref(B(1)), data_ncol, scaling_Factor_C, coder.ref(x(1)), data_nrow); */
  /*      end     */
  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * Arguments    : const double A[65536]
 *                const double B[256]
 *                double x[256]
 * Return Type  : void
 */
void multiply_Smart(const double A[65536], const double B[256], double x[256])
{
  int i19;
  double d0;
  int i20;

  /*       if coder.target('MATLAB') */
  for (i19 = 0; i19 < 256; i19++) {
    x[i19] = 0.0;
    d0 = 0.0;
    for (i20 = 0; i20 < 256; i20++) {
      d0 += A[i19 + (i20 << 8)] * B[i20];
    }

    x[i19] = d0;
  }

  /*      else     */
  /*          coder.cinclude('cblas.h') */
  /*           */
  /*          scaling_Factor_A_B = 1.0; % Scaling factor for the product of matrices A and B. */
  /*          scaling_Factor_C = 0.0; % Scaling factor for matrix C. */
  /*          n_col_B_C = 1; % Number of columns in matrices B and C. */
  /*           */
  /*          CblasColMajor = coder.opaque('CBLAS_LAYOUT', 'CblasColMajor'); */
  /*          CblasNoTrans = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*          CblasNoTrans2 = coder.opaque('CBLAS_TRANSPOSE', 'CblasNoTrans');   */
  /*           */
  /*          coder.ceval('cblas_dgemm', CblasColMajor, CblasNoTrans, CblasNoTrans2, data_nrow, n_col_B_C, data_ncol, ... */
  /*              scaling_Factor_A_B, coder.ref(A(1)), data_nrow, coder.ref(B(1)), data_ncol, scaling_Factor_C, coder.ref(x(1)), data_nrow); */
  /*      end     */
  /*         cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, (int)100, (int)1, (int) */
  /*      90, 1.0, &a[0], (int)100, &B[0], (int)90, 0.0, &y[0], (int)100); row = 100; col = 90 */
}

/*
 * File trailer for multiply_Smart.c
 *
 * [EOF]
 */
