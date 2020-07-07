/*
 * File: fwrite.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
 */

#ifndef FWRITE_H
#define FWRITE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void b_fwrite(double fileID, const emxArray_real_T *x);
  extern void c_fwrite(double fileID, const double x[65536]);
  extern void d_fwrite(double fileID, const double x[262144]);
  extern void e_fwrite(double fileID, const double x[1048576]);
  extern void f_fwrite(double fileID, const double x[4194304]);
  extern void g_fwrite(double fileID, const double x[16777216]);
  extern void getFileStar(double fileID, FILE * *filestar, boolean_T *autoflush);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for fwrite.h
 *
 * [EOF]
 */
