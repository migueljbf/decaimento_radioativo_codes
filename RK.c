// criado em		: 16 de maio de 2023
// ult. atualização	: 15 de junho de 2023
// 
// autor			: migueljbf (migueljbf@gmail.com)
// notas			: solucao numerica via metodo de Runge-Kutta de segunda ordem para o problema do decaimento radioativo X1 -> X2 -> X3
// como compilar	: gcc RK.c -lm -o RK.out (no Windows, substituir por "RK.exe")
// como executar 	: ./RK.out >> dados.dat (no Windows, substituir por  "./RK.exe >> dados.dat")


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


//variáveis que serão utilizadas
double r1, r2, r3, r1m, r2m, r3m, a, b;

int main(int argc, char **argv){
	
	//parâmetros do modelo
	double t0= 0.0;
	double tf= 3.0e4;
	double dt= 1.0;
	double T1= 120.0;
	double T2= 3321.12;
	
	//gerando a condição inicial
	double tn= t0;
	double r1n= 1.0;
	double r2n= 0.0;
	double r3n= 0.0;
	
	//imprime a condição inicial na tela 
	printf("%e %e %e %e\n",tn,r1n,r2n,r3n);
	
	//definição das constantes de decaimento
	double w1= log(2)/T1;
	double w2= log(2)/T2;
	
	//início do método de Runge-Kutta
	while (tn <= tf) {
		
		a= -w1*r1n;
		r1m= r1n + a*dt/2;
		b= -w1*r1m;
		r1= r1n + b*dt;
	
		a= (-w2*r2n) + w1*r1n;
		r2m= r2n + a*dt/2;
		b= (-w2*r2m) + w1*r1m;
		r2= r2n + b*dt;
		
		a= w2*r2n;
		r3m= r3n + a*dt/2;
		b= w2*r2m;
		r3= r3n + b*dt;
			
		r1n= r1;
		r2n= r2;
		r3n= r3;
		
		tn+= dt;
		
		//imprime na tela os dados gerados nesse passo temporal
		printf("%e %e %e %e\n",tn,r1n,r2n,r3n);
	}		
	
	return 0;
}	
