#include <Windows.h> 
#include <GL\glew.h>
#include<GL\freeglut.h>
#include <iostream>
#include <stdio.h>
#include <sstream> 
#include <iomanip>
#define PI 3.1415927

void Silindir(GLfloat radius, GLfloat height, GLubyte R, GLubyte G, GLubyte B);	
void DikdortgenPrizma();
void UcgenPrizmaGoruntu();
void KupGoruntu();
void UcgenPrizma2Goruntu();
void RobotKolu();
void Goruntu();
void specialKeys(int key, int x, int y);
void Timer(int Timer);


float xr = 0;
float yr = 0;
float q, y, z, w = 5;



void initGL() {
	glClearColor(1, 1, 1, 0);	    glClearDepth(10.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}
void Silindir(GLfloat radius,GLfloat height,GLubyte R,GLubyte G,GLubyte B)	
{
	GLfloat x = 0.0;
	GLfloat y = 0.0;
	GLfloat angle = 0.0;
	GLfloat angle_stepsize = 0.1;

	glTranslatef(-0.8, 0.6 + q, 0.0);
	glRotatef(30, -0.5, 0.3, 1);
	glColor3f(0.0, 1.0, 0.0);	
	glBegin(GL_QUAD_STRIP);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		glVertex3f(x, y, 0.0);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glVertex3f(radius, 0.0, 0.0);
	glEnd();

	
	glColor3f(0.0, 0.0, 0.1);
	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * PI) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glEnd();
}

void KupGoruntu() {

	glLoadIdentity();
	glTranslatef(0.2, 0.6 + y, 0.0);
	glRotatef(10, -0.5, 0.3, 1);

	glBegin(GL_QUADS);
	glColor3f(0, 0.0, 1);	
	glVertex3f(0.1, -0.1, -0.1);
	glVertex3f(0.1, 0.1, -0.1);
	glVertex3f(-0.1, 0.1, -0.1);
	glVertex3f(-0.1, -0.1, -0.1);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.1, -0.1, 0.1);
	glVertex3f(0.1, 0.1, 0.1);
	glVertex3f(-0.1, 0.1, 0.1);
	glVertex3f(-0.1, -0.1, 0.1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.1, -0.1, -0.1);
	glVertex3f(0.1, 0.1, -0.1);
	glVertex3f(0.1, 0.1, 0.1);
	glVertex3f(0.1, -0.1, 0.1);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.1, -0.1, 0.1);
	glVertex3f(-0.1, 0.1, 0.1);
	glVertex3f(-0.1, 0.1, -0.1);
	glVertex3f(-0.1, -0.1, -0.1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);    glVertex3f(0.1, 0.1, 0.1);
	glVertex3f(0.1, 0.1, -0.1);
	glVertex3f(-0.1, 0.1, -0.1);
	glVertex3f(-0.1, 0.1, 0.1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.1, -0.1, -0.1);
	glVertex3f(0.1, -0.1, 0.1);
	glVertex3f(-0.1, -0.1, 0.1);
	glVertex3f(-0.1, -0.1, -0.1);
	glEnd();
}
void UcgenPrizmaGoruntu() {
	
	glLoadIdentity();
	glTranslatef(-0.5, 0.5 + z, 0.0);
	glRotatef(10, 0.5, 0.8, 1);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.1, 0.1, 0);
	glVertex3f(0.3, 0.1, 0);
	glVertex3f(0.2, 0.3, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.1, 0.0);
	glVertex3f(0.2, 0.3, 0);
	glVertex3f(0.3, 0.1, 0);
	glVertex3f(0.2, 0.1, -0.3);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.1, 0.1, 0);
	glVertex3f(0.2, 0.1, -0.3);
	glVertex3f(0.2, 0.3, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.1, 0.1, 0);
	glVertex3f(0.3, 0.1, 0);
	glVertex3f(0.2, 0.1, -0.3);
	glEnd();	
}

void UcgenPrizma2Goruntu() {

	glLoadIdentity();
	glTranslatef(0.8, 0.6 + w, 0.0);
	glRotatef(200, 0.5, 0.8, 1);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.1, 0.1, 0);
	glVertex3f(0.3, 0.1, 0);
	glVertex3f(0.2, 0.3, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.1, 0.0);
	glVertex3f(0.2, 0.3, 0);
	glVertex3f(0.3, 0.1, 0);
	glVertex3f(0.2, 0.1, -0.3);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.1, 0.1, 0);
	glVertex3f(0.2, 0.1, -0.3);
	glVertex3f(0.2, 0.3, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.1, 0.1, 0);
	glVertex3f(0.3, 0.1, 0);
	glVertex3f(0.2, 0.1, -0.3);
	glEnd();
}

