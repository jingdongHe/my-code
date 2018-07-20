package ch7;

import java.awt.Color;

/*创建一个父类“汽车”Car,在父类中有域carColor, carName; 有方法start()与stop();
再创建一个子类“消防车”FireCar其中只有一个灭火方法putOutfire()；
请在测试类TestCar程序中的主方法中分别创建汽车的对象与消防车的对象，
查看消防车是否可以调用start与stop方法,汽车是否可以调用putOutfire()方法?为什么？*/
class Car {
	Color carColor;
	String carName;
	public void start()
	{
		System.out.println("start");
	}
	public void stop()
	{
		System.out.println("stop");
	}
}
class FireCar extends Car{
	public void putOutFire()
	{
		System.out.println("put out fire");
	}
}
public class TestCar {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Car c=new Car();
		FireCar f=new FireCar();
		
		f.start();
		f.stop();
		//c.putOutFire();

	}

}
