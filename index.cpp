//
//  index.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 19/08/15.
//
//

#include "index.h"
#include "App.h"
#include "Assets.h"
#include "Loop.h"

Index::Index(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
};

void Index::draw(){
    int w = 1920;
    int h = 1080;
    
    ofTrueTypeFont *font = Assets::getInstance()->getFont(30);
    
    string msg = "ÍNDICE UNTIL DAWN";
    
    
    int text_x = w / 2 - font->stringWidth(msg) / 2;
    font->drawStringAsShapes(msg, text_x, h/4 + font->stringHeight(msg) * 1.5);
    
};

void Index::update(){
}

void Index::next(){
    init();
};

void Index::init(){
    app->setCurrentState(new Loop(app));
    delete this;
};