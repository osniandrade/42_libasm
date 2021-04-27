section     .text
    global  ft_strlen

ft_strlen:
    mov     rax, -1

_while:
    inc     rax
    cmp     byte [rdi + rax], 0
    jne     _while
    ret