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

    char *fmt = "* %-8s %s\n";
    printf(fmt, "Player:",  overview.player  == NULL ? "" : overview.player);
    printf(fmt, "Concept:", overview.concept == NULL ? "" : overview.concept);
    printf(fmt, "Virtue:",  overview.virtue  == NULL ? "" : overview.virtue);
    printf(fmt, "Vice:",    overview.vice    == NULL ? "" : overview.vice);
    if(awakened) {
        if(overview.path != NULL) {
            printf(fmt, "Path:",    overview.path);
        }
        if(overview.order != NULL) {
            printf(fmt, "Order:",   overview.order);
        }
    }
    printf("\n");

    printf("Aspirations:\n");
    int c = 0;
    while(aspirations[c] != NULL) {
        printf("- %s\n", aspirations[c++]);
    }

    if(awakened) {
        printf("\n");
        printf("Obsessions:\n");
        int ob = 0;
        while(obsessions[ob] != NULL) {
            printf("* %s\n", obsessions[ob++]);
        }
    }

    if(overview.is_npc) {
        return;
    }
    printf("\n");
    printf("Unspent XP:\n");
    printf("* Normal XP: %d\n", mundane_xp - mundane_xp_spent);
    if(awakened) {
        printf("* Arcane XP: %d\n", arcane_xp - arcane_xp_spent);
    }
}

void print_notes() {
    bool set_up_eol = false;
    if(overview.quote != NULL) {
        printf("### Quote\n\n");
        printf("“%s”\n", overview.quote);
        set_up_eol = true;
    }
    if(overview.background != NULL) {
        if(set_up_eol) {
            printf("\n\n");
        } else {
            set_up_eol = true;
        }
        printf("### Background\n\n");
        printf("%s\n", overview.background);
    }
    if(overview.description != NULL) {
        if(set_up_eol) {
            printf("\n\n");
        } else {
            set_up_eol = true;
        }
        printf("### Description\n\n");
        printf("%s\n", overview.description);
    }
    if(overview.roleplaying_hints != NULL) {
        if(set_up_eol) {
            printf("\n\n");
        }
        printf("### Roleplaying Hints\n\n");
        printf("%s\n", overview.roleplaying_hints);
    }
}
