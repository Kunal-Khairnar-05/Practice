#include<iostream>
#include<graphics.h>

void Boundary(int x, int y, int f, int b){
    if(getpixel(x,y)!=f && getpixel(x,y)!=b){
        putpixel(x,y,f);
        Boundary(x,y+1,f,b);
        Boundary(x,y-1,f,b);
        Boundary(x+1,y,f,b);
        Boundary(x-1,y,f,b);
        Boundary(x+1,y+1,f,b);
        Boundary(x+1,y-1,f,b);
        Boundary(x-1,y-1,f,b);
        Boundary(x-1,y+1,f,b);
    }
}

int main(){
    initwindow(700,700);
    int poly[]={20,20,200,20,200,200,20,200,20,20};
    drawpoly(5,poly);

    Boundary(30,30,RED,WHITE);

    getch();
    closegraph();
    return 0;
}