#include "signal.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>

static BOOL WINAPI win_sig_handler(DWORD ctrl_type) {
    if (ctrl_type == CTRL_C_EVENT) {
        g_sigfn(SIGINT);
        return TRUE;
    }
    return FALSE;
}

void trealla_init_signals(void) {
    SetConsoleCtrlHandler(win_sig_handler, TRUE);
}

#else
#include <signal.h>

static void posix_sig_handler(int sig) {
    g_sigfn(sig);
}

void trealla_init_signals(void) {
    signal(SIGINT, posix_sig_handler);
}

#endif

// Trealla expects this function to exist.
void g_sigfn(int sig) {
    fprintf(stderr, "\n[trealla] Interrupt (SIGINT)\n");
}
