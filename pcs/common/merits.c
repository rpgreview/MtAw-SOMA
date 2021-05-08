#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common/utils.h"
#include "common/merits.h"

void print_merits() {
    int max_merits_name_len = 0;
    for(int m = 0; merits[m].name != NULL; ++m) {
        max_merits_name_len = max(max_merits_name_len, strnlen(merits[m].name, 256));
    }
    printf("```\n");
    for(int m = 0; merits[m].name != NULL; ++m) {
        char *dot_str = dots(merits[m].dots, 5);
        printf("%-*s %s\n", max_merits_name_len, merits[m].name, dot_str);
        free(dot_str);
    }
    printf("```\n");
}
