package ch5;
/*���Խӿڵ��÷���
����һ��Vehicle�ӿڣ��ڽӿ��ж���2�����󷽷�������start()��ɲ��stop()��
����������Car��Bike��ʵ��Vehicle�ӿ�,������ʵ�ֽӿ�start()��stop()���� ��
������һ����Test_Vehicle����main�������зֱ�ͨ��
ʹ��Vehicle�ӿڴ�������Car ��Bike������ö���audi��yongjiu��
ʹ�ýӿ�Vehicle���������ö���ֱ���ø��Ե�����start()��ɲ��stop()����ʾ��ͬ���乤�ߵĶ�̬�ԡ�
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
