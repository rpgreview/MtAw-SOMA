#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mtaw/mtaw.h>
#include <players/kaushik.h>

// Need to grab player XP here since it's the only non-shared source file.
int mundane_xp = MUNDANE_XP;
int arcane_xp  = ARCANE_XP;

struct character_overview overview = {
    /* Name        */ "Anita Talis (Shadow Name: Aristekha)",
    /* Age         */ "28",
    /* Player      */ PLAYER_NAME,
    /* Virtue      */ "Patient",
    /* Vice        */ "Fickle",
    /* Concept     */ "Initiatrix",
    /* Chronicle   */ "SOMA",
    /* Path        */ "Thyrsus",
    /* Order       */ "Guardians of the Veil",
    /* Quote       */ NULL,
    /* Background  */ "Anita was an investigative journalist focused on bringing truth to power. But the more she learned, the more she realised that there is something deeper going on behind the scenes.\n\nWhile investigating illegal logging in Maine, she found herself lost in the deep forest. It was late autumn and as the first snows began to fall, she realised that she could soon die, alone in the cold. Although panicked at first, it dawned on her that she had never felt so invigorated. She could sense the unity of her spirit with the life in the surrounding wilderness, and a connection of her life force with hidden spirit entities peering at her from the shadows.\n\nChannelling this new wildness in her being, she not only survived but thrived, and returned to civilisation a changed person. Later, she found out that this experience is called Awakening, and she felt the calling to help awaken others to the same experience. Her investigative skills and interest in Awakening made her a natural fit for the Guardians of the Veil.",
    /* Description */ NULL,
    /* RP Hints    */ NULL
};

char *aspirations[] = {
    NULL
};

char *obsessions[] = {
    "Awakening",
    NULL
};

int attributes[n_attribute_types][n_categories] = {
                   /* MENTAL                    PHYSICAL                SOCIAL       */
/* POWER      */ { /* Intelligence */ 2,     /* Strength  */ 1,      /* Presence     */  1 },
/* FINESSE    */ { /* Wits         */ 3,     /* Dexterity */ 3,      /* Manipulation */  3 },
/* RESISTANCE */ { /* Resolve      */ 3,     /* Stamina   */ 3,      /* Composure    */  3 }
};

struct skill_t skills[n_categories][n_mental_skills] = {
    /*  { Category,     Name,               Specialization, Dots,   Modifiers  } */
    // Mental
    {   { Mental,       "Academics",        "Law",          1,      0  },
        { Mental,       "Computer",         NULL,           0,      0  },
        { Mental,       "Crafts",           NULL,           1,      0  },
        { Mental,       "Investigation",    "Journalism",   2,      IS_ASSET | IS_ORDER_ROTE_SKILL  },
        { Mental,       "Medicine",         NULL,           1,      0  },
        { Mental,       "Occult",           NULL,           1,      0  },
        { Mental,       "Politics",         NULL,           1,      0  },
        { Mental,       "Science",          NULL,           0,      0  } },
    // Physical
    {   { Physical,     "Athletics",        NULL,           1,      0  },
        { Physical,     "Brawl",            NULL,           0,      0  },
        { Physical,     "Drive",            NULL,           0,      0  },
        { Physical,     "Firearms",         NULL,           1,      0  },
        { Physical,     "Larceny",          NULL,           0,      0  },
        { Physical,     "Stealth",          "Shadowing",    1,      IS_ORDER_ROTE_SKILL  },
        { Physical,     "Survival",         NULL,           1,      0  },
        { Physical,     "Weaponry",         NULL,           0,      0  } },
    // Social
    {   { Social,       "Animal Ken",       NULL,           1,      0  },
        { Social,       "Empathy",          NULL,           1,      0  },
        { Social,       "Expression",       "Journalism",   2,      IS_ASSET  },
        { Social,       "Intimidation",     NULL,           1,      0  },
        { Social,       "Persuasion",       NULL,           1,      0  },
        { Social,       "Socialize",        NULL,           1,      0  },
        { Social,       "Streetwise",       NULL,           1,      0  },
        { Social,       "Subterfuge",       "Lying",        3,      IS_ORDER_ROTE_SKILL  } }
};

struct merit merits[] = {
    { "Holistic Awareness",                 1 },
    { "Multilingual (Hindi, Arabic)",       1 },
    { "Professional Training (Journalist)", 3 },
    { "Contacts (Academic, Journalist)",    2 }, // From prof training
    { "Order Status (GoV)",                 1 },
    { "High Speech",                        1 },
    { "Occultation",                        2 },
    { "Alternate Identity",                 2 },
    { "Anonymity",                          1 },
    { NULL,                                 0 }
};

struct arcanum_t arcana[n_arcana] = {
    /* Name     Dots    Status      Path        Manifestation */
    { "Death",  0,      Common,     Moros,      Subtle  },
    { "Fate",   1,      Common,     Acanthus,   Subtle  },
    { "Forces", 0,      Common,     Obrimos,    Gross   },
    { "Life",   2,      Ruling,     Thyrsus,    Gross   },
    { "Matter", 0,      Common,     Moros,      Gross   },
    { "Mind",   0,      Common,     Mastigos,   Subtle  },
    { "Prime",  0,      Common,     Obrimos,    Subtle  },
    { "Space",  0,      Inferior,   Mastigos,   Gross   },
    { "Spirit", 2,      Ruling,     Thyrsus,    Subtle  },
    { "Time",   1,      Common,     Acanthus,   Gross   }
};

struct rote_t rotes[] = {
    { &arcana[Fate],    1,  "Quantum Flux",             "Unknown", &skills[Mental][Occult] },
    { &arcana[Time],    1,  "Green Light/Red Light",    "Unknown", &skills[Social][Subterfuge] },
    { &arcana[Spirit],  1,  "Gremlins",                 "Unknwon", &skills[Social][Subterfuge] },
    { NULL, 0, NULL, NULL, NULL }
};

char *praxes[] = {
    "Speak With Beasts",
    NULL
};

struct mundane_equipment_t misc_gear[] = {
    { "Guitar", 2, 3, 3, 2 },
    { NULL,     0, 0, 0, 0 }
};

struct weapon_t weapons[] = {
    { NULL, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void advancement() {
    awakened = true;
    gnosis = 1;
    wisdom = integrity;
    integrity = 0;
}
