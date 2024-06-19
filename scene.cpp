#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setcolor(BLUE); 
    rectangle(0, 0, getmaxx(), getmaxy());
    floodfill(getmaxx() / 2, getmaxy() / 2, BLUE);

    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    ellipse(300, 400, 0, 180, 400, 100);
    floodfill(300, 400, DARKGRAY);

    
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(100, 100, 30);
    floodfill(100, 100, YELLOW);

    
    setcolor(BROWN);
    rectangle(200, 300, 230, 400); 
    floodfill(215, 350, BROWN);
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    fillellipse(215, 250, 50, 100);


    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    rectangle(400, 300, 600, 500); 
    floodfill(500, 400, LIGHTGRAY);
    setcolor(DARKGRAY);
    rectangle(450, 250, 550, 300); 
    floodfill(500, 275, DARKGRAY);

    
    setcolor(LIGHTGRAY);
    for (int i = 0; i < 3; ++i)
    {
        line(500, 200 - i * 20, 510 + rand() % 10, 200 - i * 20 - 20);
        delay(500);
        
    }



    getch();

    closegraph();
    
     return 0;
}
