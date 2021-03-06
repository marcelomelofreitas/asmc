include stdio.inc
include io.inc
include errno.inc
include string.inc

    .code

    option win64:rsp nosave

perror proc uses rdi string:LPSTR
    mov rax,rcx
    .if rax
	mov rdi,rax
	mov al,[rdi]
	.if al

	    _write(2, rdi, strlen(rdi))
	    _write(2, ": ", 2)

	    lea rax,sys_errlist
	    mov edi,errno
	    shl edi,3
	    add rdi,rax
	    mov rdi,[rdi]

	    strlen(rdi)
	    _write(2, rdi, eax)
	    _write(2, "\n", 1)
	.endif
    .endif
    ret
perror endp

    END
