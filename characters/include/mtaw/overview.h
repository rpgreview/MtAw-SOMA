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
    char *path;
    char *order;
    char *legacy;
    char *nimbus;
    char *quote;
    char *background;
    char *description;
    char *roleplaying_hints;
    bool is_npc;
};

extern struct character_overview overview;
extern char *aspirations[];
extern int mundane_xp;
extern int mundane_xp_spent;

void print_overview();
void print_notes();
