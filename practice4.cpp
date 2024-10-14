#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
class poly
{
	int x1,y1,x2,y2,x3,y3;
	public:
		void read();
		void draw();
		poly operator +(poly t);
		poly operator -(poly t);
		poly operator /(poly t);
};
void poly::read()
{
	cout<<"Enter coordinates for triangle"<<endl;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
}
void poly::draw()
{
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
}
poly poly::operator +(poly t)
{
	int tx,ty;
	cout<<"Enter transaltion factor"<<endl;
	cin>>tx>>ty;
	t.x1=x1+tx;
	t.y1=y1+ty;
	t.x2=x2+tx;
	t.y2=y2+ty;
	t.x3=x3+tx;
	t.y3=y3+ty;
	return t;
}
poly poly::operator *(poly t)
{
	int sx,sy;
	cout<<"Enter scaling factor"<<endl;
	cin>>sx>>sy;
	t.x1=x1*sx;
	t.y1=y1*sy;
	t.x2=x2*sx;
	t.y2=y2*sy;
	t.x3=x3*sx;
	t.y3=y3*sy;
	return t;	
} 
poly poly::operator /(poly t)
{
	int r;
	cout<<"Enter rotation angle"<<endl;
	cin>>r;
	float theta=3.14*r/180;
	t.x1=abs(x1*cos(theta)-y1*sin(theta));
	t.y1=abs(x1*sin(theta)+y1*cos(theta));
	t.x2=abs(x2*cos(theta)-y2*sin(theta));
	t.y2=abs(y2*sin(theta)+y2*cos(theta));
	t.x3=abs(x3*cos(theta)-y3*sin(theta));
	t.y3=abs(x3*sin(theta)+y3*cos(theta));
}
int main()
{
	poly t1,t2,T,S,R;
	int gm;
	int gd=DETECT;

	initgraph(&gd,&gm,NULL);
		t1.read();
	t1.draw();
	T=t1+t2;
	T.draw();
	S=t1*t2;
	S.draw();
	R=t1/t2;
	R.draw();
	return 0;
}

