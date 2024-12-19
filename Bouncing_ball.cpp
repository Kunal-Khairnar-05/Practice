#include<iostream>
#include<graphics.h>
#include<cmath>

using namespace std;

const int WINDOW_HEIGHT = 640;
const int WINDOW_WIDTH = 480;
const int BALL_RADIUS = 20;
const int AMPLITUDE = 100;
const int FREQUENCY = 50;

int getYSinePosition(int x, int centerY){
    return centerY - AMPLITUDE * sin(x * M_PI / 180);
}


int main(){
   int gd = DETECT , gm;
   initwindow(700,700);

   int centerY = WINDOW_HEIGHT / 2;
   int x = 0;

   while(!kbhit()){
        cleardevice();
 
        int y = getYSinePosition(x, centerY);

        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        fillellipse(x,y,BALL_RADIUS,BALL_RADIUS);

        delay(20);

        x+=5;

        if(x > WINDOW_WIDTH + BALL_RADIUS){
            x = -BALL_RADIUS;    
        }
   }
   closegraph();
   return 0;
}