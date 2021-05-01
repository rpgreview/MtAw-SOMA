#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "common/utils.h"
#include "common/overview.h"
#include "common/attributes.h"
#include "common/skills.h"
#include "common/merits.h"
#include "players/michael.h"

// Need to grab player XP here since it's the only non-shared source file.
int mundane_xp = MUNDANE_XP;
int arcane_xp  = ARCANE_XP;

struct character_overview overview = {
    /* Name      */ "Thomas Booth",
    /* Age       */ "",
    /* Player    */ PLAYER_NAME,
    /* Virtue    */ "Charity",
    /* Vice      */ "Lust",
    /* Concept   */ "Rugged Librarian",
    /* Chronicle */ "SOMA",
    /* Faction   */ "",
    /* Group     */ ""
};

char *aspirations[] = {
    "Seduce someone",
    "Learn a mystery or secret",
    NULL
};

int attributes[n_attribute_types][n_categories] = {
                   /* MENTAL                    PHYSICAL                SOCIAL       */
/* POWER      */ { /* Intelligence */ 3,     /* Strength  */ 2,      /* Presence     */  3 },
/* FINESSE    */ { /* Wits         */ 3,     /* Dexterity */ 3,      /* Manipulation */  1 },
/* RESISTANCE */ { /* Resolve      */ 2,     /* Stamina   */ 2,      /* Composure    */  2 }
};

struct skill_t skills[n_categories][n_mental_skills] = {
        /*{ Category,   Name,               Specialization, Dots,   Asset,   Order Rote Skill  } */
    // Mental
    {   { Mental,       "Academics",        "Literature",   4,      true,    false  },
        { Mental,       "Computer",         NULL,           2,      false,   false  },
        { Mental,       "Crafts",           NULL,           0,      false,   false  },
        { Mental,       "Investigation",    NULL,           2,      false,   false  },
        { Mental,       "Medicine",         NULL,           0,      false,   false  },
        { Mental,       "Occult",           NULL,           2,      false,   false  },
        { Mental,       "Politics",         NULL,           0,      false,   false  },
        { Mental,       "Science",          NULL,           1,      true,    false  } },
    // Physical
    {   { Physical,     "Athletics",        "Running",      3,      false,   false  },
        { Physical,     "Brawl",            NULL,           1,      false,   false  },
        { Physical,     "Drive",            NULL,           0,      false,   false  },
        { Physical,     "Firearms",         NULL,           0,      false,   false  },
        { Physical,     "Larceny",          NULL,           0,      false,   false  },
        { Physical,     "Stealth",          NULL,           0,      false,   false  },
        { Physical,     "Survival",         NULL,           0,      false,   false  },
        { Physical,     "Weaponry",         NULL,           0,      false,   false  } },
    // Social
    {   { Social,       "Animal Ken",       NULL,           0,      false,   false  },
        { Social,       "Empathy",          NULL,           1,      false,   false  },
        { Social,       "Expression",       NULL,           1,      false,   false  },
        { Social,       "Intimidation",     NULL,           0,      false,   false  },
        { Social,       "Persuasion",       "Flirt",        1,      false,   false  },
        { Social,       "Socialize",        NULL,           3,      false,   false  },
        { Social,       "Streetwise",       NULL,           1,      false,   false  },
        { Social,       "Subterfuge",       NULL,           0,      false,   false  } }
};

// Different specializations lead to different skill column widths.
// Rule of thumb: keep second number at 21, adjust first number according to skill name + specialization
char *skill_column_fmt[3] = {
    "%-24s %-21s",
    "%-19s %-21s",
    "%-18s %-21s"
};

struct merit merits[] = {
    { "Martial Arts",                               4 },
    { "Prof Training (Librarian)",                  2 },
    { "Contacts (Academics, Sports Journalists)",   2 },
    { NULL,                         0 }
};

// Like skill columns, merit widths vary a lot per character.
// Customise yours here.
char *merit_fmt = "%-40s %s\n";

void advancement() {
    // Where to note experience expenditures
}
