#include <windows.h>  // For MS Windows
#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


void display();
void gameDisplay();
void welcomeDisplay();
void reshape(int, int);
void keys();

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void keys(unsigned char key, int x, int y)
{
	if (key == 'x')
	{
		glutDisplayFunc(gameDisplay);

	}
	glutPostRedisplay();
}

   void myTimer(int val)
   {
	   glutDisplayFunc(gameDisplay);
	   glutPostRedisplay();
   }

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);

	glutInitWindowPosition(200,100);
	glutInitWindowSize(700, 500);

	
	glutCreateWindow("SpellingBEE Game");
	
	glutDisplayFunc(welcomeDisplay);
	// glutReshapeFunc(reshape);
	
	glutKeyboardFunc(keys);
	glutTimerFunc(2000, myTimer, 0);
	
	init();

	glutMainLoop();
	return 0;

}

void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	//draw
	glBegin(GL_POLYGON);

	glVertex2f(3.0, 3.0);
	glVertex2f(-3.0, 3.0);
	glVertex2f(-3.0, -3.0);
	glVertex2f(3.0, -3.0);


	glEnd();

	glFlush();
}

void gameDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1, 1, 1);
	glRasterPos3f(-0.5, 0.6, 0);

	char question[] = "Choose the correct spelling ";
	for (int i = 0; i< strlen(question); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, question[i]);
		glutSwapBuffers();
	}

	//square
	glBegin(GL_POLYGON);

	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);


	glEnd();

	glFlush();

	//question one
	char choice1[] = "A. acommodate";
	char choice2[] = "B. accommodate";
	char choice3[] = "C. acommodete";
	char choice4[] = "D. accomodate";


	/*string select[] = { choice1,choice2,choice3,choice4 };

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < strlen(select[j]); i++) {
		string choice=select[j];
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, choice[i]);
		glutSwapBuffers();
	}
	}*/

	glColor3f(0, 0, 0);

	//choice A
	glRasterPos3d(-0.45, 0.20, 0);

	for (int i = 0; i<strlen(choice1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, choice1[i]);
		glutSwapBuffers();
	}

	//choice B
	glRasterPos3d(0.05, 0.20, 0);

	for (int i = 0; i < strlen(choice2); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, choice2[i]);
		glutSwapBuffers();
	}

	//choice C
	glRasterPos3d(-0.45, -0.20, 0);

	for (int i = 0; i < strlen(choice3); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, choice3[i]);
		glutSwapBuffers();
	}

	//choice D
	glRasterPos3d(0.05, -0.20, 0);

	for (int i = 0; i < strlen(choice4); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, choice4[i]);
		glutSwapBuffers();
	}
	

	//Exit game
	glColor3f(1, 1, 1);
	glRasterPos3f(-0.5, -0.8, 0);

	char exit[] = " Press X to go back to main menu ";
	for (int i = 0; i < strlen(exit); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, exit[i]);
		glutSwapBuffers();
	}
	
      

	
}
void welcomeDisplay() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1, 0, 0);

	glRasterPos3f(-0.8, 1.5, 0);
	char msg1[] = "Welcome to spellingBEE";
	for (int i = 0; i < strlen(msg1); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg1[i]);

	glColor3f(0, 0, 1);
	glRasterPos3f(-0.8, -1.5, 0);
	char msg2[] = "Press X to Start the game";
	for (int i = 0; i < strlen(msg2); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg2[i]);



	glutSwapBuffers();

}



void reshape(int w, int h) 
{
	//viewport
	glViewport(0,0,(GLsizei)w,(GLsizei)h);

	//projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5, 5, -7, 7);
	glMatrixMode(GL_MODELVIEW);
	

}
