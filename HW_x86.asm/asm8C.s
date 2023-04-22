	.file	"lab1.cpp"
	.ignore	ld_st_style
	.ignore	strict_delay
	.text
	.global	_Z10FillArrayAPA7_di
	.type	_Z10FillArrayAPA7_di, #function
	.align	8
_Z10FillArrayAPA7_di:
	.cfi_startproc
	{
	  setwd	wsz = 0xc, nfx = 0x1, dbl = 0x0
	  setbn	rsz = 0x3, rbs = 0x8, rcur = 0x0
	  getsp,0	_f16s,_lts1hi 0xfff0, %r3
	}
	{
	  adds,0,sm	0x0, 0x0, %r4
	}
.L5:
	{
	  nop 4
	  cmplsb,0	%r4, %r1, %pred0
	  disp	%ctpr1, .L7
	}
	{
	  ct	%ctpr1 ? ~%pred0
	}
.L10:
	{
	  adds,0,sm	0x0, 0x0, %r5
	}
.L12:
	{
	  nop 3
	  istofd,0	%r5, %r6
	  disp	%ctpr1, .L15
	}
	{
	  nop 4
	  fcmpltdb,0	%r6, _f64,_lts0 0x401c000000000000, %pred1
	}
	{
	  ct	%ctpr1 ? %pred1
	}
	{
	  nop 4
	  disp	%ctpr1, .L18
	}
	{
	  ct	%ctpr1
	}
.L15:
	{
	  sxt,0,sm	0x2, %r4, %r6
	  sxt,1,sm	0x2, %r5, %r7
	  istofd,3	%r4, %r8
	  addd,2,sm	0x0, _f64,_lts0 0x401c000000000000, %r9
	  istofd,4	%r5, %r10
	  addd,5,sm	0x0, _f64,_lts2 0x4022000000000000, %r11
	}
	{
	  sxt,0,sm	0x2, %r4, %r12
	  sxt,1,sm	0x2, %r5, %r13
	  addd,2,sm	0x0, [ _f64,_lts0 .LC.1 ], %b[0]
	  addd,3,sm	0x0, [ _f64,_lts2 .LC.1 ], %r14
	}
	{
	  nop 2
	  muld,0	%r6, _f16s,_lts0hi 0x38, %r6
	  shld,1	%r7, 0x3, %r7
	  muld,3	%r12, _f16s,_lts0lo 0x38, %r12
	  shld,2	%r13, 0x3, %r13
	}
	{
	  nop 2
	  fsubd,0	%r8, _f64,_lts0 0x3ff0000000000000, %r8
	  fsubd,1	%r10, _f64,_lts2 0x3ff0000000000000, %r10
	}
	{
	  addd,0	%r0, %r6, %r6
	  addd,1	%r0, %r12, %r12
	}
	{
	  addd,0	%r6, %r7, %r6
	  addd,1	%r12, %r13, %r7
	}
	{
	  nop 4
	  fmuld,0	%r9, %r8, %r8
	  fmuld,1	%r11, %r10, %r9
	}
	{
	  nop 3
	  faddd,0	%r8, %r9, %r8
	}
	{
	  nop 7
	  fdivd,5	%r8, _f64,_lts0 0x4014000000000000, %r8
	}
	{
	  nop 7
	}
	{
	  nop 1
	}
	{
	  std,2,sm	%r6, 0x0, %r8
	  ldd,5	%r7, 0x0, %r6
	}
	{
	  nop 2
	  std,2,sm	%r3, 0x0, %r14
	}
	{
	  addd,0,sm	0x0, %r6, %b[1]
	  std,2,sm	%r3, 0x8, %r6
	}
.LCS.1:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x8
	}
.LCS.2:
	{
	  nop 4
	  adds,0	%r5, 0x1, %r5
	  disp	%ctpr1, .L12
	}
	{
	  ct	%ctpr1
	}
