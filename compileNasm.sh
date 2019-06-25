nasm -f elf -o bin/multMatEscalarG.o src/multMatEscalar.asm
nasm -f elf -o bin/maiorValorDiagG.o src/maiorValorDiag.asm
nasm -f elf -o bin/multMatMatG.o src/multMatMat.asm
gcc -m32 -o bin/mainAssembly.out src/mainAssembly.c bin/multMatEscalarG.o bin/maiorValorDiagG.o bin/multMatMatG.o
./bin/mainAssembly.out