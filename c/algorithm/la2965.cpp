#include<stdio.h>
#include<map>
using namespace std;const int maxn=24;
map<int,int> table;

int bitcount(int x) { return x == 0 ? 0 : bitcount(x/2) + (x&1); }
int main() 
{
	int n, A[maxn];
	char s[1000];
	int i,j;
	while(scanf("%d", &n) == 1 && n)
	{
	// ���벢����ÿ���ַ�����Ӧ��λ����
		for(i = 0; i < n; i++) 
		{
			scanf("%s",&s);
			A[i] = 0;
			for(j = 0; s[j] != '\0'; j++) A[i] ^= (1<<(s[j]-'A'));
		}
		//��������󣬼��ɵõ����е�A[i](A[i]Ϊ���õĶ�������)
		table.clear();
     int n1 = n/2, n2 = n-n1;
     for(i = 0; i < (1<<n1); i++) {
       int x = 0;
       for(j = 0; j < n1; j++) if(i & (1<<j)) x ^= A[j];
       if(!table.count(x) || bitcount(table[x]) < bitcount(i)) table[x] = i;
     }
	}
	return 0;
}
