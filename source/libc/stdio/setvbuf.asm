include stdio.inc
include alloc.inc
include limits.inc

	.code

	ASSUME	ebx: LPFILE

setvbuf PROC USES esi ebx,
	fp:	LPFILE,
	buf:	LPSTR,
	tp:	SIZE_T,
	bsize:	SIZE_T

	mov	ebx,fp
	mov	eax,tp
	mov	ecx,bsize
	.if	eax != _IONBF && (ecx < 2 || ecx > INT_MAX || (eax != _IOFBF && eax != _IOLBF))
		mov	eax,-1
		jmp	toend
	.endif
	fflush( ebx )
	_freebuf( ebx )
	mov	esi,[ebx].iob_flag
	and	esi,not (_IOMYBUF or _IOYOURBUF or _IONBF or _IOSETVBUF or _IOFEOF or _IOFLRTN or _IOCTRLZ)
	mov	eax,tp
	.if	eax & _IONBF
		or	esi,_IONBF
		lea	eax,[ebx].iob_charbuf
		mov	buf,eax
		mov	bsize,4
	.elseif buf == 0
		.if	!malloc( bsize )
			mov	eax,-1
			jmp	toend
		.endif
		mov	buf,eax
		or	esi,_IOMYBUF or _IOSETVBUF
	.else
		or	esi,_IOYOURBUF or _IOSETVBUF
	.endif
	mov	[ebx].iob_flag,esi
	mov	eax,bsize
	mov	[ebx].iob_bufsize,eax
	mov	eax,buf
	mov	[ebx].iob_ptr,eax
	mov	[ebx].iob_base,eax
	xor	eax,eax
	mov	[ebx].iob_cnt,eax
toend:
	ret
setvbuf ENDP

	END