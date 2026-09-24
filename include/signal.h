#ifndef TREALLA_SIGNAL_H
#define TREALLA_SIGNAL_H

#ifdef _WIN32
#include <windows.h>
#define SIGINT 2
#else
#include <signal.h>
#endif

// Trealla expects g_sigfn to be a FUNCTION, not a pointer.
void g_sigfn(int sig);

void trealla_init_signals(void);

#endif
