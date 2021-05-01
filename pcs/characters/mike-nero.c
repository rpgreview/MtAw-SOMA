#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "common/utils.h"
#include "common/overview.h"
#include "common/attributes.h"
#include "common/skills.h"
#include "common/merits.h"
#include "players/jay.h"

// Need to grab player XP here before consuming it in shared source files.
int mundane_xp = MUNDANE_XP;
int arcane_xp  = ARCANE_XP;

struct character_overview overview = {
    /* Name      */ "Michael Nero",
    /* Age       */ "",
    /* Player    */ PLAYER_NAME,
    /* Virtue    */ "Faith",
    /* Vice      */ "Painkiller Addiction",
    /* Concept   */ "Strung Out Paramedic",
    /* Chronicle */ "SOMA",
    /* Faction   */ "",
    /* Group     */ ""
};

char *aspirations[] = {
    "Give someone hope",
    "Save someone's life",
    NULL
};

int attributes[n_attribute_types][n_categories] = {
                   /* MENTAL                    PHYSICAL                SOCIAL       */
/* POWER      */ { /* Intelligence */ 3,     /* Strength  */ 2,      /* Presence     */  1 },
/* FINESSE    */ { /* Wits         */ 3,     /* Dexterity */ 2,      /* Manipulation */  1 },
/* RESISTANCE */ { /* Resolve      */ 2,     /* Stamina   */ 3,      /* Composure    */  4 }
};

struct skill_t skills[n_categories][n_mental_skills] = {
        /*{ Category,   Name,               Specialization, Dots,   Asset,   Order Rote Skill  } */
    // Mental
    {   { Mental,       "Academics",        NULL,           2,      false,   false  },
        { Mental,       "Computer",         NULL,           0,      false,   false  },
        { Mental,       "Crafts",           NULL,           0,      false,   false  },
        { Mental,       "Investigation",    NULL,           2,      false,   false  },
        { Mental,       "Medicine",         "First Aid",    3,      true,    false  },
        { Mental,       "Occult",           NULL,           1,      false,   false  },
        { Mental,       "Politics",         NULL,           0,      false,   false  },
        { Mental,       "Science",          "Chemistry",    3,      false,   false  } },
    // Physical
    {   { Physical,     "Athletics",        NULL,           1,      false,   false  },
        { Physical,     "Brawl",            NULL,           0,      false,   false  },
        { Physical,     "Drive",            NULL,           1,      true,    false  },
        { Physical,     "Firearms",         NULL,           0,      false,   false  },
        { Physical,     "Larceny",          NULL,           1,      false,   false  },
        { Physical,     "Stealth",          NULL,           0,      false,   false  },
        { Physical,     "Survival",         NULL,           1,      false,   false  },
        { Physical,     "Weaponry",         NULL,           0,      false,   false  } },
    // Social
    {   { Social,       "Animal Ken",       NULL,           0,      false,   false  },
        { Social,       "Empathy",          "Calming",      2,      false,   false  },
        { Social,       "Expression",       NULL,           0,      false,   false  },
        { Social,       "Intimidation",     NULL,           0,      false,   false  },
        { Social,       "Persuasion",       NULL,           1,      false,   false  },
        { Social,       "Socialize",        NULL,           1,      false,   false  },
        { Social,       "Streetwise",       NULL,           2,      false,   false  },
        { Social,       "Subterfuge",       NULL,           1,      false,   false  } }
};

// Different specializations lead to different skill column widths.
// Rule of thumb: keep second number at 21, adjust first number according to skill name + specialization
char *skill_column_fmt[3] = {
    "%-22s %-21s",
    "%-10s %-21s",
    "%-17s %-21s"
};

struct merit merits[] = {
    { "Status (Paramedic)",         1 },
    { "Tolerance for Biology",      1 },
    { "Resources",                  2 },
    { "Good Time Management",       1 },
    { "Prof Training (Paramedic)",  2 },
    { "Contacts (Doctors, Cops)",   2 },
    { "Library",                    1 },
    { NULL,                         0 },
};

// Like skill columns, merit widths vary a lot per character.
// Customise yours here.
char *merit_fmt = "%-25s %s\n";

void advancement() {
    // Where to note experience expenditures
}
