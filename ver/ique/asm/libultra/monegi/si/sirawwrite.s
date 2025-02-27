.include "macro.inc"

/* assembler directives */
.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */
.set gp=64     /* allow use of 64-bit general purpose registers */

.section .text, "ax"

/* Generated by spimdisasm 1.11.1 */

glabel __osSiRawWriteIo
/* 46C90 8006B890 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 46C94 8006B894 AFB00010 */  sw        $s0, 0x10($sp)
/* 46C98 8006B898 00808021 */  addu      $s0, $a0, $zero
/* 46C9C 8006B89C AFB10014 */  sw        $s1, 0x14($sp)
/* 46CA0 8006B8A0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 46CA4 8006B8A4 0C01B378 */  jal       __osSiDeviceBusy
/* 46CA8 8006B8A8 00A08821 */   addu     $s1, $a1, $zero
/* 46CAC 8006B8AC 14400005 */  bnez      $v0, .LIQUE_8006B8C4
/* 46CB0 8006B8B0 2402FFFF */   addiu    $v0, $zero, -0x1
/* 46CB4 8006B8B4 3C03A000 */  lui       $v1, %hi(D_A0000000)
/* 46CB8 8006B8B8 02031825 */  or        $v1, $s0, $v1
/* 46CBC 8006B8BC AC710000 */  sw        $s1, %lo(D_A0000000)($v1)
/* 46CC0 8006B8C0 00001021 */  addu      $v0, $zero, $zero
.LIQUE_8006B8C4:
/* 46CC4 8006B8C4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 46CC8 8006B8C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 46CCC 8006B8CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 46CD0 8006B8D0 03E00008 */  jr        $ra
/* 46CD4 8006B8D4 27BD0020 */   addiu    $sp, $sp, 0x20
/* 46CD8 8006B8D8 00000000 */  nop
/* 46CDC 8006B8DC 00000000 */  nop
