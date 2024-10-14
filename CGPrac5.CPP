#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void koch(int x1, int y1, int x2, int y2,int it)
{ 
	int x3,x4,y3,y4,x,y;
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
	int gd=DETECT,gm, x1=100,y1=100, x2=400,y2=400,it=2;
	initgraph(&gd,&gm,NULL);
	koch(x1,y1,x2,y2,it);
	getch();
	closegraph();
	return 0;
}


slicex and slicey:

slicex and slicey represent the horizontal and vertical distances, respectively, that are used to divide the line segment between two points ((x1, y1) and (x2, y2)) into three equal parts.
These distances are calculated as (x2 - x1) / 3 and (y2 - y1) / 3, dividing the line into three segments.
x and y:

x and y represent the coordinates of a point that is calculated based on the initial points (x3, y3) and (x4, y4).
These coordinates are used to calculate the endpoint of a line segment after applying a rotation transformation.
The rotation is done by an angle of 60 degrees in the counter-clockwise direction. The formulae for the new coordinates are based on a rotation matrix.
: What is the Koch curve?
Answer: The Koch curve is a mathematical curve with self-similar properties, constructed by recursively replacing each straight line segment with three segments of equal length, forming an equilateral triangle.
Purpose of the Code:

Question: What is the purpose of this C++ program?
Answer: The program generates and displays a Koch curve using the graphics.h library. It demonstrates the recursive construction of the Koch curve, creating a visually appealing fractal pattern.
Role of Recursion:

Question: How does recursion play a role in drawing the Koch curve?
Answer: Recursion is used to iteratively apply the Koch curve construction process. The function koch calls itself with updated endpoints and reduced recursion depth, ultimately drawing the entire curve.
Rotation in the Koch Curve:

Question: Explain the purpose of the rotation in the code.
Answer: The rotation is used to create the characteristic "hump" in the middle of each line segment. It rotates a point around one endpoint of the segment, producing the desired shape for the Koch curve.
Parameters of the Koch Function:

Question: Describe the parameters of the koch function and their significance.
Answer: The koch function takes four parameters: initial and final coordinates of a line segment (x1, y1, x2, y2) and the recursion depth it. These parameters control the position of the line segment and the level of detail in the generated Koch curve.
Graphics Library and Initialization:

Question: Why is the graphics.h library used, and what does the initgraph function do?
Answer: The graphics.h library is used for simple graphics operations. The initgraph function initializes the graphics system, allowing subsequent drawing operations to be performed on a graphical window.
Recursion Termination Condition:

Question: How does the code ensure that recursion terminates?
Answer: The termination condition is based on the recursion depth (it). If it is greater than zero, the function continues to call itself with reduced recursion depth. When it becomes zero, the function stops further recursion and draws the line segments.
Drawing Lines vs. Recursive Calls:

Question: Explain the difference between the conditions for drawing lines and making recursive calls in the koch function.
Answer: When the recursion depth is greater than zero, the function makes recursive calls to draw the Koch curve. When the recursion depth is zero, the function draws the actual line segments using the line function.
