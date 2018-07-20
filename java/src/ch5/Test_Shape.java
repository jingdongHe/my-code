package ch5;
/*建立另一个抽象类Shape，其中包含一个抽象方法draw()；
建立两个子类J_Circle和J_Square，继承Shape,分别实现Shape中的抽象方法draw()
建立Test_Shape类，创建一个J_Square类的对象sqare，
再创建一个Shape关于J_Circle的引用对象circle；
通过circle对象调用方法draw(),观察如何实现Shape类的多态性。*/
abstract class Shape {
	abstract public void draw();
}
class J_Circle extends Shape{
	public void draw()
	{
		System.out.println("circle");
	}
}
class J_Square extends Shape{
	public void draw()
	{
		System.out.println("square");
	}
}
public class Test_Shape {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		J_Square square=new J_Square();
		square.draw();
		
		Shape circle=new  J_Circle();
		circle.draw();

	}

}
