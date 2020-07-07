/*
 * File: f3_array_save_bin.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:35:01
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
 * Arguments    : const emxArray_real_T *data
 * Return Type  : double
 */
double c_f3_array_save_bin(const emxArray_real_T *data)
{
  double err;
  signed char fileid;
  int data_idx_0;
  emxArray_real_T b_data;
  int c_data[1];
  err = 0.0;
  fileid = cfopen("f3_chol.bin", "wb");
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
 * Arguments    : const emxArray_real_T *data
 * Return Type  : double
 */
double d_f3_array_save_bin(const emxArray_real_T *data)
{
  double err;
  signed char fileid;
  int data_idx_0;
  emxArray_real_T b_data;
  int c_data[1];
  err = 0.0;
  fileid = cfopen("f3_svd.bin", "wb");
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
 * Arguments    : const emxArray_real_T *data
 * Return Type  : double
 */
double e_f3_array_save_bin(const emxArray_real_T *data)
{
  double err;
  signed char fileid;
  err = 0.0;
  fileid = cfopen("f3_multiplyNorm.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    b_fwrite(fileid, data);
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
 * Arguments    : const emxArray_real_T *data
 * Return Type  : double
 */
double f_f3_array_save_bin(const emxArray_real_T *data)
{
  double err;
  signed char fileid;
  err = 0.0;
  fileid = cfopen("f3_multiplySmart.bin", "wb");
  if (fileid < 0) {
    err = 1.0;
  } else {
    b_fwrite(fileid, data);
    b_fclose(fileid);
  }

  return err;
}

/*
 * File trailer for f3_array_save_bin.c
 *
 * [EOF]
 */
