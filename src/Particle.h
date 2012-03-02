/**     ___           ___           ___                         ___           ___
 *     /__/\         /  /\         /  /\         _____         /  /\         /__/|
 *    |  |::\       /  /::\       /  /::|       /  /::\       /  /::\       |  |:|
 *    |  |:|:\     /  /:/\:\     /  /:/:|      /  /:/\:\     /  /:/\:\      |  |:|
 *  __|__|:|\:\   /  /:/~/::\   /  /:/|:|__   /  /:/~/::\   /  /:/  \:\   __|__|:|
 * /__/::::| \:\ /__/:/ /:/\:\ /__/:/ |:| /\ /__/:/ /:/\:| /__/:/ \__\:\ /__/::::\____
 * \  \:\~~\__\/ \  \:\/:/__\/ \__\/  |:|/:/ \  \:\/:/~/:/ \  \:\ /  /:/    ~\~~\::::/
 *  \  \:\        \  \::/          |  |:/:/   \  \::/ /:/   \  \:\  /:/      |~~|:|~~
 *   \  \:\        \  \:\          |  |::/     \  \:\/:/     \  \:\/:/       |  |:|
 *    \  \:\        \  \:\         |  |:/       \  \::/       \  \::/        |  |:|
 *     \__\/         \__\/         |__|/         \__\/         \__\/         |__|/
 *
 *  Description:
 *
 *  Particle.h, created by Marek Bereza on 02/03/2012.
 */


#include "ofMain.h"

class Particle : public ofVec2f {
public:
ofVec2f vel;
Particle() {
	x = ofRandomWidth();
	y = ofRandomHeight();
	vel.set(ofRandom(0.3, 2), 0);
	vel.rotate(ofRandom(0, 360));
}

void update() {
	*this += vel;

	if(x < 0) {
		x = 0;
		vel.x *= -1;
	}

	if(y < 0) {
		y = 0;
		vel.y *= -1;
	}

	if(x > ofGetWidth()) {
		x = ofGetWidth();
		vel.x *= -1;
	}

	if(y > ofGetHeight()) {
		y = ofGetHeight();
		vel.y *= -1;
	}
}

void draw() {
	ofCircle(*this, 3);
}
};

