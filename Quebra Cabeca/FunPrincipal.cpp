#include "Utilitarios.h"

int main(){
	int Dimensao = 3;
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
	MostraMatriz(MatrizObjetivo, Dimensao);

	MostraMatriz(MatrizInicial, Dimensao);
	Mover(1,1,MatrizInicial, Dimensao);
	cout << endl;

	MostraMatriz(MatrizInicial, Dimensao);

	cout << "-----------------------------------" << endl;
	Distancias = InicializaVetorDistancias(Distancias, Dimensao, MatrizInicial, MatrizObjetivo);

	for (int i = 0; i < Dimensao * Dimensao; ++i){
		cout << Distancias[i] << " ";
	}


	return 0;
}