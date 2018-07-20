#include<stdio.h>
int main()
{
	char a[50];
	int n,i,j,k,r1=0,r2=0,r3=0,r4=0,s=0,t=0;
	while(scanf("%d",&n)!=EOF){
	getchar();
	for(i=0;i<n;i++)
	{
		t=0;
	    gets(a);
		k=strlen(a);
		if(k>=8&&k<=16)
			t++;
		for(j=0;j<k;j++)
		{
			if(a[j]>='0'&&a[j]<='9')
				r1++;
			if(a[j]>='a'&&a[j]<='z')
				r2++;
			if(a[j]>='A'&&a[j]<='Z')
				r3++;
			if(a[j]=='~'||a[j]=='!'||a[j]=='@'||a[j]=='#'||a[j]=='$'||a[j]=='%'||a[j]=='^')
				r4++;
		}
		if(r1!=0) s++;
		if(r2!=0) s++;
		if(r3!=0) s++;
		if(r4!=0) s++;
		if(s>=3&&t>0)
			printf("YES\n");
		else
			printf("NO\n");
		s=0;r1=0;r2=0;r3=0;r4=0;
		for(j=0;j<k;j++)
			a[j]='\0';
	}}
	return 0;
}

