#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/StiltGuy.h"
#include "sprite/npc/StiltGuyUnfold.h"
#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/GeneralGuy.h"

#define NAMESPACE b_area_omo2_2_stilt_guy

extern s32 N(IdleAnimations)[];
extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(check_fall_off);
extern EvtScript N(check_fall_off_2);
extern EvtScript N(fallOff);
extern EvtScript N(onDeath);
extern EvtScript N(attack);
extern EvtScript N(shy_guy_return_home);
extern EvtScript N(shy_guy_takeTurn);
extern EvtScript N(shy_guy_idle);
extern EvtScript N(shy_guy_handleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_2               = 2,
    PRT_3               = 3,
    PRT_4               = 4,
    PRT_5               = 5,
    PRT_6               = 6,
    PRT_7               = 7,
    PRT_8               = 8,
};

#include "common/GetSelectedMoveID.inc.c"

API_CALLABLE(N(SetActorLevelToZero)) {
    get_actor(script->owner1.actorID)->actorBlueprint->level = 0;
    return ApiStatus_DONE2;
}

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

s32 N(IdleAnimations2)[] = {
    STATUS_KEY_NORMAL,    ANIM_StiltGuy_Anim01,
    STATUS_KEY_STONE,     ANIM_StiltGuy_Anim00,
    STATUS_KEY_SLEEP,     ANIM_StiltGuy_Anim04,
    STATUS_KEY_POISON,    ANIM_StiltGuy_Anim01,
    STATUS_KEY_STOP,      ANIM_StiltGuy_Anim00,
    STATUS_KEY_STATIC,    ANIM_StiltGuy_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_StiltGuy_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_StiltGuy_Anim00,
    STATUS_KEY_DIZZY,     ANIM_StiltGuy_Anim00,
    STATUS_KEY_FEAR,      ANIM_StiltGuy_Anim00,
    STATUS_END,
};

s32 N(IdleAnimations3)[] = {
    STATUS_KEY_NORMAL,    ANIM_StiltGuyUnfold_Anim00,
    STATUS_END,
};

s32 N(defenseTable2)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SHOCK,    0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              60,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               60,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

