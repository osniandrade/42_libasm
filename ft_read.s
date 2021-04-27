section     .text
    global  ft_read

ft_read:

    mov     rax, 0
    syscall
    cmp     rax, 0
    jl      _finish
    ret

_finish:
    mov     rax, -1
    ret