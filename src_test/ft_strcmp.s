section .data
    text1 db "\xff\xff",10,0
    text2 db "\xff",10,0

section .text
    global _start

_start:
    mov rdi, text1
    mov rsi, text2
    call _ft_strcmp

    mov rax, 60
    mov rdi, 0
    syscall

_ft_strcmp:
    mov     rcx, 0

_while:
    mov     r8b, byte [rdi + rcx]
    mov     r9b, byte [rsi + rcx]
    inc     rcx
    cmp     r8b, 0
    je      _finish
    cmp     r9b, 0
    je      _finish
    cmp     r8b, r9b
    jne     _finish
    jmp     _while

_finish:
    sub     r8b, r9b
    movsx   rax, r8b
    ret