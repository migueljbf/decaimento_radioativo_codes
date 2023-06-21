// criado em		: 17 de maio de 2023
// ult. atualização	: 15 de junho de 2023
// 
// autor			: migueljbf (migueljbf@gmail.com)
// notas			: simulação de monte carlo para o problema do decaimento radioativo X1 -> X2 -> X3
// como compilar	: gcc MC.c -lm -o MC.out  (no Windowns, substituir por "MC.exe")
// como executar 	: ./MC.out >> dados.dat
// como executar 	: ./MC.out >> dados.dat (no Windows, substituir por  "./MC.exe >> dados.dat")


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int i;
double w;
int main(int argc, char **argv){
	
	//parâmetros do modelo
	int N0= 1e4;
	double t0= 0.0;
	double tf= 3.0e4;
	double dt= 1;
	double T1= 120.0;
	double T2= 3321.12;

	//definição das probabilidades de decaimento	
	double P1= dt*log(2)/T1;
	double P2= dt*log(2)/T2;
		
	//gerando a condição inicial	
	double tn= t0;
	int N1= N0;
	int N2= 0;
	int N3= 0;
	
	//imprime a condição inicial na tela 
	printf("%e %e %e %e\n",tn,1.0*N1/N0,1.0*N2/N0,1.0*N3/N0);

	
	//inicio das simulações de Monte Carlo
	srand(time(NULL)); //inicializando o gerador de números aleatórios
	while(tn < tf) {
		
		int c1= 0;
		int c2= 0;		

		for(i= 0;i< N1;i++){
			w = 1.0*rand()/RAND_MAX;
			if(w < P1){
				c1++;
			}
		}
	
		for(i= 0;i< N2;i++){
			w = 1.0*rand()/RAND_MAX;
			if(w < P2){
				c2++;
			}
		}
	
		N1= N1 - c1;
		N2= N2 + c1 - c2;
		N3= N3 + c2;
		
		tn= tn + dt;
		
		//imprime na tela os dados obtidos nesse passo de MC 
		printf("%e %e %e %e\n",tn,1.0*N1/N0,1.0*N2/N0,1.0*N3/N0);
	}		
	
	return 0;
}	
