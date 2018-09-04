/*
 * Constable: constable.h
 * (c)2002 by Marek Zelem <marek@terminus.sk>
 * $Id: constable.h,v 1.3 2002/10/23 10:25:43 marek Exp $
 */

#ifndef _CONSTABLE_H
#define _CONSTABLE_H

#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "types.h"
#include "language/error.h"

//#define MAX(a,b)	((a)>(b)?(a):(b))
//#define MIN(a,b)	((a)<(b)?(a):(b))

// These functions and file descriptor are set in the main() function in init.c
// debug output function when -D is used
extern void(*debug_def_out)( int arg, char *str );
extern pthread_mutex_t debug_def_lock;
extern int debug_def_arg; // file descriptor for debug output
// debug output function when -DD is used
extern void(*debug_do_out)( int arg, char *str );
extern pthread_mutex_t debug_do_lock;
extern int debug_do_arg; // file descriptor for debug output

int medusa_printlog(char *format, ...);

char *retprintf( const char *fmt, ... );
int init_error( const char *fmt, ... );
#ifdef DEBUG_TRACE
extern char runtime_file[64];
extern char runtime_pos[12];
#endif
int runtime( const char *fmt, ... );
int fatal( const char *fmt, ... );

#endif /* _CONSTABLE_H */
