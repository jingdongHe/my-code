package ch7;

import java.awt.Color;

/*����һ�����ࡰ������Car,�ڸ���������carColor, carName; �з���start()��stop();
�ٴ���һ�����ࡰ��������FireCar����ֻ��һ����𷽷�putOutfire()��
���ڲ�����TestCar�����е��������зֱ𴴽������Ķ������������Ķ���
�鿴�������Ƿ���Ե���start��stop����,�����Ƿ���Ե���putOutfire()����?Ϊʲô��*/
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
