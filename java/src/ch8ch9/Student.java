package ch8ch9;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
/*创建一个Student学生类，其中域变量包括name,age,javaScore和cScore；
创建一个TestChengji类，在main主方法中分别创建三个对象数组：
String []stu=new String[3];
String []javaScore=new String[3];
String []cScore=new String[3];
将控制台输入的数据保存在数组中，然后在保存到一个文件中。
*/
class Student1 {
	String name;int age;
	double javaScore,cScore;
	public Student1()
	{
		Scanner in=new Scanner(System.in);
		name=in.next();
		age=in.nextInt();
		javaScore=in.nextDouble();
		cScore=in.nextDouble();
		
	}
	public String getname()
	{
		return name;
	}
	public int getage()
	{
		return age;
	}
	public double getjavascore()
	{
		return javaScore;
	}
	public double getcscore()
	{
		return cScore;
	}
}
public class Student {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		PrintWriter fout
			=new PrintWriter(new BufferedWriter(new FileWriter("student.txt")));
		
		Student1 []a=new Student1[3];
		for(int i=0;i<3;i++)
		{
			a[i]=new Student1();
			fout.write(String.valueOf(a[i].getname())+" ");
			fout.write(String.valueOf(a[i].getage())+" ");
			fout.write(String.valueOf(a[i].getjavascore())+" ");
			fout.write(String.valueOf(a[i].getcscore()));
			fout.println();
		}

		fout.close();


	}

}
