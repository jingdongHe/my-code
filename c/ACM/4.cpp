#include<stdio.h>
#include<math.h>
struct Point {
	double x,y,z;
	Point(double x=0,double y=0,double z=0):x(x),y(y),z(z){}
};
typedef Point Vector;
double t,s;
Vector operator - (Point a,Point b)
{return Vector(a.x-b.x,a.y-b.y,a.z-b.z);}
Vector operator * (Point a,double p)
{return Vector(a.x*p,a.y*p,a.z*p);}
double dot(Vector a,Vector b)
{return a.x*b.x+a.y*b.y+a.z*b.z;}
int dcmp(double x)
{if(fabs(x)<1e-10) return 0;else return x<0?-1:1;}
bool LineDistance(Point p1,Vector u,Point p2,Vector v)
{
	double b=dot(u,u)*dot(v,v)-dot(u,v)*dot(u,v);
	if(dcmp(b)==0) return false;
	double a=dot(u,v)*dot(v,p1-p2)-dot(v,v)*dot(u,p1-p2);
	s=a/b;
	t=(dot(u,v)*s-dot(p2-p1,v))/dot(v,v);
	return true;
}
double Length(Vector a)
{return sqrt(dot(a,a));}
Vector cross(Vector a,Vector b)
{
	return Vector(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
double dis(Point p,Point a,Point b)
{
	Vector v=b-a,u=p-a;
	return Length(cross(v,u))/Length(v);
}
Point get(const Point& p,const Point& p0,const Vector& n)
{
	return p-n*dot(p-p0,n);
}
int main()
{
	double x1,y1,z1,x2,y2,z2;
	double x3,y3,z3,x4,y4,z4;
	double d;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&z1,&x2,&y2,&z2,&x3,&y3,&z3,&x4,&y4,&z4);
		Point A,B,C,D,p1,p2;
		A.x=x1;A.y=y1,A.z=z1;
		B.x=x2;B.y=y2,B.z=z2;
		C.x=x3;C.y=y3,C.z=z3;
		D.x=x4;D.y=y4,D.z=z4;
		Vector u,v;
		u=B-A;v=D-C;
		if(LineDistance(A,u,C,v))
		{
			p1.x=A.x+s*u.x;p1.y=A.y+s*u.y;p1.z=A.z+s*u.z;
			p2.x=C.x+t*v.x;p2.y=C.y+t*v.y;p2.z=C.z+t*v.z;
			d=sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y)+(p2.z-p1.z)*(p2.z-p1.z));
		}
		else
		{
			if(u.x/v.x==u.y/v.y&&u.z/v.z==u.x/v.x)
			{
				d=dis(A,C,D);
				p1=A;p2=get(C,A,u);
			}
		}
		printf("%lf\n",d);
		printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf%\n",p1.x,p1.y,p1.z,p2.x,p2.y,p2.z);
	}
	return 0;
}