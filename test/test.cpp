#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float angle = 0.0f;

float red = 1.0f;
float green = 1.0f;
float blue = 1.0f;

void processKeys(unsigned char key, int x, int y)
{
  if (key == 27)
    exit(0);
  else if (key=='r')
  {
		int mod = glutGetModifiers();
		if (mod == GLUT_ACTIVE_ALT)
			red = 0.0;
		else
			red = 1.0;
	}
  else if (key=='g')
  {
		int mod = glutGetModifiers();
		if (mod == GLUT_ACTIVE_ALT)
			green = 0.0;
		else
			green = 1.0;
	}
  else if (key=='b')
  {
    int mod = glutGetModifiers();
    if (mod == GLUT_ACTIVE_ALT)
      blue = 0.0;
    else
      blue = 1.0;
  }
}

void processSpecialKeys(int key, int x, int y)
{
  switch (key)
  {
    case GLUT_KEY_F1 :
      red = 1.0f;
      green = 0.0f;
      blue = 0.0f; break;
    case GLUT_KEY_F2 :
      red = 0.0f;
      green = 1.0f;
      blue = 0.0f; break;
    case GLUT_KEY_F3 :
      red = 0.0f;
      green = 0.0f;
      blue = 1.0f; break;
  }
}

void renderScene(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  gluLookAt(	0.0f, 0.0f, 1.0f,
				      0.0f, 0.0f, 0.0f,
				      0.0f, 1.0f, 0.0f);

  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  GLfloat ambientLight[]   = {0.2f, 0.2f, 0.2f, 1.0f};
  GLfloat diffuseLight[]   = {0.8f, 0.8f, 0.8f, 1.0f};
  GLfloat spectularLight[] = {1.0f, 1.0f, 1.0f, 1.0f};
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
  glLightfv(GL_LIGHT0, GL_SPECULAR, spectularLight);

  GLfloat lightPosition[] = {0.5f, 0.5f, 0.5f, 1.0f};
  glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

  glRotatef(angle, 0.0f, 0.5f, 1.0f);

  glColor3f(red, green, blue);
  //glBegin(GL_QUADS);
  //  glVertex3f(-0.5f, -0.5f, 0.0f);
  //  glVertex3f(-0.5f,  0.5f, 0.0f);
  //  glVertex3f( 0.5f,  0.5f, 0.0f);
  //  glVertex3f( 0.5f, -0.5f, 0.0f);
  //glEnd();
  glutSolidCube(1.0f);

  angle += 0.1f;

  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("GLUT test");

  glutDisplayFunc(renderScene);
  glutIdleFunc(renderScene);

  glutKeyboardFunc(processKeys);
  glutSpecialFunc(processSpecialKeys);

  glutMainLoop();

  return 0;
}
