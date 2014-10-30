#include "ofApp.h"
float ObsSpeed;
float MainWidth, MainHeight;
//--------------------------------------------------------------
void ofApp::setup(){
ObsSpeed = 1;
MainWidth = 10;
MainHeight = 30;
ofSetFrameRate(2);
}

//--------------------------------------------------------------
void ofApp::update(){
	MainWidth = ofRandom(100, 700);
	MainHeight = ofRandom(100, 700);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255,0,0);
	ofRect(ofGetWidth()/2-MainWidth/2,ofGetHeight()/2-MainWidth/2, 0, MainWidth, MainWidth);
	ofSetColor(0,255,0);
	ofCircle(ofGetWidth()/2, ofGetHeight()/2, MainWidth/4);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