.L18:
	{
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.2 ], %b[0]
	  addd,1,sm	0x0, [ _f64,_lts2 .LC.2 ], %r6
	}
	{
	  std,2,sm	%r3, 0x0, %r6
	}
.LCS.3:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x8
	}
.LCS.4:
	{
	  nop 4
	  adds,0	%r4, 0x1, %r4
	  disp	%ctpr1, .L5
	}
	{
	  ct	%ctpr1
	}
.L7:
	{
	  nop 5
	  return	%ctpr3
	}
	{
	  ct	%ctpr3
	}
	.cfi_endproc
	.size	_Z10FillArrayAPA7_di, .- _Z10FillArrayAPA7_di
	.global	_Z10FillArrayBPA7_di
	.type	_Z10FillArrayBPA7_di, #function
	.align	8
_Z10FillArrayBPA7_di:
	.cfi_startproc
	{
	  setwd	wsz = 0xc, nfx = 0x1, dbl = 0x0
	  setbn	rsz = 0x3, rbs = 0x8, rcur = 0x0
	  getsp,0	_f16s,_lts1hi 0xfff0, %r3
	}
	{
	  adds,0,sm	0x0, 0x0, %r4
	}
.L23:
	{
	  nop 4
	  cmplsb,0	%r4, %r1, %pred0
	  disp	%ctpr1, .L25
	}
	{
	  ct	%ctpr1 ? ~%pred0
	}
.L28:
	{
	  adds,0,sm	0x0, 0x0, %r5
	}
.L30:
	{
	  nop 3
	  istofd,0	%r5, %r6
	  disp	%ctpr1, .L33
	}
	{
	  nop 4
	  fcmpltdb,0	%r6, _f64,_lts0 0x401c000000000000, %pred1
	}
	{
	  ct	%ctpr1 ? %pred1
	}
	{
	  nop 4
	  disp	%ctpr1, .L36
	}
	{
	  ct	%ctpr1
	}
.L33:
	{
	  sxt,0,sm	0x2, %r4, %r6
	  sxt,1,sm	0x2, %r5, %r7
	  istofd,3	%r4, %r8
	  addd,2,sm	0x0, _f64,_lts0 0x4014000000000000, %r9
	  istofd,4	%r5, %r10
	  addd,5,sm	0x0, _f64,_lts2 0x4022000000000000, %r11
	}
	{
	  sxt,0,sm	0x2, %r4, %r12
	  sxt,1,sm	0x2, %r5, %r13
	  addd,2,sm	0x0, [ _f64,_lts0 .LC.1 ], %b[0]
	  addd,3,sm	0x0, [ _f64,_lts2 .LC.1 ], %r14
	}
	{
	  nop 2
	  muld,0	%r6, _f16s,_lts0hi 0x38, %r6
	  shld,1	%r7, 0x3, %r7
	  muld,3	%r12, _f16s,_lts0lo 0x38, %r12
	  shld,2	%r13, 0x3, %r13
	}
	{
	  nop 2
	  faddd,0	%r8, _f64,_lts0 0x3ff0000000000000, %r8
	  faddd,1	%r10, _f64,_lts2 0x3ff0000000000000, %r10
	}
	{
	  addd,0	%r0, %r6, %r6
	  addd,1	%r0, %r12, %r12
	}
	{
	  addd,0	%r6, %r7, %r6
	  addd,1	%r12, %r13, %r7
	}
	{
	  nop 4
	  fmuld,0	%r9, %r8, %r8
	  fmuld,1	%r11, %r10, %r9
	}
	{
	  nop 3
	  faddd,0	%r8, %r9, %r8
	}
	{
	  nop 7
	  fdivd,5	%r8, _f64,_lts0 0x401c000000000000, %r8
	}
	{
	  nop 7
	}
	{
	  nop 1
	}
	{
	  std,2,sm	%r6, 0x0, %r8
	  ldd,5	%r7, 0x0, %r6
	}
	{
	  nop 2
	  std,2,sm	%r3, 0x0, %r14
	}
	{
	  addd,0,sm	0x0, %r6, %b[1]
	  std,2,sm	%r3, 0x8, %r6
	}
