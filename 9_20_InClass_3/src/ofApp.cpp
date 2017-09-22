//  Author: Amay Kataria
//  Date: 09/20/2017
//  Description: Generative recursive art.

#include "ofApp.h"

int theta = 30;
int lineLength = 100;
int maxDepth = 2;
int circleRadius = 10;

// ofNoise => Periodic signals example.
// Look at the examples from this week for starting thus.

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetBackgroundColor(ofColor::black);
  ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){
  
}

void ofApp::drawCircleAndLines(int curDepth) {
  if (curDepth > maxDepth) {
    return;
  }
  
  curDepth = curDepth + 1;
  
  // Draw circle in the center.
  ofNoFill();
  ofSetColor(ofColor::green);
  ofDrawCircle(0, 0, circleRadius);
  
  // Draw inner lines.
  for (int i = 0; i < 360; i = i + theta) {
    ofPushMatrix();
      ofRotateZ(i);
      ofSetColor(ofColor::aqua);
      ofDrawLine(0, 0, lineLength, lineLength);
      drawStructure(lineLength, lineLength, curDepth);
    ofPopMatrix();
  }
}

void ofApp::drawStructure(float x, float y, int curDepth) {
  if (curDepth < maxDepth) {
    ofPushMatrix();
      ofTranslate(x, y);
      drawCircleAndLines(curDepth);
    ofPopMatrix();
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  drawStructure(ofGetWidth() / 2, ofGetHeight() / 2, 0);
}
