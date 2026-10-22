// 7. Translation: move an object with glTranslatef
#include <GL/glut.h>

// A small square around the center (0, 0)
void drawSquare()
{
    glBegin(GL_POLYGON);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.5f, 0.5f, 0.5f);
    drawSquare();                 // original position (gray)

    glPushMatrix();               // save the current position
    glTranslatef(0.5f, 0.3f, 0);  // move right 0.5 and up 0.3
    glColor3f(0, 1, 0);
    drawSquare();                 // moved square (green)
    glPopMatrix();                // go back, so other objects are not moved

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Translation");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
