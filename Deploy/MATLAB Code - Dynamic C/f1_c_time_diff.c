#include "f1_c_time_diff.h"
#include "PLXA/PLXA.h"

unsigned long time_diff_msec(unsigned long t0)
{
    unsigned long t1;

    PLXAtimeinterval_elapsed(t0, &t1);

    return t1;
    
}
