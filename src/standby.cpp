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
#include "contextClassification.h"

Standby::Standby(App *a){
    
    app = a;
    ofLogNotice() << "State: " << toString();
};

void Standby::draw(){
    
};

void Standby::update(){
    next();
}


void Standby::next(){
    app->setCurrentState(new contextClassification(app));
    delete this;
};
