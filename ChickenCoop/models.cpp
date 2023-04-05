#include<GL/glut.h>
#include "models.h"
#include<math.h>
#define pi 3.142857

void drawCircle(float x, float y, float radius)
{
	glPushMatrix();
	float x2, y2, i;
	glBegin(GL_POLYGON);
	for (i = 0; i < (2 * pi); i += 0.001)
	{
		// let 200 is radius of circle and as,
		// circle is defined as x=r*cos(i) and y=r*sin(i)

		x = radius * cos(i);
		y = radius * sin(i);
		x2 = radius * cos(i+0.001);
		y2 = radius * sin(i+0.001);
		glColor3f(0.51, 0.27, 0.16);
		glVertex3f(x, y,0);
		glVertex3f(x2, y2, 0);
		glVertex3f(0, 0, 0);
	}
	glEnd();
	glPopMatrix();
}

void drawCircleOutline(GLfloat x, GLfloat y, GLfloat r, int textureindex)
{
	float angle, radian, x2, y2;       // values needed by drawCircleOutline

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureindex);
	GLfloat xcos, ysin, tx, ty;
	glBegin(GL_POLYGON);

	for (angle = 0.0; angle < 360.0; angle += 2.0)
	{
		radian = angle * (pi / 180.0f);

		xcos = (float)cos(radian);
		ysin = (float)sin(radian);
		x2 = xcos * r + x;
		y2 = ysin * r + y;
		tx = xcos * 0.5 + 0.5;
		ty = ysin * 0.5 + 0.5;

		glTexCoord3f(tx, ty,0);
		glVertex3f(x2, y2,0);
	}

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void cube(GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLfloat l, GLfloat h, GLfloat color[]) {

	glPushMatrix();
	glTranslatef(x, y, z);
	glColor3f(color[0], color[1], color[2]);
	//glColor3f(1,1,1);


	glNormal3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);

	//TOP
	glTexCoord2f(0.0, 0.0); glVertex3f(0, h, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0, h, l);
	glTexCoord2f(1.0, 1.0); glVertex3f(w, h, l);
	glTexCoord2f(0.0, 1.0); glVertex3f(w, h, 0);
	glEnd();

	//BOTTOM
	glNormal3f(0.0, -1.0, 0.0);
	glBegin(GL_QUADS);
	//glColor3f(0.0, 1.0, 0.0);

	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(w, 0, 0);
	glTexCoord2f(1.0, 1.0); glVertex3f(w, 0, l);
	glTexCoord2f(0.0, 1.0); glVertex3f(0, 0, l);
	glEnd();


	// FRONT
	glNormal3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	//glColor3f(1.0, 0.0, 1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, l);
	glTexCoord2f(1.0, 0.0); glVertex3f(w, 0, l);
	glTexCoord2f(1.0, 1.0); glVertex3f(w, h, l);
	glTexCoord2f(0.0, 1.0); glVertex3f(0, h, l);
	glEnd();



	//// BACK
	glNormal3f(-1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	//glColor3f(1.0, 1.0, 1.0);

	glTexCoord2f(1.0, 1.0); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0, h, 0);
	glTexCoord2f(0.0, 0.0); glVertex3f(w, h, 0);
	glTexCoord2f(0.0, 1.0); glVertex3f(w, 0, 0);
	glEnd();



	// LEFT
	glNormal3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	//glColor3f(1.0, 0.0, 0.0);

	glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, l);
	glTexCoord2f(1.0, 1.0); glVertex3f(0, h, l);
	glTexCoord2f(0.0, 1.0); glVertex3f(0, h, 0);
	glEnd();

	//RIGHT
	glNormal3f(0.0, 0.0, -1.0);
	glBegin(GL_QUADS);
	//glColor3f(0.0, 0.0, 1.0);

	glTexCoord2f(1.0, 1.0); glVertex3f(w, 0, 0);
	glTexCoord2f(1.0, 0.0); glVertex3f(w, h, 0);
	glTexCoord2f(0.0, 0.0); glVertex3f(w, h, l);
	glTexCoord2f(0.0, 1.0); glVertex3f(w, 0, l);
	glEnd();

	glPopMatrix();
}

void drawGrass() {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 9);
	GLfloat color[] = { 0.62,0.58,0.54 };

//	GLfloat color[] = { 0.39, 0.67, 0.27 };
	cube(-30, -0.25, -30, 60, 60, 0.5, color);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void ground() {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 9);
	GLfloat color[] = { 0.62,0.58,0.54 };

	//	GLfloat color[] = { 0.39, 0.67, 0.27 };
	cube(30, -0.25, -30, 60, 60, 0.5, color);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 7);

	cube(30, 0, -15, 30, 30, 0.5, color);
	cube(60, 0, -15, 30, 30, 0.5, color);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();


}

