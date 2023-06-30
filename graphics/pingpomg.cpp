#include<graphics.h>
#include<stdlib.h>
float x=3.5,y=3.5;//ball speed
void player1(int,int,int);
void player2(int,int,int);
void ball(int,int,int,int,int);
void border();
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    int p1=0,p2=0,height=20,width=64;//   data input for the bat.
    int dp1=p1,dp2=p2;//determines the change in the position and shifts the bat
    int dx=0;
    border();
    int l1=0,l2=0,label;
    char c[12];
    setbkcolor(YELLOW);
    label:
    int centerx=getmaxx()/2+dx,centery=getmaxy()/2,radius=10;//ball layout
    getch();
        for(;;)
        {
            cleardevice(); 
            sprintf(c,"SCORE %d:%d",l1,l2);//display the score.
            outtextxy(getmaxx()/2,10,c);
            player1(p1,height,width);
            player2(p2,height,width);
            ball(centerx,centery,radius,p1,p2);
            if(p1<dp1)
            p1+=30;
            if(p1>dp1)
            p1-=30;
            if(p2<dp2)
            p2+=30;
            if(p2>dp2)
            p2-=30;
            centerx+=x;
            centery+=y;
            if(kbhit())
            {
            char c=getch();
                if(c=='w')
                dp1=dp1-30;
                if(c=='s')
                dp1=dp1+30;
                if(c=='8')
                dp2-=30;
                if(c=='2')
                dp2+=30;
            }
            if(centerx+radius>getmaxx())
            {
                dx=-200;
                l2++;
                goto label;
            }
            if(centerx-radius<0)
            {
                dx=200;
                l1++;
                goto label;
            }
            delay(1);
            if(l1==10)
            {
                outtextxy(250,230,(char *)"GAME OVER");
                outtextxy(250,250,(char *)"P2 WON");
                break;
            }
            if(l2==10)
            {
                outtextxy(250,230,(char *)"GAME OVER");
                outtextxy(250,250,(char *)"P1 WON");
                break;
            }
        }
    getch();
    closegraph();
    return 0;
}
void player1(int p1,int height,int weidth)
{
    int i;
    for(i=0;i<weidth;i++)
    putpixel(height,p1+i,BLACK);
    for(i=0;i<height;i++)
    putpixel(i,p1,BLACK);
    for(i=0;i<height;i++)
    putpixel(i,p1+weidth,BLACK);
}
void player2(int p2,int height,int weidth)
{
    int i;
    for(i=0;i<weidth;i++)
    putpixel(getmaxx()-height,p2+i,BLACK);
    for(i=0;i<height;i++)
    putpixel(getmaxx()-i,p2,BLACK);
    for(i=0;i<height;i++)
    putpixel(getmaxx()-i,p2+weidth,BLACK);
}
void ball(int centerx,int centery,int radius,int p1,int p2)
{
    setcolor(BLACK);
    circle(centerx,centery,radius);
    if(centerx+radius>getmaxx()-20 && centery+radius>p2 && centery-radius<p2+64)//p2
    {
        x=-x;
    }
    if(centery+radius>getmaxy())
    {
        y=-y;
    }
    if(centery+radius<0)
    {
        y=-y;
    }
    if(centerx-radius<20 && centery+radius>p1 && centery-radius<p1+64)//p1
    {
        x=-x;
    }
}
void border()
{
    outtextxy(getmaxx()/2-70,getmaxy()/2-20,(char *)"WELCOME TO PING PONG GAME");
    outtextxy(getmaxx()/2-70,getmaxy()/2,(char *)"LEFT IS P1 RIGHT IS P2");
    outtextxy(getmaxx()/2-70,getmaxy()/2+20,(char *)"PRESS ANY KEY TO BEGIN");
}