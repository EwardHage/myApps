#include "Derp.h"
Derp:: Derp(){
location = ofVec2f(30, 30);
	velocity = ofVec2f(0, 0);
	accel = ofVec2f(0, 0);
	mass = 1;

	ofSetColor(255, 0, 0);
	ofSetBackgroundColor(0,0,0);
	ofSetCircleResolution(200);
}
void Derp::update(){
	velocity += accel;
	location += velocity;
	accel += 0;
}
void Derp::display(){
	ofFill();
	ofEllipse(location.x, location.y, 40, 40);
}
void Derp::checkEdges(){
	//x axis check.
	if(location.x > ofGetWidth()){
		location.x = ofGetWidth();
		velocity *= -1;
	} else if(location.x < 0){
		location.x = 0;
		location.x *= -1;
	}
	// y axis check.
	if(location.y > ofGetHeight()){
		location.y = ofGetHeight();
		velocity *= -1;
	} else if(location.y < 0){
		location.y = 0;
		location.y *= -1;
	}
}
void Derp::applyforce(ofVec2f force){
	ofVec2f f = force/mass;
		accel += f;
}
