#include <iostream>
#include <graphics.h>
#include <stdlib.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    while (!kbhit()) { 
        int x = rand() % getmaxx(); 
        int y = rand() % getmaxy(); 
        int radius = rand() % 100; 

        int color = rand() % 15 + 1;

        setcolor(color);
        setfillstyle(SOLID_FILL, color);

        circle(x, y, radius);
        floodfill(x, y, color);

        delay(100);
    }

    closegraph();
    return 0;
}
