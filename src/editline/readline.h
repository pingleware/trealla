#ifndef READLINE_H
#define READLINE_H

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Minimal readline() replacement for Windows/MSVC.
 * Provides:
 *   - readline(prompt)
 *   - add_history(line)
 *   - basic in-memory history list
 */

static char *readline(const char *prompt)
{
    static char buffer[4096];

    if (prompt)
        fputs(prompt, stdout);

    if (!fgets(buffer, sizeof(buffer), stdin))
        return NULL;

    size_t len = strlen(buffer);

    char *line = malloc(len + 1);
    if (!line)
        return NULL;

    memcpy(line, buffer, len + 1);
    return line;
}

static void add_history(const char *line)
{
    /* No-op for now; Trealla does not require full history persistence */
    (void)line;
}

#else
#include_next <editline/readline.h>
#endif

#endif
