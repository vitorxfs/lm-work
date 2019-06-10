// Seja A e B duas matrizes de inteiros de tamanho L x L
// realizar a operação (A x 2B), 
// retornando o maior valor da diagonal principal.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define L 3

int fill(int matriz[L][L]){ //preenche matriz com valores aleatórios
    int i, j;

    srand(time(NULL));

    for(i=0; i<L; i++)
        for(j=0; j<L; j++)
            matriz[i][j] = rand()%10;
}

int printMatriz(int matriz[L][L]){
    int i, j;
    for(i=0; i<L; i++){
        for(j=0; j<L; j++)
            printf("%d  ", matriz[i][j]);
        printf("\n");
    }
}

int main() {
    int a[L][L], b[L][L];//, res[L][L]; //matrizes

    fill(a);
    fill(b);
    printf("Matriz A: \n");
    printMatriz(a);
    printf("\n\nMatriz B: \n");
    printMatriz(b);
}