# criado em		    : 17 de maio de 2023
# ult. atualização	: 15 de junho de 2023
# autor			    : migueljbf (migueljbf@gmail.com)
# notas			    : solucao numerica via metodo de Runge-Kutta de segunda ordem para o probelma do decaimento radioativo X1 -> X2 -> X3
# como compilar	    :
# como executar 	: 

import math
import random

# parâmetros do modelo
N0 = 10000
t0 = 0
tf = 30000
dt = 1
T1 = 120.0
T2 = 3321.12

# probabilidade de decaimento por átomo
P1 = dt * math.log(2) / T1
P2 = dt * math.log(2) / T2

# gerando a condição inicial
tn = t0
N1 = N0
N2 = 0
N3 = 0

# imprime as condições iniciais na tela
print("%e, %e, %e, %e" % (tn, 1.0 * N1 / N0, 1.0 * N2 / N0, 1.0 * N3 / N0))

# inicio do método de Monte Carlo
while tn < tf:
    c1 = 0
    c2 = 0

    for i in range(N1):
        w = random.random()
        if w < P1:
            c1 = c1 + 1

    for i in range(N2):
        w = random.random()
        if w < P2:
            c2 = c2 + 1

    N1 = N1 - c1
    N2 = N2 + c1 - c2
    N3 = N3 + c2

    tn = tn + dt
    # imprime na tela os dados obtidos nesse passo temporal
    print("%e, %e, %e, %e" % (tn, 1.0 * N1 / N0, 1.0 * N2 / N0, 1.0 * N3 / N0))
