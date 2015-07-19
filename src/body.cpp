//
//  temperature.cpp
//  until_dawn_screen_2
//
//  Created by miguel on 16/07/15.
//
//

#include "body.h"
#include "assets.h"


Body::Body(){
    video.loadMovie("hombre.mov");
    video.play();
    ofAddListener(ofEvents().update, this, &Body::update);
}


void Body::update(ofEventArgs &args){
    video.update();
}

void Body::draw(int x, int y){
    ofPushMatrix();
    
    ofTranslate(x, y, 0);
    
    drawVideo();
    
    ofPopMatrix();
    
}

void Body::drawVideo(){
    
    ofPushStyle();
    ofTranslate(0, ofGetWindowHeight());
    cout << ofGetMouseX() << " " << ofGetMouseY() << endl;
    ofRotate(-90);
    video.draw(0, 0);
    
    ofPopStyle();
    
}
