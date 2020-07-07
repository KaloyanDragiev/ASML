/*
 * File: trisolve.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:45:17
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "trisolve.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *A
 *                emxArray_real_T *B
 * Return Type  : void
 */
void b_trisolve(const emxArray_real_T *A, emxArray_real_T *B)
{
  int mB;
  int n;
  int u0;
  int jBcol;
  int u1;
  int k;
  int kAcol;
  int i12;
  int i;
  int i13;
  mB = B->size[0];
  n = B->size[1];
  u0 = A->size[0];
  jBcol = A->size[1];
  if (u0 < jBcol) {
    jBcol = u0;
  }

  u1 = B->size[0];
  if (jBcol < u1) {
    u1 = jBcol;
  }

  if ((B->size[1] == 0) || ((B->size[0] == 0) || (B->size[1] == 0))) {
  } else {
    for (u0 = 0; u0 < n; u0++) {
      jBcol = mB * u0 - 1;
      for (k = u1; k >= 1; k--) {
        kAcol = A->size[0] * (k - 1) - 1;
        i12 = k + jBcol;
        if (B->data[i12] != 0.0) {
          B->data[i12] /= A->data[k + kAcol];
          for (i = 0; i <= k - 2; i++) {
            i13 = (i + jBcol) + 1;
            B->data[i13] -= B->data[i12] * A->data[(i + kAcol) + 1];
          }
        }
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *A
 *                emxArray_real_T *B
 * Return Type  : void
 */
void trisolve(const emxArray_real_T *A, emxArray_real_T *B)
{
  int mB;
  int n;
  int u0;
  int u1;
  int b_u1;
  int j;
  int jBcol;
  int k;
  int kAcol;
  int i8;
  int i9;
  mB = B->size[0];
  n = B->size[1];
  u0 = A->size[0];
  u1 = A->size[1];
  if (u0 < u1) {
    u1 = u0;
  }

  b_u1 = B->size[0];
  if (u1 < b_u1) {
    b_u1 = u1;
  }

  if ((B->size[1] == 0) || ((B->size[0] == 0) || (B->size[1] == 0))) {
  } else {
    for (j = 0; j < n; j++) {
      jBcol = mB * j - 1;
      for (k = 0; k < b_u1; k++) {
        u0 = 1 + k;
        kAcol = A->size[0] * (u0 - 1) - 1;
        i8 = u0 + jBcol;
        if (B->data[i8] != 0.0) {
          B->data[i8] /= A->data[u0 + kAcol];
          u0++;
          for (u1 = u0; u1 <= b_u1; u1++) {
            i9 = u1 + jBcol;
            B->data[i9] -= B->data[i8] * A->data[u1 + kAcol];
          }
        }
      }
    }
  }
}

/*
 * File trailer for trisolve.c
 *
 * [EOF]
 */
