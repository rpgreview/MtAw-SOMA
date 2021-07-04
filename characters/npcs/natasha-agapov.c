#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mtaw/mtaw.h>
#include <players/michael.h>

int mundane_xp = 0;
int arcane_xp  = 0;

struct character_overview overview = {
    /* Name        */ "Natasha Agapov",
    /* Age         */ "26",
    /* Player      */ PLAYER_NAME,
    /* Virtue      */ "Kind",
    /* Vice        */ "Wrath",
    /* Concept     */ "Employee at the Museum of Russian Icons",
    /* Chronicle   */ "SOMA",
    /* Path        */ NULL,
    /* Order       */ NULL,
    /* Nimbus      */ NULL,
    /* Quote       */ "Sorry, this area is for staff only.",
    /* Background  */ "Natasha was raised in Russia. She moved to USA upon receiving a scholarship to study Art History at Harvard.",
    /* Description */ "5'7\", honey-coloured hair, brown eyes.",
    /* RP Hints    */ NULL,
    /* Is NPC?     */ true
};

char *aspirations[] = {
    "Get a grant to study pre-colonial Slavic-Alaskan relations.",
    "Get a new car.",
    "Acquire an impressive item to hang in apartment.",
    NULL
};

char *obsessions[] = {
    NULL
};

int attributes[n_attribute_types][n_categories] = {
                   /* MENTAL                    PHYSICAL                SOCIAL       */
/* POWER      */ { /* Intelligence */ 4,     /* Strength  */ 1,      /* Presence     */  3 },
/* FINESSE    */ { /* Wits         */ 2,     /* Dexterity */ 3,      /* Manipulation */  2 },
/* RESISTANCE */ { /* Resolve      */ 2,     /* Stamina   */ 3,      /* Composure    */  1 }
};

struct skill_t skills[n_categories][n_mental_skills] = {
    /*  { Category,     Name,               Specialization, Dots,   Modifiers  } */
    // Mental
    {   { Mental,       "Academics",        "Art History",  3,      IS_ASSET  },
        { Mental,       "Computer",         NULL,           1,      0  },
        { Mental,       "Crafts",           NULL,           2,      0  },
        { Mental,       "Investigation",    "Riddles",      2,      0  },
        { Mental,       "Medicine",         NULL,           0,      0  },
        { Mental,       "Occult",           NULL,           1,      0  },
        { Mental,       "Politics",         NULL,           1,      0  },
        { Mental,       "Science",          NULL,           1,      IS_ASSET  } },
    // Physical
    {   { Physical,     "Athletics",        NULL,           2,      0  },
        { Physical,     "Brawl",            NULL,           0,      0  },
        { Physical,     "Drive",            NULL,           0,      0  },
        { Physical,     "Firearms",         NULL,           0,      0  },
        { Physical,     "Larceny",          NULL,           0,      0  },
        { Physical,     "Stealth",          NULL,           0,      0  },
        { Physical,     "Survival",         NULL,           2,      0  },
        { Physical,     "Weaponry",         NULL,           0,      0  } },
    // Social
    {   { Social,       "Animal Ken",       NULL,           0,      0  },
        { Social,       "Empathy",          NULL,           1,      0  },
        { Social,       "Expression",       "Painting",     2,      0  },
        { Social,       "Intimidation",     NULL,           0,      0  },
        { Social,       "Persuasion",       NULL,           1,      0  },
        { Social,       "Socialize",        NULL,           2,      0  },
        { Social,       "Streetwise",       NULL,           0,      0  },
        { Social,       "Subterfuge",       NULL,           1,      0  } }
};

struct merit merits[] = {
    { "Interdisciplinary Specialty (Art History)",  1   },
    { "Language (English)",                         1   },
    { "Multilingual (Latin, Greek)",                1   },
    { "Professional Training (Academic)",           2   },
    { "Contacts (Artists, Historians)",             2   },  // From Prof Training
    { "Taste",                                      1   },
    { "Status (Academic)",                          1   },
    { NULL,                                         0   }
};

struct arcanum_t arcana[n_arcana] = {
    /* Name     Dots    Status      Path        Manifestation */
    { "Death",  0,      Common,     Moros,      Subtle  },
    { "Fate",   0,      Common,     Acanthus,   Subtle  },
    { "Forces", 0,      Common,     Obrimos,    Gross   },
    { "Life",   0,      Common,     Thyrsus,    Gross   },
    { "Matter", 0,      Common,     Moros,      Gross   },
    { "Mind",   0,      Common,     Mastigos,   Subtle  },
    { "Prime",  0,      Common,     Obrimos,    Subtle  },
    { "Space",  0,      Common,     Mastigos,   Gross   },
    { "Spirit", 0,      Common,     Thyrsus,    Subtle  },
    { "Time",   0,      Common,     Acanthus,   Gross   }
};

struct rote_t rotes[] = {
    /* Arcanum, Dots,   Spell Name,         Created By, Rote Skill  */
    { NULL,     0,      NULL,               NULL,       NULL }
};

char *praxes[] = {
    NULL
};

struct mundane_equipment_t misc_gear[] = {
    { NULL, 0, 0, 0, 0 }
};

struct weapon_t weapons[] = {
    { NULL, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void advancement() {
    // Where to note experience expenditures
}
