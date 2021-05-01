// Just a test character for baselining various functions
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "common/utils.h"
#include "common/overview.h"
#include "common/attributes.h"
#include "common/skills.h"
#include "common/merits.h"
#include "common/inventory.h"
#include "players/nobody.h"

// Need to grab player XP here since it's the only non-shared source file.
int mundane_xp = MUNDANE_XP;
int arcane_xp  = ARCANE_XP;

struct character_overview overview = {
    /* Name        */ "Nobody",
    /* Age         */ "",
    /* Player      */ PLAYER_NAME,
    /* Virtue      */ "",
    /* Vice        */ "",
    /* Concept     */ "",
    /* Chronicle   */ "SOMA",
    /* Faction     */ "",
    /* Group       */ "",
    /* Quote       */ "",
    /* Background  */ "",
    /* Description */ "",
    /* RP Hints    */ ""
};

char *aspirations[] = {
    NULL
};

int attributes[n_attribute_types][n_categories] = {
                   /* MENTAL                    PHYSICAL                SOCIAL       */
/* POWER      */ { /* Intelligence */ 1,     /* Strength  */ 1,      /* Presence     */  1 },
/* FINESSE    */ { /* Wits         */ 1,     /* Dexterity */ 1,      /* Manipulation */  1 },
/* RESISTANCE */ { /* Resolve      */ 1,     /* Stamina   */ 1,      /* Composure    */  1 }
};

struct skill_t skills[n_categories][n_mental_skills] = {
        /*{ Category,   Name,               Specialization, Dots,   Asset,   Order Rote Skill  } */
    // Mental
    {   { Mental,       "Academics",        NULL,           0,      false,   false  },
        { Mental,       "Computer",         NULL,           0,      false,   false  },
        { Mental,       "Crafts",           NULL,           0,      false,   false  },
        { Mental,       "Investigation",    NULL,           0,      false,   false  },
        { Mental,       "Medicine",         NULL,           0,      false,   false  },
        { Mental,       "Occult",           NULL,           0,      false,   false  },
        { Mental,       "Politics",         NULL,           0,      false,   false  },
        { Mental,       "Science",          NULL,           0,      false,   false  } },
    // Physical
    {   { Physical,     "Athletics",        NULL,           0,      false,   false  },
        { Physical,     "Brawl",            NULL,           0,      false,   false  },
        { Physical,     "Drive",            NULL,           0,      false,   false  },
        { Physical,     "Firearms",         NULL,           0,      false,   false  },
        { Physical,     "Larceny",          NULL,           0,      false,   false  },
        { Physical,     "Stealth",          NULL,           0,      false,   false  },
        { Physical,     "Survival",         NULL,           0,      false,   false  },
        { Physical,     "Weaponry",         NULL,           0,      false,   false  } },
    // Social
    {   { Social,       "Animal Ken",       NULL,           0,      false,   false  },
        { Social,       "Empathy",          NULL,           0,      false,   false  },
        { Social,       "Expression",       NULL,           0,      false,   false  },
        { Social,       "Intimidation",     NULL,           0,      false,   false  },
        { Social,       "Persuasion",       NULL,           0,      false,   false  },
        { Social,       "Socialize",        NULL,           0,      false,   false  },
        { Social,       "Streetwise",       NULL,           0,      false,   false  },
        { Social,       "Subterfuge",       NULL,           0,      false,   false  } }
};

// Different specializations lead to different skill column widths.
// Best to customise the widths for your character from the start.
char *skill_column_fmt[3] = {
    "%-13s %-21s",
     "%-9s %-21s",
    "%-12s %-21s"
};

struct merit merits[] = {
    { NULL,                         0 }
};

// Like skill columns, merit widths vary a lot per character.
// Customise yours here.
char *merit_fmt = "%-16s %s\n";

struct mundane_equipment_t misc_gear[] = {
    { NULL, 0, 0, 0, 0 }
};

struct weapon_t weapons[] = {
    { NULL, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void advancement() {
    // Where to note experience expenditures
}
