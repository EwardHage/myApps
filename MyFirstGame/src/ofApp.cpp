#include "ofApp.h"
// Variables //-------------------------------------------------
float PlayerRadius;
float PlayerY;
float EnemyRadius;
float EnemyX;
float EnemyY;
int score;
int speed;
bool hasLostGame;
int EnemySpeed;

//--------------------------------------------------------------
void ofApp::setup(){
	PlayerRadius = 60;
	PlayerY = ofGetHeight()-100;
	EnemyRadius = 20;
	EnemyY = 0-EnemyRadius;
	EnemyX = ofRandom(ofGetWidth());
	// Show the enemy off screen when it spawns.
	hasLostGame = false;
	EnemySpeed = 1;
	score = 0;
	ofSetVerticalSync(true); // ALWAYS do with visuals it syncs the vertical so it doesnt look glitchy.
	// hey yo this is a comment yo.
	/* hololo
		 hololo
			 hololo
				 hololo
				 */
}

//--------------------------------------------------------------
void ofApp::update(){
	if(hasLostGame == false){
			if(EnemyY > ofGetHeight()+ EnemyRadius){
				score++;								// Yay you got a point.
				EnemySpeed = EnemySpeed+0.05;				// Make it Faster
				EnemyRadius = EnemyRadius+2;			// Better stronger ;)

				EnemyY = 0- EnemyRadius;				// Respawn EnemyY to Top
				EnemyX = ofRandom(ofGetWidth());		// Respawn on Random X location
			}
		EnemyY += EnemySpeed;
		//cout << EnemyY;
		if(ofDist(mouseX, mouseY, EnemyX, EnemyY) <= EnemyRadius + PlayerRadius){
			hasLostGame = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0,0,0); // Set Background to black
	ofSetColor(0, 0, 255); // Set color of player to blue
	//ofRect(mouseX,PlayerY,0,100, 100);
	ofCircle(mouseX, mouseY, PlayerRadius); // This creates the player
	ofSetColor(255, 0, 0); // Set color of Enemy to red.
	ofCircle(EnemyX, EnemyY, EnemyRadius); // This creates the Enemy.
	ofSetColor(255); // color is white.
	ofDrawBitmapString("Score: "+ ofToString(score) , 120, 20); // Draw the score and show it on the topleft location.
	if(hasLostGame == true){
		ofDrawBitmapString("Press R to Restart", ofGetWidth()/2, ofGetHeight()/2); // If lost show restart with R in the middle.
	}

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
cout << key;
if(hasLostGame == true){ // Oh no he/she lost.
		if(key == 114){ // if R is pressed then restart.
			hasLostGame = false; // reset the Game.
			EnemyRadius = 20; // reset the EnemyRadius.
			EnemyY = 0-EnemyRadius;	// reset start position Y of enemy.
			EnemyX = ofRandom(ofGetWidth()); // set position x to a random location.
			// Show the enemy off screen when it spawns.
			EnemySpeed = 1; // reset enemy speed to default 1
			score = 0; // Nooooooo your score has gone.....
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
