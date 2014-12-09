#include "ofApp.h"
float PlayerY, Jump; // Main gameplay mechanics.
float LastLoc;
float PlayerRadius, PlayerX;
bool HasLostGame;
//--------------------------------------------------------------
void ofApp::setup(){
	Jump -= 15;
	PlayerY = ofGetHeight()/2;
	ofSetFrameRate(60);
	PlayerX = ofGetWidth()/2;
	PlayerRadius = 30;
}

//--------------------------------------------------------------
void ofApp::update(){
	PlayerY += Jump;
	Jump ++;
			
	LastLoc = PlayerY;
	// Border.
		if(PlayerY <= 0 || PlayerY >= ofGetHeight()){
			HasLostGame = true;
		} else{
			HasLostGame = false;
		}
	//cout << HasLostGame << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofCircle(PlayerX, PlayerY, PlayerRadius);
	
	if(HasLostGame == true){
		ofSetColor(255);
		ofRect(0, 0, 0, ofGetWidth(),ofGetHeight());
		ofSetColor(0);
		ofDrawBitmapString("Srry Mate U Fucked Up",ofGetWidth()/2, ofGetHeight()/2);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//cout << key << endl;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(HasLostGame == false){
		if(key == 32){
			Jump = -15;
		}
	} else{
		if(key == 32){
			HasLostGame = false;
			Jump = -15;
			PlayerY = ofGetHeight()/2;
		}
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
