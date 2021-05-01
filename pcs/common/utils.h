#pragma once

// https://stackoverflow.com/a/3437484
#define max(a,b) ({                 \
        __typeof__ (a) _a = (a);    \
        __typeof__ (b) _b = (b);    \
        _a > _b ? _a : _b;          \
    })
#define min(a,b) ({                 \
        __typeof__ (a) _a = (a);    \
        __typeof__ (b) _b = (b);    \
        _a < _b ? _a : _b;          \
    })


enum category {
    Mental,
    Physical,
    Social,
    n_categories
};

char *dots(int ndots, int max_dots);
void print_category_name(enum category c);
void advancement();
