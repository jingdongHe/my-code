package ch5;
/*������һ��������Shape�����а���һ�����󷽷�draw()��
������������J_Circle��J_Square���̳�Shape,�ֱ�ʵ��Shape�еĳ��󷽷�draw()
����Test_Shape�࣬����һ��J_Square��Ķ���sqare��
�ٴ���һ��Shape����J_Circle�����ö���circle��
ͨ��circle������÷���draw(),�۲����ʵ��Shape��Ķ�̬�ԡ�*/
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
