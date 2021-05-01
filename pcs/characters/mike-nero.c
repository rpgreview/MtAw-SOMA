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
#include "players/jay.h"

// Need to grab player XP here before consuming it in shared source files.
int mundane_xp = MUNDANE_XP;
int arcane_xp  = ARCANE_XP;

struct character_overview overview = {
    /* Name        */ "Michael Nero",
    /* Age         */ "",
    /* Player      */ PLAYER_NAME,
    /* Virtue      */ "Faith: Michael has faith that in preserving life, he gives meaning to his own.",
    /* Vice        */ "Painkiller Addiction",
    /* Concept     */ "Strung Out Paramedic",
    /* Chronicle   */ "SOMA",
    /* Faction     */ "",
    /* Group       */ "",
    /* Quote       */ "Apply pressure.",
    /* Background  */ "Michael’s a hard worker. He always has been. When he was young, Michael spent his summers helping his grandfather renovate the family’s vacation house. It was his escape from the harsh city and its dangers. He was convinced that everyone in his family was going to get mugged or hit by a drunk driver or any number of other morbid nightmares he had about the city’s horrors. But it was different here. Calm, soothing. He rehung walls with his grandfather, installed new windows and even helped out with the roofing. It was nice to do things with his hands, to see the immediate difference from his work.\n\n\
One day, while he was on the roof, he saw his grandfather fall in the yard. He whispered to the boy that it felt like a demon was sitting on his chest. By the time the paramedics arrived, Michael’s grandfather was dead. They tried for twenty minutes to resuscitate him, but there was nothing they could do.\n\n\
Michael never went out to the vacation house again. The family sold it a few summers later, but Michael had already learned a lesson from it and moved on: death comes everywhere. He blamed himself for failing his grandfather. He should have been able to help him. He read up on heart attacks, and if he had only done this, or given him that, he could have saved him. His family thought he was being noble when he started school to be a paramedic.\n\n\
To Michael, death is meaningless violence, fear and indignity. Life has meaning, and must be preserved, if only to stave off the entropy of death. He started riding the night streets with his partner, and soon he discovered that he doesn’t actually have the resources to deal with the constant loss of patients.\n\n\
But the pills take the edge off that.",
    /* Description */ "Michael has a gaunt look to him, like he doesn’t get nearly enough sleep. His uncombed hair is wild and thick. Three days of stubble is scattered across his cheeks and chin, and the worst part is, it works for him. He’s more attractive when everything’s just slightly askew than he is when he cleans up. Which is basically how he likes it.",
    /* RP Hints    */ "You look like you don’t get enough sleep because you seriously don’t get enough sleep. Between the wonky hours of driving an ambulance and the dreams, you have severe insomnia most of the time. You’re tempted to blow off the ghost thing as hallucinations, whether from the drugs or the sleep deprivation, you don’t know."
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

struct mundane_equipment_t misc_gear[] = {
    // Equipment,           Durability, Structure,  Size,   Cost);
    { "First Aid Kit +1",   1,          3,          2,      2 },
    { NULL, 0, 0, 0, 0 }
};

struct weapon_t weapons[] = {
    /* Weapon/Attack,   Dmg,    Short,  Medium, Long,   Clip,   Init,   Str,    Size    */
    { "Runed Dagger",   0,          0,       0,    0,      0,     -1,     1,       1 },
    { NULL,             0,          0,       0,    0,      0,      0,     0,       0 }
};

void advancement() {
    // Where to note experience expenditures
}
