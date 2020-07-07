/*
 * File: xgetrf.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 25-Nov-2019 15:28:30
 */

#ifndef XGETRF_H
#define XGETRF_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "f2_auto_tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void b_xgetrf(double A[1000000], int ipiv[1000], int *info);
  extern void xgetrf(double A[10000], int ipiv[100], int *info);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for xgetrf.h
 *
 * [EOF]
 */
