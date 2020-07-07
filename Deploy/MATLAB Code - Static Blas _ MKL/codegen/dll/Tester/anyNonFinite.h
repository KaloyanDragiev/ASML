/*
 * File: anyNonFinite.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

#ifndef ANYNONFINITE_H
#define ANYNONFINITE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern boolean_T anyNonFinite(const double x[65536]);
  extern boolean_T b_anyNonFinite(const double x[262144]);
  extern boolean_T c_anyNonFinite(const double x[1048576]);
  extern boolean_T d_anyNonFinite(const double x[4194304]);
  extern boolean_T e_anyNonFinite(const double x[16777216]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for anyNonFinite.h
 *
 * [EOF]
 */
