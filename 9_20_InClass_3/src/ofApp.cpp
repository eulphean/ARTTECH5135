//  Author: Amay Kataria
//  Date: 09/20/2017
//  Description: Generative recursive art.

#include "ofApp.h"

int theta = 30;
int lineLength = 100;
int maxDepth = 4;
int circleRadius = 20;

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetBackgroundColor(ofColor::black);
  ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){
  
}

void ofApp::drawCircleAndLines(int curDepth) {
  // Base condition for recursion.
  if (curDepth > maxDepth) {
    return;
  }
  
  // Increment the current depth for the subsequent recursive call.
  curDepth = curDepth + 1;
  
  // Draw circle at the translated center coordinated.
  ofFill();
  ofSetColor(ofColor::orange);
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

// Draws the core structure at (x, y)
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
  // Pass curDepth = 0 to let ofDraw loop draw this structure infinitely.
  drawStructure(ofGetWidth() / 2, ofGetHeight() / 2, 0);
}