.LCS.5:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x8
	}
.LCS.6:
	{
	  nop 4
	  adds,0	%r5, 0x1, %r5
	  disp	%ctpr1, .L30
	}
	{
	  ct	%ctpr1
	}
.L36:
	{
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.2 ], %b[0]
	  addd,1,sm	0x0, [ _f64,_lts2 .LC.2 ], %r6
	}
	{
	  std,2,sm	%r3, 0x0, %r6
	}
.LCS.7:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x8
	}
.LCS.8:
	{
	  nop 4
	  adds,0	%r4, 0x1, %r4
	  disp	%ctpr1, .L23
	}
	{
	  ct	%ctpr1
	}
.L25:
	{
	  nop 5
	  return	%ctpr3
	}
	{
	  ct	%ctpr3
	}
	.cfi_endproc
	.size	_Z10FillArrayBPA7_di, .- _Z10FillArrayBPA7_di
	.global	_Z7ComparePA7_dS0_S0_i
	.type	_Z7ComparePA7_dS0_S0_i, #function
	.align	8
_Z7ComparePA7_dS0_S0_i:
	.cfi_startproc
	{
	  setwd	wsz = 0xa, nfx = 0x1, dbl = 0x0
	  setbn	rsz = 0x3, rbs = 0x6, rcur = 0x0
	  getsp,0	_f16s,_lts1hi 0xfff0, %r5
	}
	{
	  adds,0,sm	0x0, 0x0, %r6
	}
.L41:
	{
	  nop 4
	  cmplsb,0	%r6, %r3, %pred0
	  disp	%ctpr1, .L43
	}
	{
	  ct	%ctpr1 ? ~%pred0
	}
.L46:
	{
	  adds,0,sm	0x0, 0x0, %r7
	}
.L48:
	{
	  nop 3
	  istofd,0	%r7, %r8
	  disp	%ctpr1, .L51
	}
	{
	  nop 4
	  fcmpltdb,0	%r8, _f64,_lts0 0x401c000000000000, %pred1
	}
	{
	  ct	%ctpr1 ? %pred1
	}
	{
	  nop 4
	  disp	%ctpr1, .L54
	}
	{
	  ct	%ctpr1
	}
.L51:
	{
	  nop 4
	  disp	%ctpr1, .L57
	}
	{
	  ct	%ctpr1
	}
.L60:
	{
	  sxt,0,sm	0x2, %r6, %r8
	  sxt,1,sm	0x2, %r7, %r9
	  sxt,2,sm	0x2, %r6, %r10
	  sxt,3,sm	0x2, %r7, %r11
	  disp	%ctpr1, .L76
	}
	{
	  nop 5
	  muld,0	%r8, _f16s,_lts0hi 0x38, %r8
	  shld,1	%r9, 0x3, %r9
	  muld,3	%r10, _f16s,_lts0lo 0x38, %r10
	  shld,2	%r11, 0x3, %r11
	}
	{
	  addd,0	%r0, %r8, %r8
	  addd,1	%r1, %r10, %r10
	}
	{
	  addd,0	%r8, %r9, %r8
	  addd,1	%r10, %r11, %r9
	}
	{
	  ldd,0	%r9, 0x0, %r9
	}
	{
	  nop 2
	  ldd,0	%r8, 0x0, %r8
	}
	{
	  nop 4
	  fcmpltdb,0	%r9, %r8, %pred2
	}
	{
	  ct	%ctpr1 ? %pred2
	}
	{
	  nop 4
	  disp	%ctpr1, .L79
	}
	{
	  ct	%ctpr1
	}
