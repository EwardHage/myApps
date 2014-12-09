#include "ofApp.h"
float Jump , PlayerX, PlayerY, PlayerRadius, EyeRadius; // Player Variable's.
float ObsX, ObsY, ObsWidth, ObsHeight, UpperBorder, LowerBorder;
float ObsX2, ObsY2, ObsWidth2, ObsHeight2, UpperBorder2, LowerBorder2;
float Live, LedTimer;
float Speed;
bool HasLostGame; // Awh You lost the fucking game.

//--------------------------------------------------------------
void ofApp::setup(){
	//derp.loadImage("derp.png");

	//for(int x=0; x < 11; x++){
	//	
	//	circle c;
	//	c.x = ofRandom(ofGetWidth());
	//	c.y = ofRandom(ofGetHeight());
	//	c.width = ofMap(c.x,0,1024,0,100);
	//	c.height = c.width;
	//	circles.push_back(c);
	//}
/*
	x = 10;
	int &rx = x;
	passByValue(x);
	cout<<x<<"is he value of x after running the function passbyvalue"<<endl;
*/
	//connect arduino
	myArduino.connect("COM3", 57600);
	//test if arduino is set up
	bSetupArduino =	false;

	//Default variables of the Player.
	Jump = -15; // Jump default.
	PlayerX = ofGetWidth()/4;
	PlayerY = ofGetHeight()/2; // SpawnLocation Player.
	PlayerRadius = 30; // Body Fatness.
	EyeRadius = 5; // Small black eye's for the Derp.
	
	//Obstacle1 Variables
	ObsX = ofGetWidth() + ObsWidth; // Spawn outside of screen.
	ObsY = 200;
	ObsWidth = 60;
	ObsHeight = ofGetHeight();

	//Obstacle2 Variables
	ObsX2 = ofGetWidth()*1.5 + ObsWidth; // Spawn outside of screen.
	ObsY2 = 200;
	ObsWidth2 = 60;
	ObsHeight2 = ofGetHeight();


	//Global variables.
	ofSetFrameRate(60); // Speaks for itself.
	Speed = 10;
	
	//Status Check.
	HasLostGame = false; // Player hasn't lost the freaking game.
	Live = 3;

	// Other Stuff
	ofSetVerticalSync(true); 




}

//void ofApp::passByValue(int x){
//	x =x+10;
//	cout<<x;
//}
//--------------------------------------------------------------Arduino shizzle.
void ofApp::updateArduino(){

	// a call to update the arduino update data ins and out
	myArduino.update();
}
//--------------------------------------------------------------
void ofApp::setupArduino(){
	//This will set up all of my arduino pins.
	myArduino.sendDigitalPinMode(8, ARD_OUTPUT);
	myArduino.sendDigitalPinMode(9, ARD_OUTPUT);
	myArduino.sendDigitalPinMode(10, ARD_OUTPUT);

	// default all the pins generate power to simulate 3 lives
	myArduino.sendDigital(8, ARD_HIGH);
	myArduino.sendDigital(9, ARD_HIGH);
	myArduino.sendDigital(10, ARD_HIGH);
}
//--------------------------------------------------------------
void ofApp::update(){
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

	//Player Mechanics.
	PlayerY += Jump; // PlayerY must have the jump variable to jump.
	Jump++; // Jump always goes down expotential.
	
	//Obstacle1.
	UpperBorder = ObsY-PlayerRadius*4;
	LowerBorder = ObsY+PlayerRadius*4;
	ObsX -= Speed;
	if(ObsX < -ObsWidth){
		ObsX = ofGetWidth() + ObsWidth;
		ObsY = ofRandom(200, ofGetHeight()-200);
	}
	//Obstacle2.
	UpperBorder2 = ObsY2-PlayerRadius*4;
	LowerBorder2 = ObsY2+PlayerRadius*4;
	ObsX2 -= Speed;
	if(ObsX2 < -ObsWidth2){
		ObsX2 = ofGetWidth() + ObsWidth;
		ObsY2 = ofRandom(200, ofGetHeight()-200);
	}
	
	//Check if lost.
	if(PlayerY >= ofGetHeight()){ // Borders of the game other wise it wasn't a game.
		HasLostGame = true; // Has lost is true so the plyer is your bitch now.
	} 

	//Check if Player Runned into the Obstacle.
	if(PlayerX+PlayerRadius >= ObsX && PlayerX-PlayerRadius <= ObsX+ObsWidth){
		if(PlayerY+PlayerRadius >= LowerBorder || PlayerY-PlayerRadius <= UpperBorder){
		HasLostGame = true;
		}
	}
	if(PlayerX+PlayerRadius >= ObsX2 && PlayerX-PlayerRadius <= ObsX2+ObsWidth2){
		if(PlayerY+PlayerRadius >= LowerBorder2 || PlayerY-PlayerRadius <= UpperBorder2){
		HasLostGame = true;
		}
	}


	// Life's with Arduino
	if(HasLostGame == true){
		
		Live = Live - 1;// Now works with live's
		
		PlayerY = ofGetHeight()/2; // Set the player back to it's spawn.
		Jump = -20; // And set jump back to default other wise he will be in a loop.

		//Obstacle1 Variables
		ObsX = ofGetWidth() + ObsWidth; // Spawn outside of screen.

		//Obstacle2 Variables
		ObsX2 = ofGetWidth()*1.5 + ObsWidth; // Spawn outside of screen.
		
// LedDisplay. That should it do when there is something happening.
		if(Live == 2){ // when a live is lost set one led to LOW aka off.
		HasLostGame = false;
		myArduino.sendDigital(8, ARD_LOW);
		myArduino.sendDigital(9, ARD_HIGH);
		myArduino.sendDigital(10, ARD_HIGH);
		}
		if(Live == 1){ // Same here but now 2 leds are off.
		HasLostGame = false;
		myArduino.sendDigital(8, ARD_LOW);
		myArduino.sendDigital(9, ARD_LOW);
		myArduino.sendDigital(10, ARD_HIGH);
		}
		if(Live < 1){ // Ok you lost now display all the leds to give a little light show.
		HasLostGame = true;
		Live = 0;
		LedTimer += 1;
		if(LedTimer < 30){
			myArduino.sendDigital(8, ARD_HIGH);
			myArduino.sendDigital(9, ARD_LOW);
			myArduino.sendDigital(10, ARD_LOW);
			}
			if(LedTimer >= 30 && LedTimer < 60){
			myArduino.sendDigital(8, ARD_LOW);
			myArduino.sendDigital(9, ARD_HIGH);
			myArduino.sendDigital(10, ARD_LOW);
			}
			if(LedTimer >= 60 && LedTimer <= 90){
			myArduino.sendDigital(8, ARD_LOW);
			myArduino.sendDigital(9, ARD_LOW);
			myArduino.sendDigital(10, ARD_HIGH);
			}
			if(LedTimer > 90){
			LedTimer = 0;
			}
		}

//cout << Live << endl;
	}	

}

