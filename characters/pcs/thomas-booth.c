/*
   Based on a character from "A Nightmare at Hill Manor" by Christopher Lee Simmons, 2011.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mtaw/mtaw.h>
#include <players/michael.h>

// Need to grab player XP here since it's the only non-shared source file.
int mundane_xp = MUNDANE_XP;
int arcane_xp  = ARCANE_XP;

struct character_overview overview = {
    /* Name        */ "Thomas Booth (Shadow Name: Moripilude)",
    /* Age         */ "",
    /* Player      */ PLAYER_NAME,
    /* Virtue      */ "Charity. Thomas can't resist helping those in need.",
    /* Vice        */ "Lust. Thomas has a definite weakness for the ladies.",
    /* Concept     */ "Rugged Librarian",
    /* Chronicle   */ "SOMA",
    /* Path        */ "Acanthus",
    /* Order       */ "Mysterium",
    /* Legacy      */ NULL,
    /* Nimbus      */ "Rural dawn, cold dewy air with a hint of apple blossoms, oats and wood fires",
    /* Quote       */ "Sure, I can help you study. Come over around… seven?",
    /* Background  */ "A bright child, Thomas grew up on the university campus where his parents taught. His mother was an English professor, while his father coached the school’s baseball team. Each of his parents made (what they thought were) subtle attempts to encourage Thom’s interest in their chosen passion, but he never understood why he couldn’t love both. Throughout school, Thomas pursued three things: knowledge, athletics and girls, not necessarily in that order. By the time he actually enrolled at the university he was already well-known to the faculty. They kept an eye on him like family, which turned out to be a double-edged sword. They were glad to help, but just as glad to dish out advice and meddle in his affairs. (“Oh Thomas, I don’t mean to pry, but do you really mean to date her? She’s a C student at best. You can do better.”)\n\n\
Eventually, it became something of a badge of honor for his professors to disapprove of his girlfriends. But that’s where his rebellion stopped. He worked his way through the university and graduated with a degree in English before getting his masters in library science.\n\n\
For Thomas, the decision was always easy. He knew he wasn’t good enough to go pro, no matter how much he loved baseball. He also couldn’t imagine leaving the halls of academia. It afforded him access to books and kept him on campus which means, at least for now, that it keeps him close to girls. Eventually, he’ll grow up and settle down, but he sees no reason to do that just yet.\n\n\
Thomas moved into Hill Manor Apartments just over a year ago. He likes the place; it’s a far cry from the wood paneling and old world design of his parents’ house, but the early 20th century architecture of the building feels familiar. Within a month, Thomas was recruited by Janice for the poker game. Another neighbor, Keenan is a student at the university, and Thomas knows him from the library.",
    /* Description */ "Thomas is a wiry man of average height, with brown hair. He plays to his strengths, dressing well, with a kind of geek chic that makes him attractive instead of nerdy. He carries himself with a grace and athleticism that surprises people who expect the awkward and clumsy stereotypical librarian.",
    /* RP Hints    */ "You’re smart, but not in a pedantic way. You use your observational skills and knowledge to surprise and impress people, particularly girls, not to make them feel stupid. On the other hand, you’re nearly as comfortable on the field as in the library, so you’re not afraid to get your hands dirty.\n\n\
Thomas has vowed to protect the secrets of the Mysterium, uphold the Order's tenets, and honour its rulings.",
    /* Is NPC?     */ false
};

char *aspirations[] = {
    "Acquire an impressive item to hang in apartment.",
    "Meet someone with connection to Salem witch trials, preferably someone who was actually there ;)",
    "Acquire a demesne.",
    NULL
};

char *obsessions[] = {
    "17th century New England witch trials",
    NULL
};

int attributes[n_attribute_types][n_categories] = {
                   /* MENTAL                    PHYSICAL                SOCIAL       */
/* POWER      */ { /* Intelligence */ 3,     /* Strength  */ 2,      /* Presence     */  3 },
/* FINESSE    */ { /* Wits         */ 3,     /* Dexterity */ 3,      /* Manipulation */  1 },
/* RESISTANCE */ { /* Resolve      */ 2,     /* Stamina   */ 2,      /* Composure    */  3 }
};

struct skill_t skills[n_categories][n_mental_skills] = {
    /*  { Category,     Name,               Specialization, Dots,   Modifiers  } */
    // Mental
    {   { Mental,       "Academics",        "Literature",   4,      IS_ASSET  },
        { Mental,       "Computer",         NULL,           2,      0  },
        { Mental,       "Crafts",           NULL,           0,      0  },
        { Mental,       "Investigation",    NULL,           2,      0  },
        { Mental,       "Medicine",         NULL,           0,      0  },
        { Mental,       "Occult",           NULL,           2,      0  },
        { Mental,       "Politics",         NULL,           0,      0  },
        { Mental,       "Science",          NULL,           1,      IS_ASSET  } },
    // Physical
    {   { Physical,     "Athletics",        "Running",      3,      0  },
        { Physical,     "Brawl",            NULL,           1,      0  },
        { Physical,     "Drive",            NULL,           0,      0  },
        { Physical,     "Firearms",         NULL,           0,      0  },
        { Physical,     "Larceny",          NULL,           0,      0  },
        { Physical,     "Stealth",          NULL,           0,      0  },
        { Physical,     "Survival",         NULL,           1,      0  },
        { Physical,     "Weaponry",         NULL,           0,      0  } },
    // Social
    {   { Social,       "Animal Ken",       NULL,           0,      0  },
        { Social,       "Empathy",          NULL,           1,      0  },
        { Social,       "Expression",       NULL,           1,      0  },
        { Social,       "Intimidation",     NULL,           0,      0  },
        { Social,       "Persuasion",       "Flirt",        1,      0  },
        { Social,       "Socialize",        NULL,           3,      0  },
        { Social,       "Streetwise",       NULL,           1,      0  },
        { Social,       "Subterfuge",       NULL,           0,      0  } }
};

