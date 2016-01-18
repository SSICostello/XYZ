/*
 *  rk4.c
 *  
 *
 *
 */
#include "rk4.h"



int runge4(double x, double y[], double step)
{
	const int N=6;					/* number of first order equations */
	double h=step/2.0,                      /* the midpoint */
	t1[N], t2[N], t3[N],            /* temporary storage arrays */
	k1[N], k2[N], k3[N],k4[N];      /* for Runge-Kutta */
	int i;
	
	for (i=0;i<N;i++) t1[i]=y[i]+0.5*(k1[i]=step*f(x, y, i));
	for (i=0;i<N;i++) t2[i]=y[i]+0.5*(k2[i]=step*f(x+h, t1, i));
	for (i=0;i<N;i++) t3[i]=y[i]+    (k3[i]=step*f(x+h, t2, i));
	for (i=0;i<N;i++) k4[i]=                step*f(x+step, t3, i);
	
	for (i=0;i<N;i++) y[i]+=(k1[i]+2*k2[i]+2*k3[i]+k4[i])/6.0;
    
    return 0;
}




