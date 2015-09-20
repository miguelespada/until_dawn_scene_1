//
//  standby.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 20/08/15.
//
//

#include "standby.h"
#include "App.h"
#include "Assets.h"
#include "Classification.h"

Standby::Standby(App *a){
    
    app = a;
    ofLogNotice() << "State: " << toString();
    
    Assets::getInstance()->stopVideos();
};

void Standby::draw(){
    
};

void Standby::update(){
    next();
}


void Standby::next(){
    app->setCurrentState(new Classification(app));
    delete this;
};
