#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "common/utils.h"
#include "common/overview.h"
#include "common/attributes.h"
#include "common/skills.h"
#include "common/merits.h"
#include "players/lev.h"

// Need to grab player XP here since it's the only non-shared source file.
int mundane_xp = MUNDANE_XP;
int arcane_xp  = ARCANE_XP;

struct character_overview overview = {
    /* Name      */ "Nicky Sims",
    /* Age       */ "",
    /* Player    */ PLAYER_NAME,
    /* Virtue    */ "Fortitude",
    /* Vice      */ "Wrath",
    /* Concept   */ "Small Time Hood",
    /* Chronicle */ "SOMA",
    /* Faction   */ "",
    /* Group     */ ""
};

char *aspirations[] = {
    "Rescue someone",
    "Read a book",
    NULL
};

int attributes[n_attribute_types][n_categories] = {
                   /* MENTAL                    PHYSICAL                SOCIAL       */
/* POWER      */ { /* Intelligence */ 2,     /* Strength  */ 3,      /* Presence     */  2 },
/* FINESSE    */ { /* Wits         */ 3,     /* Dexterity */ 2,      /* Manipulation */  2 },
/* RESISTANCE */ { /* Resolve      */ 2,     /* Stamina   */ 3,      /* Composure    */  2 }
};

struct skill_t skills[n_categories][n_mental_skills] = {
        /*{ Category,   Name,               Specialization, Dots,   Asset,   Order Rote Skill  } */
    // Mental
    {   { Mental,       "Academics",        NULL,           0,      false,   false  },
        { Mental,       "Computer",         NULL,           1,      false,   false  },
        { Mental,       "Crafts",           NULL,           1,      false,   false  },
        { Mental,       "Investigation",    "Casing",       2,      false,   false  },
        { Mental,       "Medicine",         NULL,           0,      false,   false  },
        { Mental,       "Occult",           NULL,           0,      false,   false  },
        { Mental,       "Politics",         NULL,           0,      false,   false  },
        { Mental,       "Science",          NULL,           0,      false,   false  } },
    // Physical
    {   { Physical,     "Athletics",        "Escape",       2,      false,   false  },
        { Physical,     "Brawl",            NULL,           2,      false,   false  },
        { Physical,     "Drive",            NULL,           0,      false,   false  },
        { Physical,     "Firearms",         NULL,           1,      false,   false  },
        { Physical,     "Larceny",          "Lockpicking",  3,      false,   false  },
        { Physical,     "Stealth",          NULL,           1,      false,   false  },
        { Physical,     "Survival",         NULL,           1,      false,   false  },
        { Physical,     "Weaponry",         NULL,           1,      false,   false  } },
    // Social
    {   { Social,       "Animal Ken",       NULL,           0,      false,   false  },
        { Social,       "Empathy",          NULL,           0,      false,   false  },
        { Social,       "Expression",       NULL,           0,      false,   false  },
        { Social,       "Intimidation",     NULL,           2,      false,   false  },
        { Social,       "Persuasion",       NULL,           1,      false,   false  },
        { Social,       "Socialize",        NULL,           0,      false,   false  },
        { Social,       "Streetwise",       NULL,           2,      false,   false  },
        { Social,       "Subterfuge",       NULL,           2,      false,   false  } }
};

// Different specializations lead to different skill column widths.
// Best to customise the widths for your character from the start.
char *skill_column_fmt[3] = {
    "%-22s %-21s",
    "%-21s %-21s",
    "%-15s %-21s"
};

struct merit merits[] = {
    { "Language (English)",         1 },
    { "Resources",                  2 },
    { "Indomitable",                2 },
    { "Alternate Identity",         2 },
    { "Library",                    1 },
    { NULL,                         0 }
};

// Like skill columns, merit widths vary a lot per character.
// Customise yours here.
char *merit_fmt = "%-18s %s\n";

void advancement() {
    // Where to note experience expenditures
}
