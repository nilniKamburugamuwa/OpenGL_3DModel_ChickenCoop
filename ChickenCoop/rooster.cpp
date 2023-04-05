#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include "rooster.h"

void drawWingRooster() {
	glColor3f(0.9, 0.6, 0);
	glTranslatef(0, 0, 0.05);
	glBegin(GL_POLYGON);
	glVertex2f(-0.3, 0);
	glVertex2f(0.3, 0);
	glVertex2f(0.3, 0.2);
	glVertex2f(0.2, 0.4);
	glVertex2f(0.1, 0.2);
	glVertex2f(0, 0.5);
	glVertex2f(-0.1, 0.2);
	glVertex2f(-0.2, 0.6);
	glVertex2f(-0.3, 0.2);
	glEnd();

	glPushMatrix();
	glBegin(GL_POLYGON);
	glTranslatef(0, 0, -0.1);
	glVertex2f(-0.3, 0);
	glVertex2f(0.3, 0);
	glVertex2f(0.3, 0.2);
	glVertex2f(0.2, 0.4);
	glVertex2f(0.1, 0.2);
	glVertex2f(0, 0.5);
	glVertex2f(-0.1, 0.2);
	glVertex2f(-0.2, 0.6);
	glVertex2f(-0.3, 0.2);
	glEnd();
	glPopMatrix();

	glBegin(GL_POLYGON);
	glVertex3f(-0.3, 0, 0);
	glVertex3f(-0.3, 0, -0.1);
	glVertex3f(-0.3, 0.2, -0.1);
	glVertex3f(-0.3, 0.2, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.3, 0.2, -0.1);
	glVertex3f(-0.3, 0.2, 0);
	glVertex3f(-0.2, 0.6, 0);
	glVertex3f(-0.2, 0.6, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.2, 0.6, 0);
	glVertex3f(-0.2, 0.6, -0.1);
	glVertex3f(-0.1, 0.2, -0.1);
	glVertex3f(-0.1, 0.2, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-0.1, 0.2, -0.1);
	glVertex3f(-0.1, 0.2, 0);
	glVertex3f(0, 0.5, 0);
	glVertex3f(0, 0.5, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0, 0.5, 0);
	glVertex3f(0, 0.5, -0.1);
	glVertex3f(0.1, 0.2, -0.1);
	glVertex3f(0.1, 0.2, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.1, 0.2, -0.1);
	glVertex3f(0.1, 0.2, 0);
	glVertex3f(0.2, 0.4, 0);
	glVertex3f(0.2, 0.4, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.2, 0.4, 0);
	glVertex3f(0.2, 0.4, -0.1);
	glVertex3f(0.3, 0.2, -0.1);
	glVertex3f(0.3, 0.2, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.3, 0.2, -0.1);
	glVertex3f(0.3, 0.2, 0);
	glVertex3f(0.3, 0, 0);
	glVertex3f(0.3, 0, -0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.3, 0, 0);
	glVertex3f(0.3, 0, -0.1);
	glVertex3f(-0.3, 0, -0.1);
	glVertex3f(-0.3, 0, 0);
	glEnd();

}


void drawRooster() {

	//head
	glColor3f(0.6, 0.4, 0);
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glutSolidSphere(0.6, 20, 20);
	glPopMatrix();

	//beak
	glColor3f(1, 0.73, 0.2);
	glPushMatrix();
	glTranslatef(0, 1, 0.6);
	glutSolidCone(0.1, 0.2, 10, 10);
	glPopMatrix();

	//comb
	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(0, 1.5, 0.2);
	glRotatef(-60, 1, 0, 0);
	glutSolidCone(0.2, 0.5, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.2, 0.5, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.5, -0.2);
	glRotatef(-120, 1, 0, 0);
	glutSolidCone(0.2, 0.5, 20, 20);
	glPopMatrix();

	//eyes
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(-0.2, 1.2, 0.5);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.2, 1.2, 0.5);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();



	//neck
	glPushMatrix();
	glColor3f(0.6, 0.4, 0);
	glTranslatef(0, 0.1, 0);
	glRotatef(-90, 1, 0, 0);
	GLUquadric* qobj = gluNewQuadric();
	gluCylinder(qobj, 0.5, 0.4, 0.6, 10, 16);
	glPopMatrix();

	glTranslatef(0, -0.8, 0);
	glColor3f(0.9, 0.6, 0);

	//body
	glutSolidSphere(1, 20, 20);

	//wing right
	glPushMatrix();
	glTranslatef(0.9, 0.5, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(160, 1, 0, 0);
	//rotate with x to flap wings
	glScalef(2, 2, 2);
	drawWingRooster();
	glPopMatrix();

	//wing left
	glPushMatrix();
	glTranslatef(-0.9, 0.5, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(-160, 1, 0, 0);
	glScalef(2, 2, 2);
	drawWingRooster();
	glPopMatrix();

	//tail
	glColor3f(0.13, 0.4, 0);

	glPushMatrix();
	glTranslatef(-0.2, 0.2, -0.7);
	glRotatef(180, 0, 1, 0);
	glutSolidCone(0.4, 0.8, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.2, -0.7);
	glRotatef(180, 0, 1, 0);
	glutSolidCone(0.4, 0.8, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.2, 0.2, -0.7);
	glRotatef(180, 0, 1, 0);
	glutSolidCone(0.4, 0.8, 20, 20);
	glPopMatrix();

}
