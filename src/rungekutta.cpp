#include "rungekutta.hpp"

double
RungeKutta::f(double x, double y)
{
	/*std::cout<<"f(x,y): " << x-2*y+1  << std::endl;*/
	return x-2*y+1;
}

void 
RungeKutta::calcX(double x, int index)
{
	this->x = (index != 2) ? x + this->h/2 : x + this->h;
}

void
RungeKutta::calcY(double y, int index)
{
	this->y = (index != 2) ? y + this->h/2 * k[index] : y + this->h * k[index];
}
void
RungeKutta::calcK(double x, double y, int index)
{
	/*std::cout << "x["<<index+1<< "]=" << x <<std::endl;
	std::cout << "y["<<index+1<< "]=" << y <<std::endl;*/
	k[index] = f(x,y);
	/*std::cout << "k["<<index+1<< "]=" << this->k[index]<<std::endl<<std::endl;*/
}

double
RungeKutta::rungeKutta4(double x, double y, double passo)
{
	double tempX, tempY;

	this->x = x;
	this->y = y;
	
	tempX = x;
	tempY = y;
	
	this->h = passo;
	
	for (int i = 0; i < 3; i++)
	{
		//std::cout << "x = " << this->x << " y = " << this->y <<std::endl;
		calcK(this->x,this->y,i);
		
		if(!(i % 2))
			calcX(tempX, i);
		
		calcY(tempY,i);
		//std::cout << "x = " << this->x << " y = " << this->y <<std::endl;
	}
	
	calcK(this->x,this->y,3);
	
	return tempY + h / 6.0 * (k[0] + 2 * (k[1] + k[2]) + k[3]);
}
