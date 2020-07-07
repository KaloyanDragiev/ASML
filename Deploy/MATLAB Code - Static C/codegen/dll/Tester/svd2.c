/*
 * File: svd2.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 14-Feb-2020 16:43:53
 */

/* Include Files */
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "Tester.h"
#include "svd2.h"
#include "xrot.h"
#include "xrotg.h"
#include "sqrt.h"
#include "xswap.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"

/* Function Definitions */

/*
 * Arguments    : const double A[262144]
 *                double U[262144]
 *                double s[512]
 *                double V[262144]
 * Return Type  : void
 */
void b_svd(const double A[262144], double U[262144], double s[512], double V
           [262144])
{
  static double b_A[262144];
  double e[512];
  double work[512];
  int q;
  int m;
  int qp1;
  int iter;
  int qq;
  boolean_T apply_transform;
  double nrm;
  int k;
  int qjj;
  double snorm;
  int qp1jj;
  double r;
  int exitg1;
  boolean_T exitg2;
  double scale;
  double sm;
  double sqds;
  double b;
  memcpy(&b_A[0], &A[0], sizeof(double) << 18);
  memset(&s[0], 0, sizeof(double) << 9);
  memset(&e[0], 0, sizeof(double) << 9);
  memset(&work[0], 0, sizeof(double) << 9);
  memset(&U[0], 0, sizeof(double) << 18);
  memset(&V[0], 0, sizeof(double) << 18);
  for (q = 0; q < 511; q++) {
    qp1 = q + 2;
    iter = q << 9;
    qq = (q + iter) + 1;
    apply_transform = false;
    nrm = c_xnrm2(512 - q, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq - 1] < 0.0) {
        nrm = -nrm;
      }

      s[q] = nrm;
      if (fabs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        qp1jj = (qq - q) + 511;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qp1jj = (qq - q) + 511;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] /= s[q];
        }
      }

      b_A[qq - 1]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }

    for (k = qp1; k < 513; k++) {
      qjj = q + ((k - 1) << 9);
      if (apply_transform) {
        d_xaxpy(512 - q, -(b_xdotc(512 - q, b_A, qq, b_A, qjj + 1) / b_A[q + (q <<
                  9)]), qq, b_A, qjj + 1);
      }

      e[k - 1] = b_A[qjj];
    }

    for (k = q + 1; k < 513; k++) {
      qp1jj = (k + iter) - 1;
      U[qp1jj] = b_A[qp1jj];
    }

    if (q + 1 <= 510) {
      nrm = d_xnrm2(511 - q, e, q + 2);
      if (nrm == 0.0) {
        e[q] = 0.0;
      } else {
        if (e[q + 1] < 0.0) {
          e[q] = -nrm;
        } else {
          e[q] = nrm;
        }

        nrm = e[q];
        if (fabs(e[q]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[q];
          for (k = qp1; k < 513; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 513; k++) {
            e[k - 1] /= nrm;
          }
        }

        e[q + 1]++;
        e[q] = -e[q];
        for (k = qp1; k < 513; k++) {
          work[k - 1] = 0.0;
        }

        for (k = qp1; k < 513; k++) {
          e_xaxpy(511 - q, e[k - 1], b_A, (q + ((k - 1) << 9)) + 2, work, q + 2);
        }

        for (k = qp1; k < 513; k++) {
          f_xaxpy(511 - q, -e[k - 1] / e[q + 1], work, q + 2, b_A, (q + ((k - 1)
                    << 9)) + 2);
        }
      }

      for (k = qp1; k < 513; k++) {
        V[(k + iter) - 1] = e[k - 1];
      }
    }
  }

  m = 510;
  s[511] = b_A[262143];
  e[510] = b_A[262142];
  e[511] = 0.0;
  memset(&U[261632], 0, sizeof(double) << 9);
  U[262143] = 1.0;
  for (q = 510; q >= 0; q--) {
    qp1 = q + 2;
    iter = q << 9;
    qq = q + iter;
    if (s[q] != 0.0) {
      for (k = qp1; k < 513; k++) {
        qjj = (q + ((k - 1) << 9)) + 1;
        d_xaxpy(512 - q, -(b_xdotc(512 - q, U, qq + 1, U, qjj) / U[qq]), qq + 1,
                U, qjj);
      }

      for (k = q + 1; k < 513; k++) {
        qp1jj = (k + iter) - 1;
        U[qp1jj] = -U[qp1jj];
      }

      U[qq]++;
      for (k = 0; k < q; k++) {
        U[k + iter] = 0.0;
      }
    } else {
      memset(&U[q << 9], 0, sizeof(double) << 9);
      U[qq] = 1.0;
    }
  }

  for (q = 511; q >= 0; q--) {
    if ((q + 1 <= 510) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + (q << 9)) + 2;
      for (k = qp1; k < 513; k++) {
        qp1jj = (q + ((k - 1) << 9)) + 2;
        d_xaxpy(511 - q, -(b_xdotc(511 - q, V, qjj, V, qp1jj) / V[qjj - 1]), qjj,
                V, qp1jj);
      }
    }

    memset(&V[q << 9], 0, sizeof(double) << 9);
    V[q + (q << 9)] = 1.0;
  }

  iter = 0;
  snorm = 0.0;
  for (q = 0; q < 512; q++) {
    if (s[q] != 0.0) {
      nrm = fabs(s[q]);
      r = s[q] / nrm;
      s[q] = nrm;
      if (q + 1 < 512) {
        e[q] /= r;
      }

      qjj = q << 9;
      qp1jj = qjj + 512;
      for (k = qjj + 1; k <= qp1jj; k++) {
        U[k - 1] *= r;
      }
    }

    if ((q + 1 < 512) && (e[q] != 0.0)) {
      nrm = fabs(e[q]);
      r = nrm / e[q];
      e[q] = nrm;
      s[q + 1] *= r;
      qjj = (q + 1) << 9;
      qp1jj = qjj + 512;
      for (k = qjj + 1; k <= qp1jj; k++) {
        V[k - 1] *= r;
      }
    }

    nrm = fabs(s[q]);
    r = fabs(e[q]);
    if ((nrm > r) || rtIsNaN(r)) {
      r = nrm;
    }

    if ((!(snorm > r)) && (!rtIsNaN(r))) {
      snorm = r;
    }
  }

  while ((m + 2 > 0) && (iter < 75)) {
    k = m;
    do {
      exitg1 = 0;
      q = k + 1;
      if (k + 1 == 0) {
        exitg1 = 1;
      } else {
        nrm = fabs(e[k]);
        if ((nrm <= 2.2204460492503131E-16 * (fabs(s[k]) + fabs(s[k + 1]))) ||
            (nrm <= 1.0020841800044864E-292) || ((iter > 20) && (nrm <=
              2.2204460492503131E-16 * snorm))) {
          e[k] = 0.0;
          exitg1 = 1;
        } else {
          k--;
        }
      }
    } while (exitg1 == 0);

    if (k + 1 == m + 1) {
      qjj = 4;
    } else {
      qp1jj = m + 2;
      qjj = m + 2;
      exitg2 = false;
      while ((!exitg2) && (qjj >= k + 1)) {
        qp1jj = qjj;
        if (qjj == k + 1) {
          exitg2 = true;
        } else {
          nrm = 0.0;
          if (qjj < m + 2) {
            nrm = fabs(e[qjj - 1]);
          }

          if (qjj > k + 2) {
            nrm += fabs(e[qjj - 2]);
          }

          r = fabs(s[qjj - 1]);
          if ((r <= 2.2204460492503131E-16 * nrm) || (r <=
               1.0020841800044864E-292)) {
            s[qjj - 1] = 0.0;
            exitg2 = true;
          } else {
            qjj--;
          }
        }
      }

      if (qp1jj == k + 1) {
        qjj = 3;
      } else if (qp1jj == m + 2) {
        qjj = 1;
      } else {
        qjj = 2;
        q = qp1jj;
      }
    }

    switch (qjj) {
     case 1:
      r = e[m];
      e[m] = 0.0;
      qp1jj = m + 1;
      for (k = qp1jj; k >= q + 1; k--) {
        xrotg(&s[k - 1], &r, &sm, &sqds);
        if (k > q + 1) {
          b = e[k - 2];
          r = -sqds * b;
          e[k - 2] = b * sm;
        }

        b_xrot(V, 1 + ((k - 1) << 9), 1 + ((m + 1) << 9), sm, sqds);
      }
      break;

     case 2:
      r = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= m + 2; k++) {
        xrotg(&s[k - 1], &r, &sm, &sqds);
        b = e[k - 1];
        r = -sqds * b;
        e[k - 1] = b * sm;
        b_xrot(U, 1 + ((k - 1) << 9), 1 + ((q - 1) << 9), sm, sqds);
      }
      break;

     case 3:
      qjj = m + 1;
      nrm = s[m + 1];
      scale = fabs(nrm);
      r = fabs(s[m]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      r = fabs(e[m]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      r = fabs(s[q]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      r = fabs(e[q]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      sm = nrm / scale;
      nrm = s[m] / scale;
      r = e[m] / scale;
      sqds = s[q] / scale;
      b = ((nrm + sm) * (nrm - sm) + r * r) / 2.0;
      nrm = sm * r;
      nrm *= nrm;
      if ((b != 0.0) || (nrm != 0.0)) {
        r = b * b + nrm;
        b_sqrt(&r);
        if (b < 0.0) {
          r = -r;
        }

        r = nrm / (b + r);
      } else {
        r = 0.0;
      }

      r += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[q] / scale);
      for (k = q + 1; k <= qjj; k++) {
        xrotg(&r, &nrm, &sm, &sqds);
        if (k > q + 1) {
          e[k - 2] = r;
        }

        b = e[k - 1];
        nrm = s[k - 1];
        e[k - 1] = sm * b - sqds * nrm;
        r = sqds * s[k];
        s[k] *= sm;
        b_xrot(V, 1 + ((k - 1) << 9), 1 + (k << 9), sm, sqds);
        s[k - 1] = sm * nrm + sqds * b;
        xrotg(&s[k - 1], &r, &sm, &sqds);
        b = e[k - 1];
        r = sm * b + sqds * s[k];
        s[k] = -sqds * b + sm * s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        b_xrot(U, 1 + ((k - 1) << 9), 1 + (k << 9), sm, sqds);
      }

      e[m] = r;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        qjj = q << 9;
        qp1jj = qjj + 512;
        for (k = qjj + 1; k <= qp1jj; k++) {
          V[k - 1] = -V[k - 1];
        }
      }

      qp1 = q + 1;
      while ((q + 1 < 512) && (s[q] < s[qp1])) {
        nrm = s[q];
        s[q] = s[qp1];
        s[qp1] = nrm;
        b_xswap(V, 1 + (q << 9), 1 + ((q + 1) << 9));
        b_xswap(U, 1 + (q << 9), 1 + ((q + 1) << 9));
        q = qp1;
        qp1++;
      }

      iter = 0;
      m--;
      break;
    }
  }
}