s32 N(statusTable2)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              70,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 40 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations2),
        .defenseTable = N(defenseTable2),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -5 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_3,
        .posOffset = { 0, 74, 0 },
        .targetOffset = { 0, -8 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable2),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -3 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_4,
        .posOffset = { -2, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable2),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, 5 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_20000000,
        .index = PRT_5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations3),
        .defenseTable = N(defenseTable2),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_20000000,
        .index = PRT_6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations3),
        .defenseTable = N(defenseTable2),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_20000000,
        .index = PRT_7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations3),
        .defenseTable = N(defenseTable2),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_20000000,
        .index = PRT_8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations3),
        .defenseTable = N(defenseTable2),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_STILT_GUY,
    .level = 0,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 75 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 70 },
    .statusTextOffset = { 10, 65 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetPartTargetFlagBits, ACTOR_SELF, PRT_4, ACTOR_PART_TARGET_FLAG_1, TRUE)
    EVT_CALL(SetPartSize, ACTOR_SELF, PRT_MAIN, 24, 30)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_8, 0, 13, 0)
    EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_7, 0, 13, 0)
    EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_6, 0, 13, 0)
    EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_5, 0, 13, 0)
    EVT_THREAD
        EVT_SET(LVar0, 90)
        EVT_SET(LVar1, 270)
        EVT_LOOP(5)
            EVT_LOOP(2)
                EVT_LABEL(0)
                EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_8, LVar1, 0, 0)
                EVT_WAIT(1)
                EVT_SUB(LVar1, LVar0)
                EVT_IF_GE(LVar1, -90)
                    EVT_GOTO(0)
                EVT_END_IF
                EVT_ADD(LVar1, 360)
            EVT_END_LOOP
            EVT_SUB(LVar0, 15)
        EVT_END_LOOP
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_8, -90, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_8, EVT_FLOAT(0.6))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_8, ANIM_StiltGuyUnfold_Anim03)
        EVT_CALL(GetActorPos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_SET(LVar0, 10)
            EVT_CALL(PlaySound, SOUND_305)
        EVT_ELSE
            EVT_SET(LVar0, 50)
            EVT_CALL(PlaySound, SOUND_306)
        EVT_END_IF
        EVT_SUB(LVar2, 13)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_8, LVar0, 200, LVar2)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, 200, LVar2)
        EVT_CALL(SetAnimation, ACTOR_ENEMY0, PRT_MAIN, ANIM_GeneralGuy_Anim02)
        EVT_CALL(SetAnimation, ACTOR_ENEMY0, PRT_MAIN, ANIM_GeneralGuy_Anim0A)
        EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, PRT_MAIN, SOUND_GENERAL_WHISTLE)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_8, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_CALL(FallPartTo, ACTOR_SELF, PRT_8, LVar0, -9, LVar2, 80)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15)
        EVT_SET(LVar0, 90)
        EVT_SET(LVar1, 450)
        EVT_LOOP(5)
            EVT_LOOP(2)
                EVT_LABEL(1)
                EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_7, LVar1, 0, 0)
                EVT_WAIT(1)
                EVT_SUB(LVar1, LVar0)
                EVT_IF_GE(LVar1, 90)
                    EVT_GOTO(1)
                EVT_END_IF
                EVT_ADD(LVar1, 360)
            EVT_END_LOOP
            EVT_SUB(LVar0, 15)
        EVT_END_LOOP
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_7, 90, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_7, EVT_FLOAT(0.6))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_7, ANIM_StiltGuyUnfold_Anim02)
        EVT_CALL(GetActorPos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_SET(LVar0, 10)
        EVT_ELSE
            EVT_SET(LVar0, 50)
        EVT_END_IF
        EVT_SUB(LVar2, 13)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_7, LVar0, 200, LVar2)
        EVT_WAIT(15)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_7, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_CALL(FallPartTo, ACTOR_SELF, PRT_7, LVar0, -9, LVar2, 80)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(30)
        EVT_SET(LVar0, 90)
        EVT_SET(LVar1, 270)
        EVT_LOOP(5)
            EVT_LOOP(2)
                EVT_LABEL(2)
                EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_6, LVar1, 0, 0)
                EVT_WAIT(1)
                EVT_SUB(LVar1, LVar0)
                EVT_IF_GE(LVar1, -90)
                    EVT_GOTO(2)
                EVT_END_IF
                EVT_ADD(LVar1, 360)
            EVT_END_LOOP
            EVT_SUB(LVar0, 15)
        EVT_END_LOOP
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_6, -90, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_6, EVT_FLOAT(0.6))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_6, ANIM_StiltGuyUnfold_Anim01)
        EVT_CALL(GetActorPos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_SET(LVar0, 10)
        EVT_ELSE
            EVT_SET(LVar0, 50)
        EVT_END_IF
        EVT_SUB(LVar2, 13)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_6, LVar0, 200, LVar2)
        EVT_WAIT(30)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_6, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_CALL(FallPartTo, ACTOR_SELF, PRT_6, LVar0, -9, LVar2, 80)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(45)
        EVT_SET(LVar0, 90)
        EVT_SET(LVar1, 450)
        EVT_LOOP(5)
            EVT_LOOP(2)
                EVT_LABEL(3)
                EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_5, LVar1, 0, 0)
                EVT_WAIT(1)
                EVT_SUB(LVar1, LVar0)
                EVT_IF_GE(LVar1, 90)
                    EVT_GOTO(3)
                EVT_END_IF
                EVT_ADD(LVar1, 360)
            EVT_END_LOOP
            EVT_SUB(LVar0, 15)
        EVT_END_LOOP
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_5, 90, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_5, EVT_FLOAT(0.6))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_5, ANIM_StiltGuyUnfold_Anim00)
        EVT_CALL(GetActorPos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_SET(LVar0, 10)
        EVT_ELSE
            EVT_SET(LVar0, 50)
        EVT_END_IF
        EVT_SUB(LVar2, 13)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_5, LVar0, 200, LVar2)
        EVT_WAIT(45)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_5, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_CALL(FallPartTo, ACTOR_SELF, PRT_5, LVar0, -9, LVar2, 80)
        EVT_WAIT(15)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_6, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_7, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_8, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_8, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 13)
        EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, 0, LVar2)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_5, LVar0, 0, LVar2)
        EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_5, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_5, LVar0, 0, LVar2)
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_5, 0, 0, 0)
        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_8, 0, 0, 0)
        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_7, 0, 0, 0)
        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_6, 0, 0, 0)
        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_5, 0, 0, 0)
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_5, SOUND_2065)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_5, ANIM_StiltGuyUnfold_Anim05)
        EVT_CALL(func_8026ED20, ACTOR_SELF, PRT_5, 1)
        EVT_CALL(SetActorPaletteSwapParams, ACTOR_SELF, PRT_5, SPR_PAL_StiltGuyUnfold_Alt, SPR_PAL_StiltGuyUnfold, 0, 36, 0, 255, 0, 0)
        EVT_CALL(SetActorPaletteEffect, ACTOR_SELF, PRT_5, PAL_ADJUST_BLEND_PALSETS)
        EVT_WAIT(18)
        EVT_CALL(func_8026ED20, ACTOR_SELF, PRT_5, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_5, ANIM_StiltGuyUnfold_Anim04)
        EVT_WAIT(5)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_5, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_5, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(SetActorVar, ACTOR_ENEMY1, 1, 3)
        EVT_ELSE
        EVT_END_IF
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(return_home) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(shy_guy_return_home))
        EVT_RETURN
    EVT_END_IF
    EVT_SET_CONST(LVar0, 2)
    EVT_SET_CONST(LVar1, ANIM_StiltGuy_Anim03)
    EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_StiltGuy_Anim01)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastElement, LVarF)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_EXEC_WAIT(N(check_fall_off))
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_StiltGuy_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_StiltGuy_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_SPIN_SMASH_HIT)
        EVT_CASE_OR_EQ(EVENT_SPIN_SMASH_LAUNCH_HIT)
            EVT_CALL(GetBattleFlags, LVar2)
            EVT_IF_FLAG(LVar2, BS_FLAGS1_PARTNER_ACTING)
                EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
                EVT_IF_EQ(LVar2, MOVE_SPOOK)
                    EVT_SET(LVar0, 2)
                    EVT_SET(LVar1, ANIM_StiltGuy_Anim01)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_StiltGuy_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(check_fall_off_2))
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_EXEC_WAIT(N(fallOff))
            EVT_END_IF
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_StiltGuy_Anim06)
            EVT_WAIT(1000)
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET(LVar0, 2)
            EVT_SET(LVar1, ANIM_StiltGuy_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetDamageSource, LVar0)
            EVT_IF_NE(LVar0, DMG_SRC_FIRE_SHELL)
                EVT_SET(LVar0, 2)
                EVT_SET(LVar1, ANIM_StiltGuy_Anim09)
                EVT_SET(LVar2, ANIM_StiltGuy_Anim0A)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_ELSE
                EVT_SET(LVar0, 2)
                EVT_SET(LVar1, ANIM_StiltGuy_Anim09)
                EVT_SET(LVar2, ANIM_StiltGuy_Anim0A)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_EXEC_WAIT(N(fallOff))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, 2)
            EVT_SET(LVar1, ANIM_StiltGuy_Anim09)
            EVT_SET(LVar2, ANIM_StiltGuy_Anim0A)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_StiltGuy_Anim0A)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_StiltGuy_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_StiltGuy_Anim07)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_StiltGuy_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(return_home))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_StiltGuy_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_StiltGuy_Anim07)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_StiltGuy_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_StiltGuy_Anim07)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(return_home))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_StiltGuy_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_StiltGuy_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(1000)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_StiltGuy_Anim03)
            EVT_SET_CONST(LVar2, ANIM_StiltGuy_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(check_fall_off) = {
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_PARTNER_ACTING)
        EVT_IF_FLAG(LVar0, BS_FLAGS1_40 | BS_FLAGS1_200)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(N(GetSelectedMoveID), LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_OR_EQ(MOVE_HEADBONK1)
            EVT_CASE_OR_EQ(MOVE_HEADBONK2)
            EVT_CASE_OR_EQ(MOVE_HEADBONK3)
            EVT_CASE_OR_EQ(MOVE_MULTIBONK)
                EVT_CALL(GetBattleFlags, LVar0)
                EVT_IF_FLAG(LVar0, BS_FLAGS1_40 | BS_FLAGS1_200)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
                EVT_END_IF
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(check_fall_off_2) = {
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_PARTNER_ACTING)
        EVT_IF_FLAG(LVarF, DAMAGE_TYPE_JUMP)
            EVT_IF_FLAG(LVar0, BS_FLAGS1_40 | BS_FLAGS1_200)
                EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LVarF, DAMAGE_TYPE_POW | DAMAGE_TYPE_QUAKE)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_SHRINK | STATUS_FLAG_STOP)
        EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_EXEC_WAIT(N(attack))
    EVT_RETURN
    EVT_END
};

