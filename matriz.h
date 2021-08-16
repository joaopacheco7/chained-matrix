//Estutura do Nó
typedef struct no No;
struct no{
    int valor;
    No *cima, *baixo;
};

//Estrutura da Matriz
typedef struct matriz Matriz;
struct matriz{
    No *primeiro;
    int m, n;
};

//Função para criar a Matriz
Matriz *criaMatriz();
//Função para alocar a Matriz na memória
Matriz *alocaMatriz(Matriz *mat, int m, int n);
//Função para deletar a Matriz
Matriz *deletaMatriz(Matriz *mat);
//Função para printar todos elementos da matriz
void printaMatriz(Matriz *mat);

//Função para inserir um valor
No *insereValor(Matriz *mat, int i, int j, int valor);
//Função para buscar um valor
No *buscaValor(Matriz *mat, int valor);
//Função para printar todos os vizinhos
No *printaVizinhos(Matriz *mat, int i, int j);
