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
** Comments : This PoC take from the CVE-2007-1365 where an IPv6 packet can lead
**	to BoF into OpenBSD kernel
**	cwe: http://cwe.mitre.org/data/definitions/120.html
**	cve: http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2007-1365
**	Vulnerable kernel: OpenBSD 3.9 and 4.0
*/
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>

struct m_buf
{
    char	buf[100];
    void	(*ext_free)(void*);
};

/*
** This is a function, let say anywhere in the kernel, we want to execute
*/
void
_got_root(void)
{
    printf("Wootwoot, you are now root!\n");
}

/*
** Init a m_buf struct, fill it with the data from user input and return it
*/
struct m_buf*
init_m_buf(const char* const data)
{
    struct m_buf* m;

    m = (struct m_buf*)malloc(sizeof(struct m_buf));
    assert(m != NULL);    
    
    // unchecked copy
    // There we need to write the addresse of "_got_root" into m->ext_free
    strcpy(m->buf, data);

    return(m);
}

/*
** This process the data inside buffer, a print is fine
*/
void
process_m_buf(struct m_buf* m)
{
    printf("%s\n", m->buf);
}

/*
** Free the allocated buffer either by using the libc/free or your...
*/
void 
free_m_buf(struct m_buf* m)
{
    if(m->ext_free)
	{
	    (*(m->ext_free))(m);
	}
    else
	{
	    free(m);
	}
}

/*
** help message
*/
void
_usage(const char* const prog)
{
    printf("Usage: %s <password>\n", prog);
    exit(0);
}

int32_t
main(int32_t argc, char** argv)
{
    struct m_buf* m;

    if(argc != 2)
	{
	    _usage(argv[0]);
	}

    m = init_m_buf(argv[1]);

    process_m_buf(m);

    free_m_buf(m);
    
    return(0);
}