void drawFloor() {

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 4);
	GLfloat color[] = { 1,1,1 };

//	GLfloat color[] = { 0.8, 0.56, 0.16 };
	cube(-15, 0, -15, 30, 30, 0.5, color);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void dirtPath() {

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 10);
	GLfloat color[] = { 0.7,0.7,0.7 };

	//	GLfloat color[] = { 0.8, 0.56, 0.16 };
	glRotatef(45, 0, 1, 0);
	cube(-2.5, 0, -2.5, 4, 4, 0.5, color);
	glTranslatef(-7, 0, -7);
	cube(-2.5, 0, -2.5, 4, 4, 0.5, color);
	glTranslatef(-7, 0, -7);
	cube(-2.5, 0, -2.5, 4, 4, 0.5, color);
	glTranslatef(-7, 0, -7);
	cube(-2.5, 0, -2.5, 4, 4, 0.5, color);
	glTranslatef(-7, 0, -7);
	cube(-2.5, 0, -2.5, 4, 4, 0.5, color);
	glTranslatef(-7, 0, -7);
	cube(-2.5, 0, -2.5, 4, 4, 0.5, color);
	glTranslatef(-7, 0, -7);
	cube(-2.5, 0, -2.5, 4, 4, 0.5, color);
	glTranslatef(-7, 0, -7);
	cube(-2.5, 0, -2.5, 4, 4, 0.5, color);
	glTranslatef(-7, 0, -7);
	cube(-2.5, 0, -2.5, 4, 4, 0.5, color);

	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void roof() {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 5);
	GLfloat color[] = { 1,1,1 };
	cube(-0.5, 34, -15, 1, 30, 1, color);
	glPushMatrix();
	glTranslatef(0, -1, 0);
	glRotatef(-30, 0, 0, 1);
	cube(-18, 30, -15, 20, 30, 1, color);
	cube(-18, 30, -10, 20, 1, 1, color);
	cube(-18, 30, -5, 20, 1, 1, color);
	cube(-18, 30, 0, 20, 1, 1, color);
	cube(-18, 30, 5, 20, 1, 1, color);
	cube(-18, 30, 10, 20, 1, 1, color);
	cube(-18, 30, 15, 20, 1, 1, color);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(14, 7, 0);
	glRotatef(30, 0, 0, 1);
	cube(-18, 30, -15, 20, 30, 1, color);
	cube(-18, 30, -10, 20, 1, 1, color);
	cube(-18, 30, -5, 20, 1, 1, color);
	cube(-18, 30, 0, 20, 1, 1, color);
	cube(-18, 30, 5, 20, 1, 1, color);
	cube(-18, 30, 10, 20, 1, 1, color);
	cube(-18, 30, 15, 20, 1, 1, color);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void window() {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 12);
	GLfloat color[] = { 1,1,1 };
	cube(14.25, 5, 0, 1, 7, 7, color);
	cube(14.25, 16, -12, 1, 7, 7, color);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void drawWalls(GLfloat door) {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 6);

	//back
	glPushMatrix();
	GLfloat color[] = { 1,1,1 };

//	GLfloat color[] = { 0.34, 0.21, 0.04 };
	cube(-15, 0, -15, 30, 0.5, 25, color);
	glPopMatrix();

	//front
	glPushMatrix();
	cube(-15, 0, 15, 10, 0.5, 10, color);
	cube(5, 0, 15, 10, 0.5, 10, color);
	cube(-15, 10, 15, 30, 0.5, 15, color);
	glPopMatrix();

	//left
	glPushMatrix();
	cube(-15, 0, -15, 0.5, 30, 25, color);
	glPopMatrix();

	//right
	glPushMatrix();
	cube(14.5, 0, -15, 0.5, 30, 25, color);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);

	//door
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 11);
	glTranslatef(-5, 0, 15);
	glRotatef(door, 0, 1, 0);
	glTranslatef(5, 0, -15);
	cube(-5, 0, 15, 10, 0.5, 10, color);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	//roof support
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 5);
	cube(-0.5, 25, 15, 1, 1,9, color);
	cube(-4, 25, 15, 1, 1, 7, color);
	cube(3, 25, 15, 1, 1, 7, color);
	cube(-7, 25, 15, 1, 1, 5.5, color);
	cube(6, 25, 15, 1, 1, 5.5, color);
	cube(-10, 25, 15, 1, 1, 4, color);
	cube(9, 25, 15, 1, 1, 4, color);

	cube(-0.5, 25, -15, 1, 1, 9, color);
	cube(-4, 25, -15, 1, 1, 7, color);
	cube(3, 25, -15, 1, 1, 7, color);
	cube(-7, 25, -15, 1, 1, 5.5, color);
	cube(6, 25, -15, 1, 1, 5.5, color);
	cube(-10, 25, -15, 1, 1, 4, color);
	cube(9, 25, -15, 1, 1, 4, color);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPopMatrix();
}

