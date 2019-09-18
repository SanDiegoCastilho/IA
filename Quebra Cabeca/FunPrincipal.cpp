#include <iostream>
#include <cmath>
#include "No.h"

using namespace std;

int main(){
	int Dimensao = 3;
	No* Borda;
    int** MatrizObjetivo;
    int** MatrizInicial;
    int MatrizInicialTop[Dimensao][Dimensao] = {
		{ 8, 1, 3 },
		{ 2, 5, 0 },
		{ 4, 7, 6 }
	};

	MatrizInicial = InstanciaMatriz(MatrizInicial, Dimensao);

	for (int i = 0; i < Dimensao; i++){
		for (int j = 0; j < Dimensao; j++){
			MatrizInicial[i][j] = MatrizInicialTop[i][j];
		}
	}

    int*  Distancias;

	MatrizObjetivo = InstanciaMatriz(MatrizObjetivo, Dimensao);
	MatrizObjetivo = InicializaMatrixObjetivo(MatrizObjetivo, Dimensao);

	cout << "Matriz Inicial Aqui:" << endl;
	MostraMatriz(MatrizInicial, Dimensao);
	cout << endl;

	cout << "Instanciando Nó" << endl;
	No n(MatrizInicial, MatrizObjetivo, Dimensao);

	n.GerarFilhos(Dimensao, MatrizObjetivo);

	return 0;
}

No* BucaSolução(int** MatrizInicial, int** MatrizObjetivo, int Dimensão){
	No n(MatrizInicial, MatrizObjetivo, Dimensao);

}