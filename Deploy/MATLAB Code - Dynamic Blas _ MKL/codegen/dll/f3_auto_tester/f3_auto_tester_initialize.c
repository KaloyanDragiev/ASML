/*
 * File: f3_auto_tester_initialize.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 09-Jan-2020 11:21:18
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "f3_auto_tester.h"
#include "f3_auto_tester_initialize.h"
#include "fileManager.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void f3_auto_tester_initialize(void)
{
  rt_InitInfAndNaN(8U);
  filedata_init();
}

/*
 * File trailer for f3_auto_tester_initialize.c
 *
 * [EOF]
 */
