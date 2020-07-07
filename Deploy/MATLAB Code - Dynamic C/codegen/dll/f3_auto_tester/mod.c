/*
 * File: mod.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 09-Jan-2020 11:21:18
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "f3_auto_tester.h"
#include "mod.h"

/* Function Definitions */

/*
 * Arguments    : double x
 * Return Type  : double
 */
double b_mod(double x)
{
  double r;
  if ((!rtIsInf(x)) && (!rtIsNaN(x))) {
    if (x == 0.0) {
      r = 0.0;
    } else {
      r = fmod(x, 4.0);
      if (r == 0.0) {
        r = 0.0;
      } else {
        if (x < 0.0) {
          r += 4.0;
        }
      }
    }
  } else {
    r = rtNaN;
  }

  return r;
}

/*
 * File trailer for mod.c
 *
 * [EOF]
 */
