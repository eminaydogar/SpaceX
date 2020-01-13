
#include "glut.h"


float gezX=0,gezZ=0,yedek=0,h=1;;
float rotplanet=0;
int scale = 1;
float a = 0.1, b = 0.1;
int state=0;
float fx=0.5, fy=0.5, px=-0.5, py=-0.5;
float i=0.3;
float x=0.6;

float planet []={0.89, 0.67, 0.30};
float planett []={0, 0, 0.6};
float kirmizi[]={1,0,0};

void drawPlanet(float size,float tx,float ty, float tz){

glPushMatrix();
glMaterialfv(GL_FRONT,GL_DIFFUSE,planett);
glMaterialfv(GL_FRONT,GL_AMBIENT,planet);
glTranslatef(i*tx,i*ty,i*tz);
glRotatef(rotplanet+=1,0,1,0);
glutSolidSphere(size/2, 80, 80);
glEnd();
glFlush();
glPopMatrix();

}
	


void uydu()
{
	
glPushMatrix();
glMaterialfv(GL_FRONT,GL_AMBIENT,kirmizi);
glMaterialfv(GL_FRONT,GL_DIFFUSE,kirmizi);
glColor3f(0,0,0);
glRotatef(30,0,1,0);
glTranslatef(-1,2,-10);
glutWireTorus(0.1, 1, 55, 1000);
glPopMatrix();
  

}

void draw4planet()
{
	
glPushMatrix();
drawPlanet(1,-18.5,6.5,-25);
drawPlanet(0.4,9,1.7,-10);
drawPlanet(0.6,12,4,-10);
drawPlanet(0.6,15,-4,-20);
glPopMatrix();

}
