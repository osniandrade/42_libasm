; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/04/18 09:05:02 by ocarlos-          #+#    #+#              ;
;    Updated: 2021/01/01 16:26:04 by ocarlos-         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section     .text
    global  ft_read
    extern  __errno_location

ft_read:

    mov     rax, 0
    syscall
    cmp     rax, 0
    jl      _error
    ret

_error:
    neg     rax
    mov     rdi, rax
    call    __errno_location
    mov     [rax], rdi
    mov     rax, -1
    ret