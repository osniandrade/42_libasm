section .text
    global ft_read

ft_read:
    test    rdi, rdi  ; if fd < 0
    js      _error
    test    rsi, rsi  ; if *buf = NULL
    jz      _error
    test    rdx, rdx  ; if count < 0
    push    rdx       ; store count in stack
    mov     rdx, 0
    js      _error
    mov     rax, 0
    syscall
    pop     rdx
    test    rax, rax  ; if ret != 0
    jne      _error

    mov rax, 0
    syscall
    ret

_error:
    mov     rax, -1
    ret