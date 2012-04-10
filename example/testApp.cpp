#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(60.0);
    ofEnableSmoothing();
    ofBackground(0, 0, 0);
    
    gViewer1.setup(512);
    gViewer1.setRange(-1.0, 1.0);
    gViewer1.setSize(512, 200);
    
    gViewer2.setup(512);
    gViewer2.setRange(0, 1000);
    gViewer2.setSize(512, 200);

}

//--------------------------------------------------------------
void testApp::update(){

    float d1 = ofRandom(-1.0, 1.0);
    gViewer1.pushData(d1);
    
    float d2 = (float)(ofGetFrameNum()%1000);
    gViewer2.pushData(d2);
}

//--------------------------------------------------------------
void testApp::draw(){

    gViewer1.draw(10, 10);

    gViewer2.draw(10, 220);
    
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("graph 1 <random number>", 530, 20);
    ofDrawBitmapString("graph 2 <frame number % 1000>", 530, 230);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}