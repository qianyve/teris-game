#include "GL/glut.h"
#include "Common.h"
#include "Win.h"
#include "Block.h"
#include "Figure.h"

Figure figure;
Win window;

void HandleKeyPress(unsigned char key,int x,int y)
{
	if(window.Get_status()){ 
	switch(key)
	{
	case 'a':
	case 'A':figure.Move_(-1,0);glutPostRedisplay();break;
	case 'd':
	case 'D':figure.Move_(1,0);glutPostRedisplay();break;
	case 'w':
	case 'W':figure.Rotate_(),glutPostRedisplay();break;
	case 's':
	case 'S':figure.Move_(0,-1);glutPostRedisplay();break;
	default:break;
	}
	}else{
	switch(key)
	{
	case 'n':window.New_();glutPostRedisplay();break;
	default:break;
	}
	}
}
void Update_(int value)
{
	if (window.Get_status())
	{
		int movesuccess=figure.Move_(0,-1);
		if (!movesuccess)
		{
			window.Update_();
			figure.New_(rand()%NUM_FIGURE);
		}
	}
	glutPostRedisplay();
	glutTimerFunc(500,Update_,0);
}
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	
	window.Draw_();
	
	if (window.Get_status()){
	figure.Draw_();	}
	glutSwapBuffers();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);

	glutInitWindowSize(WIN_WIDTH+100,WIN_HEIGHT+100);

	glutInitWindowPosition(0,0);
	
	glutCreateWindow("hello world");
	
	window.Reset_map(30,30,1);

	glClearColor( 0.0, 0.0, 0.0, 0.0 ) ;

	glMatrixMode(GL_MODELVIEW) ;  
	glLoadIdentity(); 
	gluOrtho2D(-50, (GLdouble)WIN_WIDTH+50, -50, (GLdouble)WIN_HEIGHT+50);
	//scrand(time(NULL));

	glutDisplayFunc(Display);
	
	glutKeyboardFunc(HandleKeyPress);
	
	glutTimerFunc(500,Update_,0);

	glutMainLoop();

	return 0;
}
