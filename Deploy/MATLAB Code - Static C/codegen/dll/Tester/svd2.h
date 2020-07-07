/*
 * File: svd2.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
 */

#ifndef SVD2_H
#define SVD2_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void b_svd(const double A[262144], double U[262144], double s[512],
                    double V[262144]);
  extern void c_svd(const double A[1048576], double U[1048576], double s[1024],
                    double V[1048576]);
  extern void d_svd(const double A[4194304], double U[4194304], double s[2048],
                    double V[4194304]);
  extern void e_svd(const double A[16777216], double U[16777216], double s[4096],
                    double V[16777216]);
  extern void svd(const double A[65536], double U[65536], double s[256], double
                  V[65536]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for svd2.h
 *
 * [EOF]
 */
