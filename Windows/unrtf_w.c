#include "config.h"

#ifdef _WIN32
/*-
* Copyright (c) 1990, 1993
*	The Regents of the University of California.  All rights reserved.
*
* The quadratic code is derived from software contributed to Berkeley by
* Chris Torek.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
* 4. Neither the name of the University nor the names of its contributors
*    may be used to endorse or promote products derived from this software
*    without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
* SUCH DAMAGE.
*/

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "safeunistd.h"

/*
* Find the first occurrence of find in s, ignore case.
*/
char *strcasestr(const char *s, const char *find)
{
	/* Less code size, but quadratic performance in the worst case.  */
	char c, sc;
	size_t len;

	if ((c = *find++) != 0) {
		c = tolower((unsigned char)c);
		len = strlen(find);
		do {
			do {
				if ((sc = *s++) == 0)
					return (NULL);
			} while ((char)tolower((unsigned char)sc) != c);
		} while (strncasecmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}



unsigned int unrtf_ntohl(unsigned int in)
{
	const unsigned char *f = (const unsigned char*)&in;
	return(
		((unsigned int)(f[3])) +
		((unsigned int)(f[2]) << 8) +
		((unsigned int)(f[1]) << 16) +
		((unsigned int)(f[0]) << 24));
}

#endif

#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

const char *path_thisexecpath()
{
#ifdef UNICODE
Error: Need to add UNICODE code here
#else
	static TCHAR text[MAX_PATH];
    if (text[0] == 0) {
        GetModuleFileName(NULL, text, MAX_PATH);
#ifdef NTDDI_WIN8_future
        PathCchRemoveFileSpec(text, MAX_PATH);
#else
        PathRemoveFileSpec(text);
#endif
    }
    return (const char *)text;
#endif
}

/* Location for program data: charmaps etc. The Unix code does not
 * work because it uses : as a path separator. Improvise, trying to
 * make things work in different configurations, installed or
 * uninstalled. The following are tried relative to the exec location */
static const char *completions[] = {
    "\\Share\\",
    "\\..\\share\\unrtf\\",
    "\\..\\outputs\\"
};
static const int ncomp = sizeof(completions) / sizeof(char*);
const char *unrtfDataDir()
{
    static char buffer[MAX_PATH+10];
    char path[MAX_PATH+40];
    if (buffer[0] == 0) {
        int i;
        const char *execdir = path_thisexecpath();
        for (i = 0; i < ncomp; i++) {
            if (strlen(execdir) + strlen(completions[i]) + 2 < MAX_PATH) {
                snprintf(buffer, MAX_PATH+10, "%s%s", execdir, completions[i]);
                snprintf(path, MAX_PATH+40, "%s%s", buffer, "html.conf");
                if (access(path, R_OK) == 0) {
                    break;
                }
            }
        }
    }
    /* fprintf(stderr, "unrtfDataDir: returning: [%s]\n", buffer);*/
    return buffer;
}
