#include "Utilitarios.h"

class No{
    public:
        int** Matriz;
        No** Filhos;
        No* Pai;
        int Altura;
        bool EhSolucao;

    No(int** Matriz, No* Pai, int** MatrizObjetivo, int Dimensao){
        this->Matriz = Matriz;
        this->Pai = Pai;
        this->Altura = 0;
        VerificarSolucao(MatrizObjetivo, Dimensao);
    }

    void GerarFilhos(){

    }

    void VerificarSolucao(int** MatrizObjetivo, int Dimensao){
        this->EhSolucao = VerificarObjetivo(this->Matriz, MatrizObjetivo, Dimensao);
    }

};

int main() {
    return 0;    
}