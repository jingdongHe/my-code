package asia.china.guangdong;
import asia.china.Employee;

public class Techer extends Employee{
	private int workYears;
	private String jobTitle;
	public Techer()
	{
		workYears=2;
		jobTitle="professer";
		new Employee();
	}
	public void getter()
	{
		super.getter();
		System.out.println("workyears is "+workYears);
		System.out.println("jobtitle is "+jobTitle);
	}

}