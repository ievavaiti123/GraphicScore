#include "ofApp.h"
//code by Ieva Vaiti that generates a graphic score based on given cell parameters

void ofApp::genLinePattern(int cellSize, int whichOne) {
	//function for the line patterns
	//cellSize stands for single beat size or single measure size, this creates a sense of continuity in timing.

	ofNoFill();
	ofSetColor(0);

	myLine.clear();
	if (whichOne == 0) {
		//myLine.clear();
		myLine.addVertex(0, cellSize / 2);
		myLine.addVertex(0, 0);
		myLine.addVertex(cellSize * 3, 0);
		myLine.addVertex(cellSize * 3, -cellSize / 2);
		

	} else if (whichOne == 1) {
		//myLine.clear();
		myLine.addVertex(0, 0);
		myLine.addVertex(cellSize*4, 0);
		
	}
	else if (whichOne == 2) {
		//myLine.clear();
		myLine.addVertex(0, 0);
		myLine.addVertex(cellSize, 0);
		myLine.addVertex(cellSize, cellSize);
		myLine.addVertex(cellSize * 2, cellSize);
		myLine.addVertex(cellSize * 2, cellSize * 2);
		myLine.addVertex(cellSize * 3, cellSize * 2);
	}
	else if (whichOne == 3) {
		//myLine.clear();
		myLine.addVertex(0, 0);
		myLine.addVertex(0, -cellSize);
		myLine.addVertex(cellSize, -cellSize);
		myLine.addVertex(cellSize, -cellSize - (cellSize / 2));
		myLine.addVertex(cellSize * 4, -cellSize - (cellSize / 2));
	}
	else if (whichOne == 4) {
		//myLine.clear();
		myLine.addVertex(0, 0);
		myLine.addVertex(0, cellSize / 2);
		myLine.addVertex(cellSize, cellSize / 2);
		myLine.addVertex(cellSize, cellSize + cellSize / 2);
		myLine.addVertex(0, cellSize + cellSize / 2);
		myLine.addVertex(0, cellSize * 2);
	}
	

	myLine.draw();
}

void ofApp::genCirPattern(int cellSize, int whichOne) {
	//patterns for the circles
	
	if (whichOne == 0) {
		//generate a red circle with a black border
		ofFill();
		ofSetColor(255, 0, 0);
		ofDrawCircle(0, 0, cSize);
		ofDrawCircle(cellSize, cellSize / 2, cSize);
		ofDrawCircle(cellSize * 2, 0, cSize);

		ofNoFill();
		ofSetColor(0);
		ofDrawCircle(0, 0, cSize);
		ofDrawCircle(cellSize, cellSize / 2, cSize);
		ofDrawCircle(cellSize * 2, 0, cSize);
	}

	else if (whichOne == 1) {
		ofFill();
		ofSetColor(255, 0, 0);
		ofDrawCircle(0, 0, cSize);

		ofNoFill();
		ofSetColor(0);
		ofDrawCircle(0, 0, cSize);
	}
	else if (whichOne == 2) {
		ofFill();
		ofSetColor(255, 0, 0);
		ofDrawCircle(0, 0, cSize);
		ofDrawCircle(cellSize, -cellSize/2, cSize);
		ofDrawCircle(cellSize*2, -cellSize, cSize);

		ofNoFill();
		ofSetColor(0);
		ofDrawCircle(0, 0, cSize);
		ofDrawCircle(cellSize, -cellSize / 2, cSize);
		ofDrawCircle(cellSize * 2, -cellSize, cSize);
	}
	else if (whichOne == 3) {
		ofFill();
		ofSetColor(255, 0, 0);
		ofDrawCircle(cellSize, 0, cSize);

		ofNoFill();
		ofSetColor(0);
		ofDrawCircle(cellSize, 0, cSize);
		
	}
	else if (whichOne == 4) {
		ofFill();
		ofSetColor(255, 0, 0);
		ofDrawCircle(cellSize * 4, 0, cSize);

		ofNoFill();
		ofSetColor(0);
		ofDrawCircle(cellSize * 4, 0, cSize);
	}
	else if (whichOne == 5) {
		ofFill();
		ofSetColor(255, 0, 0);
		ofDrawCircle(cellSize*3, 0, cSize);

		ofNoFill();
		ofSetColor(0);
		ofDrawCircle(cellSize * 3, 0, cSize);

	}

	
}

