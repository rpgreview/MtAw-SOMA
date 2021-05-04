#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "common/utils.h"
#include "common/overview.h"
#include "common/attributes.h"
#include "common/skills.h"
#include "common/merits.h"
#include "common/inventory.h"
#include "common/magic.h"

char *dots(int ndots, int max_dots) {
    const char *dot = "\xE2\x97\x8F";
    const char *circle = "\xE2\x97\x8B";
    char *out = malloc(max_dots*3 + 1);
    if(!out) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    memset(out, 0, max_dots*3 + 1);
    int d = 0;
    for(; d < ndots; ++d) {
        strncat(out, dot, 3);
    }
    for(; d < max_dots; ++d) {
        strncat(out, circle, 3);
    }
    return out;
}

void print_category_name(enum category c) {
    switch(c) {
        case Mental:
            printf("Mental");
            break;
        case Physical:
            printf("Physical");
            break;
        case Social:
            printf("Social");
            break;
    }
}

void calculate_secondary_stats() {
    health = size + get_attribute(Stamina);
    willpower = get_attribute(Resolve) + get_attribute(Composure);
    speed = get_attribute(Strength) + get_attribute(Dexterity) + 5;
    initiative = get_attribute(Dexterity) + get_attribute(Composure);
    perception = get_attribute(Wits) + get_attribute(Composure);
    recovery = get_attribute(Resolve) + get_attribute(Stamina);

    struct skill_t athletics;
    get_skill(&athletics, "Athletics");
    defense = min(get_attribute(Dexterity), get_attribute(Wits)) + athletics.dots;
}

void print_header(const char *h) {
    printf("\n%s\n", h);
    int h_len = strnlen(h, 256);
    char *uline = malloc(h_len + 1);
    memset(uline, '-', h_len);
    uline[h_len] = '\0';
    printf("%s\n\n", uline);
}

void print_character() {
    print_overview();
    printf("\n");

    print_header("Attributes");
    print_attributes();
    printf("\n");

    print_header("Skills");
    print_skills();
    printf("\n");

    print_header("Merits");
    print_merits();
    printf("\n");

    if(awakened) {
        print_header("Arcana");
        print_arcana();
        printf("\n");

        print_header("Rotes");
        print_rotes();
        printf("\n");
    }

    print_header("Gear");
    print_mundane_equipment();
    printf("\n");
    print_weapons();
    printf("\n");

    print_header("Notes");
    print_notes();
}

int main(int argc, char **argv) {
    advancement();
    calculate_secondary_stats();
    print_character();
    return 0;
}