/*
 * Arguments    : const double A[1048576]
 *                double U[1048576]
 *                double s[1024]
 *                double V[1048576]
 * Return Type  : void
 */
void c_svd(const double A[1048576], double U[1048576], double s[1024], double V
           [1048576])
{
  static double b_A[1048576];
  double e[1024];
  double work[1024];
  int q;
  int m;
  int qp1;
  int iter;
  int qq;
  boolean_T apply_transform;
  double nrm;
  int k;
  int qjj;
  double snorm;
  int qp1jj;
  double r;
  int exitg1;
  boolean_T exitg2;
  double scale;
  double sm;
  double sqds;
  double b;
  memcpy(&b_A[0], &A[0], sizeof(double) << 20);
  memset(&s[0], 0, sizeof(double) << 10);
  memset(&e[0], 0, sizeof(double) << 10);
  memset(&work[0], 0, sizeof(double) << 10);
  memset(&U[0], 0, sizeof(double) << 20);
  memset(&V[0], 0, sizeof(double) << 20);
  for (q = 0; q < 1023; q++) {
    qp1 = q + 2;
    iter = q << 10;
    qq = (q + iter) + 1;
    apply_transform = false;
    nrm = e_xnrm2(1024 - q, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq - 1] < 0.0) {
        nrm = -nrm;
      }

      s[q] = nrm;
      if (fabs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        qp1jj = (qq - q) + 1023;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qp1jj = (qq - q) + 1023;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] /= s[q];
        }
      }

      b_A[qq - 1]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }

    for (k = qp1; k < 1025; k++) {
      qjj = q + ((k - 1) << 10);
      if (apply_transform) {
        g_xaxpy(1024 - q, -(c_xdotc(1024 - q, b_A, qq, b_A, qjj + 1) / b_A[q +
                            (q << 10)]), qq, b_A, qjj + 1);
      }

      e[k - 1] = b_A[qjj];
    }

    for (k = q + 1; k < 1025; k++) {
      qp1jj = (k + iter) - 1;
      U[qp1jj] = b_A[qp1jj];
    }

    if (q + 1 <= 1022) {
      nrm = f_xnrm2(1023 - q, e, q + 2);
      if (nrm == 0.0) {
        e[q] = 0.0;
      } else {
        if (e[q + 1] < 0.0) {
          e[q] = -nrm;
        } else {
          e[q] = nrm;
        }

        nrm = e[q];
        if (fabs(e[q]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[q];
          for (k = qp1; k < 1025; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 1025; k++) {
            e[k - 1] /= nrm;
          }
        }

        e[q + 1]++;
        e[q] = -e[q];
        for (k = qp1; k < 1025; k++) {
          work[k - 1] = 0.0;
        }

        for (k = qp1; k < 1025; k++) {
          h_xaxpy(1023 - q, e[k - 1], b_A, (q + ((k - 1) << 10)) + 2, work, q +
                  2);
        }

        for (k = qp1; k < 1025; k++) {
          i_xaxpy(1023 - q, -e[k - 1] / e[q + 1], work, q + 2, b_A, (q + ((k - 1)
                    << 10)) + 2);
        }
      }

      for (k = qp1; k < 1025; k++) {
        V[(k + iter) - 1] = e[k - 1];
      }
    }
  }

  m = 1022;
  s[1023] = b_A[1048575];
  e[1022] = b_A[1048574];
  e[1023] = 0.0;
  memset(&U[1047552], 0, sizeof(double) << 10);
  U[1048575] = 1.0;
  for (q = 1022; q >= 0; q--) {
    qp1 = q + 2;
    iter = q << 10;
    qq = q + iter;
    if (s[q] != 0.0) {
      for (k = qp1; k < 1025; k++) {
        qjj = (q + ((k - 1) << 10)) + 1;
        g_xaxpy(1024 - q, -(c_xdotc(1024 - q, U, qq + 1, U, qjj) / U[qq]), qq +
                1, U, qjj);
      }

      for (k = q + 1; k < 1025; k++) {
        qp1jj = (k + iter) - 1;
        U[qp1jj] = -U[qp1jj];
      }

      U[qq]++;
      for (k = 0; k < q; k++) {
        U[k + iter] = 0.0;
      }
    } else {
      memset(&U[q << 10], 0, sizeof(double) << 10);
      U[qq] = 1.0;
    }
  }

  for (q = 1023; q >= 0; q--) {
    if ((q + 1 <= 1022) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + (q << 10)) + 2;
      for (k = qp1; k < 1025; k++) {
        qp1jj = (q + ((k - 1) << 10)) + 2;
        g_xaxpy(1023 - q, -(c_xdotc(1023 - q, V, qjj, V, qp1jj) / V[qjj - 1]),
                qjj, V, qp1jj);
      }
    }

    memset(&V[q << 10], 0, sizeof(double) << 10);
    V[q + (q << 10)] = 1.0;
  }

  iter = 0;
  snorm = 0.0;
  for (q = 0; q < 1024; q++) {
    if (s[q] != 0.0) {
      nrm = fabs(s[q]);
      r = s[q] / nrm;
      s[q] = nrm;
      if (q + 1 < 1024) {
        e[q] /= r;
      }

      qjj = q << 10;
      qp1jj = qjj + 1024;
      for (k = qjj + 1; k <= qp1jj; k++) {
        U[k - 1] *= r;
      }
    }

    if ((q + 1 < 1024) && (e[q] != 0.0)) {
      nrm = fabs(e[q]);
      r = nrm / e[q];
      e[q] = nrm;
      s[q + 1] *= r;
      qjj = (q + 1) << 10;
      qp1jj = qjj + 1024;
      for (k = qjj + 1; k <= qp1jj; k++) {
        V[k - 1] *= r;
      }
    }

    nrm = fabs(s[q]);
    r = fabs(e[q]);
    if ((nrm > r) || rtIsNaN(r)) {
      r = nrm;
    }

    if ((!(snorm > r)) && (!rtIsNaN(r))) {
      snorm = r;
    }
  }

  while ((m + 2 > 0) && (iter < 75)) {
    k = m;
    do {
      exitg1 = 0;
      q = k + 1;
      if (k + 1 == 0) {
        exitg1 = 1;
      } else {
        nrm = fabs(e[k]);
        if ((nrm <= 2.2204460492503131E-16 * (fabs(s[k]) + fabs(s[k + 1]))) ||
            (nrm <= 1.0020841800044864E-292) || ((iter > 20) && (nrm <=
              2.2204460492503131E-16 * snorm))) {
          e[k] = 0.0;
          exitg1 = 1;
        } else {
          k--;
        }
      }
    } while (exitg1 == 0);

    if (k + 1 == m + 1) {
      qjj = 4;
    } else {
      qp1jj = m + 2;
      qjj = m + 2;
      exitg2 = false;
      while ((!exitg2) && (qjj >= k + 1)) {
        qp1jj = qjj;
        if (qjj == k + 1) {
          exitg2 = true;
        } else {
          nrm = 0.0;
          if (qjj < m + 2) {
            nrm = fabs(e[qjj - 1]);
          }

          if (qjj > k + 2) {
            nrm += fabs(e[qjj - 2]);
          }

          r = fabs(s[qjj - 1]);
          if ((r <= 2.2204460492503131E-16 * nrm) || (r <=
               1.0020841800044864E-292)) {
            s[qjj - 1] = 0.0;
            exitg2 = true;
          } else {
            qjj--;
          }
        }
      }

      if (qp1jj == k + 1) {
        qjj = 3;
      } else if (qp1jj == m + 2) {
        qjj = 1;
      } else {
        qjj = 2;
        q = qp1jj;
      }
    }

    switch (qjj) {
     case 1:
      r = e[m];
      e[m] = 0.0;
      qp1jj = m + 1;
      for (k = qp1jj; k >= q + 1; k--) {
        xrotg(&s[k - 1], &r, &sm, &sqds);
        if (k > q + 1) {
          b = e[k - 2];
          r = -sqds * b;
          e[k - 2] = b * sm;
        }

        c_xrot(V, 1 + ((k - 1) << 10), 1 + ((m + 1) << 10), sm, sqds);
      }
      break;

     case 2:
      r = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= m + 2; k++) {
        xrotg(&s[k - 1], &r, &sm, &sqds);
        b = e[k - 1];
        r = -sqds * b;
        e[k - 1] = b * sm;
        c_xrot(U, 1 + ((k - 1) << 10), 1 + ((q - 1) << 10), sm, sqds);
      }
      break;

     case 3:
      qjj = m + 1;
      nrm = s[m + 1];
      scale = fabs(nrm);
      r = fabs(s[m]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      r = fabs(e[m]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      r = fabs(s[q]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      r = fabs(e[q]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      sm = nrm / scale;
      nrm = s[m] / scale;
      r = e[m] / scale;
      sqds = s[q] / scale;
      b = ((nrm + sm) * (nrm - sm) + r * r) / 2.0;
      nrm = sm * r;
      nrm *= nrm;
      if ((b != 0.0) || (nrm != 0.0)) {
        r = b * b + nrm;
        b_sqrt(&r);
        if (b < 0.0) {
          r = -r;
        }

        r = nrm / (b + r);
      } else {
        r = 0.0;
      }

      r += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[q] / scale);
      for (k = q + 1; k <= qjj; k++) {
        xrotg(&r, &nrm, &sm, &sqds);
        if (k > q + 1) {
          e[k - 2] = r;
        }

        b = e[k - 1];
        nrm = s[k - 1];
        e[k - 1] = sm * b - sqds * nrm;
        r = sqds * s[k];
        s[k] *= sm;
        c_xrot(V, 1 + ((k - 1) << 10), 1 + (k << 10), sm, sqds);
        s[k - 1] = sm * nrm + sqds * b;
        xrotg(&s[k - 1], &r, &sm, &sqds);
        b = e[k - 1];
        r = sm * b + sqds * s[k];
        s[k] = -sqds * b + sm * s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        c_xrot(U, 1 + ((k - 1) << 10), 1 + (k << 10), sm, sqds);
      }

      e[m] = r;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        qjj = q << 10;
        qp1jj = qjj + 1024;
        for (k = qjj + 1; k <= qp1jj; k++) {
          V[k - 1] = -V[k - 1];
        }
      }

      qp1 = q + 1;
      while ((q + 1 < 1024) && (s[q] < s[qp1])) {
        nrm = s[q];
        s[q] = s[qp1];
        s[qp1] = nrm;
        c_xswap(V, 1 + (q << 10), 1 + ((q + 1) << 10));
        c_xswap(U, 1 + (q << 10), 1 + ((q + 1) << 10));
        q = qp1;
        qp1++;
      }

      iter = 0;
      m--;
      break;
    }
  }
}

