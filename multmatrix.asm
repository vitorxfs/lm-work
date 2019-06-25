    SECTION .text

global mult_mat_mat
mult_mat_mat:
    
    push ebp
    mov ebp, esp
    push ebx

    mov eax, [ebp+8]
    mov ebx, eax
    dec ebx           ; L-1 (i counter)

  loop_i:
    mov ecx, [ebp+8]
    dec ecx
    loop_j:
        mov esi, [ebp+8]
        dec esi
        push ecx
        mov ecx, 0
        mov [ebp+24], ecx
        pop ecx
        loop_k:

            mov eax, [ebp+8]  ; L
            mul ebx
            add eax, esi ;(i*L)+k

            mov edi, 4
            mul edi    ; * 4 bytes per int

            push ebx
            mov ebx, [ebp+12] ;matriz A
            add eax, ebx
            mov ebx, [eax]



            mov eax, [ebp+8]
            mul esi
            add eax, ecx    ; (k*L)+j

            push ecx
            mov ecx, 4
            mul ecx     ; * 4 bytes per int
            pop ecx

            mov edi, eax
            push ebx
            mov ebx, [ebp+16] ;matriz B
            add edi, ebx
            pop ebx

            mov eax, [edi] 

            mul ebx ; eax has elem mult

            add eax, [ebp+24]
            mov [ebp+24], eax

            pop ebx
            
 
            dec esi
        jns loop_k

        push esi
        mov esi, [ebp+24]
        push edi
        mov edi, [ebp+20]
        push eax

        xor eax, eax
        mov eax, [ebp+8]
        mul ebx
        add eax, ecx    ;(i*L)+j

        push ecx
        mov ecx, 4
        mul ecx
        pop ecx


        mov [edi+eax], esi

        pop eax
        pop edi
        pop esi
        dec ecx   ; loop_j counter
    jns loop_j ; loop L times
    dec ebx   ; loop_i counter
  jns loop_i    ; loop L times

  end:

    pop ebx
    mov esp, ebp
    pop ebp
    ret

