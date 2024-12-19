#include <iostream>
#include <graphics.h>

using namespace std;

class Point
{
public:
    int x, y;
};

class Poly : public Point
{ 
private:
    Point p[20];
    int inter[20];
    int v, xmin, ymin, xmax, ymax;
    int c;

public:
    void read()
    {
        cout << "\n\n\tSCAN_FILL ALGORITHM\n-------------------------------\n\n";
        cout << "\nEnter the number of vertices for the polygon: ";
        cin >> v;

        if (v > 2)
        {
            for (int i = 0; i < v; i++)
            {
                cout << "\nEnter coordinates for vertex " << i + 1 << ": ";
                cout << "\n\tx" << (i + 1) << " = ";
                cin >> p[i].x;
                cout << "\n\ty" << (i + 1) << " = ";
                cin >> p[i].y;
            }
            p[v].x = p[0].x;
            p[v].y = p[0].y;

            xmin = xmax = p[0].x;
            ymin = ymax = p[0].y;
        }
        else
        {
            cout << "\nEnter a valid number of vertices (at least 3).";
            exit(1);
        }
    }

    void calculateBounds()
    {
        for (int i = 0; i < v; i++)
        {
            if (xmin > p[i].x)
                xmin = p[i].x;
            if (xmax < p[i].x)
                xmax = p[i].x;
            if (ymin > p[i].y)
                ymin = p[i].y;
            if (ymax < p[i].y)
                ymax = p[i].y;
        }
    }

    void display()
    {
        float s = ymin + 0.01;
        cleardevice();
        while (s <= ymax)
        {
            findIntersections(s);
            sortIntersections(s);
            s++;
        }
    }
    void findIntersections(float z)
    {
        int x1, x2, y1, y2, temp;
        c = 0;

        for (int i = 0; i < v; i++)
        {
            x1 = p[i].x;
            y1 = p[i].y;
            x2 = p[i + 1].x;
            y2 = p[i + 1].y;

            if (y2 < y1)
            {
                swap(x1, x2);
                swap(y1, y2);
            }

            if (z <= y2 && z >= y1)
            {
                if ((y1 - y2) == 0)
                    x = x1;
                else
                    x = ((x2 - x1) * (z - y1)) / (y2 - y1) + x1;

                if (x <= xmax && x >= xmin)
                    inter[c++] = x;
            }
        }
    }
    void sortIntersections(int z)
    {
        for (int i = 0; i < v; i++)
        {
            line(p[i].x, p[i].y, p[i + 1].x, p[i + 1].y);
        }

        for (int i = 0; i < c; i += 2)
        {
            delay(100);
            line(inter[i], z, inter[i + 1], z);
        }
    }
};

int main()
{
    int color;
    initwindow(500, 600);
    cleardevice();

    Poly polygon;
    polygon.read();
    polygon.calculateBounds();

    cout << "\nEnter the color you want (0-15): ";
    cin >> color;
    setcolor(color);

    polygon.display();

    closegraph();
    getch();
    return 0;
}