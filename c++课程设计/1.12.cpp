/*　　　12. 设计一文件阅读器, 可以一次一屏(20或22行)显示文件内容,
 每次显示完一屏内容后, 提示使用者键入一控制字符以控制屏幕翻滚。
如字符'n'显示下一屏, 字符'p'返回上一屏, 字符'q'结束阅读。*/
#include<stdio.h>
#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
using namespace std;
int main()
{
	ifstream fin;
	char ch;
	int k=0;
	int n=10;
	fin.open("fly me to the moon.txt");
	string line;
	while(getline(fin,line))
	{
		cout<<line<<endl;
		if(++k==n)
		{
			
			scanf("%c",&ch);getchar();
			if(ch=='n')
			{system("cls");k=0;continue;}
			if(ch=='p')
			{
				streampos pos = fin.tellg();
				pos-=n;
				fin.seekg(pos);
				k=0;
				system("cls");
			}
			if(ch=='q')
				return 0;
		}
	}
	fin.close();
	return 0;
}