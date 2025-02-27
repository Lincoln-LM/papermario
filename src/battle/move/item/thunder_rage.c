#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "model.h"

#define NAMESPACE battle_item_thunder_rage

#include "battle/common/move/ItemRefund.inc.c"
#include "common/FadeBackgroundToBlack.inc.c"

API_CALLABLE(N(func_802A12D4_71B474)) {
    if (isInitialCall) {
        script->functionTemp[0] = 20;
    }

    set_background_color_blend(0, 0, 0, (script->functionTemp[0] * 10) & 254);

    script->functionTemp[0]--;
    if (script->functionTemp[0] == 0) {
        set_background_color_blend(0, 0, 0, 0);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_802A1354_71B4F4)) {
    Actor* enemyTarget = get_actor(script->owner1.enemyID);
    Actor* actor = get_actor(enemyTarget->targetActorID);
    f32 posY, posX, posZ;
    s32 scaleX, scaleY;

    if (actor != NULL) {
        sfx_play_sound(SOUND_366);

        posX = actor->currentPos.x;
        posY = actor->currentPos.y + (actor->size.y / 10);
        posZ = actor->currentPos.z;

        scaleX = (actor->size.x + (actor->size.x >> 2)) * actor->scalingFactor;
        scaleY = (actor->size.y - 2) * actor->scalingFactor;

        if (actor->flags & ACTOR_FLAG_8000) {
            posY -= actor->size.y / 2;
        }

        fx_lightning(rand_int(2) + 3, posX, posY, posZ, scaleX, scaleY);

        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    EVT_SET_CONST(LVarA, ITEM_THUNDER_RAGE)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CHILD_THREAD
        EVT_WAIT(5)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 20)
    EVT_END_CHILD_THREAD
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_CALL(PlaySound, SOUND_365)
    EVT_WAIT(10)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(ItemCheckHit, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, LVar0, 0)
        EVT_IF_EQ(LVar0, 6)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(N(func_802A1354_71B4F4))
        EVT_WAIT(5)
        EVT_CALL(StartRumble, 10)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetItemPower, ITEM_THUNDER_RAGE, LVar0, LVar1)
        EVT_CALL(ItemDamageEnemy, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_LABEL(1)
        EVT_WAIT(5)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, -1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_WAIT(30)
    EVT_CALL(N(func_802A12D4_71B474))
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
