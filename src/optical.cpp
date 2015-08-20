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
    video = Assets::getInstance()->closeups[0];
    initMovie();
}


void Optical::update(){
    CloseupModule::update();
}

void Optical::draw(){
    drawMovie();
}