void secondFloor() {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 1);
	GLfloat color[] = { 1,1,1 };

//	GLfloat color[] = { 0.8, 0.56, 0.16 };
	cube(-15, 15, -15, 20, 15, 0.5, color);
	cube(5, 15, -15, 10, 10, 0.5, color);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}


void drawBarrel() {	
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 5);

	glColor3f(0.61, 0.37, 0.06);
	GLUquadric* top = gluNewQuadric();
	GLUquadric* bottom = gluNewQuadric();
	gluCylinder(top,2,3,3,20,20);

	glPushMatrix();
	glTranslatef(0, 0, 3);
	gluCylinder(bottom, 3, 2, 3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 0);
	glutSolidTorus(0.2, 2, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 6);
	glutSolidTorus(0.2, 2, 20, 20);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, 0, 0.4);
	glutSolidTorus(0.3, 2, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, 0, 5.6);
	glutSolidTorus(0.3, 2, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 0);
	drawCircle(0, 0, 2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 6);
	drawCircle(0, 0, 2);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void ladder() {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 5);
	GLfloat color[] = { 1,1,1 };

//	GLfloat color[] = { 0.51, 0.27, 0.16 };
	cube(-2, 0, 0, 0.5, 0.5, 20,color);
	cube(2, 0, 0, 0.5, 0.5, 20, color);
	cube(-2, 2, 0, 4, 0.5, 0.5, color);
	cube(-2, 4, 0, 4, 0.5, 0.5, color);
	cube(-2, 6, 0, 4, 0.5, 0.5, color);
	cube(-2, 8, 0, 4, 0.5, 0.5, color);
	cube(-2, 10, 0, 4, 0.5, 0.5, color);
	cube(-2, 12, 0, 4, 0.5, 0.5, color);
	cube(-2, 14, 0, 4, 0.5, 0.5, color);
	cube(-2, 16, 0, 4, 0.5, 0.5, color);
	cube(-2, 18, 0, 4, 0.5, 0.5, color);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void fence() {
	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 5);
	GLfloat color[] = { 1,1,1 };

//	GLfloat color[] = { 0.51, 0.27, 0.16 };
	//cube(-2, 0, 0, 0.5, 0.5, 20, color);
	cube(2, 0, 0, 0.5, 0.5, 20, color);
	cube(-2, 2, 0, 4, 0.5, 0.5, color);
	cube(-2, 4, 0, 4, 0.5, 0.5, color);
	cube(-2, 6, 0, 4, 0.5, 0.5, color);
	cube(-2, 8, 0, 4, 0.5, 0.5, color);
	cube(-2, 10, 0, 4, 0.5, 0.5, color);
	cube(-2, 12, 0, 4, 0.5, 0.5, color);
	cube(-2, 14, 0, 4, 0.5, 0.5, color);
	cube(-2, 16, 0, 4, 0.5, 0.5, color);
	cube(-2, 18, 0, 4, 0.5, 0.5, color);
	cube(-2, 0, 0, 4, 0.5, 0.5, color);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();	glPopMatrix();
}

void fence2() {
	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 5);
	GLfloat color[] = { 1,1,1 };

	//	GLfloat color[] = { 0.51, 0.27, 0.16 };
		//cube(-2, 0, 0, 0.5, 0.5, 20, color);
	cube(0, 0, 0, 0.5, 0.5, 20, color);
	cube(-2, 2, 0, 4, 0.5, 0.5, color);
	cube(-2, 4, 0, 4, 0.5, 0.5, color);
	cube(-2, 6, 0, 4, 0.5, 0.5, color);
	cube(-2, 8, 0, 4, 0.5, 0.5, color);
	cube(-2, 10, 0, 4, 0.5, 0.5, color);
	cube(-2, 12, 0, 4, 0.5, 0.5, color);
	cube(-2, 14, 0, 4, 0.5, 0.5, color);
	cube(-2, 16, 0, 4, 0.5, 0.5, color);
	cube(-2, 18, 0, 4, 0.5, 0.5, color);
	cube(-2, 0, 0, 4, 0.5, 0.5, color);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();	glPopMatrix();
}

