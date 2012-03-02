
#include "Caustics.h"


Caustics::Caustics() {
	ping = NULL;
	currTime = 0;
	pong = NULL;
}

Caustics::~Caustics() {
	cleanUp();
}

void Caustics::cleanUp() {
	if(ping!=NULL) {
		delete ping;
		ping = NULL;
	}
	
	if(pong!=NULL) {
		delete pong;
		pong = NULL;
	}
}

void Caustics::setup(int width, int height, int maxNumPoints) {
	cleanUp();
	ping = new ofFbo();
	pong = new ofFbo();
	ping->allocate(ofGetWidth(), ofGetHeight(), GL_RGB16F);
	pong->allocate(ofGetWidth(), ofGetHeight(), GL_RGB16F);
	triangulator.init(maxNumPoints);
	clearedFbo = false;
}

void Caustics::reset() {
	triangulator.reset();
}
void Caustics::addPoint(const ofVec2f &p) {
	triangulator.addPoint(p.x, p.y);
}

void Caustics::update() {
	triangulator.triangulate();
}


void Caustics::drawWavyLine(ofVec2f a, ofVec2f b) {

	ofVec2f diff = (b-a);
	float length = diff.length();
	
	
	// now calculate the normal, normalized
	ofVec2f n = diff/length;
	
	// turn (x, y) into (y, -x) - this flips the vector 90 degrees
	float ny = n.y;
	n.y = -n.x;
	n.x = ny;
	

	glBegin(GL_LINE_STRIP);


	for(float f = 0; f < PI*2; f+=PI/5.f) {
		float d = f/TWO_PI;
		
		float window = 1-4*(d-0.5)*(d-0.5);
		ofVec2f sine = n * sin(f+currTime)*ofMap(length, 0, 200, 0, 8)*window;
		ofVec2f p = sine + a + diff * d;
	
		glVertex2f(p.x, p.y);
	}
	glVertex2f(b.x, b.y);
	
	glEnd();
}


void Caustics::renderToFbo() {
	

	if(!clearedFbo) {
		pong->begin();
		ofClear(0, 0, 0, 0);
		pong->end();
		clearedFbo = true;
	}
	ping->begin();
	{
		ofEnableBlendMode(OF_BLENDMODE_ALPHA);
		ofClear(0, 0, 0, 0);
		glColor4f(1, 1, 1, 0.98);
		
		glPushMatrix();
		glTranslatef(ofGetWidth()/2, ofGetHeight()/2, 0);
		float s = 1 + 0.002;
		
		glScalef(s, s, 1);
		pong->setAnchorPercent(0.5, 0.5);
		
		pong->draw(0, 0.5);
		glPopMatrix();
		glColor4f(1, 1, 1, 0.05);
		
		int numTris = triangulator.getNumTriangles();
		ITRIANGLE *tris = triangulator.getTriangles();
		XYZ *points = triangulator.getPoints();
		
		currTime = ofGetElapsedTimef();
		ofEnableBlendMode(OF_BLENDMODE_ADD);
		for(int i = 0; i < numTris; i++) {
			ofVec2f a = ofVec2f(points[tris[i].p1].x, points[tris[i].p1].y);
			ofVec2f b = ofVec2f(points[tris[i].p2].x, points[tris[i].p2].y);
			ofVec2f c = ofVec2f(points[tris[i].p3].x, points[tris[i].p3].y);
			
			drawWavyLine(a, b);
			drawWavyLine(b, c);
			drawWavyLine(c, a);
			
		}
		ofEnableBlendMode(OF_BLENDMODE_ALPHA);
		
	}
	ping->end();
	pong->setAnchorPercent(0, 0);
	ofSetHexColor(0xFFFFFF);
	
	
	// do the ping-pong
	ofFbo *temp = ping;
	ping = pong;
	pong = temp;
}


ofFbo &Caustics::getFbo() {
	return *pong;
}
