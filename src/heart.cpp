//
//  heart.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#include "heart.h"
#include "assets.h"

Heart::Heart(){
    video = Assets::getInstance()->closeups[1];
    initMovie();
}


void Heart::update(){
    CloseupModule::update();
}

void Heart::draw(){
    drawMovie();
}
