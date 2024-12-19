#include <graphics.h>
#include <iostream>

using namespace std;

// Function to draw and fill a polygon using the scanline algorithm
void scanlineFill(int x[], int y[], int n) {
    int ymin = y[0], ymax = y[0];

    for (int i = 1; i < n; i++) {
        if (y[i] < ymin) ymin = y[i];
        if (y[i] > ymax) ymax = y[i];
    }

    for (int scanline = ymin; scanline <= ymax; scanline++) {
        int intersections[10], k = 0;

        for (int i = 0; i < n; i++) {
            int x1 = x[i], y1 = y[i];
            int x2 = x[(i + 1) % n], y2 = y[(i + 1) % n];

            if (y1 != y2 && scanline >= min(y1, y2) && scanline <= max(y1, y2)) {
                // Find x-coordinate of intersection
                int x_int = x1 + (scanline - y1) * (x2 - x1) / (y2 - y1);
                intersections[k++] = x_int;
            }
        }
s
        // Sort intersections by x-coordinates
        for (int i = 0; i < k - 1; i++) {
            for (int j = 0; j < k - i - 1; j++) {
                if (intersections[j] > intersections[j + 1]) {
                    swap(intersections[j], intersections[j + 1]);
                }
            }
        }

        // Fill the pixels between pairs of intersections
        for (int i = 0; i < k; i += 2) {
            line(intersections[i], scanline, intersections[i + 1], scanline);
            delay(50);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initwindow(700,700);

    // Define polygon vertices
    int x[] = {200, 300, 250, 150};
    int y[] = {150, 200, 300, 250};
    int n = 4; // Number of vertices

    // Draw the polygon outline
    for (int i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }

    // Fill the polygon using Scanline algorithm
    scanlineFill(x, y, n);

    getch();
    closegraph();
    return 0;
}
