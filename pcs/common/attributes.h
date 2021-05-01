#pragma once
#include "common/utils.h"

enum attribute_type {
    Power,
    Finesse,
    Resistance,
    n_attribute_types
};

enum attributes {
    Intelligence,
    Wits,
    Resolve,
    Strength,
    Dexterity,
    Stamina,
    Presence,
    Manipulation,
    Composure,
    n_attributes
};

struct attribute_coordinates_t {
    enum attribute_type type;
    enum category       attribute_category;
};

static char *attribute_names[n_attribute_types][n_categories] = {
    { "Intelligence",   "Strength",     "Presence"      },
    { "Wits",           "Dexterity",    "Manipulation"  },
    { "Resolve",        "Stamina",      "Composure"     }
};

extern int attributes[n_attribute_types][n_categories];
extern int size;
extern int integrity;
extern int health;
extern int willpower;
extern int speed;
extern int defense;
extern int armor;
extern int initiative;
extern int perception;

void attribute_to_coords(struct attribute_coordinates_t *coords, enum attributes attr);
void print_attribute_type_name(enum attribute_type t);
int get_attribute(enum attributes a);
void print_attributes();
