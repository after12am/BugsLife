#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	
	ofSetVerticalSync(true);
	ofBackgroundHex(0xfdefc2);
	ofSetFrameRate(30);
	ofSetLogLevel(OF_LOG_NOTICE);
		
	world.setup();
}

//--------------------------------------------------------------
void testApp::update() {
	
	world.update();
}


//--------------------------------------------------------------
void testApp::draw() {
	
	ofSetWindowTitle(ofToString(ofGetFrameRate(), 1));
	
	world.draw();
	
	ofSetColor(ofColor(0));
	ofDrawBitmapString(ofToString("press left key to jump to 10 generations later"), 10, ofGetHeight() - 10);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
	
	// right key
	if (key == 358) {
		
		// jump to some generations later
		for (int i = 0; i < world.turn * 15 * (10 + 1); i++) {
			world.update();
		}
	}
	
	if(key == 'f') {
		
        ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::resized(int w, int h){
}

