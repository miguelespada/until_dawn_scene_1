//
//  CloseupModule.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 20/08/15.
//
//

#include "CloseupModule.h"

void CloseupModule::init(){
    assets = Assets::getInstance();
}

void CloseupModule::drawMovie(){
    if(video.isLoaded())
        video.draw(0, 0);
}

void CloseupModule::initMovie(){
    video.setPosition(0);
    video.play();
}

void CloseupModule::update() {
    if(video.isLoaded())
        video.update();
};


void CloseupModule::clear(){
    video.stop();
};