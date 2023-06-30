#include<graphics.h>
#include<iostream>
int main()
{
    int gd= DETECT,gm;
    initgraph(&gd,&gm," ")
    circle =(200,200,100);
    std::cout<<"This is a circle";
    getch();
    closegraph();
    return 0;

}
