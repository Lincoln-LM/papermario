.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetSelfAnimationFromTable
/* 020B34 80045734 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 020B38 80045738 AFB10014 */  sw    $s1, 0x14($sp)
/* 020B3C 8004573C 0080882D */  daddu $s1, $a0, $zero
/* 020B40 80045740 AFBF001C */  sw    $ra, 0x1c($sp)
/* 020B44 80045744 AFB20018 */  sw    $s2, 0x18($sp)
/* 020B48 80045748 AFB00010 */  sw    $s0, 0x10($sp)
/* 020B4C 8004574C 8E30000C */  lw    $s0, 0xc($s1)
/* 020B50 80045750 8E320148 */  lw    $s2, 0x148($s1)
/* 020B54 80045754 8E050000 */  lw    $a1, ($s0)
/* 020B58 80045758 0C0B1EAF */  jal   get_variable
/* 020B5C 8004575C 26100004 */   addiu $s0, $s0, 4
/* 020B60 80045760 00021080 */  sll   $v0, $v0, 2
/* 020B64 80045764 8E4300CC */  lw    $v1, 0xcc($s2)
/* 020B68 80045768 8E050000 */  lw    $a1, ($s0)
/* 020B6C 8004576C 00431021 */  addu  $v0, $v0, $v1
/* 020B70 80045770 8C460000 */  lw    $a2, ($v0)
/* 020B74 80045774 0C0B2026 */  jal   set_variable
/* 020B78 80045778 0220202D */   daddu $a0, $s1, $zero
/* 020B7C 8004577C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 020B80 80045780 8FB20018 */  lw    $s2, 0x18($sp)
/* 020B84 80045784 8FB10014 */  lw    $s1, 0x14($sp)
/* 020B88 80045788 8FB00010 */  lw    $s0, 0x10($sp)
/* 020B8C 8004578C 24020002 */  addiu $v0, $zero, 2
/* 020B90 80045790 03E00008 */  jr    $ra
/* 020B94 80045794 27BD0020 */   addiu $sp, $sp, 0x20

/* 020B98 80045798 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 020B9C 8004579C AFBF0010 */  sw    $ra, 0x10($sp)
/* 020BA0 800457A0 8C82000C */  lw    $v0, 0xc($a0)
/* 020BA4 800457A4 0C0B1EAF */  jal   get_variable
/* 020BA8 800457A8 8C450000 */   lw    $a1, ($v0)
/* 020BAC 800457AC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 020BB0 800457B0 3C018011 */  lui   $at, 0x8011
/* 020BB4 800457B4 AC22EF08 */  sw    $v0, -0x10f8($at)
/* 020BB8 800457B8 24020002 */  addiu $v0, $zero, 2
/* 020BBC 800457BC 03E00008 */  jr    $ra
/* 020BC0 800457C0 27BD0018 */   addiu $sp, $sp, 0x18

/* 020BC4 800457C4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 020BC8 800457C8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 020BCC 800457CC AFB00010 */  sw    $s0, 0x10($sp)
/* 020BD0 800457D0 8C82000C */  lw    $v0, 0xc($a0)
/* 020BD4 800457D4 8C450000 */  lw    $a1, ($v0)
/* 020BD8 800457D8 0C0B1EAF */  jal   get_variable
/* 020BDC 800457DC 8C900148 */   lw    $s0, 0x148($a0)
/* 020BE0 800457E0 A20200B5 */  sb    $v0, 0xb5($s0)
/* 020BE4 800457E4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 020BE8 800457E8 8FB00010 */  lw    $s0, 0x10($sp)
/* 020BEC 800457EC 24020002 */  addiu $v0, $zero, 2
/* 020BF0 800457F0 03E00008 */  jr    $ra
/* 020BF4 800457F4 27BD0018 */   addiu $sp, $sp, 0x18

/* 020BF8 800457F8 24020001 */  addiu $v0, $zero, 1
/* 020BFC 800457FC 3C01800B */  lui   $at, 0x800b
/* 020C00 80045800 A0220F22 */  sb    $v0, 0xf22($at)
/* 020C04 80045804 03E00008 */  jr    $ra
/* 020C08 80045808 24020002 */   addiu $v0, $zero, 2

