#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100
#define DELAY 100

int snakeX[MAX_LENGTH], snakeY[MAX_LENGTH];
int length = 5;
int foodX, foodY;
int direction = 0; // 0: right, 1: down, 2: left, 3: up

void initGame() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    for (int i = 0; i < length; i++) {
        snakeX[i] = 20 - i * 10;
        snakeY[i] = 20;
    }

    srand(time(0));
    foodX = (rand() % (getmaxx() / 10)) * 10;
    foodY = (rand() % (getmaxy() / 10)) * 10;
}

void drawSnake() {
    for (int i = 0; i < length; i++) {
        rectangle(snakeX[i], snakeY[i], snakeX[i] + 10, snakeY[i] + 10);
        floodfill(snakeX[i] + 5, snakeY[i] + 5, WHITE);
    }
}

void drawFood() {
    rectangle(foodX, foodY, foodX + 10, foodY + 10);
    floodfill(foodX + 5, foodY + 5, WHITE);
}

void updateSnake() {
    for (int i = length - 1; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }

    if (direction == 0) snakeX[0] += 10;
    if (direction == 1) snakeY[0] += 10;
    if (direction == 2) snakeX[0] -= 10;
    if (direction == 3) snakeY[0] -= 10;
}

int checkCollision() {
    if (snakeX[0] < 0 || snakeX[0] >= getmaxx() || snakeY[0] < 0 || snakeY[0] >= getmaxy()) {
        return 1;
    }

    for (int i = 1; i < length; i++) {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
            return 1;
        }
    }

    if (snakeX[0] == foodX && snakeY[0] == foodY) {
        length++;
        foodX = (rand() % (getmaxx() / 10)) * 10;
        foodY = (rand() % (getmaxy() / 10)) * 10;
    }

    return 0;
}

int main() {
    initGame();

    while (1) {
        if (kbhit()) {
            char ch = getch();
            if (ch == 0) ch = getch();
            if (ch == 72 && direction != 1) direction = 3; // Up
            if (ch == 80 && direction != 3) direction = 1; // Down
            if (ch == 75 && direction != 0) direction = 2; // Left
            if (ch == 77 && direction != 2) direction = 0; // Right
        }

        updateSnake();

        if (checkCollision()) {
            outtextxy(getmaxx() / 2, getmaxy() / 2, "Game Over");
            break;
        }

        cleardevice();
        drawFood();
        drawSnake();
        delay(DELAY);
    }

    getch();
    closegraph();
    return 0;
}