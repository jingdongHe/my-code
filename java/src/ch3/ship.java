package ch3;

import java.util.Scanner;

class Rect{
	int height,width;
	public Rect(int height,int width)
	{
		this.height=height;
		this.width=width;
	}
	public int s()
	{
		return height*width;
	}
	public int per()
	{
		return (height+width)*2;
	}
}
class Circle {
	double r;
	public Circle(double r)
	{
		this.r=r;
	}
	public double s()
	{
		return r*r*Math.PI;
	}
	public double per()
	{
		return 2*Math.PI*r;
	}
}
public class ship {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in= new Scanner(System.in);
		int a,b;double c;
		
		a=in.nextInt();
		b=in.nextInt();
		Rect r=new Rect(a,b);
		System.out.println(r.s()+" "+r.per());
		c=in.nextDouble();
		Circle C=new Circle(2.3);
		System.out.println(C.s()+" "+C.per());
	}

}
