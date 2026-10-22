// 14. Basic OpenGL program structure: start every new program from this
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // ---- write your drawing code here ----

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);                          // start GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // single buffer, RGB colors
    glutInitWindowSize(500, 500);                   // window size in pixels
    glutCreateWindow("OpenGL");                     // window title
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);           // background color (black)
    glutDisplayFunc(display);                       // function that draws
    glutMainLoop();                                 // keep the window open
    return 0;
}
