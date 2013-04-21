/*
 * A particle is a tiny dot in the space :) (2d space actually)
 * The (x,y) coordinates of a particle are relative to the position of the 
 * particle emitter.
 */

#ifndef PARTICLE_H
#define PARTICLE_H
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
	int getTTL();
	float getX() {return x;}
	float getY() {return y;}
	void decreaseTTL() {ttl--;}
	void updatePosition(long currentTime);
};
#endif
