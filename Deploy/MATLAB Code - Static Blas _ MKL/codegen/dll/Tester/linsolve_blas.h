/*
 * File: linsolve_blas.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

#ifndef LINSOLVE_BLAS_H
#define LINSOLVE_BLAS_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void b_linsolve_blas(double A[10000], const emxArray_real_T *B,
    emxArray_real_T *result);
  extern void c_linsolve_blas(double A[10000], const double B[512],
    emxArray_real_T *result);
  extern void d_linsolve_blas(double A[10000], const double B[1024],
    emxArray_real_T *result);
  extern void e_linsolve_blas(double A[10000], const double B[2048],
    emxArray_real_T *result);
  extern void f_linsolve_blas(double A[10000], const double B[4096],
    emxArray_real_T *result);
  extern void linsolve_blas(double A[10000], const double B[256],
    emxArray_real_T *result);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for linsolve_blas.h
 *
 * [EOF]
 */
