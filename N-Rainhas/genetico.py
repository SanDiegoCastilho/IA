import random

def criarTabelas(quantidadeTabelas,n):
    tabelas = [[] for i in range(quantidadeTabelas)]
    for i in range(quantidadeTabelas):
        tabelas[i] = criarTabela(n)
    return tabelas

def criarTabela(n):
    posicaoRainhas = [ j for j in range(n)]
    random.shuffle(posicaoRainhas)
    return posicaoRainhas

def count_attacks(jogo,j):
    i = jogo[j]

    d1 = i - j
    d2 = i + j

    attacks = 0

    for c in range(n): # loop into columns
      if c != j: # if the column is different of the given
        # If a queen exists in the same row
        # or in the main diagonal (\)
        # or in the secondary diagonal (/)
        if ((jogo[c] == i) or
          (d1 < n and d1 >= 0 and jogo[c] == d1) or 
          (d2 < n and d2 >= 0 and jogo[c] == d2)):
          attacks += 1

      d1 += 1
      d2 -= 1

    return attacks

# Given a board, return the its total cost
def state_cost(jogo):
  cost = 0
  for j in range(n): # loop into columns
    cost += count_attacks(jogo,j)

  cost = int(cost / 2)
  
  return cost

def GeraRoleta(jogos):
  Cjogos = []
  for i in jogos:
    Cjogos.append(1 - (state_cost(i) / (n*n)))  

  somaProbabilidades = sum(Cjogos)

  PEscolha = []
  for i in Cjogos:
    PEscolha.append(i / somaProbabilidades)

  Roleta = []
  for i in PEscolha:
    if len(Roleta) == 0:
      Roleta.append((0, i))
    else:
      ultimo = Roleta[-1]
      Roleta.append((ultimo[1], ultimo[1]+i))


  escolhaRandomica = random.random()

  indiceEscolhido = 0
  for i in Roleta:
    if(escolhaRandomica >= i[0] and escolhaRandomica < i[1]):
      indiceEscolhido = Roleta.index(i)

  return indiceEscolhido


def Cruzamento(pai1, pai2, jogos):
	indexAleatorio = random.randint(0, n-1)

	filho1 = pai1[:indexAleatorio] + pai2[indexAleatorio:]
	filho2 = pai2[:indexAleatorio] + pai1[indexAleatorio:]

	#Mutação
	if random.random() > 0.00:
	  filho1[random.randint(0, n-1)] = random.randint(0, n-1)

	if random.random() > 0.00:
	  filho2[random.randint(0, n-1)] = random.randint(0, n-1)

	jogos.append(filho1)
	jogos.append(filho2)

def CruzamentoIntercalado(pai1, pai2, jogos):
	indexAleatorio = random.randint(0, n-1)

	filho1 = []
	filho2 = []

	for i in range(0, len(pai1)):
		if (i % 2 == 0):
			filho1.append(pai1[i])
			filho2.append(pai1[i])
		else:
			filho1.append(pai2[i])
			filho2.append(pai2[i])

	#Mutação
	if random.random() > 0.00:
	  filho1[random.randint(0, n-1)] = random.randint(0, n-1)

	if random.random() > 0.00:
	  filho2[random.randint(0, n-1)] = random.randint(0, n-1)

	jogos.append(filho1)
	jogos.append(filho2)


n = 40
jogos = criarTabelas(10,n)
ProxGeracao = []
achou = False

for x in range(1,500):
    for i in range(0, int(len(jogos)/2)):
	    pai1 = jogos[GeraRoleta(jogos)]
	    pai2 = jogos[GeraRoleta(jogos)]
	    CruzamentoIntercalado(pai1, pai2, ProxGeracao)
    
    jogos = ProxGeracao
    ProxGeracao = []
    for x in range(0, len(jogos)):
    	if (state_cost(jogos[x]) == 0) :
    		achou = True
    		break
    if (achou):
    	break

aux = state_cost(jogos[0])
i = 0
for x in range(0, len(jogos)):
	if (state_cost(jogos[x]) < aux):
		aux = state_cost(jogos[x])
		i = x
print(aux)		
print(jogos[i])