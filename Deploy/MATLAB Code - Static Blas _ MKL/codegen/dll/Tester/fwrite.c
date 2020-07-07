/*
 * File: fwrite.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "fwrite.h"
#include "fclose.h"
#include "Tester_rtwutil.h"
#include "Tester_data.h"

/* Function Definitions */

/*
 * Arguments    : double fileID
 *                const emxArray_real_T *x
 * Return Type  : void
 */
void b_fwrite(double fileID, const emxArray_real_T *x)
{
  FILE * filestar;
  boolean_T autoflush;
  size_t bytesOutSizet;
  getFileStar(fileID, &filestar, &autoflush);
  if ((filestar == NULL) || (x->size[0] == 0)) {
  } else {
    bytesOutSizet = fwrite(&x->data[0], (size_t)sizeof(double), (size_t)x->size
      [0], filestar);
    if (((double)bytesOutSizet > 0.0) && autoflush) {
      fflush(filestar);
    }
  }
}

/*
 * Arguments    : double fileID
 *                const double x[65536]
 * Return Type  : void
 */
void c_fwrite(double fileID, const double x[65536])
{
  FILE * filestar;
  boolean_T autoflush;
  size_t bytesOutSizet;
  getFileStar(fileID, &filestar, &autoflush);
  if (!(filestar == NULL)) {
    bytesOutSizet = fwrite(&x[0], (size_t)sizeof(double), (size_t)65536,
      filestar);
    if (((double)bytesOutSizet > 0.0) && autoflush) {
      fflush(filestar);
    }
  }
}

/*
 * Arguments    : double fileID
 *                const double x[262144]
 * Return Type  : void
 */
void d_fwrite(double fileID, const double x[262144])
{
  FILE * filestar;
  boolean_T autoflush;
  size_t bytesOutSizet;
  getFileStar(fileID, &filestar, &autoflush);
  if (!(filestar == NULL)) {
    bytesOutSizet = fwrite(&x[0], (size_t)sizeof(double), (size_t)262144,
      filestar);
    if (((double)bytesOutSizet > 0.0) && autoflush) {
      fflush(filestar);
    }
  }
}

/*
 * Arguments    : double fileID
 *                const double x[1048576]
 * Return Type  : void
 */
void e_fwrite(double fileID, const double x[1048576])
{
  FILE * filestar;
  boolean_T autoflush;
  size_t bytesOutSizet;
  getFileStar(fileID, &filestar, &autoflush);
  if (!(filestar == NULL)) {
    bytesOutSizet = fwrite(&x[0], (size_t)sizeof(double), (size_t)1048576,
      filestar);
    if (((double)bytesOutSizet > 0.0) && autoflush) {
      fflush(filestar);
    }
  }
}

/*
 * Arguments    : double fileID
 *                const double x[4194304]
 * Return Type  : void
 */
void f_fwrite(double fileID, const double x[4194304])
{
  FILE * filestar;
  boolean_T autoflush;
  size_t bytesOutSizet;
  getFileStar(fileID, &filestar, &autoflush);
  if (!(filestar == NULL)) {
    bytesOutSizet = fwrite(&x[0], (size_t)sizeof(double), (size_t)4194304,
      filestar);
    if (((double)bytesOutSizet > 0.0) && autoflush) {
      fflush(filestar);
    }
  }
}

/*
 * Arguments    : double fileID
 *                const double x[16777216]
 * Return Type  : void
 */
void g_fwrite(double fileID, const double x[16777216])
{
  FILE * filestar;
  boolean_T autoflush;
  size_t bytesOutSizet;
  getFileStar(fileID, &filestar, &autoflush);
  if (!(filestar == NULL)) {
    bytesOutSizet = fwrite(&x[0], (size_t)sizeof(double), (size_t)16777216,
      filestar);
    if (((double)bytesOutSizet > 0.0) && autoflush) {
      fflush(filestar);
    }
  }
}

/*
 * Arguments    : double fileID
 *                FILE * *filestar
 *                boolean_T *autoflush
 * Return Type  : void
 */
void getFileStar(double fileID, FILE * *filestar, boolean_T *autoflush)
{
  signed char fileid;
  fileid = (signed char)rt_roundd_snf(fileID);
  if ((fileid > 22) || (fileid < 0) || (fileID != fileid)) {
    fileid = -1;
  }

  if (fileid >= 3) {
    *filestar = eml_openfiles[fileid - 3];
    *autoflush = eml_autoflush[fileid - 3];
  } else if (fileid == 0) {
    *filestar = stdin;
    *autoflush = true;
  } else if (fileid == 1) {
    *filestar = stdout;
    *autoflush = true;
  } else if (fileid == 2) {
    *filestar = stderr;
    *autoflush = true;
  } else {
    *filestar = NULL;
    *autoflush = true;
  }

  if (!(fileID != 0.0)) {
    *filestar = NULL;
  }
}

/*
 * File trailer for fwrite.c
 *
 * [EOF]
 */
