include stdlib.inc
include crtl.inc
include winbase.inc

.data
__argv	dq 0
_pgmptr dq 0

.code

Install proc private
    mov __argv,setargv(addr __argc, GetCommandLineA())
    mov rcx,[rax]
    mov _pgmptr,rcx
    ret
Install endp

pragma_init Install, 4

    end
