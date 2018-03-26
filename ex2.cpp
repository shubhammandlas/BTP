#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include <glut.h>
// #include <GL/glu.h>
// #include <GL/gl.h>
 
#include <GL/gl.h>
#include <GL/glut.h> 
 // GLfloat gAngle = 0.0;
GLfloat i=0.0;
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
 
}
 
void display()
{
	
	glClear( GL_COLOR_BUFFER_BIT );
	// i+=.1;
	// aa( GL_COLOR_BUFFER_BIT );
	glBegin (GL_LINES);
		// for (i=0; i<=20; i=i+.015)
		// {
		

			// float angle = 2. * (float)i*3.14/(float)20;
			// rotate
			// aa(0.0 0.0, 0.0, 0.0);
					i+=.2;	

				glVertex3f(i, 0, 0);
				glVertex3f(i, 0.5, 0);
				// aa( GL_COLOR_BUFFER_BIT );
				// aaColor(0.0, 0.0, 0.0, 0.0);
		
			
			// glVertex3f(0.5*cos(angle), 0.0, 0.5*sin(angle));
		
		 	// aa( GL_COLOR_BUFFER_BIT );
		 	glEnd();
		 	glutSwapBuffers();
		 	
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
	// glutInit(&amp;argc, argv);
	int j=0;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(350,350);
	glutCreateWindow("lets go");
	

	for(j=0;j<20;j++){
		// glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		i+=.2;	
		init();
		glClear( GL_COLOR_BUFFER_BIT );
		glutDisplayFunc(display);
		// glutReshapeFunc(reshape);
		printf("%dhola\n",j);
		glutMainLoop();
		
	}	
printf("%dhp\n",j);
	return 0;
}

