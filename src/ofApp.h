#pragma once

#include "ofMain.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void genLinePattern(int cellSize, int whichOne);
		void genCirPattern(int cellSize, int whichOne);
		vector <int> genRandArray(int from, int to, int size);
		ofPolyline myLine;
		float cellSize = 15.0;
		float cSize = 3.0;
		int barSize;
		
		int seed = 50;
		vector <int> randArray1;
		vector <int> randArray2;

		string filename;
		int saveCount = 0;
		bool saving = false;

		ofFbo canvasFbo;
		float fboWidth;
		float fboHeight;
		float fboScale;
		float scaleFactor;
		
};
