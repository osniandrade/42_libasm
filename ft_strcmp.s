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
    global  ft_strcmp

ft_strcmp:
    mov     r8, -1

_while:
    inc     r8
    mov     al, byte [rdi + r8]
    mov     dl, byte [rsi + r8]
    cmp     al, 0
    je      _finish
    cmp     dl, 0
    je      _finish
    cmp     al, dl
    jne     _finish
    je      _while

_finish:
    sub     rax, rdx
    ret