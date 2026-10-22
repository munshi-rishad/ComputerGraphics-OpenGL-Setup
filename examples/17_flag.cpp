// 17. Flag drawing: the flag of Bangladesh (green rectangle + red circle)
#include <GL/glut.h>
#include <cmath>

// Draws a filled circle with center (cx, cy) and radius r
void circle(float cx, float cy, float r)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float a = i * 3.1416f / 180;    // degree to radian
        glVertex2f(cx + r * cos(a), cy + r * sin(a));
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Green field, size 10 : 6
    glColor3f(0.0f, 0.42f, 0.31f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.75f, -0.45f);
    glVertex2f(0.75f, -0.45f);
    glVertex2f(0.75f, 0.45f);
    glVertex2f(-0.75f, 0.45f);
    glEnd();

    // Red circle, a little to the left of the center
    glColor3f(0.96f, 0.16f, 0.25f);
    circle(-0.075f, 0, 0.3f);

    // Flag pole
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.8f, -0.9f);
    glVertex2f(-0.75f, -0.9f);
    glVertex2f(-0.75f, 0.45f);
    glVertex2f(-0.8f, 0.45f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Flag");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
