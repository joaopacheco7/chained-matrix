#include<stdio.h>
#include<stdlib.h>
#include"matriz.h"

Matriz *criaMatriz(){

  Matriz *mat = (Matriz*) malloc(sizeof(Matriz));

  mat->primeiro = NULL;

  return mat;
}

Matriz *alocaMatriz(Matriz *mat, int m, int n){

  if(mat == NULL)
    return 0;

  No *elem = (No*) malloc((m*n*sizeof(No)));
  mat->m = m;
  mat->n = n;
  mat->primeiro = elem;

  if(mat->primeiro == NULL)
    return 0;

  for(int a=0, b=mat->m; b<mat->m*mat->n; a++, b++){
    No *auxA = &mat->primeiro[a];
    No *auxB = &mat->primeiro[b];
    auxA->baixo = auxB;
    auxB->cima = auxA;
  }

  for(int a=0, b=(mat->m-1)*mat->n; a<mat->m, b<(mat->m)*mat->n; a++, b++){
    No *auxA = &mat->primeiro[a];
    No *auxB = &mat->primeiro[b];
    auxA->cima = auxB;
    auxB->baixo = auxA;
  }

  No *auxA = &mat->primeiro[0];
  auxA -= 1;
  auxA = &mat->primeiro[(mat->m)*(mat->n)];

  for(int i=0, a=0; i<m; i++){
    for(int j=0; j<n; j++, a++){
        printf("Inserindo valor em [%d][%d] -> ", i+1, j+1);
        scanf("%d", &mat->primeiro[a].valor);
    }
  }

  return mat;
}

Matriz *deletaMatriz(Matriz *mat){

  if(mat != NULL){
    free(mat);
  }
}

void printaMatriz(Matriz *mat){

  if(mat == NULL)
    return 0;

  for(int i=0, a=0; i<mat->n; i++){
    for(int j=0; j<mat->m; j++, a++)
      printf("%d\t", mat->primeiro[a].valor);
    printf("\n");
  }
}

No *insereValor(Matriz *mat, int i, int j, int valor){

  if(mat == NULL)
    return 0;

  if((i-1 < 0)||(j-1 > mat->m)||(i-1 > mat->n)||(j-1 < 0)){
    printf("Fora do intervalo da matriz!");
    exit(1);
  }

  No *elem = &mat->primeiro[(((i-1)*mat->m)+j-1)];

  elem->valor = valor;

  return mat;
}

No *buscaValor(Matriz *mat, int valor){

  if(mat == NULL)
    return 0;

  int aux=0, linhas = mat->n, colunas = mat->m;

  printf("Coordenada do valor %d: \n", valor);
  for(int i=0, j=0, k=0; k<mat->m*mat->n; k++, j++){
    if(k > linhas-1){
      i++;
      linhas += linhas;
    }
    if(k > colunas-1){
      j=0;
      colunas += colunas;
      }
      if(mat->primeiro[k].valor == valor){
          printf("(%d, %d)\t", i+1, j+1);
          aux++;
      }
  }
  printf("\n");
  if(aux == 0)
      return NULL;
  return mat;
}

No *printaVizinhos(Matriz *mat, int i, int j){

  if(mat == NULL)
    return 0;

  if((i-1 < 0)||(j-1 > mat->m)||(i-1 > mat->n)||(j-1 < 0)){
    printf("Fora do intervalo da matriz!");
    exit(1);
  }

  printf("(%d, %d) vizinhos: \n", i, j);
  No *aux = &mat->primeiro[(((i-1)*mat->m)+j-1)];
  No *elem = aux;

  elem = aux->cima;
  printf("\t%d\t \n", elem->valor);

  if(i-1 == 0 && j-1 == 0){
    elem = &mat->primeiro[((mat->n)-1)*mat->m+((mat->n)-1)];
    printf("%d\t%d\t", elem->valor, aux->valor);
  }
  else{
    elem = aux-1;
    printf("%d\t%d\t", elem->valor, aux->valor);
  }

  if(i-1 == (mat->m)-1 && j-1 == (mat->n)-1){
    elem = &mat->primeiro[0];
    printf("%d\t\n", elem->valor);
  }
  else{
    elem = aux+1;
    printf("%d\t\n", elem->valor);
  }

  elem = aux->baixo;
  printf("\t%d \n", elem->valor);
}
