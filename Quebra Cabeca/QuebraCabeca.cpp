//San Diego - 09/09/19
#include <iostream>

using namespace std;

//Função responsável por alocar o espaço correspondente para a matriz.
int** InstanciaMatriz(int** Matriz, int Dimensao);

//Função responsável por inicializar com os respectivos valores de cada posição da matriz.
int** InicializaMatrixObjetivo(int** Matriz, int Dimensao);

//Inicializa vetor de distâncias
int* InicializaVetorDistancias(int* Vetor, int Dimensao, int** MatrizInicial, int** MatrizObjetivo)

void MostraMatriz(int** Matriz, int Dimensao);

//Funções de movimentações de peças
void MoverBaixo(int i, int j, int** Matriz, int Dimensao);

void MoverCima(int i, int j, int** Matriz, int Dimensao);

void MoverEsquerda(int i, int j, int** Matriz, int Dimensao);

void MoverDireita(int i, int j, int** Matriz, int Dimensao);

//Verifica se o estado objetivo foi alcançado.
bool VerificarObjetivo(int** Matriz, int** MatrizObjetivo, int Dimensao);

int main(){
	int Dimensao;
    int** MatrizObjetivo;
    int** MatrizInicial;
    int*  Distancias;

	cout << "Digite a dimensão da Matrix: ";
	cin >> Dimensao;

	MatrizObjetivo = InstanciaMatriz(MatrizObjetivo, Dimensao);
	MatrizObjetivo = InicializaMatrixObjetivo(MatrizObjetivo, Dimensao);
	MostraMatriz(MatrizObjetivo, Dimensao);

	MatrizInicial = InstanciaMatriz(MatrizInicial, Dimensao);
	
	cout << "Entre com a Matriz Inicial" << endl;
	for (int i = 0; i < Dimensao; i++){
		for (int j = 0; j < Dimensao; j++){
			cout << "posição (" << i << ", " << j << "): ";
			cin >> MatrizInicial[i][j];
		}
	}

	MostraMatriz(MatrizInicial, Dimensao);
	MoverBaixo(1,1,MatrizInicial, Dimensao);
	cout << endl;
	MostraMatriz(MatrizInicial, Dimensao);
	MoverCima(2,1,MatrizInicial, Dimensao);
	cout << endl;
	MostraMatriz(MatrizInicial, Dimensao);

	return 0;
}

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
	Vetor = new int[Dimensao];
	
	for (int i = 0; i < ; ++i){
		/* code */
	}
}

// ------------- Funções de movimentação de peças ------------------
void MoverBaixo(int i, int j, int** Matriz, int Dimensao){
	if (Matriz[i][j] == 0 && i < Dimensao - 1){
		Matriz[i][j] = Matriz[i+1][j];
		Matriz[i+1][j] = 0; 
	}
}

void MoverCima(int i, int j, int** Matriz, int Dimensao){
	if (Matriz[i][j] == 0 && i > 0){
		Matriz[i][j] = Matriz[i-1][j];
		Matriz[i-1][j] = 0;
	}
}

void MoverEsquerda(int i, int j, int** Matriz, int Dimensao){
	if (Matriz[i][j] == 0 && j > 0){
		Matriz[i][j] = Matriz[i][j-1];
		Matriz[i][j-1] = 0;	
	}
}

void MoverDireita(int i, int j, int** Matriz, int Dimensao){
	if (Matriz[i][j] == 0 && j < Dimensao - 1){
		Matriz[i][j] = Matriz[i][j+1];
		Matriz[i][j+1] = 0;	
	}
}

bool VerificarObjetivo(int** Matriz, int** MatrizObjetivo, int Dimensao){
	bool aux = true;

	for (int i = 0; i < Dimensao; i++){
		for (int j = 0; j < Dimensao; j++){
			if(Matriz[i][j] != MatrizObjetivo[i][j]){
				aux = false;
			}
		}
	}

	return aux;
}