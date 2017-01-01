include alloc.inc

public	_chkstk
public	_alloca_probe

	.code

_chkstk:
_alloca_probe:

	mov	[rsp-8],rcx
	lea	rcx,[rsp+8]
@@:
	cmp	rax,1000h	; probe pages
	jb	@F
	sub	rcx,1000h
	test	[rcx],rax
	sub	rax,1000h
	jmp	@B
@@:
	sub	rcx,rax
	and	rcx,-16		; align 16
	test	[rcx],rax	; probe page
	mov	rax,rsp
	mov	rsp,rcx
	mov	rcx,[rax-8]
	mov	rax,[rax]
	jmp	rax

	end
