/*Implementação da Classe RungeKutta*/
#include "rungekutta.hpp"

/*Metodo que calcula os valores da função*/
double
RungeKutta::f(double x, double y)
{
	return  -0.5924*(x + 5);
}

/*Metodo que calcula o valor de x*/
void 
RungeKutta::calcX(double x, int index)
{
	this->x = (index != 2) ? x + this->h/2 : x + this->h;
}

/*Metodo que calcula o valor de y*/
void
RungeKutta::calcY(double y, int index)
{
	this->y = (index != 2) ? y + this->h/2 * k[index] : y + this->h * k[index];
}

/*Metodo que calcula o valor de cada K, o parametro index, é o indice do k a ser calculado*/
void
RungeKutta::calcK(int index)
{
	k[index] = f(this->x,this->y);
}

/*Metodo principal que calcula o resultado da edo*/
double
RungeKutta::rungeKutta4(double x, double y, double passo)
{
	double tempX, tempY;

	this->x = x;
	this->y = y;
	
	tempX = x; //Armazena os x e y temporarios
	tempY = y;
	
	this->h = passo;//Armazena o passo
	
	for (int i = 0; i < 3; i++)
	{
		calcK(i);
		
		if(!(i % 2)) //caso o i for par, calcula o valor de X, ja que deve ser calculado x na iteração 1
			calcX(tempX, i);
		
		calcY(tempY,i);
	}
	
	calcK(3);
	
	return tempY + h / 6.0 * (k[0] + 2 * (k[1] + k[2]) + k[3]); //retorna o resultado
}
