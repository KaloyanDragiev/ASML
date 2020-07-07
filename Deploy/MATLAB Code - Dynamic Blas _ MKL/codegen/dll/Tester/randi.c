/*
 * File: randi.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:35:01
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Tester.h"
#include "randi.h"
#include "rand.h"

/* Function Definitions */

/*
 * Arguments    : double lowhigh
 *                double varargin_1
 *                emxArray_real_T *r
 * Return Type  : void
 */
void randi(double lowhigh, double varargin_1, emxArray_real_T *r)
{
  int i1;
  int k;
  b_rand(varargin_1, r);
  i1 = r->size[0] * r->size[1];
  for (k = 0; k < i1; k++) {
    r->data[k] = 1.0 + floor(r->data[k] * lowhigh);
  }
}

/*
 * File trailer for randi.c
 *
 * [EOF]
 */
