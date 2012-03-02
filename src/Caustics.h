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
 *  Caustics.h, created by Marek Bereza on 02/03/2012.
 */

#pragma

#include "ofMain.h"
#include "ofxDelaunay.h"

class Caustics {
public:
void setup(int width, int height, int maxNumPoints);



// every frame, call reset(), add your points, then update()

void reset();
void addPoint(const ofVec2f &p);
// generates delaunay
void update();

void renderToFbo();


// this won't be the same fbo
// every time, it's a pingpong.
ofFbo &getFbo();


Caustics();
~Caustics();


private:
// memory management
void cleanUp();

ofxDelaunay triangulator;

// the two fbo's that we flip between, every frame
ofFbo *ping;
ofFbo *pong;


void drawWavyLine(ofVec2f a, ofVec2f b);

float currTime;

// check if the FBO has been cleared for initialization
bool clearedFbo;
};

