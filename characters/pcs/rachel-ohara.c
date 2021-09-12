/*
   Based on a character from "A Nightmare at Hill Manor" by Christopher Lee Simmons, 2011.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mtaw/mtaw.h>
#include <players/andrew.h>

// Need to grab player XP here since it's the only non-shared source file.
int mundane_xp = MUNDANE_XP;
int arcane_xp  = ARCANE_XP;

struct character_overview overview = {
    /* Name        */ "Rachel O'Hara (Shadow Name: Sphinx)",
    /* Age         */ "",
    /* Player      */ PLAYER_NAME,
    /* Virtue      */ "Justice. Rachel feels fulfilled when things go right and justice is served.",
    /* Vice        */ "Alcoholic",
    /* Concept     */ "Old-fashioned Cop",
    /* Chronicle   */ "SOMA",
    /* Path        */ "Obrimos",
    /* Order       */ "Silver Ladder",
    /* Nimbus      */ "Hot glowing",
    /* Quote       */ "Put on the cuffs and I won’t have to hurt you.",
    /* Background  */ "Rachel comes from a cop family. Her father, Joe, was a good Irish Catholic boy, the favorite son. At least, he was until he married a Jewish girl named Irene. His brothers mocked him for it, but his dad just said, “at least she’s not a Protestant.” Irene’s family threatened to disown her for marrying a gentile. So Rachel grew up here, away from the bulk of the family in Boston, just because her dad was tired of getting grief from both sides of the family.\n\n\
Joe was a cop, old fashioned and hard-nosed. Rachel’s granddad once told her that Joe’d been born with the nightstick in his hand. He’d been a cop too until he retired, along with her great-grandfather and his father before him. Joe figured the dynasty was done, but to Rachel, it was never a question. She joined the academy as soon as she was of age.\n\n\
She worked her way up from pounding pavement on the street to her current position as a detective. When she got her detective badge, her granddad told her it was “adequate,” despite the fact that he’d never made detective in his entire career.\n\n\
Rachel moved into Hill Manor apartments with a guy, but they broke up. She liked the place, so she kept it. She even likes the poker game, though she has a feeling Mike’s got a problem.",
    /* Description */ "Rachel has shoulder-length brown hair that she usually keeps pulled back into a ponytail, and a scattering of freckles across her strong face. Physically, she’s pretty, but the tension in her—the intensity—makes her beautiful.",
    /* RP Hints    */ "You’re constantly trying to prove yourself. You grew up on the crossroads between two worlds, and you were never quite good enough for either. So you have to be better than both. Given the situation here, your first priority is to gather survivors and protect them while leading your people out of this.\n\n\
Rachel has vowed to protect the secrets of the Silver Ladder, uphold the Order's tenets, and honour its rulings.",
    /* Is NPC?     */ false
};

char *aspirations[] = {
    "Arrest someone",
    "Show leadership in a challenging situation",
    "Cast a spell using Forces",
    NULL
};

char *obsessions[] = {
    "Collapse of the USSR",
    NULL
};

int attributes[n_attribute_types][n_categories] = {
                   /* MENTAL                    PHYSICAL                SOCIAL       */
/* POWER      */ { /* Intelligence */ 2,     /* Strength  */ 2,      /* Presence     */  3 },
/* FINESSE    */ { /* Wits         */ 3,     /* Dexterity */ 2,      /* Manipulation */  3 },
/* RESISTANCE */ { /* Resolve      */ 2,     /* Stamina   */ 2,      /* Composure    */  2 }
};

struct skill_t skills[n_categories][n_mental_skills] = {
    /*  { Category,     Name,               Specialization, Dots,   Modifiers  } */
    // Mental
    {   { Mental,       "Academics",        "Law",          1,      0  },
        { Mental,       "Computer",         NULL,           1,      0  },
        { Mental,       "Crafts",           NULL,           0,      0  },
        { Mental,       "Investigation",    "Crime Scenes", 4,      0  },
        { Mental,       "Medicine",         NULL,           0,      0  },
        { Mental,       "Occult",           NULL,           0,      0  },
        { Mental,       "Politics",         NULL,           1,      0  },
        { Mental,       "Science",          NULL,           0,      0  } },
    // Physical
    {   { Physical,     "Athletics",        NULL,           3,      0  },
        { Physical,     "Brawl",            NULL,           2,      0  },
        { Physical,     "Drive",            NULL,           1,      0  },
        { Physical,     "Firearms",         NULL,           4,      IS_ASSET  },
        { Physical,     "Larceny",          NULL,           1,      0  },
        { Physical,     "Stealth",          NULL,           0,      0  },
        { Physical,     "Survival",         NULL,           0,      0  },
        { Physical,     "Weaponry",         "Clubs",        1,      0  } },
    // Social
    {   { Social,       "Animal Ken",       NULL,           0,      0  },
        { Social,       "Empathy",          NULL,           1,      0  },
        { Social,       "Expression",       NULL,           0,      0  },
        { Social,       "Intimidation",     NULL,           2,      0  },
        { Social,       "Persuasion",       NULL,           0,      0  },
        { Social,       "Socialize",        NULL,           0,      0  },
        { Social,       "Streetwise",       NULL,           1,      IS_ASSET  },
        { Social,       "Subterfuge",       NULL,           1,      0  } }
};

