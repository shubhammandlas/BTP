#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
 
GLfloat gAngle = 0.0;
GLfloat p;
GLUquadricObj *IDquadric;
int arr[50][3],i=0; 
// printf("sdff");
// printf("i=%d  %d  holllllla\n",i,arr[4][2]);
void timer(int value)
{
  printf("i=%d  %d  hollllllla\n",i,arr[4][2]);
  const int desiredFPS=150;
  glutTimerFunc(1000/100, timer, ++value);
  GLfloat dt = 10./desiredFPS;
 
  //put your specific idle code here
  //... this code will run at desiredFPS
  gAngle += .05*360./8.; //rotate 360 degrees every 8 seconds
  //end your specific idle code here
  // gAngle += .2;
 p+=.09;
  glutPostRedisplay(); // initiate display() call at desiredFPS rate
}
 
void display() {
  // printf("i=%d  %d  holllllla\n",i,arr[4][2]);
  glClear(GL_COLOR_BUFFER_BIT);
  arr[i][2]=p;
  i++;
    glPushMatrix();
    glTranslatef(0,0,-105 );
    // glTranslatef(0,0,p);
    glRotatef(gAngle,1,1,1);
    glutWireCube(10.); //cube of size 20x20x20
    //gluCylinder(IDquadric,10.0f,10.0f,10.0f,32,32);
  // glBegin(GL_LINES);
  //   glVertex3f(0,0,0);
  //   glVertex3f(0,5.75,0);
    
  // glEnd();  
    printf("%dhey  i=%d\n",arr[i][2],i);
    glPopMatrix();
    
    glutSwapBuffers();
}
 
void cleanupQuadric(void)          // Properly Kill The Window
{
  gluDeleteQuadric(IDquadric);
  printf( "cleanupQuadric completed\n" );
}
 
void init() {
  // printf("i=%d  %d  hoooooola\n",i,arr[4][2]);
  glClearColor(0.0, 0.0, 0.0, 0.0);
 
  IDquadric=gluNewQuadric();      // Create A Pointer To The Quadric Object ( NEW )
  gluQuadricNormals(IDquadric, GLU_SMOOTH);  // Create Smooth Normals ( NEW )
  gluQuadricTexture(IDquadric, GL_TRUE);    // Create Texture Coords ( NEW )
  atexit(cleanupQuadric);
  
  GLdouble Vol = 10*1.8;
  GLdouble Left=-Vol;
  GLdouble Right=Vol;
  GLdouble Bottom=-Vol;
  GLdouble Top=Vol;
  GLdouble Near=0;
  GLdouble Far=2*Vol;
 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(Left, Right, Bottom, Top,  Near, Far);
 
  GLdouble eyeX=0;
  GLdouble eyeY=0;
  GLdouble eyeZ=-100+Vol;
  GLdouble centerX=0;
  GLdouble centerY=0;
  GLdouble centerZ=-100;
  GLdouble upX=0;
  GLdouble upY=1;
  GLdouble upZ=0;
 
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(eyeX,eyeY,eyeZ,centerX,centerY,centerZ,upX,upY,upZ);
}
 
void keyboard(unsigned char key, int x, int y)
{
  
   switch (key) {
      case 27:  // escape key
         exit(0);
         break;
      default:
         break;
   }
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE);
   glutCreateWindow("FPS test /w glutTimerFunc");
   glutInitWindowSize(400,400);
   glutTimerFunc(0,timer,0);
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   // printf("i=%d  %d  hola\n",i,arr[4][2]);
   init();
   // printf("i=%d  %d  hola\n",i,arr[4][2]);
   glutMainLoop();
   
   return 0;
}



