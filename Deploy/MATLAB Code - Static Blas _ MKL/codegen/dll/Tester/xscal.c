/*
 * File: xscal.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "xscal.h"
#include "cblas.h"

/* Function Definitions */

/*
 * Arguments    : double a
 *                double x[1048576]
 *                int ix0
 * Return Type  : void
 */
void b_xscal(double a, double x[1048576], int ix0)
{
  cblas_dscal((int)1024, a, &x[ix0 - 1], (int)1);
}

/*
 * Arguments    : double a
 *                double x[4194304]
 *                int ix0
 * Return Type  : void
 */
void c_xscal(double a, double x[4194304], int ix0)
{
  cblas_dscal((int)2048, a, &x[ix0 - 1], (int)1);
}

/*
 * Arguments    : double a
 *                double x[16777216]
 *                int ix0
 * Return Type  : void
 */
void d_xscal(double a, double x[16777216], int ix0)
{
  cblas_dscal((int)4096, a, &x[ix0 - 1], (int)1);
}

/*
 * Arguments    : double a
 *                double x[262144]
 *                int ix0
 * Return Type  : void
 */
void xscal(double a, double x[262144], int ix0)
{
  cblas_dscal((int)512, a, &x[ix0 - 1], (int)1);
}

/*
 * File trailer for xscal.c
 *
 * [EOF]
 */
