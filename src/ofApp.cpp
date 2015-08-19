#include "ofApp.h"
#include "Loop.h"
#include "Closeup.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
//    ofSetWindowPosition(0, 0);
//    ofToggleFullscreen();
    ofSetFrameRate(30);
    
    assets = Assets::getInstance();

    for(int i = 0; i < 256; i ++)
        keyIsDown[i] = false;
    
    bRotated = true;
    setRotation();
    
    app.setCurrentState(new Loop(&app));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    
    ofPushMatrix();
    
    if(!bRotated){
        ofTranslate(0, ofGetHeight());
        ofRotate(-90);
    }
    
    app.draw();    
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {

        case 'R':
            bRotated = !bRotated;
            setRotation();
            break;
        default:
            break;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    keyIsDown[key] = false;

}

void ofApp::setRotation(){
    
    if(bRotated)
        ofSetWindowShape(1080 * assets->getScale(), 1920 * assets->getScale());
    else
        ofSetWindowShape(1920 * assets->getScale(), 1080 * assets->getScale());
}
