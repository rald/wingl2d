#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "gl2d.h"

#define GAME_TITLE "GL2D Testing"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define NBALLS 10

bool quit = false;

float x, y;

void setup(void) {
    
}

void loop(void) {
	clearScreen(gl2d_color(0x00, 0x00, 0x00, 0xFF));

    x = 10.0f; y = 10.0f;
    drawPoint(x + 16.0f, y + 16.0f, 1.0f, gl2d_color(255, 255, 255, 255));

    x += 32.0f + 10.0f;
    drawLine(x, y, x + 32.0f, y + 32.0f, 1.0f, gl2d_color(255, 255, 255, 255));

    x += 32.0f + 10.0f;
    drawRect(x, y, 32.0f, 32.0f, 1.0f, gl2d_color(255, 255, 255, 255));

    x += 32.0f + 10.0f;
    fillRect(x, y, 32.0f, 32.0f, gl2d_color(255, 255, 255, 255));

    x += 32.0f + 10.0f + 16.0f; y += 16.0f;
    drawCircle(x, y, 16.0f, 32.0f, 1.0f, gl2d_color(255, 255, 255, 255));

    x += 32.0f + 8.0f;
    fillCircle(x, y, 16.0f, 32.0f, gl2d_color(255, 255, 255, 255));    
    
    drawText(16.0f, 128.0f, "Hello World", 2.0f, gl2d_color(255, 255, 255, 255));
}

int main(void) {
	
	if (!gl2dInit(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE)) {
        return -1;
    }    
    
    setup();

    while (!quit) {

        loop();

        glfwSwapBuffers();

        // Check if ESC is pressed or window was closed
        quit = glfwGetKey(GLFW_KEY_ESC) == GLFW_PRESS || 
               !glfwGetWindowParam(GLFW_OPENED);
    }

    glfwTerminate();
    return 0;
}
