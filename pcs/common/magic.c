#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "common/attributes.h"
#include "common/skills.h"
#include "common/magic.h"
#include "common/merits.h"

int arcane_xp_spent = 0;
bool awakened = false;
int gnosis = 0;
int wisdom = 0;

void print_arcana() {
    printf("```\n");
    char *dot_str;
    for(int a = 0; a < n_paths*n_manifestations; ++a) {
        dot_str = dots(arcana[a].dots, 5);
        printf("%-7s %s", arcana[a].name, dot_str);
        free(dot_str);
        if(arcana[a].status != Common) {
            printf(" (%s)", arcanum_status_names[arcana[a].status]);
        }
        printf("\n");
    }
    printf("```\n");
}

void print_rotes() {
    printf("```\n");
    printf(    "%-7s %-5s %-16s %-16s %s\n", "Arcanum",              "Level",        "Spell",        "Creator",          "Rote Skill");
    for(int r = 0; rotes[r].spell != NULL; ++r) {
        printf("%-7s %5d %-16s %-16s %s\n",  rotes[r].arcanum->name, rotes[r].level, rotes[r].spell, rotes[r].creator,   rotes[r].rote_skill->name);
    }
    printf("```\n");
}

void print_praxes() {
    printf("```\n");
    for(int p = 0; praxes[p] != NULL; printf("%s\n", praxes[p++]));
    printf("```\n");
}
