#ifndef RUNGEKUTTA_H
#define RUNGEKUTTA_H

#include <iostream>

class RungeKutta
{
private:
	double k[3];
	double x;
	double y;
	double h;
	
	double f(double x, double y);
	void calcX(double x, int index);
	void calcY(double y, int index);
	void calcK(int index);
	
public:
	double rungeKutta4(double x, double y, double h);
};

#endif
