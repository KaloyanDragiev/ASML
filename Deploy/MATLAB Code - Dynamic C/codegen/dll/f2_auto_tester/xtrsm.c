/*
 * File: xtrsm.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 25-Nov-2019 15:28:30
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "f2_auto_tester.h"
#include "xtrsm.h"
#include "cblas.h"

/* Type Definitions */

/* Function Definitions */

/*
 * Arguments    : const double A[10000]
 *                double B[100]
 * Return Type  : void
 */
void b_xtrsm(const double A[10000], double B[100])
{
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit,
              (int)100, (int)1, 1.0, &A[0], (int)100, &B[0], (int)100);
}

/*
 * Arguments    : const double A[1000000]
 *                double B[1000000]
 * Return Type  : void
 */
void c_xtrsm(const double A[1000000], double B[1000000])
{
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasUnit,
              (int)1000, (int)1000, 1.0, &A[0], (int)1000, &B[0], (int)1000);
}

/*
 * Arguments    : const double A[1000000]
 *                double B[1000000]
 * Return Type  : void
 */
void d_xtrsm(const double A[1000000], double B[1000000])
{
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit,
              (int)1000, (int)1000, 1.0, &A[0], (int)1000, &B[0], (int)1000);
}

/*
 * Arguments    : const double A[1000000]
 *                double B[1000000]
 * Return Type  : void
 */
void e_xtrsm(const double A[1000000], double B[1000000])
{
  cblas_dtrsm(CblasColMajor, CblasRight, CblasUpper, CblasNoTrans, CblasNonUnit,
              (int)1000, (int)1000, 1.0, &A[0], (int)1000, &B[0], (int)1000);
}

/*
 * Arguments    : const double A[1000000]
 *                double B[1000000]
 * Return Type  : void
 */
void f_xtrsm(const double A[1000000], double B[1000000])
{
  cblas_dtrsm(CblasColMajor, CblasRight, CblasLower, CblasNoTrans, CblasUnit,
              (int)1000, (int)1000, 1.0, &A[0], (int)1000, &B[0], (int)1000);
}

/*
 * Arguments    : const double A[10000]
 *                double B[100]
 * Return Type  : void
 */
void xtrsm(const double A[10000], double B[100])
{
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasUnit,
              (int)100, (int)1, 1.0, &A[0], (int)100, &B[0], (int)100);
}

/*
 * File trailer for xtrsm.c
 *
 * [EOF]
 */
