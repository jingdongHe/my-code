package ch8ch9;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Triangle {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		
		FileOutputStream f=new FileOutputStream("triangle.txt");
		PrintStream fout=new PrintStream(f);
		
		int d=0;
		while(d<=n/2)
		{
			for(int i=0;i<d;i++)
			{
				fout.print(' ');
				System.out.print(" ");
			}
			for(int i=d;i<n-d*2+d;i++)
			{
				fout.print("*");
				System.out.print("*");
			}
			fout.print("\n");
			System.out.print('\n');
			d++;
		}
	}

}
