//
//  preIndex.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#include "preIndex.h"
#include "App.h"
#include "Assets.h"
#include "index.h"

preIndex::preIndex(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
    
    timer = ofGetElapsedTimef();
    alpha = 0;
    dots = 0;
};

void preIndex::draw(){
    int w = Assets::getInstance()->getWidth();
    int h = Assets::getInstance()->getHeight();
    
    ofPushMatrix();
    
    ofTranslate(w/2, h/4);
    
    float r = w/3;
    ofEnableSmoothing();
    ofSetColor(255);
    ofPath p = ofPath();
    p.setCircleResolution(200);
    p.setFilled(false);
    p.setStrokeColor(255);
    p.moveTo(r, 0);
    ofRotate(- ofRadToDeg(alpha), 0, 0, 1);
    p.arc(0, 0, r, r, 0, 180 );
    p.setStrokeWidth(1.5);
    p.draw();
    ofDisableSmoothing();
    
    
    ofPopMatrix();
    
    ofTrueTypeFont *font = Assets::getInstance()->getFont(30);
    string msg = "CALCULANDO";
    
    int text_x = w / 2 - font->stringWidth(msg) / 2;
    font->drawString(msg, text_x, h/4);
    
    msg = "ÍNDICE UNTIL DAWN";
    
    
    text_x = w / 2 - font->stringWidth(msg) / 2;
    font->drawString(msg, text_x, h/4 + font->stringHeight(msg) * 1.5);
    
    string dots_msg = "";
    for(int i = 0; i < dots; i ++)
        dots_msg += ".";
    
    font->drawString(dots_msg, text_x + font->stringWidth(msg) - 20 * Assets::getInstance()->getScale() , h/4 + font->stringHeight(msg) * 1.5);
};

void preIndex::update(){
    alpha += 0.2;
    if(ofGetElapsedTimef() >= timer + 4)
        next();
    
    if(ofGetFrameNum() % 10 == 0)
        dots = (dots + 1) % 4;
}


void preIndex::next(){
    app->setCurrentState(new Index(app));
    delete this;
};