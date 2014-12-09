#include "ofApp.h"
#include <ioStream>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	//m = new Mover(); 
	numMovers = 100;

	gravity = ofVec2f(0, 0.01);
	wind = ofVec2f(0.01, 0);

	for(int i =0; i <numMovers; i ++){
		Mover*m = new Mover(ofRandom(0.1, 4), 0, 0);
		movers.push_back(*m);
	}
	ofBackgroundGradient(100,0, OF_GRADIENT_CIRCULAR);
}

//--------------------------------------------------------------
void ofApp::update(){
for(int i =0; i <numMovers; i ++){	
	movers[i].applyForce(wind);
	movers[i].applyForce(gravity);
}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for(int i =0; i <numMovers; i ++){	
	movers[i].update();
	movers[i].display();
	movers[i].checkEdges();
	}
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
