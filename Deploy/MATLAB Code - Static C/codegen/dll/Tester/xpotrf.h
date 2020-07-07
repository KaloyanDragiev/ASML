/*
 * File: xpotrf.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
 */

#ifndef XPOTRF_H
#define XPOTRF_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern int b_xpotrf(double A[65536]);
  extern int c_xpotrf(double A[262144]);
  extern int d_xpotrf(double A[1048576]);
  extern int e_xpotrf(double A[4194304]);
  extern int f_xpotrf(double A[16777216]);
  extern int xpotrf(double A[10000]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for xpotrf.h
 *
 * [EOF]
 */
