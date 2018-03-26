#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
GLfloat gAngle = 0.0;
static int ortho = 0;
 
static void display(void) {
    aa(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glutWireCube(2);
    if (ortho) {
    } else {
        /* This only rotates and translates the world around to look like the camera moved. */
        gluLookAt(0.0, 0.0, -3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    }
    glColor3f(1.0f, 1.0f, 1.0f);
        gAngle+=.5;
    glRotatef(gAngle,1,1,1);
    glutWireCube(2);


    glFlush();
}

static void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (ortho) {
        glOrtho(-2.0, 2.0, -2.0, 2.0, -1.5, 1.5);
    } else {
        glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    }
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    if (argc > 1) {
        ortho = 1;
    }
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    aaColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return EXIT_SUCCESS;
}