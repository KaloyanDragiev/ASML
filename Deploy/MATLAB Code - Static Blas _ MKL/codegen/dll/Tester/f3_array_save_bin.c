/*
 * File: f3_array_save_bin.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:28:22
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "f3_array_save_bin.h"
#include "fclose.h"
#include "fwrite.h"
#include "fileManager.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *data
 * Return Type  : double
 */
double b_f3_array_save_bin(const emxArray_real_T *data)
{
  double err;
  signed char fileid;
  int data_idx_0;
  emxArray_real_T b_data;
  int c_data[1];
  err = 0.0;
  fileid = cfopen("f3_lin_y.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    data_idx_0 = data->size[0] * data->size[1];
    b_data = *data;
    c_data[0] = data_idx_0;
    b_data.size = &c_data[0];
    b_data.numDimensions = 1;
    b_fwrite(fileid, &b_data);
    b_fclose(fileid);
  }

  return err;
}

/*
 * Arguments    : const double data[65536]
 * Return Type  : double
 */
double c_f3_array_save_bin(const double data[65536])
{
  double err;
  signed char fileid;
  err = 0.0;
  fileid = cfopen("f3_chol.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    c_fwrite(fileid, data);
    b_fclose(fileid);
  }

  return err;
}

/*
 * Arguments    : const double data[65536]
 * Return Type  : double
 */
double d_f3_array_save_bin(const double data[65536])
{
  double err;
  signed char fileid;
  err = 0.0;
  fileid = cfopen("f3_svd.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    c_fwrite(fileid, data);
    b_fclose(fileid);
  }

  return err;
}

/*
 * Arguments    : const double data[256]
 * Return Type  : double
 */
double e_f3_array_save_bin(const double data[256])
{
  double err;
  signed char fileid;
  FILE * filestar;
  boolean_T autoflush;
  size_t bytesOutSizet;
  err = 0.0;
  fileid = cfopen("f3_multiplyNorm.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    getFileStar(fileid, &filestar, &autoflush);
    if (!(filestar == NULL)) {
      bytesOutSizet = fwrite(&data[0], (size_t)sizeof(double), (size_t)256,
        filestar);
      if (((double)bytesOutSizet > 0.0) && autoflush) {
        fflush(filestar);
      }
    }

    b_fclose(fileid);
  }

  return err;
}

/*
 * Arguments    : const emxArray_real_T *data
 * Return Type  : double
 */
double f3_array_save_bin(const emxArray_real_T *data)
{
  double err;
  signed char fileid;
  int data_idx_0;
  emxArray_real_T b_data;
  int c_data[1];
  err = 0.0;
  fileid = cfopen("f3_lin_x.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    data_idx_0 = data->size[0] * data->size[1];
    b_data = *data;
    c_data[0] = data_idx_0;
    b_data.size = &c_data[0];
    b_data.numDimensions = 1;
    b_fwrite(fileid, &b_data);
    b_fclose(fileid);
  }

  return err;
}

/*
 * Arguments    : const double data[100]
 * Return Type  : double
 */
double f_f3_array_save_bin(const double data[100])
{
  double err;
  signed char fileid;
  FILE * filestar;
  boolean_T autoflush;
  size_t bytesOutSizet;
  err = 0.0;
  fileid = cfopen("f3_multiplySmart.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    getFileStar(fileid, &filestar, &autoflush);
    if (!(filestar == NULL)) {
      bytesOutSizet = fwrite(&data[0], (size_t)sizeof(double), (size_t)100,
        filestar);
      if (((double)bytesOutSizet > 0.0) && autoflush) {
        fflush(filestar);
      }
    }

    b_fclose(fileid);
  }

  return err;
}

/*
 * Arguments    : const double data[262144]
 * Return Type  : double
 */
double g_f3_array_save_bin(const double data[262144])
{
  double err;
  signed char fileid;
  err = 0.0;
  fileid = cfopen("f3_chol.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    d_fwrite(fileid, data);
    b_fclose(fileid);
  }

  return err;
}

/*
 * Arguments    : const double data[262144]
 * Return Type  : double
 */
double h_f3_array_save_bin(const double data[262144])
{
  double err;
  signed char fileid;
  err = 0.0;
  fileid = cfopen("f3_svd.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    d_fwrite(fileid, data);
    b_fclose(fileid);
  }

  return err;
}

/*
 * Arguments    : const double data[512]
 * Return Type  : double
 */
