#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
         void Matrix();

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
		
};

class Line {
public:
    //line();
    void update();
    // void draw();
    ofPoint loc;
    void draw();    // draw method, this where you'll do the object's drawing
    void setup();
    // variables
//    float x;        // position
//    float y;
//    float z;
//    int dim;        // size
    
   // ofColor color;  // color using ofColor type
    //   ofFbo fbo;
    Line();  // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
    
private:
    float sTime;	// start time
    float sWeight;      // scale weight
    float fallSpeed;	// how fast to fall
    float fallWiggle;   // back and forth
    
    //ofImage leafImg;
    float scale;
    float dScaleX;	// delta scales
    float dScaleY;
    float dScaleZ;
    
    float a, b, c;
    float n;
    
    float rX;		// rotate angles
    float rY;
    float rZ;
    ofColor color;
};
