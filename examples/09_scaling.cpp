// 9. Scaling: make an object bigger or smaller with glScalef
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

    glPushMatrix();
    glScalef(2, 2, 1);            // 2 times bigger in x and y
    glColor3f(0, 0.4f, 1);
    drawSquare();                 // big square (blue)
    glPopMatrix();

    glColor3f(1, 1, 1);
    drawSquare();                 // normal size (white)

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Scaling");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
