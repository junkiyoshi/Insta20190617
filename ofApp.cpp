#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(3);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	for (int y = -300; y <= 300; y += 30) {

		ofPushMatrix();
		ofTranslate(0, y, 0);
		ofRotateY(ofGetFrameNum() * ofRandom(0.5, 3) * (ofRandom(1) < 0.5 ? 1 : -1));

		float width = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, 50, 400);
		float depth = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, 50, 400);

		ofFill();
		ofSetColor(239);
		ofDrawBox(glm::vec3(), width, 20, depth);

		ofNoFill();
		ofSetColor(39);
		ofDrawBox(glm::vec3(), width, 20, depth);

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}