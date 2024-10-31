	.file	"biblioteca.c"
	.section .rdata,"dr"
LC0:
	.ascii "%i \0"
	.text
	.globl	_imprimehastan
	.def	_imprimehastan;	.scl	2;	.type	32;	.endef
_imprimehastan:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	_i.2371, %eax
	cmpl	8(%ebp), %eax
	jg	L3
	movl	_i.2371, %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	_i.2371, %eax
	addl	$1, %eax
	movl	%eax, _i.2371
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_imprimehastan
L3:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.globl	__generar
	.def	__generar;	.scl	2;	.type	32;	.endef
__generar:
LFB16:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	_i.2376, %eax
	cmpl	8(%ebp), %eax
	jge	L6
	movl	_i.2376, %eax
	leal	0(,%eax,4), %edx
	movl	12(%ebp), %eax
	leal	(%edx,%eax), %ebx
	call	_rand
	movl	%eax, %ecx
	movl	$1098413215, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$8, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$1001, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, (%ebx)
	movl	_i.2376, %eax
	addl	$1, %eax
	movl	%eax, _i.2376
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__generar
L6:
	nop
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE16:
	.globl	_generar
	.def	_generar;	.scl	2;	.type	32;	.endef
_generar:
LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$0, (%esp)
	call	_time
	movl	%eax, (%esp)
	call	_srand
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__generar
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE17:
	.globl	__imprime
	.def	__imprime;	.scl	2;	.type	32;	.endef
__imprime:
LFB18:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	_i.2385, %eax
	cmpl	12(%ebp), %eax
	jge	L10
	movl	_i.2385, %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	_i.2385, %eax
	addl	$1, %eax
	movl	%eax, _i.2385
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__imprime
L10:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE18:
	.section .rdata,"dr"
LC1:
	.ascii "[ \0"
	.text
	.globl	_imprime
	.def	_imprime;	.scl	2;	.type	32;	.endef
_imprime:
LFB19:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$LC1, (%esp)
	call	_printf
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__imprime
	movl	$93, (%esp)
	call	_putchar
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE19:
	.globl	__encuentraElMasGrande
	.def	__encuentraElMasGrande;	.scl	2;	.type	32;	.endef
__encuentraElMasGrande:
LFB20:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	_i.2395, %eax
	cmpl	$9, %eax
	jg	L15
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	_i.2395, %edx
	leal	0(,%edx,4), %ecx
	movl	8(%ebp), %edx
	addl	%ecx, %edx
	movl	(%edx), %edx
	cmpl	%edx, %eax
	jge	L14
	movl	%edx, %eax
L14:
	movl	16(%ebp), %edx
	movl	%eax, (%edx)
	movl	_i.2395, %eax
	addl	$1, %eax
	movl	%eax, _i.2395
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__encuentraElMasGrande
L15:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE20:
	.section .rdata,"dr"
LC2:
	.ascii "\12El mas grande es: %i\12\0"
	.text
	.globl	_encuentraElMasGrande
	.def	_encuentraElMasGrande;	.scl	2;	.type	32;	.endef
_encuentraElMasGrande:
LFB21:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$-2147483647, -12(%ebp)
	leal	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__encuentraElMasGrande
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE21:
	.globl	_cuentaDigitos
	.def	_cuentaDigitos;	.scl	2;	.type	32;	.endef
_cuentaDigitos:
LFB22:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 8(%ebp)
	je	L18
	movl	8(%ebp), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, 8(%ebp)
	movl	_contador.2404, %eax
	addl	$1, %eax
	movl	%eax, _contador.2404
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_cuentaDigitos
L18:
	movl	_contador.2404, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE22:
	.data
	.align 4
_i.2371:
	.long	1
.lcomm _i.2376,4,4
.lcomm _i.2385,4,4
.lcomm _i.2395,4,4
.lcomm _contador.2404,4,4
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_rand;	.scl	2;	.type	32;	.endef
	.def	_time;	.scl	2;	.type	32;	.endef
	.def	_srand;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
