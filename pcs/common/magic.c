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

void print_rote(char *arcanum, int level, char *spell_name, int max_spell_name_len, char *creator, int max_creator_name_len, char *skill_name, int max_rote_skill_len) {
    // We want to display arcanum name and level together, eg "Mind ●●", so set up a buffer for this.
    // Buffer size = max arcanum length (6) + space (1) + max level (5) + 2x invisible characters per dot + allow room for \0 = 12 + 2*length + 1.
    int arcanum_col_width = 12 + 2*level;
    const int arcanum_buf_size = arcanum_col_width + 1;
    char arcanum_str[arcanum_buf_size];
    memset(arcanum_str, 0, arcanum_buf_size);
    strncpy(arcanum_str, arcanum, 8);
    strncat(arcanum_str, " ", 2);
    char *dot_str = dots(level, level);
    strncat(arcanum_str, dot_str, 20);
    printf("| %-*s | %-*s | %-*s | %-*s |\n", arcanum_col_width, arcanum_str, max_spell_name_len, spell_name, max_creator_name_len, creator, max_rote_skill_len, skill_name);
    free(dot_str);
}

void print_rotes() {
    // Grab the longest names for the format string
    char *spell_name_header = "Spell";
    int max_spell_name_len = strnlen(spell_name_header, 64);
    char *creator_name_header = "Creator";
    int max_creator_name_len = strnlen(creator_name_header, 64);
    char *rote_skill_header = "Rote Skill";
    int max_rote_skill_len = strnlen(rote_skill_header, 64);
    for(int r = 0; rotes[r].spell != NULL; ++r) {
        max_spell_name_len = max(max_spell_name_len, strnlen(rotes[r].spell, 64));
        max_creator_name_len = max(max_creator_name_len, strnlen(rotes[r].creator, 64));
        max_rote_skill_len = max(max_rote_skill_len, strnlen(rotes[r].rote_skill->name, 64));
    }

    printf("```\n");
    // Construct a "+---------+-----------+" style table border
    char *corner_padding = "+--+--+--+--+"; // To help calculate full width of border
    int max_dots = 5;
    int max_arcanum_len = 6;
    const int rote_border_len = max_arcanum_len + 1 + max_dots + max_spell_name_len + max_creator_name_len + max_rote_skill_len + strnlen(corner_padding, 16);
    char rote_border[rote_border_len];
    memset(rote_border, '-', rote_border_len);
    char corner = '+';
    char *cursor = rote_border;
    *cursor = corner;
    cursor += 1 + max_arcanum_len + 1 + max_dots + 2;
    *cursor = corner;
    cursor += 1 + max_spell_name_len + 2;
    *cursor = corner;
    cursor += 1 + max_creator_name_len + 2;
    *cursor = corner;
    cursor += 1 + max_rote_skill_len + 2;
    *cursor = corner;

    // Print header
    printf("%s\n", rote_border);
    print_rote("Arcanum", 0, spell_name_header, max_spell_name_len, creator_name_header, max_creator_name_len, rote_skill_header, max_rote_skill_len);
    printf("%s\n", rote_border);

    // Print the actual rotes
    for(int r = 0; rotes[r].spell != NULL; ++r) {
        print_rote(rotes[r].arcanum->name, rotes[r].level, rotes[r].spell, max_spell_name_len, rotes[r].creator, max_creator_name_len, rotes[r].rote_skill->name, max_rote_skill_len);
    }
    printf("%s\n", rote_border);
    printf("```\n");
}

void print_praxes() {
    printf("```\n");
    for(int p = 0; praxes[p] != NULL; printf("%s\n", praxes[p++]));
    printf("```\n");
}
