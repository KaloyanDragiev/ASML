/*
 * File: randi.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Tester.h"
#include "randi.h"
#include "rand.h"

/* Function Definitions */

/*
 * Arguments    : double r[262144]
 * Return Type  : void
 */
void b_randi(double r[262144])
{
  int k;
  c_rand(r);
  for (k = 0; k < 262144; k++) {
    r[k] = 1.0 + floor(r[k] * 512.0);
  }
}

/*
 * Arguments    : double r[1048576]
 * Return Type  : void
 */
void c_randi(double r[1048576])
{
  int k;
  d_rand(r);
  for (k = 0; k < 1048576; k++) {
    r[k] = 1.0 + floor(r[k] * 1024.0);
  }
}

/*
 * Arguments    : double r[4194304]
 * Return Type  : void
 */
void d_randi(double r[4194304])
{
  int k;
  e_rand(r);
  for (k = 0; k < 4194304; k++) {
    r[k] = 1.0 + floor(r[k] * 2048.0);
  }
}

/*
 * Arguments    : double r[16777216]
 * Return Type  : void
 */
void e_randi(double r[16777216])
{
  int k;
  f_rand(r);
  for (k = 0; k < 16777216; k++) {
    r[k] = 1.0 + floor(r[k] * 4096.0);
  }
}

/*
 * Arguments    : double r[65536]
 * Return Type  : void
 */
void randi(double r[65536])
{
  int k;
  b_rand(r);
  for (k = 0; k < 65536; k++) {
    r[k] = 1.0 + floor(r[k] * 256.0);
  }
}

/*
 * File trailer for randi.c
 *
 * [EOF]
 */
