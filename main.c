#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(){
    Matriz *mat;
    mat = criaMatriz();

    alocaMatriz(mat, 3, 3);

    printf("/-------------------------/\n");

    printaMatriz(mat);

    printf("/-------------------------/\n");

    insereValor(mat, 1, 1, 5);
    insereValor(mat, 1, 2, 10);
    insereValor(mat, 1, 3, 2);
    insereValor(mat, 2, 1, 2);
    insereValor(mat, 2, 2, 5);
    insereValor(mat, 2, 3, 10);
    insereValor(mat, 3, 1, 10);
    insereValor(mat, 3, 2, 1);
    insereValor(mat, 3, 3, 5);

    printf("Nova Matriz: \n");
    printaMatriz(mat);

    printf("/-------------------------/\n");

    buscaValor(mat, 10);

    printf("/-------------------------/\n");

    printaVizinhos(mat, 2, 2);

    return 0;
    getch();
}
