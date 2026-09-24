#ifndef HISTEDIT_H
#define HISTEDIT_H

#ifdef _WIN32

#include <stdio.h>

typedef struct EditLine EditLine;
typedef struct History History;

typedef struct {
    int dummy;
} HistEvent;

/* Minimal stubs to satisfy Trealla’s usage */
static inline EditLine *el_init(const char *prog, FILE *fin, FILE *fout, FILE *ferr) {
    return NULL;
}

static inline void el_end(EditLine *e) {
    (void)e;
}

static inline void el_set(EditLine *e, int op, ...) {
    (void)e; (void)op;
}

static inline const char *el_gets(EditLine *e, int *count) {
    static char buffer[4096];
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        *count = 0;
        return NULL;
    }
    *count = (int)strlen(buffer);
    return buffer;
}

static inline int history_init(History *h, void *ptr) {
    (void)h; (void)ptr;
    return 0;
}

static inline int history_end(History *h) {
    (void)h;
    return 0;
}

static inline int history(History *h, HistEvent *ev, int op, ...) {
    (void)h; (void)ev; (void)op;
    return 0;
}

#else
/* On non-Windows, use real histedit.h */
#include_next <histedit.h>
#endif

#endif
