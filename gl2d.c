#include "gl2d.h"
#include "font8x8.h"

#include <math.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

int gl2dInit(int width, int height, const char* title) {
    if (!glfwInit()) return 0;

    // GLFW 2.7.9 window creation
    if (!glfwOpenWindow(width, height, 8, 8, 8, 8, 0, 0, GLFW_WINDOW)) {
        glfwTerminate();
        return 0;
    }

    glfwSetWindowTitle(title);

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    return 1;
}

GL2D_Color gl2d_color(byte r, byte g, byte b, byte a) {
    return (GL2D_Color){r, g, b, a};
}

void clearScreen(GL2D_Color color) {
    glClearColor(color.r/255.0f, color.g/255.0f, color.b/255.0f, color.a/255.0f);
    glClear(GL_COLOR_BUFFER_BIT); // Fixed typo here
}

void drawPoint(float x, float y, float size, GL2D_Color color) {
    glPointSize(size);
    glColor4ub(color.r, color.g, color.b, color.a);
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
}

void drawLine(float x1, float y1, float x2, float y2, float width, GL2D_Color color) {
    glLineWidth(width);
    glColor4ub(color.r, color.g, color.b, color.a);
    glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    glEnd();
}

void drawRect(float x, float y, float w, float h, float lineWidth, GL2D_Color color) {
    glLineWidth(lineWidth);
    glColor4ub(color.r, color.g, color.b, color.a);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x, y + h);
    glEnd();
}

void fillRect(float x, float y, float w, float h, GL2D_Color color) {
    glColor4ub(color.r, color.g, color.b, color.a);
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x, y + h);
    glEnd();
}

void drawCircle(float cx, float cy, float radius, int segments, float lineWidth, GL2D_Color color) {
    glLineWidth(lineWidth);
    glColor4ub(color.r, color.g, color.b, color.a);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * M_PI * (float)i / (float)segments;
        glVertex2f(cx + radius * cosf(theta), cy + radius * sinf(theta));
    }
    glEnd();
}

void fillCircle(float cx, float cy, float radius, int segments, GL2D_Color color) {
    glColor4ub(color.r, color.g, color.b, color.a);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= segments; i++) {
        float theta = 2.0f * M_PI * (float)i / (float)segments;
        glVertex2f(cx + radius * cosf(theta), cy + radius * sinf(theta));
    }
    glEnd();
}

void drawChar(float x, float y, char c, float scale, GL2D_Color color) {
    // Cast char to unsigned to index the font array safely
    unsigned char uc = (unsigned char)c;
    if (uc > 127) uc = 0;

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            // Check if the bit for this pixel is set
            // LSB is the leftmost pixel (col 0)
            if (font8x8_basic[uc][row] & (1 << col)) {
                // Use fillRect to support scaling (e.g., scale=2.0f makes it 16x16)
                fillRect(x + col * scale, y + row * scale, scale, scale, color);
            }
        }
    }
}

void drawText(float x, float y, const char* text, float scale, GL2D_Color color) {
    while (*text) {
        drawChar(x, y, *text, scale, color);
        x += 8 * scale; // Move cursor right by 8 pixels * scale
        text++;
    }
}
