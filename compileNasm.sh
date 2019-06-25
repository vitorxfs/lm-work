nasm -f elf -o mult.o mult.asm
nasm -f elf -o maiorValorDiag.o maiorValorDiag.asm
nasm -f elf -o multmatrix.o multmatrix.asm
gcc -m32 -o mainAssembly.out mainAssembly.c mult.o maiorValorDiag.o multmatrix.o
./mainAssembly.out