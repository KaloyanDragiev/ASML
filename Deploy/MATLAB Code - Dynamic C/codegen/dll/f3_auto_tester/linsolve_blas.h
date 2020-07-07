/*
 * File: linsolve_blas.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 09-Jan-2020 11:21:18
 */

#ifndef LINSOLVE_BLAS_H
#define LINSOLVE_BLAS_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "f3_auto_tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void b_linsolve_blas(double A[10000], const emxArray_real_T *B, double
    data_nrow, double data_ncol, boolean_T opts_LT, emxArray_real_T *result);
  extern void linsolve_blas(double A[10000], const double B[4024], double
    data_nrow, double data_ncol, boolean_T opts_LT, emxArray_real_T *result);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for linsolve_blas.h
 *
 * [EOF]
 */
