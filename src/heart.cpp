//
//  heart.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#include "heart.h"

Heart::Heart(){
    video = Assets::getInstance()->closeups[1];
    initMovie();
    if(ofGetWindowWidth() < ofGetWindowHeight()){
        w = ofGetWindowWidth();
        h = ofGetWindowHeight();
    }
    else{
        h = ofGetWindowWidth();
        w = ofGetWindowHeight();
    }

}


void Heart::update(){
    CloseupModule::update();
}

void Heart::draw(){
    assets = Assets::getInstance();
    
    drawMovie();
    
    table.drawTable();
    assets->wireframe_heart.draw(0, 0, w, h);
    assets->logos.draw(0, 0, w, h);
    assets->lineas.draw(0, 0, w, h);
    assets->degradado.draw(0, 10, w, h);
}
