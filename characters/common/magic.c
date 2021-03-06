#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <mtaw/mtaw.h>

int arcane_xp_spent = 0;
bool awakened = false;
int gnosis = 0;
int wisdom = 0;

int expected_obsessions(const int g) {
    return((g/3)+1);
}

void print_gnosis_summary() {
        printf("* Ritual Interval: %s\n", ritual_interval[gnosis]);
        printf("* Trait Max: %d\n", max(5, gnosis));
        printf("* Yantras: %d\n", (gnosis+1)/2+1);
        printf("* Paradox: %d\n", (gnosis+1)/2);
        printf("* Combined Spells: %d\n", expected_obsessions(gnosis));
        printf("* Obsessions: %d\n", expected_obsessions(gnosis));
        printf("* Total Mana Capacity: %d\n", max_mana[gnosis]);
        printf("* Mana Per Turn: %d\n", mana_per_turn[gnosis]);
        printf("* Ruling Arcana Max: %d\n", min(5, (gnosis+1)/2+2));
        printf("* Other Arcana Max: %d\n", min(5, gnosis/2+2));
}

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

void print_rote(char *arcanum, int level, int max_arcanum_chars, char *spell_name, int max_spell_name_len, char *skill_name, int max_rote_skill_len) {
    // We want to display arcanum name and level together, eg "Mind ●●", so set up a buffer for this.
    // The column width needs to account for 2x hidden chars in each dot.
    int arcanum_col_width = max_arcanum_chars + 2*level;
    const int arcanum_buf_size = arcanum_col_width + 1;
    char arcanum_str[arcanum_buf_size];
    memset(arcanum_str, 0, arcanum_buf_size);
    strncpy(arcanum_str, arcanum, 8);
    if(level > 0) {
        strncat(arcanum_str, " ", 2);
        char *dot_str = dots(level, level);
        strncat(arcanum_str, dot_str, 20);
        free(dot_str);
    }
    printf("| %-*s | %-*s | %-*s |\n", arcanum_col_width, arcanum_str, max_spell_name_len, spell_name, max_rote_skill_len, skill_name);
}

void print_rotes() {
    if(rotes[0].spell == NULL) {
        printf("None\n");
        return;
    }

    // Grab the longest names for the format string
    char *arcanum_header = "Arcanum";
    int max_arcanum_chars = strnlen(arcanum_header, 32);
    int max_level = 0;
    char *spell_name_header = "Spell";
    int max_spell_name_len = strnlen(spell_name_header, 64);
    char *rote_skill_header = "Rote Skill";
    int max_rote_skill_len = strnlen(rote_skill_header, 64);
    for(int r = 0; rotes[r].spell != NULL; ++r) {
        max_arcanum_chars = max(max_arcanum_chars, strnlen(rotes[r].arcanum->name, 8) + 1 + rotes[r].level);
        max_level = max(max_level, rotes[r].level);
        max_spell_name_len = max(max_spell_name_len, strnlen(rotes[r].spell, 64));
        max_rote_skill_len = max(max_rote_skill_len, strnlen(rotes[r].rote_skill->name, 64));
    }

    // Construct a "+---------+-----------+" style table border
    int ncols = 4;
    int padding_per_field = 3; // "+-" corresponding to the start of each field and another "-" at the end
    int total_padding_chars = ncols*padding_per_field + 1; // Add one for terminating corner '+'.
    const int rote_border_len = max_arcanum_chars + max_spell_name_len + max_rote_skill_len + total_padding_chars;
    char rote_border[rote_border_len + 1];
    memset(rote_border, '-', rote_border_len);
    char corner = '+';
    char *cursor;
    *(cursor =  rote_border)                                = corner;
    *(cursor += padding_per_field + max_arcanum_chars)      = corner;
    *(cursor += padding_per_field + max_spell_name_len)     = corner;
    *(cursor += padding_per_field + max_rote_skill_len)     = corner;
    *(++cursor) = '\0';

    // Do the actual printing
    printf("```\n");
    printf("%s\n", rote_border);
    print_rote(arcanum_header, 0, max_arcanum_chars, spell_name_header, max_spell_name_len, rote_skill_header, max_rote_skill_len);
    printf("%s\n", rote_border);
    for(int r = 0; rotes[r].spell != NULL; ++r) {
        print_rote(rotes[r].arcanum->name, rotes[r].level, max_arcanum_chars, rotes[r].spell, max_spell_name_len, rotes[r].rote_skill->name, max_rote_skill_len);
    }
    printf("%s\n", rote_border);
    printf("```\n");
}

void print_praxes() {
    if(praxes[0].name == NULL) {
        printf("None\n");
        return;
    }
    int gnosis_freebies = 0;
    printf("```\n");
    for(int p = 0; praxes[p].name != NULL; gnosis_freebies += praxes[p].gnosis_freebie, printf("%s\n", praxes[p++].name));
    printf("```\n");
    if(gnosis_freebies != gnosis) {
        printf("**Warning:** %d Praxes acquired due to Gnosis, but Gnosis is %d\n", gnosis_freebies, gnosis);
    }
}

void print_familiars() {
    int f = 0;
    while(familiars[f] != NULL) {
        printf("\n");
        struct familiar_t *this = familiars[f];
        printf("* Name: %s\n", this->name);
        printf("* Path: %s\n", path_names[this->path]);
        printf("* Traits: %d/%d/%d\n", this->power, this->finesse, this->resistance);

        printf("* Abilities:");
        int a = 0;
        if(this->abilities[a] != NULL) {
            printf(" %s", this->abilities[a]);
        }
        while(this->abilities[++a] != NULL) {
            printf(", %s", this->abilities[a]);
        }
        printf("\n");

        printf("* Agenda: %s\n", this->agenda);
        printf("* Notes: %s\n", this->notes);
        ++f;
    }
}
