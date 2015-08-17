//
//  App.cpp
//  App
//
//  Created by miguel on 12/10/14.
//
//

#include "App.h"
#include "heart.h"
#include "optical.h"

App::App(){
    // Register events and actions
    ofAddListener(ofEvents().keyPressed, this, &App::keyPressed);
    ofAddListener(ofEvents().update, this, &App::update);
    moduleIndex = 0;
}

void App::setCurrentState(State *s){
    current_state = s;
}

void App::next(){
    current_state->next();
}

void App::jump(){
    current_state->jump();
}

void App::cancel(){
    current_state->cancel();
}

void App::draw(){
    ofPushStyle();
    ofPushMatrix();
    current_state->draw();
    ofPopMatrix();
    ofPopStyle();
}

void App::update(){
    current_state->update();
    ofSendMessage("[Info] " + current_state->toString());
}

void App::update(ofEventArgs &args){
    update();
}


void App::keyPressed (ofKeyEventArgs& eventArgs){
    switch (eventArgs.key) {
        case 'n':
            next();
            break;
        case 'c':
            cancel();
            break;
        case 'M':
            bMale = !bMale;
            break;
        default:
            break;
    }
}

bool App::isMale(){
    return bMale;
}

int App::getCurrentModule(){
    return moduleIndex;
}

void App::incCurrentModule(){
    moduleIndex = (moduleIndex + 1) % 5;
}
