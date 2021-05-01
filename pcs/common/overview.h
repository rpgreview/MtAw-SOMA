#pragma once
#include <stdbool.h>

struct character_overview {
    char *name;
    char *age;
    char *player;
    char *virtue;
    char *vice;
    char *concept;
    char *chronicle;
    char *faction;
    char *group;
    char *quote;
    char *background;
    char *description;
    char *roleplaying_hints;
};

extern struct character_overview overview;
extern char *aspirations[];
extern int mundane_xp;
extern int arcane_xp;
extern int mundane_xp_spent;
extern int arcane_xp_spent;
extern bool awakened;

void print_overview();
void print_notes();
