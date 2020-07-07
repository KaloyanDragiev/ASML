/*
 * File: Tester_types.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

#ifndef TESTER_TYPES_H
#define TESTER_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#include "cblas.h"
#include <stdio.h>
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#include <stddef.h>
#endif

/*
 * File trailer for Tester_types.h
 *
 * [EOF]
 */
