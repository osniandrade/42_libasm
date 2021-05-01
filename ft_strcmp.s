section     .text
    global  ft_strcmp

ft_strcmp:
    mov     r8, -1

_while:
    inc     r8
    mov     al, byte [rdi + r8]
    mov     bl, byte [rsi + r8]
    cmp     al, bl
    jne     _finish
    cmp     al, 0
    je      _finish
    cmp     bl, 0
    je      _finish
    je      _while

_finish:
    sub     al, bl
    movsx   rax, al
    ret