; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/04/18 09:05:02 by ocarlos-          #+#    #+#              ;
;    Updated: 2021/01/01 16:26:04 by ocarlos-         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

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