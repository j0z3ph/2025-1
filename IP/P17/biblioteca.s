	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 13, 1
	.globl	_imprimehastan                  ## -- Begin function imprimehastan
	.p2align	4, 0x90
_imprimehastan:                         ## @imprimehastan
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	_imprimehastan.i(%rip), %eax
	cmpl	-4(%rbp), %eax
	jg	LBB0_2
## %bb.1:
	movl	_imprimehastan.i(%rip), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	_imprimehastan.i(%rip), %eax
	addl	$1, %eax
	movl	%eax, _imprimehastan.i(%rip)
	movl	-4(%rbp), %edi
	callq	_imprimehastan
LBB0_2:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__DATA,__data
	.p2align	2                               ## @imprimehastan.i
_imprimehastan.i:
	.long	1                               ## 0x1

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%i "

.subsections_via_symbols
