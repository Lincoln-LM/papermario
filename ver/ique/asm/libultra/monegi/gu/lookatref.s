.include "macro.inc"

/* assembler directives */
.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */
.set gp=64     /* allow use of 64-bit general purpose registers */

.section .text, "ax"

/* Generated by spimdisasm 1.11.1 */

glabel guLookAtReflectF
/* 3D020 80061C20 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 3D024 80061C24 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* 3D028 80061C28 C7BC0088 */  lwc1      $f28, 0x88($sp)
/* 3D02C 80061C2C F7BE0060 */  sdc1      $f30, 0x60($sp)
/* 3D030 80061C30 C7BE008C */  lwc1      $f30, 0x8C($sp)
/* 3D034 80061C34 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* 3D038 80061C38 C7BA0090 */  lwc1      $f26, 0x90($sp)
/* 3D03C 80061C3C F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3D040 80061C40 C7B4007C */  lwc1      $f20, 0x7C($sp)
/* 3D044 80061C44 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3D048 80061C48 C7B60080 */  lwc1      $f22, 0x80($sp)
/* 3D04C 80061C4C AFB1002C */  sw        $s1, 0x2C($sp)
/* 3D050 80061C50 00808821 */  addu      $s1, $a0, $zero
/* 3D054 80061C54 AFB00028 */  sw        $s0, 0x28($sp)
/* 3D058 80061C58 00A08021 */  addu      $s0, $a1, $zero
/* 3D05C 80061C5C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3D060 80061C60 C7B80084 */  lwc1      $f24, 0x84($sp)
/* 3D064 80061C64 AFBF0030 */  sw        $ra, 0x30($sp)
/* 3D068 80061C68 AFA60070 */  sw        $a2, 0x70($sp)
/* 3D06C 80061C6C 0C019698 */  jal       guMtxIdentF
/* 3D070 80061C70 AFA70074 */   sw       $a3, 0x74($sp)
/* 3D074 80061C74 C7AE0070 */  lwc1      $f14, 0x70($sp)
/* 3D078 80061C78 460EA501 */  sub.s     $f20, $f20, $f14
/* 3D07C 80061C7C 4614A002 */  mul.s     $f0, $f20, $f20
/* 3D080 80061C80 C7B20074 */  lwc1      $f18, 0x74($sp)
/* 3D084 80061C84 4612B581 */  sub.s     $f22, $f22, $f18
/* 3D088 80061C88 4616B102 */  mul.s     $f4, $f22, $f22
/* 3D08C 80061C8C C7AE0078 */  lwc1      $f14, 0x78($sp)
/* 3D090 80061C90 460EC601 */  sub.s     $f24, $f24, $f14
/* 3D094 80061C94 4618C082 */  mul.s     $f2, $f24, $f24
/* 3D098 80061C98 46040000 */  add.s     $f0, $f0, $f4
/* 3D09C 80061C9C E7B40010 */  swc1      $f20, 0x10($sp)
/* 3D0A0 80061CA0 46020300 */  add.s     $f12, $f0, $f2
/* 3D0A4 80061CA4 E7B60014 */  swc1      $f22, 0x14($sp)
/* 3D0A8 80061CA8 46006084 */  sqrt.s    $f2, $f12
/* 3D0AC 80061CAC 46021032 */  c.eq.s    $f2, $f2
/* 3D0B0 80061CB0 45010004 */  bc1t      .LIQUE_80061CC4
/* 3D0B4 80061CB4 E7B80018 */   swc1     $f24, 0x18($sp)
/* 3D0B8 80061CB8 0C0183A0 */  jal       sqrtf
/* 3D0BC 80061CBC 00000000 */   nop
/* 3D0C0 80061CC0 46000086 */  mov.s     $f2, $f0
.LIQUE_80061CC4:
/* 3D0C4 80061CC4 460010A1 */  cvt.d.s   $f2, $f2
/* 3D0C8 80061CC8 3C01BFF0 */  lui       $at, (0xBFF00000 >> 16)
/* 3D0CC 80061CCC 44810800 */  mtc1      $at, $f1
/* 3D0D0 80061CD0 44800000 */  mtc1      $zero, $f0
/* 3D0D4 80061CD4 C7AE0018 */  lwc1      $f14, 0x18($sp)
/* 3D0D8 80061CD8 46220003 */  div.d     $f0, $f0, $f2
/* 3D0DC 80061CDC 46200020 */  cvt.s.d   $f0, $f0
/* 3D0E0 80061CE0 46007382 */  mul.s     $f14, $f14, $f0
/* 3D0E4 80061CE4 C7B20010 */  lwc1      $f18, 0x10($sp)
/* 3D0E8 80061CE8 46009482 */  mul.s     $f18, $f18, $f0
/* 3D0EC 80061CEC 460EF102 */  mul.s     $f4, $f30, $f14
/* 3D0F0 80061CF0 E7B20010 */  swc1      $f18, 0x10($sp)
/* 3D0F4 80061CF4 C7B20014 */  lwc1      $f18, 0x14($sp)
/* 3D0F8 80061CF8 46009482 */  mul.s     $f18, $f18, $f0
/* 3D0FC 80061CFC E7AE0018 */  swc1      $f14, 0x18($sp)
/* 3D100 80061D00 C7AE0010 */  lwc1      $f14, 0x10($sp)
/* 3D104 80061D04 460ED282 */  mul.s     $f10, $f26, $f14
/* 3D108 80061D08 4612D082 */  mul.s     $f2, $f26, $f18
/* 3D10C 80061D0C E7B20014 */  swc1      $f18, 0x14($sp)
/* 3D110 80061D10 C7B20018 */  lwc1      $f18, 0x18($sp)
/* 3D114 80061D14 4612E182 */  mul.s     $f6, $f28, $f18
/* 3D118 80061D18 C7AE0014 */  lwc1      $f14, 0x14($sp)
/* 3D11C 80061D1C 460EE302 */  mul.s     $f12, $f28, $f14
/* 3D120 80061D20 C7B20010 */  lwc1      $f18, 0x10($sp)
/* 3D124 80061D24 4612F202 */  mul.s     $f8, $f30, $f18
/* 3D128 80061D28 46022601 */  sub.s     $f24, $f4, $f2
/* 3D12C 80061D2C 4618C002 */  mul.s     $f0, $f24, $f24
/* 3D130 80061D30 46065501 */  sub.s     $f20, $f10, $f6
/* 3D134 80061D34 4614A102 */  mul.s     $f4, $f20, $f20
/* 3D138 80061D38 46086581 */  sub.s     $f22, $f12, $f8
/* 3D13C 80061D3C 4616B082 */  mul.s     $f2, $f22, $f22
/* 3D140 80061D40 46040000 */  add.s     $f0, $f0, $f4
/* 3D144 80061D44 46020300 */  add.s     $f12, $f0, $f2
/* 3D148 80061D48 46006004 */  sqrt.s    $f0, $f12
/* 3D14C 80061D4C 46000032 */  c.eq.s    $f0, $f0
/* 3D150 80061D50 45010003 */  bc1t      .LIQUE_80061D60
/* 3D154 80061D54 00000000 */   nop
/* 3D158 80061D58 0C0183A0 */  jal       sqrtf
/* 3D15C 80061D5C 00000000 */   nop
.LIQUE_80061D60:
/* 3D160 80061D60 3C013FF0 */  lui       $at, (0x3FF00000 >> 16)
/* 3D164 80061D64 44817800 */  mtc1      $at, $f15
/* 3D168 80061D68 44807000 */  mtc1      $zero, $f14
/* 3D16C 80061D6C 46000021 */  cvt.d.s   $f0, $f0
/* 3D170 80061D70 46207003 */  div.d     $f0, $f14, $f0
/* 3D174 80061D74 46200020 */  cvt.s.d   $f0, $f0
/* 3D178 80061D78 4600C602 */  mul.s     $f24, $f24, $f0
/* 3D17C 80061D7C 4600B582 */  mul.s     $f22, $f22, $f0
/* 3D180 80061D80 4600A502 */  mul.s     $f20, $f20, $f0
/* 3D184 80061D84 C7B20014 */  lwc1      $f18, 0x14($sp)
/* 3D188 80061D88 46169102 */  mul.s     $f4, $f18, $f22
/* 3D18C 80061D8C C7AE0018 */  lwc1      $f14, 0x18($sp)
/* 3D190 80061D90 46147082 */  mul.s     $f2, $f14, $f20
/* 3D194 80061D94 46187282 */  mul.s     $f10, $f14, $f24
/* 3D198 80061D98 C7B20010 */  lwc1      $f18, 0x10($sp)
/* 3D19C 80061D9C 46169182 */  mul.s     $f6, $f18, $f22
/* 3D1A0 80061DA0 46149302 */  mul.s     $f12, $f18, $f20
/* 3D1A4 80061DA4 C7AE0014 */  lwc1      $f14, 0x14($sp)
/* 3D1A8 80061DA8 46187202 */  mul.s     $f8, $f14, $f24
/* 3D1AC 80061DAC 46022701 */  sub.s     $f28, $f4, $f2
/* 3D1B0 80061DB0 461CE002 */  mul.s     $f0, $f28, $f28
/* 3D1B4 80061DB4 46065781 */  sub.s     $f30, $f10, $f6
/* 3D1B8 80061DB8 461EF102 */  mul.s     $f4, $f30, $f30
/* 3D1BC 80061DBC 46086681 */  sub.s     $f26, $f12, $f8
/* 3D1C0 80061DC0 461AD082 */  mul.s     $f2, $f26, $f26
/* 3D1C4 80061DC4 46040000 */  add.s     $f0, $f0, $f4
/* 3D1C8 80061DC8 46020300 */  add.s     $f12, $f0, $f2
/* 3D1CC 80061DCC 46006004 */  sqrt.s    $f0, $f12
/* 3D1D0 80061DD0 46000032 */  c.eq.s    $f0, $f0
/* 3D1D4 80061DD4 45010003 */  bc1t      .LIQUE_80061DE4
/* 3D1D8 80061DD8 00000000 */   nop
/* 3D1DC 80061DDC 0C0183A0 */  jal       sqrtf
/* 3D1E0 80061DE0 00000000 */   nop
.LIQUE_80061DE4:
/* 3D1E4 80061DE4 3C013FF0 */  lui       $at, (0x3FF00000 >> 16)
/* 3D1E8 80061DE8 44819800 */  mtc1      $at, $f19
/* 3D1EC 80061DEC 44809000 */  mtc1      $zero, $f18
/* 3D1F0 80061DF0 46000021 */  cvt.d.s   $f0, $f0
/* 3D1F4 80061DF4 46209003 */  div.d     $f0, $f18, $f0
/* 3D1F8 80061DF8 46200020 */  cvt.s.d   $f0, $f0
/* 3D1FC 80061DFC 4600E702 */  mul.s     $f28, $f28, $f0
/* 3D200 80061E00 4600F782 */  mul.s     $f30, $f30, $f0
/* 3D204 80061E04 4600D682 */  mul.s     $f26, $f26, $f0
/* 3D208 80061E08 3C014300 */  lui       $at, (0x43000000 >> 16)
/* 3D20C 80061E0C 44810000 */  mtc1      $at, $f0
/* 3D210 80061E10 4600C002 */  mul.s     $f0, $f24, $f0
/* 3D214 80061E14 3C0142FE */  lui       $at, (0x42FE0000 >> 16)
/* 3D218 80061E18 44811000 */  mtc1      $at, $f2
/* 3D21C 80061E1C 4602003C */  c.lt.s    $f0, $f2
/* 3D220 80061E20 45000005 */  bc1f      .LIQUE_80061E38
/* 3D224 80061E24 2402007F */   addiu    $v0, $zero, 0x7F
/* 3D228 80061E28 4600038D */  trunc.w.s $f14, $f0
/* 3D22C 80061E2C 44027000 */  mfc1      $v0, $f14
/* 3D230 80061E30 0801878F */  j         .LIQUE_80061E3C
/* 3D234 80061E34 A2020008 */   sb       $v0, 0x8($s0)
.LIQUE_80061E38:
/* 3D238 80061E38 A2020008 */  sb        $v0, 0x8($s0)
.LIQUE_80061E3C:
/* 3D23C 80061E3C 3C014300 */  lui       $at, (0x43000000 >> 16)
/* 3D240 80061E40 44810000 */  mtc1      $at, $f0
/* 3D244 80061E44 4600A002 */  mul.s     $f0, $f20, $f0
/* 3D248 80061E48 3C0142FE */  lui       $at, (0x42FE0000 >> 16)
/* 3D24C 80061E4C 44811000 */  mtc1      $at, $f2
/* 3D250 80061E50 4602003C */  c.lt.s    $f0, $f2
/* 3D254 80061E54 45000005 */  bc1f      .LIQUE_80061E6C
/* 3D258 80061E58 2402007F */   addiu    $v0, $zero, 0x7F
/* 3D25C 80061E5C 4600038D */  trunc.w.s $f14, $f0
/* 3D260 80061E60 44027000 */  mfc1      $v0, $f14
/* 3D264 80061E64 0801879C */  j         .LIQUE_80061E70
/* 3D268 80061E68 A2020009 */   sb       $v0, 0x9($s0)
.LIQUE_80061E6C:
/* 3D26C 80061E6C A2020009 */  sb        $v0, 0x9($s0)
.LIQUE_80061E70:
/* 3D270 80061E70 3C014300 */  lui       $at, (0x43000000 >> 16)
/* 3D274 80061E74 44810000 */  mtc1      $at, $f0
/* 3D278 80061E78 4600B002 */  mul.s     $f0, $f22, $f0
/* 3D27C 80061E7C 3C0142FE */  lui       $at, (0x42FE0000 >> 16)
/* 3D280 80061E80 44811000 */  mtc1      $at, $f2
/* 3D284 80061E84 4602003C */  c.lt.s    $f0, $f2
/* 3D288 80061E88 45000005 */  bc1f      .LIQUE_80061EA0
/* 3D28C 80061E8C 2402007F */   addiu    $v0, $zero, 0x7F
/* 3D290 80061E90 4600038D */  trunc.w.s $f14, $f0
/* 3D294 80061E94 44027000 */  mfc1      $v0, $f14
/* 3D298 80061E98 080187A9 */  j         .LIQUE_80061EA4
/* 3D29C 80061E9C A202000A */   sb       $v0, 0xA($s0)
.LIQUE_80061EA0:
/* 3D2A0 80061EA0 A202000A */  sb        $v0, 0xA($s0)
.LIQUE_80061EA4:
/* 3D2A4 80061EA4 3C014300 */  lui       $at, (0x43000000 >> 16)
/* 3D2A8 80061EA8 44810000 */  mtc1      $at, $f0
/* 3D2AC 80061EAC 4600E002 */  mul.s     $f0, $f28, $f0
/* 3D2B0 80061EB0 3C0142FE */  lui       $at, (0x42FE0000 >> 16)
/* 3D2B4 80061EB4 44811000 */  mtc1      $at, $f2
/* 3D2B8 80061EB8 4602003C */  c.lt.s    $f0, $f2
/* 3D2BC 80061EBC 45000005 */  bc1f      .LIQUE_80061ED4
/* 3D2C0 80061EC0 2402007F */   addiu    $v0, $zero, 0x7F
/* 3D2C4 80061EC4 4600038D */  trunc.w.s $f14, $f0
/* 3D2C8 80061EC8 44027000 */  mfc1      $v0, $f14
/* 3D2CC 80061ECC 080187B6 */  j         .LIQUE_80061ED8
/* 3D2D0 80061ED0 A2020018 */   sb       $v0, 0x18($s0)
.LIQUE_80061ED4:
/* 3D2D4 80061ED4 A2020018 */  sb        $v0, 0x18($s0)
.LIQUE_80061ED8:
/* 3D2D8 80061ED8 3C014300 */  lui       $at, (0x43000000 >> 16)
/* 3D2DC 80061EDC 44810000 */  mtc1      $at, $f0
/* 3D2E0 80061EE0 4600F002 */  mul.s     $f0, $f30, $f0
/* 3D2E4 80061EE4 3C0142FE */  lui       $at, (0x42FE0000 >> 16)
/* 3D2E8 80061EE8 44811000 */  mtc1      $at, $f2
/* 3D2EC 80061EEC 4602003C */  c.lt.s    $f0, $f2
/* 3D2F0 80061EF0 45000005 */  bc1f      .LIQUE_80061F08
/* 3D2F4 80061EF4 2402007F */   addiu    $v0, $zero, 0x7F
/* 3D2F8 80061EF8 4600038D */  trunc.w.s $f14, $f0
/* 3D2FC 80061EFC 44027000 */  mfc1      $v0, $f14
/* 3D300 80061F00 080187C3 */  j         .LIQUE_80061F0C
/* 3D304 80061F04 A2020019 */   sb       $v0, 0x19($s0)
.LIQUE_80061F08:
/* 3D308 80061F08 A2020019 */  sb        $v0, 0x19($s0)
.LIQUE_80061F0C:
/* 3D30C 80061F0C 3C014300 */  lui       $at, (0x43000000 >> 16)
/* 3D310 80061F10 44810000 */  mtc1      $at, $f0
/* 3D314 80061F14 4600D002 */  mul.s     $f0, $f26, $f0
/* 3D318 80061F18 3C0142FE */  lui       $at, (0x42FE0000 >> 16)
/* 3D31C 80061F1C 44811000 */  mtc1      $at, $f2
/* 3D320 80061F20 4602003C */  c.lt.s    $f0, $f2
/* 3D324 80061F24 45000005 */  bc1f      .LIQUE_80061F3C
/* 3D328 80061F28 2402007F */   addiu    $v0, $zero, 0x7F
/* 3D32C 80061F2C 4600038D */  trunc.w.s $f14, $f0
/* 3D330 80061F30 44027000 */  mfc1      $v0, $f14
/* 3D334 80061F34 080187D0 */  j         .LIQUE_80061F40
/* 3D338 80061F38 A202001A */   sb       $v0, 0x1A($s0)
.LIQUE_80061F3C:
/* 3D33C 80061F3C A202001A */  sb        $v0, 0x1A($s0)
.LIQUE_80061F40:
/* 3D340 80061F40 C7AE0070 */  lwc1      $f14, 0x70($sp)
/* 3D344 80061F44 46187182 */  mul.s     $f6, $f14, $f24
/* 3D348 80061F48 C7B20074 */  lwc1      $f18, 0x74($sp)
/* 3D34C 80061F4C 46149002 */  mul.s     $f0, $f18, $f20
/* 3D350 80061F50 C7AE0078 */  lwc1      $f14, 0x78($sp)
/* 3D354 80061F54 46167302 */  mul.s     $f12, $f14, $f22
/* 3D358 80061F58 C7B20070 */  lwc1      $f18, 0x70($sp)
/* 3D35C 80061F5C 461C9102 */  mul.s     $f4, $f18, $f28
/* 3D360 80061F60 C7AE0074 */  lwc1      $f14, 0x74($sp)
/* 3D364 80061F64 A2000000 */  sb        $zero, 0x0($s0)
/* 3D368 80061F68 461E7402 */  mul.s     $f16, $f14, $f30
/* 3D36C 80061F6C A2000001 */  sb        $zero, 0x1($s0)
/* 3D370 80061F70 A2000002 */  sb        $zero, 0x2($s0)
/* 3D374 80061F74 C7B20078 */  lwc1      $f18, 0x78($sp)
/* 3D378 80061F78 461A9482 */  mul.s     $f18, $f18, $f26
/* 3D37C 80061F7C 46003180 */  add.s     $f6, $f6, $f0
/* 3D380 80061F80 460C3180 */  add.s     $f6, $f6, $f12
/* 3D384 80061F84 E7B20020 */  swc1      $f18, 0x20($sp)
/* 3D388 80061F88 A2000003 */  sb        $zero, 0x3($s0)
/* 3D38C 80061F8C A2000004 */  sb        $zero, 0x4($s0)
/* 3D390 80061F90 A2000005 */  sb        $zero, 0x5($s0)
/* 3D394 80061F94 A2000006 */  sb        $zero, 0x6($s0)
/* 3D398 80061F98 C7AE0070 */  lwc1      $f14, 0x70($sp)
/* 3D39C 80061F9C C7B20010 */  lwc1      $f18, 0x10($sp)
/* 3D3A0 80061FA0 24020080 */  addiu     $v0, $zero, 0x80
/* 3D3A4 80061FA4 46127082 */  mul.s     $f2, $f14, $f18
/* 3D3A8 80061FA8 A2000007 */  sb        $zero, 0x7($s0)
/* 3D3AC 80061FAC A2000010 */  sb        $zero, 0x10($s0)
/* 3D3B0 80061FB0 A2020011 */  sb        $v0, 0x11($s0)
/* 3D3B4 80061FB4 C7AE0074 */  lwc1      $f14, 0x74($sp)
/* 3D3B8 80061FB8 C7B20014 */  lwc1      $f18, 0x14($sp)
/* 3D3BC 80061FBC 46127282 */  mul.s     $f10, $f14, $f18
/* 3D3C0 80061FC0 A2000012 */  sb        $zero, 0x12($s0)
/* 3D3C4 80061FC4 A2000013 */  sb        $zero, 0x13($s0)
/* 3D3C8 80061FC8 A2000014 */  sb        $zero, 0x14($s0)
/* 3D3CC 80061FCC A2020015 */  sb        $v0, 0x15($s0)
/* 3D3D0 80061FD0 C7AE0078 */  lwc1      $f14, 0x78($sp)
/* 3D3D4 80061FD4 C7B20018 */  lwc1      $f18, 0x18($sp)
/* 3D3D8 80061FD8 3C013F80 */  lui       $at, (0x3F800000 >> 16)
/* 3D3DC 80061FDC 44810000 */  mtc1      $at, $f0
/* 3D3E0 80061FE0 46127202 */  mul.s     $f8, $f14, $f18
/* 3D3E4 80061FE4 A2000016 */  sb        $zero, 0x16($s0)
/* 3D3E8 80061FE8 A2000017 */  sb        $zero, 0x17($s0)
/* 3D3EC 80061FEC E6380000 */  swc1      $f24, 0x0($s1)
/* 3D3F0 80061FF0 E6340010 */  swc1      $f20, 0x10($s1)
/* 3D3F4 80061FF4 E6360020 */  swc1      $f22, 0x20($s1)
/* 3D3F8 80061FF8 E63C0004 */  swc1      $f28, 0x4($s1)
/* 3D3FC 80061FFC E63E0014 */  swc1      $f30, 0x14($s1)
/* 3D400 80062000 E63A0024 */  swc1      $f26, 0x24($s1)
/* 3D404 80062004 C7AE0010 */  lwc1      $f14, 0x10($sp)
/* 3D408 80062008 8FBF0030 */  lw        $ra, 0x30($sp)
/* 3D40C 8006200C 8FB00028 */  lw        $s0, 0x28($sp)
/* 3D410 80062010 D7BE0060 */  ldc1      $f30, 0x60($sp)
/* 3D414 80062014 D7BC0058 */  ldc1      $f28, 0x58($sp)
/* 3D418 80062018 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* 3D41C 8006201C D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3D420 80062020 46102100 */  add.s     $f4, $f4, $f16
/* 3D424 80062024 E62E0008 */  swc1      $f14, 0x8($s1)
/* 3D428 80062028 C7B20014 */  lwc1      $f18, 0x14($sp)
/* 3D42C 8006202C 46003187 */  neg.s     $f6, $f6
/* 3D430 80062030 E6320018 */  swc1      $f18, 0x18($s1)
/* 3D434 80062034 C7AE0020 */  lwc1      $f14, 0x20($sp)
/* 3D438 80062038 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3D43C 8006203C 460E2100 */  add.s     $f4, $f4, $f14
/* 3D440 80062040 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3D444 80062044 C7B20018 */  lwc1      $f18, 0x18($sp)
/* 3D448 80062048 460A1080 */  add.s     $f2, $f2, $f10
/* 3D44C 8006204C E6320028 */  swc1      $f18, 0x28($s1)
/* 3D450 80062050 AE20000C */  sw        $zero, 0xC($s1)
/* 3D454 80062054 AE20001C */  sw        $zero, 0x1C($s1)
/* 3D458 80062058 AE20002C */  sw        $zero, 0x2C($s1)
/* 3D45C 8006205C 46081080 */  add.s     $f2, $f2, $f8
/* 3D460 80062060 E620003C */  swc1      $f0, 0x3C($s1)
/* 3D464 80062064 E6260030 */  swc1      $f6, 0x30($s1)
/* 3D468 80062068 46002107 */  neg.s     $f4, $f4
/* 3D46C 8006206C E6240034 */  swc1      $f4, 0x34($s1)
/* 3D470 80062070 46001087 */  neg.s     $f2, $f2
/* 3D474 80062074 E6220038 */  swc1      $f2, 0x38($s1)
/* 3D478 80062078 8FB1002C */  lw        $s1, 0x2C($sp)
/* 3D47C 8006207C 03E00008 */  jr        $ra
/* 3D480 80062080 27BD0068 */   addiu    $sp, $sp, 0x68

