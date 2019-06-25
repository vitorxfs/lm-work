 as --32 -o bin/multMatEscalar.o src/multMatEscalar.s
 as --32 -o bin/maiorValorDiag.o src/maiorValorDiag.s
 gcc -m32 -o bin/mainAssembly.out src/mainAssembly.c bin/multMatEscalar.o bin/maiorValorDiag.o
 ./bin/mainAssembly.out