	.file	"employer.c"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	call	connect_employer
	movq	%rax, %rbx
	movl	$1, %eax
	testq	%rbx, %rbx
	je	.L2
	movq	%rbx, %rdi
	call	add_employer
	movq	%rbx, %rdi
	call	get_employer
	movq	%rbx, %rdi
	call	PQfinish
	xorl	%eax, %eax
.L2:
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.4) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