/*
 * Arguments    : const double A[4194304]
 *                double U[4194304]
 *                double s[2048]
 *                double V[4194304]
 * Return Type  : void
 */
void d_svd(const double A[4194304], double U[4194304], double s[2048], double V
           [4194304])
{
  static double b_A[4194304];
  double e[2048];
  double work[2048];
  int q;
  int m;
  int qp1;
  int iter;
  int qq;
  boolean_T apply_transform;
  double nrm;
  int k;
  int qjj;
  double snorm;
  int qp1jj;
  double r;
  int exitg1;
  boolean_T exitg2;
  double scale;
  double sm;
  double sqds;
  double b;
  memcpy(&b_A[0], &A[0], sizeof(double) << 22);
  memset(&s[0], 0, sizeof(double) << 11);
  memset(&e[0], 0, sizeof(double) << 11);
  memset(&work[0], 0, sizeof(double) << 11);
  memset(&U[0], 0, sizeof(double) << 22);
  memset(&V[0], 0, sizeof(double) << 22);
  for (q = 0; q < 2047; q++) {
    qp1 = q + 2;
    iter = q << 11;
    qq = (q + iter) + 1;
    apply_transform = false;
    nrm = g_xnrm2(2048 - q, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq - 1] < 0.0) {
        nrm = -nrm;
      }

      s[q] = nrm;
      if (fabs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        qp1jj = (qq - q) + 2047;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qp1jj = (qq - q) + 2047;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] /= s[q];
        }
      }

      b_A[qq - 1]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }

    for (k = qp1; k < 2049; k++) {
      qjj = q + ((k - 1) << 11);
      if (apply_transform) {
        j_xaxpy(2048 - q, -(d_xdotc(2048 - q, b_A, qq, b_A, qjj + 1) / b_A[q +
                            (q << 11)]), qq, b_A, qjj + 1);
      }

      e[k - 1] = b_A[qjj];
    }

    for (k = q + 1; k < 2049; k++) {
      qp1jj = (k + iter) - 1;
      U[qp1jj] = b_A[qp1jj];
    }

    if (q + 1 <= 2046) {
      nrm = h_xnrm2(2047 - q, e, q + 2);
      if (nrm == 0.0) {
        e[q] = 0.0;
      } else {
        if (e[q + 1] < 0.0) {
          e[q] = -nrm;
        } else {
          e[q] = nrm;
        }

        nrm = e[q];
        if (fabs(e[q]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[q];
          for (k = qp1; k < 2049; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 2049; k++) {
            e[k - 1] /= nrm;
          }
        }

        e[q + 1]++;
        e[q] = -e[q];
        for (k = qp1; k < 2049; k++) {
          work[k - 1] = 0.0;
        }

        for (k = qp1; k < 2049; k++) {
          k_xaxpy(2047 - q, e[k - 1], b_A, (q + ((k - 1) << 11)) + 2, work, q +
                  2);
        }

        for (k = qp1; k < 2049; k++) {
          l_xaxpy(2047 - q, -e[k - 1] / e[q + 1], work, q + 2, b_A, (q + ((k - 1)
                    << 11)) + 2);
        }
      }

      for (k = qp1; k < 2049; k++) {
        V[(k + iter) - 1] = e[k - 1];
      }
    }
  }

  m = 2046;
  s[2047] = b_A[4194303];
  e[2046] = b_A[4194302];
  e[2047] = 0.0;
  memset(&U[4192256], 0, sizeof(double) << 11);
  U[4194303] = 1.0;
  for (q = 2046; q >= 0; q--) {
    qp1 = q + 2;
    iter = q << 11;
    qq = q + iter;
    if (s[q] != 0.0) {
      for (k = qp1; k < 2049; k++) {
        qjj = (q + ((k - 1) << 11)) + 1;
        j_xaxpy(2048 - q, -(d_xdotc(2048 - q, U, qq + 1, U, qjj) / U[qq]), qq +
                1, U, qjj);
      }

      for (k = q + 1; k < 2049; k++) {
        qp1jj = (k + iter) - 1;
        U[qp1jj] = -U[qp1jj];
      }

      U[qq]++;
      for (k = 0; k < q; k++) {
        U[k + iter] = 0.0;
      }
    } else {
      memset(&U[q << 11], 0, sizeof(double) << 11);
      U[qq] = 1.0;
    }
  }

  for (q = 2047; q >= 0; q--) {
    if ((q + 1 <= 2046) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + (q << 11)) + 2;
      for (k = qp1; k < 2049; k++) {
        qp1jj = (q + ((k - 1) << 11)) + 2;
        j_xaxpy(2047 - q, -(d_xdotc(2047 - q, V, qjj, V, qp1jj) / V[qjj - 1]),
                qjj, V, qp1jj);
      }
    }

    memset(&V[q << 11], 0, sizeof(double) << 11);
    V[q + (q << 11)] = 1.0;
  }

  iter = 0;
  snorm = 0.0;
  for (q = 0; q < 2048; q++) {
    if (s[q] != 0.0) {
      nrm = fabs(s[q]);
      r = s[q] / nrm;
      s[q] = nrm;
      if (q + 1 < 2048) {
        e[q] /= r;
      }

      qjj = q << 11;
      qp1jj = qjj + 2048;
      for (k = qjj + 1; k <= qp1jj; k++) {
        U[k - 1] *= r;
      }
    }

    if ((q + 1 < 2048) && (e[q] != 0.0)) {
      nrm = fabs(e[q]);
      r = nrm / e[q];
      e[q] = nrm;
      s[q + 1] *= r;
      qjj = (q + 1) << 11;
      qp1jj = qjj + 2048;
      for (k = qjj + 1; k <= qp1jj; k++) {
        V[k - 1] *= r;
      }
    }

    nrm = fabs(s[q]);
    r = fabs(e[q]);
    if ((nrm > r) || rtIsNaN(r)) {
      r = nrm;
    }

    if ((!(snorm > r)) && (!rtIsNaN(r))) {
      snorm = r;
    }
  }

  while ((m + 2 > 0) && (iter < 75)) {
    k = m;
    do {
      exitg1 = 0;
      q = k + 1;
      if (k + 1 == 0) {
        exitg1 = 1;
      } else {
        nrm = fabs(e[k]);
        if ((nrm <= 2.2204460492503131E-16 * (fabs(s[k]) + fabs(s[k + 1]))) ||
            (nrm <= 1.0020841800044864E-292) || ((iter > 20) && (nrm <=
              2.2204460492503131E-16 * snorm))) {
          e[k] = 0.0;
          exitg1 = 1;
        } else {
          k--;
        }
      }
    } while (exitg1 == 0);

    if (k + 1 == m + 1) {
      qjj = 4;
    } else {
      qp1jj = m + 2;
      qjj = m + 2;
      exitg2 = false;
      while ((!exitg2) && (qjj >= k + 1)) {
        qp1jj = qjj;
        if (qjj == k + 1) {
          exitg2 = true;
        } else {
          nrm = 0.0;
          if (qjj < m + 2) {
            nrm = fabs(e[qjj - 1]);
          }

          if (qjj > k + 2) {
            nrm += fabs(e[qjj - 2]);
          }

          r = fabs(s[qjj - 1]);
          if ((r <= 2.2204460492503131E-16 * nrm) || (r <=
               1.0020841800044864E-292)) {
            s[qjj - 1] = 0.0;
            exitg2 = true;
          } else {
            qjj--;
          }
        }
      }

      if (qp1jj == k + 1) {
        qjj = 3;
      } else if (qp1jj == m + 2) {
        qjj = 1;
      } else {
        qjj = 2;
        q = qp1jj;
      }
    }

    switch (qjj) {
     case 1:
      r = e[m];
      e[m] = 0.0;
      qp1jj = m + 1;
      for (k = qp1jj; k >= q + 1; k--) {
        xrotg(&s[k - 1], &r, &sm, &sqds);
        if (k > q + 1) {
          b = e[k - 2];
          r = -sqds * b;
          e[k - 2] = b * sm;
        }

        d_xrot(V, 1 + ((k - 1) << 11), 1 + ((m + 1) << 11), sm, sqds);
      }
      break;

     case 2:
      r = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= m + 2; k++) {
        xrotg(&s[k - 1], &r, &sm, &sqds);
        b = e[k - 1];
        r = -sqds * b;
        e[k - 1] = b * sm;
        d_xrot(U, 1 + ((k - 1) << 11), 1 + ((q - 1) << 11), sm, sqds);
      }
      break;

     case 3:
      qjj = m + 1;
      nrm = s[m + 1];
      scale = fabs(nrm);
      r = fabs(s[m]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      r = fabs(e[m]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      r = fabs(s[q]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      r = fabs(e[q]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      sm = nrm / scale;
      nrm = s[m] / scale;
      r = e[m] / scale;
      sqds = s[q] / scale;
      b = ((nrm + sm) * (nrm - sm) + r * r) / 2.0;
      nrm = sm * r;
      nrm *= nrm;
      if ((b != 0.0) || (nrm != 0.0)) {
        r = b * b + nrm;
        b_sqrt(&r);
        if (b < 0.0) {
          r = -r;
        }

        r = nrm / (b + r);
      } else {
        r = 0.0;
      }

      r += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[q] / scale);
      for (k = q + 1; k <= qjj; k++) {
        xrotg(&r, &nrm, &sm, &sqds);
        if (k > q + 1) {
          e[k - 2] = r;
        }

        b = e[k - 1];
        nrm = s[k - 1];
        e[k - 1] = sm * b - sqds * nrm;
        r = sqds * s[k];
        s[k] *= sm;
        d_xrot(V, 1 + ((k - 1) << 11), 1 + (k << 11), sm, sqds);
        s[k - 1] = sm * nrm + sqds * b;
        xrotg(&s[k - 1], &r, &sm, &sqds);
        b = e[k - 1];
        r = sm * b + sqds * s[k];
        s[k] = -sqds * b + sm * s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        d_xrot(U, 1 + ((k - 1) << 11), 1 + (k << 11), sm, sqds);
      }

      e[m] = r;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        qjj = q << 11;
        qp1jj = qjj + 2048;
        for (k = qjj + 1; k <= qp1jj; k++) {
          V[k - 1] = -V[k - 1];
        }
      }

      qp1 = q + 1;
      while ((q + 1 < 2048) && (s[q] < s[qp1])) {
        nrm = s[q];
        s[q] = s[qp1];
        s[qp1] = nrm;
        d_xswap(V, 1 + (q << 11), 1 + ((q + 1) << 11));
        d_xswap(U, 1 + (q << 11), 1 + ((q + 1) << 11));
        q = qp1;
        qp1++;
      }

      iter = 0;
      m--;
      break;
    }
  }
}

