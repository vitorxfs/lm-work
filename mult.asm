;     SECTION .data

; a: db 1,0,8,1,8,5,7,8,4,8,7,1,5,4,7,0
; b: db 5,3,2,4,1,0,8,6,5,1,5,6,2,3,7,1

; v: db 2

    SECTION .text

global mult_val_matrix

mult_val_matrix:
    push ebp
    mov ebp, esp

    mov ecx, [ebp+8]   ; L
    mov ebx, [ebp+12]  ; escalar(2)
    mov esi, [ebp+16]  ; matriz[0][0]

    mov eax, ecx
    mul ecx
    xchg ecx, eax
    dec ecx

  lp:
    mov eax, [esi+ecx*4]
    mul bx
    mov [esi+ecx*4], eax
    dec ecx
    jns lp                  ;itera de (LxL)-1 até 0

    mov esp, ebp
    pop ebp
    ret
