// 12. DDA line algorithm: draws a line pixel by pixel
#include <GL/glut.h>
#include <cmath>

void ddaLine(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    // Number of steps = the bigger of |dx| and |dy|
    float steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        glVertex2i(round(x), round(y));   // round to the nearest pixel
        x = x + xInc;
        y = y + yInc;
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);

    ddaLine(50, 50, 450, 300);    // gentle slope
    ddaLine(100, 450, 300, 50);   // steep, going down
    ddaLine(50, 250, 450, 250);   // horizontal

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA Line");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Use pixel coordinates: (0, 0) bottom-left, (500, 500) top-right
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
