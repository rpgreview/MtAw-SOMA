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
#include "players/lev.h"

// Need to grab player XP here since it's the only non-shared source file.
int mundane_xp = MUNDANE_XP;
int arcane_xp  = ARCANE_XP;

struct character_overview overview = {
    /* Name        */ "Nishan \"Nicky Sims\" Sadoyan",
    /* Age         */ "",
    /* Player      */ PLAYER_NAME,
    /* Virtue      */ "Fortitude. Nicky has a somewhat stoic, “it is what it is” mentality about hardship.",
    /* Vice        */ "Wrath. Nishan tries to remain hopeful, to believe in another way, but his life has continually presented him with obstacles that needed to be knocked down.",
    /* Concept     */ "Small Time Hood",
    /* Chronicle   */ "SOMA",
    /* Path        */ "Mastigos",
    /* Order       */ NULL,
    /* Quote       */ "I do what I gotta do.",
    /* Background  */ "Nishan grew up a nomad. His father kept him moving, from one score to the next, across the rapidly changing landscape of the former Soviet Union. He sat in the back of a Lada Niva playing with toys while his father brokered drug deals in Gori. As a teen, he kept a lookout for Russian authorities while his father broke into a house in Moscow. When they came, he ran.\n\n\
For a while, he bounced around the region on his own, stealing food to get by, squatting in abandoned factories and half-finished “luxury” apartment buildings. Eventually he fell into a smuggling operation and ended up on a ship bound for Canada. From there, he snuck across the border into the United States, and eventually wound up here.\n\n\
Nishan tried to go legit. He called in a favor with someone he’d known in Chambarak, and got himself decent papers. He got a job, working in a convenience store on the late shift. People liked “Nicky,” and Nicky liked people. Everything was going well, life was boring and predictable and oh, so peaceful.\n\n\
Until the robbery.\n\n\
He was there with the fucking gun in his stupid, shaking hand. He was strung out, looking for a score. Nicky knew that was the end of it. A junky like that is more dangerous than a pro—hand over the cash and the pro’ll get the hell out without risking extra charges. “Never trust a junky, Nisha,” his father used to say, so Nicky took the gun away from him. Stupid junky. Now the cops would come, and they’d look too closely at his ID and Nishan would have to move on. Nicky pulled the would-be robber over the counter. He was still beating him when Anton, the store’s owner got there and pulled him off.\n\n\
The cops never came. It turned out that the store was a front, used by Anton and his associates to launder money. Anton was, as he put it, “diversifying.” And he was impressed with Nicky’s performance. Nishan was told that the robber had died from the beating. A shame, but Anton’s friends could channel Nicky’s temper to more profitable ends.\n\n\
Nicky started doing odd jobs for Anton. Nothing big, at first. Acting as a black-market gofer wasn’t what he wanted for his life in America, but got used to it. Eventually he graduated to delivering strange, locked coolers that he suspected held more than a few sodas and ice. Finally, Anton sent Nicky out to do collections. He tried to make it simple. Pay the money or get out of town, he offered, but they always strung him along. “I’ll pay you this Friday,” they’d say, but then they wouldn’t have it. They’d cajole and argue and, when that didn’t work, they’d yell at Nicky. Like he was the one who got them so far in debt to someone like his boss. Like he was hassling them, when he had tried to do them a favor. So he hurt them, like Anton wanted.\n\n\
He started to get used to that, too.\n\n\
As the pay got better, Nicky moved into Hill Manor Apartments. He pays his rent on time, and keeps anything related to work at the convenience store in a lockbox hidden in the back of the freezer. Home is supposed to be quiet, a safe haven away from the inevitable demands Anton makes on him. He wasn’t there a week before Janice started coming around, inviting him to poker games and socials. She’s a nice person, and her poker game is actually kind of fun, when he can make it.",
    /* Description */ "Nicky is a thickly built, hirsute man who stands a few inches under six feet tall. He has a perpetual five o’clock shadow even just after shaving. He looks older than he is—the life of a vagabond stray took its toll before he found his way to Hill Manor Apartments.",
    /* RP Hints    */ "You do your best to fit in. Nicky doesn’t want to be remembered as “that foreign guy.” Despite your Armenian accent, you try hard to be seen as American. Part of this is an attempt to forget your past and make a new life here in the United States, but another part of it is camouflage. You know Rachel is a cop, and the last thing you want is for her to find out about your extra-curricular activities. You don’t actually want to be a criminal, but you will always do what’s necessary to survive, and crime is where your skills lie.",
    /* Is NPC?     */ false
};

char *aspirations[] = {
    "Put a bad guy in hospital",
    "Find out what's up with Anton's guns",
    NULL
};

char *obsessions[] = {
    "The soviet space program: a metaphysical perspective",
    NULL
};

