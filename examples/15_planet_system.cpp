// 15. Planet system: a planet goes around the sun and a moon goes around the planet
#include <GL/glut.h>
#include <cmath>

float angle = 0;

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

    glColor3f(1, 0.8f, 0);
    circle(0, 0, 0.15f);                 // sun in the center

    glPushMatrix();
    glRotatef(angle, 0, 0, 1);           // 1. turn around the sun
    glTranslatef(0.6f, 0, 0);            // 2. move out to the orbit distance
    glColor3f(0, 0.5f, 1);
    circle(0, 0, 0.07f);                 // planet

    glRotatef(angle * 3, 0, 0, 1);       // moon turns faster around the planet
    glTranslatef(0.15f, 0, 0);
    glColor3f(0.8f, 0.8f, 0.8f);
    circle(0, 0, 0.03f);                 // moon
    glPopMatrix();

    glutSwapBuffers();
}

void update(int value)
{
    angle += 1;
    if (angle >= 360)
        angle = 0;

    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);   // double buffer = smooth animation
    glutInitWindowSize(500, 500);
    glutCreateWindow("Planet System");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutTimerFunc(30, update, 0);
    glutMainLoop();
    return 0;
}
