/*
 * File: xtrsm.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 25-Nov-2019 15:28:30
 */

#ifndef XTRSM_H
#define XTRSM_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "f2_auto_tester_types.h"

/* Type Definitions */
#include "cblas.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void b_xtrsm(const double A[10000], double B[100]);
  extern void c_xtrsm(const double A[1000000], double B[1000000]);
  extern void d_xtrsm(const double A[1000000], double B[1000000]);
  extern void e_xtrsm(const double A[1000000], double B[1000000]);
  extern void f_xtrsm(const double A[1000000], double B[1000000]);
  extern void xtrsm(const double A[10000], double B[100]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for xtrsm.h
 *
 * [EOF]
 */
