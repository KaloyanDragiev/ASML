/*
 * File: anyNonFinite.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "anyNonFinite.h"

/* Function Definitions */

/*
 * Arguments    : const double x[65536]
 * Return Type  : boolean_T
 */
boolean_T anyNonFinite(const double x[65536])
{
  boolean_T p;
  int k;
  p = true;
  for (k = 0; k < 65536; k++) {
    if (p && ((!rtIsInf(x[k])) && (!rtIsNaN(x[k])))) {
      p = true;
    } else {
      p = false;
    }
  }

  return !p;
}

/*
 * Arguments    : const double x[262144]
 * Return Type  : boolean_T
 */
boolean_T b_anyNonFinite(const double x[262144])
{
  boolean_T p;
  int k;
  p = true;
  for (k = 0; k < 262144; k++) {
    if (p && ((!rtIsInf(x[k])) && (!rtIsNaN(x[k])))) {
      p = true;
    } else {
      p = false;
    }
  }

  return !p;
}

/*
 * Arguments    : const double x[1048576]
 * Return Type  : boolean_T
 */
boolean_T c_anyNonFinite(const double x[1048576])
{
  boolean_T p;
  int k;
  p = true;
  for (k = 0; k < 1048576; k++) {
    if (p && ((!rtIsInf(x[k])) && (!rtIsNaN(x[k])))) {
      p = true;
    } else {
      p = false;
    }
  }

  return !p;
}

/*
 * Arguments    : const double x[4194304]
 * Return Type  : boolean_T
 */
boolean_T d_anyNonFinite(const double x[4194304])
{
  boolean_T p;
  int k;
  p = true;
  for (k = 0; k < 4194304; k++) {
    if (p && ((!rtIsInf(x[k])) && (!rtIsNaN(x[k])))) {
      p = true;
    } else {
      p = false;
    }
  }

  return !p;
}

/*
 * Arguments    : const double x[16777216]
 * Return Type  : boolean_T
 */
boolean_T e_anyNonFinite(const double x[16777216])
{
  boolean_T p;
  int k;
  p = true;
  for (k = 0; k < 16777216; k++) {
    if (p && ((!rtIsInf(x[k])) && (!rtIsNaN(x[k])))) {
      p = true;
    } else {
      p = false;
    }
  }

  return !p;
}

/*
 * File trailer for anyNonFinite.c
 *
 * [EOF]
 */
