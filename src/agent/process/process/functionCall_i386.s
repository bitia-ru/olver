.globl functionLongValuesCall
functionLongValuesCall:
        pushl   %ebp
        movl    %esp, %ebp
        pushl   %ebx
        movl    8(%ebp), %ebx
L1:     cmpl    $1, %ebx
        je      L2
        movl    %ebx, %eax
        decl    %eax
        imull   $4, %eax
        addl    12(%ebp), %eax
        movl    (%eax), %eax
        pushl   %eax
        decl    %ebx
        jmp     L1
L2:     movl    12(%ebp), %eax
        movl    (%eax), %eax
        call    *%eax
        movl    %ebp, %esp
        subl    $4, %esp
        popl    %ebx
        popl    %ebp
        ret
