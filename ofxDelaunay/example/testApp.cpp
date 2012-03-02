#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	ofBackground(0, 0, 0);
	for(int i=0; i < 500; i++){
		triangulator.addPoint(ofRandom(100, 600), ofRandom(100, 600));
	}
	triangulator.triangulate();
	triangulator.outputTriangles();
}

//--------------------------------------------------------------
void testApp::exit(){
}

//--------------------------------------------------------------
void testApp::update(){
	triangulator.reset();
	for(int i=0; i < 500; i++){
		triangulator.addPoint(ofRandom(100, 600), ofRandom(100, 600));
	}
	triangulator.triangulate();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(0, 255, 0);
	ofDrawBitmapString(ofToString(ofGetFrameRate(), 1) + "fps", 10, 20);
	triangulator.drawTriangles();
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

