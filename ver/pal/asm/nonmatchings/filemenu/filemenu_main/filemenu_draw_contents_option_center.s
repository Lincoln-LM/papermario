.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

/* Generated by spimdisasm 1.11.1 */

glabel filemenu_draw_contents_option_center
/* 171954 80248F34 27BDFFD0 */  addiu      $sp, $sp, -0x30
/* 171958 80248F38 0080382D */  daddu      $a3, $a0, $zero
/* 17195C 80248F3C AFB1001C */  sw         $s1, 0x1C($sp)
/* 171960 80248F40 00A0882D */  daddu      $s1, $a1, $zero
/* 171964 80248F44 AFBF002C */  sw         $ra, 0x2C($sp)
/* 171968 80248F48 AFB40028 */  sw         $s4, 0x28($sp)
/* 17196C 80248F4C AFB30024 */  sw         $s3, 0x24($sp)
/* 171970 80248F50 AFB20020 */  sw         $s2, 0x20($sp)
/* 171974 80248F54 AFB00018 */  sw         $s0, 0x18($sp)
/* 171978 80248F58 80E30004 */  lb         $v1, 0x4($a3)
/* 17197C 80248F5C 28620004 */  slti       $v0, $v1, 0x4
/* 171980 80248F60 10400010 */  beqz       $v0, .Lfilemenu_80248FA4
/* 171984 80248F64 00C0902D */   daddu     $s2, $a2, $zero
/* 171988 80248F68 1860000E */  blez       $v1, .Lfilemenu_80248FA4
/* 17198C 80248F6C 24130009 */   addiu     $s3, $zero, 0x9
/* 171990 80248F70 0000A02D */  daddu      $s4, $zero, $zero
/* 171994 80248F74 3C0500FF */  lui        $a1, (0xFFFF00 >> 16)
/* 171998 80248F78 34A5FF00 */  ori        $a1, $a1, (0xFFFF00 & 0xFFFF)
/* 17199C 80248F7C 3C040001 */  lui        $a0, (0x10200 >> 16)
/* 1719A0 80248F80 34840200 */  ori        $a0, $a0, (0x10200 & 0xFFFF)
/* 1719A4 80248F84 8CE20000 */  lw         $v0, 0x0($a3)
/* 1719A8 80248F88 3C038015 */  lui        $v1, %hi(gCurrentLanguage)
/* 1719AC 80248F8C 8C63AE4C */  lw         $v1, %lo(gCurrentLanguage)($v1)
/* 1719B0 80248F90 3C108025 */  lui        $s0, %hi(D_filemenu_802508F4)
/* 1719B4 80248F94 02038021 */  addu       $s0, $s0, $v1
/* 1719B8 80248F98 921008F4 */  lbu        $s0, %lo(D_filemenu_802508F4)($s0)
/* 1719BC 80248F9C 080923F6 */  j          .Lfilemenu_80248FD8
/* 1719C0 80248FA0 00451024 */   and       $v0, $v0, $a1
.Lfilemenu_80248FA4:
/* 1719C4 80248FA4 2413000A */  addiu      $s3, $zero, 0xA
/* 1719C8 80248FA8 0000A02D */  daddu      $s4, $zero, $zero
/* 1719CC 80248FAC 3C0500FF */  lui        $a1, (0xFFFF00 >> 16)
/* 1719D0 80248FB0 34A5FF00 */  ori        $a1, $a1, (0xFFFF00 & 0xFFFF)
/* 1719D4 80248FB4 3C040001 */  lui        $a0, (0x10200 >> 16)
/* 1719D8 80248FB8 34840200 */  ori        $a0, $a0, (0x10200 & 0xFFFF)
/* 1719DC 80248FBC 8CE20000 */  lw         $v0, 0x0($a3)
/* 1719E0 80248FC0 3C038015 */  lui        $v1, %hi(gCurrentLanguage)
/* 1719E4 80248FC4 8C63AE4C */  lw         $v1, %lo(gCurrentLanguage)($v1)
/* 1719E8 80248FC8 00451024 */  and        $v0, $v0, $a1
/* 1719EC 80248FCC 3C108025 */  lui        $s0, %hi(D_filemenu_802508EC)
/* 1719F0 80248FD0 02038021 */  addu       $s0, $s0, $v1
/* 1719F4 80248FD4 921008EC */  lbu        $s0, %lo(D_filemenu_802508EC)($s0)
.Lfilemenu_80248FD8:
/* 1719F8 80248FD8 14440005 */  bne        $v0, $a0, .Lfilemenu_80248FF0
/* 1719FC 80248FDC 24040036 */   addiu     $a0, $zero, 0x36
/* 171A00 80248FE0 02302821 */  addu       $a1, $s1, $s0
/* 171A04 80248FE4 24A5FFF6 */  addiu      $a1, $a1, -0xA
/* 171A08 80248FE8 0C091B44 */  jal        filemenu_set_cursor_goal_pos
/* 171A0C 80248FEC 26460008 */   addiu     $a2, $s2, 0x8
.Lfilemenu_80248FF0:
/* 171A10 80248FF0 0C093A16 */  jal        filemenu_get_menu_message
/* 171A14 80248FF4 0260202D */   daddu     $a0, $s3, $zero
/* 171A18 80248FF8 0040202D */  daddu      $a0, $v0, $zero
/* 171A1C 80248FFC 02302821 */  addu       $a1, $s1, $s0
/* 171A20 80249000 02543021 */  addu       $a2, $s2, $s4
/* 171A24 80249004 24C60002 */  addiu      $a2, $a2, 0x2
/* 171A28 80249008 24020001 */  addiu      $v0, $zero, 0x1
/* 171A2C 8024900C 240700FF */  addiu      $a3, $zero, 0xFF
/* 171A30 80249010 AFA00010 */  sw         $zero, 0x10($sp)
/* 171A34 80249014 0C0939C7 */  jal        filemenu_draw_message
/* 171A38 80249018 AFA20014 */   sw        $v0, 0x14($sp)
/* 171A3C 8024901C 8FBF002C */  lw         $ra, 0x2C($sp)
/* 171A40 80249020 8FB40028 */  lw         $s4, 0x28($sp)
/* 171A44 80249024 8FB30024 */  lw         $s3, 0x24($sp)
/* 171A48 80249028 8FB20020 */  lw         $s2, 0x20($sp)
/* 171A4C 8024902C 8FB1001C */  lw         $s1, 0x1C($sp)
/* 171A50 80249030 8FB00018 */  lw         $s0, 0x18($sp)
/* 171A54 80249034 03E00008 */  jr         $ra
/* 171A58 80249038 27BD0030 */   addiu     $sp, $sp, 0x30
