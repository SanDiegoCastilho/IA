//San Diego - 09/09/19
#include <iostream>

using namespace std;

//Função responsável por alocar o espaço correspondente para a matriz.
int** InstanciaMatriz(int** Matriz, int Dimensao);

//Função responsável por inicializar com os respectivos valores de cada posição da matriz.
int** InicializaMatrixObjetivo(int** Matriz, int Dimensao);

void MostraMatriz(int** Matriz, int Dimensao);

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
			cout << endl;
		}
	}

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