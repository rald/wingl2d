#include "gl2d.h"

#define GAME_TITLE "GL2D Test"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

bool quit = false;

void setup(void) {
}

void loop(void) {
	clearScreen();
	drawLine(10, 10, 40, 40, 1, getSweetie(2));
	drawCircle(65, 25, 15, 32, 1, getSweetie(3));
	fillCircle(110, 25, 15, 32, getSweetie(4));
	drawRect(140, 10, 30, 30, 1, getSweetie(5));
	fillRect(185, 10, 30, 30, getSweetie(6));
	drawText(0, 64, "It's Alive!", 2, getSweetie(7));    
}

int main(void) {
	if (!gl2dInit(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE)) return -1;        
    setup();
    while (!quit) {
        loop();
        glfwSwapBuffers();
        quit = glfwGetKey(GLFW_KEY_ESC) == GLFW_PRESS || !glfwGetWindowParam(GLFW_OPENED);
    }
    glfwTerminate();
    return 0;
}


