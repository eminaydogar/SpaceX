
   #include "glut.h"

	float r=1;
	float sari[]={ 1,1,0.1,1};
    void drawRandomStar()
{
    	
    r+=0.3;
	if(r>5) r=1;
	
glMaterialfv(GL_FRONT,GL_AMBIENT,sari);

	glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(-5,1.7,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(2,-1.3,r);
	glutSolidCube(0.03);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.1,0.1,0.5);
	glTranslatef(-6.2,-2.27,r);
		glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
	glScalef(0.1,0.1,0.5);
	glTranslatef(-5.5,-2.7,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(6,2.17,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(5,3.4,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(-7.2,-3.37,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(-5.5,-2.97,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(-6.2,-3.7,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(5.2,4.7,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(5,3.7,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(5.5,-1.97,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(-6,2.7,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(5.6,4.7,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(-7,2.2,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(-6.32,5.7,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(-5.6,-2.1,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(-5.8,-1.3,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(6.31,2.8,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(4.91,5.2,r);
		glutSolidCube(0.03);
	glPopMatrix();
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(5.6,3.3,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
	
	
	
	
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(4.5,3.7,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(8,-5.3,r);
	glutSolidCube(0.03);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.1,0.1,0.5);
	glTranslatef(-8.2,-5.27,r);
		glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
	glScalef(0.1,0.1,0.5);
	glTranslatef(-9.5,-6.7,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(9,7.17,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(7,9.4,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(10.2,-3.37,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(-10.5,9.97,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(-6.2,8.7,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(-8.2,6.7,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(5,1.7,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(2.5,-1.97,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(-3,2.7,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(2.6,1.7,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(-7,6.2,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(-6.32,8.7,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(-5.6,-7.1,r);
	glutSolidCube(0.03);
	glPopMatrix();
	
	
		glPushMatrix();
glScalef(0.1,0.1,0.5);
	glTranslatef(-5.8,1.3,r);
	glutSolidCube(0.03);
	glPopMatrix();
	

	
	
 }
