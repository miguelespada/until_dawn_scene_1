//
//  temperature.cpp
//  until_dawn_screen_2
//
//  Created by miguel on 16/07/15.
//
//

#include "body.h"
#include "assets.h"

Body::Body(){
}

void Body::update(){
    if(!video.isPlaying())
        video.play();
    video.update();
}

void Body::draw(){
    if(ofGetWindowWidth() < ofGetWindowHeight())
        video.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    else
        video.draw(0, 0, ofGetWindowHeight(), ofGetWindowWidth());
}

void Body::setMale(bool s){
    if(s)
        video = Assets::getInstance()->male_loop;
    else
        video = Assets::getInstance()->female_loop;
}

