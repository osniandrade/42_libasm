section     .text
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
    jmp     _finish

_finish:
    pop     r8
    sub     rax, rbx
    ret