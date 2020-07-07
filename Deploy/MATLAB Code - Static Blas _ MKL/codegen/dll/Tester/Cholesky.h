/*
 * File: Cholesky.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

#ifndef CHOLESKY_H
#define CHOLESKY_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void Cholesky(const double A[65536], double L[10000]);
  extern void b_Cholesky(const double A[262144], double L[10000]);
  extern void c_Cholesky(const double A[1048576], double L[10000]);
  extern void d_Cholesky(const double A[4194304], double L[10000]);
  extern void e_Cholesky(const double A[16777216], double L[10000]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for Cholesky.h
 *
 * [EOF]
 */
