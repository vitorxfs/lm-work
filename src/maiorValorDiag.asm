    ; [ebp+12] é o tamanho da matriz
    ; [ebp+8] é o endereço do primeiro elemento da matriz

    SECTION .data

    SECTION .text

    global maior_valor_diagonal

maior_valor_diagonal:
    push ebp
    mov ebp, esp
    push ebx
    push ecx

    mov ecx, [ebp+8]
    mov ebx, [ebp+12]

    mov eax, 1
    add eax, ecx ; L+1
    add eax, eax ; (L+1)*2
    add eax, eax ; (L+1)*4
    
    dec ecx

    xor esi, esi
    mov esi, eax ; esi faz referência a (L+1)*4

    mov edi, 0

loop:
    mov eax, esi
    mul ecx
    cmp edi, [ebx+eax]
    ja continue
    mov edi, [ebx+eax]
continue:
    dec ecx
    jns loop

    mov eax, edi

    pop ecx
    pop ebx

    mov esp, ebp
    pop ebp
    ret
