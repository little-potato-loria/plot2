#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#define ka 0.1
#define roup 1
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.27, 2.02, -6, 1); 
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
    glVertex2f(-1.25, -5.5);
    glVertex2f(2,-5.5);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(-1, -6);
    glVertex2f(-1, 2);
    glEnd();
    for (int j = -2; j < 2; j++) {
        glBegin(GL_LINES);
        glVertex2f(j , -5.75);
        glVertex2f(j , -5.5);
        glEnd();
        char buffer[3], ui[3] = { "10" };
        snprintf(buffer,sizeof(buffer), "%d", j);
        drawString(j + 0.04, -5.7, buffer, GLUT_BITMAP_HELVETICA_12);
        drawString(j-0.08, -5.9, ui, GLUT_BITMAP_HELVETICA_18);
        for (int i = 2; i < 10; i++) {
            glBegin(GL_LINES);
            glVertex2f(j+log10(i), -5.65);
            glVertex2f(j+log10(i), -5.5);
            glEnd();
        }
    }
    for (int j = -5; j < 2; j++) {
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
    glColor3f(0.0, 0.0, 0.0); 
    glBegin(GL_LINES);
    glVertex2f(-1.25, 0);
    glVertex2f(2, 0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    for (float x = -1; x <= 2.5; x += 0.1) {
        glVertex2f(x, -3.4259687322722811-0.5*log10(roup)-1.5*x);
    }
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (float x = 2.5; x >= -0.1212736085078122+0.3333333333333333*log10(ka)-0.1666666666666667*log10(roup); x -= 0.01) {
        glVertex2f(x, -3.0621479067488445 - log10(ka)+ 1.5 * x);
    }
    glEnd();
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (float x = 2.5; x >= 0.3274699789910593634 + 0.3333333333333333 * log10(ka) - 0.1666666666666667 * log10(roup); x -= 0.01) {
        glVertex2f(x, -2.079737969775666 +0.5* log10(roup) - 1.5 * x);
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

