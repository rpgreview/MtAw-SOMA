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

struct rote_t {
    struct arcanum_t *arcanum;
    int level;
    char *spell;
    struct skill_t *rote_skill;
};

extern bool awakened;
extern int gnosis;
extern int wisdom;
extern char *obsessions[];
extern struct arcanum_t arcana[n_arcana];
extern struct rote_t rotes[];
extern char *praxes[];

extern int arcane_xp;
extern int arcane_xp_spent;

void print_arcana();
void print_rotes();
void print_praxes();
