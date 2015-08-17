//
//  heart.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#include "termal.h"
#include "assets.h"

Termal::Termal(){
    video = Assets::getInstance()->closeups[2];
    initMovie();
}


void Termal::update(){
    CloseupModule::update();
}

void Termal::draw(){
    drawMovie();
}
