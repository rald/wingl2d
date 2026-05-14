#include "gl2d.h"

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GAME_TITLE "GL2D Test"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

bool quit = false;

float x, y;

float tx,ty;
float tdx,tdy;
float speed;



void setup(void) {
    tx=(SCREEN_WIDTH-11*8*2)/2;
    ty=(SCREEN_HEIGHT-8*2)/2;
    speed=3;
    tdx=speed;
    tdy=speed;    
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
    
    drawText(tx, ty, "Hello World", 2.0f, gl2d_color(255, 255, 255, 255));
    
    tx+=tdx;
	ty+=tdy;

    if(tx<0) { tx=0; tdx=speed; }
    if(tx>SCREEN_WIDTH-11*8*2) { tx=SCREEN_WIDTH-11*8*2; tdx=-speed; }
    
    if(ty<0) { ty=0; tdy=speed; }
    if(ty>SCREEN_HEIGHT-8*2) { ty=SCREEN_HEIGHT-8*2; tdy=-speed; }
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
