
include quadmath.inc

    .code

    option win64:rsp nosave noauto

fminq proc vectorcall A:XQFLOAT, B:XQFLOAT

    .ifd cmpq(xmm0, xmm1) == 1

        movaps xmm0,xmm1
    .endif
    ret

fminq endp

    end
