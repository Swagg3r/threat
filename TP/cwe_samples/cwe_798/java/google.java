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
**	username/password. The vulnerable code is hold in the class "scada".
**	Looking for vulnerabilities HERE is a waste of time.
**
**	This module just emulate what Google can do for you, when you are 
**	looking for credentials... ;)
**	http://cwe.mitre.org/data/definitions/798.html
*/
public class google
{
    /*
    ** This class emulate the Internet, especially a well known search engine.
    ** What you want is to retrieve credentials to get into a SCADA system.
    ** By looking on google, and using google dorks one could gather a lot of funky
    ** information!
    */
    public static void main(String[] argv)
    {
	String	query;

	// Usage
	if(argv.length != 1)
	{
	    System.err.println("Usage: google <query>\n");
	    System.err.println("Ask you question to Google ;)\n");
	    System.err.println("query:\tThe question\n");

	    System.exit(1);
	}

	/*
	** Credentials are given only if the user ask for it. Google also return 
	** an example of google dorks (more or less random in this case)
	*/
	if(argv[0].equals("credential"))
	{
	    System.out.println("query \"intext:password or intext:scada " +
			       "filetype:txt\" returns root:AdminIsTheNewRoot");
	}
	else
	{
	    System.out.println("Mioumiou");
	}
    }
}
