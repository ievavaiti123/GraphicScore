#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	//Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	ofGLWindowSettings settings;
	settings.setSize(1200, 400);
	settings.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN
	auto window = ofCreateWindow(settings);
	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();

	// for exporting high resolution image
	//ofSetupOpenGL(842, 595, OF_WINDOW);			// <-------- setup the GL context

	//// this kicks off the running of my app
	//// can be OF_WINDOW or OF_FULLSCREEN
	//// pass in width and height too:
	//ofRunApp(new ofApp());
}
