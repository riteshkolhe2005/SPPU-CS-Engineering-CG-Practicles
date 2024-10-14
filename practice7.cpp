#include<iostream>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
using namespace std;
int main()
{
	float x=1,y,count=0.1,j=0.5;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	setcolor(01);
	for(int k=0;k<7;k++)
	{
		for(int i=90;i<270;i+=10)
		{
			y=cos(i*3.14/180)/j;
			x+=5;
			circle(x,y*100+200,15);
			floodfill(x,y*100+200,01);
			line(0,215,800,215);
			delay(50);
		}
		j+=count;
		count+=0.1;
	}
	getch();
	return 0;
}
