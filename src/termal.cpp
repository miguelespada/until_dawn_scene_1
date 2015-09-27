//
//  heart.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#include "termal.h"
#include "assets.h"

Termal::Termal(){
    
    CloseupModule::init();
    video = Assets::getInstance()->closeups[4];
    initMovie();
    value = int(ofRandom(0, 360));
}


void Termal::update(){
    CloseupModule::update();
}

void Termal::draw(ofxJSONElement user){
    
    Assets *assets = Assets::getInstance();
    drawMovie();
    
    
    ofSetColor(assets->green);
    Assets::getInstance()->rejilla.draw(0, -400);
    ofSetColor(255);
    
    
    ofPushMatrix();
    
    
    assets->wireframe_temperature.draw(0, 0);
    ofTrueTypeFont *font = assets->getFont(26);
    string msg;
    
    float value = user["thermal"][user["thermal"].size() - 1].asFloat();
    msg = ofToString(int(value * 100)) + "% THERMAL VARIANCE";
    font->drawStringAsShapes(msg, 100, 393 + font->stringHeight(msg) * 1.5);
    
    ofPopMatrix();
}
