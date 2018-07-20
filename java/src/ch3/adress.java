package ch3;

import java.util.Scanner;

class AdressBook{
	private String name,adres,phone;
	
	
	public void setName(String name)
	{
		this.name=name;
	}
	public void setAdress(String adres)
	{
		this.adres=adres;
	}
	public void setPhone(String phone)
	{
		this.phone=phone;
	}
	
	
	public String getName()
	{
		return name;
	}
	public String getAdress()
	{
		return adres;
	}
	public String getPhone()
	{
		return phone;
	}
	
	public void getAllInfo()
	{
		System.out.println("Please entry the info");
		String name,adres,phone;
		Scanner in= new Scanner(System.in);
		name=in.next();
		adres=in.next();
		phone=in.next();
		
		setName(name);
		setAdress(adres);
		setPhone(phone);
		
		System.out.println(getName()+" "+getAdress()+" "+getPhone());
	}
}
public class adress {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		AdressBook a=new AdressBook();
		a.getAllInfo();
	}

}