EvtScript N(attack) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(SetBattleCamOffsetZ, 40)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_StiltGuy_Anim03)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_StiltGuy_Anim04)
    EVT_WAIT(8)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_THREAD
                EVT_WAIT(9)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_StiltGuy_Anim04)
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_StiltGuy_Anim05)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 15)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2EF)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2066)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 25)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2066)
            EVT_WAIT(15)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_2, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(return_home))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_2, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_StiltGuy_Anim04)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_StiltGuy_Anim05)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2EF)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 8, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2066)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_StiltGuy_Anim01)
            EVT_WAIT(8)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(return_home))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(fallOff) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
    EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_MULTI_TARGET)
    EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_3, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_NO_TARGET)
    EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_4, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_NO_TARGET)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim0C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar1, 50)
    EVT_ELSE
        EVT_ADD(LVar1, 20)
    EVT_END_IF
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_WAIT(6)
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_2, SOUND_2067)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_StiltGuy_Anim08)
        EVT_SET(LVar0, 0)
        EVT_LOOP(15)
            EVT_ADD(LVar0, 6)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_2, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_2, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_NO_TARGET)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_2, SOUND_301)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_CALL(RandInt, 100, LVar1)
    EVT_IF_LT(LVar1, 50)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim10)
        EVT_WAIT(10)
    EVT_END_IF
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(shy_guy_takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(shy_guy_idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(shy_guy_handleEvent)))
    EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_SHY_GUY)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, TRUE)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(GetActorSize, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(SetActorSize, ACTOR_SELF, 24, LVar1)
    EVT_CALL(N(SetActorLevelToZero))
    EVT_RETURN
    EVT_END
};

