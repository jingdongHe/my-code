package ch2;

import java.util.Scanner;

public class t1_chnegji {

	/*定义一个学生的JAVA成绩为76，编写一个程序输出这个学生成绩是“中”级。
	 * （优：>=90;良：>=80;中：>=70;及格：>=60;不及格：<60)
	 */
	static int sorce=0;
	static void print()
	{
		if(sorce>=90)
			System.out.println("优");
		else if(sorce>=80)
			System.out.println("良");
		else if(sorce>=70)
			System.out.println("中");
		else if(sorce>=60)
			System.out.println("及格");
		else
			System.out.println("不及格");
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		sorce=in.nextInt();
		System.out.println(sorce);
		print();
	}

}
