include consx.inc

    .code

dllevent proc ldlg:ptr S_DOBJ, listp:ptr S_LOBJ
    push tdllist
    mov eax,listp
    mov tdllist,eax
    dlevent(ldlg)
    pop ecx
    mov tdllist,ecx
    ret
dllevent endp

    END
