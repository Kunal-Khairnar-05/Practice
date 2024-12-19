#include<iostream>
#include<graphics.h>
using namespace std;

int main(){
   int gd=DETECT, gm;

   initwindow(700,700);
   int Xmin,Ymin,Xmax,Ymax;
   float x1,y1,x2,y2;

   float op[2][4];

   cout<<"Enter coordinates of clipping window : ";
   cin>>Xmin>>Ymin>>Xmax>>Ymax;

   cout<<"\nEnter coordinates of Line : ";
   cin>>x1>>y1>>x2>>y2;

   if(x1<Xmin){
    op[0][3]=1;
   }
   else{
    op[0][3]=0;
   }

   if(x1>Xmax){
    op[0][2]=1;
   }
   else{
    op[0][2]=0;
   }
   if(y1>Ymax){
    op[0][1]=1;
   }
   else{
    op[0][1]=0;
   }
   if(y1<Ymin){
    op[0][0]=1;
   }
   else{
    op[0][0]=0;
   }

   if(x2<Xmin){
    op[1][3]=1;
   }
   else{
    op[1][3]=0;
   }

   if(x2>Xmax){
    op[1][2]=1;
   }
   else{
    op[1][2]=0;
   }
   if(y2>Ymax){
    op[1][1]=1;
   }
   else{
    op[1][1]=0;
   }
   if(y2<Ymin){
    op[1][0]=1;
   }
   else{
    op[1][0]=0;
   }


    outtextxy(100,100,"Before Clipping");
    rectangle(Xmin,Ymin,Xmax,Ymax);
    line(x1,y1,x2,y2);
    delay(5000);
    cleardevice();
    
    float m = (y2-y1)/(x2-x1);

    if(!(op[0][0]==0&&op[0][1]==0&&op[0][2]==0&&op[0][3]==0&&op[1][0]==0&&op[1][1]==0&&op[1][2]==0&&op[1][3]==0)){
       
        if(((op[0][0]&&op[1][0])==0)&&
           ((op[0][1]&&op[1][1])==0)&&
           ((op[0][2]&&op[1][2])==0)&&
           ((op[0][3]&&op[1][3])==0)){

                // top 1
                if(op[0][0]==1){
                    x1=x1+(Ymin-y1)/m;
                    y1=Ymin;
                }
                if(op[1][0]==1){
                    x2 = x2+(Ymin-y2)/m;
                    y2=Ymin;
                }
                // bottom 
                if(op[0][1]==1){
                    x1=x1+(Ymax-y1)/m;
                    y1=Ymax;
                }
                if(op[1][1]==1){
                    x2= x2+(Ymax-y2)/m;
                    y2=Ymax;
                }

                // right
                if(op[0][2]==1){
                    y1=y1+m*(Xmax-x1);
                    x1=Xmax;
                }
                if(op[1][2]==1){
                    y2=y2+m*(Xmax-x2);
                    x2=Xmax;
                }

                // left
                if(op[0][3]==1){
                    y1=y1+m*(Xmin-x1);
                    x1=Xmin;
                }
                if(op[1][3]==1){
                    y2=y2+m*(Xmin-x2);
                    x2=Xmin;
                }
           }
           else{
            x1=x2=y1=y2=0;
           }
    }
   

    outtextxy(100,100,"After Clipping");
    rectangle(Xmin,Ymin,Xmax,Ymax);
    line(x1,y1,x2,y2);
    getch();
    closegraph();
   return 0;
}