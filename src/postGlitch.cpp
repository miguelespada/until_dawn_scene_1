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
    
    int w = Assets::getInstance()->getWidth();
    int h = Assets::getInstance()->getHeight();
    
    if(video.isLoaded())
        video.draw(0, 0, w, h);
        
};

void postGlitch::update(){
    video.update();
    if(video.getIsMovieDone()){
        next();
    }
}

void postGlitch::next(){
    app->setCurrentState(new Loop(app));    
    app->incCurrentModule();
    delete this;
    
};
