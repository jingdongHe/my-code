#include<stdio.h>
int main()
{
		int n,i,j;
        int N[4];
		int n_min=0;int n_max = 0;
		scanf("%d",&n);
        for(i=0;i<4;i++)
        {
                N[3-i] = n % 10;
                n=n/10;
        }
        for(i=0;i<3;i++)
                for(j=0;j<3-i;j++)
                        if(N[j]>N[j+1])
                        {
                                int t = N[j+1];
                                N[j+1] = N[j];
                                N[j] = t;
                        }
        
        for(i=0; i<4; i++)
                n_min = n_min * 10 + N[i];
        
        for(i=3; i>=0; i--)
                n_max = n_max * 10 + N[i];
        printf("%d\n",n_max-n_min);
}
