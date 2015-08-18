//
//  Closeup.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#include "Closeup.h"
#include "App.h"
#include "Assets.h"
#include "postGlitch.h"
#include "heart.h"
#include "optical.h"
#include "termal.h"
#include "galvanic.h"
#include "pressure.h"

Closeup::Closeup(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
    
    switch (app->getCurrentModule()) {
        case 0:
            closeup = new Heart();
            break;
        case 1:
            closeup = new Optical();
            break;
        case 2:
            closeup = new Termal();
            break;
        case 3:
            closeup = new Galvanic();
            break;
        case 4:
            closeup = new Pressure();
            break;
        default:
            break;
    }
};

void Closeup::draw(){
    closeup->draw();
};

void Closeup::update(){
    
    closeup->update();

    if(closeup->isDone())
        next();
}

void Closeup::push(){
};

void Closeup::next(){
    app->setCurrentState(new postGlitch(app));
    delete closeup;
    delete this;
};

void Closeup::jump(){
};