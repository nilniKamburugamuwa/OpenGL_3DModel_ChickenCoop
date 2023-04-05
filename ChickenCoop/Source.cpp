#include<iostream>
#include<GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<stdio.h>
#include <math.h>
#include "models.h"
#include "textures.h"
#include "rooster.h"
#include "hen.h"

//variables to move the camera
GLfloat camX = 0.0;
GLfloat camY = 0.0;
GLfloat camZ = 0.0;

//variables to move the scene
GLfloat sceX = 0.0;
GLfloat sceY = 0.0;
GLfloat sceZ = 0.0;

//variables to move the hen
GLfloat henx = 0.0;
GLfloat heny = 0.0;
GLfloat henz = 0.0;

//move rooster
GLfloat objX = 0.0;
GLfloat objZ = 0.0;
GLfloat roostangle = 0;

//hens bouncing
GLfloat bounce = 0;

GLfloat wingL = 0;
GLfloat wingR = 0;

GLboolean fly = false;
GLboolean open = false;
GLboolean close = false;

GLfloat scarerot = -10;
GLfloat peck = 0;
GLfloat door = 0;
GLfloat rotsce = 0;
GLfloat rothen = 0;

GLfloat trahenX = 0;
GLfloat trahenZ = 0;
GLfloat step=0;

void init() {
	glClearColor(1, 1, 1, 1);
	//glClearColor(0.64f, 0.93f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);


	glLoadIdentity();
	glEnable(GL_LIGHTING);
	GLfloat globalAmbient[] = { 0.2, 0.2, 0.2, 1.0 };
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);

	glEnable(GL_LIGHTING);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glShadeModel(GL_SMOOTH);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

	glEnable(GL_COLOR_MATERIAL);


	glEnable(GL_NORMALIZE);

	loadExternalTextures();
}

void drawGrid() {
	GLfloat step = 1.0f;
	GLint line;

	glBegin(GL_LINES);
	for (line = -20; line <= 20; line += step) {
		glVertex3f(line, -0.4, 20);
		glVertex3f(line, -0.4, -20);

		glVertex3f(20, -0.4, line);
		glVertex3f(-20, -0.4, line);
	}
	glEnd();
}

