// OpenGL starter file
// Write your drawing code inside display() and press F9 in Code::Blocks.
// More ready examples are in the "examples" folder of this repository:
// copy one of them here, replace everything, and run.
//
// Screen coordinates: x goes from -1 (left) to 1 (right),
//                     y goes from -1 (bottom) to 1 (top), (0, 0) is the center.

#include <GL/glut.h>
#include <cmath>

const float PI = 3.1416f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);   // clear the screen with the background color

    // Draw a white circle with radius 0.5 in the middle of the window
    glColor3f(1.0f, 1.0f, 1.0f);
    float r = 0.5f;

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float angle = i * PI / 180;   // degree to radian
        glVertex2f(r * cos(angle), r * sin(angle));
    }
    glEnd();

    glFlush();   // show the drawing
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL 64bit");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);   // black background
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
