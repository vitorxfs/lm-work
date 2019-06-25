 as --32 -o mult.o mult.s
 as --32 -o maiorValorDiag.o maiorValorDiag.s
 gcc -m32 -o main.out main.c mult.o maiorValorDiag.o