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
** Comments : Basic exploit of format string by putting input data
**	on the stack
**	http://julianor.tripod.com/bc/NN-formats.txt
**	By using an uncontrolled format string we will write, from command line
**	argument, a value into miaou
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

#define	BUF_SIZE	1024

int
main(int argc, char** argv)
{
    int32_t	miaou;
    char	buf[BUF_SIZE];

    miaou = 1;

    if(argc != 2)
	{
	    fprintf(stderr, "Usage: %s <str>\n", argv[0]);
	    exit(1);
	}

    printf("Before formating: miaou: [%p] = %d\n", &miaou, miaou);

//    strncpy(buf, argv[1], sizeof(buf));
    // There a user is able to read/write the stack, for example the canary "miaou"
    printf(argv[1]);
    printf("\n");

    printf("After formating: miaou: [%p] = %d\n", &miaou, miaou);

    return(0);
}

/*

./format_string '12345%n%x'
after miaou = 5

*/