void drawAxes() {
	glBegin(GL_LINES);
	glLineWidth(1.5);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-200, 0, 0);
	glVertex3f(200, 0, 0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, -200, 0);
	glVertex3f(0, 200, 0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0, 0, -200);
	glVertex3f(0, 0, 200);

	glEnd();
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	// camera orientation (eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)
	gluLookAt(0 + camX, 40 + (GLint)camY, 40 + (GLint)camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(rotsce, 0.0, 1.0, 0.0);
	glTranslatef(sceX, -15, sceZ);
	
	GLfloat harvestYellow[] = { 0.9,0.6,0,1 };
	GLfloat white[] = { 1,1,1,1 };

	//glEnable(GL_LIGHT0);
	GLfloat position[] = { 0,15,-2,1 };
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);

	//glEnable(GL_LIGHT1);
	GLfloat position1[] = { 0,40,-2,1 };
	glLightfv(GL_LIGHT1, GL_POSITION, position1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white);

	//glEnable(GL_LIGHT2);
	GLfloat position2[] = { 60,30,-2,1 };
	glLightfv(GL_LIGHT2, GL_POSITION, position2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT2, GL_SPECULAR, white);

	//glEnable(GL_LIGHT3);
	GLfloat position3[] = { 90,30,0,1 };
	glLightfv(GL_LIGHT2, GL_POSITION, position3);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, harvestYellow);
	glLightfv(GL_LIGHT2, GL_SPECULAR, white);

	//Draw a grid on the xz plane
	glColor3f(1, 1, 1);

	//draw grid
	drawGrid();
	//draw the three axes
	//drawAxes();

	ground();

	//grass
	drawGrass();

	//floor
	drawFloor();

	//walls
	drawWalls(door);

	//window
	window();

	//roof
	roof();

	//second floor
	secondFloor();

	//barrel 1
	glPushMatrix();
	glTranslatef(-13, 15.8, -13);
	glRotatef(-90, 1, 0, 0);
	glScalef(0.5, 0.5, 0.5);
	drawBarrel();
	glPopMatrix();

	//barrel 2
	glPushMatrix();
	glTranslatef(-10, 15.8, -13);
	glRotatef(-90, 1, 0, 0);
	glScalef(0.5, 0.5, 0.5);
	drawBarrel();
	glPopMatrix();

	//barrel 3
	glPushMatrix();
	glTranslatef(-13, 15.8, -10);
	glRotatef(-90, 1, 0, 0);
	glScalef(0.5, 0.5, 0.5);
	drawBarrel();
	glPopMatrix();

	//ladder
	glPushMatrix();
	glRotatef(-30, 1, 0, 0);
	glTranslatef(11, -1.5, 3.5);
	ladder();
	glPopMatrix();

	//feeding pen
	feedingPen();

	//hay stacks
	glPushMatrix();
	hay();
	glTranslatef(-6.2, 0, 0);
	hay();
	glTranslatef(3, 0, 6.2);
	hay();
	glTranslatef(1, 6, -3);
	hay();
	glPopMatrix();

	//water
	water();

	//eggs
	glPushMatrix();
	glTranslatef(-13, 1.5, -3);
	egg();
	glTranslatef(15, -0.5, 5);
	egg();
	glTranslatef(-1, 0, -10);
	egg();
	glTranslatef(-5, 15.5, 0);
	egg();
	glPopMatrix();

	//pitchfork
	glPushMatrix();
	glTranslatef(3, 6.5, -8);
	glRotatef(-20, 1, 0, 0);
	pitchfork();
	glPopMatrix();

	//rooster
	glPushMatrix();
	glTranslatef(0 + objX, 2.2, 0 + objZ);
	glTranslatef(-1, -1, -1);
	glRotatef(roostangle, 0, 1, 0);
	glTranslatef(0, 1, 0);
	drawRooster();
	glPopMatrix();

	//hens
	glPushMatrix();
	glTranslatef(0, bounce, 0);
	//hen1
	glPushMatrix();
	glTranslatef(-4, 1.5, -2);
	glRotatef(25 + peck, 1, 0, 0);
	drawHen(wingL, wingR);
	glPopMatrix();

	//hen2
	glPushMatrix();
	glTranslatef(-12.5, 2, -10);
	glRotatef(90, 0, 1, 0);
	drawHen(wingL, wingR);
	glPopMatrix();

	//hen3
	glPushMatrix();
	glTranslatef(-12.5, 2, -6);
	glRotatef(70, 0, 1, 0);
	drawHen(wingL, wingR);
	glPopMatrix();

	//hen4
	glPushMatrix();
	glTranslatef(-10, 1.5, 4);
	glRotatef(-80, 0, 1, 0);
	drawHen(wingL, wingR);
	glPopMatrix();

	//hen5
	glPushMatrix();
	glTranslatef(2, 1.5, 7);
	glRotatef(-120, 0, 1, 0);
	drawHen(wingL, wingR);
	glPopMatrix();

	//hen6
	glPushMatrix();
	glTranslatef(4+henx, 18.5+heny, -1+henz);
	drawHen(wingL, wingR);
	glPopMatrix();

	//hen7
	glPushMatrix();
	glTranslatef(65, 2, -10);
	glRotatef(45 + peck, 1, 0, 0);
	drawHen(wingL, wingR);
	glPopMatrix();

	//hen8
	glPushMatrix();
	glTranslatef(50, 2, 13);
	glRotatef(45 + peck, 1, 0, 0);
	drawHen(wingL, wingR);
	glPopMatrix();

	//hen9
	glPushMatrix();
	glTranslatef(30+trahenX, 2, 20+trahenZ);
	glTranslatef(-1, -1, -1);
	glRotatef(rothen, 0, 1, 0);
	glTranslatef(0, 1, 0);
	drawHen(wingL, wingR);
	glPopMatrix();

	glPopMatrix();

	//crates
	glPushMatrix();
	crate();
	glTranslatef(0, 0, 3);
	glRotatef(-30, 0, 1, 0);
	crate();
	glPopMatrix();

	//fence inside
	glPushMatrix();
	glTranslatef(5,16.5,-1);
	glScalef(1, 0.5, 1);
	fence();
	glPopMatrix();

	//fence outside
	glPushMatrix();
	glTranslatef(50, 2, 15);
	fence2();
	glTranslatef(20, 0, 0);
	fence2();
	glTranslatef(20, 0, 0);
	fence2();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(50, 2, -15);
	fence2();
	glTranslatef(20, 0, 0);
	fence2();
	glTranslatef(20, 0, 0);
	fence2();
	glPopMatrix();
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(15, 2, 30);
	fence2();
	glPopMatrix();

	blocks();

	glPushMatrix();
	glTranslatef(40, 9, 2);
	glScalef(2, 2, 2);
	label();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(60, 10, 2);
	glTranslatef(0, -15, 0);
	glRotatef(scarerot, 0, 0, 1);
	glTranslatef(0, 15, 0);
	glScalef(2, 2, 2);
	scarecrow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(80, 0, 22);;
	dirtPath();
	glPopMatrix();

	glPopMatrix();

	glutSwapBuffers();

}

