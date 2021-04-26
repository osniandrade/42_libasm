section .text
    global  ft_strcmp

ft_strcmp:
    push    r8
    mov     r8, -1

_while:
    inc     r8
    mov     al, byte [rdi + r8]
    mov     bl, byte [rsi + r8]
    cmp     al, 0
    je      _finish
    cmp     bl, 0
    je      _finish
    cmp     al, bl
    je      _while

_finish:
    pop     r8
    sub     al, bl
    cmp     al, 0
    jg      _bigger
    jl      _lower
    ret

_bigger:
    mov     rax, 1
    ret

_lower:
    mov     rax, -1
    ret