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
	  setwd	wsz = 0x6, nfx = 0x1, dbl = 0x0
	}
	{
	  adds,0,sm	0x0, 0x0, %r4
	}
.L5:
	{
	  nop 4
	  cmplsb,0	%r4, %r1, %pred0
	  disp	%ctpr1, .L7; ipd 2
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
	  disp	%ctpr1, .L15; ipd 2
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
	  disp	%ctpr1, .L18; ipd 2
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
	  adds,0	%r5, 0x1, %r5
	  disp	%ctpr1, .L12; ipd 2
	}
	{
	  nop 2
	  muld,0	%r6, _f16s,_lts0hi 0x38, %r6
	  shld,1	%r7, 0x3, %r7
	}
	{
	  nop 2
	  fsubd,0	%r8, _f64,_lts0 0x3ff0000000000000, %r8
	  fsubd,1	%r10, _f64,_lts2 0x3ff0000000000000, %r10
	}
	{
	  addd,0	%r0, %r6, %r6
	}
	{
	  addd,0	%r6, %r7, %r6
	}
	{
	  nop 4
	  fmuld,0	%r9, %r8, %r7
	  fmuld,1	%r11, %r10, %r8
	}
	{
	  nop 3
	  faddd,0	%r7, %r8, %r7
	}
	{
	  nop 7
	  fdivd,5	%r7, _f64,_lts0 0x4014000000000000, %r7
	}
	{
	  nop 7
	}
	{
	  nop 1
	}
	{
	  std,2,sm	%r6, 0x0, %r7
	  ct	%ctpr1
	}
.L18:
	{
	  nop 4
	  adds,0	%r4, 0x1, %r4
	  disp	%ctpr1, .L5; ipd 2
	}
	{
	  ct	%ctpr1
	}
.L7:
	{
	  nop 5
	  return	%ctpr3; ipd 2
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
	  setwd	wsz = 0x6, nfx = 0x1, dbl = 0x0
	}
	{
	  adds,0,sm	0x0, 0x0, %r4
	}
.L23:
	{
	  nop 4
	  cmplsb,0	%r4, %r1, %pred0
	  disp	%ctpr1, .L25; ipd 2
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
	  disp	%ctpr1, .L33; ipd 2
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
	  disp	%ctpr1, .L36; ipd 2
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
	  adds,0	%r5, 0x1, %r5
	  disp	%ctpr1, .L30; ipd 2
	}
	{
	  nop 2
	  muld,0	%r6, _f16s,_lts0hi 0x38, %r6
	  shld,1	%r7, 0x3, %r7
	}
	{
	  nop 2
	  faddd,0	%r8, _f64,_lts0 0x3ff0000000000000, %r8
	  faddd,1	%r10, _f64,_lts2 0x3ff0000000000000, %r10
	}
	{
	  addd,0	%r0, %r6, %r6
	}
	{
	  addd,0	%r6, %r7, %r6
	}
	{
	  nop 4
	  fmuld,0	%r9, %r8, %r7
	  fmuld,1	%r11, %r10, %r8
	}
	{
	  nop 3
	  faddd,0	%r7, %r8, %r7
	}
	{
	  nop 7
	  fdivd,5	%r7, _f64,_lts0 0x401c000000000000, %r7
	}
	{
	  nop 7
	}
	{
	  nop 1
	}
	{
	  std,2,sm	%r6, 0x0, %r7
	  ct	%ctpr1
	}
.L36:
	{
	  nop 4
	  adds,0	%r4, 0x1, %r4
	  disp	%ctpr1, .L23; ipd 2
	}
	{
	  ct	%ctpr1
	}
.L25:
	{
	  nop 5
	  return	%ctpr3; ipd 2
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
	  setwd	wsz = 0x6, nfx = 0x1, dbl = 0x0
	}
	{
	  adds,0,sm	0x0, 0x0, %r6
	}
.L41:
	{
	  nop 4
	  cmplsb,0	%r6, %r3, %pred0
	  disp	%ctpr1, .L43; ipd 2
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
	  disp	%ctpr1, .L51; ipd 2
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
	  disp	%ctpr1, .L54; ipd 2
	}
	{
	  ct	%ctpr1
	}
.L51:
	{
	  nop 4
	  disp	%ctpr1, .L57; ipd 2
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
	  disp	%ctpr1, .L76; ipd 2
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
	  disp	%ctpr1, .L79; ipd 2
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
	  disp	%ctpr1, .L96; ipd 2
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
	  nop 4
	  disp	%ctpr1, .L113; ipd 2
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
	  disp	%ctpr1, .L131; ipd 2
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
	  disp	%ctpr1, .L134; ipd 2
	}
	{
	  ct	%ctpr1
	}