//Animation timer function
void timer(int x) {
	if (bounce == 0)
		bounce += 0.1;
	else
		bounce = 0;

	if (wingL == 20)
		wingL = 0;
	else
		wingL += 20;

	if (wingR == -20)
		wingR = 0;
	else
		wingR -= 20;


	if (scarerot == 10)
		scarerot -= 5;
	else
		scarerot += 5;

	if (peck == 0)
		peck += 45;
	else
		peck = 0;

	if (open) {
		if (door != -120)
			door -= 10;
	}

	if (close) {
		if (door != 0)
			door += 10;
	}


	if (step <= 3) {
		rothen = 90;
		trahenX += 1;
		step += 1;
	}
	else {
		if (step > 3 && step < 8) {
			rothen = 270;
			trahenX -= 1;
			step += 1;
		}
		else {
			step = 0;
		}
	}

	glutPostRedisplay();

	glutTimerFunc(300.0, timer, 1);
}

void timer2(int x) {
	if (fly) {
		if (henz < 13) {
			henz += 0.5;
			//henx += 0.2;
			if (henz < 4) {
				heny += 0.5;
			}
			if (henz > 3 && heny > -20) {
				heny -= 1;
			}
		}

	}
	glutPostRedisplay();
	glutTimerFunc(50, timer2, 1);
}

void keyboardSpecial(int key, int x, int y) {
	if (key == GLUT_KEY_UP)
		camY += 1;

	if (key == GLUT_KEY_DOWN)
		camY -= 1;

	if (key == GLUT_KEY_RIGHT)
		sceX -= 1;

	if (key == GLUT_KEY_LEFT)
		sceX += 1;

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	/*if (key == 'l')
		camX += 1;

	if (key == '2')
		camX -= 1;

	if (key == '3')
		camY += 1;

	if (key == '4')
		camY -= 1;

	if (key == '5')
		camZ += 1;

	if (key == '6')
		camZ -= 1;*/

	if (key == 'f')
		fly = true;

	if (key == 'o') {
		open = true;
		close = false;
	}

	if (key == 'c') {
		close = true;
		open = false;
	}

		


	if (key == 'r') {
		camX = 0;
		camY = 0;
		camZ = 0;
		fly = false;
		open = false;
		close = false;
		henx = 0;
		heny = 0;
		henz = 0;
		objX = 0;
		objZ = 0;
		
	}

	if (key == ')')
		glDisable(GL_LIGHT0);
	if (key == '0')
		glEnable(GL_LIGHT0);
	if (key == '!')
		glDisable(GL_LIGHT1);
	if (key == '1')
		glEnable(GL_LIGHT1);
	if (key == '@')
		glDisable(GL_LIGHT2);
	if (key == '2')
		glEnable(GL_LIGHT2);
	if (key == '#')
		glDisable(GL_LIGHT3);
	if (key == '3')
		glEnable(GL_LIGHT3);
	if (key == '$')
		glDisable(GL_LIGHT4);
	if (key == '4')
		glEnable(GL_LIGHT4);
	if (key == '%')
		glDisable(GL_LIGHT5);
	if (key == '5')
		glEnable(GL_LIGHT5);
	if (key == '^')
		glDisable(GL_LIGHT6);
	if (key == '6')
		glEnable(GL_LIGHT6);
	if (key == '&')
		glDisable(GL_LIGHT7);
	if (key == '7')
		glEnable(GL_LIGHT7);

	//move rooster
	if (key == 'w')
		objZ -= 1;
	if (key == 's')
		objZ += 1;
	if (key == 'a')
		objX -= 1;
	if (key == 'd')
		objX += 1;
	if (key == 'q')
		roostangle -= 5;
	if (key == 'e')
		roostangle += 5;

	if (key == 'l')
		sceZ -= 1;
	if (key == 'p')
		sceZ += 1;

	if (key == 'h')
		rotsce -= 5;
	if (key == 'j')
		rotsce += 5;

	if (key == 'n')
		rothen -= 5;
	if (key == 'm')
		rothen += 5;

	glutPostRedisplay();
}

void reshape(GLsizei width, GLsizei height) {

	if (height == 0) height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping area to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset the projection matrix
	gluPerspective(60, aspect, 1, 200);


}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("First 3D OpenGL Object");

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardSpecial);
	glutTimerFunc(200, timer, 0);
	glutTimerFunc(50, timer2, 1);
	glutMainLoop();
	return 0;
}
