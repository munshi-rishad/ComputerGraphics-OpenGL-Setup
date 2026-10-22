// 13. Bresenham line algorithm: uses only integers, works for every direction
#include <GL/glut.h>
#include <cstdlib>

void bresenhamLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;   // step direction in x
    int sy = (y1 < y2) ? 1 : -1;   // step direction in y
    int err = dx - dy;             // decision value

    int x = x1;
    int y = y1;

    glBegin(GL_POINTS);
    while (true)
    {
        glVertex2i(x, y);
        if (x == x2 && y == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)   // move in x
        {
            err -= dy;
            x += sx;
        }
        if (e2 < dx)    // move in y
        {
            err += dx;
            y += sy;
        }
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 0);

    bresenhamLine(50, 50, 450, 300);    // gentle slope
    bresenhamLine(100, 450, 300, 50);   // steep, going down
    bresenhamLine(450, 450, 50, 400);   // right to left

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Line");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Use pixel coordinates: (0, 0) bottom-left, (500, 500) top-right
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