/*
 * Arguments    : const double A[16777216]
 *                double U[16777216]
 *                double s[4096]
 *                double V[16777216]
 * Return Type  : void
 */
void e_svd(const double A[16777216], double U[16777216], double s[4096], double
           V[16777216])
{
  static double b_A[16777216];
  double e[4096];
  double work[4096];
  int q;
  int m;
  int qp1;
  int iter;
  int qq;
  boolean_T apply_transform;
  double nrm;
  int k;
  int qjj;
  double snorm;
  int qp1jj;
  double r;
  int exitg1;
  boolean_T exitg2;
  double scale;
  double sm;
  double sqds;
  double b;
  memcpy(&b_A[0], &A[0], sizeof(double) << 24);
  memset(&s[0], 0, sizeof(double) << 12);
  memset(&e[0], 0, sizeof(double) << 12);
  memset(&work[0], 0, sizeof(double) << 12);
  memset(&U[0], 0, sizeof(double) << 24);
  memset(&V[0], 0, sizeof(double) << 24);
  for (q = 0; q < 4095; q++) {
    qp1 = q + 2;
    iter = q << 12;
    qq = (q + iter) + 1;
    apply_transform = false;
    nrm = i_xnrm2(4096 - q, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq - 1] < 0.0) {
        nrm = -nrm;
      }

      s[q] = nrm;
      if (fabs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        qp1jj = (qq - q) + 4095;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qp1jj = (qq - q) + 4095;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] /= s[q];
        }
      }

      b_A[qq - 1]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }

    for (k = qp1; k < 4097; k++) {
      qjj = q + ((k - 1) << 12);
      if (apply_transform) {
        m_xaxpy(4096 - q, -(e_xdotc(4096 - q, b_A, qq, b_A, qjj + 1) / b_A[q +
                            (q << 12)]), qq, b_A, qjj + 1);
      }

      e[k - 1] = b_A[qjj];
    }

    for (k = q + 1; k < 4097; k++) {
      qp1jj = (k + iter) - 1;
      U[qp1jj] = b_A[qp1jj];
    }

    if (q + 1 <= 4094) {
      nrm = j_xnrm2(4095 - q, e, q + 2);
      if (nrm == 0.0) {
        e[q] = 0.0;
      } else {
        if (e[q + 1] < 0.0) {
          e[q] = -nrm;
        } else {
          e[q] = nrm;
        }

        nrm = e[q];
        if (fabs(e[q]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[q];
          for (k = qp1; k < 4097; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 4097; k++) {
            e[k - 1] /= nrm;
          }
        }

        e[q + 1]++;
        e[q] = -e[q];
        for (k = qp1; k < 4097; k++) {
          work[k - 1] = 0.0;
        }

        for (k = qp1; k < 4097; k++) {
          n_xaxpy(4095 - q, e[k - 1], b_A, (q + ((k - 1) << 12)) + 2, work, q +
                  2);
        }

        for (k = qp1; k < 4097; k++) {
          o_xaxpy(4095 - q, -e[k - 1] / e[q + 1], work, q + 2, b_A, (q + ((k - 1)
                    << 12)) + 2);
        }
      }

      for (k = qp1; k < 4097; k++) {
        V[(k + iter) - 1] = e[k - 1];
      }
    }
  }

  m = 4094;
  s[4095] = b_A[16777215];
  e[4094] = b_A[16777214];
  e[4095] = 0.0;
  memset(&U[16773120], 0, sizeof(double) << 12);
  U[16777215] = 1.0;
  for (q = 4094; q >= 0; q--) {
    qp1 = q + 2;
    iter = q << 12;
    qq = q + iter;
    if (s[q] != 0.0) {
      for (k = qp1; k < 4097; k++) {
        qjj = (q + ((k - 1) << 12)) + 1;
        m_xaxpy(4096 - q, -(e_xdotc(4096 - q, U, qq + 1, U, qjj) / U[qq]), qq +
                1, U, qjj);
      }

      for (k = q + 1; k < 4097; k++) {
        qp1jj = (k + iter) - 1;
        U[qp1jj] = -U[qp1jj];
      }

      U[qq]++;
      for (k = 0; k < q; k++) {
        U[k + iter] = 0.0;
      }
    } else {
      memset(&U[q << 12], 0, sizeof(double) << 12);
      U[qq] = 1.0;
    }
  }

  for (q = 4095; q >= 0; q--) {
    if ((q + 1 <= 4094) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + (q << 12)) + 2;
      for (k = qp1; k < 4097; k++) {
        qp1jj = (q + ((k - 1) << 12)) + 2;
        m_xaxpy(4095 - q, -(e_xdotc(4095 - q, V, qjj, V, qp1jj) / V[qjj - 1]),
                qjj, V, qp1jj);
      }
    }

    memset(&V[q << 12], 0, sizeof(double) << 12);
    V[q + (q << 12)] = 1.0;
  }

  iter = 0;
  snorm = 0.0;
  for (q = 0; q < 4096; q++) {
    if (s[q] != 0.0) {
      nrm = fabs(s[q]);
      r = s[q] / nrm;
      s[q] = nrm;
      if (q + 1 < 4096) {
        e[q] /= r;
      }

      qjj = q << 12;
      qp1jj = qjj + 4096;
      for (k = qjj + 1; k <= qp1jj; k++) {
        U[k - 1] *= r;
      }
    }

    if ((q + 1 < 4096) && (e[q] != 0.0)) {
      nrm = fabs(e[q]);
      r = nrm / e[q];
      e[q] = nrm;
      s[q + 1] *= r;
      qjj = (q + 1) << 12;
      qp1jj = qjj + 4096;
      for (k = qjj + 1; k <= qp1jj; k++) {
        V[k - 1] *= r;
      }
    }

    nrm = fabs(s[q]);
    r = fabs(e[q]);
    if ((nrm > r) || rtIsNaN(r)) {
      r = nrm;
    }

    if ((!(snorm > r)) && (!rtIsNaN(r))) {
      snorm = r;
    }
  }

  while ((m + 2 > 0) && (iter < 75)) {
    k = m;
    do {
      exitg1 = 0;
      q = k + 1;
      if (k + 1 == 0) {
        exitg1 = 1;
      } else {
        nrm = fabs(e[k]);
        if ((nrm <= 2.2204460492503131E-16 * (fabs(s[k]) + fabs(s[k + 1]))) ||
            (nrm <= 1.0020841800044864E-292) || ((iter > 20) && (nrm <=
              2.2204460492503131E-16 * snorm))) {
          e[k] = 0.0;
          exitg1 = 1;
        } else {
          k--;
        }
      }
    } while (exitg1 == 0);

    if (k + 1 == m + 1) {
      qjj = 4;
    } else {
      qp1jj = m + 2;
      qjj = m + 2;
      exitg2 = false;
      while ((!exitg2) && (qjj >= k + 1)) {
        qp1jj = qjj;
        if (qjj == k + 1) {
          exitg2 = true;
        } else {
          nrm = 0.0;
          if (qjj < m + 2) {
            nrm = fabs(e[qjj - 1]);
          }

          if (qjj > k + 2) {
            nrm += fabs(e[qjj - 2]);
          }

          r = fabs(s[qjj - 1]);
          if ((r <= 2.2204460492503131E-16 * nrm) || (r <=
               1.0020841800044864E-292)) {
            s[qjj - 1] = 0.0;
            exitg2 = true;
          } else {
            qjj--;
          }
        }
      }

      if (qp1jj == k + 1) {
        qjj = 3;
      } else if (qp1jj == m + 2) {
        qjj = 1;
      } else {
        qjj = 2;
        q = qp1jj;
      }
    }

    switch (qjj) {
     case 1:
      r = e[m];
      e[m] = 0.0;
      qp1jj = m + 1;
      for (k = qp1jj; k >= q + 1; k--) {
        xrotg(&s[k - 1], &r, &sm, &sqds);
        if (k > q + 1) {
          b = e[k - 2];
          r = -sqds * b;
          e[k - 2] = b * sm;
        }

        e_xrot(V, 1 + ((k - 1) << 12), 1 + ((m + 1) << 12), sm, sqds);
      }
      break;

     case 2:
      r = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= m + 2; k++) {
        xrotg(&s[k - 1], &r, &sm, &sqds);
        b = e[k - 1];
        r = -sqds * b;
        e[k - 1] = b * sm;
        e_xrot(U, 1 + ((k - 1) << 12), 1 + ((q - 1) << 12), sm, sqds);
      }
      break;

     case 3:
      qjj = m + 1;
      nrm = s[m + 1];
      scale = fabs(nrm);
      r = fabs(s[m]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      r = fabs(e[m]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      r = fabs(s[q]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      r = fabs(e[q]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      sm = nrm / scale;
      nrm = s[m] / scale;
      r = e[m] / scale;
      sqds = s[q] / scale;
      b = ((nrm + sm) * (nrm - sm) + r * r) / 2.0;
      nrm = sm * r;
      nrm *= nrm;
      if ((b != 0.0) || (nrm != 0.0)) {
        r = b * b + nrm;
        b_sqrt(&r);
        if (b < 0.0) {
          r = -r;
        }

        r = nrm / (b + r);
      } else {
        r = 0.0;
      }

      r += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[q] / scale);
      for (k = q + 1; k <= qjj; k++) {
        xrotg(&r, &nrm, &sm, &sqds);
        if (k > q + 1) {
          e[k - 2] = r;
        }

        b = e[k - 1];
        nrm = s[k - 1];
        e[k - 1] = sm * b - sqds * nrm;
        r = sqds * s[k];
        s[k] *= sm;
        e_xrot(V, 1 + ((k - 1) << 12), 1 + (k << 12), sm, sqds);
        s[k - 1] = sm * nrm + sqds * b;
        xrotg(&s[k - 1], &r, &sm, &sqds);
        b = e[k - 1];
        r = sm * b + sqds * s[k];
        s[k] = -sqds * b + sm * s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        e_xrot(U, 1 + ((k - 1) << 12), 1 + (k << 12), sm, sqds);
      }

      e[m] = r;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        qjj = q << 12;
        qp1jj = qjj + 4096;
        for (k = qjj + 1; k <= qp1jj; k++) {
          V[k - 1] = -V[k - 1];
        }
      }

      qp1 = q + 1;
      while ((q + 1 < 4096) && (s[q] < s[qp1])) {
        nrm = s[q];
        s[q] = s[qp1];
        s[qp1] = nrm;
        e_xswap(V, 1 + (q << 12), 1 + ((q + 1) << 12));
        e_xswap(U, 1 + (q << 12), 1 + ((q + 1) << 12));
        q = qp1;
        qp1++;
      }

      iter = 0;
      m--;
      break;
    }
  }
}