glabel guLookAtReflect
/* 3D484 80062084 27BDFF88 */  addiu     $sp, $sp, -0x78
/* 3D488 80062088 AFB00070 */  sw        $s0, 0x70($sp)
/* 3D48C 8006208C 00808021 */  addu      $s0, $a0, $zero
/* 3D490 80062090 C7A00088 */  lwc1      $f0, 0x88($sp)
/* 3D494 80062094 C7A2008C */  lwc1      $f2, 0x8C($sp)
/* 3D498 80062098 C7A40090 */  lwc1      $f4, 0x90($sp)
/* 3D49C 8006209C C7A60094 */  lwc1      $f6, 0x94($sp)
/* 3D4A0 800620A0 C7A80098 */  lwc1      $f8, 0x98($sp)
/* 3D4A4 800620A4 C7AA009C */  lwc1      $f10, 0x9C($sp)
/* 3D4A8 800620A8 C7AC00A0 */  lwc1      $f12, 0xA0($sp)
/* 3D4AC 800620AC 27A40030 */  addiu     $a0, $sp, 0x30
/* 3D4B0 800620B0 AFBF0074 */  sw        $ra, 0x74($sp)
/* 3D4B4 800620B4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3D4B8 800620B8 E7A20014 */  swc1      $f2, 0x14($sp)
/* 3D4BC 800620BC E7A40018 */  swc1      $f4, 0x18($sp)
/* 3D4C0 800620C0 E7A6001C */  swc1      $f6, 0x1C($sp)
/* 3D4C4 800620C4 E7A80020 */  swc1      $f8, 0x20($sp)
/* 3D4C8 800620C8 E7AA0024 */  swc1      $f10, 0x24($sp)
/* 3D4CC 800620CC 0C018708 */  jal       guLookAtReflectF
/* 3D4D0 800620D0 E7AC0028 */   swc1     $f12, 0x28($sp)
/* 3D4D4 800620D4 27A40030 */  addiu     $a0, $sp, 0x30
/* 3D4D8 800620D8 0C0196B0 */  jal       guMtxF2L
/* 3D4DC 800620DC 02002821 */   addu     $a1, $s0, $zero
/* 3D4E0 800620E0 8FBF0074 */  lw        $ra, 0x74($sp)
/* 3D4E4 800620E4 8FB00070 */  lw        $s0, 0x70($sp)
/* 3D4E8 800620E8 03E00008 */  jr        $ra
/* 3D4EC 800620EC 27BD0078 */   addiu    $sp, $sp, 0x78
