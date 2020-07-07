/*
 * File: f2_auto_tester_types.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 25-Nov-2019 15:28:30
 */

#ifndef F2_AUTO_TESTER_TYPES_H
#define F2_AUTO_TESTER_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#include "cblas.h"
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

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  double A[1000000];
  double B[1000000];
  double C[1000000];
  __attribute((aligned(16))) double D[1000000];
} struct_T;

#endif                                 /*typedef_struct_T*/
#endif

/*
 * File trailer for f2_auto_tester_types.h
 *
 * [EOF]
 */
