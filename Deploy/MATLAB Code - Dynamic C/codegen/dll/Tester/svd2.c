/*
 * File: svd2.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 18-Feb-2020 14:45:17
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "Tester.h"
#include "svd2.h"
#include "Tester_emxutil.h"
#include "xrot.h"
#include "xrotg.h"
#include "sqrt.h"
#include "xswap.h"
#include "xscal.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *A
 *                emxArray_real_T *U
 *                emxArray_real_T *s
 *                emxArray_real_T *V
 * Return Type  : void
 */
void svd(const emxArray_real_T *A, emxArray_real_T *U, emxArray_real_T *s,
         emxArray_real_T *V)
{
  emxArray_real_T *b_A;
  int m;
  int nmq;
  int n;
  int p;
  int ns;
  int minnp;
  emxArray_real_T *b_s;
  emxArray_real_T *e;
  emxArray_real_T *work;
  int ii;
  int nrt;
  int nct;
  int nctp1;
  int k;
  int q;
  int qp1;
  int qq;
  boolean_T apply_transform;
  double nrm;
  int qjj;
  double rt;
  double snorm;
  boolean_T exitg1;
  double f;
  double scale;
  double b;
  double sqds;
  emxInit_real_T(&b_A, 2);
  m = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  emxEnsureCapacity_real_T(b_A, m);
  nmq = A->size[0] * A->size[1];
  for (m = 0; m < nmq; m++) {
    b_A->data[m] = A->data[m];
  }

  n = A->size[0];
  p = A->size[1];
  nmq = A->size[0] + 1;
  ns = A->size[1];
  if (nmq < ns) {
    ns = nmq;
  }

  nmq = A->size[0];
  minnp = A->size[1];
  if (nmq < minnp) {
    minnp = nmq;
  }

  emxInit_real_T(&b_s, 1);
  m = b_s->size[0];
  b_s->size[0] = ns;
  emxEnsureCapacity_real_T(b_s, m);
  for (m = 0; m < ns; m++) {
    b_s->data[m] = 0.0;
  }

  emxInit_real_T(&e, 1);
  nmq = A->size[1];
  m = e->size[0];
  e->size[0] = nmq;
  emxEnsureCapacity_real_T(e, m);
  for (m = 0; m < nmq; m++) {
    e->data[m] = 0.0;
  }

  emxInit_real_T(&work, 1);
  nmq = A->size[0];
  m = work->size[0];
  work->size[0] = nmq;
  emxEnsureCapacity_real_T(work, m);
  for (m = 0; m < nmq; m++) {
    work->data[m] = 0.0;
  }

  nmq = A->size[0];
  ns = A->size[0];
  m = U->size[0] * U->size[1];
  U->size[0] = nmq;
  U->size[1] = ns;
  emxEnsureCapacity_real_T(U, m);
  nmq *= ns;
  for (m = 0; m < nmq; m++) {
    U->data[m] = 0.0;
  }

  nmq = A->size[1];
  ns = A->size[1];
  m = V->size[0] * V->size[1];
  V->size[0] = nmq;
  V->size[1] = ns;
  emxEnsureCapacity_real_T(V, m);
  nmq *= ns;
  for (m = 0; m < nmq; m++) {
    V->data[m] = 0.0;
  }

  if ((A->size[0] == 0) || (A->size[1] == 0)) {
    m = A->size[0];
    for (ii = 0; ii < m; ii++) {
      U->data[ii + U->size[0] * ii] = 1.0;
    }

    m = A->size[1];
    for (ii = 0; ii < m; ii++) {
      V->data[ii + V->size[0] * ii] = 1.0;
    }
  } else {
    if (A->size[1] > 2) {
      nmq = A->size[1] - 2;
    } else {
      nmq = 0;
    }

    nrt = A->size[0];
    if (nmq < nrt) {
      nrt = nmq;
    }

    if (A->size[0] > 1) {
      nmq = A->size[0] - 1;
    } else {
      nmq = 0;
    }

    nct = A->size[1];
    if (nmq < nct) {
      nct = nmq;
    }

    nctp1 = nct + 1;
    if (nct > nrt) {
      m = nct;
    } else {
      m = nrt;
    }

    for (q = 0; q < m; q++) {
      qp1 = q + 2;
      qq = q + n * q;
      nmq = n - q;
      apply_transform = false;
      if (q + 1 <= nct) {
        nrm = xnrm2(nmq, b_A, qq + 1);
        if (nrm > 0.0) {
          apply_transform = true;
          if (b_A->data[qq] < 0.0) {
            b_s->data[q] = -nrm;
          } else {
            b_s->data[q] = nrm;
          }

          if (fabs(b_s->data[q]) >= 1.0020841800044864E-292) {
            xscal(nmq, 1.0 / b_s->data[q], b_A, qq + 1);
          } else {
            ns = qq + nmq;
            for (k = qq + 1; k <= ns; k++) {
              b_A->data[k - 1] /= b_s->data[q];
            }
          }

          b_A->data[qq]++;
          b_s->data[q] = -b_s->data[q];
        } else {
          b_s->data[q] = 0.0;
        }
      }

      for (k = qp1; k <= p; k++) {
        qjj = q + n * (k - 1);
        if (apply_transform) {
          nrm = -(xdotc(nmq, b_A, qq + 1, b_A, qjj + 1) / b_A->data[q +
                  b_A->size[0] * q]);
          xaxpy(nmq, nrm, qq + 1, b_A, qjj + 1);
        }

        e->data[k - 1] = b_A->data[qjj];
      }

      if (q + 1 <= nct) {
        for (ii = q + 1; ii <= n; ii++) {
          U->data[(ii + U->size[0] * q) - 1] = b_A->data[(ii + b_A->size[0] * q)
            - 1];
        }
      }

      if (q + 1 <= nrt) {
        qq = p - q;
        nrm = xnrm2(qq - 1, e, q + 2);
        if (nrm == 0.0) {
          e->data[q] = 0.0;
        } else {
          if (e->data[q + 1] < 0.0) {
            e->data[q] = -nrm;
          } else {
            e->data[q] = nrm;
          }

          nrm = e->data[q];
          if (fabs(e->data[q]) >= 1.0020841800044864E-292) {
            nrm = 1.0 / e->data[q];
            ns = q + qq;
            for (k = qp1; k <= ns; k++) {
              e->data[k - 1] *= nrm;
            }
          } else {
            ns = q + qq;
            for (k = qp1; k <= ns; k++) {
              e->data[k - 1] /= nrm;
            }
          }

          e->data[q + 1]++;
          e->data[q] = -e->data[q];
          if (q + 2 <= n) {
            for (ii = qp1; ii <= n; ii++) {
              work->data[ii - 1] = 0.0;
            }

            for (k = qp1; k <= p; k++) {
              b_xaxpy(nmq - 1, e->data[k - 1], b_A, (q + n * (k - 1)) + 2, work,
                      q + 2);
            }

            for (k = qp1; k <= p; k++) {
              b_xaxpy(nmq - 1, -e->data[k - 1] / e->data[q + 1], work, q + 2,
                      b_A, (q + n * (k - 1)) + 2);
            }
          }
        }

        for (ii = qp1; ii <= p; ii++) {
          V->data[(ii + V->size[0] * q) - 1] = e->data[ii - 1];
        }
      }
    }

    if (A->size[1] < A->size[0] + 1) {
      m = A->size[1] - 1;
    } else {
      m = A->size[0];
    }

    if (nct < A->size[1]) {
      b_s->data[nct] = b_A->data[nct + b_A->size[0] * nct];
    }

    if (A->size[0] < m + 1) {
      b_s->data[m] = 0.0;
    }

    if (nrt + 1 < m + 1) {
      e->data[nrt] = b_A->data[nrt + b_A->size[0] * m];
    }

    e->data[m] = 0.0;
    if (nct + 1 <= A->size[0]) {
      for (k = nctp1; k <= n; k++) {
        for (ii = 0; ii < n; ii++) {
          U->data[ii + U->size[0] * (k - 1)] = 0.0;
        }

        U->data[(k + U->size[0] * (k - 1)) - 1] = 1.0;
      }
    }

    for (q = nct; q >= 1; q--) {
      qp1 = q + 1;
      ns = n - q;
      nmq = ns + 1;
      qq = (q + n * (q - 1)) - 1;
      if (b_s->data[q - 1] != 0.0) {
        for (k = qp1; k <= n; k++) {
          qjj = q + n * (k - 1);
          nrm = -(xdotc(nmq, U, qq + 1, U, qjj) / U->data[qq]);
          xaxpy(ns + 1, nrm, qq + 1, U, qjj);
        }

        for (ii = q; ii <= n; ii++) {
          U->data[(ii + U->size[0] * (q - 1)) - 1] = -U->data[(ii + U->size[0] *
            (q - 1)) - 1];
        }

        U->data[qq]++;
        for (ii = 0; ii <= q - 2; ii++) {
          U->data[ii + U->size[0] * (q - 1)] = 0.0;
        }
      } else {
        for (ii = 0; ii < n; ii++) {
          U->data[ii + U->size[0] * (q - 1)] = 0.0;
        }

        U->data[qq] = 1.0;
      }
    }

    for (q = p; q >= 1; q--) {
      if ((q <= nrt) && (e->data[q - 1] != 0.0)) {
        qp1 = q + 1;
        qq = p - q;
        ns = (q + p * (q - 1)) + 1;
        for (k = qp1; k <= p; k++) {
          nmq = (q + p * (k - 1)) + 1;
          nrm = -(xdotc(qq, V, ns, V, nmq) / V->data[ns - 1]);
          xaxpy(qq, nrm, ns, V, nmq);
        }
      }

      for (ii = 0; ii < p; ii++) {
        V->data[ii + V->size[0] * (q - 1)] = 0.0;
      }

      V->data[(q + V->size[0] * (q - 1)) - 1] = 1.0;
    }

    for (q = 0; q <= m; q++) {
      if (b_s->data[q] != 0.0) {
        rt = fabs(b_s->data[q]);
        nrm = b_s->data[q] / rt;
        b_s->data[q] = rt;
        if (q + 1 < m + 1) {
          e->data[q] /= nrm;
        }

        if (q + 1 <= n) {
          xscal(n, nrm, U, 1 + n * q);
        }
      }

      if ((q + 1 < m + 1) && (e->data[q] != 0.0)) {
        rt = fabs(e->data[q]);
        nrm = rt / e->data[q];
        e->data[q] = rt;
        b_s->data[q + 1] *= nrm;
        xscal(p, nrm, V, 1 + p * (q + 1));
      }
    }

    qjj = m;
    qq = 0;
    snorm = 0.0;
    for (ii = 0; ii <= m; ii++) {
      nrm = fabs(b_s->data[ii]);
      rt = fabs(e->data[ii]);
      if ((nrm > rt) || rtIsNaN(rt)) {
        rt = nrm;
      }

      if ((!(snorm > rt)) && (!rtIsNaN(rt))) {
        snorm = rt;
      }
    }

    while ((m + 1 > 0) && (qq < 75)) {
      ii = m;
      exitg1 = false;
      while (!(exitg1 || (ii == 0))) {
        nrm = fabs(e->data[ii - 1]);
        if ((nrm <= 2.2204460492503131E-16 * (fabs(b_s->data[ii - 1]) + fabs
              (b_s->data[ii]))) || (nrm <= 1.0020841800044864E-292) || ((qq > 20)
             && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e->data[ii - 1] = 0.0;
          exitg1 = true;
        } else {
          ii--;
        }
      }

      if (ii == m) {
        nmq = 4;
      } else {
        ns = m + 1;
        nmq = m + 1;
        exitg1 = false;
        while ((!exitg1) && (nmq >= ii)) {
          ns = nmq;
          if (nmq == ii) {
            exitg1 = true;
          } else {
            nrm = 0.0;
            if (nmq < m + 1) {
              nrm = fabs(e->data[nmq - 1]);
            }

            if (nmq > ii + 1) {
              nrm += fabs(e->data[nmq - 2]);
            }

            rt = fabs(b_s->data[nmq - 1]);
            if ((rt <= 2.2204460492503131E-16 * nrm) || (rt <=
                 1.0020841800044864E-292)) {
              b_s->data[nmq - 1] = 0.0;
              exitg1 = true;
            } else {
              nmq--;
            }
          }
        }

        if (ns == ii) {
          nmq = 3;
        } else if (ns == m + 1) {
          nmq = 1;
        } else {
          nmq = 2;
          ii = ns;
        }
      }

      switch (nmq) {
       case 1:
        f = e->data[m - 1];
        e->data[m - 1] = 0.0;
        for (k = m; k >= ii + 1; k--) {
          xrotg(&b_s->data[k - 1], &f, &rt, &b);
          if (k > ii + 1) {
            f = -b * e->data[k - 2];
            e->data[k - 2] *= rt;
          }

          xrot(p, V, 1 + p * (k - 1), 1 + p * m, rt, b);
        }
        break;

       case 2:
        f = e->data[ii - 1];
        e->data[ii - 1] = 0.0;
        for (k = ii + 1; k <= m + 1; k++) {
          xrotg(&b_s->data[k - 1], &f, &rt, &b);
          f = -b * e->data[k - 1];
          e->data[k - 1] *= rt;
          xrot(n, U, 1 + n * (k - 1), 1 + n * (ii - 1), rt, b);
        }
        break;

       case 3:
        scale = fabs(b_s->data[m]);
        rt = fabs(b_s->data[m - 1]);
        if ((!(scale > rt)) && (!rtIsNaN(rt))) {
          scale = rt;
        }

        rt = fabs(e->data[m - 1]);
        if ((!(scale > rt)) && (!rtIsNaN(rt))) {
          scale = rt;
        }

        rt = fabs(b_s->data[ii]);
        if ((!(scale > rt)) && (!rtIsNaN(rt))) {
          scale = rt;
        }

        rt = fabs(e->data[ii]);
        if ((!(scale > rt)) && (!rtIsNaN(rt))) {
          scale = rt;
        }

        f = b_s->data[m] / scale;
        nrm = b_s->data[m - 1] / scale;
        rt = e->data[m - 1] / scale;
        sqds = b_s->data[ii] / scale;
        b = ((nrm + f) * (nrm - f) + rt * rt) / 2.0;
        nrm = f * rt;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          rt = b * b + nrm;
          b_sqrt(&rt);
          if (b < 0.0) {
            rt = -rt;
          }

          rt = nrm / (b + rt);
        } else {
          rt = 0.0;
        }

        f = (sqds + f) * (sqds - f) + rt;
        nrm = sqds * (e->data[ii] / scale);
        for (k = ii + 1; k <= m; k++) {
          xrotg(&f, &nrm, &rt, &b);
          if (k > ii + 1) {
            e->data[k - 2] = f;
          }

          f = rt * b_s->data[k - 1] + b * e->data[k - 1];
          e->data[k - 1] = rt * e->data[k - 1] - b * b_s->data[k - 1];
          nrm = b * b_s->data[k];
          b_s->data[k] *= rt;
          xrot(p, V, 1 + p * (k - 1), 1 + p * k, rt, b);
          b_s->data[k - 1] = f;
          xrotg(&b_s->data[k - 1], &nrm, &rt, &b);
          f = rt * e->data[k - 1] + b * b_s->data[k];
          b_s->data[k] = -b * e->data[k - 1] + rt * b_s->data[k];
          nrm = b * e->data[k];
          e->data[k] *= rt;
          if (k < n) {
            xrot(n, U, 1 + n * (k - 1), 1 + n * k, rt, b);
          }
        }

        e->data[m - 1] = f;
        qq++;
        break;

       default:
        if (b_s->data[ii] < 0.0) {
          b_s->data[ii] = -b_s->data[ii];
          xscal(p, -1.0, V, 1 + p * ii);
        }

        qp1 = ii + 1;
        while ((ii + 1 < qjj + 1) && (b_s->data[ii] < b_s->data[qp1])) {
          rt = b_s->data[ii];
          b_s->data[ii] = b_s->data[qp1];
          b_s->data[qp1] = rt;
          if (ii + 1 < p) {
            xswap(p, V, 1 + p * ii, 1 + p * (ii + 1));
          }

          if (ii + 1 < n) {
            xswap(n, U, 1 + n * ii, 1 + n * (ii + 1));
          }

          ii = qp1;
          qp1++;
        }

        qq = 0;
        m--;
        break;
      }
    }
  }

  emxFree_real_T(&work);
  emxFree_real_T(&e);
  emxFree_real_T(&b_A);
  m = s->size[0];
  s->size[0] = minnp;
  emxEnsureCapacity_real_T(s, m);
  for (k = 0; k < minnp; k++) {
    s->data[k] = b_s->data[k];
  }

  emxFree_real_T(&b_s);
}

/*
 * File trailer for svd2.c
 *
 * [EOF]
 */
