package ch7;

public class Hello_java {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String a,b;
		a=new String("Hello java");
		//b=new String("Hello java");
		b=a;
		
		if(a==b)
			System.out.println("YES");
		else
			System.out.println("NO");
		if(a.equals(b))
			System.out.println("YES");
		else
			System.out.println("NO");

	}

}
