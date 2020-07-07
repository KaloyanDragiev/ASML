/*
 * File: rand.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 25-Nov-2019 15:28:30
 */

/* Include Files */
#include <string.h>
#include "rt_nonfinite.h"
#include "f2_auto_tester.h"
#include "rand.h"
#include "f2_auto_tester_data.h"

/* Variable Definitions */
static unsigned int c_state[625];

/* Function Declarations */
static double eml_rand_mcg16807(unsigned int *d_state);
static double eml_rand_mt19937ar(unsigned int d_state[625]);

/* Function Definitions */

/*
 * Arguments    : unsigned int *d_state
 * Return Type  : double
 */
static double eml_rand_mcg16807(unsigned int *d_state)
{
  int hi;
  unsigned int a;
  unsigned int b;
  hi = (int)(*d_state / 127773U);
  a = 16807U * (*d_state - hi * 127773U);
  b = 2836U * hi;
  if (a < b) {
    *d_state = ~(b - a) & 2147483647U;
  } else {
    *d_state = a - b;
  }

  return (double)*d_state * 4.6566128752457969E-10;
}

/*
 * Arguments    : unsigned int d_state[625]
 * Return Type  : double
 */
static double eml_rand_mt19937ar(unsigned int d_state[625])
{
  double r;
  int j;
  unsigned int u[2];
  unsigned int mti;
  int kk;
  unsigned int y;

  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on:        */
  /*                                                                         */
  /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
  /*                                                                         */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
  /*  All rights reserved.                                                   */
  /*                                                                         */
  /*  Redistribution and use in source and binary forms, with or without     */
  /*  modification, are permitted provided that the following conditions     */
  /*  are met:                                                               */
  /*                                                                         */
  /*    1. Redistributions of source code must retain the above copyright    */
  /*       notice, this list of conditions and the following disclaimer.     */
  /*                                                                         */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer      */
  /*       in the documentation and/or other materials provided with the     */
  /*       distribution.                                                     */
  /*                                                                         */
  /*    3. The names of its contributors may not be used to endorse or       */
  /*       promote products derived from this software without specific      */
  /*       prior written permission.                                         */
  /*                                                                         */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
  /*                                                                         */
  /* =============================   END   ================================= */
  do {
    for (j = 0; j < 2; j++) {
      mti = d_state[624] + 1U;
      if (mti >= 625U) {
        for (kk = 0; kk < 227; kk++) {
          y = (d_state[kk] & 2147483648U) | (d_state[kk + 1] & 2147483647U);
          if ((y & 1U) == 0U) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          d_state[kk] = d_state[kk + 397] ^ y;
        }

        for (kk = 0; kk < 396; kk++) {
          y = (d_state[kk + 227] & 2147483648U) | (d_state[kk + 228] &
            2147483647U);
          if ((y & 1U) == 0U) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          d_state[kk + 227] = d_state[kk] ^ y;
        }

        y = (d_state[623] & 2147483648U) | (d_state[0] & 2147483647U);
        if ((y & 1U) == 0U) {
          y >>= 1U;
        } else {
          y = y >> 1U ^ 2567483615U;
        }

        d_state[623] = d_state[396] ^ y;
        mti = 1U;
      }

      y = d_state[(int)mti - 1];
      d_state[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      u[j] = y ^ y >> 18U;
    }

    u[0] >>= 5U;
    u[1] >>= 6U;
    r = 1.1102230246251565E-16 * ((double)u[0] * 6.7108864E+7 + (double)u[1]);
  } while (r == 0.0);

  return r;
}

/*
 * Arguments    : double r[10000]
 * Return Type  : void
 */
void b_rand(double r[10000])
{
  int mti;
  unsigned int b_r;
  unsigned int u0;
  if (method == 4U) {
    for (mti = 0; mti < 10000; mti++) {
      r[mti] = eml_rand_mcg16807(&state);
    }
  } else if (method == 5U) {
    for (mti = 0; mti < 10000; mti++) {
      b_r = 69069U * b_state[0] + 1234567U;
      u0 = b_state[1] ^ b_state[1] << 13;
      u0 ^= u0 >> 17;
      u0 ^= u0 << 5;
      b_state[0] = b_r;
      b_state[1] = u0;
      r[mti] = (double)(b_r + u0) * 2.328306436538696E-10;
    }
  } else {
    if (!state_not_empty) {
      memset(&c_state[0], 0, 625U * sizeof(unsigned int));
      b_r = 5489U;
      c_state[0] = 5489U;
      for (mti = 0; mti < 623; mti++) {
        b_r = ((b_r ^ b_r >> 30U) * 1812433253U + mti) + 1U;
        c_state[mti + 1] = b_r;
      }

      c_state[624] = 624U;
      state_not_empty = true;
    }

    for (mti = 0; mti < 10000; mti++) {
      r[mti] = eml_rand_mt19937ar(c_state);
    }
  }
}

/*
 * Arguments    : double r[100]
 * Return Type  : void
 */
void c_rand(double r[100])
{
  int mti;
  unsigned int b_r;
  unsigned int u1;
  if (method == 4U) {
    for (mti = 0; mti < 100; mti++) {
      r[mti] = eml_rand_mcg16807(&state);
    }
  } else if (method == 5U) {
    for (mti = 0; mti < 100; mti++) {
      b_r = 69069U * b_state[0] + 1234567U;
      u1 = b_state[1] ^ b_state[1] << 13;
      u1 ^= u1 >> 17;
      u1 ^= u1 << 5;
      b_state[0] = b_r;
      b_state[1] = u1;
      r[mti] = (double)(b_r + u1) * 2.328306436538696E-10;
    }
  } else {
    if (!state_not_empty) {
      memset(&c_state[0], 0, 625U * sizeof(unsigned int));
      b_r = 5489U;
      c_state[0] = 5489U;
      for (mti = 0; mti < 623; mti++) {
        b_r = ((b_r ^ b_r >> 30U) * 1812433253U + mti) + 1U;
        c_state[mti + 1] = b_r;
      }

      c_state[624] = 624U;
      state_not_empty = true;
    }

    for (mti = 0; mti < 100; mti++) {
      r[mti] = eml_rand_mt19937ar(c_state);
    }
  }
}

/*
 * Arguments    : double r[1000000]
 * Return Type  : void
 */
void d_rand(double r[1000000])
{
  int mti;
  unsigned int b_r;
  unsigned int u2;
  if (method == 4U) {
    for (mti = 0; mti < 1000000; mti++) {
      r[mti] = eml_rand_mcg16807(&state);
    }
  } else if (method == 5U) {
    for (mti = 0; mti < 1000000; mti++) {
      b_r = 69069U * b_state[0] + 1234567U;
      u2 = b_state[1] ^ b_state[1] << 13;
      u2 ^= u2 >> 17;
      u2 ^= u2 << 5;
      b_state[0] = b_r;
      b_state[1] = u2;
      r[mti] = (double)(b_r + u2) * 2.328306436538696E-10;
    }
  } else {
    if (!state_not_empty) {
      memset(&c_state[0], 0, 625U * sizeof(unsigned int));
      b_r = 5489U;
      c_state[0] = 5489U;
      for (mti = 0; mti < 623; mti++) {
        b_r = ((b_r ^ b_r >> 30U) * 1812433253U + mti) + 1U;
        c_state[mti + 1] = b_r;
      }

      c_state[624] = 624U;
      state_not_empty = true;
    }

    for (mti = 0; mti < 1000000; mti++) {
      r[mti] = eml_rand_mt19937ar(c_state);
    }
  }
}

/*
 * File trailer for rand.c
 *
 * [EOF]
 */
