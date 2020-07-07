/*
 * File: Tester_initialize.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:45:17
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "Tester_initialize.h"
#include "fileManager.h"
#include "eml_rand_shr3cong_stateful.h"
#include "eml_rand_mcg16807_stateful.h"
#include "eml_rand.h"
#include "eml_rand_mt19937ar_stateful.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void Tester_initialize(void)
{
  rt_InitInfAndNaN(8U);
  state_not_empty_init();
  eml_rand_init();
  eml_rand_mcg16807_stateful_init();
  eml_rand_shr3cong_stateful_init();
  filedata_init();
}

/*
 * File trailer for Tester_initialize.c
 *
 * [EOF]
 */
