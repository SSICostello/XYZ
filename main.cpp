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
/* Vector3d Rinit(Re+300000.0,0.0,0.0); */
/* Vector3d Vinit(0.0,sqrt(Mu/Rinit[0]),0.0); */
double lat (34.7328 * dtr);
double longitude (120.5681 * dtr);

Vector3d Rinit(Re*cos(lat)*cos(longitude),Re*cos(lat)*sin(longitude),Re*sin(lat));
Vector3d Vinit=WEarth.cross(Rinit);


FILE * output;                   /* internal filename */

int main()
{
    double t, y[N];
    /* y[0] = x initial position */
    /* y[1] = y initial position */
    /* y[2] = z initial position */
    /* y[3] = x initial velocity */
    /* y[4] = y initial velocity */
    /* y[5] = z initial velocity */
    
    ofstream output("osc.txt");                   /* external filename */
    if (! output)
    { cout << "Error Opening output file" << endl;
        return -1;
    }
    
    y[0] = Rinit[0];
    y[1] = Rinit[1];
    y[2] = Rinit[2];
    y[3] = Vinit[0];
    y[4] = Vinit[1];
    y[5] = Vinit[2];
    t=0.0;
    
    output.setf(ios::fixed);
    output.precision(2);
    
    output << setw(15) << t << setw(15) << y[0] << setw(15) << y[1] << setw(15) << y[2] << setw(15) << y[3] << setw(15) << y[4] << setw(15) << y[5] << endl;
    
    while (t < 360)
    {
        t = t + step;
        runge4(t, y, step);
        output << setw(15) << t << setw(15) << y[0] << setw(15) << y[1] << setw(15) << y[2] << setw(15) << y[3] << setw(15) << y[4] << setw(15) << y[5] << endl;
    }
    
    output.close();
}
