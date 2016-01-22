// consoleI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//
// Example code for OpenGL programming
//
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <GL/glut.h>



int nFPS = 30;
float fRotateAngle = 0.f;

float sine[91] , pi=3.141592653 ;

int i;


float x = 0;
float y =0;
float z = 0.0;

void init(void)
{
	// init your data, setup OpenGL environment here
	glClearColor(1.0,1.0,1.0,1.0); // clear color is gray
	glPolygonMode(GL_FRONT_FACE, GL_FILL);


	for (i=0; i<90; i++) {
		sine[i]=((pi/180)*i);
		}
	i = 0;

	// GL_POINT / GL_LINE / GL_FILL (default)
	glPointSize(4.0);
}


void display(void)
{
	// put your OpenGL display commands here
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// reset OpenGL transformation matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); // reset transformation matrix to identity

	// setup look at transformation so that
	// eye is at : (0,0,3)
	// look at center is at : (0,0,0)
	// up direction is +y axis
	gluLookAt(0.f,0.f,3.f,0.f,0.f,0.f,0.f,1.f,0.f);







	glColor3f(1.0, 0.45, 0.0); // Make 'I' illinois orange colour. 

	// Creating the main dancing I.


	glRotatef(sin(y), 0, 1, 1);
	glTranslatef(sin(x), sin(y), 0);//animation makes 'I' look like party animal




	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(-.2, .6);
	glVertex2f(-.6, .6);
	glVertex2f(-.6, 1.0);
	glVertex2f(.6, 1.0);
	glVertex2f(.2, .6);
	glVertex2f(.2, -.6);
	glVertex2f(-.2, -.6);

	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(.2, .6);
	glVertex2f(.6, .6);
	glVertex2f(.6, 1.0);

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(-.6, -1.0);
	glVertex2f(-.6, -.6);
	glVertex2f(-.2, -.6);
	glVertex2f(.2, -.6);
	glVertex2f(.6, -.6);
	glVertex2f(.6, -1.0);

	glEnd();


	glFlush();
	glutSwapBuffers();	// swap front/back framebuffer to avoid flickering
}

void reshape (int w, int h)
{
	// reset viewport ( drawing screen ) size
	glViewport(0, 0, w, h);
	float fAspect = ((float)w)/h;
	// reset OpenGL projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70.f,fAspect,0.001f,30.f);

}



void keyboard(unsigned char key, int x, int y)
{
	// put your keyboard control here
	if (key == 27)
	{
	// ESC hit, so quit
	printf("demonstration finished.\n");
	exit(0);
	}
	if(key == 'b')
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//Press 'b' to return to block fill mode

}

void mouse(int button, int state, int x, int y)
{
	// process your mouse control here
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//mouse click shows wireframe underneath
}


void timer(int v)
{
	fRotateAngle += 1.f; // change rotation angles

	x += 0.1;
	y += 0.2;
	z += .3;
	//using global variables to animate. 

	glClearColor(sin(x),sin(y),sin(z),1.0);//change background to look like disco






	glutPostRedisplay(); // trigger display function by sending redraw into message queue
	glutTimerFunc(1000/nFPS,timer,v); // restart timer again
}

int main(int argc, char* argv[])
{
	glutInit(&argc, (char**)argv);
	// set up for double-buffering & RGB color buffer & depth test
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ((const char*)"Hello Illinois");

	init(); // setting up user data & OpenGL environment

	// set up the call-back functions
	glutDisplayFunc(display); // called when drawing
	glutReshapeFunc(reshape); // called when change window size
	glutKeyboardFunc(keyboard); // called when received keyboard interaction
	glutMouseFunc(mouse);	 // called when received mouse interaction
	glutTimerFunc(100,timer,nFPS); // a periodic timer. Usually used for updating animation


	glutMainLoop(); // start the main message-callback loop

return 0;
}


