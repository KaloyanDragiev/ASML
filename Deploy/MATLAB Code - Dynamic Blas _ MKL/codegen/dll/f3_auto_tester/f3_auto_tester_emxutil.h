/*
 * File: f3_auto_tester_emxutil.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 09-Jan-2020 11:21:18
 */

#ifndef F3_AUTO_TESTER_EMXUTIL_H
#define F3_AUTO_TESTER_EMXUTIL_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "f3_auto_tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);
  extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
  extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
  extern void emxFree_real_T(emxArray_real_T **pEmxArray);
  extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
  extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for f3_auto_tester_emxutil.h
 *
 * [EOF]
 */
