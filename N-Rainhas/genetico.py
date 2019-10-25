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

  print(indiceEscolhido)
  return indiceEscolhido



n = 10

# jogos = [[7,7,7,7,7,7,7,7,7,7], [9,9,9,9,9,9,9,9,9,9]]

jogos = criarTabelas(5,n)
pai1 = jogos[GeraRoleta(jogos)]
pai2 = jogos[GeraRoleta(jogos)]

indexAleatorio = random.randint(0, n-1)
print(indexAleatorio)

filho1 = pai1[:indexAleatorio] + pai2[indexAleatorio:]
filho2 = pai2[:indexAleatorio] + pai1[indexAleatorio:]

if random.random() > 0.00:
  filho1[random.randint(0, n-1)] = random.randint(0, n-1)

if random.random() > 0.00:
  filho2[random.randint(0, n-1)] = random.randint(0, n-1)

print(filho1)
print(filho2)

jogos[0] = filho1
jogos[1] = filho2