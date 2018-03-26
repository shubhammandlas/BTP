// #include <windows.h>
#include <iostream>
#include <fstream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

// #include <gl/Gl.h>
// #include <gl/Glu.h>
// #include <gl/glut.h>
#include <math.h>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <time.h>
// usleep(3000000);
clock_t t;
int count=0;
time_t start_t, end_t,now;
ofstream myfile;
GLfloat x=-2.0;
GLfloat gAngle = 0.0;
// myfile.open ("moving.txt");
void myIdle();
void myDisplay();

// struct TVector
// {
// float x,y,z;
// };

// struct TObject3D
// {
// TVector position;
// TVector velocity;
// };

// TObject3D sphere;
 
// #define GRAVITY 10.0

// void RunPhysics(float dt)
// {
// 	sphere.velocity.y=sphere.velocity.y-GRAVITY*dt;

// 	sphere.position.x=sphere.position.x+sphere.velocity.x*dt;
// 	sphere.position.y=sphere.position.y+sphere.velocity.y*dt;
// 	sphere.position.z=sphere.position.z+sphere.velocity.z*dt;


// 	if (sphere.velocity.y<0)
// 	{
	 
// 		if (sphere.position.y<0.5)
// 		{
			 
// 			if ((sphere.position.x>-2) && (sphere.position.x<-1.2))
// 				sphere.velocity.y=-sphere.velocity.y;
// 		}
			 
// 		if (sphere.position.y<-0.9) 
// 			sphere.velocity.y=-sphere.velocity.y;
			 
// 	}
	
	
 
// }
 
void myInit()
{
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluPerspective(60.0, 64/48.0, 0.1, 100);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	gluLookAt(0,0, 5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	 
	glColor3d(0,0,0);
}
 
void myIdle()
{
// RunPhysics(0.01);
myDisplay();
 
}
 
void myDisplay(void)
{
if(x==-2){
t=clock();	
printf("were%d \n",clock());
// time(&start_t);
}
count++; 
glClear(GL_COLOR_BUFFER_BIT);
// glBegin(GL_LINE_LOOP); // Draw Platform

// glVertex3d(0.8,-0.9,0.5); 
// glVertex3d(0.8,0.9,0.5);
// glVertex3d(-1.8,0.9,0.9);
// glVertex3d(-1.8,-0.9,0.9);
// glEnd();
glPushMatrix();
x=x+.03;
gAngle += 1;

// glutWireCube(1.);
glTranslated(x,0,0);
// glRotatef(gAngle,0,0,1);

//  // printf("sdfs	%f\n",x);

glBegin(GL_LINES);
    glVertex3f(0,-2,0);
    glVertex3f(0,2.00,0);

    
glEnd();   
 // printf("hola	%f\n",x);
// glBegin(GL_LINE_LOOP); 
// glVertex3d(-2.0, 0.1, 0.5); // Draw little Bar
// glVertex3d(-2.0, 0.3,0.5);
// glVertex3d(-1.2, 0.3,0.5);
// glVertex3d(-1.2, 0.1,0.5);
 
// glEnd();
 
// glPushMatrix(); // draw and place Sphere
// glTranslated(sphere.position.x,sphere.positi/a.outon.y,sphere.position.z);
 
// glutSolidSphere(0.2, 15, 15);
// myfile.open ("moving.txt");
if(x>3.9){
	myfile.close();
	t=clock()-t;
	time(&end_t);
	// printf("hola	%d %d %f \n",t,count,((float)t)/CLOCKS_PER_SEC);
	 cout << t/(double)CLOCKS_PER_SEC << endl;
	// return();
	exit(0);

}
myfile << x <<"," << clock() <<"\n";
// myfile.close();
glPopMatrix();
glutSwapBuffers();
// printf("%ld\n",clock());
usleep(30000);

}

int main(int argc, char **argv)
{
// sphere.position.x=-1.7;
// sphere.position.y=0.5;
// sphere.position.z=0.5;

// sphere.velocity.x=1;
// sphere.velocity.y=0;
// sphere.velocity.z=0;
// // ofstream myfile;(
// t=clock();	
myfile.open ("time.txt"); 
// printf("asda %f asda",CLOCKS_PER_SEC);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
glutInitWindowSize(640,480);
glutInitWindowPosition(50, 50);
glutCreateWindow("Rolling");
glutDisplayFunc(myDisplay);
glutIdleFunc(myIdle);
glClearColor(1.0f, 1.0f, 1.0f,0.0f);
glViewport(0, 0, 640, 480);
// sleep_for(10);
//glutKeyboardFunc(myKeyboard);
myInit();


glutMainLoop(); 
// t=clock()-t;
// printf("hola	%d %d",t,count);
return(0);
}