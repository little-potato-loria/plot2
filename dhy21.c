#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#define bl 1
#define roup 1
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.27, 2.02, 7.4, 14.1); 
}
void drawString(float x, float y, const char* string, void* font) {
    glRasterPos2f(x, y);
    while (*string) { 
        glutBitmapCharacter(font, *string++); 
    }
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); 
    glBegin(GL_LINES);
    glVertex2f(-1.25, 8);
    glVertex2f(2,8);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(-1, 7.5);
    glVertex2f(-1, 14);
    glEnd();
    for (int j = -1; j < 2; j++) {
        glBegin(GL_LINES);
        glVertex2f(j , 7.7);
        glVertex2f(j , 8);
        glEnd();
        char buffer[3], ui[3] = { "10" };
        snprintf(buffer,sizeof(buffer), "%d", j);
        drawString(j + 0.04, 7.64, buffer, GLUT_BITMAP_HELVETICA_12);
        drawString(j-0.08, 7.55, ui, GLUT_BITMAP_HELVETICA_18);
        for (int i = 2; i < 10; i++) {
            glBegin(GL_LINES);
            glVertex2f(j+log10(i), 7.85);
            glVertex2f(j+log10(i), 8);
            glEnd();
        }
    }
    for (int j = 8; j < 14; j++) {
        glBegin(GL_LINES);
        glVertex2f(-1.125, j );
        glVertex2f(-1, j );
        glEnd();
        char buffer[3], ui[3] = { "10" };
        snprintf(buffer, sizeof(buffer), "%d", j);
        drawString(-1.13,j, buffer, GLUT_BITMAP_HELVETICA_12);
        drawString(-1.25,j-0.15, ui, GLUT_BITMAP_HELVETICA_18);
        for (int i = 2; i < 10; i++) {
            glBegin(GL_LINES);
            glVertex2f(-1.07,j + log10(i));
            glVertex2f(-1,j + log10(i));
            glEnd();
        }
    }
    glColor3f(1.0, 0.0, 0.0); 
    glBegin(GL_LINE_STRIP);
    for (float x = -1; x <= 2.5; x += 0.1) {
        glVertex2f(x, log10(2*pow(bl,0.33333333333334))+11+x);
    }
    glEnd();
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (float x = -1; x <= 2.5; x += 0.1) {
        glVertex2f(x, log10(4 * bl) + 10 + x/2);
    }
    glEnd();
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_STRIP);
    for (float x = -1; x <= 2.5; x += 0.1) {
        glVertex2f(x, log10(4.16) + 9 + x *11/4);
    }
    glEnd();
    glColor3f(0.5, 0.5, 0.0);
    glBegin(GL_LINE_STRIP);
    for (float x = -1; x <= 2.5; x += 0.1) {
        glVertex2f(x, 8.517610768528308-0.5*x+0.6666666666666667*log10(bl)+ log10(roup)/6);
    }
    glEnd();
    glColor3f(0.5, 0.0, 0.5);
    glBegin(GL_LINE_STRIP);
    for (float x = -1; x <= 2.5; x += 0.1) {
        glVertex2f(x, 9.68310737804902 + 0.6666666666666667 * log10(bl) + log10(roup)/6);
    }
    glEnd();
    glColor3f(0.0, 0.5, 0.5);
    glBegin(GL_LINE_STRIP);
    for (float x = -1; x <= 2.5; x += 0.1) {
        glVertex2f(x, 10.267610768528308 +0.25*x+ 0.6666666666666667 * log10(bl) + log10(roup) / 6);
    }
    glEnd();
    glFlush();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("made by dhy");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

