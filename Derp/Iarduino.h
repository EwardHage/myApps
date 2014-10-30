#include<stdio.h>
#include"ofMain.h"
class Iarduino{
public:
	Iarduino(){};
	void setup(string port);
	void setupArd(const int &version);
	void update();
	void draw();
	void testLed();

	ofArduino myArduino;
};