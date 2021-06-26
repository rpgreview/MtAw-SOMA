#pragma once

struct mundane_equipment_t {
    char *name;
    int  durability;
    int  structure;
    int  size;
    int  cost;
};

struct weapon_t {
    char *name;
    int  dmg;
    int  range_short;
    int  range_medium;
    int  range_long;
    int  clip;
    int  initiative;
    int  strength;
    int  size;
};

extern struct mundane_equipment_t misc_gear[];
extern struct weapon_t weapons[];

void print_mundane_equipment();
void print_weapons();
