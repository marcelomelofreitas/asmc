include malloc.inc

    .data
    core dq 20 dup(?)
    diff dq 20 dup(?)
    memp dq 20 dup(?)
    .code
    getcore macro i
	call __coreleft
	mov core[i*8],rax
	endm
    getmemp macro i,z
	invoke malloc,z
	mov memp[i*8],rax
	.assert rax
	endm
    setdiff macro i,x
	mov rax,core
	sub rax,core[x*8]
	mov diff[i*8],rax
	endm
    getcdm macro i,d,m
	getcore i
	setdiff d,d+1
	getmemp m,64000
	endm

main proc

  local stk:qword

    mov stk,rsp
    .assert malloc(8)
    .assert free(rax)
    getcore 0

    .assert _aligned_malloc(_SEGSIZE_, _SEGSIZE_)
    .assert ax == 0
    .assert free(rax)

    getmemp 0,124
    getcore 1
    setdiff 0,1
    .assert rax
    free(memp)

    getcore 2
    setdiff 1,2
    .assert !rax

    getmemp 1,65531
    getcore 3
    setdiff 2,3
    free(memp[1*8])

    getcore 4
    setdiff 3,4
    .assert !rax

    getmemp 2,64000
    getcdm  5,4,3
    getcdm  6,5,4
    getcdm  7,6,5
    getcdm  8,7,6
    getcdm  9,8,7
    getcdm  10,9,8
    getcore 11
    setdiff 10,11
    getmemp 9,32000
    getcore 12
    setdiff 11,12
    getmemp 10,16000
    getcore 13
    setdiff 12,13
    free(memp[2*8])
    free(memp[3*8])
    free(memp[4*8])
    free(memp[5*8])
    free(memp[6*8])
    free(memp[7*8])
    free(memp[8*8])
    free(memp[9*8])
    free(memp[10*8])
    getcore 14
    setdiff 13,14
    .assert !rax

    .assert malloc(_HEAP_GROWSIZE*2)
    .assert free(rax)

    mov rsp,stk
    xor rax,rax
    ret

main endp

    end
