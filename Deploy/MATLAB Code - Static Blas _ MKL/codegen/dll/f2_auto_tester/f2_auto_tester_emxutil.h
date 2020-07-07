/*
 * File: f2_auto_tester_emxutil.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 25-Nov-2019 15:28:30
 */

#ifndef F2_AUTO_TESTER_EMXUTIL_H
#define F2_AUTO_TESTER_EMXUTIL_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "f2_auto_tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
  extern void emxFree_real_T(emxArray_real_T **pEmxArray);
  extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for f2_auto_tester_emxutil.h
 *
 * [EOF]
 */