struct merit merits[] = {
    { "Prof Training (Police)",         2 },
    { "Status (Police)",                2 },
    { "Police Tactics",                 3 },
    { "Contacts (Lawyers, Gangs)",      2 }, // Due to Prof Training
    { "Serpentine",                     2 },
    { "Order Status (Silver Ladder)",   1 }, // Conditional on keeping vow
    { "Enhanced Item",                  3 }, // Amulet of Initiative from the Phylacterion
    { NULL,                             0 }
};

struct arcanum_t arcana[n_arcana] = {
    /* Name     Dots    Status      Path        Manifestation */
    { "Death",  0,      Inferior,   Moros,      Subtle  },
    { "Fate",   0,      Common,     Acanthus,   Subtle  },
    { "Forces", 3,      Ruling,     Obrimos,    Gross   },
    { "Life",   0,      Common,     Thyrsus,    Gross   },
    { "Matter", 0,      Inferior,   Moros,      Gross   },
    { "Mind",   0,      Common,     Mastigos,   Subtle  },
    { "Prime",  3,      Ruling,     Obrimos,    Subtle  },
    { "Space",  0,      Common,     Mastigos,   Gross   },
    { "Spirit", 0,      Common,     Thyrsus,    Subtle  },
    { "Time",   0,      Common,     Acanthus,   Gross   }
};

struct rote_t rotes[] = {
    /* Arcanum,         Dots,   Spell Name,                     Created By, Rote Skill  */
    { &arcana[Forces],  1,      "Nightvision",                  "Unknown",  &skills[Mental][Investigation]  },
    { &arcana[Prime],   1,      "Supernal Vision",              "Unknown",  &skills[Mental][Occult]         },
    { NULL,             0,      NULL,                           NULL,       NULL }
};

char *praxes[] = {
    "Control Electricity",
    "Control Fire",
    NULL
};

struct mundane_equipment_t misc_gear[] = {
    // Equipment,               Durability, Structure,  Size,   Cost);
    { "Amulet of Initiative",   4,          4,          1,      5 },
    { NULL,                     0,          0,          0,      0 }
};

struct weapon_t weapons[] = {
    /* Weapon/Attack,   Dmg,    Short,  Medium, Long,   Clip,   Init,   Str,    Size    */
    { "Glock 9mm",      1,         20,      40,   80,     17,      0,     2,       1 },
    { "Runed Dagger",   0,          0,       0,    0,      0,     -1,     1,       1 },
    { NULL,             0,          0,       0,    0,      0,      0,     0,       0 }
};

void advancement() {
    // Session 1
    --integrity;

    // Buy a point of Serpentine
    ++mundane_xp_spent;

    // After witnessing several uncanny event, Rachel is starting to feel like she's seen it all, and things don't phase her as much.
    ++attributes[Resistance][Social];

    // Rachel Awakens
    awakened = true;
    gnosis = 1;
    wisdom = integrity;
    integrity = 0;

    // Acquire an extra dot in each of Forces and Prime
    arcane_xp_spent += 2;

    // Run and gun: gain an extra dot in Serpentine and Firearms
    mundane_xp_spent += 3;

    // Acquire a point of subterfuge
    mundane_xp_spent += 2;

    // Perform magic in front of sleepers, an Act of Hubris
    --wisdom;

    // Gain Gnosis
    ++gnosis;
    mundane_xp_spent += 1;
    arcane_xp_spent += 4;

    // Acquire Rotes: Nightvision and Supernal Vision
    ++mundane_xp_spent;
    ++arcane_xp_spent;

    // From Amulet of Initiative
    initiative += 2;
}