int attributes[n_attribute_types][n_categories] = {
                   /* MENTAL                    PHYSICAL                SOCIAL       */
/* POWER      */ { /* Intelligence */ 2,     /* Strength  */ 3,      /* Presence     */  2 },
/* FINESSE    */ { /* Wits         */ 3,     /* Dexterity */ 2,      /* Manipulation */  2 },
/* RESISTANCE */ { /* Resolve      */ 2,     /* Stamina   */ 3,      /* Composure    */  2 }
};

struct skill_t skills[n_categories][n_mental_skills] = {
        /*{ Category,   Name,               Specialization, Dots,   Unlock,  Asset,   Order Rote Skill  } */
    // Mental
    {   { Mental,       "Academics",        NULL,           0,      false,   false,   false  },
        { Mental,       "Computer",         NULL,           1,      false,   false,   false  },
        { Mental,       "Crafts",           NULL,           1,      false,   false,   false  },
        { Mental,       "Investigation",    "Casing",       2,      false,   false,   false  },
        { Mental,       "Medicine",         NULL,           0,      false,   false,   false  },
        { Mental,       "Occult",           NULL,           0,      false,   false,   false  },
        { Mental,       "Politics",         NULL,           0,      false,   false,   false  },
        { Mental,       "Science",          NULL,           0,      false,   false,   false  } },
    // Physical
    {   { Physical,     "Athletics",        "Escape",       2,      false,   false,   false  },
        { Physical,     "Brawl",            NULL,           2,      false,   false,   false  },
        { Physical,     "Drive",            NULL,           0,      false,   false,   false  },
        { Physical,     "Firearms",         NULL,           1,      false,   false,   false  },
        { Physical,     "Larceny",          "Lockpicking",  3,      false,   false,   false  },
        { Physical,     "Stealth",          NULL,           1,      false,   false,   false  },
        { Physical,     "Survival",         NULL,           1,      false,   false,   false  },
        { Physical,     "Weaponry",         NULL,           1,      false,   false,   false  } },
    // Social
    {   { Social,       "Animal Ken",       NULL,           0,      false,   false,   false  },
        { Social,       "Empathy",          NULL,           0,      false,   false,   false  },
        { Social,       "Expression",       NULL,           0,      false,   false,   false  },
        { Social,       "Intimidation",     NULL,           2,      false,   false,   false  },
        { Social,       "Persuasion",       NULL,           1,      false,   false,   false  },
        { Social,       "Socialize",        NULL,           0,      false,   false,   false  },
        { Social,       "Streetwise",       NULL,           2,      false,   false,   false  },
        { Social,       "Subterfuge",       NULL,           2,      false,   false,   false  } }
};

struct merit merits[] = {
    { "Language (English)",                             1 },
    { "Resources",                                      2 },
    { "Indomitable",                                    2 },
    { "Alternate Identity",                             2 },
    { "Library",                                        1 },
    { "Professional Training (Criminal)",               1 },
    { "Contacts (Black Market, Security/Locksmiths)",   2 }, // Due to prof training
    { NULL,                                             0 }
};

struct arcanum_t arcana[n_arcana] = {
    /* Name     Dots    Status      Path        Manifestation */
    { "Death",  0,      Common,     Moros,      Subtle  },
    { "Fate",   0,      Inferior,   Acanthus,   Subtle  },
    { "Forces", 0,      Common,     Obrimos,    Gross   },
    { "Life",   0,      Common,     Thyrsus,    Gross   },
    { "Matter", 0,      Common,     Moros,      Gross   },
    { "Mind",   0,      Ruling,     Mastigos,   Subtle  },
    { "Prime",  0,      Common,     Obrimos,    Subtle  },
    { "Space",  1,      Ruling,     Mastigos,   Gross   },
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
    /* Equipment                Durability  Structure   Size    Cost */
    { "1yr membership, MoRI",   1,          1,          1,      2   },
    { NULL,                     0,          0,          0,      0   }
};

struct weapon_t weapons[] = {
    /* Weapon/Attack,   Dmg,    Short,  Medium, Long,   Clip,   Init,   Str,    Size    */
    { ".38 Special",    1,         20,      40,   80,      6,      0,     2,       1 },
    { "Runed Dagger",   0,          0,       0,    0,      0,     -1,     1,       1 },
    { NULL,             0,          0,       0,    0,      0,      0,     0,       0 }
};

void advancement() {
    // Where to note experience expenditures

    // Buy a point of Prof Training (Criminal)
    ++mundane_xp_spent;

    // After witnessing strange events, Nicky feels harder than ever.
    ++attributes[Resistance][Physical];

    // Nicky Awakens
    awakened = true;
    gnosis = 1;
    wisdom = integrity;
    integrity = 0;
}
