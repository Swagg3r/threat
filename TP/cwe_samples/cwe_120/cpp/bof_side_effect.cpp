/*
** Creative Commons Attribution-ShareAlike 3.0 License -
** This work is licensed under the Creative Commons Attribution-Share Alike
** 3.0 License. To view a copy of this license,
** visit http://creativecommons.org/licenses/by-sa/3.0/legalcode;
** or, (b) send a letter to Creative Commons, 171 2nd Street, Suite 300, San
** Francisco, California, 94105, USA.
**
** Originally created : Mataru
**
** Comments : CWE-120: Buffer Copy without Checking Size of 
**	Input ('Classic Buffer Overflow'). PoC Based on non checking
**	of length of string while copying string
**	http://cwe.mitre.org/data/definitions/120.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*
** Help on how to use the prog
*/
void
_usage(const char* const sw)
{
    fprintf(stderr, "Usage: %s <password>\n\n", sw);
    fprintf(stderr, "password:\tenter you password\n");
    
    exit(1);
}

/*
** Check if the given password, match one known
*/
int32_t 
_check_creds(char *password) 
{
    int32_t     res = 0;
    char	buf[16];
    
    // Copying password from user input without checking input length
    // Withint entering something like chocolat or miaou we are able to set res none null
    strcpy(buf, password);
    
    if(strcmp(buf, "chocolat") == 0)
	{
	    res = 1;
	}

    if(strcmp(buf, "miaou") == 0)
	{
	    res = 1;
	}

    return(res);
}

int32_t
main(int argc, char *argv[]) 
{
    if(argc != 2) 
	{
	    _usage(argv[0]);
	}

    if(_check_creds(argv[1]))
	{
	    printf("=== Welcome home! ===\n");
	} 
    else
	{
	    printf("Access Denied\n");
	}

    return(0);
} 
