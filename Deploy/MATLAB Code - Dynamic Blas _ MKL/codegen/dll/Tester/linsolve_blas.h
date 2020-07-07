/*
 * File: linsolve_blas.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:35:01
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

  extern void linsolve_blas(emxArray_real_T *A, const emxArray_real_T *B, double
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