EvtScript N(onDeath) = {
    EVT_EXEC_WAIT(EVS_Enemy_DeathWithoutRemove)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(GetActorVar, ACTOR_ENEMY1, 2, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_ENEMY1, 2, LVar0)
    EVT_IF_GE(LVar0, 2)
        EVT_CALL(FreezeBattleState, TRUE)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 100)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(shy_guy_rotate) = {
    EVT_SET(LVar0, 0)
    EVT_LABEL(0)
    EVT_SUB(LVar0, 30)
    EVT_IF_LT(LVar0, 0)
        EVT_ADD(LVar0, 360)
    EVT_END_IF
    EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(shy_guy_on_spin_smash) = {
    EVT_EXEC_GET_TID(N(shy_guy_rotate), LVarE)
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, LVar0, LVarA)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(PlayerCreateTargetList, TARGET_FLAG_4 | TARGET_FLAG_10000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerID, LVar1)
    EVT_CALL(GetOwnerTarget, LVar0, LVar9)
    EVT_IF_NE(LVar1, LVar0)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_ADD(LVarF, 1)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_EQ(LVar0, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GetOwnerTarget, LVar0, LVar9)
    EVT_CALL(GetActorFlags, LVar0, LVar1)
    EVT_IF_FLAG(LVar1, ACTOR_FLAG_TARGET_ONLY)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_ALL, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_GOTO(1)
    EVT_LABEL(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(GetActorSize, ACTOR_SELF, LVar0, LVar3)
    EVT_DIV(LVar3, 2)
    EVT_SET(LVar4, 70)
    EVT_SUB(LVar4, LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar5, LVar4)
    EVT_SUB(LVar5, LVar0)
    EVT_IF_LT(LVar5, 6)
        EVT_SET(LVar5, 1)
    EVT_ELSE
        EVT_SET(LVar5, 0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, LVar5, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar6, LVar7, LVar8)
    EVT_SUB(LVar4, 18)
    EVT_IF_LE(LVar4, LVar6)
        EVT_SET(LVar4, LVar6)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_ELSE
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalToHome, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar4, LVar7, LVar8)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_END_IF
    EVT_KILL_THREAD(LVarE)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

s32 N(IdleAnimations)[] = {
    STATUS_KEY_NORMAL,    ANIM_ShyGuy_Red_Anim01,
    STATUS_KEY_STONE,     ANIM_ShyGuy_Red_Anim00,
    STATUS_KEY_SLEEP,     ANIM_ShyGuy_Red_Anim12,
    STATUS_KEY_POISON,    ANIM_ShyGuy_Red_Anim01,
    STATUS_KEY_STOP,      ANIM_ShyGuy_Red_Anim00,
    STATUS_KEY_STATIC,    ANIM_ShyGuy_Red_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_ShyGuy_Red_Anim00,
    STATUS_KEY_DIZZY,     ANIM_ShyGuy_Red_Anim13,
    STATUS_KEY_FEAR,      ANIM_ShyGuy_Red_Anim13,
    STATUS_END,
};

EvtScript N(shy_guy_init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(shy_guy_takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(shy_guy_idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(shy_guy_handleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(shy_guy_idle) = {
    EVT_LABEL(0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -4, 14)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
        EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 13, 10, 13)
    EVT_ELSE
        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 24)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -10)
        EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(shy_guy_return_home) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim03)
    EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim01)
    EVT_RETURN
    EVT_END
};

