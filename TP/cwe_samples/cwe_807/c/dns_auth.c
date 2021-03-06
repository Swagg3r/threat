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
** Comments : CWE-807 - Reliance on Untrusted Inputs in a Security Decision.
**	http://cwe.mitre.org/data/definitions/807.html
**	We will use a DNS query to identify a node in the network from being 
**	part of a trusted network or not. This is a flaw as we could easily
**	craft malicious response.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define UNTRUSTED_FQDN	0
#define	TRUSTED_FQDN	1

const char* const	TRUSTED_DN	= "secure.nsa.gov";

/*
** Prints an help and resumes
*/
static void
_usage(const char* const prog)
{
    fprintf(stderr, "Usage: %s <fqdn>\n\n", prog);
    fprintf(stderr, "fqdn:\t Fully Qualified Domain Name: Your FQDN\n");

    exit(1);
}

static int32_t
_is_trusted_fqdn(const char* const fqdn)
{
    size_t	trust_len;
    size_t	fqdn_len;
    size_t	off;

    trust_len = strlen(TRUSTED_DN);
    fqdn_len = strlen(fqdn);

    if(fqdn_len <= trust_len)
	{
	    return(UNTRUSTED_FQDN);
	}

    // how many char we need to jump in the fqdn str
    off = fqdn_len - trust_len;

    if(off == 0)
	{
	    fprintf(stderr, "Enter a valid FQDN\n");
	    exit(2);
	}

    if(strcmp(TRUSTED_DN, fqdn + off) == 0)
	{
	    return(TRUSTED_FQDN);
	}
    else
	{
	    return(UNTRUSTED_FQDN);
	}
}

int
main(int argc, char** argv)
{
    int32_t	res;

    if(argc != 2)
	{
	    _usage(argv[0]);
	}

    res = _is_trusted_fqdn(argv[1]);

    if(res == TRUSTED_FQDN)
	{
	    printf("Welcome to the NSA datacenter\n");
	}
    else
	{
	    printf("Whistelblower, out!\n");
	}
    
    return(0);
}
