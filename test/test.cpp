#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void renderScene(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glBegin(GL_QUADS);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(-0.5,  0.5, 0.0);
    glVertex3f( 0.5,  0.5, 0.0);
    glVertex3f( 0.5, -0.5, 0.0);
  glEnd();

  glutSwapBuffers();
}

void changeSize(int w, int h)
{
  if (h == 0)
  {
    h = 1;
  }
  float ratio = 1.0* w / h;

  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();

  glViewport(0, 0, w, h);

  gluPerspective(45, ratio, 1, 1000);

  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("GLUT test");

  glutDisplayFunc(renderScene);

  glutReshapeFunc(changeSize);

  glutMainLoop();

  return 0;
}
