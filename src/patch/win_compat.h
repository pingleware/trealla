#pragma once
#include <stdio.h>
#include <sys/stat.h>

/* Windows-safe replacements for POSIX-only functions */

#ifdef _WIN32

/* fseeko / ftello replacements */
#define fseeko _fseeki64
#define ftello _ftelli64

/* S_ISxxx macros */
#ifndef S_ISDIR
#define S_ISDIR(m)  (((m) & S_IFMT) == S_IFDIR)
#endif

#ifndef S_ISREG
#define S_ISREG(m)  (((m) & S_IFMT) == S_IFREG)
#endif

#ifndef S_ISFIFO
#define S_ISFIFO(m)  (((m) & S_IFMT) == S_IFIFO)
#endif

#ifndef S_IFIFO
#define S_IFIFO 0x1000   /* FIFO special file */
#endif


/* History functions (no-op in embedded mode) */
static inline void write_history(const char *path) { (void)path; }
static inline void clear_history(void) {}

#endif /* _WIN32 */
