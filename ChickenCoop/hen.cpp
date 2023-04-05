#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include "Hen.h"
#define M_PI 3.142857


void drawHalfSphere(GLfloat r) {
	int i, j;
	int scaley = 20;
	int scalex = 4;
	GLfloat v[80][3];

	for (i = 0; i < scalex; ++i) {
		for (j = 0; j < scaley; ++j) {
			v[i * scaley + j][0] = r * cos(j * 2 * M_PI / scaley) * cos(i * M_PI / (2 * scalex));
			v[i * scaley + j][1] = r * sin(i * M_PI / (2 * scalex));
			v[i * scaley + j][2] = r * sin(j * 2 * M_PI / scaley) * cos(i * M_PI / (2 * scalex));
		}
	}

	glBegin(GL_QUADS);
	for (i = 0; i < scalex - 1; ++i) {
		for (j = 0; j < scaley; ++j) {
			glVertex3fv(v[i * scaley + j]);
			glVertex3fv(v[i * scaley + (j + 1) % scaley]);
			glVertex3fv(v[(i + 1) * scaley + (j + 1) % scaley]);
			glVertex3fv(v[(i + 1) * scaley + j]);
		}
	}
	glEnd();
}

void drawWing() {
	glColor3f(1, 1, 0.8);
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

void drawHen(GLfloat wingL, GLfloat wingR) {
	glColor3f(1, 1, 0.8);

	//body

	glutSolidSphere(1, 20, 20);

	//head
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glutSolidSphere(0.6, 20, 20);
	glPopMatrix();


	//wing right
	glPushMatrix();
	glTranslatef(0.9, 0.5, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(160 + wingR, 1, 0, 0);
	//rotate with x to flap wings
	glScalef(2, 2, 2);
	drawWing();
	glPopMatrix();

	//wing left
	glPushMatrix();
	glTranslatef(-0.9, 0.5, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(-160 + wingL, 1, 0, 0);
	glScalef(2, 2, 2);
	drawWing();
	glPopMatrix();

	//tail
	glColor3f(1, 1, 0.8);
	glPushMatrix();
	glTranslatef(0, 0.1, -0.8);
	glutSolidSphere(0.5, 20, 20);
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

}
