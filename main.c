// Seja A e B duas matrizes de inteiros de tamanho L x L
// realizar a operação (A x 2B), 
// retornando o maior valor da diagonal principal.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define o tamanho da matriz
#define L 4

//retorna o maior valor da diagonal principal
int maiorValorDiagonalPrincipal(int matriz[L][L]){
    int i, j, maior;
    maior = 0;
    for(i=0; i<L; i++)
        maior = (matriz[i][i] > maior) ? matriz[i][i] : maior;
    return maior;
}

//multiplica uma matriz por um valor inteiro
void multMatValue(int b[L][L], int valor){ 
    int i, j;
    for(i=0; i<L; i++)
        for(j=0; j<L; j++)
            b[i][j] *= valor;
}

//multiplica duas matrizes
void multMatMat(int a[L][L], int b[L][L], int res[L][L]){ 
    int i, j, k, sum;
    for(i=0; i<L; i++)
        for(j=0; j<L; j++){
            sum = 0;
            for (k=0; k<L; k++){
                sum += a[i][k] * b[k][j];
            }
            res[i][j] = sum;
        }
}

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
    int res[L][L]; //matrizes
    int bres[L][L];

    int a[L][L] = {{1,0,8,1}, {8,5,7,8}, {4,8,7,1}, {5,4,7,0}}; //teste
    int b[L][L] = {{5,3,2,4}, {1,0,8,6}, {5,1,5,6}, {2,3,7,1}}; //teste

    srand(time(NULL));
    
    //fill(a);
    //fill(b);
    printf("Matriz A: \n");
    printMatriz(a);
    printf("\n\nMatriz B: \n");
    printMatriz(b);


    clock_t mult_val_matrixStart = clock(); //Início da contagem do tempo de execução da função mult_val_matrix
    
    //multMatValue(b, 2);
    extern int mult_val_matrix(int, int, int *);
    mult_val_matrix(L, 2, *b); //NASM


    /****  TEMPO DE EXECUÇÃO  *****/

    clock_t mult_val_matrixEnd = clock(); //Início da contagem do tempo de execução da função mult_val_matrix
    double mult_val_matrixTimeSpent = (double)(mult_val_matrixEnd - mult_val_matrixStart) / CLOCKS_PER_SEC; 
    printf("Execution time for function mult_val_matrix: %lf \n\n", mult_val_matrixTimeSpent);
    
    /*******************************/


    printf("\n\nNova Matriz B: \n");
    printMatriz(b);

    // multMatMat(a, b, res);


    // printf("\n\nResultado: \n");
    // printMatriz(res);
    
    // printf("\nO maior valor da diagonal principal é: %d\n", maiorValorDiagonalPrincipal(res));

    
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