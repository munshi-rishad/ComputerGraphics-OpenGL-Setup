// 6. Circle drawing using cos and sin
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

    glColor3f(1, 1, 0);
    circle(0, 0, 0.5f);

    glColor3f(0, 0.6f, 1);
    circle(0.6f, 0.6f, 0.2f);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Circle");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
