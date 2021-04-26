section .data
    text1 db "Hello boy",10,0

section .text
    global _start

_start:
    mov rdi, text1
    call ft_strlen

    mov rax, 60
    mov rdi, 0
    syscall

ft_strlen:
    mov         rax, -1

loop:
    inc         rax
    cmp byte    [rdi+rax], 0
    jne loop
    ret