/*
 * File: xaxpy.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:35:01
 */

#ifndef XAXPY_H
#define XAXPY_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void b_xaxpy(int n, double a, const emxArray_real_T *x, int ix0,
                      emxArray_real_T *y, int iy0);
  extern void xaxpy(int n, double a, int ix0, emxArray_real_T *y, int iy0);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for xaxpy.h
 *
 * [EOF]
 */
