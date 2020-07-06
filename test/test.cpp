#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void renderScene(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glBegin(GL_QUADS);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(-0.5,  0.5, 0.0);
    glVertex3f( 0.5,  0.5, 0.0);
    glVertex3f( 0.5, -0.5, 0.0);
  glEnd();

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

  glutMainLoop();

  return 0;
}
