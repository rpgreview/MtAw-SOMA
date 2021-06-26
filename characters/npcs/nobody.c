// Just a test character for baselining various functions
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mtaw/mtaw.h>
#include <players/nobody.h>

// Need to grab player XP here since it's the only non-shared source file.
int mundane_xp = MUNDANE_XP;
int arcane_xp  = ARCANE_XP;

struct character_overview overview = {
    /* Name        */ "Nobody",
    /* Age         */ "",
    /* Player      */ PLAYER_NAME,
    /* Virtue      */ NULL,
    /* Vice        */ NULL,
    /* Concept     */ NULL,
    /* Chronicle   */ "SOMA",
    /* Path        */ NULL,
    /* Order       */ NULL,
    /* Quote       */ NULL,
    /* Background  */ NULL,
    /* Description */ NULL,
    /* RP Hints    */ NULL,
    /* Is NPC?     */ true
};

char *aspirations[] = {
    NULL
};

char *obsessions[] = {
    NULL
};

int attributes[n_attribute_types][n_categories] = {
                   /* MENTAL                    PHYSICAL                SOCIAL       */
/* POWER      */ { /* Intelligence */ 1,     /* Strength  */ 1,      /* Presence     */  1 },
/* FINESSE    */ { /* Wits         */ 1,     /* Dexterity */ 1,      /* Manipulation */  1 },
/* RESISTANCE */ { /* Resolve      */ 1,     /* Stamina   */ 1,      /* Composure    */  1 }
};

struct skill_t skills[n_categories][n_mental_skills] = {
    /*  { Category,     Name,               Specialization, Dots,   Modifiers  } */
    // Mental
    {   { Mental,       "Academics",        NULL,           0,      0  },
        { Mental,       "Computer",         NULL,           0,      0  },
        { Mental,       "Crafts",           NULL,           0,      0  },
        { Mental,       "Investigation",    NULL,           0,      0  },
        { Mental,       "Medicine",         NULL,           0,      0  },
        { Mental,       "Occult",           NULL,           0,      0  },
        { Mental,       "Politics",         NULL,           0,      0  },
        { Mental,       "Science",          NULL,           0,      0  } },
    // Physical
    {   { Physical,     "Athletics",        NULL,           0,      0  },
        { Physical,     "Brawl",            NULL,           0,      0  },
        { Physical,     "Drive",            NULL,           0,      0  },
        { Physical,     "Firearms",         NULL,           0,      0  },
        { Physical,     "Larceny",          NULL,           0,      0  },
        { Physical,     "Stealth",          NULL,           0,      0  },
        { Physical,     "Survival",         NULL,           0,      0  },
        { Physical,     "Weaponry",         NULL,           0,      0  } },
    // Social
    {   { Social,       "Animal Ken",       NULL,           0,      0  },
        { Social,       "Empathy",          NULL,           0,      0  },
        { Social,       "Expression",       NULL,           0,      0  },
        { Social,       "Intimidation",     NULL,           0,      0  },
        { Social,       "Persuasion",       NULL,           0,      0  },
        { Social,       "Socialize",        NULL,           0,      0  },
        { Social,       "Streetwise",       NULL,           0,      0  },
        { Social,       "Subterfuge",       NULL,           0,      0  } }
};

struct merit merits[] = {
    { NULL,                         0 }
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
