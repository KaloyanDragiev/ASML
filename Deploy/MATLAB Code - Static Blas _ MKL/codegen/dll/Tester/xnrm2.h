/*
 * File: xnrm2.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

#ifndef XNRM2_H
#define XNRM2_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern double b_xnrm2(int n, const double x[256], int ix0);
  extern double c_xnrm2(int n, const double x[262144], int ix0);
  extern double d_xnrm2(int n, const double x[512], int ix0);
  extern double e_xnrm2(int n, const double x[1048576], int ix0);
  extern double f_xnrm2(int n, const double x[1024], int ix0);
  extern double g_xnrm2(int n, const double x[4194304], int ix0);
  extern double h_xnrm2(int n, const double x[2048], int ix0);
  extern double i_xnrm2(int n, const double x[16777216], int ix0);
  extern double j_xnrm2(int n, const double x[4096], int ix0);
  extern double xnrm2(int n, const double x[65536], int ix0);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for xnrm2.h
 *
 * [EOF]
 */