/* 020C0C 8004580C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 020C10 80045810 AFBF0010 */  sw    $ra, 0x10($sp)
/* 020C14 80045814 8C82000C */  lw    $v0, 0xc($a0)
/* 020C18 80045818 3C06800B */  lui   $a2, 0x800b
/* 020C1C 8004581C 80C60F16 */  lb    $a2, 0xf16($a2)
/* 020C20 80045820 0C0B2026 */  jal   set_variable
/* 020C24 80045824 8C450000 */   lw    $a1, ($v0)
/* 020C28 80045828 8FBF0010 */  lw    $ra, 0x10($sp)
/* 020C2C 8004582C 24020002 */  addiu $v0, $zero, 2
/* 020C30 80045830 03E00008 */  jr    $ra
/* 020C34 80045834 27BD0018 */   addiu $sp, $sp, 0x18

/* 020C38 80045838 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 020C3C 8004583C AFB10014 */  sw    $s1, 0x14($sp)
/* 020C40 80045840 0080882D */  daddu $s1, $a0, $zero
/* 020C44 80045844 AFBF0020 */  sw    $ra, 0x20($sp)
/* 020C48 80045848 AFB3001C */  sw    $s3, 0x1c($sp)
/* 020C4C 8004584C AFB20018 */  sw    $s2, 0x18($sp)
/* 020C50 80045850 AFB00010 */  sw    $s0, 0x10($sp)
/* 020C54 80045854 8E30000C */  lw    $s0, 0xc($s1)
/* 020C58 80045858 8E050000 */  lw    $a1, ($s0)
/* 020C5C 8004585C 0C0B1EAF */  jal   get_variable
/* 020C60 80045860 26100004 */   addiu $s0, $s0, 4
/* 020C64 80045864 8E050000 */  lw    $a1, ($s0)
/* 020C68 80045868 26100004 */  addiu $s0, $s0, 4
/* 020C6C 8004586C 0220202D */  daddu $a0, $s1, $zero
/* 020C70 80045870 0C0B1EAF */  jal   get_variable
/* 020C74 80045874 0040902D */   daddu $s2, $v0, $zero
/* 020C78 80045878 0220202D */  daddu $a0, $s1, $zero
/* 020C7C 8004587C 8E050000 */  lw    $a1, ($s0)
/* 020C80 80045880 0C0B1EAF */  jal   get_variable
/* 020C84 80045884 0040982D */   daddu $s3, $v0, $zero
/* 020C88 80045888 0220202D */  daddu $a0, $s1, $zero
/* 020C8C 8004588C 0240282D */  daddu $a1, $s2, $zero
/* 020C90 80045890 0C0B36B0 */  jal   resolve_npc
/* 020C94 80045894 0040802D */   daddu $s0, $v0, $zero
/* 020C98 80045898 10400004 */  beqz  $v0, .L800458AC
/* 020C9C 8004589C 0040202D */   daddu $a0, $v0, $zero
/* 020CA0 800458A0 0260282D */  daddu $a1, $s3, $zero
/* 020CA4 800458A4 0C012530 */  jal   func_800494C0
/* 020CA8 800458A8 0200302D */   daddu $a2, $s0, $zero
.L800458AC:
/* 020CAC 800458AC 24020002 */  addiu $v0, $zero, 2
/* 020CB0 800458B0 8FBF0020 */  lw    $ra, 0x20($sp)
/* 020CB4 800458B4 8FB3001C */  lw    $s3, 0x1c($sp)
/* 020CB8 800458B8 8FB20018 */  lw    $s2, 0x18($sp)
/* 020CBC 800458BC 8FB10014 */  lw    $s1, 0x14($sp)
/* 020CC0 800458C0 8FB00010 */  lw    $s0, 0x10($sp)
/* 020CC4 800458C4 03E00008 */  jr    $ra
/* 020CC8 800458C8 27BD0028 */   addiu $sp, $sp, 0x28

/* 020CCC 800458CC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 020CD0 800458D0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 020CD4 800458D4 8C820148 */  lw    $v0, 0x148($a0)
/* 020CD8 800458D8 8C420018 */  lw    $v0, 0x18($v0)
/* 020CDC 800458DC 8C83000C */  lw    $v1, 0xc($a0)
/* 020CE0 800458E0 9446002A */  lhu   $a2, 0x2a($v0)
/* 020CE4 800458E4 8C650000 */  lw    $a1, ($v1)
/* 020CE8 800458E8 0C0B2026 */  jal   set_variable
/* 020CEC 800458EC 30C60008 */   andi  $a2, $a2, 8
/* 020CF0 800458F0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 020CF4 800458F4 24020002 */  addiu $v0, $zero, 2
/* 020CF8 800458F8 03E00008 */  jr    $ra
/* 020CFC 800458FC 27BD0018 */   addiu $sp, $sp, 0x18

