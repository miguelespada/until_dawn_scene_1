//
//  heart.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#include "galvanic.h"
#include "assets.h"

Galvanic::Galvanic(){
    
    CloseupModule::init();
    video = Assets::getInstance()->closeups[2];
    initMovie();
}


void Galvanic::update(){
    CloseupModule::update();
}

void Galvanic::draw(ofxJSONElement user){
    
    Assets *assets = Assets::getInstance();
    drawMovie();
    
    
    ofSetColor(assets->blue);
    Assets::getInstance()->rejilla.draw(0, -400);
    ofSetColor(255);
    
    
    ofPushMatrix();
    
    
    assets->wireframe_galvanic.draw(0, 0);
    ofTrueTypeFont *font = assets->getFont(26);
    
    int value = user["galvanicVoltage"][user["galvanicVoltage"].size() - 1].asFloat();
    string msg = ofToString(value) + "S/m";

    font->drawStringAsShapes(msg, 962 - font->stringWidth(msg) , 568 + font->stringHeight(msg) * 1.5);
    
    
    ofPopMatrix();
}
