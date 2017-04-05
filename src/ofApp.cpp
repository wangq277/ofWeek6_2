#include "ofApp.h"

ofFbo fbo;
//ofImage leaf;
//--------------------------------------------------------------
vector<Line> leaves;

Line::Line(){
    //leafImg.load("leaf.png");
    
    // while(!leafImg.getWidth());  // loop here till loaded
    //loc -= ofPoint(leafImg.getWidth()/2, leafImg.getHeight()/2);
//    sTime = ofGetElapsedTimef();
//    sWeight = ofRandom(0.1, 0.4);
//    fallSpeed = ofRandom(2, 8);
}

void Line :: setup(){
    loc = ofPoint(0,0,0);
    sWeight= ofRandom(1,1.5);
    
    n = ofRandom(0.1,2);
    
    a = ofRandom(0.2,0.3);
    b = ofRandom(0.3,0.4);
    c = ofRandom(0.4,0.5);
    
    rX = ofRandom(45);
    rY = ofRandom(60);
    rZ = ofRandom(30);
    
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
    
    fbo.allocate(ofGetWindowWidth(),ofGetWindowHeight());
    fbo.begin();
    ofClear(255,255,255,0);
    fbo.end();
}


//--------------------------------------------------------------
void Line::update(){
    //    rX++;
    //    if(ofGetFrameNum()%3 == 0)
    //        rY++;
    //    if(ofGetFrameNum()%7 ==0)
    //        rZ++;
    
    sTime = ofGetElapsedTimef()*n;
    
    rX = ofSignedNoise(sTime * 0.2) * 400.0;  // rotate +- 400deg
    rY = ofSignedNoise(sTime * 0.3) * 400.0;
    rZ = ofSignedNoise(sTime * 0.1) * 400.0;
    
    scale = (1 - ofNoise(sTime * 0.2)) * sWeight;
    
    dScaleX = (1 - ofNoise(sTime * a)) * ofRandom(1,10);
    dScaleY = (1 - ofNoise(sTime * b)) * ofRandom(1,10);
    dScaleZ = (1 - ofNoise(sTime * c)) * ofRandom(1,10);
    
    //fallWiggle = ofSignedNoise(sTime * 0.6) * ofRandom(20, 70);
    loc += ofPoint(dScaleX, dScaleY, dScaleZ);
}

//--------------------------------------------------------------
void Line::draw() {
    
    fbo.begin();
    ofSetColor(255, 255, 255, 5);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    //float z = ofSignedNoise((ofGetElapsedTimef() + sTime) * 0.9) * 400;
    
    ofPushMatrix();
    ofTranslate(loc.x, loc.y, loc.z);
    // ofScale(dScaleX, dScaleY, dScaleZ);  // can be 3 dimensional
    
    ofScale(dScaleX, dScaleY, dScaleZ);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    // leafImg.draw(0 - leafImg.getWidth()/2, 0 - leafImg.getHeight()/2);  // draw at new 0,0
    ofSetColor(color);
    ofDrawLine(-10, 0, 10, 0);
    ofPopMatrix();
    
    fbo.end();
    
    ofSetColor(255);
    fbo.draw(0,0);

}

void ofApp::setup(){
    // leaf.load("leaf.png");
//    fbo.allocate(ofGetWidth(), ofGetHeight());  // higher precision alpha (no artifacts)
//    
//    fbo.begin();
//    ofClear(255,255,255, 0);
//    fbo.end();

    for(int i=0; i<5; i++){
        Line newLine;
        newLine.setup();
        leaves.push_back(newLine);
    
    }
}

//float rX = 0;
//float rY = 0;
//float rZ = 0;

//----------------------------------------------------------------------------

void ofApp::update(){
    for(int i; i < leaves.size(); i++) {
        leaves[i].update();
        
        if (leaves[i].loc.y > ofGetHeight()) {  // age it out
            leaves.erase(leaves.begin() + i);
            Line newLine;
            newLine.setup();
            leaves.push_back(newLine);
        
//        if(leaves[i].loc.y<0||leaves[i].loc.y>ofGetWindowHeight()||leaves[i].loc.x<0|leaves[i].loc.x>ofGetWindowWidth()){
//            leaves.erase(leaves.begin()+i);
//            Line newLine;
//            newLine.setup();
//            leaves.push_back(newLine);
        }
    }
}


void ofApp::draw(){
    ofBackground(255);
//    
//    fbo.begin();

    //    ofSetColor(255,255,255, 10);
//    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
//    
//    ofPushMatrix();
//    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
//    
//    ofScale(0.3, 0.3, 0.3); //can be 3 dimensional
//    
////    ofRotateX(rX);
////    ofRotateY(rY);
////    ofRotateZ(rZ);
//   // leaf.draw(0 - leaf.getWidth()/2, 0 - leaf.getHeight()/2); //draw at new 0,0
//    ofSetColor(0);
//    ofDrawLine(-60, 500, 60, 500);
//    ofDrawLine(-120, 500, 120, 500);
//    ofPopMatrix();
    for(int i=0; i<leaves.size(); i++){
        leaves[i].draw();
    }

    
//    fbo.end();
//    fbo.draw(0,0);
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