double i_f3_array_save_bin(const double data[512])
{
  double err;
  signed char fileid;
  FILE * filestar;
  boolean_T autoflush;
  size_t bytesOutSizet;
  err = 0.0;
  fileid = cfopen("f3_multiplyNorm.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    getFileStar(fileid, &filestar, &autoflush);
    if (!(filestar == NULL)) {
      bytesOutSizet = fwrite(&data[0], (size_t)sizeof(double), (size_t)512,
        filestar);
      if (((double)bytesOutSizet > 0.0) && autoflush) {
        fflush(filestar);
      }
    }

    b_fclose(fileid);
  }

  return err;
}

/*
 * Arguments    : const double data[1048576]
 * Return Type  : double
 */
double j_f3_array_save_bin(const double data[1048576])
{
  double err;
  signed char fileid;
  err = 0.0;
  fileid = cfopen("f3_chol.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    e_fwrite(fileid, data);
    b_fclose(fileid);
  }

  return err;
}

/*
 * Arguments    : const double data[1048576]
 * Return Type  : double
 */
double k_f3_array_save_bin(const double data[1048576])
{
  double err;
  signed char fileid;
  err = 0.0;
  fileid = cfopen("f3_svd.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    e_fwrite(fileid, data);
    b_fclose(fileid);
  }

  return err;
}

/*
 * Arguments    : const double data[1024]
 * Return Type  : double
 */
double l_f3_array_save_bin(const double data[1024])
{
  double err;
  signed char fileid;
  FILE * filestar;
  boolean_T autoflush;
  size_t bytesOutSizet;
  err = 0.0;
  fileid = cfopen("f3_multiplyNorm.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    getFileStar(fileid, &filestar, &autoflush);
    if (!(filestar == NULL)) {
      bytesOutSizet = fwrite(&data[0], (size_t)sizeof(double), (size_t)1024,
        filestar);
      if (((double)bytesOutSizet > 0.0) && autoflush) {
        fflush(filestar);
      }
    }

    b_fclose(fileid);
  }

  return err;
}

/*
 * Arguments    : const double data[4194304]
 * Return Type  : double
 */
double m_f3_array_save_bin(const double data[4194304])
{
  double err;
  signed char fileid;
  err = 0.0;
  fileid = cfopen("f3_chol.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    f_fwrite(fileid, data);
    b_fclose(fileid);
  }

  return err;
}

/*
 * Arguments    : const double data[4194304]
 * Return Type  : double
 */
double n_f3_array_save_bin(const double data[4194304])
{
  double err;
  signed char fileid;
  err = 0.0;
  fileid = cfopen("f3_svd.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    f_fwrite(fileid, data);
    b_fclose(fileid);
  }

  return err;
}

/*
 * Arguments    : const double data[2048]
 * Return Type  : double
 */
double o_f3_array_save_bin(const double data[2048])
{
  double err;
  signed char fileid;
  FILE * filestar;
  boolean_T autoflush;
  size_t bytesOutSizet;
  err = 0.0;
  fileid = cfopen("f3_multiplyNorm.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    getFileStar(fileid, &filestar, &autoflush);
    if (!(filestar == NULL)) {
      bytesOutSizet = fwrite(&data[0], (size_t)sizeof(double), (size_t)2048,
        filestar);
      if (((double)bytesOutSizet > 0.0) && autoflush) {
        fflush(filestar);
      }
    }

    b_fclose(fileid);
  }

  return err;
}

/*
 * Arguments    : const double data[16777216]
 * Return Type  : double
 */
double p_f3_array_save_bin(const double data[16777216])
{
  double err;
  signed char fileid;
  err = 0.0;
  fileid = cfopen("f3_chol.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    g_fwrite(fileid, data);
    b_fclose(fileid);
  }

  return err;
}

/*
 * Arguments    : const double data[16777216]
 * Return Type  : double
 */
double q_f3_array_save_bin(const double data[16777216])
{
  double err;
  signed char fileid;
  err = 0.0;
  fileid = cfopen("f3_svd.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    g_fwrite(fileid, data);
    b_fclose(fileid);
  }

  return err;
}

/*
 * Arguments    : const double data[4096]
 * Return Type  : double
 */
double r_f3_array_save_bin(const double data[4096])
{
  double err;
  signed char fileid;
  FILE * filestar;
  boolean_T autoflush;
  size_t bytesOutSizet;
  err = 0.0;
  fileid = cfopen("f3_multiplyNorm.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    getFileStar(fileid, &filestar, &autoflush);
    if (!(filestar == NULL)) {
      bytesOutSizet = fwrite(&data[0], (size_t)sizeof(double), (size_t)4096,
        filestar);
      if (((double)bytesOutSizet > 0.0) && autoflush) {
        fflush(filestar);
      }
    }

    b_fclose(fileid);
  }

  return err;
}

/*
 * File trailer for f3_array_save_bin.c
 *
 * [EOF]
 */
