#include <iostream>

#include "rungekutta.hpp"

using namespace std;

int main()
{
	double limInf, limSup, iteracoes;
	double x,y,x0;
	double passo;
	RungeKutta *r = new RungeKutta();
	
	cout.precision(8);

	cout << "Metodo Runge-Kutta 4 Ordem" << endl;

	cout << "Digite o limite inferior: ";
	cin >> limInf;

	cout << "Digite o limite superior: ";
	cin >> limSup;

	cout << "Digite o numero de iterações desejadas: ";
	cin >> iteracoes;

	cout << "Digite o valor de x0: ";
	cin >> x;

	cout << "Digite o valor de y0: ";
	cin >> y;

	passo = (limSup-limInf)/iteracoes;
	cout << "Iteracao\tValor de x\t\tValor de y" << endl;
	cout << fixed << "0\t\t" << x  << "\t\t" << y << endl;
	
	/*Inicio do calculo da EDO passando por cada iteração*/
	x0 = x;
	for(int i = 1; i <= iteracoes; i++)
	{
		
		y = r->rungeKutta4(x,y,passo);//Executa o metodo para o calculo da EDO	
		
		x = x0 + i*passo;//incrementa o passo de x

		cout << fixed << i << "\t\t" << x  << "\t\t" << y << endl; //mostra o resultado da iteração
		
	}
	
	return 0;
}
