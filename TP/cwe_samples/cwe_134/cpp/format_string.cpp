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
** Comments : CWE-134: Uncontrolled Format String.
**	http://cwe.mitre.org/data/definitions/134.html
**	Rewrite the addr of a function pointer
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define	BUF_SIZE	1024

void
_restricted_area(void)
{
    printf("Secret place, you should not be there\n");
}

void
_public_area(void)
{
    printf("Hi folk welcome to Canada\n");
}

int
main(int argc, char** argv)
{
    void	(*fct_jmp)(void);
    char	buf[BUF_SIZE];
    fct_jmp = _public_area;

    if(argc != 2)
	{
	    fprintf(stderr, "Usage: %s <str>\n", argv[0]);
	    exit(1);
	}

    strncpy(buf, argv[1], sizeof(buf));

    // This format should be use to write onto fct_jump the addr of _restricted_area
    printf(argv[1]);
    printf("\n");

    (*fct_jmp)();
    
    return(0);
}
