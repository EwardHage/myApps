/* made by Eward Hage
	Student at the HKU Utrecht */
#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	//struct circle{
		//	int x;
		//	int y;
		//	int height;
		//	int width;
		//}

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
		
//		void passByValue(int x);
		//vector<circle>circles;     
//		int x;


		//Function for arduino
		void setupArduino();
		void updateArduino();
		// This variable will only be false when the ode first runs arduino
		bool bSetupArduino;

		//Variables for arduino
		ofSerial serial; // allows for serial output.
		ofArduino myArduino; // an arduino object.

		// Add images
		//ofImage derp;
};
