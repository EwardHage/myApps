#include "ofApp.h"
float Speed;
float Shape1Size, Shape2Size, Shape3Size;
float SetAnim;
bool Change;
//NOTHING HAPENING HERE YET SRRY.

//--------------------------------------------------------------
void ofApp::setup(){
	Speed = 1;
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update(){
	cout << SetAnim << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//cout << key << endl;
	if(key == 32){
		SetAnim += 1;
		Change = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(key == 32){
		SetAnim += 0;
		Change = true;
	}
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
