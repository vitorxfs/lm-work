nasm -f elf -o mult.o mult.asm
nasm -f elf -o multmatrix.o multmatrix.asm
gcc -m32 -o main.out main.c mult.o multmatrix.o