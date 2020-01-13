
#include <windows.h>
#include "glut.h"
#include "glm.c"
#pragma comment(lib, "WINMM.lib")
#include "stars.c"
#include "planets.c"
#include <ctime>



GLMmodel* pmodel = NULL;

int cammood=2;
int counter=0;	
float sinir=0.85;
float x_move;
float bulletcolor[]={1,0,0};
int bulletsayac=0;
float ztarget=0;
float xtarget=-0.1;

float isik_yer[] = {0, 0, 2};
float yesil[]={0, 1, 0, 1};


float targetxloc[]={-0.3,-0.25,-0.15,-0.1,0.1,0.15,0.25,0.3};

 bool globalbool=true;
 
class bullet {
public:
	float bz;
	bool visible=false;
    float x_bullet;
    
     drawbullet(int i){
 	if(visible)
	 {
 	if(bz>=-5)
	{
 	glPushMatrix();
 	glRotatef(180,0,0,1);
 	glMaterialfv(GL_FRONT,GL_DIFFUSE,bulletcolor);
    glMaterialfv(GL_FRONT,GL_AMBIENT,bulletcolor);
	glTranslatef(x_bullet,0,bz+=-0.2);
	glutSolidCone(0.02,0.02,50,50);
	glPopMatrix(); 
	}
	else {bz=0; visible=false;}
	 }
	 else x_bullet=x_move;
 
	
}
};

bullet mybullet[50];


void init(void)
{
	gluLookAt(0, 0.3,3, 0, 0, 0, 0, 2, 0);
   GLfloat light0_position[] = { 0.45, 0.61, 0.66, 0 };
   GLfloat light0_color[] = { 0.65, 0.64, 0.53, 0.15 };
   
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);

   glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
   glLightfv(GL_LIGHT0, GL_AMBIENT, light0_color);
   
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
   
}



void displaybullet()
{
for(int j=0; j<=50; j++)
mybullet[j].drawbullet(i);
}

void drawtarget(bool x=true)
{
if(x==true)
{
if(ztarget<=1.8){
glPushMatrix();
glMaterialfv(GL_FRONT,GL_AMBIENT,yesil);
glTranslatef(xtarget,0.2,ztarget+=0.015);
glutSolidCube(0.1);
glPopMatrix();  }
else exit(0);
}	
}


void shooting(){
for(int i=0; i<=50; i++){
if(-mybullet[i].x_bullet>0){
if (mybullet[i].visible==true && mybullet[i].bz<=-3 && -mybullet[i].x_bullet>=xtarget+xtarget && -mybullet[i].x_bullet<=xtarget+3*xtarget )
{ globalbool=false; mybullet[i].visible=false; ztarget=0; counter++; }}
else{
if (mybullet[i].visible==true && mybullet[i].bz<=-3 && -mybullet[i].x_bullet<=xtarget+xtarget && -mybullet[i].x_bullet>=xtarget+3.8*xtarget ){
globalbool=false; mybullet[i].visible=false; ztarget=0; counter++; }}}}


void drawmodel(char* nesne)
{
    pmodel = glmReadOBJ(nesne);
    if (!pmodel) exit(0);
    glmUnitize(pmodel);
    glmFacetNormals(pmodel);
    glmVertexNormals(pmodel, 90.0);
    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}


void timer(int value)
{
srand(time(0));
if(globalbool==false )
 {
 globalbool=true; 
 int yedek = rand()%7;
 xtarget=targetxloc[yedek];
 }	
  glutTimerFunc(1000, timer, 0);
}


void mydisplay(){
glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


draw4planet();
uydu();
drawRandomStar();
displaybullet();

shooting();
drawtarget(globalbool);

glPushMatrix();
glRotatef(180,0,1,0);
glScalef(0.5,0.5,0.5);
glTranslatef(x_move,0,0);
drawmodel("f-16.obj");
glPopMatrix();


glutSwapBuffers();
}


void keyboard (int key, int x, int y){
switch(key)
{
	case GLUT_KEY_RIGHT:
	if(x_move>=-sinir){x_move -=0.05;}
	break;
	
	case GLUT_KEY_LEFT:
	if(x_move<=sinir){x_move +=0.05;}
	break;
			
}
	glutPostRedisplay();
}

void mouse(int button,int state,int x, int y){
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
	mybullet[bulletsayac].visible=true;
	bulletsayac++;
	if(counter>=45) {bulletsayac=0; counter=0;}
	}
	
	glutPostRedisplay();
	
}



void reshape(int w, int h)
{
float ratio = (float)w / h;
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glViewport(0, 0, w, h);
gluPerspective(45, ratio, -1.0, 1.0);
glMatrixMode(GL_MODELVIEW);
}




int main(int argc, char** argv){

 glutInitWindowSize (1550, 1150);
glutInitWindowPosition(0,1);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutCreateWindow("G�kta��");    
init();
glutDisplayFunc(mydisplay);
glutSpecialFunc(keyboard);
glutTimerFunc(1000, timer, 0);
glutMouseFunc(mouse);
glutIdleFunc(mydisplay);
PlaySound(TEXT("soundx.wav"),NULL,SND_ASYNC);
glutReshapeFunc(reshape);
glutMainLoop();
}


