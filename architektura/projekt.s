	.file	"projekt.c"
	.section	.rodata
.LC0:
	.string	"fqr  b qabxx xryc pqr"
.LC1:
	.string	"%hd,%hd\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x74,0x6
	.cfi_escape 0x10,0x6,0x2,0x75,0x7c
	.cfi_escape 0x10,0x3,0x2,0x75,0x78
	subl	$28, %esp
	movl	$.LC0, -36(%ebp)
	movl	-36(%ebp), %edx
#APP
# 6 "projekt.c" 1
	.intel_syntax noprefix;xor eax,eax;xor ebx,ebx;xor ecx,ecx;mov ebx,%edx;petla:mov al,[ebx];sub al, 0;cmp al, 'q';jz wyjscie;inc ecx;inc ebx;jmp petla;wyjscie:mov %esi, eax;mov %edx,ecx;.att_syntax prefix;
# 0 "" 2
#NO_APP
	movl	%esi, -32(%ebp)
	movl	%edx, -28(%ebp)
	subl	$4, %esp
	pushl	-28(%ebp)
	pushl	-32(%ebp)
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	movl	$0, %eax
	leal	-12(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
