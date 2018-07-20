package ch5;

class J_Employee {
	public int m_workYear;
	
	public J_Employee()
	{
		m_workYear=1;
	}
}
class J_people {
	public String name;
	public J_people(String name)
	{
		this.name=name;
	}
}
class J_Student extends J_people{
	public int age;
	public J_Student(String name)
	{
		super(name);
		age=10;
	}
	public void mb_printInfo()
	{
		System.out.println("名字"+name);
		System.out.println("年龄"+age);
	}
}
public class J_Teacher extends J_people{

	public int m_classHour;
	public J_Teacher(String name)
	{
		super(name);
		m_classHour=96;
	}
	public void mb_printInfo()
	{
		System.out.println("名字"+name);
		System.out.println("课时"+m_classHour);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		J_Teacher tom=new J_Teacher("tom");
		tom.mb_printInfo();
		J_Student bill=new J_Student("bill");
		bill.mb_printInfo();

	}

}
