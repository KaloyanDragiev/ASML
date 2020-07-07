/*
 * File: xrot.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
 */

#ifndef XROT_H
#define XROT_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void b_xrot(double x[262144], int ix0, int iy0, double c, double s);
  extern void c_xrot(double x[1048576], int ix0, int iy0, double c, double s);
  extern void d_xrot(double x[4194304], int ix0, int iy0, double c, double s);
  extern void e_xrot(double x[16777216], int ix0, int iy0, double c, double s);
  extern void xrot(double x[65536], int ix0, int iy0, double c, double s);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for xrot.h
 *
 * [EOF]
 */