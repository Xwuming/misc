#ifndef __XDEBUG_H
#define __XDEBUG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <execinfo.h>
#include <string.h>


//#define PRINT_COMEINTO redisLog(REDIS_WARNING, "MY_DEBUG Come into == %s:%d:%s == ", __FILE__, __LINE__, __FUNCTION__);

inline void current_stack(char *buf, int len)
{
	memset(buf, 0, len);
 
	int write_len, left_len;
	char *write_ptr;

	write_ptr = buf;
	write_len = 0;
	left_len = len;

	if (left_len > 0) {
		write_len = snprintf(write_ptr, left_len, "%s", "-------print stack------- \n");
		write_ptr += write_len;
		left_len -= write_len;
	}

    char **strings; 
    void *buffer[100]; 
    int j, nptrs; 
    nptrs = backtrace(buffer, 100); 

	if (left_len > 0) {
		write_len = snprintf(write_ptr, left_len, "backtrace() returned %d addresses \n", nptrs);
		write_ptr += write_len;
		left_len -= write_len;
	}

    strings = backtrace_symbols(buffer, nptrs); 
    if (strings == NULL) { 
        if (left_len > 0) {
			write_len = snprintf(write_ptr, left_len, "backtrace_symbols return NULL \n");
			write_ptr += write_len;
			left_len -= write_len;
		}
		return;
    } 
    for (j = 0; j < nptrs; j++) {
        if (left_len > 0) {
			write_len = snprintf(write_ptr, left_len, "==%s== \n", strings[j]);
			write_ptr += write_len;
			left_len -= write_len;
		}
	}
    free(strings); 
}

#endif

