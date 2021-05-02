/*
   Based on a character from "A Nightmare at Hill Manor" by Christopher Lee Simmons, 2011.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "common/utils.h"
#include "common/overview.h"
#include "common/attributes.h"
#include "common/skills.h"
#include "common/merits.h"
#include "common/inventory.h"
#include "common/magic.h"
#include "players/andrew.h"

// Need to grab player XP here since it's the only non-shared source file.
int mundane_xp = MUNDANE_XP;
int arcane_xp  = ARCANE_XP;

struct character_overview overview = {
    /* Name        */ "Rachel O'Hara",
    /* Age         */ "",
    /* Player      */ PLAYER_NAME,
    /* Virtue      */ "Justice. Rachel feels fulfilled when things go right and justice is served.",
    /* Vice        */ "Alcoholic",
    /* Concept     */ "Old-fashioned Cop",
    /* Chronicle   */ "SOMA",
    /* Faction     */ "",
    /* Group       */ "",
    /* Quote       */ "Put on the cuffs and I won’t have to hurt you.",
    /* Background  */ "Rachel comes from a cop family. Her father, Joe, was a good Irish Catholic boy, the favorite son. At least, he was until he married a Jewish girl named Irene. His brothers mocked him for it, but his dad just said, “at least she’s not a Protestant.” Irene’s family threatened to disown her for marrying a gentile. So Rachel grew up here, away from the bulk of the family in Boston, just because her dad was tired of getting grief from both sides of the family.\n\n\
Joe was a cop, old fashioned and hard-nosed. Rachel’s granddad once told her that Joe’d been born with the nightstick in his hand. He’d been a cop too until he retired, along with her great-grandfather and his father before him. Joe figured the dynasty was done, but to Rachel, it was never a question. She joined the academy as soon as she was of age.\n\n\
She worked her way up from pounding pavement on the street to her current position as a detective. When she got her detective badge, her granddad told her it was “adequate,” despite the fact that he’d never made detective in his entire career.\n\n\
Rachel moved into Hill Manor apartments with a guy, but they broke up. She liked the place, so she kept it. She even likes the poker game, though she has a feeling Mike’s got a problem.",
    /* Description */ "Rachel has shoulder-length brown hair that she usually keeps pulled back into a ponytail, and a scattering of freckles across her strong face. Physically, she’s pretty, but the tension in her—the intensity—makes her beautiful.",
    /* RP Hints    */ "You’re constantly trying to prove yourself. You grew up on the crossroads between two worlds, and you were never quite good enough for either. So you have to be better than both. Given the situation here, your first priority is to gather survivors and protect them while leading your people out of this."
};

char *aspirations[] = {
    "Bring down a powerful crime boss",
    NULL
};

char *obsessions[] = {
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
    { "Contacts (Lawyers, Gangs)",  2 }, // Due to Prof Training
    { "Serpentine",                 1 },
    { NULL,                         0 }
};

// Like skill columns, merit widths vary a lot per character.
// Customise yours here.
char *merit_fmt = "%-25s %s\n";

struct mundane_equipment_t misc_gear[] = {
    { NULL, 0, 0, 0, 0 }
};

struct weapon_t weapons[] = {
    /* Weapon/Attack,   Dmg,    Short,  Medium, Long,   Clip,   Init,   Str,    Size    */
    { "Glock 9mm",      1,         20,      40,   80,     17,      0,     2,       1 },
    { "Runed Dagger",   0,          0,       0,    0,      0,     -1,     1,       1 },
    { NULL,             0,          0,       0,    0,      0,      0,     0,       0 }
};

void advancement() {
    // Where to note experience expenditures

    // Session 1
    --integrity;

    // Buy a point of Serpentine
    ++mundane_xp_spent;

    // After witnessing several uncanny event, Rachel is starting to feel like she's seen it all, and things don't phase her as much.
    ++attributes[Resistance][Social];
}
