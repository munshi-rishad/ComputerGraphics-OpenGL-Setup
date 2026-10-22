// 2. Line drawing: a horizontal and a vertical line
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(3);
    glColor3f(1, 1, 1);

    glBegin(GL_LINES);        // every 2 points make one line
    glVertex2f(-0.5, 0);
    glVertex2f(0.5, 0);

    glVertex2f(0, -0.5);
    glVertex2f(0, 0.5);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Line");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
