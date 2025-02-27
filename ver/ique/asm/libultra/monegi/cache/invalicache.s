.include "macro.inc"

/* assembler directives */
.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */
.set gp=64     /* allow use of 64-bit general purpose registers */

.section .text, "ax"

/* Generated by spimdisasm 1.11.1 */

# Handwritten function
glabel osInvalICache
/* 3B980 80060580 18A00011 */  blez      $a1, .LIQUE_800605C8
/* 3B984 80060584 00000000 */   nop
/* 3B988 80060588 240B4000 */  addiu     $t3, $zero, 0x4000
/* 3B98C 8006058C 00AB082B */  sltu      $at, $a1, $t3
/* 3B990 80060590 1020000F */  beqz      $at, .LIQUE_800605D0
/* 3B994 80060594 00000000 */   nop
/* 3B998 80060598 0080402D */  daddu     $t0, $a0, $zero
/* 3B99C 8006059C 00854821 */  addu      $t1, $a0, $a1
/* 3B9A0 800605A0 0109082B */  sltu      $at, $t0, $t1
/* 3B9A4 800605A4 10200008 */  beqz      $at, .LIQUE_800605C8
/* 3B9A8 800605A8 00000000 */   nop
/* 3B9AC 800605AC 2529FFE0 */  addiu     $t1, $t1, -0x20
/* 3B9B0 800605B0 310A001F */  andi      $t2, $t0, 0x1F
/* 3B9B4 800605B4 010A4023 */  subu      $t0, $t0, $t2
.LIQUE_800605B8:
/* 3B9B8 800605B8 BD100000 */  cache     0x10, 0x0($t0) # handwritten instruction
/* 3B9BC 800605BC 0109082B */  sltu      $at, $t0, $t1
/* 3B9C0 800605C0 1420FFFD */  bnez      $at, .LIQUE_800605B8
/* 3B9C4 800605C4 25080020 */   addiu    $t0, $t0, 0x20
.LIQUE_800605C8:
/* 3B9C8 800605C8 03E00008 */  jr        $ra
/* 3B9CC 800605CC 00000000 */   nop
.LIQUE_800605D0:
/* 3B9D0 800605D0 3C088000 */  lui       $t0, 0x8000
/* 3B9D4 800605D4 010B4821 */  addu      $t1, $t0, $t3
/* 3B9D8 800605D8 2529FFE0 */  addiu     $t1, $t1, -0x20
.LIQUE_800605DC:
/* 3B9DC 800605DC BD000000 */  cache     0x00, 0x0($t0) # handwritten instruction
/* 3B9E0 800605E0 0109082B */  sltu      $at, $t0, $t1
/* 3B9E4 800605E4 1420FFFD */  bnez      $at, .LIQUE_800605DC
/* 3B9E8 800605E8 25080020 */   addiu    $t0, $t0, (0x80000020 & 0xFFFF)
/* 3B9EC 800605EC 03E00008 */  jr        $ra
/* 3B9F0 800605F0 00000000 */   nop
/* 3B9F4 800605F4 00000000 */  nop
/* 3B9F8 800605F8 00000000 */  nop
/* 3B9FC 800605FC 00000000 */  nop
