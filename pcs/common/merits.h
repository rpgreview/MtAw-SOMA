#pragma once

struct merit {
    char *name;
    int dots;
};

extern struct merit merits[];
extern char *merit_fmt;

void print_merits();