.L76:
	{
	  sxt,0,sm	0x2, %r6, %r8
	  sxt,1,sm	0x2, %r7, %r9
	  sxt,2,sm	0x2, %r6, %r10
	  sxt,3,sm	0x2, %r7, %r11
	  disp	%ctpr1, .L96
	}
	{
	  nop 5
	  muld,0	%r8, _f16s,_lts0hi 0x38, %r8
	  shld,1	%r9, 0x3, %r9
	  muld,3	%r10, _f16s,_lts0lo 0x38, %r10
	  shld,2	%r11, 0x3, %r11
	}
	{
	  addd,0	%r2, %r8, %r8
	  addd,1	%r0, %r10, %r10
	}
	{
	  addd,0	%r8, %r9, %r8
	  addd,1	%r10, %r11, %r9
	}
	{
	  nop 2
	  ldd,0	%r9, 0x0, %r9
	}
	{
	  std,2,sm	%r8, 0x0, %r9
	  ct	%ctpr1
	}
.L79:
	{
	  sxt,0,sm	0x2, %r6, %r8
	  sxt,1,sm	0x2, %r7, %r9
	  sxt,2,sm	0x2, %r6, %r10
	  sxt,3,sm	0x2, %r7, %r11
	}
	{
	  nop 5
	  muld,0	%r8, _f16s,_lts0hi 0x38, %r8
	  shld,1	%r9, 0x3, %r9
	  muld,3	%r10, _f16s,_lts0lo 0x38, %r10
	  shld,2	%r11, 0x3, %r11
	}
	{
	  addd,0	%r2, %r8, %r8
	  addd,1	%r1, %r10, %r10
	}
	{
	  addd,0	%r8, %r9, %r8
	  addd,1	%r10, %r11, %r9
	}
	{
	  nop 2
	  ldd,0	%r9, 0x0, %r9
	}
	{
	  std,2,sm	%r8, 0x0, %r9
	}
.L96:
	{
	  sxt,0,sm	0x2, %r6, %r8
	  sxt,1,sm	0x2, %r7, %r9
	  addd,2,sm	0x0, [ _f64,_lts0 .LC.1 ], %b[0]
	  addd,3,sm	0x0, [ _f64,_lts2 .LC.1 ], %r10
	}
	{
	  nop 5
	  muld,0	%r8, _f16s,_lts0hi 0x38, %r8
	  shld,1	%r9, 0x3, %r9
	}
	{
	  addd,0	%r2, %r8, %r8
	}
	{
	  addd,0	%r8, %r9, %r8
	}
	{
	  nop 2
	  ldd,0	%r8, 0x0, %r8
	  std,2,sm	%r5, 0x0, %r10
	}
	{
	  addd,0,sm	0x0, %r8, %b[1]
	  std,2,sm	%r5, 0x8, %r8
	}
.LCS.9:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x6
	}
.LCS.10:
	{
	  nop 4
	  disp	%ctpr1, .L131
	}
	{
	  ct	%ctpr1
	}
.L57:
	{
	  sxt,0,sm	0x2, %r6, %r8
	  sxt,1,sm	0x2, %r7, %r9
	  sxt,2,sm	0x2, %r6, %r10
	  sxt,3,sm	0x2, %r7, %r11
	  disp	%ctpr1, .L149
	}
	{
	  nop 5
	  muld,0	%r8, _f16s,_lts0hi 0x38, %r8
	  shld,1	%r9, 0x3, %r9
	  muld,3	%r10, _f16s,_lts0lo 0x38, %r10
	  shld,2	%r11, 0x3, %r11
	}
	{
	  addd,0	%r0, %r8, %r8
	  addd,1	%r1, %r10, %r10
	}
	{
	  addd,0	%r8, %r9, %r8
	  addd,1	%r10, %r11, %r9
	}
	{
	  nop 2
	  ldd,0	%r8, 0x0, %r8
	  ldd,2	%r9, 0x0, %r9
	}
	{
	  nop 4
	  fcmpltdb,0	%r8, %r9, %pred3
	}
	{
	  ct	%ctpr1 ? %pred3
	}
	{
	  nop 4
	  disp	%ctpr1, .L152
	}
	{
	  ct	%ctpr1
	}
