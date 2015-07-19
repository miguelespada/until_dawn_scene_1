#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowPosition(+1921, 0);
    
    ofToggleFullscreen();
    ofSetFrameRate(12);
    
    initial_time = ofGetElapsedTimef();
    assets = Assets::getInstance();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    assets->body.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    keyIsDown[key] = true;
    int times = 1;
    if(keyIsDown['a'])
        times *= 10;
    if(keyIsDown['q'])
        times *= 10;
    
    
    switch (key) {
        case OF_KEY_UP:
            assets->x += 1 * times;
            break;
        case OF_KEY_DOWN:
            assets->x -= 1 * times;
            break;
        case OF_KEY_RIGHT:
            assets->y += 1 * times;
            break;
        case OF_KEY_LEFT:
            assets->y -= 1 * times;
            break;
               default:
            break;
    }


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    keyIsDown[key] = false;

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
