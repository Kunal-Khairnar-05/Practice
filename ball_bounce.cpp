#include<iostream>
#include<cmath>
#include<graphics.h>
using namespace std;

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 300;
const int BALL_RADIUS=20;
const int AMPLITUDE = 50;
const int FREQUENCY = 50;

int getYSinePosition(int x, int centerY){
    return centerY - AMPLITUDE * sin(x*M_PI/180);
}

int main(){
   
   int gd=DETECT, gm;
   initwindow(700,700);

   int x = 0;
   int centerY = WINDOW_WIDTH/2;

   while(!kbhit()){
    cleardevice();

    int y = getYSinePosition(x,centerY);

    setcolor(RED);
    setfillstyle(SOLID_FILL,RED);
    fillellipse(x,y,BALL_RADIUS,BALL_RADIUS);

    delay(20);

    x+=5;

    if(x>WINDOW_WIDTH+BALL_RADIUS){
        x = -BALL_RADIUS;
    }
   }
   closegraph();
   return 0;
}