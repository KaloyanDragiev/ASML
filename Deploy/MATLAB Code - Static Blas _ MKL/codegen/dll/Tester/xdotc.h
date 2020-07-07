/*
 * File: xdotc.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

#ifndef XDOTC_H
#define XDOTC_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern double b_xdotc(int n, const double x[262144], int ix0, const double y
                        [262144], int iy0);
  extern double c_xdotc(int n, const double x[1048576], int ix0, const double y
                        [1048576], int iy0);
  extern double d_xdotc(int n, const double x[4194304], int ix0, const double y
                        [4194304], int iy0);
  extern double e_xdotc(int n, const double x[16777216], int ix0, const double
                        y[16777216], int iy0);
  extern double xdotc(int n, const double x[65536], int ix0, const double y
                      [65536], int iy0);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for xdotc.h
 *
 * [EOF]
 */
