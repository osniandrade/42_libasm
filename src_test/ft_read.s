section .data
    text1 db "Hello Dad",10,0

section .text
    ;global ft_read
    global _start

_start:
    mov rax, 0
    mov rdi, 3
    mov rsi, text1
    mov rdx, 10
    call ft_read

    mov rax, 60
    mov rdi, 0
    syscall

ft_read:
    call _test

    mov rax, 0
    syscall
    ret

_test:
    test    rdi, rdi  ; if fd < 0
    js      _error

    test    rsi, rsi  ; if *buf = NULL
    jz      _error

    test    rdx, rdx  ; if count < 0
    js      _error
    
    push    rdx       ; store count in stack
    mov     rdx, 0
    js      _error
    mov     rax, 0
    syscall
    pop     rdx

    test    rax, rax  ; if ret != 0
    jne      _error
    ret

_error:
    mov     rax, -1
    ret