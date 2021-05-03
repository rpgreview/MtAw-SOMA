#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "common/overview.h"
#include "common/magic.h"

int mundane_xp_spent = 0;

void print_overview() {
    printf("%s\n", overview.name);
    int name_len = strnlen(overview.name, 128);
    for(int c = 0; c < name_len; ++c) {
        printf("=");
    }
    printf("\n\n");

    char *fmt = "* %-8s %-24s\n";
    printf(fmt, "Player:",      overview.player);
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

    if(awakened) {
        printf("Obsessions:\n");
        int ob = 0;
        while(obsessions[ob] != NULL) {
            printf("* %s\n", obsessions[ob++]);
        }
        printf("\n");
    }

    printf("Unspent XP:\n");
    printf("* Normal XP: %d\n", mundane_xp - mundane_xp_spent);
    if(awakened) {
        printf("* Arcane XP: %d\n", arcane_xp - arcane_xp_spent);
    }
}

void print_notes() {
    printf("### Quote\n\n");
    printf("“%s”\n\n\n", overview.quote);
    printf("### Background\n\n");
    printf("%s\n\n\n", overview.background);
    printf("### Description\n\n");
    printf("%s\n", overview.roleplaying_hints);
}
