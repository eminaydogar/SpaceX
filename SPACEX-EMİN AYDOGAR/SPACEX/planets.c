
#include "glut.h"
#include <windows.h>

GLuint tex[2];
GLUquadric* sphere;

float rot=1;
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

 GLubyte mode=0;					// Doku kaplamada Env Mode deðiþimi için kullanýlacak
GLboolean sm=0;					// Shade Model deðiþimi için kullanýlacak (0:FLAT, 1: SMOOTH)
GLuint texName[3];				// 3 farklý görüntü kaplanacaðý için texName dizi olacak
GLubyte checkImage[64][64][4];  // Satranç tahtasýnýn saklanacaðý dizi (alpha var: [4])
GLubyte *data;					// BMP içindeki BGR (RGB deðil) verisinin saklanacaðý yer
// BMP dosyasýnýn baþlýðýndan alýnan deðerler için:
GLubyte header[54];				// BMP dosyalarý 54-byte header içerir
GLuint dataPos;					// Piksel verilerinin baþlangýç adresi
GLuint width, height;			// BMP'nin geniþliði ve yüksekliði saklanacak
GLuint imageSize;			
 
 
 


	
	 GLuint loadBMP_custom(const char * imagepath){
	// Open the file
	FILE * file = fopen(imagepath, "rb");
	if (!file){
		printf("Image could not be opened\n"); 
		return 0;
	}
	if ( fread(header, 1, 54, file)!=54 ){ // If not 54 bytes read : problem
		printf("Not a correct BMP file\n");
		return 0;
	}
	if ( header[0]!='B' || header[1]!='M' ){
		printf("Not a correct BMP file\n");
		return 0;
	}
	// Read ints from the byte array
	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);
	// Some BMP files are misformatted, guess missing information
	if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos==0)      dataPos=54; // The BMP header is done that way

	// Create a buffer
	data = new unsigned char [imageSize];
	// Read the actual data from the file into the buffer
	fread(data,1,imageSize,file);
	//Everything is in memory now, the file can be closed
	fclose(file);
}
 
	
	
void make_tex(void)
{
 
  glGenTextures(2, tex);
 
    loadBMP_custom("d.bmp"); 
    glBindTexture(GL_TEXTURE_2D, tex[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, (const GLvoid *) data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
     loadBMP_custom("mcqueen.bmp"); 
    glBindTexture(GL_TEXTURE_2D, tex[1]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, (const GLvoid *) data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    
}


void drawPlanet(float size,float tx,float ty, float tz){

glPushMatrix();
glMaterialfv(GL_FRONT,GL_DIFFUSE,planett);
glMaterialfv(GL_FRONT,GL_AMBIENT,planet);
glTranslatef(i*tx,i*ty,i*tz);
glRotatef(rotplanet+=rot,0,1,0);
gluSphere(sphere,size/2, 100, 150);
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
//drawPlanet(1,-18.5,6.5,-25);
//drawPlanet(0.4,9,1.7,-10);
//drawPlanet(0.6,12,4,-10);
//drawPlanet(0.6,15,-4,-20);

void draw4planet()
{
	glEnable(GL_TEXTURE_2D);


	glPushMatrix();	
    gluQuadricDrawStyle(sphere, GLU_FILL);
    glBindTexture(GL_TEXTURE_2D, tex[0]);
    gluQuadricTexture(sphere, GL_TRUE);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    drawPlanet(1,-18.5,6.5,-25);
   drawPlanet(0.4,9,1.7,-10);
	glPopMatrix();
	
		glPushMatrix();	
    gluQuadricDrawStyle(sphere, GLU_FILL);
    glBindTexture(GL_TEXTURE_2D, tex[1]);
    gluQuadricTexture(sphere, GL_TRUE);
    gluQuadricNormals(sphere, GLU_SMOOTH);
	   drawPlanet(0.6,12,4,-10);
   drawPlanet(0.6,15,-4,-20);
   	glPopMatrix();
   	
    glDisable(GL_TEXTURE_2D);

}
