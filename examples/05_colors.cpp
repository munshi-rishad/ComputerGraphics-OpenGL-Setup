// 5. Using colors: glColor3f(red, green, blue), each value from 0 to 1
#include <GL/glut.h>

void square(float x, float y)
{
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + 0.4f, y);
    glVertex2f(x + 0.4f, y + 0.4f);
    glVertex2f(x, y + 0.4f);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 0, 0);   // red
    square(-0.8f, 0.1f);

    glColor3f(0, 1, 0);   // green
    square(-0.2f, 0.1f);

    glColor3f(0, 0, 1);   // blue
    square(0.4f, 0.1f);

    // Different color on each corner makes a smooth color mix
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0); glVertex2f(0, -0.2f);
    glColor3f(0, 1, 0); glVertex2f(-0.5f, -0.8f);
    glColor3f(0, 0, 1); glVertex2f(0.5f, -0.8f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Colors");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
