#include "ofApp.h"
ofImage HSB;
const int HSBsize = 255, HSBX = 767;

bool leftPressed;
//--------------------------------------------------------------
void ofApp::setup(){
	//connect arduino
//	myArduino.connect("COM3", 57600);
	//test if arduino is set up

//	bSetupArduino =	false;
	HSB.loadImage("hsb.png");
	//ofSetFrameRate(6);
	mouseX = mouseX-32;

	red = 0;
	green = 0;
	blue = 0;
}
/*
//--------------------------------------------------------------Arduino shizzle.
void ofApp::updateArduino(){

	// a call to update the arduino update data ins and out
	myArduino.update();
}
//--------------------------------------------------------------
void ofApp::setupArduino(){
	//This will set up all of my arduino pins.
	myArduino.sendDigitalPinMode(3, ARD_PWM);
	myArduino.sendDigitalPinMode(5, ARD_PWM);
	myArduino.sendDigitalPinMode(6, ARD_PWM);

}
*/
//--------------------------------------------------------------
void ofApp::update(){
/*	
	// Arduino.
	if(myArduino.isArduinoReady()){
		if(bSetupArduino == false){
			//1s setup the arduino if haven't already.
			cout << "arduino running" << endl;
			
			setupArduino(); //This function assigns the pins
			// we have started running arduino so no need need to call setup again.
			bSetupArduino = true; // only do this once
		}

		//2nd do the update of the arduino.
		updateArduino();
	}
*/
if(leftPressed == true){
	//Go get the HSB values
if(mouseY >= ofGetHeight()/3 && mouseY <= ofGetHeight()/3+255){	
	//Red
	if(mouseX <= 127){
	//cout << "red" << endl;
	red = 255;
	green = mouseX*2;
	blue = 0;
	}

	//Green
	if(mouseX >=128 && mouseX <= 383){
	//cout << "green" << endl;
	red = 512 - mouseX*2;
	green = 255;
	blue = -512 + mouseX*2;
	}

	// BLUE
	if(mouseX >= 384 && mouseX <= 639){
	//cout << "blue" << endl;
	red = -1024 + mouseX*2;
	green = 1023 - mouseX*2;
	blue = 255;
	}

	//RED
	if(mouseX >= 640){
	//cout << "red" << endl;
	red = 255;
	green = 0;
	blue = 1526 - mouseX*2;
	}
}
if(mouseY >= ofGetHeight()/3+255){
	if(mouseX <= ofGetWidth()/2){
	red = 255;
	green = 255;
	blue = 255;
	}
	else{
	red = 0;
	green = 0;
	blue = 0;
	}
}

	if(mouseY >= 140 && mouseY <= 160){
		if(mouseX >= 118 && mouseX <= 138){
		red = 255;
		green = 0;
		blue = 0;
		}
		if(mouseX >= ofGetWidth()/2-10 &&mouseX <= ofGetWidth()/2+10){
		red = 0;
		green = 255;
		blue = 0;
		}
		if(mouseX >= ofGetWidth()-138 &&mouseX <= ofGetWidth()-118){
		red = 0;
		green = 0;
		blue = 255;
		}
	}


	OUTPUTRED = red;
	OUTPUTGREEN = green;
	OUTPUTBLUE = blue;

	if(red <= 0){
		OUTPUTRED = 0;
	} else{
		OUTPUTRED = red;
	}
	if(green <= 0){
		OUTPUTGREEN = 0;
	} else{
		OUTPUTGREEN = green;
	}
	if(blue <= 0){
		OUTPUTBLUE = 0;
	} else{
		OUTPUTBLUE = blue;
	}
	
	// Printing the shit out of this script.
	cout << "R " << OUTPUTRED << endl;
	cout << "G " << OUTPUTGREEN << endl;
	cout << "B " << OUTPUTBLUE << endl;
	cout << " " << endl;
}
/*	
	myArduino.sendPwm(3, OUTPUTRED);
	myArduino.sendPwm(5, OUTPUTGREEN);
	myArduino.sendPwm(6, OUTPUTBLUE);
*/	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	//HSB shit
	ofSetColor(255,255,255);
	HSB.draw(0,ofGetHeight()/3,HSBX, HSBsize);
	
	//Show me which color I mouse over.
	ofSetColor(red, green, blue);
	ofSetCircleResolution(45);
	ofCircle(ofGetWidth()/2,0,100);
	
	// Set color to white
	ofSetColor(255);
	ofRect(0, ofGetHeight()/3+255, ofGetWidth()/2, ofGetHeight()/3);
	
	// Set color to red
	ofSetColor(255, 0, 0);
	ofCircle(128, 150, 20);
	
	// set color to green.
	ofSetColor(0, 255, 0);
	ofCircle(ofGetWidth()/2, 150, 20);
	
	// set color to blue.
	ofSetColor(0, 0, 255);
	ofCircle(ofGetWidth()-128, 150, 20);

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	//cout << x << endl;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if(button == 0){
	leftPressed = true;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if(button == 0){
	leftPressed = false;
	}
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
