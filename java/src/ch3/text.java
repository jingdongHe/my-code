package ch3;

import java.util.Scanner;

public class text {
	private String name,adress,phone;
	
	public void setName(String name)
	{
		this.name=name;
	}
	public void setAdress(String adress)
	{
		this.adress=adress;
	}
	public void setPhone(String phone)
	{
		this.phone=phone;
	}
	
	void getInfor()
	{
		System.out.println("name :"+name+" adress"+adress+" phone"+phone);
	}

	void setTel(String phone)
	{
		this.phone=phone;
	}
	void getTel()
	{
		System.out.println(phone);
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		text zhangsan_text=new text();
		Scanner in=new Scanner(System.in);
		String s;
		
		s=in.next();
		zhangsan_text.setName(s);
		s=in.next();
		zhangsan_text.setAdress(s);
		s=in.next();
		zhangsan_text.setPhone(s);
		
		zhangsan_text.getInfor();
		
		s=in.next();
		zhangsan_text.setTel(s);
		zhangsan_text.getTel();
	}

}
