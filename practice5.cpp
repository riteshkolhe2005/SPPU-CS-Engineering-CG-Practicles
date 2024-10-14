#include<iostream>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

void koch(int x1,int y1,int x2,int y2,int it)
{
	int x,y,x3,y3,x4,y4;
	int slicex=(x2-x1)/3;
	int slicey=(y2-y1)/3;
	x3=x1+slicex;
	y3=y1+slicey;
	x4=x2-slicex;
	y4=y2-slicey;
	float theta=(60*M_PI)/180;
	x=x3+(x4-x3)*cos(theta)+(y4-y3)*sin(theta);
	y=y3-(x4-x3)*sin(theta)+(y4-y3)*cos(theta);
	if(it>0)
	{
		koch(x1,y1,x3,y3,it-1);
		koch(x3,y3,x,y,it-1);
		koch(x,y,x4,y4,it-1);
		koch(x4,y4,x2,y2,it-1);
	}
	else
	{
		line(x1,y1,x3,y3);
		line(x3,y3,x,y);
		line(x,y,x4,y4);
		line(x4,y4,x2,y2);
	}
	
	
}
int main()
{
	int x1=100,y1=100,x2=400,y2=400,it=2;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	koch(x1,y1,x2,y2,it);
	getch();
	closegraph();
	return 0;
}