vector<int> ofApp::genRandArray(int from, int to, int size) {
	//function to generate array of random numbers

	for (int i = 0; i < size; i++) {
		//two arrays for two patterns.
		randArray1.push_back(ofRandom(from, to));
		randArray2.push_back(ofRandom(from, to));
	}
	return randArray1;
	return randArray2;
}

//--------------------------------------------------------------

void ofApp::setup(){
	ofBackground(220);
	ofSetCircleResolution(60);

	ofSetLineWidth(2);
	barSize = cellSize * 5;
	//one bar is 4 beats, so barSize is 4 beats * 5. can be changed to increase or decrease number of beats in a bar

	//generate an array of random numbers to use with the patterns
	//numbers range to 20 so there is 1:5 chance that a pattern is selected, increase or descrease to make the score more sparse or busy
	genRandArray(0, 20, 100);

	//uncomment for high res image
	/*fboScale = 5;
	fboWidth = 842 * fboScale;
	fboHeight = 595 * fboScale;
	scaleFactor = 842 / fboWidth;

	canvasFbo.allocate(fboWidth, fboHeight, GL_RGBA, 4);

	canvasFbo.begin();
	ofClear(255, 255, 255, 255);


	canvasFbo.end();*/
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	if (saving) {
		filename = "mySVG-" + to_string(saveCount) + ".svg";
		
		ofBeginSaveScreenAsSVG(filename);
		//for saving svgs
	}

	//uncomment for high res image
	/*canvasFbo.begin();
	ofPushMatrix();
	ofBackground(220);

	ofScale(fboScale);*/
	

	int width = ofGetWidth();
	int height = ofGetHeight();
	int count = 0;
	int count2 = 0;
	int staveGap = 15;
	float rectHeight = cellSize * 10;

	//centre the rectangle
	ofTranslate(25, height / 2 - (rectHeight/2));

	//white rectangle with a black border
	ofFill();
	ofSetColor(255);
	ofDrawRectangle(0, 0, width-50, rectHeight);
	ofNoFill();
	ofSetColor(0);
	ofDrawRectangle(0, 0, width - 50, rectHeight);


	ofPushMatrix();
	//centre the score
	ofTranslate(cellSize, cellSize * 3);
	
	for (int x = 0; x <= width - (barSize + 50 + cellSize); x += barSize) {
		//generate new bars until the edge of the page

		for (int y = 0; y <= staveGap * 3; y += staveGap) {
			//generate 3 stave lines for each bar.
			//change this to generate more or less stave lines

			ofPushMatrix();
			ofTranslate(x, y);
			//run the line and circle pattern functions here
			genLinePattern(cellSize, randArray1[count]);
			genCirPattern(cellSize, randArray2[count]);
			ofPopMatrix();
			count += 1;

		}
	}
	ofPopMatrix();

	//uncomment for high res image
	/*ofPopMatrix();
	canvasFbo.end();*/

	
	
	if (saving) {
		ofEndSaveScreenAsSVG();
		cout << "Saved svg" << endl;
		saveCount += 1;
		saving = false; // reset the saving variable
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'r') {
		//press R to refresh the array of random numbers and thus generate a new score
		randArray1.clear();
		randArray2.clear();
		genRandArray(0, 20, 100);
	}
	if (key == 's') {
		//save svg
		saving = true;
	}

	if (key == 'i') {
		//this will only work when the high res code is uncommented
		ofPixels pix;
		canvasFbo.readToPixels(pix);
		ofSaveImage(pix, "ParametricPoster_" + ofGetTimestampString() + ".png", OF_IMAGE_QUALITY_BEST);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
