/*
 * File: rand.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

#ifndef RAND_H
#define RAND_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void b_rand(double r[65536]);
  extern void c_rand(double r[262144]);
  extern void d_rand(double r[1048576]);
  extern void e_rand(double r[4194304]);
  extern void f_rand(double r[16777216]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for rand.h
 *
 * [EOF]
 */
