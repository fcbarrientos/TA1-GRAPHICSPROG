/*
    CS0045 - Technical Assessment 1
    OpenGL Starter Program
    Coverage: Modules 1-4

    This starter program is intentionally PARTIALLY COMPLETED.

    Already provided:
    - GLUT initialization
    - Window creation
    - Working display() function
    - One basic graphical object (triangle)
    - Program structure that should compile before modification

    STUDENT TASKS:
    1. Add at least two additional visible objects.
    2. Use at least two different OpenGL primitive types.
    3. Use at least three different colors.
    4. Convert one object to vertex-array rendering.
    5. Add one keyboard interaction using glutKeyboardFunc().
    6. Add short on-screen instructions using GLUT bitmap text.
*/

#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>

using namespace std;
float triangleX = 0.0f;
float triangleY = 0.0f;
bool changeColor = false;

// ------------------------------------------------------------
// Function Prototypes
// ------------------------------------------------------------
void display();
void keyboard(unsigned char key, int x, int y);

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("CS0045 - Technical Assessment 1");

    // Already completed:
    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}

// ------------------------------------------------------------
// STARTER OBJECT
// ------------------------------------------------------------
void drawStarterTriangle()
{
    glPushMatrix();

    glTranslatef(triangleX, triangleY, 0.0f);

    if (changeColor)
    {
        glColor3f(1.0f, 0.0f, 1.0f); // Magenta
    }
    else
    {
        glColor3f(0.0f, 0.8f, 0.2f); // Original green
    }

    glBegin(GL_TRIANGLES);

        glVertex2f(0.0f,  0.60f);
        glVertex2f(-0.60f, -0.40f);
        glVertex2f(0.60f, -0.40f);

    glEnd();

    glPopMatrix();
}

// ------------------------------------------------------------
// REQUIREMENT 2: VERTEX ARRAY OBJECT - ALEI
// ------------------------------------------------------------
void drawVertexArrayObject()
{
    // Object 4
    GLfloat vertices[] = {
        0.5f,  0.8f,
        0.8f, 0.8f,
        0.8f, 0.5f,
        0.5f, 0.5f
    };

    GLfloat colors[] = {
        1.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 0.0f,
        1.0f, 0.5f, 0.0f,
        1.0f, 0.5f, 0.0f,
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawArrays(GL_QUADS, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

// ------------------------------------------------------------
// DISPLAY CALLBACK
// ------------------------------------------------------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Already completed:
    drawStarterTriangle();

    // ------------------------------------------------------------
    // REQUIREMENT 1: ADD TWO ADDITIONAL VISIBLE OBJECTS - CHESKA
    // ------------------------------------------------------------
    // Object 2
    glColor3f(0.2f, 0.4f, 1.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.4f, 1.0f);
    glVertex2f(-0.65f,  0.75f);
    glVertex2f(-0.48f,  0.65f);
    glVertex2f(-0.48f,  0.45f);
    glColor3f(0.6f, 0.2f, 1.0f);
    glVertex2f(-0.65f,  0.35f);
    glVertex2f(-0.82f,  0.45f);
    glVertex2f(-0.82f,  0.65f);
    glEnd();
    // Object 3
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.68f, -0.61f);
    glColor3f(1.0f, 0.2f, 0.2f);
    glVertex2f(0.50f, -0.61f);
    glColor3f(1.0f, 0.7f, 0.1f);
    glVertex2f(0.54f, -0.52f);
    glColor3f(0.2f, 0.8f, 0.3f);
    glVertex2f(0.68f, -0.47f);
    glColor3f(0.2f, 0.6f, 1.0f);
    glVertex2f(0.82f, -0.52f);
    glColor3f(0.7f, 0.3f, 1.0f);
    glVertex2f(0.86f, -0.61f);
    glColor3f(1.0f, 0.2f, 0.2f);
    glVertex2f(0.68f, -0.61f);
    glEnd();

    // Requirement 2: Function call - ALEI
    drawVertexArrayObject();

    // Requirement 4: On-screen instructions - SILVA
    const unsigned char instructionText[] = "WASD - Move | C - Color | R - Reset";
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.95f, -0.90f);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, instructionText);

    glFlush();
}

// ------------------------------------------------------------
// Requirement 3: KEYBOARD CALLBACK - SIMON
// ------------------------------------------------------------
void keyboard(unsigned char key, int x, int y)
{
    if (key == 27)   // ESC key
    {
        exit(0);
    }
    else if (key == 'a' || key == 'A')
    {
        triangleX -= 0.1f;
    }
    else if (key == 'd' || key == 'D')
    {
        triangleX += 0.1f;
    }
    else if (key == 'w' || key == 'W')
    {
        triangleY += 0.1f;
    }
    else if (key == 's' || key == 'S')
    {
        triangleY -= 0.1f;
    }
    else if (key == 'c' || key == 'C')
    {
        changeColor = !changeColor;
    }
    else if (key == 'r' || key == 'R')
    {
        triangleX = 0.0f;
        triangleY = 0.0f;
    }

    glutPostRedisplay();
}
