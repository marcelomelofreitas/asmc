; _COPYSIGN.ASM--
; Copyright (C) 2017 Asmc Developers
;
include float.inc

.code

_copysign proc x:REAL8, q:REAL8

    mov al,byte ptr q[7]
    and al,0x80
    and byte ptr x[7],0x7F
    or	byte ptr x[7],al
    fld x
    ret

_copysign endp

    end
