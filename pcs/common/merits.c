#include <stdio.h>
#include <stdlib.h>
#include "common/utils.h"
#include "common/merits.h"

void print_merits() {
    for(int m = 0; merits[m].name != NULL; ++m) {
        char *dot_str = dots(merits[m].dots, 5);
        printf(merit_fmt, merits[m].name, dot_str);
        free(dot_str);
    }
}