.L149:
	{
	  sxt,0,sm	0x2, %r6, %r8
	  sxt,1,sm	0x2, %r7, %r9
	  sxt,2,sm	0x2, %r6, %r10
	  sxt,3,sm	0x2, %r7, %r11
	  disp	%ctpr1, .L169
	}
	{
	  nop 5
	  muld,0	%r8, _f16s,_lts0hi 0x38, %r8
	  shld,1	%r9, 0x3, %r9
	  muld,3	%r10, _f16s,_lts0lo 0x38, %r10
	  shld,2	%r11, 0x3, %r11
	}
	{
	  addd,0	%r2, %r8, %r8
	  addd,1	%r0, %r10, %r10
	}
	{
	  addd,0	%r8, %r9, %r8
	  addd,1	%r10, %r11, %r9
	}
	{
	  nop 2
	  ldd,0	%r9, 0x0, %r9
	}
	{
	  std,2,sm	%r8, 0x0, %r9
	  ct	%ctpr1
	}
.L152:
	{
	  sxt,0,sm	0x2, %r6, %r8
	  sxt,1,sm	0x2, %r7, %r9
	  sxt,2,sm	0x2, %r6, %r10
	  sxt,3,sm	0x2, %r7, %r11
	}
	{
	  nop 5
	  muld,0	%r8, _f16s,_lts0hi 0x38, %r8
	  shld,1	%r9, 0x3, %r9
	  muld,3	%r10, _f16s,_lts0lo 0x38, %r10
	  shld,2	%r11, 0x3, %r11
	}
	{
	  addd,0	%r2, %r8, %r8
	  addd,1	%r1, %r10, %r10
	}
	{
	  addd,0	%r8, %r9, %r8
	  addd,1	%r10, %r11, %r9
	}
	{
	  nop 2
	  ldd,0	%r9, 0x0, %r9
	}
	{
	  std,2,sm	%r8, 0x0, %r9
	}
.L169:
	{
	  sxt,0,sm	0x2, %r6, %r8
	  sxt,1,sm	0x2, %r7, %r9
	  addd,2,sm	0x0, [ _f64,_lts0 .LC.1 ], %b[0]
	  addd,3,sm	0x0, [ _f64,_lts2 .LC.1 ], %r10
	}
	{
	  nop 5
	  muld,0	%r8, _f16s,_lts0hi 0x38, %r8
	  shld,1	%r9, 0x3, %r9
	}
	{
	  addd,0	%r2, %r8, %r8
	}
	{
	  addd,0	%r8, %r9, %r8
	}
	{
	  nop 2
	  ldd,0	%r8, 0x0, %r8
	  std,2,sm	%r5, 0x0, %r10
	}
	{
	  addd,0,sm	0x0, %r8, %b[1]
	  std,2,sm	%r5, 0x8, %r8
	}
.LCS.11:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x6
	}
.LCS.12:
.L131:
	{
	  nop 4
	  adds,0	%r7, 0x1, %r7
	  disp	%ctpr1, .L48
	}
	{
	  ct	%ctpr1
	}
.L54:
	{
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.2 ], %b[0]
	  addd,1,sm	0x0, [ _f64,_lts2 .LC.2 ], %r8
	}
	{
	  std,2,sm	%r5, 0x0, %r8
	}
.LCS.13:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x6
	}
.LCS.14:
	{
	  nop 4
	  adds,0	%r6, 0x1, %r6
	  disp	%ctpr1, .L41
	}
	{
	  ct	%ctpr1
	}
.L43:
	{
	  nop 5
	  return	%ctpr3
	}
	{
	  ct	%ctpr3
	}
	.cfi_endproc
	.size	_Z7ComparePA7_dS0_S0_i, .- _Z7ComparePA7_dS0_S0_i
	.global	main
	.type	main, #function
	.align	8
