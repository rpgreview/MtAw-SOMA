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
#include "players/michael.h"

// Need to grab player XP here since it's the only non-shared source file.
int mundane_xp = MUNDANE_XP;
int arcane_xp  = ARCANE_XP;

struct character_overview overview = {
    /* Name        */ "Thomas Booth",
    /* Age         */ "",
    /* Player      */ PLAYER_NAME,
    /* Virtue      */ "Charity. Thomas can't resist helping those in need.",
    /* Vice        */ "Lust. Thomas has a definite weakness for the ladies.",
    /* Concept     */ "Rugged Librarian",
    /* Chronicle   */ "SOMA",
    /* Faction     */ "",
    /* Group       */ "",
    /* Quote       */ "Sure, I can help you study. Come over around… seven?",
    /* Background  */ "A bright child, Thomas grew up on the university campus where his parents taught. His mother was an English professor, while his father coached the school’s baseball team. Each of his parents made (what they thought were) subtle attempts to encourage Thom’s interest in their chosen passion, but he never understood why he couldn’t love both. Throughout school, Thomas pursued three things: knowledge, athletics and girls, not necessarily in that order. By the time he actually enrolled at the university he was already well-known to the faculty. They kept an eye on him like family, which turned out to be a double-edged sword. They were glad to help, but just as glad to dish out advice and meddle in his affairs. (“Oh Thomas, I don’t mean to pry, but do you really mean to date her? She’s a C student at best. You can do better.”)\n\n\
Eventually, it became something of a badge of honor for his professors to disapprove of his girlfriends. But that’s where his rebellion stopped. He worked his way through the university and graduated with a degree in English before getting his masters in library science.\n\n\
For Thomas, the decision was always easy. He knew he wasn’t good enough to go pro, no matter how much he loved baseball. He also couldn’t imagine leaving the halls of academia. It afforded him access to books and kept him on campus which means, at least for now, that it keeps him close to girls. Eventually, he’ll grow up and settle down, but he sees no reason to do that just yet.\n\n\
Thomas moved into Hill Manor Apartments just over a year ago. He likes the place; it’s a far cry from the wood paneling and old world design of his parents’ house, but the early 20th century architecture of the building feels familiar. Within a month, Thomas was recruited by Janice for the poker game. Another neighbor, Keenan is a student at the university, and Thomas knows him from the library.",
    /* Description */ "Thomas is a wiry man of average height, with brown hair. He plays to his strengths, dressing well, with a kind of geek chic that makes him attractive instead of nerdy. He carries himself with a grace and athleticism that surprises people who expect the awkward and clumsy stereotypical librarian.",
    /* RP Hints    */ "You’re smart, but not in a pedantic way. You use your observational skills and knowledge to surprise and impress people, particularly girls, not to make them feel stupid. On the other hand, you’re nearly as comfortable on the field as in the library, so you’re not afraid to get your hands dirty."
};

char *aspirations[] = {
    "Seduce someone",
    NULL
};

char *obsessions[] = {
    NULL
};

int attributes[n_attribute_types][n_categories] = {
                   /* MENTAL                    PHYSICAL                SOCIAL       */
/* POWER      */ { /* Intelligence */ 3,     /* Strength  */ 2,      /* Presence     */  3 },
/* FINESSE    */ { /* Wits         */ 3,     /* Dexterity */ 3,      /* Manipulation */  1 },
/* RESISTANCE */ { /* Resolve      */ 2,     /* Stamina   */ 2,      /* Composure    */  2 }
};

struct skill_t skills[n_categories][n_mental_skills] = {
        /*{ Category,   Name,               Specialization, Dots,   Unlock,  Asset,   Order Rote Skill  } */
    // Mental
    {   { Mental,       "Academics",        "Literature",   4,      false,   true,    false  },
        { Mental,       "Computer",         NULL,           2,      false,   false,   false  },
        { Mental,       "Crafts",           NULL,           0,      false,   false,   false  },
        { Mental,       "Investigation",    NULL,           2,      false,   false,   false  },
        { Mental,       "Medicine",         NULL,           0,      false,   false,   false  },
        { Mental,       "Occult",           NULL,           2,      false,   false,   false  },
        { Mental,       "Politics",         NULL,           0,      false,   false,   false  },
        { Mental,       "Science",          NULL,           1,      false,   true,    false  } },
    // Physical
    {   { Physical,     "Athletics",        "Running",      3,      false,   false,   false  },
        { Physical,     "Brawl",            NULL,           1,      false,   false,   false  },
        { Physical,     "Drive",            NULL,           0,      false,   false,   false  },
        { Physical,     "Firearms",         NULL,           0,      false,   false,   false  },
        { Physical,     "Larceny",          NULL,           0,      false,   false,   false  },
        { Physical,     "Stealth",          NULL,           0,      false,   false,   false  },
        { Physical,     "Survival",         NULL,           0,      false,   false,   false  },
        { Physical,     "Weaponry",         NULL,           0,      false,   false,   false  } },
    // Social
    {   { Social,       "Animal Ken",       NULL,           0,      false,   false,   false  },
        { Social,       "Empathy",          NULL,           1,      false,   false,   false  },
        { Social,       "Expression",       NULL,           1,      false,   false,   false  },
        { Social,       "Intimidation",     NULL,           0,      false,   false,   false  },
        { Social,       "Persuasion",       "Flirt",        1,      false,   false,   false  },
        { Social,       "Socialize",        NULL,           3,      false,   false,   false  },
        { Social,       "Streetwise",       NULL,           1,      false,   false,   false  },
        { Social,       "Subterfuge",       NULL,           0,      false,   false,   false  } }
};

// Different specializations lead to different skill column widths.
// Rule of thumb: keep second number at 21, adjust first number according to skill name + specialization
char *skill_column_fmt[3] = {
    "%-24s %-21s",
    "%-19s %-21s",
    "%-18s %-21s"
};

struct merit merits[] = {
    { "Martial Arts",                               4 },
    { "Prof Training (Librarian)",                  2 },
    { "Contacts (Academics, Sports Journalists)",   2 }, // Due to Prof Training
    { "Library",                                    1 },
    { "Trained Observer",                           1 },
    { NULL,                                         0 }
};

// Like skill columns, merit widths vary a lot per character.
// Customise yours here.
char *merit_fmt = "%-40s %s\n";

struct mundane_equipment_t misc_gear[] = {
    { NULL, 0, 0, 0, 0 }
};

struct weapon_t weapons[] = {
    { NULL, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void advancement() {
    // Where to note experience expenditures

    // Purchase the Trained Observer Merit
    ++mundane_xp_spent;

    // After witnessing several uncanny event, Thomas is starting to feel like he's seen it all, and things don't phase him as much.
    ++attributes[Resistance][Social];
}
