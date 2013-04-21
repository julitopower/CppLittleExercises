#include "ParticleEngine.hpp"
#include "Particle.hpp"
#include <list>
#include <iterator>
#include <iostream>
#include <GL/glut.h>

using namespace std;

ParticleEngine::ParticleEngine(float x, float y) {
	this->x = x;
	this->y = y;
}

void ParticleEngine::render() {
	for (list<Particle *>::iterator it = particlesList.begin() ; it != particlesList.end() ; it++) {
		Particle & p = *(*it);
		float x = p.getX() - 0.8f;
		float y = p.getY() - 0.8f;
		glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      			glColor3f(0.8f, 1.0/((float)p.getTTL()*0.05), 0.0f); // Red
      			glVertex2f(x - 0.01f, y - 0.01f);    // x, y
      			glVertex2f(x + 0.01f, y - 0.01f);
      			glVertex2f(x + 0.01f, y + 0.01f);
      			glVertex2f(x - 0.01f, y + 0.01f);
   		glEnd();
	}
}


void ParticleEngine::update() {
	for (list<Particle *>::iterator it = particlesList.begin() ; it != particlesList.end() ;) {
		if ((*it)->getTTL() == 0) {
			delete *it;
			it = particlesList.erase(it);	
		} else {
			(*it)->updatePosition(100);
			(*it)->decreaseTTL();
			it++;
		}
	}
}

void ParticleEngine::addParticles(int numberOfParticles) {
	for(int i = 0 ; i < numberOfParticles ; i++) {
		particlesList.push_front(new Particle(200));	
	}
}

