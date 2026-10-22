// 11. Keyboard input: arrow keys move the square, R resets it, Esc closes
#include <GL/glut.h>
#include <cstdlib>

float posX = 0, posY = 0;

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
    glTranslatef(posX, posY, 0);
    glColor3f(0, 1, 0.5f);
    drawSquare();
    glPopMatrix();

    glutSwapBuffers();
}

// Normal keys (letters, numbers, Esc)
void keyboard(unsigned char key, int x, int y)
{
    if (key == 'r' || key == 'R')
    {
        posX = 0;
        posY = 0;
    }
    if (key == 27)    // Esc
        exit(0);

    glutPostRedisplay();
}

// Special keys (arrows, F1...)
void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_LEFT)  posX -= 0.05f;
    if (key == GLUT_KEY_RIGHT) posX += 0.05f;
    if (key == GLUT_KEY_UP)    posY += 0.05f;
    if (key == GLUT_KEY_DOWN)  posY -= 0.05f;

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Keyboard Input");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
