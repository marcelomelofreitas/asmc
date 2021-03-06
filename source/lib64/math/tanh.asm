
include math.inc
include immintrin.inc

    .code

    option win64:nosave

tanh proc x:double

    .if _mm_comigt_sd(xmm0, FLT8(50.0))

        _mm_move_sd(xmm0, FLT8(1.0))
    .else

        _mm_move_sd(xmm2, FLT8(-50.0))
        _mm_move_pd(xmm1, xmm0)
        _mm_move_sd(xmm0, FLT8(-1.0))

        .if _mm_comile_sd(xmm2, xmm1)

            exp(xmm1)
            _mm_move_sd(xmm2, FLT8(1.0))
            _mm_move_pd(xmm1, xmm0)
            _mm_div_sd(xmm2, xmm0)
            _mm_add_sd(xmm0, xmm2)
            _mm_sub_sd(xmm1, xmm2)
            _mm_div_sd(xmm1, xmm0)
            _mm_move_pd(xmm0, xmm1)
        .endif
    .endif
    ret

tanh endp

    end
