//
//  ballistic.cpp
//  XYZ
//
//  Created by tobin on 12/30/15.
//  Copyright © 2015 tobin. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "ballistic.h"

int sgn(double x)
{
    return(round(x/fabs(x)));
}

double f(double x, double y[], int i)
{
    const double g=9.81;
    if (i==0) return(y[1]);                                      /* derivative of first equation */
    if (i==1) return(-g-sgn(y[1])*Bc*y[1]*y[1]);                   /* derivative of second equation */
    if (i==2) return(y[3]);
    if (i==3) return(-sgn(y[3])*Bc*y[3]*y[3]);
    
    return 0;
}