struct merit merits[] = {
    { "Martial Arts",                               4 },
    { "Prof Training (Librarian)",                  2 },
    { "Contacts (Academics, Sports Journalists)",   2 }, // Due to Prof Training
    { "Library",                                    1 },
    { "Trained Observer",                           1 },
    { "Fame",                                       1 }, // Some combination of college sports, Salem witch ancestor, and being filmed at the Askuanebi event.
    { "Inheritance (Descended from Salem Witch)",   2 },
    { "Order Status (Mysterium)",                   2 }, // Conditional on keeping vow and demonstrating proficiency in Order Rote Skills.
    { "Familiar",                                   3 }, // From the Phylacterion
    { NULL,                                         0 }
};

struct arcanum_t arcana[n_arcana] = {
    /* Name     Dots    Status      Path        Manifestation */
    { "Death",  1,      Common,     Moros,      Subtle  },
    { "Fate",   2,      Ruling,     Acanthus,   Subtle  },
    { "Forces", 0,      Inferior,   Obrimos,    Gross   },
    { "Life",   0,      Common,     Thyrsus,    Gross   },
    { "Matter", 0,      Common,     Moros,      Gross   },
    { "Mind",   0,      Common,     Mastigos,   Subtle  },
    { "Prime",  0,      Common,     Obrimos,    Subtle  },
    { "Space",  0,      Common,     Mastigos,   Gross   },
    { "Spirit", 0,      Common,     Thyrsus,    Subtle  },
    { "Time",   3,      Ruling,     Acanthus,   Gross   }
};

struct rote_t rotes[] = {
    /* Arcanum,         Dots,   Spell Name,                     Rote Skill  */
    { &arcana[Fate],    1,      "Serendipity",                  &skills[Physical][Survival]     },
    { &arcana[Time],    1,      "Divination",                   &skills[Mental][Investigation]  },
    { NULL,             0,      NULL,                           NULL }
};

struct praxis_t praxes[] = {
    /* Name                     Gnosis Freebie? */
    { "Perfect Timing",         true            },
    { "Postcognition",          true            },
    { NULL,                     false           }
};

struct familiar_t amanda = {
/* Name         */  "Amanda",
/* Path         */  Moros,
/* Power        */  1,
/* Finesse      */  4,
/* Resistance   */  3,
/* Agenda       */  "Free all who are caged.",
/* Notes        */  "Amanda is a ghost who was originally the young daughter of a witch. While on the run from witch hunters, she found her way into a magical facility called the Phylacterion. While exploring the Phylacterion, she befriended and uncaged a powerful demon called Glasya-Labolas. They wandered around the facility together for a while, trying to find a way out. Glasya-Labolas fell into a trap intended for escapees, and Amanda was stuck in the trap with him. Without access to food or water, she soon died. Centuries later, Thomas found her ghost and helped retrieve her corpse, hoping to give it a proper burial. She agreed to become his friend and familiar, and invested herself into the body of a red squirrel (base traits: 1/3/1).",
/* Abilities    */  {
        "Innocuous",
        "Animal Ken 2",
        NULL
    }
};

struct familiar_t *familiars[] = {
    &amanda,
    NULL
};

struct mundane_equipment_t misc_gear[] = {
    { NULL, 0, 0, 0, 0 }
};

struct weapon_t weapons[] = {
    { NULL, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void advancement() {
    // Purchase the Trained Observer Merit
    ++mundane_xp_spent;

    // Thomas Awakens
    awakened = true;
    gnosis = 1;
    wisdom = integrity;
    integrity = 0;

    // Purchase Fame and Inheritance Merits
    mundane_xp_spent += 3;

    // Learn Survival
    mundane_xp_spent += 2;

    // Gain Gnosis
    ++gnosis;
    arcane_xp_spent += 5;

    // Gain Ruling Arcana dots at discount rates
    ++mundane_xp_spent;
    ++arcane_xp_spent;

    // Acquire Rotes: Serendipity and Divination
    ++mundane_xp_spent;
    ++arcane_xp_spent;

    // Acquire a dot in Death.
    // One of the first six dots, so available for 2XP.
    // This is then reduced to 1XP thanks to Familiar tutelage.
    ++arcane_xp_spent;
}
