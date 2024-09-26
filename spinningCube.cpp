#include <GL/freeglut.h>
#include <iostream>

using namespace std;

GLfloat T = 0;

void Spin()
{
	T = T+0.05;
	if (T >= 360)
		T = 0;
	glutPostRedisplay();
}

void initCalors()
{
	glClearColor(0.5f, 0.5f, 0.0f, 1.00f); //specifies the color of the screen
	//glColor4f(1.00f,0.00f,0.00f, 0.50f); //specifies the color of the objects
	glEnable(GL_DEPTH_TEST);
}

void Face(GLfloat A[],GLfloat B[],GLfloat C[],GLfloat D[])
{
	glBegin(GL_POLYGON);
		glVertex3fv(A);
		glVertex3fv(B);
		glVertex3fv(C);
		glVertex3fv(D);
	glEnd();
}

void Cube(GLfloat V0[],GLfloat V1[],GLfloat V2[],GLfloat V3[],GLfloat V4[],GLfloat V5[],GLfloat V6[],GLfloat V7[])
{
	glColor3f(1,0,0);
	Face(V0, V1, V2, V3);

	glColor3f(0,1,0);
	Face(V4, V5, V6, V7);

	glColor3f(0,0.25,0.25);
	Face(V0, V3, V7, V4);

	glColor3f(1,1,1);
	Face(V1, V2, V6, V5);

	glColor3f(0.0,0.0,0.0);
	Face(V0, V1, V5, V4);

	glColor3f(0.3,0.5,0);
	Face(V3, V2, V6, V7);

	//glColor3f(0,1,0);
	//Face(V4, V5, V6, V7);

	glutSwapBuffers();
}

void Draw()
{
	GLfloat V [8][3] =
	{
		{-0.5,0.5,0.5},
		{0.5,0.5,0.5},
		{0.5,-0.5,0.5},
		{-0.5,-0.5,0.5},

		{-0.5,0.5,-0.5},
		{0.5,0.5,-0.5},
		{0.5,-0.5,-0.5},
		{-0.5,-0.5,-0.5}
	};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //3° TEM QUE LIMPAR O DEPTH BUFFER TBM
	glPointSize(5);

	glLoadIdentity();
	glRotatef(T,1,1,0);
	Cube(V[0],V[1],V[2],V[3],V[4],V[5],V[6],V[7]);
	//glutSwapBuffers();
	glFlush();
}

const string nameMainWindow = "Spinning cube"; //2°

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); //1°
	glutInitWindowPosition(100,150);
	glutCreateWindow(nameMainWindow.c_str());
	glutInitWindowSize(600,1350);
	
	initCalors();
	Draw();	
//glutDisplayFunc(Draw);
	glutIdleFunc(Spin);//

	glutMainLoop();
	return 0;
}
