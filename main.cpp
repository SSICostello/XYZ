//
//  main.cpp
//  XYZ
//
//  Created by tobin on 12/30/15.
//  Copyright © 2015 tobin. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <Eigen/Dense>
#include "rk4.h"
#include "init.hpp"
#include "orbit.hpp"

using namespace std;
using namespace Eigen;

const int N=6;                       /* number of first order equations */
const double step = 1;               /* stepsize in t*/
/* Vector3d RInit(Re+300000.0,0.0,0.0); */
/* Vector3d VInit(0.0,sqrt(Mu/RInit[0]),0.0);
double lat (34.7328 * dtr);
double longitude (120.5681 * dtr); */
double lat (0.0 * dtr);
double longitude (0.0 * dtr);
Vector3d WEarth;

Vector3d RInit, VInit;


FILE * output;                   /* internal filename */

int main()
{

    double t, y[N];
    
    ofstream output("osc.txt");                   /* external filename */
    if (! output)
    { cout << "Error Opening output file" << endl;
        return -1;
    }
    
    RInit << Re*cos(lat)*cos(longitude),Re*cos(lat)*sin(longitude),Re*sin(lat);
    WEarth << 0,0, - 360.0 / 86400.0 * dtr;
    VInit = WEarth.cross(RInit);


    
    y[0] = RInit[0];
    y[1] = RInit[1];
    y[2] = RInit[2];
    y[3] = VInit[0];
    y[4] = VInit[1];
    y[5] = VInit[2];
    t=0.0;
    
    output.setf(ios::fixed);
    output.precision(2);
    
    output << setw(15) << t << setw(15) << y[0] << setw(15) << y[1] << setw(15) << y[2] << setw(15) << y[3] << setw(15) << y[4] << setw(15) << y[5] << endl;
    
    while (t < 720.0)
    {
        t = t + step;
        runge4(t, y, step);
        output << setw(15) << t << setw(15) << y[0] << setw(15) << y[1] << setw(15) << y[2] << setw(15) << y[3] << setw(15) << y[4] << setw(15) << y[5] << endl;
    }
    
    output.close();
}
