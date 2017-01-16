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
** Comments : CWE 190 - Integer Overflow or Wraparound applied in order to 
**	lead to undefined loop.
*/
public class bof_loop
{
    public static void main(String[] argv)
    {
	short	i;
	int	iter_c;

	// usage
	if(argv.length != 1)
	{
	    System.err.println("Usage: bof_loop <iteration>\n");
	    System.err.println("Run a loop with given number of iterations\n");
	    System.err.println("iteration:\tNumber of iteration of the loop\n");

	    System.exit(1);
	}

	// string (user input) to int
	iter_c = Integer.parseInt(argv[0]);

	/*
	** Loop until our short i equals the value given
	** As iter_c belongs to [-2**31; (2**31) -1]
	** and i belongs to [-2**15; (2**15) - 1]
	** By setting iter_c to the right value you can make this program run
	** in an endless loop
	*/
	for(i = 0; i < iter_c; ++i)
	{
	    // do nothing
	    continue;
	}
    }
}
