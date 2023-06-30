#include<stdio.h>
#include<graphics.h>
int main()
{
	int x=10, y=10,a=400,b=400;
	int gd=DETECT, gm;
	initgraph(&gd,&gm," ");
	
		Line(x,y,a,b);
		delay(50000);
		closegraph();
		return 0;
	
}
