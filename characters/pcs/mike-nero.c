/*
   Based on a character from "A Nightmare at Hill Manor" by Christopher Lee Simmons, 2011.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mtaw/mtaw.h>
#include <players/jay.h>

// Need to grab player XP here before consuming it in shared source files.
int mundane_xp = MUNDANE_XP;
int arcane_xp  = ARCANE_XP;

struct character_overview overview = {
    /* Name        */ "Michael Nero (Shadow Name: Marcus Aurelius)",
    /* Age         */ "",
    /* Player      */ PLAYER_NAME,
    /* Virtue      */ "Faith: Michael has faith that in preserving life, he gives meaning to his own.",
    /* Vice        */ "Painkiller Addiction",
    /* Concept     */ "Strung Out Paramedic",
    /* Chronicle   */ "SOMA",
    /* Path        */ "Moros",
    /* Order       */ "Mysterium",
    /* Nimbus      */ NULL,
    /* Quote       */ "Apply pressure.",
    /* Background  */ "Michael’s a hard worker. He always has been. When he was young, Michael spent his summers helping his grandfather renovate the family’s vacation house. It was his escape from the harsh city and its dangers. He was convinced that everyone in his family was going to get mugged or hit by a drunk driver or any number of other morbid nightmares he had about the city’s horrors. But it was different here. Calm, soothing. He rehung walls with his grandfather, installed new windows and even helped out with the roofing. It was nice to do things with his hands, to see the immediate difference from his work.\n\n\
One day, while he was on the roof, he saw his grandfather fall in the yard. He whispered to the boy that it felt like a demon was sitting on his chest. By the time the paramedics arrived, Michael’s grandfather was dead. They tried for twenty minutes to resuscitate him, but there was nothing they could do.\n\n\
Michael never went out to the vacation house again. The family sold it a few summers later, but Michael had already learned a lesson from it and moved on: death comes everywhere. He blamed himself for failing his grandfather. He should have been able to help him. He read up on heart attacks, and if he had only done this, or given him that, he could have saved him. His family thought he was being noble when he started school to be a paramedic.\n\n\
To Michael, death is meaningless violence, fear and indignity. Life has meaning, and must be preserved, if only to stave off the entropy of death. He started riding the night streets with his partner, and soon he discovered that he doesn’t actually have the resources to deal with the constant loss of patients.\n\n\
But the pills take the edge off that.",
    /* Description */ "Michael has a gaunt look to him, like he doesn’t get nearly enough sleep. His uncombed hair is wild and thick. Three days of stubble is scattered across his cheeks and chin, and the worst part is, it works for him. He’s more attractive when everything’s just slightly askew than he is when he cleans up. Which is basically how he likes it.",
    /* RP Hints    */ "You look like you don’t get enough sleep because you seriously don’t get enough sleep. Between the wonky hours of driving an ambulance and the dreams, you have severe insomnia most of the time. You’re tempted to blow off the ghost thing as hallucinations, whether from the drugs or the sleep deprivation, you don’t know.\n\n\
Michael has vowed to protect the secrets of the Mysterium, uphold the Order's tenets, and honour its rulings.",
    /* Is NPC?     */ false
};

char *aspirations[] = {
    "Save a life",
    "Find a magic book or teacher",
    NULL
};

char *obsessions[] = {
    "The mysterious villa which serves as lodge for the New England Wizards (NEW)",
    NULL
};

int attributes[n_attribute_types][n_categories] = {
                   /* MENTAL                    PHYSICAL                SOCIAL       */
/* POWER      */ { /* Intelligence */ 3,     /* Strength  */ 2,      /* Presence     */  1 },
/* FINESSE    */ { /* Wits         */ 3,     /* Dexterity */ 2,      /* Manipulation */  1 },
/* RESISTANCE */ { /* Resolve      */ 2,     /* Stamina   */ 3,      /* Composure    */  5 }
};

