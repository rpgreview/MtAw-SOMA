#pragma once
#include <stdbool.h>
#include <mtaw/utils.h>

#define IS_UNLOCKED                      1
#define IS_ASSET                         2
#define IS_AREA_OF_EXPERTISE             4
#define IS_INTERDISCIPLINARY_SPECIALTY   8
#define IS_ORDER_ROTE_SKILL             16

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
    unsigned short int modifiers;
};

extern struct skill_t skills[n_categories][n_mental_skills];

void print_skills();
void get_skill(struct skill_t *s, const char *target);
