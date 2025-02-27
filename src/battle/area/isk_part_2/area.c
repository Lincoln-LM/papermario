#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_2

extern ActorBlueprint N(tutankoopa);

extern Stage N(isk_00);
extern Stage N(isk_01);
extern Stage N(isk_02);
extern Stage N(isk_02b);
extern Stage N(isk_02c);
extern Stage N(isk_03);
extern Stage N(isk_03b);
extern Stage N(isk_04);
extern Stage N(isk_05);
extern Stage N(isk_06);
extern Stage N(isk_06b);
extern Stage N(isk_07);

Vec3i N(BossPos) = { 97, 70, 17 };

Formation N(Formation_00) = {
    ACTOR_BY_POS(N(tutankoopa), N(BossPos), 10),
};

BattleList N(Formations) = {
    BATTLE(N(Formation_00), N(isk_01), "カーメン　ワンワン"),
    {},
};

StageList N(Stages) = {
    STAGE("isk_00", N(isk_00)),
    STAGE("isk_01", N(isk_01)),
    STAGE("isk_02", N(isk_02)),
    STAGE("isk_02b", N(isk_02b)),
    STAGE("isk_02c", N(isk_02c)),
    STAGE("isk_03", N(isk_03)),
    STAGE("isk_03b", N(isk_03b)),
    STAGE("isk_04", N(isk_04)),
    STAGE("isk_05", N(isk_05)),
    STAGE("isk_06", N(isk_06)),
    STAGE("isk_06b", N(isk_06b)),
    STAGE("isk_07", N(isk_07)),
    {},
};
