#ifndef PARTICLE_H
#define PARTICLE_H

/*
 * A particle is a tiny dot in the space :) (2d space actually)
 * The (x,y) coordinates of a particle are relative to the position of the
 * particle emitter. A Particle has a time to live after which it is
 * destroyed.
 */
class Particle {
private:
  float x;
  float y;
  float angle;
  float angularVelocity;
  float vx;
  float vy;
  int ttl;

  /*
   * This method sets up a random initial velocity and angular velocity
   */
  void init();

public:
  Particle(int ttl);
  void setCoordinates(float newX, float newY);
  void setVelocity(float newVx, float newVy);
  void incrementCoordinates(float deltaX, float deltaY);
  void incrementVelocity(float deltaVx, float deltaVy);
  int getTTL() const { return ttl; }
  float getX() const { return x; }
  float getY() const { return y; }
  void decreaseTTL() { --ttl; }
  void updatePosition(long currentTime);
};
#endif
