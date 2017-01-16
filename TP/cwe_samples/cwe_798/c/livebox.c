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
** Comments : CWE-798 - Use of Hard-coded Credentials based on hardcoded
**	username/password
**	http://cwe.mitre.org/data/definitions/798.html
**
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Top Secret/Orange Only/INT
static const char*	adm_name	= "admin";
static const char*	adm_pwd		= "admin";

static int8_t
_check_creds(const char* const username, const char* const password)
{
    int8_t	res;

    res = 0;

    // We are just checking if both username and password match expected one without leading to timing attack
    if(strcmp(adm_name, username) == 0)
	{
	    res = 1;
	}
    else
	{
	    res = 0;
	}
    
    if(strcmp(adm_pwd, password) == 0)
	{
	    res = res & 1;
	}
    else
	{
	    res = 0;
	}

    return(res);    
}

int
main(int argc, char** argv)
{
    int8_t	res;

    if(argc != 3)
	{
	    fprintf(stderr, "Usage: %s <username> <password>\n\n", argv[0]);
	    fprintf(stderr, "username:\tyour username\n");
	    fprintf(stderr, "password:\tpassword associated with you username\n");
	    exit(1);
	}

    res = _check_creds(argv[1], argv[2]);

    if(res)
	{
	    printf("Access granted %s\n", argv[1]);
	}
    else
	{
	    printf("Access denied: username/password unknwon\n");
	}

    return(0);
}
