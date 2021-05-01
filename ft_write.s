section     .text
    global  ft_write
    extern  error

ft_write:
    mov     rax, 0x1
    syscall
    push    rax
    jc      _error
    pop     rax
    ret

_error:
    call    error
    mov     r10, rax
    pop     rax
    mov     [r10], rax
    mov     rax, -1
    ret