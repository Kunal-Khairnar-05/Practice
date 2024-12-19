#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initwindow(700, 700);

    int x1, y1, x2, y2, x3, y3, x4, y4, tx, ty;

    cout << "Enter the coordinates of the square: ";
    cin >> x1 >> y1 >> x3 >> y3;
    rectangle(x1, y1, x3, y3);

    cout << "Enter the translation factors: ";
    cin >> tx >> ty;

    x1 = x1 + tx;
    y1 = y1 + ty;
    x3 = x3 + tx;
    y3 = y3 + ty;

    rectangle(x1, y1, x3, y3);

    delay(1000);

    int sx, sy;
    cout << "\nEnter Scaling factor : ";
    cin >> sx >> sy;

    x1 *= sx;
    y1 *= sy;
    x3 *= sx;
    y3 *= sy;

    rectangle(x1, y1, x3, y3);
    delay(1000);

    int angle;

    cout << "\nEnter Angle or rotation : ";
    // cin >> angle;

    angle = 60 * M_PI / 180;
    int points[8] = {
        -50, -30, // top left
        50, -30,  // top right
        50, 30,   // bottom right
        -50, 30   // bottom left
    };

    int cx = 200,cy=200;

    // Draw rotated rectangle
    for (int i = 0; i < 8; i += 2)
    {
        int next = (i + 2) % 8;

        int x1 = cx + points[i] * cos(angle) - points[i + 1] * sin(angle);
        int y1 = cy + points[i] * sin(angle) + points[i + 1] * cos(angle);

        int x2 = cx + points[next] * cos(angle) - points[next + 1] * sin(angle);
        int y2 = cy + points[next] * sin(angle) + points[next + 1] * cos(angle);

        line(x1, y1, x2, y2);
    }

    delay(1000);
    getch();
    closegraph();

    return 0;
}