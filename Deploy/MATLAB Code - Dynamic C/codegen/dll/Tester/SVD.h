/*
 * File: SVD.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:45:17
 */

#ifndef SVD_H
#define SVD_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void SVD(const emxArray_real_T *A, double data_nrow, double data_ncol,
                  emxArray_real_T *u, emxArray_real_T *S, emxArray_real_T *V);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for SVD.h
 *
 * [EOF]
 */
