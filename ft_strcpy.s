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
    global  ft_strcpy

ft_strcpy:
    mov     rax, 0

_while:
    mov     cl, byte [rsi + rax]
    mov     byte [rdi + rax], cl
    inc     rax
    cmp     cl, 0
    je      _finish
    jmp     _while

_finish:
    movsx   rax, cl
    movsx   rdx, dl
    mov     rax, rdi
    ret