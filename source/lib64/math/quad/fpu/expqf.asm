
include quadmath.inc

    .code

expqf proc vectorcall Q:XQFLOAT

  local x:REAL10

    XQFLOATTOLD(x)

    fld x
    fxam
    fstsw ax
    fwait
    sahf

    .if PARITY? && CARRY?
        .if ah & 2
            fstp st
            fldz
        .endif
    .else
        fldl2e
        fmul    st,st(1)
        fst     st(1)
        frndint
        fxch    st(1)
        fsub    st,st(1)
        f2xm1
        fld1
        faddp   st(1),st
        fscale
        fstp    st(1)
    .endif

    LDTOXQFLOAT(x)
    ret

expqf endp

    end
