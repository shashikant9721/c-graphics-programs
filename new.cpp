#include <graphics.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DROPS 200

struct RainDrop {
    int x, y, speed;
};

void drawScenery() {
    setcolor(LIGHTBLUE);
    rectangle(0, 0, getmaxx(), getmaxy());
    floodfill(1, 1, LIGHTBLUE);

    setcolor(GREEN);
    rectangle(0, getmaxy() / 2, getmaxx(), getmaxy());
    floodfill(1, getmaxy() / 2 + 1, GREEN);
}

void drawRainDrops(struct RainDrop *drops, int numDrops) {
    for (int i = 0; i < numDrops; i++) {
        setcolor(BLUE);
        line(drops[i].x, drops[i].y, drops[i].x, drops[i].y + 5);
    }
}

void updateRainDrops(struct RainDrop *drops, int numDrops) {
    for (int i = 0; i < numDrops; i++) {
        drops[i].y += drops[i].speed;
        if (drops[i].y >= getmaxy() / 2) {
            drops[i].y = 0;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    srand(time(NULL));

    struct RainDrop drops[MAX_DROPS];
    for (int i = 0; i < MAX_DROPS; i++) {
        drops[i].x = rand() % getmaxx();
        drops[i].y = rand() % (getmaxy() / 2);
        drops[i].speed = rand() % 10 + 1;
    }

    while (!kbhit()) {
        cleardevice();

        drawScenery();
        drawRainDrops(drops, MAX_DROPS);
        updateRainDrops(drops, MAX_DROPS);

        delay(50); // Adjust the speed of animation
    }

    closegraph();
    return 0;
}
