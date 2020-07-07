/*
 * File: _coder_f3_auto_tester_api.h
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 09-Jan-2020 11:21:18
 */

#ifndef _CODER_F3_AUTO_TESTER_API_H
#define _CODER_F3_AUTO_TESTER_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_f3_auto_tester_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void f3_auto_tester(void);
  extern void f3_auto_tester_api(int32_T nlhs);
  extern void f3_auto_tester_atexit(void);
  extern void f3_auto_tester_initialize(void);
  extern void f3_auto_tester_terminate(void);
  extern void f3_auto_tester_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_f3_auto_tester_api.h
 *
 * [EOF]
 */