struct skill_t skills[n_categories][n_mental_skills] = {
    /*  { Category,     Name,               Specialization, Dots,   Modifiers  } */
    // Mental
    {   { Mental,       "Academics",        NULL,           2,      0  },
        { Mental,       "Computer",         NULL,           0,      0  },
        { Mental,       "Crafts",           NULL,           0,      0  },
        { Mental,       "Investigation",    NULL,           2,      0  },
        { Mental,       "Medicine",         "First Aid",    3,      IS_ASSET  },
        { Mental,       "Occult",           NULL,           1,      0  },
        { Mental,       "Politics",         NULL,           0,      0  },
        { Mental,       "Science",          "Chemistry",    3,      0  } },
    // Physical
    {   { Physical,     "Athletics",        NULL,           1,      0  },
        { Physical,     "Brawl",            NULL,           1,      0  },
        { Physical,     "Drive",            NULL,           1,      IS_ASSET  },
        { Physical,     "Firearms",         NULL,           0,      0  },
        { Physical,     "Larceny",          NULL,           1,      0  },
        { Physical,     "Stealth",          NULL,           0,      0  },
        { Physical,     "Survival",         NULL,           1,      0  },
        { Physical,     "Weaponry",         NULL,           0,      0  } },
    // Social
    {   { Social,       "Animal Ken",       NULL,           0,      0  },
        { Social,       "Empathy",          "Calming",      2,      0  },
        { Social,       "Expression",       NULL,           0,      0  },
        { Social,       "Intimidation",     NULL,           0,      0  },
        { Social,       "Persuasion",       NULL,           1,      0  },
        { Social,       "Socialize",        NULL,           1,      0  },
        { Social,       "Streetwise",       NULL,           2,      0  },
        { Social,       "Subterfuge",       NULL,           1,      0  } }
};

struct merit merits[] = {
    { "Status (Paramedic)",                 1 },
    { "Tolerance for Biology",              1 },
    { "Resources",                          5 },
    { "Good Time Management",               1 },
    { "Prof Training (Paramedic)",          2 },
    { "Contacts (Doctors, Cops)",           2 }, // Due to Prof Training
    { "Library",                            1 },
    { "Order Status (Mysterium)",           2 }, // Conditional on keeping vow and demonstrating proficiency in Order Rote Skills.
    { "Safe Place (Hill Manor Penthouse)",  3 }, // Purchased with Resources.
    { NULL,                                 0 },
};

struct arcanum_t arcana[n_arcana] = {
    /* Name     Dots    Status      Path        Manifestation */
    { "Death",  2,      Ruling,     Moros,      Subtle  },
    { "Fate",   0,      Common,     Acanthus,   Subtle  },
    { "Forces", 0,      Common,     Obrimos,    Gross   },
    { "Life",   0,      Common,     Thyrsus,    Gross   },
    { "Matter", 3,      Ruling,     Moros,      Gross   },
    { "Mind",   0,      Common,     Mastigos,   Subtle  },
    { "Prime",  0,      Common,     Obrimos,    Subtle  },
    { "Space",  0,      Common,     Mastigos,   Gross   },
    { "Spirit", 0,      Inferior,   Thyrsus,    Subtle  },
    { "Time",   0,      Common,     Acanthus,   Gross   }
};

struct rote_t rotes[] = {
    /* Arcanum, Dots,   Spell Name,         Created By, Rote Skill  */
    { NULL,     0,      NULL,               NULL,       NULL }
};

char *praxes[] = {
    "Remote Control",
    NULL
};

struct mundane_equipment_t misc_gear[] = {
    // Equipment,           Durability, Structure,  Size,   Cost);
    { "First Aid Kit +1",   1,          3,          2,      2 },
    { "Crime Scene Kit",    2,          2,          3,      2 },
    { "Scuba Gear",         2,          3,          3,      2 },
    { "Submersible Drone",  2,          3,          2,      3 },
    { NULL, 0, 0, 0, 0 }
};

struct weapon_t weapons[] = {
    /* Weapon/Attack,   Dmg,    Short,  Medium, Long,   Clip,   Init,   Str,    Size    */
    { "Runed Dagger",   0,          0,       0,    0,      0,     -1,     1,       1 },
    { NULL,             0,          0,       0,    0,      0,      0,     0,       0 }
};

void advancement() {
    // Unlock Brawl
    mundane_xp_spent += 2;

    // Get a generous inheritance: Resources += 3
    mundane_xp_spent += 3;

    // Nero Awakens
    awakened = true;
    gnosis = 1;
    wisdom = integrity;
    integrity = 0;

    // Acquire an extra dot in each of Death and Matter
    arcane_xp_spent += 2;
}
