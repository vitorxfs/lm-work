    .text

    .global maior_valor_diagonal

maior_valor_diagonal:
    push %ebp
    mov %esp, %ebp
    push %ebx
    push %ecx

    mov 8(%ebp), %ecx
    mov 12(%ebp), %ebx

    mov 1, %eax
    add %ecx, %eax
    add %eax, %eax
    add %eax, %eax

    dec %ecx

    xor %esi, %esi
    mov %eax, %esi

    mov 0, %edi

loop:
    mov %esi, %eax
    mul %ecx
    cmp (%ebx, %eax), %edi
    ja continue
    mov (%ebx, %eax), %edi
continue:
    dec %ecx
    jns loop

    mov %edi, %eax

    pop %ecx
    pop %ebx

    mov %ebp, %esp
    pop %ebp
    ret
    