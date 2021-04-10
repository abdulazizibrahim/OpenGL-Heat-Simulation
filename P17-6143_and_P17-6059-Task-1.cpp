//  Computer Graphics
//  Professor: Dr. Omar Osman Khan
//  Group Members:
//                Hassan Hussain Bokhari
//                P17-6059
//                Abdul Aziz Muhammad Ibrahim Isa
//                P17-6143
// Heat Simulation 

#define GL_SILENCE_DEPRECATION

#include "GL/glut.h"
#include <cmath>
#include <random>

GLfloat g = 0, b = 1, r = 0;
GLfloat Og = 0, Ob = 1, Or = 0;
GLfloat xt = 150, yt = 150;

void initgl()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0, 1.0); /* background colour */
	glColor3f(1.0, 0.0, 0.0);       /* foreground colour */
}

GLfloat angleCube = 0.0f;
GLfloat angleCube2 = 0.0f;

void display() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(angleCube2, 1.0f, 0.0f, 0.0f);
	glRotatef(angleCube, 0.0f, 1.0f, 0.0f);

	for (int x = -150; x < 150; x += 20)
	{
		glBegin(GL_QUADS);

		glColor3f(Or, Og, Ob);

		for (int y = -150; y < 150; y += 20) {
			for (int z = -150; z < 150; z += 20) {
				//Front
				glVertex3f(x, y, z);
				glVertex3f(x + 20, y, z);
				glVertex3f(x + 20, y + 20, z);
				glVertex3f(x, y + 20, z);

				//Right
				glVertex3f(x + 20, y, z);
				glVertex3f(x + 20, y, z + 20);
				glVertex3f(x + 20, y + 20, z + 20);
				glVertex3f(x + 20, y + 20, z);

				//Back
				glVertex3f(x, y, z + 20);
				glVertex3f(x + 20, y, z + 20);
				glVertex3f(x + 20, y + 20, z + 20);
				glVertex3f(x, y + 20, z + 20);

				//Left
				glVertex3f(x, y, z);
				glVertex3f(x, y + 20, z);
				glVertex3f(x, y + 20, z + 20);
				glVertex3f(x, y, z + 20);

				//Top
				glVertex3f(x, y + 20, z);
				glVertex3f(x, y + 20, z + 20);
				glVertex3f(x + 20, y + 20, z + 20);
				glVertex3f(x + 20, y + 20, z);

				//Bottom
				glVertex3f(x, y, z);
				glVertex3f(x, y, z + 20);
				glVertex3f(x + 20, y, z + 20);
				glVertex3f(x + 20, y, z);
			}
		}
	}
	for (int x = abs(xt)*-1; x < abs(xt); x += 20)
	{
		glBegin(GL_QUADS);

		glColor3f(r, g, b);

		for (int y = abs(yt)*-1; y < abs(yt); y += 20) {
			for (int z = -150; z < 150; z += 20) {
				//Front
				glVertex3f(x, y, z);
				glVertex3f(x + 20, y, z);
				glVertex3f(x + 20, y + 20, z);
				glVertex3f(x, y + 20, z);

				//Right
				glVertex3f(x + 20, y, z);
				glVertex3f(x + 20, y, z + 20);
				glVertex3f(x + 20, y + 20, z + 20);
				glVertex3f(x + 20, y + 20, z);

				//Back
				glVertex3f(x, y, z + 20);
				glVertex3f(x + 20, y, z + 20);
				glVertex3f(x + 20, y + 20, z + 20);
				glVertex3f(x, y + 20, z + 20);

				//Left
				glVertex3f(x, y, z);
				glVertex3f(x, y + 20, z);
				glVertex3f(x, y + 20, z + 20);
				glVertex3f(x, y, z + 20);

				//Top
				glVertex3f(x, y + 20, z);
				glVertex3f(x, y + 20, z + 20);
				glVertex3f(x + 20, y + 20, z + 20);
				glVertex3f(x + 20, y + 20, z);

				//Bottom
				glVertex3f(x, y, z);
				glVertex3f(x, y, z + 20);
				glVertex3f(x + 20, y, z + 20);
				glVertex3f(x + 20, y, z);
			}
		}
	}
	glEnd();
	glutSwapBuffers();
}

void keyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_RIGHT: {
		angleCube += 0.2f;
		break;
	}
	case GLUT_KEY_LEFT: {
		angleCube -= 0.2f;
		break;
	}
	case GLUT_KEY_UP: {
		angleCube2 += 0.2f;
		break;
	}
	case GLUT_KEY_DOWN: {
		angleCube2 -= 0.2f;
		break;
	}
	}
	glutPostRedisplay();
}

void reshape(GLsizei width, GLsizei height) {
	glOrtho(-300, 300, -300, 300, -300, 300);
}

void timer(int x) {
	if (g < 1) {
		g += 0.005;
		xt = yt = 30;
	}
	if (g >= 1) {
		Og += 0.05;
		if (b > 0)
			b -= 0.005;
		if (xt < 50 && yt < 50) {
			xt += 1;
			yt += 1;
		}
	}
	if (b <= 0 && g >= 1 && r < 1) {
		Ob += 0.05;;
		if (r != 1) {
			r += 0.005;
		}
		if (xt < 110 && yt < 110) {
			xt += 0.5;
			yt += 0.5;
		}
	}
	if (r >= 1) {
		Or += 0.1;
		if (g > 0)
			g -= 0.01;
		if (xt < 150 && yt < 150) {
			xt += 1;
			yt += 1;
		}
		xt = yt = 150;
	}
	glutPostRedisplay();
	glutTimerFunc(1000 / 100, timer, 0);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(600, 400);
	glutCreateWindow("Heat Simulation");
	glutDisplayFunc(display);
	glutTimerFunc(1000 / 100, timer, 0);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboard);
	glutMainLoop();
}