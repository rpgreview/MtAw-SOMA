#include <stdio.h>
#include "common/inventory.h"

void print_mundane_equipment() {
    printf("```\n");
    printf(     "%-18s %10s %11s %12s %10s\n", "Equipment", "Durability", "Structure", "Size", "Cost");
    char *fmt = "%-18s %10d %11d %12d %10d\n";
    int g = 0;
    for(; misc_gear[g].name != NULL; ++g) {
        printf(fmt, misc_gear[g].name, misc_gear[g].durability, misc_gear[g].structure, misc_gear[g].size, misc_gear[g].cost);
    }
    if(g == 0) {
        printf("(None)\n");
    }
    printf("```\n");
}

void print_weapons() {
    printf("```\n");
    printf(     "%-18s %3s %8s %6s %6s %6s %6s %6s %6s\n", "Weapon/Attack", "Dmg", "Short", "Medium", "Long", "Clip", "Init", "Str", "Size");
    char *fmt = "%-18s %3d %8d %6d %6d %6d %6d %6d %6d\n";
    int w = 0;
    for(; weapons[w].name != NULL; ++w) {
        printf(fmt, weapons[w].name, weapons[w].dmg, weapons[w].range_short, weapons[w].range_medium, weapons[w].range_long, weapons[w].clip, weapons[w].initiative, weapons[w].strength, weapons[w].size);
    }
    if(w == 0) {
        printf("(None)\n");
    }
    printf("```\n");
}