.L131:
	{
	  sxt,0,sm	0x2, %r6, %r8
	  sxt,1,sm	0x2, %r7, %r9
	  sxt,2,sm	0x2, %r6, %r10
	  sxt,3,sm	0x2, %r7, %r11
	  disp	%ctpr1, .L151; ipd 2
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
.L134:
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
.L151:
.L113:
	{
	  nop 4
	  adds,0	%r7, 0x1, %r7
	  disp	%ctpr1, .L48; ipd 2
	}
	{
	  ct	%ctpr1
	}
.L54:
	{
	  nop 4
	  adds,0	%r6, 0x1, %r6
	  disp	%ctpr1, .L41; ipd 2
	}
	{
	  ct	%ctpr1
	}
.L43:
	{
	  nop 5
	  return	%ctpr3; ipd 2
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
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.1 ], %b[0]
	}
	{
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.1 ], %r3
	}
	{
	  std,2,sm	%r2, 0x0, %r3
	}
.LCS.1:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.2:
	{
	  addd,0	%r1, _f16s,_lts0hi 0xfee0, %r3
	  addd,1,sm	0x5, 0x0, %b[1]
	}
	{
	  addd,0,sm	0x0, %r3, %b[0]
	}
.LCS.3:
	{
	  nop 4
	  disp	%ctpr1, _Z10FillArrayAPA7_di
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.4:
	{
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.2 ], %b[0]
	  addd,1,sm	0x0, [ _f64,_lts2 .LC.2 ], %r3
	}
	{
	  std,2,sm	%r2, 0x0, %r3
	}
.LCS.5:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.6:
	{
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.3 ], %b[0]
	  addd,1,sm	0x0, [ _f64,_lts2 .LC.3 ], %r3
	}
	{
	  std,2,sm	%r2, 0x0, %r3
	}
.LCS.7:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.8:
	{
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.4 ], %b[0]
	  addd,1,sm	0x0, [ _f64,_lts2 .LC.4 ], %r3
	}
	{
	  std,2,sm	%r2, 0x0, %r3
	}
.LCS.9:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.10:
	{
	  addd,0	%r1, _f16s,_lts0hi 0xfdc0, %r3
	  addd,1,sm	0x5, 0x0, %b[1]
	}
	{
	  addd,0,sm	0x0, %r3, %b[0]
	}
.LCS.11:
	{
	  nop 4
	  disp	%ctpr1, _Z10FillArrayBPA7_di
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.12:
	{
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.2 ], %b[0]
	  addd,1,sm	0x0, [ _f64,_lts2 .LC.2 ], %r3
	}
	{
	  std,2,sm	%r2, 0x0, %r3
	}
.LCS.13:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.14:
	{
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.3 ], %b[0]
	  addd,1,sm	0x0, [ _f64,_lts2 .LC.3 ], %r3
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
	  addd,0,sm	0x0, [ _f64,_lts0 .LC.5 ], %b[0]
	  addd,1,sm	0x0, [ _f64,_lts2 .LC.5 ], %r3
	}
	{
	  std,2,sm	%r2, 0x0, %r3
	}
.LCS.17:
	{
	  nop 4
	  disp	%ctpr1, printf
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.18:
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
.LCS.19:
	{
	  nop 4
	  disp	%ctpr1, _Z7ComparePA7_dS0_S0_i
	}
	{
	  call	%ctpr1, wbs = 0x4
	}
.LCS.20:
	{
	  nop 5
	  addd,0,sm	0x0, 0x0, %r0
	  return	%ctpr3; ipd 2
	}
	{
	  ct	%ctpr3
	}
	.cfi_endproc
	.size	main, .- main
	.section .rodata
	.align	16
.LC.1:
	.ascii	"Matrix A:\n\000"
	.align	16
.LC.2:
	.ascii	"-------------------------------\000"
	.align	2
.LC.3:
	.ascii	"\n\000"
	.align	16
.LC.4:
	.ascii	"Matrix B:\n\000"
	.align	16
.LC.5:
	.ascii	"Result matrix C:\n\000"
	.weak	elbrus_compiler_v1.25.17_May_16_2021
	elbrus_compiler_v1.25.17_May_16_2021 = 0x0
