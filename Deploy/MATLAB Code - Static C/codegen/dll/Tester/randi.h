/*
 * File: randi.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
 */

#ifndef RANDI_H
#define RANDI_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void b_randi(double r[262144]);
  extern void c_randi(double r[1048576]);
  extern void d_randi(double r[4194304]);
  extern void e_randi(double r[16777216]);
  extern void randi(double r[65536]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for randi.h
 *
 * [EOF]
 */
