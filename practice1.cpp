#include<iostream>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
using namespace std;
class line1
{
	public:
		void dda(int x1,int y1,int x2,int y2)
		{
			float x,y,xincre,yincre,length,dx,dy;
			dx=abs(x2-x1);
			dy=abs(y2-y1);
			if(dx>dy)
			{
				length=dx;
			}
			else
			{
				length=dy;
			}
			xincre=(x2-x1)/(float)length;
			yincre=(y2-y1)/(float)length;
			x=x1+0.5;
			y=y1+0.5;
			for(int i=0;i<length;i++)
			{
				putpixel(x,y,12);
				x=x+xincre;
				y=y+yincre;
			}
		}
		
};
class Circle
{
	public:
		void drawc(int x,int y,int r)
		{
			float d,x1,y1;
			d=3-2*r;
			x1=0;
			y1=r;
			while(x1<=y1)
			{
				plot(x1,y1,x,y);
				if(d<0)
				{
					x1=x1+1;
					d=d+(4*x1)+6;
				}
				else
				{
					x1=x1+1;
					y1=y1-1;
					d=d+(4*(x1-y1))+6;
				}
			}
		}
		void plot(int x1,int y1,int x2,int y2)
		{
			putpixel(x1+x2,y1+y2,12);
			putpixel(y1+x2,x1+y2,12);
			putpixel(-x1+x2,y1+y2,12);
			putpixel(y1+x2,-x1+y2,12);
			putpixel(x1+x2,-y1+y2,12);
			putpixel(-y1+x2,x1+y2,12);
			putpixel(-x1+x2,-y1+y2,12);
			putpixel(-y1+x2,-x1+y2,12);
		}
};
int main()
{
	Circle obj;
	line1 obj1;
	int x,y,r1,r2,x1,y1,x2,y2,x3,y3;
	cout<<"enter circle"<<endl;
	cin>>x>>y;
	cout<<"enter outer and inner circle"<<endl;
	cin>>r1>>r2;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	obj.drawc(x,y,r1);
	obj.drawc(x,y,r2);
	float length=sqrt((r1*r1)-(r2*r2));
	x1=x;
	y1=y-r1;
	x2=x-length;
	y2=y+r2;
	x3=x+length;
	y3=y+r2;
	obj1.dda(x1,y1,x2,y2);
	delay(100);
	obj1.dda(x2,y2,x3,y3);
	delay(100);
	obj1.dda(x3,y3,x1,y1);
	delay(100);
	getch();
	return 0;
}
