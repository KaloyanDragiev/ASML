/*
 * File: multiply_Smart.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
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

  extern void b_multiply_Smart(const double A[65536], const double B[256],
    double x[100]);
  extern void c_multiply_Smart(const double A[262144], const double B[512],
    double x[512]);
  extern void d_multiply_Smart(const double A[262144], const double B[512],
    double x[100]);
  extern void e_multiply_Smart(const double A[1048576], const double B[1024],
    double x[1024]);
  extern void f_multiply_Smart(const double A[1048576], const double B[1024],
    double x[100]);
  extern void g_multiply_Smart(const double A[4194304], const double B[2048],
    double x[2048]);
  extern void h_multiply_Smart(const double A[4194304], const double B[2048],
    double x[100]);
  extern void i_multiply_Smart(const double A[16777216], const double B[4096],
    double x[4096]);
  extern void j_multiply_Smart(const double A[16777216], const double B[4096],
    double x[100]);
  extern void multiply_Smart(const double A[65536], const double B[256], double
    x[256]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for multiply_Smart.h
 *
 * [EOF]
 */
