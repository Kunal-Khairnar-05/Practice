#include<iostream>
#include<graphics.h>
using namespace std;

void scanfill(int x[], int y[], int n){
    int ymin = y[0], ymax=y[0];

    for(int i=0;i<n;i++){
        if(y[i]<ymin)
            ymin=y[i];
        
        if(ymax<y[i]){
            ymax = y[i];
        }
    }


    for(int scanline = ymin; scanline<ymax; scanline++){
        int intersection[10],k=0;

        for(int i=0; i<n; i++){
            int x1 = x[i], y1=y[i];
            int x2 = x[(i+1)%n], y2=y[(i+1)%n];

            if(y1!=y2 && scanline>=min(y1,y2) && scanline<=max(y1,y2)){
                int x_inter = x1+(scanline - y1)*(x2-x1)/(y2-y1);
                intersection[k++]=x_inter;
            }
        }
    
        for(int i=0; i<k-1; i++){
            for(int j=0; j<k-i-1; j++){
                if(intersection[j]>intersection[j+1]){
                    swap(intersection[j],intersection[j+1]);
                }
            }
        }

        for(int i=0;i<k; i+=2){
            line(intersection[i],scanline,intersection[i+1],scanline);
            delay(20);
        }
         outtextxy(300,100,"Scanfill  O__O");
    }
}

int main(){
   initwindow(700,700);

    int x[]={100,200,200,100};
    int y[]={50,50,200,200};
    int n=4;

    for(int i=0; i<n; i++){
        line(x[i],y[i],x[(i+1)%n],y[(i+1)%n]);
    }
    scanfill(x,y,n);
    getch();
    closegraph();
   return 0;
}