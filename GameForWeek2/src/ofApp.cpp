#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
// Images.
	//derp.loadImage("derp.png");
//Player
PlayerY = ofGetHeight()/2;// default start location Player
PlayerRadius = 30; // How fat is the body of the player?
EyeRadius = 5; // Awh cute eyes..

//Enemy
EnemyRadius = 30;
EnemyX = ofGetWidth()+EnemyRadius;
EnemyY = ofRandom(0, ofGetHeight());
EnemySpeed = 5;

// Global
Speed = -15; // Default speed.
ofSetFrameRate(60); // FrameRate for playability it runs 2 smooth.
HasLostGame = false; // We have a chance to win here!!!
}

void ofApp::updateArduino(){

	// a call to update the arduino update data ins and out
	myArduino.update();
}
void ofApp::setupArduino(){
	//This will set up all of my arduino pins.
	myArduino.sendDigitalPinMode(9, ARD_OUTPUT);
}
//--------------------------------------------------------------
void ofApp::update(){
	
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



//score stuff
Time ++;
Seconds = Time/60;

//Player stuff
PlayerY += Speed;
Speed ++;
//Enemy Stuff
EnemyX -= EnemySpeed;
if(EnemyX < 0-EnemyRadius){
EnemyX = ofGetWidth()+EnemyRadius;
EnemyY = ofRandom(0, ofGetHeight());
}

//border stuff
if(PlayerY < 0){
	PlayerY = 0;
}
if(PlayerY > ofGetHeight()+PlayerRadius || ofDist(ofGetWidth()/2, PlayerY, EnemyX,EnemyY) <= EnemyRadius + PlayerRadius){
	HasLostGame = true;
}
//Syncing the vertical shit out of it.
ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::draw(){
	// turn the 9th pin on the arduino on. For this case you il turn on an led.
	myArduino.sendDigital(9, ARD_HIGH);

	ofBackground(0);
	//PlayerStuff.
	
	// Images for player.
	//derp.draw(ofGetWidth()/2, PlayerY, PlayerRadius);

	ofSetColor(255); // White for body.
	ofCircle(ofGetWidth()/2, PlayerY, PlayerRadius); // Shape of body.
	ofSetColor(0); // Black for eyes.
	ofCircle(ofGetWidth()/2-10, PlayerY-5, EyeRadius-2); // Draw left Eye
	ofCircle(ofGetWidth()/2+10, PlayerY-5, EyeRadius); // Draw right eye
	//EnemyStuff
	ofSetColor(255, 0, 0);
	ofCircle(EnemyX, EnemyY, EnemyRadius);
	//Score with the second counter.
	ofSetColor(255); // White for Time
	ofDrawBitmapString(ofToString(Seconds) +" Seconds" , 10, 10); // String with the number of seconds
	//When lost draw white screen with a message.
	if(HasLostGame == true){
		// Turn the led off.
		myArduino.sendDigital(9, ARD_LOW);

		ofBackground(255); // set background to White
		ofSetColor(0); // Black for Reset text
		ofDrawBitmapString("Press R to Restart", ofGetWidth()/2-50, ofGetHeight()/2); // Reset text
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	//When game lost press 114 "R" to restart the game
	if(HasLostGame == true){
		if(key == 114){ // Like I said 114 is R
		HasLostGame = false; // Reset Lost state.
		PlayerY = ofGetHeight()/2; // reset start location
		Speed = -15; // Reset speed.
		Time = 0; // reset score based on the time.
		EnemyX = ofGetWidth()+EnemyRadius;
		EnemyY = ofRandom(0, ofGetHeight());
		}
	}
		// When Arrow key up is pressed change the speed to the negative side.
		if(key == 357){ // 357 Arrow Key up.
		Speed = -15; // Set Speed back.
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
