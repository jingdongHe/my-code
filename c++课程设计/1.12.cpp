/*������12. ���һ�ļ��Ķ���, ����һ��һ��(20��22��)��ʾ�ļ�����,
 ÿ����ʾ��һ�����ݺ�, ��ʾʹ���߼���һ�����ַ��Կ�����Ļ������
���ַ�'n'��ʾ��һ��, �ַ�'p'������һ��, �ַ�'q'�����Ķ���*/
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