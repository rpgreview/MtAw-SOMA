#pragma once
#include <stdbool.h>
#include "common/skills.h"

enum arcana {
    Death,
    Fate,
    Forces,
    Life,
    Matter,
    Mind,
    Prime,
    Space,
    Spirit,
    Time,
    n_arcana
};

struct arcanum_t {
    char *name;
    int dots;
    bool is_ruling;
    bool is_inferior;
};

struct rote {
    enum arcana arcanum;
    int level;
    char *spell;
    char *creator;
    struct skill_t *rote_skill;
};

extern bool awakened;
extern int gnosis;
extern int wisdom;
extern char *obsessions[];

extern int arcane_xp;
extern int arcane_xp_spent;
