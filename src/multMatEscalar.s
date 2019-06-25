    .text

    .global mult_val_matrix

mult_val_matrix:
    push %ebp
    mov %esp, %ebp

    xor %edx, %edx
    mov 8(%ebp), %ecx
    mov 12(%ebp), %edi
    mov 16(%ebp), %esi


    mov %ecx, %eax
    mul %ecx
    xchg %ecx, %eax
    dec %ecx

lp:
    mov (%esi,%ecx,0x4), %eax
    mul %edi
    mov %eax, (%esi,%ecx,0x4)
    dec %ecx
    jns lp

    mov %ebp, %esp
    pop %ebp
    ret
    