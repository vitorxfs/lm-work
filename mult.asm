    SECTION .text

global mult_val_matrix

mult_val_matrix:
    push ebp
    mov ebp, esp

    xor edx, edx
    mov ecx, [ebp+8]   ; L
    mov edi, [ebp+12] ; escalar(2)
    mov esi, [ebp+16]  ; matriz[0][0]
    

    mov eax, ecx
    mul ecx
    xchg ecx, eax
    dec ecx

  lp:
    mov eax, [esi+ecx*4]
    mul edi
    mov [esi+ecx*4], eax
    dec ecx
    jns lp                  ;itera de (LxL)-1 até 0

    mov esp, ebp
    pop ebp
    ret
