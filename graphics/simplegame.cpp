#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = SCREEN_WIDTH / 2;   // Initial x-coordinate of the character
    int y = SCREEN_HEIGHT / 2;  // Initial y-coordinate of the character

    while (1) {
        if (kbhit()) {
            char ch = getch();
            if (ch == 27)  // ASCII code for ESC key
                break;
            else if (ch == 75)  // ASCII code for left arrow key
                x -= 10;
            else if (ch == 77)  // ASCII code for right arrow key
                x += 10;
            else if (ch == 72)  // ASCII code for up arrow key
                y -= 10;
            else if (ch == 80)  // ASCII code for down arrow key
                y += 10;
        }

        cleardevice();  // Clear the screen
        circle(x, y, 20);  // Draw the character
        delay(100);  // Delay for smooth animation
    }

    closegraph();
    return 0;
}
