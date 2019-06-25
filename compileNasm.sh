nasm -f elf -o bin/multMatEscalar.o src/multMatEscalar.asm
nasm -f elf -o bin/maiorValorDiag.o src/maiorValorDiag.asm
nasm -f elf -o bin/multMatMat.o src/multMatMat.asm
gcc -m32 -o bin/mainAssembly.out src/mainAssembly.c bin/multMatEscalar.o bin/maiorValorDiag.o bin/multMatMat.o
./bin/mainAssembly.out