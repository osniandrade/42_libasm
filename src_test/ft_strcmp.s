section .data
    text1 db "Hello boy",10,0
    text2 db "Hello boy",10,0

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
    sub     rax, rbx
    ret