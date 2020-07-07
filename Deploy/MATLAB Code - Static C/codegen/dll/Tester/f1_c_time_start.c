#include "f1_c_time_start.h"
#include "PLXA/PLXA.h"

unsigned long time_start_msec()
{
    unsigned long t0;

    PLXAtimeinterval_start(&t0);

    return t0;
    
}
