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
    
    Vector3d Vunit, RUnit;
    double RMag = RUnit.norm();
    double RMag3 = pow(sqrt(y[0]*y[0] + y[1]*y[1] + y[2]*y[2]),3);
/*    double Vmag = sqrt(y[3]*y[3] + y[4]*y[4] + y[5]*y[5]);
    Vunit[0] = y[3]/Vmag;
    Vunit[1] = y[4]/Vmag;
    Vunit[2] = y[5]/Vmag; */
    RUnit[1] = y[0]/RMag;
    RUnit[2] = y[1]/RMag;
    RUnit[3] = y[2]/RMag;
    if (i==0) return(y[3]);
    if (i==1) return(y[4]);
    if (i==2) return(y[5]);
    if (i==3) return(-Mu/RMag3*y[0]+Tm*Vunit[0]);
    if (i==4) return(-Mu/RMag3*y[1]+Tm*Vunit[1]);
    if (i==5) return(-Mu/RMag3*y[2]+Tm*Vunit[2]);
   
    return 0;
}
