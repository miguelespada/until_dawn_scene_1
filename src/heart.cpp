//
//  heart.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#include "heart.h"

Heart::Heart(){
    CloseupModule::init();
    video = assets->closeups[1];
    initMovie();
}

void Heart::update(){
    CloseupModule::update();
}

void Heart::draw(ofxJSONElement user){
    
    Assets *assets = Assets::getInstance();
    drawMovie();

    
    ofSetColor(assets->red);
    Assets::getInstance()->rejilla.draw(0, -400);
    ofSetColor(255);

   
    ofPushMatrix();
    
    ofTranslate(150, -100);
    
    assets->wireframe_heart.draw(0, 0);
    ofTrueTypeFont *font = assets->getFont(26);
    string msg;
    
    int value = user["heartRate"][user["heartRate"].size() - 1].asFloat();
    msg = ofToString(value) + " BPM";
    font->drawStringAsShapes(msg, 372 - font->stringWidth(msg) , 1142 + font->stringHeight(msg) * 1.5);
    ofPopMatrix();
}
