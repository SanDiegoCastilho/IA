#include "Utilitarios.h"

class No{
    public:
        int** Matriz;
        No** Filhos;
        No* Pai;
        int Altura;
        bool EhSolucao;

    No(int** Matriz, int** MatrizObjetivo, int Dimensao){
        this->Matriz = Matriz;
        //this->Pai = Pai;
        this->Altura = 0;
        this->Filhos = new No* [4];
        VerificarSolucao(MatrizObjetivo, Dimensao);
    }

    void GerarFilhos(int Dimensao){
        int u, v;

        for (int i = 0; i < Dimensao; i++){
            for (int j = 0; j < Dimensao; j++){
                if (this->Matriz[i][j] == 0){
                    u = i;
                    v = j;
                }
            }
        }

        int** MatrizAux1 = this-> Matriz;
        Mover(u+1, v, MatrizAux1, Dimensao);
        //this->Filhos[0] = new No(MatrizAux1, );

        int** MatrizAux2 = this-> Matriz; 
        Mover(u, v+1, MatrizAux2, Dimensao);
        //this->Filhos[1] = new No();

        int** MatrizAux3 = this-> Matriz; 
        Mover(u-1, v, MatrizAux3, Dimensao);
        //this->Filhos[2] = new No();

        int** MatrizAux4 = this-> Matriz; 
        Mover(u, v-1, MatrizAux4, Dimensao);
        //this->Filhos[3] = new No();
    
    }

    void VerificarSolucao(int** MatrizObjetivo, int Dimensao){
        this->EhSolucao = VerificarObjetivo(this->Matriz, MatrizObjetivo, Dimensao);
    }

};

int main() {
    return 0;    
}