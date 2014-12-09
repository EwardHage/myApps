#include "ofMain.h"
#include "ofApp.h"
using namespace std;
void secondFunction(int &address);
void secondFunction (int x, int y);

// on the heap


//========================================================================
int main(){
	// on the stack!
	int x=0;
	secondFunction(x, 0);	
	cout << x << " is the value of x" << endl;
	
	int &rx=x;

	int* ptr = 0;
	cout << ptr << " ptr print" << endl;
	int y = 10;

	ptr = &x;

	cout << *ptr << endl;
	ptr = &y;
	rx = y;
	y = 20;
	cout << x << " after got assigned to y" << endl;
	cout << y << " is still y" << endl;
	cout << &rx << " Goes to the memory address" << endl;

	secondFunction(*ptr);
	cout << x << endl;

	ofSetupOpenGL(100,100,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
void secondFunction(int x, int y){
	x = 10;

}
void secondFunction(int &address){
	cout << address << endl;
	//int x = 0;
	address ++;
}