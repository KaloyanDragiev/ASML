/*
 * File: magic.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 09-Jan-2020 11:21:18
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "f3_auto_tester.h"
#include "magic.h"
#include "fix.h"
#include "mod.h"
#include "meshgrid.h"

/* Function Definitions */

/*
 * Arguments    : double M[16192576]
 * Return Type  : void
 */
void magic(double M[16192576])
{
  int z;
  double dv0[4024];
  static double J[16192576];
  static double b_I[16192576];
  static int iv0[16192576];
  int b_M;
  double d0;
  double d1;
  for (z = 0; z < 4024; z++) {
    dv0[z] = 1.0 + (double)z;
  }

  meshgrid(dv0, J, b_I);
  for (z = 0; z < 16192576; z++) {
    iv0[z] = 1 + z;
  }

  for (z = 0; z < 4024; z++) {
    for (b_M = 0; b_M < 4024; b_M++) {
      M[b_M + 4024 * z] = iv0[z + 4024 * b_M];
    }
  }

  for (z = 0; z < 16192576; z++) {
    b_M = (int)M[z];
    d0 = b_mod(b_I[z]) / 2.0;
    b_fix(&d0);
    d1 = b_mod(J[z]) / 2.0;
    b_fix(&d1);
    if (d0 == d1) {
      b_M = 16192577 - (int)M[z];
    }

    M[z] = b_M;
  }
}

/*
 * File trailer for magic.c
 *
 * [EOF]
 */