main:
	.cfi_startproc
	{
	  setwd	wsz = 0x8, nfx = 0x1, dbl = 0x0
	  setbn	rsz = 0x3, rbs = 0x4, rcur = 0x0
	  getsp,0	_f16s,_lts1hi 0xfc80, %r2
	}
	{
	  addd,0	%r2, _f16s,_lts0hi 0x380, %r1
	}
	{
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.3 ], %b[0]
	}
	{
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.3 ], %r3
	}
	{
	  std,2,sm	%r2, 0x0, %r3
	}
.LCS.15:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.16:
	{
	  addd,0	%r1, _f16s,_lts0hi 0xfee0, %r3
	  addd,1,sm	0x5, 0x0, %b[1]
	}
	{
	  addd,0,sm	0x0, %r3, %b[0]
	}
.LCS.17:
	{
	  nop 4
	  disp	%ctpr1, _Z10FillArrayAPA7_di
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.18:
	{
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.4 ], %b[0]
	  addd,1,sm	0x0, [ _f64,_lts2 .LC.4 ], %r3
	}
	{
	  std,2,sm	%r2, 0x0, %r3
	}
.LCS.19:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.20:
	{
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.2 ], %b[0]
	  addd,1,sm	0x0, [ _f64,_lts2 .LC.2 ], %r3
	}
	{
	  std,2,sm	%r2, 0x0, %r3
	}
.LCS.21:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.22:
	{
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.5 ], %b[0]
	  addd,1,sm	0x0, [ _f64,_lts2 .LC.5 ], %r3
	}
	{
	  std,2,sm	%r2, 0x0, %r3
	}
.LCS.23:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.24:
	{
	  addd,0	%r1, _f16s,_lts0hi 0xfdc0, %r3
	  addd,1,sm	0x5, 0x0, %b[1]
	}
	{
	  addd,0,sm	0x0, %r3, %b[0]
	}
.LCS.25:
	{
	  nop 4
	  disp	%ctpr1, _Z10FillArrayBPA7_di
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.26:
	{
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.4 ], %b[0]
	  addd,1,sm	0x0, [ _f64,_lts2 .LC.4 ], %r3
	}
	{
	  std,2,sm	%r2, 0x0, %r3
	}
.LCS.27:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.28:
	{
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.2 ], %b[0]
	  addd,1,sm	0x0, [ _f64,_lts2 .LC.2 ], %r3
	}
	{
	  std,2,sm	%r2, 0x0, %r3
	}
.LCS.29:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.30:
	{
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.6 ], %b[0]
	  addd,1,sm	0x0, [ _f64,_lts2 .LC.6 ], %r3
	}
	{
	  std,2,sm	%r2, 0x0, %r3
	}
.LCS.31:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.32:
	{
	  addd,0	%r1, _f16s,_lts0hi 0xfee0, %r3
	  addd,1	%r1, _f16s,_lts0lo 0xfdc0, %r4
	  addd,2	%r1, _f16s,_lts1hi 0xfca0, %r5
	  addd,3,sm	0x5, 0x0, %b[3]
	}
	{
	  addd,0,sm	0x0, %r3, %b[0]
	  addd,1,sm	0x0, %r4, %b[1]
	  addd,2,sm	0x0, %r5, %b[2]
	}
.LCS.33:
	{
	  nop 4
	  disp	%ctpr1, _Z7ComparePA7_dS0_S0_i
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.34:
	{
	  nop 5
	  addd,0,sm	0x0, 0x0, %r0
	  return	%ctpr3
	}
	{
	  ct	%ctpr3
	}
	.cfi_endproc
	.size	main, .- main
	.section .rodata
	.align	4
.LC.1:
	.ascii	"%f \000"
	.align	2
.LC.2:
	.ascii	"\n\000"
	.align	16
.LC.3:
	.ascii	"Matrix A:\n\000"
	.align	16
.LC.4:
	.ascii	"-------------------------------\000"
	.align	16
.LC.5:
	.ascii	"Matrix B:\n\000"
	.align	16
.LC.6:
	.ascii	"Result matrix C:\n\000"
	.weak	elbrus_compiler_v1.25.17_May_16_2021
	elbrus_compiler_v1.25.17_May_16_2021 = 0x0
