nasm -f elf -o mult.o mult.asm
gcc -m32 -o main.out main.c mult.o