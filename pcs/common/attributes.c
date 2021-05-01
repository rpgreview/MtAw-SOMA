#include <stdio.h>
#include <stdlib.h>
#include "common/utils.h"
#include "common/attributes.h"
#include "common/skills.h"

int size = 5;
int integrity = 7;

// Derived stats
int health = 0;
int willpower = 0;
int speed = 0;
int defense = 0;
int armor = 0;
int initiative = 0;
int perception = 0;

void print_attribute_type_name(enum attribute_type t) {
    switch(t) {
        case Power:
            printf("Power");
            break;
        case Finesse:
            printf("Finesse");
            break;
        case Resistance:
            printf("Resistance");
            break;
    }
}

void attribute_to_coords(struct attribute_coordinates_t *coords, enum attributes attr) {
    coords->type = -1;
    coords->attribute_category = -1;
    switch(attr) {
        case Intelligence:  case Wits:          case Resolve:
            coords->attribute_category = Mental;
            break;
        case Strength:      case Dexterity:     case Stamina:
            coords->attribute_category = Physical;
            break;
        case Presence:      case Manipulation:  case Composure:
            coords->attribute_category = Social;
            break;
    }
    switch(attr) {
        case Intelligence:  case Strength:      case Presence:
            coords->type = Power;
            break;
        case Wits:          case Dexterity:     case Manipulation:
            coords->type = Finesse;
            break;
        case Resolve:       case Stamina:       case Composure:
            coords->type = Resistance;
            break;
    }
}

int get_attribute(enum attributes a) {
    struct attribute_coordinates_t ac;
    attribute_to_coords(&ac, a);
    return(attributes[ac.type][ac.attribute_category]);
}

void print_attributes() {
    char *dot_str;
    for(int i = 0; i < 64; ++i) {
        printf("%c", i % 21 ? '-' : '+');
    }
    printf("\n");
    for(int t = 0; t < n_attribute_types; ++t) {
        printf("%-2s", "|");
        for(int c = 0; c < n_categories; ++c) {
            dot_str = dots(attributes[t][c], 5);
            printf("%-12s %s | ", attribute_names[t][c], dot_str, "|");
            free(dot_str);
        }
        printf("\n");
    }
    for(int i = 0; i < 64; ++i) {
        printf("%c", i % 21 ? '-' : '+');
    }
    printf("\n");

    printf("\n");
    char *fmt = "%-12s %3d %s\n";

    dot_str = dots(health, max(10, health));
    printf(fmt, "Health:", health, dot_str);
    free(dot_str);

    dot_str = dots(willpower, max(10, willpower));
    printf(fmt, "Willpower:", willpower, dot_str);
    free(dot_str);

    dot_str = dots(integrity, max(10, integrity));
    printf(fmt, "Integrity:", integrity, dot_str);
    free(dot_str);
    printf("\n");

    dot_str = dots(size, max(10, size));
    printf(fmt, "Size:", size, dot_str);
    free(dot_str);

    dot_str = dots(speed, max(10, speed));
    printf(fmt, "Speed:", speed, dot_str);
    free(dot_str);

    dot_str = dots(defense, max(10, defense));
    printf(fmt, "Defense:", defense, dot_str);
    free(dot_str);

    dot_str = dots(initiative, max(10, initiative));
    printf(fmt, "Initiative:", initiative, dot_str);
    free(dot_str);

    if(armor > 0) {
        dot_str = dots(armor, max(10, armor));
        printf(fmt, "Armor:", armor, dot_str);
        free(dot_str);
    }

    dot_str = dots(perception, max(10, perception));
    printf(fmt, "Perception:", perception, dot_str);
    free(dot_str);
}
