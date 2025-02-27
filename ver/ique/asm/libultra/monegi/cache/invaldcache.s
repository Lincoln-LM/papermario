.include "macro.inc"

/* assembler directives */
.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */
.set gp=64     /* allow use of 64-bit general purpose registers */

.section .text, "ax"

/* Generated by spimdisasm 1.11.1 */

# Handwritten function
glabel osInvalDCache
/* 3B8D0 800604D0 18A00020 */  blez      $a1, .LIQUE_80060554
/* 3B8D4 800604D4 00000000 */   nop
/* 3B8D8 800604D8 240B2000 */  addiu     $t3, $zero, 0x2000
/* 3B8DC 800604DC 00AB082B */  sltu      $at, $a1, $t3
/* 3B8E0 800604E0 1020001E */  beqz      $at, .LIQUE_8006055C
/* 3B8E4 800604E4 00000000 */   nop
/* 3B8E8 800604E8 0080402D */  daddu     $t0, $a0, $zero
/* 3B8EC 800604EC 00854821 */  addu      $t1, $a0, $a1
/* 3B8F0 800604F0 0109082B */  sltu      $at, $t0, $t1
/* 3B8F4 800604F4 10200017 */  beqz      $at, .LIQUE_80060554
/* 3B8F8 800604F8 00000000 */   nop
/* 3B8FC 800604FC 2529FFF0 */  addiu     $t1, $t1, -0x10
/* 3B900 80060500 310A000F */  andi      $t2, $t0, 0xF
/* 3B904 80060504 11400007 */  beqz      $t2, .LIQUE_80060524
/* 3B908 80060508 00000000 */   nop
/* 3B90C 8006050C 010A4023 */  subu      $t0, $t0, $t2
/* 3B910 80060510 BD150000 */  cache     0x15, 0x0($t0) # handwritten instruction
/* 3B914 80060514 0109082B */  sltu      $at, $t0, $t1
/* 3B918 80060518 1020000E */  beqz      $at, .LIQUE_80060554
/* 3B91C 8006051C 00000000 */   nop
/* 3B920 80060520 25080010 */  addiu     $t0, $t0, 0x10
.LIQUE_80060524:
/* 3B924 80060524 312A000F */  andi      $t2, $t1, 0xF
/* 3B928 80060528 11400006 */  beqz      $t2, .LIQUE_80060544
/* 3B92C 8006052C 00000000 */   nop
/* 3B930 80060530 012A4823 */  subu      $t1, $t1, $t2
/* 3B934 80060534 BD350010 */  cache     0x15, 0x10($t1) # handwritten instruction
/* 3B938 80060538 0128082B */  sltu      $at, $t1, $t0
/* 3B93C 8006053C 14200005 */  bnez      $at, .LIQUE_80060554
/* 3B940 80060540 00000000 */   nop
.LIQUE_80060544:
/* 3B944 80060544 BD110000 */  cache     0x11, 0x0($t0) # handwritten instruction
/* 3B948 80060548 0109082B */  sltu      $at, $t0, $t1
/* 3B94C 8006054C 1420FFFD */  bnez      $at, .LIQUE_80060544
/* 3B950 80060550 25080010 */   addiu    $t0, $t0, 0x10
.LIQUE_80060554:
/* 3B954 80060554 03E00008 */  jr        $ra
/* 3B958 80060558 00000000 */   nop
.LIQUE_8006055C:
/* 3B95C 8006055C 3C088000 */  lui       $t0, 0x8000
/* 3B960 80060560 010B4821 */  addu      $t1, $t0, $t3
/* 3B964 80060564 2529FFF0 */  addiu     $t1, $t1, -0x10
.LIQUE_80060568:
/* 3B968 80060568 BD010000 */  cache     0x01, 0x0($t0) # handwritten instruction
/* 3B96C 8006056C 0109082B */  sltu      $at, $t0, $t1
/* 3B970 80060570 1420FFFD */  bnez      $at, .LIQUE_80060568
/* 3B974 80060574 25080010 */   addiu    $t0, $t0, (0x80000010 & 0xFFFF)
/* 3B978 80060578 03E00008 */  jr        $ra
/* 3B97C 8006057C 00000000 */   nop
