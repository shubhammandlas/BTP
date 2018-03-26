/* BASIC 3-D Program

This program introduces the viewing mode called perspective.  The
program draws a simple BOX and a sphere, but utilizes the concept
of depth buffering so that objects in the background are drawn
first and objects in the foreground drawn last.  This gives the
proper overlap and the appearance of depth.  The program also uses 
"double buffering" which allows for smooth animation.

*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <GL/glut.h>

// Some constants related to the lighting
float light_diffuse[] = {2.0, 2.0, 1.0, 1.0};
float light_position[] = {10.0, 5.0, 5.0, 0.0};

float spin = 0.0;

// Window variables
int window; 


void drawroutine(void) // Display routine for Window 
{
  aaColor(0.4, 0.4, 0.6, 1.0);
  aa(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
  glPushMatrix();
    glRotatef(spin, 0.0, 1.0, 0.0);
    glutWireCube(3.0);
  glPopMatrix();
    glutSolidSphere( 1.0,  20,  20);
  glFlush();
  glutSwapBuffers();
}

void display(void)  // Initial Window 1 display calls the other routine
{
  glPushMatrix();
    glTranslatef(0.0, 0.0, -3.0);
    drawroutine();
  glPopMatrix();

}
 

// Simple Mouse Function to Rotate Box
void mouse(int button, int state, int x, int y)
{
  if ((button == 2) && (state == GLUT_DOWN)) spin += 2.0;
  if ((button == 0) && (state == GLUT_DOWN)) spin -= 2.0;
  glutPostRedisplay();
}


void init(void)
{
// This enables some of the the characteristics needed for lighing
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

// This enables Z-Buffering.  This quatilty draws things in the foreground last.
  glEnable(GL_DEPTH_TEST);

// This enables perspective rather than orthographic projection
//    gluPerspective (Angle, Aspect Ratio, Near Clipping, Far Clipping)
  glMatrixMode(GL_PROJECTION);
  gluPerspective( 40.0, 1.0, 1.0,  20.0);
  glMatrixMode(GL_MODELVIEW);

// gluLookAt(Eye_X, Eye_Y, Eye_Z, View_X, View_Y, View_Z, Up_X, Up_Y, UpZ)
  gluLookAt(0.0, 0.0, 5.0,  0.0, 0.0, 0.0,  0.0, 1.0, 0.); 
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);

// This is essential for Double Buffering, RGB Color, and Depth Testing
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

// Create Window
  window = glutCreateWindow("3-D Window");
  glutMouseFunc(mouse);
  init();
  glutDisplayFunc(display);

  glutMainLoop();
  return 0;          
}