//--------------------------------------------------------------
void ofApp::draw(){

//	for(int i =0; i<circles.size(); i ++)){
//		ofSetColor(circles[i].width, 255, 255);
//		ofFill();
//		ofEllipse(circles[i].x, circles[].y, circles[i].width, circles[i].height);
//	}

	if(HasLostGame == false){
	ofBackground(0); // Background color = black.
	ofSetColor(255);
	ofDrawBitmapString(ofToString(Live) +" Live" , 10, 10);
	
	//Player shit.
	ofSetColor(255); // Set color white for the player.
	ofCircle(PlayerX, PlayerY, PlayerRadius); // Body of the player.
	ofSetColor(0);// Set color of eyes to black.
	ofCircle(PlayerX-5, PlayerY-5, EyeRadius-2); // Left Eye.
	ofCircle(PlayerX+5, PlayerY-5, EyeRadius); // Right Eye.
	//derp.draw(PlayerX, PlayerY, PlayerRadius);
	
	//Obstacle1 Shizzle.
	ofSetColor(255, 0, 0);
	ofRect(ObsX, UpperBorder, 0, ObsWidth, -ObsHeight); //Upper
	ofRect(ObsX, LowerBorder, 0, ObsWidth, ObsHeight); // Lower
	
	//Obstacle2 Shizzle.
	ofSetColor(255, 0, 0);
	ofRect(ObsX2, UpperBorder2, 0, ObsWidth2, -ObsHeight2); //Upper
	ofRect(ObsX2, LowerBorder2, 0, ObsWidth2, ObsHeight2); // Lower
	}
	//When game is lost.
	if(HasLostGame == true){ // When Has lost is true then.
		ofSetColor(255); // Make coffe for me so I can have a caffeine rush.
		ofRect(0,0,0,ofGetWidth(),ofGetHeight()); // Because I am getting lazy with this train programming ;).
		ofSetColor(0); // But realy set the color of the text to black.
		ofDrawBitmapString("Press Again to start",ofGetWidth()/2-50,ofGetHeight()/2); // Otherwise we cant read it.
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//cout << "Feed me with keys!!!" << endl;
	//cout << key << endl;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	//cout << key;
	if(key == 32){ // When spacing is pressed.
	Jump = -15; // Jump 15 high on the screen.
	}

	//When game is lost then Space becomes a reset button.
	if(Live == 0){ // When the player is your bitch.
		if(key == 32){ // When pressed STONERSPACE.
			HasLostGame = false; // The player isn't your bitch anymore.
			PlayerY = ofGetHeight()/2; // Set the player back to it's spawn.
			Jump = -20; // And set jump back to default other wise he will be in a loop.

			//Obstacle1 Variables
			ObsX = ofGetWidth() + ObsWidth; // Spawn outside of screen.

			//Obstacle2 Variables
			ObsX2 = ofGetWidth()*1.5 + ObsWidth; // Spawn outside of screen.

			Live = 3;

			// default all the pins generate power to simulate 3 lives
			myArduino.sendDigital(8, ARD_HIGH);
			myArduino.sendDigital(9, ARD_HIGH);
			myArduino.sendDigital(10, ARD_HIGH);

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
