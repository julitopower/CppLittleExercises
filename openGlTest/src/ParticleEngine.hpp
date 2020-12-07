#ifndef PARTICLE_ENGINE_H
#define PARTICLE_ENGINE_H

#include <list>

#include "Particle.hpp"

class ParticleEngine {
private:
  // This coordinates are "absolute"
  float x;
  float y;
  long lastUpdateTime;
  std::list<Particle *> particlesList;

public:
  ParticleEngine(float x, float y);
  
  /*
   * This method is responsible for updating the position
   * and velocities of each particle
   */
  void update();

  /*
   * Guess what this method does
   */
  void render();

  void addParticles(int numberOfParticles);
};

#endif
