//
//  postGlitch.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#include "postGlitch.h"
#include "App.h"
#include "Assets.h"
#include "Loop.h"

postGlitch::postGlitch(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
    video = Assets::getInstance()->glitches[int(ofRandom(5))];
    video.play();
    video.setLoopState(OF_LOOP_NONE);

};

void postGlitch::draw(){
    
    if(ofGetWindowWidth() < ofGetWindowHeight())
        video.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    else
        video.draw(0, 0, ofGetWindowHeight(), ofGetWindowWidth());
};

void postGlitch::update(){
    video.update();
    if(video.getIsMovieDone()){
        next();
    }
}

void postGlitch::push(){
};

void postGlitch::next(){
    app->setCurrentState(new Loop(app));    
    app->incCurrentModule();
    delete this;
    
};

void postGlitch::jump(){
};