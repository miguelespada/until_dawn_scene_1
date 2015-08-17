//
//  preGlitch.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#include "preGlitch.h"
#include "App.h"
#include "Assets.h"
#include "Closeup.h"

preGlitch::preGlitch(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
    video = Assets::getInstance()->glitches[int(ofRandom(5))];
    video.play();
    video.setLoopState(OF_LOOP_NONE);

};

void preGlitch::draw(){
    
    if(ofGetWindowWidth() < ofGetWindowHeight())
        video.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    else
        video.draw(0, 0, ofGetWindowHeight(), ofGetWindowWidth());
};

void preGlitch::update(){
    video.update();
    if(video.getIsMovieDone()){
        next();
    }
}

void preGlitch::push(){
};

void preGlitch::next(){
    app->setCurrentState(new Closeup(app));
    delete this;
    
};

void preGlitch::jump(){
};