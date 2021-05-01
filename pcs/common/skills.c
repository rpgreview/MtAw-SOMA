#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "common/skills.h"

void print_skills() {
    char buf[256];
    char dot_str[10];
    bool assets_found = false;
    bool rote_skills_found = false;
    char asset_sym = '+';
    char rote_sym = '*';
    for(int s = 0; s < n_mental_skills; ++s) {
        for(int c = 0; c < n_categories; ++c) {
            memset(buf, 0, 256);
            int start = 0;
            if(skills[c][s].is_asset) {
                assets_found = true;
                buf[start] = asset_sym;
                ++start;
            }
            if(skills[c][s].is_order_rote_skill) {
                rote_skills_found = true;
                buf[start] = rote_sym;
                ++start;
            }
            if(start != 0) {
                buf[start] = ' ';
            }
            strncat(buf, skills[c][s].name, 64);
            if(skills[c][s].specialization != NULL) {
                strncat(buf, " (", 3);
                strncat(buf, skills[c][s].specialization, 128);
                strncat(buf, ")", 2);
            }
            char *dot_str = dots(skills[c][s].dots, 5);
            printf(skill_column_fmt[c], buf, dot_str);
            free(dot_str);
        }
        printf("\n");
    }

    if(assets_found || rote_skills_found) {
        printf("\n");
    }
    if(assets_found) {
        printf("%c Professional Training Asset Skills\n", asset_sym);
    }
    if(rote_skills_found) {
        printf("%c Order Rote Skills\n", rote_sym);
    }
}

void get_skill(struct skill_t *skill, const char *target) {
    for(int c = 0; c < n_categories; ++c) {
        for(int s = 0; s < n_mental_skills; ++s) {
            if(strncmp(skills[c][s].name, target, 32) == 0) {
                *skill = skills[c][s];
            }
        }
    }
}
