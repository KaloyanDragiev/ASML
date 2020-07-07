/*
 * File: xscal.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

#ifndef XSCAL_H
#define XSCAL_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void b_xscal(double a, double x[1048576], int ix0);
  extern void c_xscal(double a, double x[4194304], int ix0);
  extern void d_xscal(double a, double x[16777216], int ix0);
  extern void xscal(double a, double x[262144], int ix0);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for xscal.h
 *
 * [EOF]
 */
