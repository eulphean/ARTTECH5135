#include "ofApp.h"

// Center of the app.
float centerX, centerY;

// Shape dimensions.
int squareLength = 300;
int squarePixelOffset = 5;

//--------------------------------------------------------------
void ofApp::setup(){
  // Set background color.
  ofBackground(ofColor::black);
  ofSetLineWidth(1.5);
}

//--------------------------------------------------------------
void ofApp::update(){
  
  // Set the center variables.
  centerX = ofGetWidth()/2;
  centerY = ofGetHeight()/2;
}

void drawCenterSquare() {
  float squareOriginX = centerX - squareLength/2;
  float squareOriginY = centerY - squareLength/2;
  
  // Draw the center square.
  ofSetColor(ofColor::black);
  ofDrawRectangle(squareOriginX, squareOriginY, squareLength, squareLength);
  
  // Lines inside the square.
  for (int i = squareOriginY; i < (squareOriginY + squareLength); i = i + squarePixelOffset) {
    ofSetColor(ofColor::ghostWhite);
    ofDrawLine(squareOriginX + 1, i, squareOriginX + squareLength - 1, i);
  }
  
  // Stroke - Redraw the rectangle with stroke.
  ofSetColor(ofColor::white);
  ofNoFill();
  ofDrawRectangle(squareOriginX, squareOriginY, squareLength, squareLength);
}

//--------------------------------------------------------------
void ofApp::draw(){
  drawCenterSquare();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
