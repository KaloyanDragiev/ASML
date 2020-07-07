/*
 * File: SVD.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
 */

#ifndef SVD_H
#define SVD_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Tester_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void SVD(const double A[65536], double u[65536], double S[65536],
                  double V[65536]);
  extern void b_SVD(const double A[262144], double u[262144], double S[262144],
                    double V[262144]);
  extern void c_SVD(const double A[1048576], double u[1048576], double S[1048576],
                    double V[1048576]);
  extern void d_SVD(const double A[4194304], double u[4194304], double S[4194304],
                    double V[4194304]);
  extern void e_SVD(const double A[16777216], double u[16777216], double S
                    [16777216], double V[16777216]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for SVD.h
 *
 * [EOF]
 */
