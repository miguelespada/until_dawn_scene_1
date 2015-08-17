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
    video = Assets::getInstance()->closeups[3];
    initMovie();
}


void Pressure::update(){
    CloseupModule::update();
}

void Pressure::draw(){
    drawMovie();
}
