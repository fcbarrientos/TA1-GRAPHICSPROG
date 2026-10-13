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

    // TODO:
    // Register your keyboard callback here.
    //
    // Example:
    // glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}

// ------------------------------------------------------------
// STARTER OBJECT
// ------------------------------------------------------------
void drawStarterTriangle()
{
    // This object is already completed.
    // You may keep it or use it as reference.

    glColor3f(0.0f, 0.8f, 0.2f);

    glBegin(GL_TRIANGLES);

        glVertex2f(0.0f,  0.60f);
        glVertex2f(-0.60f, -0.40f);
        glVertex2f(0.60f, -0.40f);

    glEnd();
}

// ------------------------------------------------------------
// REQUIREMENT 2: VERTEX ARRAY OBJECT
// ------------------------------------------------------------
void drawVertexArrayObject()
{
    glColor3f(1.0f, 1.0f, 0.0f);

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

    /*
    ============================================================
                       STUDENT WORK AREA
    ============================================================

    Add the rest of your scene here.

    REQUIREMENTS:

    Object 2
    ----------
    Add another graphical object using an appropriate
    OpenGL primitive.

    Object 3
    ----------
    Add another graphical object using another primitive
    type and another color.

    Vertex Array
    ------------
    At least one object must use vertex-array rendering.

    Suggested functions:

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(...);
        glDrawArrays(...);
        glDisableClientState(GL_VERTEX_ARRAY); 
    */
   
    //Requirement 2: Function call - ALEI
   drawVertexArrayObject();
    
    /*
    Text
    ----
    Display a short instruction in the window.

    Suggested functions:

        glRasterPos2f(...);
        glutBitmapString(...);

    Keyboard
    --------
    Implement one meaningful keyboard interaction.

    Use:

        glutKeyboardFunc(keyboard);

    and call:

        glutPostRedisplay();

    when a keyboard action changes something visible.

    ============================================================
    */

    glFlush();
}

// ------------------------------------------------------------
// KEYBOARD CALLBACK
// ------------------------------------------------------------
void keyboard(unsigned char key, int x, int y)
{
    /*
        STUDENT WORK AREA

        Implement at least one meaningful keyboard interaction.

        Possible examples:

            'a' -> move an object left
            'd' -> move an object right
            'r' -> reset an object
            'c' -> change a color

        Example structure:

            if (key == 'r')
            {
                // Reset object
                glutPostRedisplay();
            }
    */

    (void)key;
    (void)x;
    (void)y;
}