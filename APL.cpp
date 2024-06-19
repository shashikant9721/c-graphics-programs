#include <graphics.h>
#include <conio.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const int PADDLE_WIDTH = 20;
const int PADDLE_HEIGHT = 100;

const int BALL_SIZE = 20;

const int PADDLE_SPEED = 10;

int ballSpeedX = 5;
int ballSpeedY = 5;

void drawPaddle(int x, int y) {
    bar(x, y, x + PADDLE_WIDTH, y + PADDLE_HEIGHT);
}

void drawBall(int x, int y) {
    fillellipse(x, y, BALL_SIZE / 2, BALL_SIZE / 2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int leftPaddleX = 50;
    int leftPaddleY = (SCREEN_HEIGHT / 2) - (PADDLE_HEIGHT / 2);
    int rightPaddleX = SCREEN_WIDTH - 50 - PADDLE_WIDTH;
    int rightPaddleY = (SCREEN_HEIGHT / 2) - (PADDLE_HEIGHT / 2);
    int ballX = SCREEN_WIDTH / 2;
    int ballY = SCREEN_HEIGHT / 2;

    int quit = 0;

    while (!quit) {
        if (kbhit()) {
            switch (getch()) {
                case 'w':
                    leftPaddleY -= PADDLE_SPEED;
                    break;
                case 's':
                    leftPaddleY += PADDLE_SPEED;
                    break;
                case KEY_UP:
                    rightPaddleY -= PADDLE_SPEED;
                    break;
                case KEY_DOWN:
                    rightPaddleY += PADDLE_SPEED;
                    break;
                case 27:
                    quit = 1;
                    break;
            }
        }

        ballX -= ballSpeedX;
        ballY -= ballSpeedY;

        if (ballY <= 0 || ballY >= SCREEN_HEIGHT) {
            ballSpeedY = -ballSpeedY;
        }

        if ((ballX - BALL_SIZE / 2 <= leftPaddleX + PADDLE_WIDTH && ballY >= leftPaddleY && ballY <= leftPaddleY + PADDLE_HEIGHT) ||
            (ballX + BALL_SIZE / 2 >= rightPaddleX && ballY >= rightPaddleY && ballY <= rightPaddleY + PADDLE_HEIGHT)) {
            ballSpeedX = -ballSpeedX;
        }

        if (ballX <= 0 || ballX >= SCREEN_WIDTH) {
            ballX = SCREEN_WIDTH / 2;
            ballY = SCREEN_HEIGHT / 2;
        }

        cleardevice();

        drawPaddle(leftPaddleX, leftPaddleY);
        drawPaddle(rightPaddleX, rightPaddleY);
        drawBall(ballX, ballY);

        delay(30);
    }

    closegraph();
    return 0;
}