//
//  heart.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#include "pressure.h"
#include "assets.h"

Pressure::Pressure(){
    
    CloseupModule::init();
    video = Assets::getInstance()->closeups[0];
    initMovie();
}


void Pressure::update(){
    CloseupModule::update();
}

void Pressure::draw(ofxJSONElement user){
    Assets *assets = Assets::getInstance();
    drawMovie();
    
    
    ofSetColor(assets->yellow);
    Assets::getInstance()->rejilla.draw(0, -400);
    ofSetColor(255);
    
    
    ofPushMatrix();
    
    
    assets->wireframe_pressure.draw(0, 0);
    ofTrueTypeFont *font = assets->getFont(26);
    string msg;
    
    int value = user["stress"][user["stress"].size() - 1].asFloat();
    msg = ofToString(value) + " %";
    font->drawStringAsShapes(msg, 962 - font->stringWidth(msg) , 578 + font->stringHeight(msg) * 1.5);
    
    
    ofPopMatrix();
}
