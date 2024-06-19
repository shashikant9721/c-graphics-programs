#include <graphics.h>
#include <time.h>
#include <stdio.h>

void displayTime(int x, int y, int color) {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 80, "%H:%M:%S", timeinfo);

    setcolor(color);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
    outtextxy(x, y, buffer);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    while (!kbhit()) {
        cleardevice();
        displayTime(200, 200, WHITE);
        delay(1000); // Update every second
    }

    closegraph();
    return 0;
}