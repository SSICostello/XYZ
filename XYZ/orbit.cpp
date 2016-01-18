//
//  orbit.cpp
//  XYZ
//
//  Created by tobin on 12/30/15.
//  Copyright © 2015 tobin. All rights reserved.
//

#include "orbit.hpp"
#include "init.hpp"
#include <math.h>
#include <Eigen/Dense>
using namespace Eigen;


double f(double x, double y[], int i)
{
    
    Vector3d R(y[0],y[1],y[2]), RUnit;
    double RMag = R.norm();
    double RMag3 = pow(RMag,3);
    RUnit = R/RMag;
    if (i==0) return(y[3]);
    if (i==1) return(y[4]);
    if (i==2) return(y[5]);
    if (i==3) return(-Mu/RMag3*y[0]+Tm*RUnit[0]);
    if (i==4) return(-Mu/RMag3*y[1]+Tm*RUnit[1]);
    if (i==5) return(-Mu/RMag3*y[2]+Tm*RUnit[2]);
   
    return 0;
}