/* 020D00 80045900 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 020D04 80045904 AFB00040 */  sw    $s0, 0x40($sp)
/* 020D08 80045908 0080802D */  daddu $s0, $a0, $zero
/* 020D0C 8004590C AFBF0048 */  sw    $ra, 0x48($sp)
/* 020D10 80045910 AFB10044 */  sw    $s1, 0x44($sp)
/* 020D14 80045914 8E110148 */  lw    $s1, 0x148($s0)
/* 020D18 80045918 0C00EABB */  jal   get_npc_unsafe
/* 020D1C 8004591C 86240008 */   lh    $a0, 8($s1)
/* 020D20 80045920 8E03000C */  lw    $v1, 0xc($s0)
/* 020D24 80045924 0200202D */  daddu $a0, $s0, $zero
/* 020D28 80045928 8C650000 */  lw    $a1, ($v1)
/* 020D2C 8004592C 0C0B1EAF */  jal   get_variable
/* 020D30 80045930 0040802D */   daddu $s0, $v0, $zero
/* 020D34 80045934 8E2300B0 */  lw    $v1, 0xb0($s1)
/* 020D38 80045938 34630004 */  ori   $v1, $v1, 4
/* 020D3C 8004593C 14400040 */  bnez  $v0, .L80045A40
/* 020D40 80045940 AE2300B0 */   sw    $v1, 0xb0($s1)
/* 020D44 80045944 30620010 */  andi  $v0, $v1, 0x10
/* 020D48 80045948 14400004 */  bnez  $v0, .L8004595C
/* 020D4C 8004594C 00000000 */   nop   
/* 020D50 80045950 8E2200CC */  lw    $v0, 0xcc($s1)
/* 020D54 80045954 8C420000 */  lw    $v0, ($v0)
/* 020D58 80045958 AE020028 */  sw    $v0, 0x28($s0)
.L8004595C:
/* 020D5C 8004595C 8E2200B0 */  lw    $v0, 0xb0($s1)
/* 020D60 80045960 30420008 */  andi  $v0, $v0, 8
/* 020D64 80045964 14400015 */  bnez  $v0, .L800459BC
/* 020D68 80045968 24040002 */   addiu $a0, $zero, 2
/* 020D6C 8004596C 0200282D */  daddu $a1, $s0, $zero
/* 020D70 80045970 860300A8 */  lh    $v1, 0xa8($s0)
/* 020D74 80045974 44800000 */  mtc1  $zero, $f0
/* 020D78 80045978 3C01C1A0 */  lui   $at, 0xc1a0
/* 020D7C 8004597C 44811000 */  mtc1  $at, $f2
/* 020D80 80045980 24020028 */  addiu $v0, $zero, 0x28
/* 020D84 80045984 AFA2001C */  sw    $v0, 0x1c($sp)
/* 020D88 80045988 44834000 */  mtc1  $v1, $f8
/* 020D8C 8004598C 00000000 */  nop   
/* 020D90 80045990 46804220 */  cvt.s.w $f8, $f8
/* 020D94 80045994 44060000 */  mfc1  $a2, $f0
/* 020D98 80045998 3C013F80 */  lui   $at, 0x3f80
/* 020D9C 8004599C 44810000 */  mtc1  $at, $f0
/* 020DA0 800459A0 44074000 */  mfc1  $a3, $f8
/* 020DA4 800459A4 03A21021 */  addu  $v0, $sp, $v0
/* 020DA8 800459A8 AFA20020 */  sw    $v0, 0x20($sp)
/* 020DAC 800459AC E7A20018 */  swc1  $f2, 0x18($sp)
/* 020DB0 800459B0 E7A00010 */  swc1  $f0, 0x10($sp)
/* 020DB4 800459B4 0C01BFA4 */  jal   fx_emote
/* 020DB8 800459B8 AFA60014 */   sw    $a2, 0x14($sp)
.L800459BC:
/* 020DBC 800459BC 8E020000 */  lw    $v0, ($s0)
/* 020DC0 800459C0 24030808 */  addiu $v1, $zero, 0x808
/* 020DC4 800459C4 30420A08 */  andi  $v0, $v0, 0xa08
/* 020DC8 800459C8 1443001D */  bne   $v0, $v1, .L80045A40
/* 020DCC 800459CC 27A5002C */   addiu $a1, $sp, 0x2c
/* 020DD0 800459D0 27A60030 */  addiu $a2, $sp, 0x30
/* 020DD4 800459D4 C6000038 */  lwc1  $f0, 0x38($s0)
/* 020DD8 800459D8 860200A8 */  lh    $v0, 0xa8($s0)
/* 020DDC 800459DC 3C0142C8 */  lui   $at, 0x42c8
/* 020DE0 800459E0 44812000 */  mtc1  $at, $f4
/* 020DE4 800459E4 44823000 */  mtc1  $v0, $f6
/* 020DE8 800459E8 00000000 */  nop   
/* 020DEC 800459EC 468031A0 */  cvt.s.w $f6, $f6
/* 020DF0 800459F0 27A20038 */  addiu $v0, $sp, 0x38
/* 020DF4 800459F4 E7A0002C */  swc1  $f0, 0x2c($sp)
/* 020DF8 800459F8 C600003C */  lwc1  $f0, 0x3c($s0)
/* 020DFC 800459FC C6020040 */  lwc1  $f2, 0x40($s0)
/* 020E00 80045A00 46060000 */  add.s $f0, $f0, $f6
/* 020E04 80045A04 E7A40038 */  swc1  $f4, 0x38($sp)
/* 020E08 80045A08 E7A20034 */  swc1  $f2, 0x34($sp)
/* 020E0C 80045A0C E7A00030 */  swc1  $f0, 0x30($sp)
/* 020E10 80045A10 AFA20010 */  sw    $v0, 0x10($sp)
/* 020E14 80045A14 8E040080 */  lw    $a0, 0x80($s0)
/* 020E18 80045A18 0C0372DF */  jal   func_800DCB7C
/* 020E1C 80045A1C 27A70034 */   addiu $a3, $sp, 0x34
/* 020E20 80045A20 10400003 */  beqz  $v0, .L80045A30
/* 020E24 80045A24 00000000 */   nop   
/* 020E28 80045A28 C7A00030 */  lwc1  $f0, 0x30($sp)
/* 020E2C 80045A2C E600003C */  swc1  $f0, 0x3c($s0)
.L80045A30:
/* 020E30 80045A30 8E020000 */  lw    $v0, ($s0)
/* 020E34 80045A34 2403F7FF */  addiu $v1, $zero, -0x801
/* 020E38 80045A38 00431024 */  and   $v0, $v0, $v1
/* 020E3C 80045A3C AE020000 */  sw    $v0, ($s0)
.L80045A40:
/* 020E40 80045A40 8FBF0048 */  lw    $ra, 0x48($sp)
/* 020E44 80045A44 8FB10044 */  lw    $s1, 0x44($sp)
/* 020E48 80045A48 8FB00040 */  lw    $s0, 0x40($sp)
/* 020E4C 80045A4C 24020002 */  addiu $v0, $zero, 2
/* 020E50 80045A50 03E00008 */  jr    $ra
/* 020E54 80045A54 27BD0050 */   addiu $sp, $sp, 0x50

