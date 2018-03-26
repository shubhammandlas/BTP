#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
class wcPt2d{
	public :
	GLfloat x,y;
};
void initLighting()
{

    // Enable lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

     // Set lighting intensity and color
       glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
    

}
void setPixel(GLint xCoord,GLint yCoord){
	glBegin(GL_POINTS);
	glVertex2i(xCoord,yCoord);
	glEnd();
}
int main(int argc, char ** argv){
	glutInit(&argc, argv); 
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(350,350);
    glutCreateWindow("Solid Sphere");
    // initLighting(); 
	setPixel(10,50);
	return 0;
}