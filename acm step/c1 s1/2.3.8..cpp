#include<iostream>
#include<string>
using namespace std;
const int maxn=40;
string add(string a,string b)
{
	string c="";
	int i,j,s=0;
	for(i=a.size()-1,j=b.size()-1;i>=0&&j>=0;i--,j--)
	{
		int k=a[i]+b[j]-2*'0'+s;
		c=char(k%10+'0')+c;
		s=k/10;
	}
	while(i>=0)
	{
		int k=a[i]-'0'+s;
		c=char(k%10+'0')+c;
		s=k/10;
		i--;
	} 
	while(j>=0)
	{
		int k=b[j]-'0'+s;
		c=char(k%10+'0')+c;
		s=k/10;
		j--;
	} 
	while(s!=0)
	{
		c=char(s%10+'0')+c;
		s/=10;
	}
	return c;
}
int main()
{
	string a[maxn][maxn];
	int n,t=0;
	while(cin>>n&&n!=-1)
	{
		t++;
		for(int i=0;i<=n+1;i++)
		{
			for(int j=0;j<=n+1;j++)
				a[i][j]="0";
		}
		for(int i=1;i<=n+1;i++)
			a[1][i]="1";
		for(int i=2;i<=n+1;i++)
		{
			for(int j=1;j<=n+1;j++)
			{
				if(i>j) continue;
				a[i][j]=add(a[i-1][j],a[i][j-1]);
			}
		}
		cout<<t<<" "<<n<<" "<<add(a[n+1][n+1],a[n+1][n+1])<<endl;
	}
	return 0;
}
