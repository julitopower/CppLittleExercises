#include <iostream>

#include <GL/glut.h>

#include "Particle.hpp"
#include "ParticleEngine.hpp"

// Dirty global ParticleEngine
ParticleEngine p = ParticleEngine(0.0f, 0.2f);

void init(int argc, char **argv);
void display();

int main(int argc, char **argv) {
  std::cout << "Particle engine test" << std::endl;
  init(argc, argv);
  return 0;
}

void init(int argc, char **argv) {

  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  // Windows size :)
  glutInitWindowSize(800, 600);

  // Initial Position
  glutInitWindowPosition(100, 100);

  // I don't really know what this does
  glutInit(&argc, argv);

  // The title of the window
  glutCreateWindow("Particle engine test");

  // The callback function that is call in every loop
  glutDisplayFunc(display);

  // Start the loop
  glutMainLoop();
}

void display() {

  // Clear the color buffer. The screen is in double buffer mode
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1, 1, 1);

  p.addParticles(2);
  p.update();
  p.render();

  // Swap the background buffer with the onscreen one
  glutSwapBuffers();
  glutPostRedisplay();
}
