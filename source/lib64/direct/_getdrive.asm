include errno.inc
include winbase.inc

    .code

_getdrive proc

  local b[512]:byte

    .if GetCurrentDirectoryA(512, &b)

        mov ax,word ptr b
        .if ah == ':'

            movzx eax,al
            or    al,0x20
            sub   al,'a' - 1  ; A: == 1
        .else
            xor eax,eax
        .endif
    .else
        osmaperr()
    .endif
    ret

_getdrive endp

    END
