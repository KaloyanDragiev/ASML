/*
 * File: xswap.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

#ifndef XSWAP_H
#define XSWAP_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void b_xswap(double x[262144], int ix0, int iy0);
  extern void c_xswap(double x[1048576], int ix0, int iy0);
  extern void d_xswap(double x[4194304], int ix0, int iy0);
  extern void e_xswap(double x[16777216], int ix0, int iy0);
  extern void xswap(double x[65536], int ix0, int iy0);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for xswap.h
 *
 * [EOF]
 */
