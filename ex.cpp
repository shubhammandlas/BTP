#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
GLfloat gAngle = 0.0;
void Draw(){
	aa(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glTranslatef(0,0,-50 );
	glPushMatrix();
	glBegin(GL_LINES);
		glVertex3f(.25,.25,0) ;
		glVertex3f(.75,.75,0) ;
	// glutWireCube(20.);	
	gAngle+=.1;	
	glRotatef(gAngle,0,0,1);	
	glEnd();	
	glFlush();	
}

void make(){
	aaColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20,20,-20,20,0,40);
	gluLookAt(0,0,-90,0,0,-90,0,1,0);
}

void keyboard(unsigned char key, int x, int y)
{

   switch (key)  {
      case 27:  // escape key
         exit(0);
         break;
      default:
         break;
   } 

}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   // glutInitWindowSize(350,350);
    glutInitWindowPosition(700,200);
	// glutCreateWindow("FPS test /w glutTimerFunc");
   int i;
   glutCreateWindow("FPS test /w glutTimerFunc");
  
	   make();
	   glutDisplayFunc(Draw);
	   // glutIdleFunc(myIdle);
	   
	   glutKeyboardFunc(keyboard);
	   glutMainLoop();
}   
