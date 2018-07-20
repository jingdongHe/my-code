#include<stdio.h>
#include<math.h>
int ax,ay,bx,by,cx,cy,dx,dy;
int P,R,Q;
double dis(double Ax,double Ay,double Bx,double By)
{
	return sqrt((Bx-Ax)*(Bx-Ax)+(By-Ay)*(By-Ay));
}
double find_min(double ax,double ay)
{
	double cdxmin=cx,cdymin=cy,cdxmax=dx,cdymax=dy;
	double cdxmid,cdymid,cdxmid2,cdymid2;
	double k1,k2;
	do
	{
		cdxmid=(cdxmin+cdxmax)/2.0;
		cdymid=(cdymin+cdymax)/2.0;
		cdxmid2=(cdxmid+cdxmax)/2.0;
		cdymid2=(cdymid+cdymax)/2.0;
		k1=dis(ax,ay,cdxmid,cdymid)/(R*1.0)+dis(cdxmid,cdymid,dx,dy)/(Q*1.0);
		k2=dis(ax,ay,cdxmid2,cdymid2)/(R*1.0)+dis(cdxmid2,cdymid2,dx,dy)/(Q*1.0);
		/*printf("%lf  %lf\n",k1,k2);
		printf("%lf  %lf  %lf  %lf\n",cdxmid,cdymid,cdxmid2,cdymid2);*/
		if(k1>k2){cdxmin=cdxmid;cdymin=cdymid;}
		else{cdxmax=cdxmid2;cdymax=cdymid2;}
	}while(fabs(k2-k1)>1e-4);
	return k1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy,&P,&Q,&R);
		double abxmin=ax,abymin=ay,abxmax=bx,abymax=by;
		double abxmid,abymid,abxmid2,abymid2;
		double k1,k2;
		do
		{
			abxmid=(abxmin+abxmax)/2.0;
			abymid=(abymin+abymax)/2.0;
			abxmid2=(abxmid+abxmax)/2.0;
			abymid2=(abymid+abymax)/2.0;
			//printf(".............%lf  %lf  %lf  %lf:\n",abxmid,abymid,abxmid2,abymid2);
			k1=dis(abxmid,abymid,ax,ay)/(P*1.0)+find_min(abxmid,abymid);
			k2=dis(abxmid2,abymid2,ax,ay)/(P*1.0)+find_min(abxmid2,abxmid2);
			if(k1>k2){abxmin=abxmid;abymin=abymid;}
			else{abxmax=abxmid2;abymax=abymid2;}
		}while(fabs(k2-k1)>1e-4&&(abxmid!=abxmid2||abymid!=abymid2));
		printf("%.2lf\n",k1);
	}
	return 0;
}
