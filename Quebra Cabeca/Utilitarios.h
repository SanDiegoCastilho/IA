//San Diego - 09/09/19
#include <iostream>
#include <cmath>

using namespace std;

//Função responsável por alocar o espaço correspondente para a matriz.
int** InstanciaMatriz(int** Matriz, int Dimensao);

//Função responsável por inicializar com os respectivos valores de cada posição da matriz.
int** InicializaMatrixObjetivo(int** Matriz, int Dimensao);

//Inicializa vetor de distâncias
int* InicializaVetorDistancias(int* Vetor, int Dimensao, int** MatrizInicial, int** MatrizObjetivo);

void MostraMatriz(int** Matriz, int Dimensao);

int CalcularDistancia(int i, int j, int u, int v);

//Funções de movimentações de peças
void Mover(int i, int j, int** Matriz, int Dimensao);

//Verifica se o estado objetivo foi alcançado.
bool VerificarObjetivo(int** Matriz, int** MatrizObjetivo, int Dimensao);


//Função responsável por alocar o espaço correspondente para a matriz.
int** InstanciaMatriz(int** Matriz, int Dimensao){
	Matriz = new int *[Dimensao];

	for (int i = 0; i < Dimensao; i++){
		Matriz[i] = new int [Dimensao];
	}

	return Matriz;
}

//Função responsável por inicializar com os respectivos valores de cada posição da matriz.
int** InicializaMatrixObjetivo(int** Matriz, int Dimensao){
	int cont = 1;
	for (int i = 0; i < Dimensao; i++){
		for (int j = 0; j < Dimensao; j++){
			if (i == j && j == Dimensao - 1){
				Matriz[i][j] = 0;

			}else{
				Matriz[i][j] = cont;
				cont++;
			}
		}
	}

	return Matriz;
}

void MostraMatriz(int** Matriz, int Dimensao){
	for (int i = 0; i < Dimensao; i++){
		for (int j = 0; j < Dimensao; j++){
			cout << Matriz[i][j] << " ";
		}

		cout << endl;
	}
}

int* InicializaVetorDistancias(int* Vetor, int Dimensao, int** MatrizInicial, int** MatrizObjetivo){
	Vetor = new int[Dimensao * Dimensao];
	int u, v, index;

	for (int i = 0; i < Dimensao; i++){
		for (int j = 0; j < Dimensao; j++){
			index = MatrizInicial[i][j] - 1;

			if (index < 0){
				u = v = Dimensao-1;

			}else{
				u = abs(floor(index/Dimensao));
				v = index % Dimensao;
			}

			Vetor[MatrizInicial[i][j]] = CalcularDistancia(i,j,u,v);
		}	
	}

	return Vetor;
}

// ------------- Funções de movimentação de peças ------------------
void Mover(int i, int j, int** Matriz, int Dimensao){
	int posicao[4][2] = {
		{i-1, j},
		{i, j+1},
		{i+1 ,j},
		{i, j-1}
	};
	int u, v;

	for (int k = 0; k < 4; k++){
		u = posicao[k][0];
		v = posicao[k][1];

		if (!(u > Dimensao - 1 || u < 0 || v < 0 || v > Dimensao - 1) && Matriz[u][v] == 0) {
			Matriz[u][v] = Matriz[i][j];
			Matriz[i][j] = 0;
		}
	}
}

bool VerificarObjetivo(int** Matriz, int** MatrizObjetivo, int Dimensao){
	for (int i = 0; i < Dimensao; i++){
		for (int j = 0; j < Dimensao; j++){
			if(Matriz[i][j] != MatrizObjetivo[i][j]){
				return false;
			}
		}
	}

	return true;
}

int CalcularDistancia(int i, int j, int u, int v){
	int distancia = abs(i - u) + abs(j - v);

	return distancia;
}