#include <cstdlib>
#include <iostream>

#include "Particle.hpp"

Particle::Particle(int ttl) : ttl{ttl} {
  x = 0.0f;
  y = 0.0f;
  init();
}

void Particle::setCoordinates(float newX, float newY) {
  x = newX;
  y = newY;
}

void Particle::setVelocity(float newVx, float newVy) {
  vx = newVx;
  vy = newVy;
}

void Particle::incrementCoordinates(float deltaX, float deltaY) {
  x += deltaX;
  y += deltaY;
}

void Particle::incrementVelocity(float deltaVx, float deltaVy) {
  vx += deltaVx;
  vy += deltaVy;
}

void Particle::init() {
  vx = 0.01 * ((float)rand() / (float)RAND_MAX);
  vy = 0.01 * ((float)rand() / (float)RAND_MAX);
  angle = rand() % 360;
  angularVelocity = rand() % 10;
}

void Particle::updatePosition(long deltaTime) {
  x += vx;
  y += vy;
}
