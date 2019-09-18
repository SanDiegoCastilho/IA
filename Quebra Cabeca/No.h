//San Diego - 18/09/2019
// #include "Utilitarios.h"

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

class No{
    public:
        int** Matriz;
        No** Filhos;
        No* Pai;
        int Altura;
        bool EhSolucao;

    public:
        //Construtor
        No(int**, No* , int**, int);

         //Construtor
        No(int**, int**, int);

        //Função responsável por gerar os filhos de cada nó.
        void GerarFilhos(int, int**);

        //Função q determina se o atual nó é uma solução ou não.
        void VerificaSolucao(int**, int);

};

// int main(){
//     return 0;
// }