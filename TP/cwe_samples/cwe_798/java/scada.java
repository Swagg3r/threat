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
**	username/password. By properly ask the "Internet" you could retrieve
**	relevant information in order to get into some SCADA systems.
**
**	http://cwe.mitre.org/data/definitions/798.html
*/
public class scada
{
    /*
    ** You should get into the system by gather username/password.
    ** Note: Imagine this is a black box binary, that you cannot touch. 
    **	You could ask google...
    */
    public static void main(String[] argv)
    {
	final String EXP_USERNAME	= "root";
	final String EXP_PASSWORD	= "AdminIsTheNewRoot";
	
	boolean res;
	
	if(argv.length != 2)
	{
	    System.err.println("Usage: scada <username> <password>\n");
	    System.err.println("Authenticate yourself before mastering SCADA devices\n");
	    System.err.println("username:\tThe username of an administrator account\n");
	    System.err.println("password:\tPassword of an administrator account\n");

	    System.exit(1);
	}

	// Just check user input 
	if(argv[0].equals(EXP_USERNAME))
	{
	    res = true;
	}
	else
	{
	    res = false;
	}

	if(argv[1].equals(EXP_PASSWORD))
	{
	    res = res & true;
	}
	else
	{
	    res = res & false;
	}

	if(res)
	{
	    System.out.println("Welcome home bro!");
	}
	else
	{
	    System.err.println("Access denied.");
	}
    }
}