void feedingPen() {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 5);
	GLfloat color[] = { 1,1,1 };

	//GLfloat color[] = { 0.50, 0.33, 0 };
	cube(-14.5, 0, -14.5, 3, 0.5, 3, color);
	cube(-14.5, 0, -0.5, 3, 0.5, 3, color);
	cube(-14.5, 0.5, -14.5, 3, 14, 0.5, color);
	cube(-14.5, 0, -14.5, 0.5, 14, 3, color);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void water() {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 3);
	GLfloat color[] = { 1,1,1 };
	//GLfloat color[] = { 0.52, 0.52, 0.47 };
	cube(-14.5, 0, 1, 3, 0.5, 2, color);
	cube(-14.5, 0, 5.5, 3, 0.5, 2, color);
	cube(-14.5, 0.5, 1, 3, 5, 0.5, color);
	cube(-14.5, 0, 1, 0.5, 5, 2, color);
	cube(-11.5, 0, 1, 0.5, 5, 2, color);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	GLfloat color1[] = { 0.47, 0.72, 0.89 };
	cube(-14, 0.5, 1.5, 2.5, 4, 1,color1);
	glPopMatrix();
}

void incubator() {
	GLfloat color[] = { 0.52, 0.52, 0.47 };
	cube(-14.5, 0, 1, 3, 0.5, 3, color);
	cube(-14.5, 0, -0.5, 3, 0.5, 3, color);
	cube(-14.5, 0.5, 1, 3, 5, 0.5, color);
	cube(-14.5, 0, 1, 0.5, 5, 3, color);
	cube(-11.5, 0, 1, 0.5, 5, 3, color);
}

void hay() {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 2);

	GLfloat color[] = { 0.82, 0.75, 0.32 };
	cube(8.5, 0, -14.5, 6, 6, 6, color);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void crate() {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 8);
	GLfloat color[] = { 1,1,1 };

//	GLfloat color[] = { 0.82, 0.75, 0.32 };
	cube(-8, 15.5, -14.5, 4, 4, 4, color);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void egg() {
	glPushMatrix();
	glColor3f( 0.92, 0.93, 0.89 );
	glScalef(0.8, 1, 0.8);
	glutSolidSphere(0.5, 10, 10);
	glPopMatrix();
}

void pitchfork() {
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, 1);
	GLfloat color[] = { 0.5, 0.3, 0.07 };
	cube(-0.3,-0.1,-0.2,0.6,0.2,0.2,color);
	GLfloat color1[] = { 0.3, 0.3, 0.3 };
	cube(-0.5, -0.1, 4, 1, 0.2, 0.2, color1);
	glColor3f(0.5, 0.3, 0.07);
	GLUquadric* pole = gluNewQuadric();
	gluCylinder(pole, 0.1, 0.1, 4, 20, 20);

	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(-0.3, 0, 4.2);
	glutSolidCone(0.1, 1, 20, 20);
	glTranslatef(0.3, 0, 0);
	glutSolidCone(0.1, 1, 20, 20);
	glTranslatef(0.3, 0, 0);
	glutSolidCone(0.1, 1, 20, 20);
	glPopMatrix();

	glPopMatrix();
}

void stones() {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 3);
	GLfloat color[] = { 1,1,1 };

//	GLfloat color[] = { 0.5, 0.3, 0.07 };
	cube(5, 0, 3, 2, 0.5, 3, color);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void blocks() {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	GLfloat color[] = { 1,1,1 };
	cube(15.5, 0.5, -10, 4, 2, 2, color);
	cube(15.5, 2.5, -10, 4, 2, 2, color);
	cube(15.5, 0.5, -6, 4, 2, 2, color);
	cube(16.5, 2.5, -6.5, 4, 2, 2, color);
	cube(17, 0.5, -3, 4, 2, 2, color);
	cube(16, 2.5, -4, 4, 2, 2, color);
	cube(16.5, 4.5, -5, 4, 2, 2, color);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void label() {
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, 1);
	GLfloat color[] = { 0.5, 0.3, 0.07 };
	cube(-1, -0.1, -0.2, 2, 1, 0.2, color);
	glColor3f(0.5, 0.3, 0.07);
	GLUquadric* pole = gluNewQuadric();
	gluCylinder(pole, 0.1, 0.1, 4, 20, 20);

	glPopMatrix();
}

void scarecrow() {
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, 1);
	GLfloat color[] = { 0.5, 0.3, 0.07 };
	cube(-3, 0, 0, 6, 0.2, 0.2, color);
	glColor3f(1, 0.66, 0);
	GLUquadric* body = gluNewQuadric();
	gluCylinder(body, 0.5, 1, 1.5, 20, 20);
	glColor3f(0.5, 0.3, 0.07);
	GLUquadric* pole = gluNewQuadric();
	gluCylinder(pole, 0.1, 0.1, 4, 20, 20);
	glPushMatrix();
	glTranslatef(0, 0, -0.5);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	//eyes
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(-0.2, 0.5, -0.5);
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(0.4, 0, 0);
	glutSolidSphere(0.5, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-0.3, 0.8, -0.5);
	glutSolidSphere(0.2, 20, 20);
	glTranslatef(0.6, 0, 0);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();

	glPopMatrix();
}