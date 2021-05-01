#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "common/utils.h"
#include "common/overview.h"
#include "common/attributes.h"
#include "common/skills.h"
#include "common/merits.h"
#include "players/andrew.h"

// Need to grab player XP here since it's the only non-shared source file.
int mundane_xp = MUNDANE_XP;
int arcane_xp  = ARCANE_XP;

struct character_overview overview = {
    /* Name      */ "Rachel O'Hara",
    /* Age       */ "",
    /* Player    */ PLAYER_NAME,
    /* Virtue    */ "Justice",
    /* Vice      */ "Alcoholic",
    /* Concept   */ "Old-fashioned Cop",
    /* Chronicle */ "SOMA",
    /* Faction   */ "",
    /* Group     */ ""
};

char *aspirations[] = {
    "Don't drink for a day",
    "Bring down a powerful crim boss",
    NULL
};

int attributes[n_attribute_types][n_categories] = {
                   /* MENTAL                    PHYSICAL                SOCIAL       */
/* POWER      */ { /* Intelligence */ 2,     /* Strength  */ 2,      /* Presence     */  3 },
/* FINESSE    */ { /* Wits         */ 3,     /* Dexterity */ 2,      /* Manipulation */  3 },
/* RESISTANCE */ { /* Resolve      */ 2,     /* Stamina   */ 2,      /* Composure    */  2 }
};

struct skill_t skills[n_categories][n_mental_skills] = {
        /*{ Category,   Name,               Specialization, Dots,   Asset,   Order Rote Skill  } */
    // Mental
    {   { Mental,       "Academics",        "Law",          1,      false,   false  },
        { Mental,       "Computer",         NULL,           1,      false,   false  },
        { Mental,       "Crafts",           NULL,           0,      false,   false  },
        { Mental,       "Investigation",    "Crime Scenes", 4,      false,   false  },
        { Mental,       "Medicine",         NULL,           0,      false,   false  },
        { Mental,       "Occult",           NULL,           0,      false,   false  },
        { Mental,       "Politics",         NULL,           1,      false,   false  },
        { Mental,       "Science",          NULL,           0,      false,   false  } },
    // Physical
    {   { Physical,     "Athletics",        NULL,           3,      false,   false  },
        { Physical,     "Brawl",            NULL,           2,      false,   false  },
        { Physical,     "Drive",            NULL,           1,      false,   false  },
        { Physical,     "Firearms",         NULL,           3,      true,    false  },
        { Physical,     "Larceny",          NULL,           1,      false,   false  },
        { Physical,     "Stealth",          NULL,           0,      false,   false  },
        { Physical,     "Survival",         NULL,           0,      false,   false  },
        { Physical,     "Weaponry",         "Clubs",        1,      false,   false  } },
    // Social
    {   { Social,       "Animal Ken",       NULL,           0,      false,   false  },
        { Social,       "Empathy",          NULL,           1,      false,   false  },
        { Social,       "Expression",       NULL,           0,      false,   false  },
        { Social,       "Intimidation",     NULL,           2,      false,   false  },
        { Social,       "Persuasion",       NULL,           0,      false,   false  },
        { Social,       "Socialize",        NULL,           0,      false,   false  },
        { Social,       "Streetwise",       NULL,           1,      true,    false  },
        { Social,       "Subterfuge",       NULL,           0,      false,   false  } }
};

// Different specializations lead to different skill column widths.
// Best to customise the widths for your character from the start.
char *skill_column_fmt[3] = {
    "%-28s %-21s",
    "%-16s %-21s",
    "%-12s %-21s"
};

struct merit merits[] = {
    { "Prof Training (Police)",     2 },
    { "Status (Police)",            2 },
    { "Police Tactics",             3 },
    { "Contacts (Lawyers, Gangs)",  2 },
    { NULL,                         0 }
};

// Like skill columns, merit widths vary a lot per character.
// Customise yours here.
char *merit_fmt = "%-25s %s\n";

void advancement() {
    // Where to note experience expenditures

    // Session 1
    --integrity;
}
