//
//  ofxGraphViewer.cpp
//
//  Created by motoi ishibashi on 12/04/05.
//

#include <iostream>

#include "ofxGraphViewer.h"

ofxGraphViewer::ofxGraphViewer()
{
    data = NULL;
    bufferLength = 0;
    min = -1.0;
    max = 1.0;
    width = 200.0;
    height = 50.0;
}

ofxGraphViewer::~ofxGraphViewer()
{
    if(data != NULL){
        delete data;
    }
}

void ofxGraphViewer::setup(int _bufferLength)
{
    bufferLength = _bufferLength;
    
    this->allocate(bufferLength);
    
}

void ofxGraphViewer::allocate(int num)
{
    if(data != NULL){
        delete data;
    }
    
    bufferLength = num;
    
    data = new float[bufferLength];
    memset(data, 0, sizeof(float)*bufferLength);
    
}

void ofxGraphViewer::pushData(float _d)
{
    for (int i=bufferLength-1; i> 0; i--) {
        data[i] = data[i-1];
    }
    
    data[0] = _d;
}

void ofxGraphViewer::draw()
{
    draw(0.0, 0.0);
}

void ofxGraphViewer::draw(float posx, float posy)
{
    draw(posx, posy, width, height, min, max);
}


void ofxGraphViewer::draw(float posx, float posy, float w, float h, float min, float max)
{
    if(data == NULL) return;
    
    ofPushStyle();
	ofNoFill();
	ofSetColor(ofColor::white);
	ofRect(posx, posy, w, h);
	ofSetColor(120, 120, 120);
	ofLine(posx, posy+h/2.0, posx+w, posy+h/2.0);
    
	ofSetColor(ofColor::green);
	glBegin(GL_LINE_STRIP);
	for(int i=0; i<bufferLength; i++){
		glVertex3d(posx+(w/(float)bufferLength)*i, posy + h - ofMap(data[i], min, max, 0.0, h), 0.0);
	}
	glEnd();
    
    ofPopStyle();
}

void ofxGraphViewer::setSize(float _width, float _height)
{
    width = _width;
    height = _height;
}

void ofxGraphViewer::setRange(float _min, float _max)
{
    min = _min;
    max = _max;
}
