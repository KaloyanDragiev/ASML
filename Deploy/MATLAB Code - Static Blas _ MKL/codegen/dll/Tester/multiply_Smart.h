/*
 * File: multiply_Smart.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

#ifndef MULTIPLY_SMART_H
#define MULTIPLY_SMART_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void b_multiply_Smart(double A[65536], double B[256], double data_ncol,
    double x[100]);
  extern void c_multiply_Smart(double A[262144], double B[512], double data_ncol,
    double x[512]);
  extern void d_multiply_Smart(double A[262144], double B[512], double data_ncol,
    double x[100]);
  extern void e_multiply_Smart(double A[1048576], double B[1024], double
    data_ncol, double x[1024]);
  extern void f_multiply_Smart(double A[1048576], double B[1024], double
    data_ncol, double x[100]);
  extern void g_multiply_Smart(double A[4194304], double B[2048], double
    data_ncol, double x[2048]);
  extern void h_multiply_Smart(double A[4194304], double B[2048], double
    data_ncol, double x[100]);
  extern void i_multiply_Smart(double A[16777216], double B[4096], double
    data_ncol, double x[4096]);
  extern void j_multiply_Smart(double A[16777216], double B[4096], double
    data_ncol, double x[100]);
  extern void multiply_Smart(double A[65536], double B[256], double data_ncol,
    double x[256]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for multiply_Smart.h
 *
 * [EOF]
 */
