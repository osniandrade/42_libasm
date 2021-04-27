section     .text
    global  ft_strcpy

ft_strcpy:
    mov     rax, 0

_while:
    mov     cl, byte [rsi + rax]
    mov     byte [rdi + rax], cl
    inc     rax
    cmp     cl, 0
    je      _finish
    jmp     _while

_finish:
    movsx   rax, cl
    movsx   rdx, dl
    mov     rax, rdi
    ret