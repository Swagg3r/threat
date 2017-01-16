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
** Comments : This is an example of CWE-131: Incorrect calculation of buffer size,
**	see http://cwe.mitre.org/data/definitions/131.html
*/
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int
main(int argc, char** argv)
{
    int		len;
    char*	str;

    if(argc != 2)
	{
	    fprintf(stderr, "Usage: %s <len>\n", argv[0]);
	    exit(1);
	}

    len = atoi(argv[1]);
    len++; // handle null char to terminate string

    str = malloc(len);
    assert(str != NULL);

    printf("Congratz you have ask for a buffer of %d bytes\n", len);

    return(0);
}

/*
La valeur de len n'est pas vérifié et peut etre négative.
./trick_malloc -1
buffer of 0 bytes

*/