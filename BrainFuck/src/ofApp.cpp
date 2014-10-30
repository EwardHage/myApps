#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	for(int x=0; x < 11; x++){
		
		circle c;
		c.x = ofRandom(ofGetWidth());
		c.y = ofRandom(ofGetHeight());
		c.width = ofMap(c.x,0,1024,0,100);
		c.height = c.width;
		circles.push_back(c);
	}

	x = 10;
	//rx = x;
	passByValue(x);
	cout<<x<<"is he value of x after running the function passbyvalue"<<endl;
}
//--------------------------------------------------------------
void ofApp::passByValue(int x){
	x =x+10;
	cout<<x;
}
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	for(int i =0; i<circles.size(); i ++){
		ofSetColor(circles[i].width, 255, 255);
		ofFill();
		ofEllipse(circles[i].x, circles[i].y, circles[i].width, circles[i].height);
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
