#ifndef _SIGNAL_H
#define _SIGNAL_H
typedef void (*sighandler_t)(int);
extern sighandler_t signal(int signum, sighandler_t handler);
#define SIG_DFL ((sighandler_t)0)
#define SIG_ERR ((sighandler_t)((void*)signal+1))
#define SIG_HOLD ((sighandler_t)((void*)signal+2))
#define SIG_IGN ((sighandler_t)((void*)signal+3))
volatile signed char sig_atomic_t;
typedef int sigset_t;
extern int raise(int sig);
#endif
