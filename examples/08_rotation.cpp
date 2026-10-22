// 8. Rotation: turn an object with glRotatef(angle, 0, 0, 1)
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
    drawSquare();                 // not rotated (gray)

    glPushMatrix();
    glRotatef(45, 0, 0, 1);       // rotate 45 degrees around the Z axis
    glColor3f(1, 0.5f, 0);
    drawSquare();                 // rotated square (orange)
    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotation");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
