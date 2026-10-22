// 16. Collision check: move the green box with the arrow keys.
// It turns red when it touches the white box.
#include <GL/glut.h>

float playerX = -0.8f, playerY = -0.1f, playerSize = 0.2f;
float objectX = 0.2f, objectY = -0.2f, objectW = 0.3f, objectH = 0.4f;
bool collision = false;

void rect(float x, float y, float w, float h)
{
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glVertex2f(x, y + h);
    glEnd();
}

// Two boxes touch when they overlap on both the x and the y axis
void checkCollision()
{
    collision = playerX < objectX + objectW &&
                playerX + playerSize > objectX &&
                playerY < objectY + objectH &&
                playerY + playerSize > objectY;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1);
    rect(objectX, objectY, objectW, objectH);

    if (collision)
        glColor3f(1, 0, 0);   // red when touching
    else
        glColor3f(0, 1, 0);   // green otherwise
    rect(playerX, playerY, playerSize, playerSize);

    glutSwapBuffers();
}

void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_LEFT)  playerX -= 0.05f;
    if (key == GLUT_KEY_RIGHT) playerX += 0.05f;
    if (key == GLUT_KEY_UP)    playerY += 0.05f;
    if (key == GLUT_KEY_DOWN)  playerY -= 0.05f;

    checkCollision();
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Collision Check");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
