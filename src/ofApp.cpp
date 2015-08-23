#include "ofApp.h"
#include "Loop.h"
#include "Closeup.h"
#include "standby.h"
#include "preIndex.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    ofSetWindowPosition(0, 0);
//    ofToggleFullscreen();
    ofSetFrameRate(12);
    
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
    
    if(ofGetWindowWidth() < ofGetWindowHeight())
        ofScale(ofGetWidth() / 1080., ofGetHeight() / 1920. );
    else
        ofScale(ofGetWidth() / 1920., ofGetHeight() / 1080. );
    
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
        case 'S':
            delete app.current_state;
            app.setCurrentState(new Standby(&app));
            break;
        case 'I':
            delete app.current_state;
            app.setCurrentState(new preIndex(&app));
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
        ofSetWindowShape(HH, WW);
    else
        ofSetWindowShape(WW, HH);
}