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
    video = Assets::getInstance()->closeups[4];
    initMovie();
}


void Galvanic::update(){
    CloseupModule::update();
}

void Galvanic::draw(){
    drawMovie();
}
