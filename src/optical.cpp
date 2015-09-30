//
//  heart.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#include "optical.h"
#include "assets.h"

Optical::Optical(){
    
    CloseupModule::init();
    video = Assets::getInstance()->closeups[3];
    initMovie();
}


void Optical::update(){
    CloseupModule::update();
}

void Optical::draw(ofxJSONElement user){
    
    Assets *assets = Assets::getInstance();
    drawMovie();
    
    
    ofSetColor(assets->blue);
    Assets::getInstance()->rejilla.draw(0, -400);
    ofSetColor(255);
    
    
    ofPushMatrix();
    
    
    assets->wireframe_galvanic.draw(0, 0);
    ofTrueTypeFont *font = assets->getFont(26);

    
    float value = user["flow"][user["flow"].size() - 1].asFloat() * 100;
    
    string msg = ofToString(value) + " mm/s";
    
    font->drawStringAsShapes(msg, 962 - font->stringWidth(msg) , 568 + font->stringHeight(msg) * 1.5);
    
    
    ofPopMatrix();
}
