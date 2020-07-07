/*
 * File: fileManager.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tester.h"
#include "fileManager.h"
#include "Tester_data.h"

/* Function Declarations */
static signed char filedata(void);

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : signed char
 */
static signed char filedata(void)
{
  signed char f;
  int k;
  boolean_T exitg1;
  f = 0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 20)) {
    if (eml_openfiles[k] == NULL) {
      f = (signed char)(k + 1);
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/*
 * Arguments    : const char * cfilename
 *                const char * cpermission
 * Return Type  : signed char
 */
signed char cfopen(const char * cfilename, const char * cpermission)
{
  signed char fileid;
  signed char j;
  FILE * filestar;
  int i2;
  fileid = -1;
  j = filedata();
  if (j >= 1) {
    filestar = fopen(cfilename, cpermission);
    if (filestar != NULL) {
      eml_openfiles[j - 1] = filestar;
      eml_autoflush[j - 1] = true;
      i2 = j + 2;
      if (i2 > 127) {
        i2 = 127;
      }

      fileid = (signed char)i2;
    }
  }

  return fileid;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void filedata_init(void)
{
  FILE * a;
  int i;
  a = NULL;
  for (i = 0; i < 20; i++) {
    eml_autoflush[i] = false;
    eml_openfiles[i] = a;
  }
}

/*
 * File trailer for fileManager.c
 *
 * [EOF]
 */
