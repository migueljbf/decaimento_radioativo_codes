# criado em		    : 17 de maio de 2023
# ult. atualização	: 15 de junho de 2023
# autor			    : migueljbf (migueljbf@gmail.com)
# notas			    : solucao numerica via metodo de Runge-Kutta de segunda ordem para o probelma do decaimento radioativo X1 -> X2 -> X3
# como compilar	    :
# como executar 	: 

import math

#parâmetros do modelo
t0= 0
tf= 30000
dt= 1
T1= 120.0
T2= 3321.12

#gerando a condição inicial
tn= t0
r1n= 1
r2n= 0
r3n= 0

#imprime as condições iniciais na tela
print("%e, %e, %e, %e" % (tn,r1n,r2n,r3n))

#definição das constantes de decaimento
w1= math.log(2)/T1
w2= math.log(2)/T2

#inicio do método de Runge-Kutta de segunda ordem
while tn < tf:
    a= (-w1*r1n)
    r1m= r1n + a*dt/2
    b= (-w1*r1m)
    r1= r1n + b*dt

    a = (-w2 * r2n) + w1*r1n
    r2m = r2n + a * dt / 2
    b = (-w2 * r2m) + w1*r1m
    r2 = r2n + b * dt

    a = w2 * r2n
    r3m = r3n + a * dt / 2
    b = w2 * r2m
    r3 = r3n + b * dt

    r1n= r1
    r2n= r2
    r3n= r3

    tn= tn + dt
    # imprime na tela os dados obtidos nesse passo temporal
    print("%e, %e, %e, %e" % (tn,r1n,r2n,r3n))
