global _start

section .text

_start:
        ; move data to rax register
        ; mov [destination], [source]
        mov rax, 10

        ; move data to rbx register
        mov rbx, 5

        ; sums the values of two registers
        add rax, rbx

        mov rbx, 20
        add rax, rbx

        mov rbx, 35
        add rax, rbx

        ; exit syscall
        mov rax, 1
        int 0x80