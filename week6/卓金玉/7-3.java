import java.util.*;
import java.util.regex.Pattern;
import java.util.regex.Matcher;
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String regex = "[a-zA-Z]+";
		String s = in.nextLine();
		String ps=in.nextLine();
		ps=ps.toLowerCase();
		int cnt=0;
		Pattern pattern;
		Matcher matcher;
		pattern=Pattern.compile(regex);
		matcher=pattern.matcher(s);
		
		while(matcher.find())
		{
	         String str = matcher.group().toLowerCase(); 
	         if(str.contains(ps))
	         {
	        	 cnt++;
	         }
	    }
		System.out.print(cnt);
	}
}