#include <GL/freeglut.h>
#include <iostream>

using namespace std;

void Draw()
{
	glClearColor(1.00f,0.00f,0.00f,1.00f);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

const string nameMainWindow = "janela vermelha";

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(100,150);
	//sets the image properties of the images
	
	glutCreateWindow(nameMainWindow.c_str());
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,500);

	glutDisplayFunc(Draw);

	glutMainLoop();
	return 0;

}




