#include <iostream>
#include <graphics.h>
using namespace std;
int main()
{
    int gd = DETECT , gm;
    int X1,Y1,X2,Y2;
    cout<<"Enter the Clipping window Coordinates:"<<endl;
    cin>>X1>>Y1>>X2>>Y2;
    float x1,y1,x2,y2;
    cout<<"Enter the Line Coordinates:"<<endl;
    cin>>x1>>y1>>x2>>y2;

    float op[2][4]; 

    if(x1<X1)
        op[0][3]=1;
    else
        op[0][3]=0;
    if(x1>X2) 
        op[0][2]=1;
    else
        op[0][2]=0;
    if(y1<Y1)
        op[0][0]=1;
    else
        op[0][0]=0;
    if(y1>Y2)
        op[0][1]=1;
    else
        op[0][1]=0;
    if(x2<X1)
        op[1][3]=1;
    else
        op[1][3]=0;
    if(x2>X2) 
        op[1][2]=1;
    else
        op[1][2]=0;
    if(y2<Y1)
        op[1][0]=1;
    else
        op[1][0]=0;
    if(y2>Y2)
        op[1][1]=1;
    else
        op[1][1]=0;
    initwindow(700,700);
    outtextxy(100,100,"Before Clipping:");
    rectangle(X1,Y1,X2,Y2);
    line(x1,y1,x2,y2);
    delay(3000);
    cleardevice();
  
    float m = (y2-y1)/(x2-x1);
    
    cout<<op[0][0]<<op[0][1]<<op[0][2]<<op[0][3]<<endl;
    cout<<op[1][0]<<op[1][1]<<op[1][2]<<op[1][3]<<endl;
   
    if(!(op[0][0]==0&&op[0][1]==0&&op[0][2]==0&&op[0][3]==0&&op[1][0]==0&&op[1][1]==0&&op[1][2]==0&&op[1][3]==0))
    {
        if(((op[0][0]&&op[1][0])==0)&&((op[0][1]&&op[1][1])==0)&&((op[0][2]&&op[1][2])==0)&&((op[0][3]&&op[1][3])==0))
        {          
            if(op[0][0]==1)
            {    
                x1 += (Y1-y1)/m;
                y1=Y1;
            }
            if(op[0][1]==1)
            {
                x1 += (Y2-y1)/m;
                y1=Y2;
            }
            if(op[0][2]==1)
            {
                y1 += m*(X2-x1);
                x1=X2;
            }
            if(op[0][3]==1)
            {
                y1 += m*(X1-x1);
                x1= X1;
            } 
            if(op[1][0]==1)
            {
                x2 += (Y1-y2)/m;
                y2=Y1;
            }
            if(op[1][1]==1)
            {
                x2 += (Y2-y2)/m;
                y2=Y2;
            }    
            if(op[1][2]==1)
            {
                y2 += m*(X2-x2);
                x2=X2;
            }
            if(op[1][3]==1)
            {
                y2 += m*(X1-x2);
                x2= X1;
            }
        }
        else
        {
            x1=x2=y1=y2=0;
        }
    }
    outtextxy(100,100,"After Clipping:");
    rectangle(X1,Y1,X2,Y2);
    line(x1,y1,x2,y2);
    getch();
    closegraph();
    return 0;
}