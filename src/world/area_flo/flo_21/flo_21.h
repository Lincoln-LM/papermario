/// @file flo_21.h
/// @brief Flower Fields - Huff N Puff Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_21_shape.h"
#include "mapfs/flo_21_hit.h"

enum {
    NPC_HuffNPuff_01            = 0,
    NPC_HuffNPuff_02            = 1,
    NPC_HuffNPuff_03            = 2,
    NPC_TuffPuff_01             = 3,
    NPC_TuffPuff_02             = 4,
    NPC_TuffPuff_03             = 5,
    NPC_TuffPuff_04             = 6,
    NPC_TuffPuff_05             = 7,
    NPC_TuffPuff_06             = 8,
    NPC_TuffPuff_07             = 9,
    NPC_TuffPuff_08             = 10,
    NPC_TuffPuff_09             = 11,
    NPC_TuffPuff_10             = 12,
    NPC_TuffPuff_11             = 13,
    NPC_TuffPuff_12             = 14,
    NPC_TuffPuff_13             = 15,
    NPC_TuffPuff_14             = 16,
    NPC_TuffPuff_15             = 17,
};

enum {
    MV_Unk_00           = MapVar(0),
    MV_Unk_01           = MapVar(1),
    MV_Unk_02           = MapVar(2),
    MV_Unk_03           = MapVar(3),
    MV_Unk_04           = MapVar(4),
    MV_BossDefeated     = MapVar(10),
    MV_HuffScaleX       = MapVar(11),
    MV_HuffScaleY       = MapVar(12),
    MV_BossFightState   = MapVar(13),
};

#define NAMESPACE flo_21

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupCloudPuffs);
extern EvtScript N(EVS_Scene_HuffNPuffAmbush);
extern EvtScript N(EVS_TrySpawningStarCard);

extern NpcGroupList N(DefaultNPCs);
