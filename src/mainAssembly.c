// Seja A e B duas matrizes de inteiros de tamanho L x L
// realizar a operação (A x 2B), 
// retornando o maior valor da diagonal principal.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define o tamanho da matriz
#define L 4


//preenche matriz com valores aleatórios
void fill(int matriz[L][L]){ 
    int i, j; 

    for(i=0; i<L; i++)
        for(j=0; j<L; j++)
            matriz[i][j] = rand()%10;

}

//imprime uma matriz na tela
void printMatriz(int matriz[L][L]){ 
    int i, j;
    for(i=0; i<L; i++){
        for(j=0; j<L; j++)
            printf("%d  ", matriz[i][j]);
        printf("\n");
    }
}

int main() {
    int res[L][L] = {0}; //matrizes

    clock_t mult_val_matrixStart, mult_val_matrixEnd, mult_mat_matStart, mult_mat_matEnd, maior_valor_diagonalStart, maior_valor_diagonalEnd;
    double timeSpent;

    int a[L][L] = {{1,0,8,1}, {8,5,7,8}, {4,8,7,1}, {5,4,7,0}}; //teste
    int b[L][L] = {{5,3,2,4}, {1,0,8,6}, {5,1,5,6}, {2,3,7,1}}; //teste

    int soma;
    int maiorDiag;

    extern int mult_val_matrix(int, int, int *);
    extern int maior_valor_diagonal(int, int *);
    extern int mult_mat_mat(int, int *, int *, int *, int);

    srand(time(NULL));
    
    //fill(a);
    //fill(b);
    printf("Matriz A: \n");
    printMatriz(a);
    printf("\n\nMatriz B: \n");
    printMatriz(b);

    
    /***********************************************************************/
    /********************  MULTIPLICAÇÃO MATRIZ ESCALAR ********************/
    /***********************************************************************/
    mult_val_matrixStart = clock(); //Início da contagem do tempo de execução da função mult_val_matrix   

    mult_val_matrix(L, 2, *b);

    mult_val_matrixEnd = clock(); //Início da contagem do tempo de execução da função mult_val_matrix
    timeSpent = (double)(mult_val_matrixEnd - mult_val_matrixStart) / CLOCKS_PER_SEC;

    printf("\n\nNova Matriz B: \n");
    printMatriz(b); 
    printf("\nTempo de execucao para funcao mult_val_matrix em Assembly: %lf segundos \n\n", timeSpent);

    /***********************************************************************/
    /***********************************************************************/
    /***********************************************************************/



    /***********************************************************************/
    /********************  MULTIPLICAÇÃO ENTRE MATRIZES ********************/
    /***********************************************************************/
    mult_mat_matStart = clock();
    mult_mat_mat(L, *a, *b, *res, soma);
    mult_mat_matEnd = clock();
    timeSpent = (double)(mult_mat_matEnd - mult_mat_matStart) / CLOCKS_PER_SEC;

    printf("\n\nResultado: \n");
    printMatriz(res);

    printf("\nTempo de execucao para funcao mult_mat_mat em Assembly: %lf segundos \n\n", timeSpent);

    /***********************************************************************/
    /***********************************************************************/
    /***********************************************************************/



    /***********************************************************************/
    /********************  MAIOR VALOR DIAGONAL PRINCIPAL ******************/
    /***********************************************************************/
    maior_valor_diagonalStart = clock();

    maiorDiag = maior_valor_diagonal(L, *a);

    maior_valor_diagonalEnd = clock();

    printf("\nMaior valor da diagonal principal: %d \n", maiorDiag);
    timeSpent = (double)(maior_valor_diagonalEnd - maior_valor_diagonalStart) / CLOCKS_PER_SEC;
    printf("\nTempo de execucao para funcao maior_valor_diagonal em Assembly: %lf segundos \n\n", timeSpent);

    /***********************************************************************/
    /***********************************************************************/
    /***********************************************************************/
 
    
}

/*
Valores de teste utilizados:

Matriz A:
1  0  8  1  
8  5  7  8  
4  8  7  1  
5  4  7  0

Matriz B:
5  3  2  4  
1  0  8  6  
5  1  5  6  
2  3  7  1 

O resultado a partir dos valores de teste deve ser:

94   28   98   106  
192  110  294  224  
130  44   228  214  
128  44   154  172 

Sendo 288 o maior valor da diagonal principal.

*/