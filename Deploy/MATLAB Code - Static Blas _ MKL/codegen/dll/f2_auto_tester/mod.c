/*
 * File: mod.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 25-Nov-2019 15:28:30
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "f2_auto_tester.h"
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
 * Arguments    : const double x[1000000]
 *                double r[1000000]
 * Return Type  : void
 */
void c_mod(const double x[1000000], double r[1000000])
{
  int k;
  double b_r;
  for (k = 0; k < 1000000; k++) {
    if ((!rtIsInf(x[k])) && (!rtIsNaN(x[k]))) {
      if (x[k] == 0.0) {
        b_r = 0.0;
      } else {
        b_r = fmod(x[k], 9.0);
        if (b_r == 0.0) {
          b_r = 0.0;
        } else {
          if (x[k] < 0.0) {
            b_r += 9.0;
          }
        }
      }
    } else {
      b_r = rtNaN;
    }

    r[k] = b_r;
  }
}

/*
 * File trailer for mod.c
 *
 * [EOF]
 */
