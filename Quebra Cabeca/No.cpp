#include <iostream>
// #include "Utilitarios.h"
#include <cmath>
#include "No.h"

using namespace std;

//Construtor
No::No(int** Matriz, No* Pai, int** MatrizObjetivo, int Dimensao){
        this->Matriz = Matriz;
        this->Pai = Pai;
        this->Altura = Pai->Altura + 1;
        this->Filhos = new No* [4];
        GerarFilhos(Dimensao, MatrizObjetivo);
        VerificaSolucao(MatrizObjetivo, Dimensao);
}

No::No(int** Matriz, int** MatrizObjetivo, int Dimensao){
        this->Matriz = Matriz;
        this->Pai = Pai;
        this->Altura = 0;
        this->Filhos = new No* [4];
        GerarFilhos(Dimensao, MatrizObjetivo);
        VerificaSolucao(MatrizObjetivo, Dimensao);
}

void No::GerarFilhos(int Dimensao, int** MatrizObjetivo){
    int u, v;
    int*** MatrizAux; 

    for (int i = 0; i < Dimensao; i++){
        for (int j = 0; j < Dimensao; j++){
            if (this->Matriz[i][j] == 0){
                u = i;
                v = j;
            }
        }
    }

    MatrizAux = new int**[4];

    for (int i = 0; i < 4 ; i++){
        MatrizAux[i] = this->Matriz;
    }

    cout << "aqui" <<endl;

    Mover(u+1, v, MatrizAux[0], Dimensao);
    this->Filhos[0] = new No(MatrizAux[0], this, MatrizObjetivo, Dimensao);
    this->Filhos[0]->Altura = this->Altura+1;

    Mover(u, v+1, MatrizAux[1], Dimensao);
    this->Filhos[1] = new No(MatrizAux[1], this, MatrizObjetivo, Dimensao);
    this->Filhos[1]->Altura = this->Altura+1;

    Mover(u-1, v, MatrizAux[2], Dimensao);
    this->Filhos[2] = new No(MatrizAux[2], this, MatrizObjetivo, Dimensao);
    this->Filhos[2]->Altura = this->Altura+1;
 
    Mover(u, v-1, MatrizAux[3], Dimensao);
    this->Filhos[3] = new No(MatrizAux[3], this, MatrizObjetivo, Dimensao);
    this->Filhos[3]->Altura = this->Altura+1;
}

void No::VerificaSolucao(int** MatrizObjetivo, int Dimensao){
    this->EhSolucao = VerificarObjetivo(this->Matriz, MatrizObjetivo, Dimensao);
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

int CalcularDistancia(int i, int j, int u, int v){
    int distancia = abs(i - u) + abs(j - v);

    return distancia;
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