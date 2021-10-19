#pragma once
#include <stdbool.h>
#include <mtaw/skills.h>

enum paths {
    Acanthus,
    Mastigos,
    Moros,
    Obrimos,
    Thyrsus,
    n_paths
};

enum manifestations {
    Gross,
    Subtle,
    n_manifestations
};

enum arcana {
    Death,
    Fate,
    Forces,
    Life,
    Matter,
    Mind,
    Prime,
    Space,
    Spirit,
    Time,
    n_arcana
};

enum arcanum_status {
    Inferior,
    Common,
    Ruling,
    n_arcanum_statuses
};

static char *arcanum_status_names[3] = {
    "Inferior",
    "Common",
    "Ruling"
};

struct arcanum_t {
    char *name;
    int dots;
    enum arcanum_status status;
    enum paths path;
    enum manifestations manifestation;
};

struct praxis_t {
    char *name;
    bool gnosis_freebie;
};

struct rote_t {
    struct arcanum_t *arcanum;
    int level;
    char *spell;
    struct skill_t *rote_skill;
};

static char *ritual_interval[11] = {
    "N/A",
    "3 Hours",
    "3 Hours",
    "1 Hour",
    "1 Hour",
    "30 Minutes",
    "30 Minutes",
    "10 Minutes",
    "10 Minutes",
    "1 Minute",
    "1 Minute"
};

static int max_mana[11] = {
    0,
    10,
    11,
    12,
    13,
    15,
    20,
    25,
    30,
    50,
    75
};

static int mana_per_turn[11] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    10,
    15
};

extern bool awakened;
extern int gnosis;
extern int wisdom;
extern char *obsessions[];
extern struct arcanum_t arcana[n_arcana];
extern struct praxis_t praxes[];
extern struct rote_t rotes[];
extern char *ritual_interval[];
extern int max_mana[];

extern int arcane_xp;
extern int arcane_xp_spent;

int expected_obsessions(const int g);
void print_gnosis_summary();
void print_arcana();
void print_rotes();
void print_praxes();
