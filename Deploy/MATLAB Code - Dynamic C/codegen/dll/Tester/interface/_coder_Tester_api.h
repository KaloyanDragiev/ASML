/*
 * File: _coder_Tester_api.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:45:17
 */

#ifndef _CODER_TESTER_API_H
#define _CODER_TESTER_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_Tester_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void Tester(void);
  extern void Tester_api(int32_T nlhs);
  extern void Tester_atexit(void);
  extern void Tester_initialize(void);
  extern void Tester_terminate(void);
  extern void Tester_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_Tester_api.h
 *
 * [EOF]
 */