void DikdortgenPrizma(){
	
		glLoadIdentity();
		glTranslatef(0.0+xr, -0.8+yr, 0.0);
		glRotatef(10, 0.5, 0.8, 1);

		glBegin(GL_QUADS);
		glColor3f(1, 0.0, 0);		
		glVertex3f(-0.2, 0.1, 0.0);
		glVertex3f(0.2 , 0.1, 0.0);
		glVertex3f(-0.2 , -0.1, 0.0);
		glVertex3f(0.2 , -0.1, 0.0);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1, 0.0, 0.0);
		glVertex3f(0.2 , -0.1, 0.0);
		glVertex3f(0.2 , -0.1, -0.1);
		glVertex3f(0.2 , 0.1, -0.1);
		glVertex3f(0.2 , 0.1, 0.0);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 0.0);
		glVertex3f(-0.2 , -0.1, 0.0);
		glVertex3f(0.2 , -0.1, 0.0);
		glVertex3f(0.2 , -0.1, -0.1);
		glVertex3f(-0.2 , -0.1, -0.1);
		glEnd();


		glBegin(GL_QUADS);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-0.2 , 0.1, 0.0); 
		glVertex3f(0.2 , 0.1, 0.0); 
		glVertex3f(0.2 , 0.1, -0.1); 
		glVertex3f(-0.2 , 0.1, -0.1); 
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-0.2 , 0.1, 0.0);
		glVertex3f(-0.2 , 0.1, -0.1);
		glVertex3f(-0.2 , -0.1, -0.1);
		glVertex3f(-0.2 , -0.1, 0.0);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-0.2 , -0.1, -0.1); glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.2 , -0.1, -0.1); glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.2 , 0.1, -0.1); glColor3f(0.0, 0.0, 1.0);
		glVertex3f(-0.2 , 0.1, -0.1); glColor3f(1.0, 0.0, 1.0);
		glEnd();

}

void RobotKolu() {
	
	glLoadIdentity();	
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-1.0, -0.8 , 0.0);
	glVertex3f(-0.8 + xr, -0.8 + yr , 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-0.8 +xr , -0.8 +yr, 0.0);
	glVertex3f(-0.7 + xr, -0.5 + yr, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-0.7 + xr, -0.5 + yr, 0.0);
	glVertex3f(-0.6 + xr, -0.9 + yr, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-0.6 + xr, -0.9 + yr, 0.0);
	glVertex3f(-0.4+xr, -0.8 + yr, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-0.4+xr, -0.8+yr, 0.0);
	glVertex3f(0.0+xr, -0.8 + yr, 0.0);
	glEnd();
}

void Goruntu() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	Silindir(0.1, 0.5, 122, 80, 50);
	DikdortgenPrizma();
	UcgenPrizmaGoruntu();
	KupGoruntu();
	UcgenPrizma2Goruntu();
	RobotKolu();

	glFlush();
    glutSwapBuffers();
}
void Timer(int timer) {
    glutPostRedisplay();
    glutTimerFunc(100, Timer, 0);

	q -= rand() % 2;
	y -= rand() % 2;
	z -= rand() % 2;
	w -= rand() % 2;
	

	if (q <= -5)
		q = 0.8;

	if (y <= -5)
		y = 0.8;

	if (z <= -5)
		z = 0.9;

	if (w <= -5)
		w = 0.7;
}
void specialKeys(int key, int x, int y)
{
	if (xr != 0.8 && xr != -0.8 && yr != 0.8 && yr != 0.8)
	{
        switch (key)
		{
		case GLUT_KEY_LEFT:
			xr -= 0.1;
			glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT:
			xr += 0.1;
			glutPostRedisplay();
			break;		case GLUT_KEY_UP:			yr += 0.1;			glutPostRedisplay();
			break;		case GLUT_KEY_DOWN:			yr -= 0.1;			glutPostRedisplay();
			break;		}	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400, 600);
	glutCreateWindow("Bilgisayar Grafikleri Proje 2");
	glutInitWindowPosition(800, 400);
    initGL();
	glutTimerFunc(100, Timer, 0);
	glutDisplayFunc(Goruntu);
    glutSpecialFunc(specialKeys);
	glutMainLoop();
	return 0;
}