/*
 * Arguments    : const double A[65536]
 *                double U[65536]
 *                double s[256]
 *                double V[65536]
 * Return Type  : void
 */
void svd(const double A[65536], double U[65536], double s[256], double V[65536])
{
  static double b_A[65536];
  double e[256];
  double work[256];
  int q;
  int m;
  int qp1;
  int iter;
  int qq;
  boolean_T apply_transform;
  double nrm;
  int k;
  int qjj;
  double snorm;
  int qp1jj;
  double r;
  int exitg1;
  boolean_T exitg2;
  double scale;
  double sm;
  double sqds;
  double b;
  memcpy(&b_A[0], &A[0], sizeof(double) << 16);
  memset(&s[0], 0, sizeof(double) << 8);
  memset(&e[0], 0, sizeof(double) << 8);
  memset(&work[0], 0, sizeof(double) << 8);
  memset(&U[0], 0, sizeof(double) << 16);
  memset(&V[0], 0, sizeof(double) << 16);
  for (q = 0; q < 255; q++) {
    qp1 = q + 2;
    iter = q << 8;
    qq = (q + iter) + 1;
    apply_transform = false;
    nrm = xnrm2(256 - q, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq - 1] < 0.0) {
        nrm = -nrm;
      }

      s[q] = nrm;
      if (fabs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        qp1jj = (qq - q) + 255;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qp1jj = (qq - q) + 255;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] /= s[q];
        }
      }

      b_A[qq - 1]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }

    for (k = qp1; k < 257; k++) {
      qjj = q + ((k - 1) << 8);
      if (apply_transform) {
        xaxpy(256 - q, -(xdotc(256 - q, b_A, qq, b_A, qjj + 1) / b_A[q + (q << 8)]),
              qq, b_A, qjj + 1);
      }

      e[k - 1] = b_A[qjj];
    }

    for (k = q + 1; k < 257; k++) {
      qp1jj = (k + iter) - 1;
      U[qp1jj] = b_A[qp1jj];
    }

    if (q + 1 <= 254) {
      nrm = b_xnrm2(255 - q, e, q + 2);
      if (nrm == 0.0) {
        e[q] = 0.0;
      } else {
        if (e[q + 1] < 0.0) {
          e[q] = -nrm;
        } else {
          e[q] = nrm;
        }

        nrm = e[q];
        if (fabs(e[q]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[q];
          for (k = qp1; k < 257; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 257; k++) {
            e[k - 1] /= nrm;
          }
        }

        e[q + 1]++;
        e[q] = -e[q];
        for (k = qp1; k < 257; k++) {
          work[k - 1] = 0.0;
        }

        for (k = qp1; k < 257; k++) {
          b_xaxpy(255 - q, e[k - 1], b_A, (q + ((k - 1) << 8)) + 2, work, q + 2);
        }

        for (k = qp1; k < 257; k++) {
          c_xaxpy(255 - q, -e[k - 1] / e[q + 1], work, q + 2, b_A, (q + ((k - 1)
                    << 8)) + 2);
        }
      }

      for (k = qp1; k < 257; k++) {
        V[(k + iter) - 1] = e[k - 1];
      }
    }
  }

  m = 254;
  s[255] = b_A[65535];
  e[254] = b_A[65534];
  e[255] = 0.0;
  memset(&U[65280], 0, sizeof(double) << 8);
  U[65535] = 1.0;
  for (q = 254; q >= 0; q--) {
    qp1 = q + 2;
    iter = q << 8;
    qq = q + iter;
    if (s[q] != 0.0) {
      for (k = qp1; k < 257; k++) {
        qjj = (q + ((k - 1) << 8)) + 1;
        xaxpy(256 - q, -(xdotc(256 - q, U, qq + 1, U, qjj) / U[qq]), qq + 1, U,
              qjj);
      }

      for (k = q + 1; k < 257; k++) {
        qp1jj = (k + iter) - 1;
        U[qp1jj] = -U[qp1jj];
      }

      U[qq]++;
      for (k = 0; k < q; k++) {
        U[k + iter] = 0.0;
      }
    } else {
      memset(&U[q << 8], 0, sizeof(double) << 8);
      U[qq] = 1.0;
    }
  }

  for (q = 255; q >= 0; q--) {
    if ((q + 1 <= 254) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + (q << 8)) + 2;
      for (k = qp1; k < 257; k++) {
        qp1jj = (q + ((k - 1) << 8)) + 2;
        xaxpy(255 - q, -(xdotc(255 - q, V, qjj, V, qp1jj) / V[qjj - 1]), qjj, V,
              qp1jj);
      }
    }

    memset(&V[q << 8], 0, sizeof(double) << 8);
    V[q + (q << 8)] = 1.0;
  }

  iter = 0;
  snorm = 0.0;
  for (q = 0; q < 256; q++) {
    if (s[q] != 0.0) {
      nrm = fabs(s[q]);
      r = s[q] / nrm;
      s[q] = nrm;
      if (q + 1 < 256) {
        e[q] /= r;
      }

      qjj = q << 8;
      qp1jj = qjj + 256;
      for (k = qjj + 1; k <= qp1jj; k++) {
        U[k - 1] *= r;
      }
    }

    if ((q + 1 < 256) && (e[q] != 0.0)) {
      nrm = fabs(e[q]);
      r = nrm / e[q];
      e[q] = nrm;
      s[q + 1] *= r;
      qjj = (q + 1) << 8;
      qp1jj = qjj + 256;
      for (k = qjj + 1; k <= qp1jj; k++) {
        V[k - 1] *= r;
      }
    }

    nrm = fabs(s[q]);
    r = fabs(e[q]);
    if ((nrm > r) || rtIsNaN(r)) {
      r = nrm;
    }

    if ((!(snorm > r)) && (!rtIsNaN(r))) {
      snorm = r;
    }
  }

  while ((m + 2 > 0) && (iter < 75)) {
    k = m;
    do {
      exitg1 = 0;
      q = k + 1;
      if (k + 1 == 0) {
        exitg1 = 1;
      } else {
        nrm = fabs(e[k]);
        if ((nrm <= 2.2204460492503131E-16 * (fabs(s[k]) + fabs(s[k + 1]))) ||
            (nrm <= 1.0020841800044864E-292) || ((iter > 20) && (nrm <=
              2.2204460492503131E-16 * snorm))) {
          e[k] = 0.0;
          exitg1 = 1;
        } else {
          k--;
        }
      }
    } while (exitg1 == 0);

    if (k + 1 == m + 1) {
      qjj = 4;
    } else {
      qp1jj = m + 2;
      qjj = m + 2;
      exitg2 = false;
      while ((!exitg2) && (qjj >= k + 1)) {
        qp1jj = qjj;
        if (qjj == k + 1) {
          exitg2 = true;
        } else {
          nrm = 0.0;
          if (qjj < m + 2) {
            nrm = fabs(e[qjj - 1]);
          }

          if (qjj > k + 2) {
            nrm += fabs(e[qjj - 2]);
          }

          r = fabs(s[qjj - 1]);
          if ((r <= 2.2204460492503131E-16 * nrm) || (r <=
               1.0020841800044864E-292)) {
            s[qjj - 1] = 0.0;
            exitg2 = true;
          } else {
            qjj--;
          }
        }
      }

      if (qp1jj == k + 1) {
        qjj = 3;
      } else if (qp1jj == m + 2) {
        qjj = 1;
      } else {
        qjj = 2;
        q = qp1jj;
      }
    }

    switch (qjj) {
     case 1:
      r = e[m];
      e[m] = 0.0;
      qp1jj = m + 1;
      for (k = qp1jj; k >= q + 1; k--) {
        xrotg(&s[k - 1], &r, &sm, &sqds);
        if (k > q + 1) {
          b = e[k - 2];
          r = -sqds * b;
          e[k - 2] = b * sm;
        }

        xrot(V, 1 + ((k - 1) << 8), 1 + ((m + 1) << 8), sm, sqds);
      }
      break;

     case 2:
      r = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= m + 2; k++) {
        xrotg(&s[k - 1], &r, &sm, &sqds);
        b = e[k - 1];
        r = -sqds * b;
        e[k - 1] = b * sm;
        xrot(U, 1 + ((k - 1) << 8), 1 + ((q - 1) << 8), sm, sqds);
      }
      break;

     case 3:
      qjj = m + 1;
      nrm = s[m + 1];
      scale = fabs(nrm);
      r = fabs(s[m]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      r = fabs(e[m]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      r = fabs(s[q]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      r = fabs(e[q]);
      if ((!(scale > r)) && (!rtIsNaN(r))) {
        scale = r;
      }

      sm = nrm / scale;
      nrm = s[m] / scale;
      r = e[m] / scale;
      sqds = s[q] / scale;
      b = ((nrm + sm) * (nrm - sm) + r * r) / 2.0;
      nrm = sm * r;
      nrm *= nrm;
      if ((b != 0.0) || (nrm != 0.0)) {
        r = b * b + nrm;
        b_sqrt(&r);
        if (b < 0.0) {
          r = -r;
        }

        r = nrm / (b + r);
      } else {
        r = 0.0;
      }

      r += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[q] / scale);
      for (k = q + 1; k <= qjj; k++) {
        xrotg(&r, &nrm, &sm, &sqds);
        if (k > q + 1) {
          e[k - 2] = r;
        }

        b = e[k - 1];
        nrm = s[k - 1];
        e[k - 1] = sm * b - sqds * nrm;
        r = sqds * s[k];
        s[k] *= sm;
        xrot(V, 1 + ((k - 1) << 8), 1 + (k << 8), sm, sqds);
        s[k - 1] = sm * nrm + sqds * b;
        xrotg(&s[k - 1], &r, &sm, &sqds);
        b = e[k - 1];
        r = sm * b + sqds * s[k];
        s[k] = -sqds * b + sm * s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        xrot(U, 1 + ((k - 1) << 8), 1 + (k << 8), sm, sqds);
      }

      e[m] = r;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        qjj = q << 8;
        qp1jj = qjj + 256;
        for (k = qjj + 1; k <= qp1jj; k++) {
          V[k - 1] = -V[k - 1];
        }
      }

      qp1 = q + 1;
      while ((q + 1 < 256) && (s[q] < s[qp1])) {
        nrm = s[q];
        s[q] = s[qp1];
        s[qp1] = nrm;
        xswap(V, 1 + (q << 8), 1 + ((q + 1) << 8));
        xswap(U, 1 + (q << 8), 1 + ((q + 1) << 8));
        q = qp1;
        qp1++;
      }

      iter = 0;
      m--;
      break;
    }
  }
}

/*
 * File trailer for svd2.c
 *
 * [EOF]
 */
