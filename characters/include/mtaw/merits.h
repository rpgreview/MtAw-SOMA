#pragma once

struct merit {
    char *name;
    int dots;
};

extern struct merit merits[];

int trained_observer();
void print_merits();