/* 020E58 80045A58 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 020E5C 80045A5C AFB10014 */  sw    $s1, 0x14($sp)
/* 020E60 80045A60 0080882D */  daddu $s1, $a0, $zero
/* 020E64 80045A64 AFBF0018 */  sw    $ra, 0x18($sp)
/* 020E68 80045A68 AFB00010 */  sw    $s0, 0x10($sp)
/* 020E6C 80045A6C 8E30000C */  lw    $s0, 0xc($s1)
/* 020E70 80045A70 8E050000 */  lw    $a1, ($s0)
/* 020E74 80045A74 0C0B1EAF */  jal   get_variable
/* 020E78 80045A78 26100004 */   addiu $s0, $s0, 4
/* 020E7C 80045A7C 0220202D */  daddu $a0, $s1, $zero
/* 020E80 80045A80 8E050000 */  lw    $a1, ($s0)
/* 020E84 80045A84 0C0B1EAF */  jal   get_variable
/* 020E88 80045A88 0040802D */   daddu $s0, $v0, $zero
/* 020E8C 80045A8C 0200202D */  daddu $a0, $s0, $zero
/* 020E90 80045A90 0C00FB3A */  jal   get_enemy
/* 020E94 80045A94 0040802D */   daddu $s0, $v0, $zero
/* 020E98 80045A98 AC5000D8 */  sw    $s0, 0xd8($v0)
/* 020E9C 80045A9C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 020EA0 80045AA0 8FB10014 */  lw    $s1, 0x14($sp)
/* 020EA4 80045AA4 8FB00010 */  lw    $s0, 0x10($sp)
/* 020EA8 80045AA8 24020002 */  addiu $v0, $zero, 2
/* 020EAC 80045AAC 03E00008 */  jr    $ra
/* 020EB0 80045AB0 27BD0020 */   addiu $sp, $sp, 0x20

/* 020EB4 80045AB4 00000000 */  nop   
/* 020EB8 80045AB8 00000000 */  nop   
/* 020EBC 80045ABC 00000000 */  nop   


