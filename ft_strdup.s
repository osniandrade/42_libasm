section     .text
    extern  malloc
    extern  ft_strlen
    extern  ft_strcpy
    global  ft_strdup

ft_strdup:
    push    rdi
    call    ft_strlen
    inc     rax
    mov     rdi, rax
    call    malloc
    pop     rdi
    mov     rsi, rdi
    mov     rdi, rax
    call    ft_strcpy
    ret