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
    global  ft_strlen

ft_strlen:
    mov     rax, -1

_while:
    inc     rax
    cmp     byte [rdi + rax], 0
    jne     _while
    ret