include string.inc

	.code

	OPTION	WIN64:0, STACKBASE:rsp

_strlwr PROC string:LPSTR
	mov	r10,rcx
	.while	1
		mov	al,[rcx]
		.break .if !al
		sub	al,'A'
		cmp	al,'Z' - 'A' + 1
		sbb	al,al
		and	al,'a' - 'A'
		xor	[rcx],al
		inc	rcx
	.endw
	mov	rax,r10
	ret
_strlwr ENDP

	END
