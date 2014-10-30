#pragma once

#include "ofMain.h"
#include <iostream>
using namespace std;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		//Function for arduino
		void setupArduino();
		void updateArduino();
		// This variable will only be false when the ode first runs arduino
		bool bSetupArduino;


		float PlayerY, PlayerRadius, EyeRadius; // Variables for player
		float EnemyX, EnemyY, EnemyRadius, EnemySpeed;
		float Speed; // Variable for falling speed.
		float Time; // Get exact play time.
		int Seconds; // Get full seconds.
		bool HasLostGame; // Did you lose the game yes or no?

		//Variables for arduino
		ofSerial serial; // allows for serial output.
		ofArduino myArduino; // an arduino object.

		// Add images
		//ofImage derp;
		
};
