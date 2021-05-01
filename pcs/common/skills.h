#pragma once
#include <stdbool.h>
#include "common/utils.h"

enum mental_skills {
    Academics,
    Computer,
    Crafts,
    Investigation,
    Medicine,
    Occult,
    Politics,
    Science,
    n_mental_skills
};

enum physical_skills {
    Athletics,
    Brawl,
    Drive,
    Firearms,
    Larceny,
    Stealth,
    Survival,
    Weaponry,
    n_physical_skills
};

enum social_skills {
    Animal_Ken,
    Empathy,
    Expression,
    Intimidation,
    Persuasion,
    Socialize,
    Streetwise,
    Subterfuge,
    n_social_skills
};

struct skill_t {
    enum category skill_category;
    char *name;
    char *specialization;
    int  dots;
    bool is_asset;
    bool is_order_rote_skill;
};

extern struct skill_t skills[n_categories][n_mental_skills];
extern char *skill_column_fmt[3];

void print_skills();
void get_skill(struct skill_t *s, const char *target);
