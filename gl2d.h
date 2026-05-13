#ifndef GL2D_H
#define GL2D_H

#include "glfw.h"

typedef unsigned char byte;

typedef struct {
    byte r, g, b, a;
} GL2D_Color;

int gl2dInit(int width, int height, const char* title);
GL2D_Color gl2d_color(byte r, byte g, byte b, byte a);
void clearScreen(GL2D_Color color);

void drawPoint(float x, float y, float size, GL2D_Color color);
void drawLine(float x1, float y1, float x2, float y2, float width, GL2D_Color color);
void drawRect(float x, float y, float w, float h, float lineWidth, GL2D_Color color);
void fillRect(float x, float y, float w, float h, GL2D_Color color);
void drawCircle(float cx, float cy, float radius, int segments, float lineWidth, GL2D_Color color);
void fillCircle(float cx, float cy, float radius, int segments, GL2D_Color color);

void drawChar(float x, float y, char c, float scale, GL2D_Color color);
void drawText(float x, float y, const char* text, float scale, GL2D_Color color);

#endif
