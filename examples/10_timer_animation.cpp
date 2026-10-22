// 10. Timer animation: a square that keeps rotating
#include <GL/glut.h>

float angle = 0;

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
    glRotatef(angle, 0, 0, 1);
    glColor3f(1, 1, 0);
    drawSquare();
    glPopMatrix();

    glutSwapBuffers();   // with GLUT_DOUBLE use this instead of glFlush()
}

// Runs every 30 ms
void update(int value)
{
    angle += 2;
    if (angle >= 360)
        angle = 0;

    glutPostRedisplay();             // draw again
    glutTimerFunc(30, update, 0);    // call update again after 30 ms
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);   // double buffer = smooth animation
    glutInitWindowSize(500, 500);
    glutCreateWindow("Timer Animation");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutTimerFunc(30, update, 0);
    glutMainLoop();
    return 0;
}
