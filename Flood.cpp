#include <iostream>
#include <graphics.h>
#include <string.h>

int flood(int x, int y, int n, int o)
{
    if (getpixel(x, y) == o)
    {
        putpixel(x, y, n);
        flood(x, y + 1, n, o);
        flood(x, y - 1, n, o);
        flood(x + 1, y, n, o);
        flood(x - 1, y, n, o);
        flood(x + 1, y + 1, n, o);
        flood(x - 1, y + 1, n, o);
        flood(x, y - 1, n, o);
        flood(x - 1, y - 1, n, o);
    }
}

int main()
{
    int gd = DETECT, gm;
    char *path = "C:\\Program Files (x86)\\Colorado\\cs1300\\bgi";
    char *text = "Flood Fill Algorithm";
    initgraph(&gd, &gm, path);
    int poly[] = {20, 20, 200, 20, 200, 200, 20, 200, 20, 20};
    drawpoly(5, poly);
    flood(30, 30, 3, 0);
    setcolor(2);

    outtextxy(300, 20, text);
    getch();
    closegraph();
    return 0;
}