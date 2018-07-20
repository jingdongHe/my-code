package ch2;

import java.util.Scanner;

public class t2_cal {

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a,b,d;
		char c;
		String S;
		Scanner in=new Scanner(System.in);
		S=in.next();d=0;a=0;b=0;c=0;
		char []s=S.toCharArray();
		for(int i=0;i<S.length();i++)
		{
			if(d==0&s[i]>='0'&s[i]<='9')
				a=a*10+s[i]-'0';
			else if(d==1&s[i]>='0'&s[i]<='9')
				b=b*10+s[i]-'0';
			else
				{c=s[i];d=1;}
		}
		switch(c)
		{
		case '+':System.out.println(a+b);break;
		case '-':System.out.println(a-b);break;
		case '*':System.out.println(a*b);break;
		case '/':System.out.println(a*1.0/b);break;
		}
	}

}
