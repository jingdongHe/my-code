package ch5;
/*测试接口的用法：
创建一个Vehicle接口，在接口中定义2个抽象方法：启动start()和刹车stop()。
定义两个类Car和Bike，实现Vehicle接口,并具体实现接口start()和stop()方法 。
创建另一个类Test_Vehicle，在main主方法中分别通过
使用Vehicle接口创建关于Car 与Bike类的引用对象audi与yongjiu。
使用接口Vehicle的两个引用对象分别调用各自的启动start()与刹车stop()，显示不同运输工具的多态性。
*/
interface Vehicle {
	abstract void start();
	abstract void stop();
}

class Car implements Vehicle{
	public void start()
	{
		System.out.println("start");
	}
	public void stop()
	{
		System.out.println("stop");
	}
}

class Bike implements Vehicle{
	public void start()
	{
		System.out.println("start");
	}
	public void stop()
	{
		System.out.println("stop");
	}

}
public class Test_Vehicle {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Car c=new Car();
		c.start();
		c.stop();
		
		Bike b=new Bike();
		b.start();
		b.stop();
	}

}
