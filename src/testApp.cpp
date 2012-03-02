#include "testApp.h"
#include "ofxDelaunay.h"


//--------------------------------------------------------------
void testApp::setup(){
	
	NUM_PARTICLES = 70;

	// create particles
	for(int i =0; i < NUM_PARTICLES; i++) {
		particles.push_back(Particle());
	}
	
	// setup caustics with 70 points
	caustics.setup(ofGetWidth(), ofGetHeight(), NUM_PARTICLES);
	
	// setup opengl stuff
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);
	ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
	
	// reset caustics and a re-add all the points
	caustics.reset();
	for(int i = 0; i < particles.size(); i++) {
		particles[i].update();
		caustics.addPoint(particles[i]);
	}

	// this triggers the delaunay
	caustics.update();
	ofSetWindowTitle(ofToString(ofGetFrameRate(), 0));
}

//--------------------------------------------------------------
void testApp::draw(){
	caustics.renderToFbo();
	caustics.getFbo().draw(0, 0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}