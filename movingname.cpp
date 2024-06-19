#include <graphics.h>
#include <conio.h>

void drawText(int x, int y) {
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(x, y, "SHASHIKANT");
}

void animateText() {
    int x = 0, y = getmaxy() / 2;

    while (!kbhit()) {
        cleardevice();
        drawText(x, y);
        delay(100);
        x += 10;
        if (x > getmaxx()) {
            x = 0;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    animateText();

    getch();
    closegraph();
    return 0;
}