EvtScript N(shy_guy_handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0D)
            EVT_SET_CONST(LVar2, ANIM_ShyGuy_Red_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0D)
            EVT_SET_CONST(LVar2, ANIM_ShyGuy_Red_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0E)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(N(shy_guy_on_spin_smash))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(N(shy_guy_on_spin_smash))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_JumpBack)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(shy_guy_return_home))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim03)
            EVT_SET_CONST(LVar2, ANIM_ShyGuy_Red_Anim14)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(shy_guy_attack1) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim03)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_2EF, 0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_20BA, SOUND_3B4)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim04)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim05)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim01)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2EF)
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_20BA, SOUND_3B4)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim05)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim01)
    EVT_WAIT(8)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_EXEC_WAIT(N(shy_guy_return_home))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(shy_guy_attack2) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_234)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim09)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim03)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 80)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_20BA, SOUND_3B4)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_SUB(LVar0, 40)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim09)
            EVT_THREAD
                EVT_WAIT(12)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim0A)
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 10)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 24, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim05)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim01)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim09)
    EVT_THREAD
        EVT_WAIT(9)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim0A)
    EVT_END_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                EVT_SET(LVar3, 0)
                EVT_LOOP(20)
                    EVT_SUB(LVar3, 30)
                    EVT_IF_LT(LVar3, 0)
                        EVT_ADD(LVar3, 360)
                    EVT_END_IF
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar3)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_349)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_349 | SOUND_ID_TRIGGER_CHANGE_SOUND)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim09)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim07)
            EVT_WAIT(15)
            EVT_GOTO(2)
            EVT_LABEL(1)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E4)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim10)
            EVT_WAIT(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20C3)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LT(LVar0, 50)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim11)
            EVT_ELSE
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim13)
            EVT_END_IF
            EVT_WAIT(25)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_LABEL(2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim01)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(shy_guy_takeTurn) = {
    EVT_CALL(RandInt, 1, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_EXEC_WAIT(N(shy_guy_attack1))
    EVT_ELSE
        EVT_EXEC_WAIT(N(shy_guy_attack2))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
