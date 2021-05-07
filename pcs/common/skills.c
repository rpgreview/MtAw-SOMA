#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "common/skills.h"

void print_skills() {
    int max_skill_name_len[n_categories] = { 0, 0, 0 };
    for(int c = 0; c < n_categories; ++c) {
        for(int s = 0; s < n_mental_skills; ++s) {
            int tag_len = skills[c][s].is_unlocked + skills[c][s].is_asset + skills[c][s].is_order_rote_skill;
            if(tag_len > 0) {
                // We'll add a space
                ++tag_len;
            }
            int spec_len = 0;
            if(skills[c][s].specialization != NULL) {
                // Need room for both the specialization itself, a pair of parentheses, and a space
                spec_len = strnlen(skills[c][s].specialization, 64) + 3;
            }
            int this_skill_len = tag_len + strnlen(skills[c][s].name, 64) + spec_len;
            max_skill_name_len[c] = max(max_skill_name_len[c], this_skill_len);
        }
    }
    printf("```\n");
    char buf[256];
    char dot_str[10];
    bool unlocked_found = false;
    bool assets_found = false;
    bool rote_skills_found = false;
    char unlocked_sym = '?';
    char asset_sym = '+';
    char rote_sym = '*';
    for(int s = 0; s < n_mental_skills; ++s) {
        for(int c = 0; c < n_categories; ++c) {
            memset(buf, 0, 256);
            int start = 0;
            if(skills[c][s].is_unlocked) {
                unlocked_found = true;
                buf[start] = unlocked_sym;
                ++start;
            }
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
            printf("%-*s %15s", max_skill_name_len[c], buf, dot_str);
            free(dot_str);
            if(c < n_categories-1) {
                // Add some padding between columns
                printf("%-6s", "");
            }
        }
        printf("\n");
    }

    if(unlocked_found || assets_found || rote_skills_found) {
        printf("\n");
    }
    if(unlocked_found) {
        printf("%c Skill unlocked: no penalty for zero dots\n", unlocked_sym);
    }
    if(assets_found) {
        printf("%c Professional Training Asset Skills\n", asset_sym);
    }
    if(rote_skills_found) {
        printf("%c Order Rote Skills\n", rote_sym);
    }
    printf("```\n");
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
