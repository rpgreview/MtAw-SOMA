#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "common/overview.h"

int mundane_xp_spent = 0;
int arcane_xp_spent = 0;
bool awakened = false;

void print_overview() {
    printf("%s\n", overview.name);
    int name_len = strnlen(overview.name, 128);
    for(int c = 0; c < name_len; ++c) {
        printf("=");
    }
    printf("\n\n");

    char *fmt = "%-9s %-24s\n";
    printf(fmt, "Concept:",     overview.concept);
    printf(fmt, "Virtue:",      overview.virtue);
    printf(fmt, "Vice:",        overview.vice);
    printf("\n");

    printf("Aspirations:\n");
    int c = 0;
    while(aspirations[c] != NULL) {
        printf("- %s\n", aspirations[c++]);
    }
    printf("\n");

    printf("Unspent XP: %d\n", mundane_xp - mundane_xp_spent);
    if(awakened) {
        printf("Unspent Arcane XP: %d\n", arcane_xp - arcane_xp_spent);
    }
}
