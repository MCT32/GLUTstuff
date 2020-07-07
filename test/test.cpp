#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float angle = 0.0f;

void renderScene(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  //gluLookAt(	0.0f, 0.0f, 10.0f,
	//			      0.0f, 0.0f,  0.0f,
	//			      0.0f, 1.0f,  0.0f);

  glRotatef(angle, 0.0f, 0.0f, 1.0f);

  glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(-0.5f,  0.5f, 0.0f);
    glVertex3f( 0.5f,  0.5f, 0.0f);
    glVertex3f( 0.5f, -0.5f, 0.0f);
  glEnd();

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

  glutMainLoop();

  return 0;
}
