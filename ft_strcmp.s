section     .text
    global  ft_strcmp

ft_strcmp:
    mov     rcx, 0

_while:
    mov     r8b, byte [rdi + rcx]
    mov     r9b, byte [rsi + rcx]
    inc     rcx
    cmp     r8b, r9b
    jne     _finish
    cmp     r8b, 0
    je      _finish
    cmp     r9b, 0
    je      _finish
    jmp     _while

_finish:
    sub     r8b, r9b
    movsx   rax, r8b
    ret