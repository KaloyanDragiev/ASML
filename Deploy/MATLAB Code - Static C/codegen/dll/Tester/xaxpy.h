/*
 * File: xaxpy.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
 */

#ifndef XAXPY_H
#define XAXPY_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void b_xaxpy(int n, double a, const double x[65536], int ix0, double y
                      [256], int iy0);
  extern void c_xaxpy(int n, double a, const double x[256], int ix0, double y
                      [65536], int iy0);
  extern void d_xaxpy(int n, double a, int ix0, double y[262144], int iy0);
  extern void e_xaxpy(int n, double a, const double x[262144], int ix0, double
                      y[512], int iy0);
  extern void f_xaxpy(int n, double a, const double x[512], int ix0, double y
                      [262144], int iy0);
  extern void g_xaxpy(int n, double a, int ix0, double y[1048576], int iy0);
  extern void h_xaxpy(int n, double a, const double x[1048576], int ix0, double
                      y[1024], int iy0);
  extern void i_xaxpy(int n, double a, const double x[1024], int ix0, double y
                      [1048576], int iy0);
  extern void j_xaxpy(int n, double a, int ix0, double y[4194304], int iy0);
  extern void k_xaxpy(int n, double a, const double x[4194304], int ix0, double
                      y[2048], int iy0);
  extern void l_xaxpy(int n, double a, const double x[2048], int ix0, double y
                      [4194304], int iy0);
  extern void m_xaxpy(int n, double a, int ix0, double y[16777216], int iy0);
  extern void n_xaxpy(int n, double a, const double x[16777216], int ix0, double
                      y[4096], int iy0);
  extern void o_xaxpy(int n, double a, const double x[4096], int ix0, double y
                      [16777216], int iy0);
  extern void xaxpy(int n, double a, int ix0, double y[65536], int iy0);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for xaxpy.h
 *
 * [EOF]
 */
