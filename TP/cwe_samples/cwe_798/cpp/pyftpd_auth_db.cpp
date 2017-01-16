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
** Comments : CWE-798 Use of Hard-coded Credentials, based on CVE-2010-2073.
**	cwe: http://cwe.mitre.org/data/definitions/798.html
**	cve: http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2010-2073
**	where a file "auth_db_config.py" handle encoded credentials that anyone could use to
**	logon on pyftpd server.
** 
** All versions of pyFTPd are vulnerable.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<openssl/md5.h>

static const char*	adm_name	= "root";
static const char*	adm_pwd		= "7ecc19e1a0be36ba2c6f05d06b5d3058";

static char*
_print_sum(unsigned char* md)
{
    uint32_t	i;
    char* buf;

    buf = (char*)malloc(33 * sizeof(char));

    for(i = 0; i < 16; ++i)
	{
	    sprintf(buf+i*2, "%02x", md[i]);
	}

    buf[33] = '\0';

    return(buf);
}

/*
** Check both if given username match expected one.
** Also check if given password once it has been hashed with a very secure
** algorithm MD5 (don't use this) match adm_pwd
**
** :param username: user input username
** :param password: user input password
*/ 
static bool 
_check_creds(const char* const username, const char* const password)
{
    int8_t		res;
    bool		ret;
    unsigned char	sec_pwd[16];
    MD5_CTX		ctx;
    char*		sec_pwd_hex;

    // Compute the MD5 of user input password either binary and digest one
    MD5_Init(&ctx);
    MD5_Update(&ctx, password, 4);
    MD5_Final(sec_pwd, &ctx);
    sec_pwd_hex = _print_sum(sec_pwd);

    // check of the md5(password) == adm_pwd & username == adm_name
    res = memcmp(adm_pwd, sec_pwd_hex, 32);

    if(strcmp(adm_name, username) == 0)
	{
	    ret = true;
	}
    else
	{
	    ret = false;
	}

    if(res == 0)
	{
	    return(true & ret);
	}
    else
	{
	    return(false);
	}
}

int
main(int argc, char** argv)
{
    bool	res;

    if(argc != 3)
	{
	    fprintf(stderr, "Usage: %s <username> <password>\n", argv[0]);
	    exit(1);
	}

    res = _check_creds(argv[1], argv[2]);

    if(res)
	{
	    printf("Access granted\n");
	}
    else
	{
	    printf("Access denied\n");
	}

    return(0);
}
