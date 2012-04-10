//
//  ofxGraphViewer.h
//
//
//  like Max/MSP multislider object
//

#ifndef _OFX_GraphViewer_h
#define _OFX_GraphViewer_h

#include "ofMain.h"

class ofxGraphViewer
{
public:
    ofxGraphViewer();
    ~ofxGraphViewer();
    
    void setup(int _bufferLength = 256);
    
    void allocate(int num);
    void pushData(float _d);
    
    void draw();
    void draw(float posx, float posy);
    void draw(float posx, float posy, float w, float h, float min, float max);
    
    void setSize(float _width, float _height);
    void setRange(float _min, float _max);
    
    float min, max, width, height;
    
private:
    int bufferLength;
    float* data;
    
    
};


#endif
