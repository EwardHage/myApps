/*
Tutorial for Richelle how to use the ofSetColor function with images
*/

#include "ofApp.h"
ofImage Image; // YOU PUT THIS IN THE HEADER FILE (ofApp.h)
//--------------------------------------------------------------
void ofApp::setup(){
Image.loadImage("imageofcat.png");// Refer to the data file. ALWAYS IN SETUP.
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
ofBackground(255);
ofSetColor(255,255,255); // NOTE if there isnt another image or object with a color set by ofSetColor you dont need this.
Image.draw(0, ofGetHeight()/2, 0, 100,100);
ofSetColor(255,0,0); // NOTE now you have put another object with ofSetColor you need to say to the image HEY BITCH set color to origional for the image..... origional color is ofSetColor(255,255,255);
ofCircle(ofGetWidth()/2, ofGetHeight()-200, 100);
Image.draw(ofGetWidth()/2, ofGetHeight()/3, 100, 100);// Gets the color of the last set thing
//Now with this principle just like in Processing with the fill() function you can make different kinds of objects with another color
//NOTE if you dont put the ofSetColor() function on top of that object it gets the color of the last object with the fill. Just like the second image().

ofSetColor(0,0,255);
ofRect(ofGetWidth()-200, ofGetHeight()-200, 0, 100, 100);
Image.draw(ofGetWidth()-200, ofGetHeight()-400, 0, 100, 100);
//Now were gonna place another orig image.
ofSetColor(255,255,255);
Image.draw(0,0,100,100);

// Now comment some shizzle out to see what it does. ur welcome.
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
