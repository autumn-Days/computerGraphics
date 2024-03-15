#include <GL/freeglut.h>
#include <iostream>
using namespace std;

string windowName = "redSquare";

void InitColors()
{
    glClearColor(1.00f, 0.00f, 0.00f, 0.00f);
    glColor4f(0.00f, 1.00f, 0.00f, 0.00f);
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5,0.5);
        glVertex2f(-0.5,-0.5);
        glVertex2f(0.5,-0.5);
        glVertex2f(0.5,0.5);
    glEnd();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    
    // Enable window resizing and double buffering
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

	glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 150);
    glutCreateWindow(windowName.c_str());

    // Register the display function
    InitColors();
    glutDisplayFunc(Draw);

    // Register the close function
    //glutCloseFunc(CloseWindow);

    // Enter the GLUT event processing loop
    glutMainLoop();

    return 0;
}
