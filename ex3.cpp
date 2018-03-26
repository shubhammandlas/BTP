#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include <glut.h>
// #include <GL/glu.h>
// #include <GL/gl.h>
 
#include <GL/gl.h>
#include <GL/glut.h> 
 
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
 
}
 
void display()
{
	glClear( GL_COLOR_BUFFER_BIT );
	glBegin (GL_TRIANGLE_FAN);
		glVertex3f(0., 1.0, 0.);
		for (int i=0; i<20; i++)
		{
			float angle = 2. * (float)i*3.14/(float)20;
			glVertex3f(0.5*cos(angle), 0.0, 0.5*sin(angle));
		}
							 
	glEnd();
	glFlush();	
}
 
void reshape(int w, int h)
{
	glViewport (0,0,(GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
}
 
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

