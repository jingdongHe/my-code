package ch2;

import java.util.Scanner;

public class t1_chnegji {

	/*����һ��ѧ����JAVA�ɼ�Ϊ76����дһ������������ѧ���ɼ��ǡ��С�����
	 * ���ţ�>=90;����>=80;�У�>=70;����>=60;������<60)
	 */
	static int sorce=0;
	static void print()
	{
		if(sorce>=90)
			System.out.println("��");
		else if(sorce>=80)
			System.out.println("��");
		else if(sorce>=70)
			System.out.println("��");
		else if(sorce>=60)
			System.out.println("����");
		else
			System.out.println("������");
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		sorce=in.nextInt();
		System.out.println(sorce);
		print();
	}

}
