/*
 * 3DSphere.cpp
 *
 *  Created on: Oct 30, 2012
 *      Author: guptaa
 */
 
 
 
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

 
GLfloat mat_specular[] = {1.0, 1.0,1.0,1.0};
GLfloat mat_shininess[] = {50.0};
GLfloat light_position[] = {1.0,1.0,2.0,0.0};
 
void display(void)
{
    aa(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    glLoadIdentity();
    gluLookAt(0.0,1.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
     glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);    // This has to be light not material
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glTranslatef(0.5,0,0);
    glutSolidSphere(0.5,100,102);
    glTranslatef(-2,0,5);
    // glutSolidSphere(0.5,100,100);
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}
 
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0,2.0,-2.0*h/w,2.0*h/w,-10.0,10.0);
    else
        glOrtho(-2.0*w/h,2.0*w/h,-2.0,2.0,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
}
 
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Spheres");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}